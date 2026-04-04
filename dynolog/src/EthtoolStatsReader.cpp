/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/EthtoolStatsReader.h"

#include <glog/logging.h>
#include <linux/sockios.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>
#include <system_error>

namespace dynolog {

namespace {
class EthtoolIoctlImpl : public EthtoolIoctlInterface {
 public:
  int openSocket() override {
    return socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
  }
  int doIoctl(int fd, unsigned long req, struct ifreq* ifr) override {
    return ioctl(fd, req, ifr);
  }
  void closeSocket(int fd) override {
    close(fd);
  }
};
} // namespace

EthtoolStatsReader::~EthtoolStatsReader() {
  cleanup();
}

void EthtoolStatsReader::cleanup() {
  if (fd_ >= 0 && ioctl_) {
    ioctl_->closeSocket(fd_);
    fd_ = -1;
  }
  names_.clear();
  values_.clear();
  nStats_ = 0;
  initialized_ = false;
}

bool EthtoolStatsReader::init(const std::string& ifname) {
  cleanup();

  if (!ioctl_) {
    ioctl_ = std::make_unique<EthtoolIoctlImpl>();
  }

  fd_ = ioctl_->openSocket();
  if (fd_ < 0) {
    LOG(ERROR) << "EthtoolStatsReader: socket open failed for " << ifname
               << ": " << std::generic_category().message(errno);
    return false;
  }

  memset(&ifr_, 0, sizeof(ifr_));
  strncpy(ifr_.ifr_name, ifname.c_str(), IFNAMSIZ - 1);

  // Step 1: ETHTOOL_GSSET_INFO — get stat count
  union {
    struct ethtool_sset_info hdr;
    uint8_t buf[sizeof(struct ethtool_sset_info) + sizeof(uint32_t)];
  } sset{};
  sset.hdr.cmd = ETHTOOL_GSSET_INFO;
  sset.hdr.sset_mask = 1ULL << ETH_SS_STATS;
  ifr_.ifr_data = reinterpret_cast<char*>(&sset);

  if (ioctl_->doIoctl(fd_, SIOCETHTOOL, &ifr_) != 0) {
    LOG(ERROR) << "EthtoolStatsReader: ETHTOOL_GSSET_INFO failed for " << ifname
               << ": " << std::generic_category().message(errno);
    cleanup();
    return false;
  }

  nStats_ = sset.hdr.sset_mask ? sset.hdr.data[0] : 0;
  if (nStats_ == 0) {
    LOG(WARNING) << "EthtoolStatsReader: no stats for " << ifname;
    cleanup();
    return false;
  }

  // Step 2: ETHTOOL_GSTRINGS — get stat names
  size_t gstrSz =
      sizeof(struct ethtool_gstrings) + (size_t)nStats_ * ETH_GSTRING_LEN;
  auto gstrBuf = std::make_unique<char[]>(gstrSz);
  auto* gstr = reinterpret_cast<struct ethtool_gstrings*>(gstrBuf.get());
  memset(gstr, 0, gstrSz);
  gstr->cmd = ETHTOOL_GSTRINGS;
  gstr->string_set = ETH_SS_STATS;
  gstr->len = nStats_;
  ifr_.ifr_data = reinterpret_cast<char*>(gstr);

  if (ioctl_->doIoctl(fd_, SIOCETHTOOL, &ifr_) != 0) {
    LOG(ERROR) << "EthtoolStatsReader: ETHTOOL_GSTRINGS failed for " << ifname
               << ": " << std::generic_category().message(errno);
    cleanup();
    return false;
  }

  names_.resize(nStats_);
  for (uint32_t i = 0; i < nStats_; i++) {
    names_[i] = std::string(
        reinterpret_cast<char*>(&gstr->data[i * ETH_GSTRING_LEN]),
        strnlen(
            reinterpret_cast<char*>(&gstr->data[i * ETH_GSTRING_LEN]),
            ETH_GSTRING_LEN));
  }

  values_.resize(nStats_, 0);
  initialized_ = true;
  return true;
}

bool EthtoolStatsReader::sample() {
  if (!initialized_) {
    LOG(WARNING) << "EthtoolStatsReader: not initialized, call init() first";
    return false;
  }

  size_t statsSz = sizeof(struct ethtool_stats) + nStats_ * sizeof(uint64_t);
  auto statsBuf = std::make_unique<char[]>(statsSz);
  auto* stats = reinterpret_cast<struct ethtool_stats*>(statsBuf.get());
  memset(stats, 0, statsSz);
  stats->cmd = ETHTOOL_GSTATS;
  stats->n_stats = nStats_;
  ifr_.ifr_data = reinterpret_cast<char*>(stats);

  if (ioctl_->doIoctl(fd_, SIOCETHTOOL, &ifr_) != 0) {
    LOG_EVERY_N(ERROR, 10) << "EthtoolStatsReader: ETHTOOL_GSTATS failed: "
                           << std::generic_category().message(errno);
    return false;
  }

  for (uint32_t i = 0; i < nStats_; i++) {
    values_[i] = stats->data[i];
  }
  return true;
}

size_t EthtoolStatsReader::size() const {
  return nStats_;
}

const std::string& EthtoolStatsReader::name(size_t i) const {
  return names_.at(i);
}

uint64_t EthtoolStatsReader::value(size_t i) const {
  return values_.at(i);
}

std::map<std::string, uint64_t> EthtoolStatsReader::getAllStats() const {
  std::map<std::string, uint64_t> result;
  for (size_t i = 0; i < nStats_; i++) {
    result[names_[i]] = values_[i];
  }
  return result;
}

} // namespace dynolog
