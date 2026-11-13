/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <linux/ethtool.h>
#include <net/if.h>
#include <sys/uio.h>
#include <unistd.h>
#include <algorithm>
#include <cerrno>
#include <cstdint>
#include <cstring>
#include <string>
#include <utility>
#include <vector>

#include "dynolog/src/EthtoolStatsReader.h"

namespace dynolog::fakes {

// A NIC's ethtool stats, shared with (and mutable while used by) a
// FakeEthtoolIoctl.
struct FakeEthtoolNic {
  FakeEthtoolNic() = default;
  FakeEthtoolNic(std::vector<std::string> n, std::vector<uint64_t> v)
      : names(std::move(n)), values(std::move(v)) {}

  std::vector<std::string> names;
  std::vector<uint64_t> values;
  bool failSsetInfo = false;
  bool failStats = false;
  // If non-zero, ETHTOOL_GSSET_INFO reports this count instead of the real
  // one, to model the count growing right after it was queried.
  uint32_t staleSsetInfoCount = 0;
  // Every ETHTOOL_* command received, in order.
  std::vector<uint32_t> commands;
};

// Fake ethtool ioctls backed by a FakeEthtoolNic. Like the kernel,
// ETHTOOL_GSTRINGS and ETHTOOL_GSTATS ignore the caller's len / n_stats, write
// the driver's current count back into it, and then copy that many entries.
// Copies into the caller's buffer behave like copy_to_user: a copy that hits
// unmapped or protected memory fails with EFAULT instead of crashing.
class FakeEthtoolIoctl : public EthtoolIoctlInterface {
 public:
  explicit FakeEthtoolIoctl(FakeEthtoolNic* nic) : nic_(nic) {}

  int openSocket() override {
    return 3;
  }

  int doIoctl(int /*fd*/, unsigned long /*req*/, struct ifreq* ifr) override {
    char* user = ifr->ifr_data;
    uint32_t cmd = 0;
    memcpy(&cmd, user, sizeof(cmd));
    nic_->commands.push_back(cmd);
    const auto count = static_cast<uint32_t>(nic_->names.size());
    switch (cmd) {
      case ETHTOOL_GSSET_INFO: {
        if (nic_->failSsetInfo) {
          return fail(EOPNOTSUPP);
        }
        auto* sset = reinterpret_cast<struct ethtool_sset_info*>(user);
        sset->sset_mask = 1ULL << ETH_SS_STATS;
        sset->data[0] =
            nic_->staleSsetInfoCount ? nic_->staleSsetInfoCount : count;
        return 0;
      }
      case ETHTOOL_GSTRINGS: {
        struct ethtool_gstrings hdr{};
        memcpy(&hdr, user, sizeof(hdr));
        hdr.len = count;
        std::vector<char> data(static_cast<size_t>(count) * ETH_GSTRING_LEN);
        for (size_t i = 0; i < count; i++) {
          memcpy(
              data.data() + i * ETH_GSTRING_LEN,
              nic_->names[i].data(),
              std::min<size_t>(nic_->names[i].size(), ETH_GSTRING_LEN));
        }
        if (!copyToUser(user, &hdr, sizeof(hdr)) ||
            !copyToUser(user + sizeof(hdr), data.data(), data.size())) {
          return fail(EFAULT);
        }
        return 0;
      }
      case ETHTOOL_GSTATS: {
        if (nic_->failStats) {
          return fail(EIO);
        }
        struct ethtool_stats hdr{};
        memcpy(&hdr, user, sizeof(hdr));
        hdr.n_stats = static_cast<uint32_t>(nic_->values.size());
        if (!copyToUser(user, &hdr, sizeof(hdr)) ||
            !copyToUser(
                user + sizeof(hdr),
                nic_->values.data(),
                nic_->values.size() * sizeof(uint64_t))) {
          return fail(EFAULT);
        }
        return 0;
      }
      default:
        return fail(EOPNOTSUPP);
    }
  }

  void closeSocket(int /*fd*/) override {}

 private:
  static int fail(int err) {
    errno = err;
    return -1;
  }

  // Writes through the kernel, so a fault is reported instead of raised.
  static bool copyToUser(void* dst, const void* src, size_t len) {
    if (len == 0) {
      return true;
    }
    struct iovec local{const_cast<void*>(src), len};
    struct iovec remote{dst, len};
    return process_vm_writev(getpid(), &local, 1, &remote, 1, 0) ==
        static_cast<ssize_t>(len);
  }

  FakeEthtoolNic* nic_;
};

} // namespace dynolog::fakes
