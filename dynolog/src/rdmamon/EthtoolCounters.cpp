// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <fmt/format.h>
#include <gflags/gflags.h>

#include "dynolog/src/rdmamon/EthtoolCounters.h"

#ifdef FBCODE
#include "secure_lib/secure_string.h"
#endif // FBCODE

namespace dynolog {
namespace rdmamon {

bool EthtoolCounters::setupEthtoolCounters() {
  const std::vector<std::string> eth_counter_names_ = {
      "tx_pause_ctrl_phy",
      "tx_prio0_pause",
      "tx_prio1_pause",
      "tx_prio2_pause",
      "tx_prio3_pause",
      "tx_prio4_pause",
      "tx_prio5_pause",
      "tx_prio6_pause",
      "tx_prio7_pause",
      "tx_pause_storm_warning_events",
      "tx_pause_storm_error_events",
  };
  return setup_ethtool_counters(eth_counter_names_);
}

bool EthtoolCounters::sampleEthtoolCounters(
    std::map<std::string, int64_t>& countersMap) {
  if (!get_current_ethtool_counters()) {
    return false;
  }

  if (!first_sample_) {
    for (auto it = eth_counters_.begin(); it != eth_counters_.end(); it++) {
      int64_t diff =
          cur_eth_stats_->data[it->second] - prev_eth_stats_->data[it->second];
      const auto key = fmt::format("{}.{}", ifname_, it->first);
      countersMap[key] = diff;
    }
  }
  first_sample_ = false;
  size_t copy_sz =
      (gstrings_->len * sizeof(uint64_t)) + sizeof(struct ethtool_stats);
#ifdef FBCODE
  if (try_checked_memcpy(prev_eth_stats_, stats_sz_, cur_eth_stats_, copy_sz) !=
      0) {
    LOG_EVERY_N(WARNING, 100)
        << "Uanble to copy current stats due to insufficient space";
    return false;
  }
#else
  memcpy(prev_eth_stats_, cur_eth_stats_, copy_sz);
#endif // FBCODE
  return true;
}

} // namespace rdmamon
} // namespace dynolog
