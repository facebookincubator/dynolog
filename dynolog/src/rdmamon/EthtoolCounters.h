// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <glog/logging.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>
#include <net/if.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include <map>
#include <string>

// @lint-ignore-every CLANGTIDY facebook-hte-BadCall-strerror

namespace dynolog {
namespace rdmamon {

class EthtoolCounters {
 public:
  explicit EthtoolCounters(const std::string& ifname) : ifname_(ifname) {}
  virtual ~EthtoolCounters() {
    teardown_ethtool_counters();
  }

  bool setupEthtoolCounters();
  bool sampleEthtoolCounters(std::map<std::string, int64_t>& rdmaCounterMap);

 private:
  std::string ifname_;
  int ioctl_sock_fd_;
  struct ethtool_gstrings* gstrings_ = nullptr;
  struct ethtool_stats *cur_eth_stats_ = nullptr, *prev_eth_stats_ = nullptr;
  size_t stats_sz_ = 0;
  struct ifreq ifr_;
  bool first_sample_ = true;

  std::map<std::string, int> eth_counters_;

  [[nodiscard]] bool open_ioctl_socket() {
    ioctl_sock_fd_ = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (ioctl_sock_fd_ < 0) {
      LOG(ERROR) << "Unable to create socket (" << std::strerror(errno) << ")";
      return false;
    }
    return true;
  }

  void close_ioctl_socket() {
    if (ioctl_sock_fd_ >= 0) {
      close(ioctl_sock_fd_);
      ioctl_sock_fd_ = -1;
    }
  }

  [[nodiscard]] bool setup_ethtool_counters(
      const std::vector<std::string>& eth_counter_names_) {
    union {
      struct ethtool_sset_info hdr;
      // Allocate extra space for flexible array member.
      uint8_t
          _buf[offsetof(struct ethtool_sset_info, data) + sizeof(uint32_t[1])];
    } ss_stats;
    uint32_t ss_stats_len;

    if (!open_ioctl_socket()) {
      return false;
    }

    // Fetch how many stats will be returned
    ss_stats.hdr.cmd = ETHTOOL_GSSET_INFO;
    ss_stats.hdr.reserved = 0;
    ss_stats.hdr.sset_mask = 1ULL << ETH_SS_STATS;
    memset(&ifr_, 0, sizeof(ifr_));
    strncpy(ifr_.ifr_name, ifname_.c_str(), sizeof(ifr_.ifr_name));
    ifr_.ifr_data = (char*)&ss_stats;
    if (ioctl(ioctl_sock_fd_, SIOCETHTOOL, &ifr_)) {
      LOG(ERROR) << "IOCTL error for ETHTOOL_GSSET_INFO ("
                 << std::strerror(errno) << ")";
      return false;
    }
    ss_stats_len = ss_stats.hdr.sset_mask ? ss_stats.hdr.data[0] : 0;
    if (ss_stats_len < 1) {
      LOG(INFO) << "Cannot retrieve the stats information";
      return false;
    }
    size_t gstrings_size =
        sizeof(*gstrings_) + (ss_stats_len * ETH_GSTRING_LEN);
    gstrings_ = (struct ethtool_gstrings*)calloc(1, gstrings_size);
    if (!gstrings_) {
      LOG(ERROR) << "Unable to allocate " << gstrings_size
                 << " bytes for gstrings";
      return false;
    }

    // Fetch the strings for each stats
    gstrings_->cmd = ETHTOOL_GSTRINGS;
    gstrings_->string_set = ETH_SS_STATS;
    gstrings_->len = ss_stats_len;
    memset(&ifr_.ifr_data, 0, sizeof(ifr_.ifr_data));
    ifr_.ifr_data = (char*)gstrings_;
    if (ioctl(ioctl_sock_fd_, SIOCETHTOOL, &ifr_)) {
      LOG(ERROR) << "IOCTL error for ETHTOOL_GSTRINGS (" << std::strerror(errno)
                 << ")";
      return false;
    }
    memset(&ifr_.ifr_data, 0, sizeof(ifr_.ifr_data));

    /* Allocate the memory for stats */
    stats_sz_ =
        (gstrings_->len * sizeof(uint64_t)) + sizeof(struct ethtool_stats);
    cur_eth_stats_ = (struct ethtool_stats*)calloc(1, stats_sz_);
    prev_eth_stats_ = (struct ethtool_stats*)calloc(1, stats_sz_);
    if (!cur_eth_stats_ || !prev_eth_stats_) {
      LOG(ERROR) << "Unable to allocate " << stats_sz_
                 << " bytes of memory for eth_stats";
      return false;
    }
    cur_eth_stats_->cmd = ETHTOOL_GSTATS;
    cur_eth_stats_->n_stats = gstrings_->len;
    ifr_.ifr_data = (char*)cur_eth_stats_;

    for (auto eth_counter_name : eth_counter_names_) {
      for (int j = 0; j < gstrings_->len; j++) {
        if (0 ==
            memcmp(
                (void*)eth_counter_name.c_str(),
                (void*)(&gstrings_->data[j * ETH_GSTRING_LEN]),
                strlen(eth_counter_name.c_str()))) {
          eth_counters_[eth_counter_name] = j;
        }
      }
    }

    return true;
  }

  void teardown_ethtool_counters() {
    eth_counters_.clear();

    if (gstrings_) {
      free(gstrings_);
      gstrings_ = nullptr;
    }

    if (cur_eth_stats_) {
      free(cur_eth_stats_);
      cur_eth_stats_ = nullptr;
    }

    if (prev_eth_stats_) {
      free(prev_eth_stats_);
      prev_eth_stats_ = nullptr;
    }

    close_ioctl_socket();
  }

  bool get_current_ethtool_counters() {
    if (ioctl(ioctl_sock_fd_, SIOCETHTOOL, &ifr_)) {
      LOG_EVERY_N(ERROR, 10) << "IOCTL error while getting ethtool counters ("
                             << std::strerror(errno) << ")";
      return false;
    }
    return true;
  }
};

} // namespace rdmamon
} // namespace dynolog
