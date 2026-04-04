/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <fmt/format.h>

#include "dynolog/src/rdmamon/EthtoolCounters.h"

namespace dynolog::rdmamon {

bool EthtoolCounters::setupEthtoolCounters() {
  const std::vector<std::string> counterNames = {
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

  if (!reader_.init(ifname_)) {
    return false;
  }

  for (size_t i = 0; i < reader_.size(); i++) {
    for (const auto& name : counterNames) {
      if (reader_.name(i) == name) {
        eth_counters_[name] = i;
        break;
      }
    }
  }

  prevValues_.resize(reader_.size(), 0);
  return true;
}

bool EthtoolCounters::sampleEthtoolCounters(
    std::map<std::string, int64_t>& countersMap) {
  if (!reader_.sample()) {
    return false;
  }

  if (!first_sample_) {
    for (const auto& [name, idx] : eth_counters_) {
      int64_t diff = static_cast<int64_t>(reader_.value(idx)) -
          static_cast<int64_t>(prevValues_[idx]);
      countersMap[fmt::format("{}.{}", ifname_, name)] = diff;
    }
  }
  first_sample_ = false;

  for (size_t i = 0; i < reader_.size(); i++) {
    prevValues_[i] = reader_.value(i);
  }
  return true;
}

} // namespace dynolog::rdmamon
