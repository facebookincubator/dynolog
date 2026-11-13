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
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <system_error>
#include <utility>

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

GuardedBuffer::GuardedBuffer(size_t size) {
  const size_t page = static_cast<size_t>(sysconf(_SC_PAGESIZE));
  const size_t aligned = (size + 7) & ~size_t{7};
  const size_t dataBytes = (aligned + page - 1) / page * page;
  void* map = mmap(
      nullptr,
      dataBytes + page,
      PROT_READ | PROT_WRITE,
      MAP_PRIVATE | MAP_ANONYMOUS,
      -1,
      0);
  if (map == MAP_FAILED) {
    return;
  }
  char* guard = static_cast<char*>(map) + dataBytes;
  if (mprotect(guard, page, PROT_NONE) != 0) {
    munmap(map, dataBytes + page);
    return;
  }
  map_ = map;
  mapSize_ = dataBytes + page;
  // Writes go upwards from data_, so the end of the buffer is put right at
  // the guard page.
  data_ = guard - aligned;
}

GuardedBuffer::~GuardedBuffer() {
  release();
}

GuardedBuffer::GuardedBuffer(GuardedBuffer&& other) noexcept
    : map_(std::exchange(other.map_, nullptr)),
      mapSize_(std::exchange(other.mapSize_, 0)),
      data_(std::exchange(other.data_, nullptr)) {}

GuardedBuffer& GuardedBuffer::operator=(GuardedBuffer&& other) noexcept {
  if (this != &other) {
    release();
    map_ = std::exchange(other.map_, nullptr);
    mapSize_ = std::exchange(other.mapSize_, 0);
    data_ = std::exchange(other.data_, nullptr);
  }
  return *this;
}

void GuardedBuffer::release() {
  if (map_ != nullptr) {
    munmap(map_, mapSize_);
  }
  map_ = nullptr;
  mapSize_ = 0;
  data_ = nullptr;
}

EthtoolStatsReader::~EthtoolStatsReader() {
  cleanup();
}

EthtoolStatsReader::EthtoolStatsReader(EthtoolStatsReader&& other) noexcept
    : ioctl_(std::move(other.ioctl_)),
      fd_(std::exchange(other.fd_, -1)),
      ifr_(other.ifr_),
      nStats_(std::exchange(other.nStats_, 0)),
      names_(std::move(other.names_)),
      values_(std::move(other.values_)),
      statsBuf_(std::move(other.statsBuf_)),
      initialized_(std::exchange(other.initialized_, false)),
      needsReinit_(std::exchange(other.needsReinit_, false)) {}

EthtoolStatsReader& EthtoolStatsReader::operator=(
    EthtoolStatsReader&& other) noexcept {
  if (this != &other) {
    cleanup();
    ioctl_ = std::move(other.ioctl_);
    fd_ = std::exchange(other.fd_, -1);
    ifr_ = other.ifr_;
    nStats_ = std::exchange(other.nStats_, 0);
    names_ = std::move(other.names_);
    values_ = std::move(other.values_);
    statsBuf_ = std::move(other.statsBuf_);
    initialized_ = std::exchange(other.initialized_, false);
    needsReinit_ = std::exchange(other.needsReinit_, false);
  }
  return *this;
}

std::optional<uint32_t> EthtoolStatsReader::queryStatCount() {
  union {
    struct ethtool_sset_info hdr;
    uint8_t buf[sizeof(struct ethtool_sset_info) + sizeof(uint32_t)];
  } sset{};
  sset.hdr.cmd = ETHTOOL_GSSET_INFO;
  sset.hdr.sset_mask = 1ULL << ETH_SS_STATS;
  ifr_.ifr_data = reinterpret_cast<char*>(&sset);
  if (ioctl_->doIoctl(fd_, SIOCETHTOOL, &ifr_) != 0) {
    return std::nullopt;
  }
  return sset.hdr.sset_mask ? sset.hdr.data[0] : 0;
}

void EthtoolStatsReader::cleanup() {
  if (fd_ >= 0 && ioctl_) {
    ioctl_->closeSocket(fd_);
    fd_ = -1;
  }
  names_.clear();
  values_.clear();
  statsBuf_ = GuardedBuffer();
  nStats_ = 0;
  initialized_ = false;
  needsReinit_ = false;
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
  auto count = queryStatCount();
  if (!count) {
    LOG(ERROR) << "EthtoolStatsReader: ETHTOOL_GSSET_INFO failed for " << ifname
               << ": " << std::generic_category().message(errno);
    cleanup();
    return false;
  }
  nStats_ = *count;
  if (nStats_ == 0) {
    LOG(WARNING) << "EthtoolStatsReader: no stats for " << ifname;
    cleanup();
    return false;
  }

  // Step 2: ETHTOOL_GSTRINGS — get stat names. The kernel ignores len and
  // writes the driver's current count back into it before copying that many
  // names; the guard page stops the copy if the count grew since step 1.
  GuardedBuffer gstrBuf(
      sizeof(struct ethtool_gstrings) +
      static_cast<size_t>(nStats_) * ETH_GSTRING_LEN);
  if (!gstrBuf) {
    LOG(ERROR) << "EthtoolStatsReader: buffer allocation failed for " << ifname;
    cleanup();
    return false;
  }
  auto* gstr = reinterpret_cast<struct ethtool_gstrings*>(gstrBuf.data());
  gstr->cmd = ETHTOOL_GSTRINGS;
  gstr->string_set = ETH_SS_STATS;
  gstr->len = nStats_;
  ifr_.ifr_data = reinterpret_cast<char*>(gstr);

  int rc = ioctl_->doIoctl(fd_, SIOCETHTOOL, &ifr_);
  if (gstr->len != nStats_) {
    LOG(WARNING) << "EthtoolStatsReader: stat count for " << ifname
                 << " changed from " << nStats_ << " to " << gstr->len
                 << " during init";
    cleanup();
    return false;
  }
  if (rc != 0) {
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

  statsBuf_ = GuardedBuffer(
      sizeof(struct ethtool_stats) +
      static_cast<size_t>(nStats_) * sizeof(uint64_t));
  if (!statsBuf_) {
    LOG(ERROR) << "EthtoolStatsReader: buffer allocation failed for " << ifname;
    cleanup();
    return false;
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
  if (needsReinit_) {
    return false;
  }

  // The kernel ignores n_stats, writes the driver's current count back into
  // it, then copies that many values. If the count changed since init() (e.g.
  // driver reload), the guard page after statsBuf_ stops the copy (EFAULT)
  // and the returned n_stats tells us to re-init.
  auto* stats = reinterpret_cast<struct ethtool_stats*>(statsBuf_.data());
  stats->cmd = ETHTOOL_GSTATS;
  stats->n_stats = nStats_;
  ifr_.ifr_data = reinterpret_cast<char*>(stats);

  int rc = ioctl_->doIoctl(fd_, SIOCETHTOOL, &ifr_);
  if (stats->n_stats != nStats_) {
    LOG(WARNING) << "EthtoolStatsReader: stat count changed from " << nStats_
                 << " to " << stats->n_stats << ", re-init needed";
    needsReinit_ = true;
    return false;
  }
  if (rc != 0) {
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
