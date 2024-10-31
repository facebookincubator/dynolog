// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/rdmamon/RdmaCounters.h"
#include <fmt/format.h>
#include <cstdint>
#include <map>

namespace dynolog {
namespace rdmamon {

bool RdmaCounters::setupRdmaCounters() {
  const std::vector<std::string> rdma_port_counters_ = {
      "port_xmit_data",
      "port_xmit_packets",
      "port_xmit_discards",
      "port_rcv_data",
      "port_rcv_packets",
      "port_rcv_errors",
  };

  const std::vector<std::string> rdma_hw_counters_ = {
      "np_cnp_sent",
      "rp_cnp_handled",
      "np_ecn_marked_roce_packets",
      "rx_atomic_requests",
      "rx_read_requests",
      "rx_write_requests",
  };

  return (
      init_rdma_counters_(rdma_port_counter_path_, rdma_port_counters_) &&
      init_rdma_counters_(rdma_hw_counter_path_, rdma_hw_counters_));
}

bool RdmaCounters::sampleRdmaCounters(
    std::map<std::string, int64_t>& rdmaCountersMap) {
  for (auto& rdma_counter : rdma_counters_) {
    auto sysfs_counter = std::move(rdma_counter->sysfs_counter);
    uint64_t prev_val = rdma_counter->prev;
    auto val = sysfs_counter->getSysfsCounter();
    uint64_t cur_val = (val) ? *val : prev_val;
    if (!first_sample_) {
      uint64_t diff = cur_val - prev_val;
      DLOG(INFO) << sysfs_counter->getSysfsCounterName()
                 << ": will return report value " << diff;
      if (diff < 0) {
        LOG(ERROR) << sysfs_counter->getSysfsCounterName()
                   << ": current counter value " << cur_val
                   << " is lower than previous counter value " << prev_val
                   << " thus giving negative delta " << diff;
        diff = 0;
      } else {
        const auto key = fmt::format(
            "{}.{}",
            std::string(ifname_),
            sysfs_counter->getSysfsCounterName());
        rdmaCountersMap[key] = diff;
        DLOG(INFO) << "Value stored in map: " << rdmaCountersMap[key];
      }
    }
    prev_val = cur_val;
    rdma_counter->sysfs_counter = std::move(sysfs_counter);
    rdma_counter->prev = prev_val;
    rdma_counter->cur = cur_val;
  }
  first_sample_ = false;
  return true;
}

} // namespace rdmamon
} // namespace dynolog
