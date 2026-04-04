/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <glog/logging.h>
#include <cstring>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "dynolog/src/EthtoolStatsReader.h"

// @lint-ignore-every CLANGTIDY facebook-hte-BadCall-strerror

namespace dynolog::rdmamon {

class EthtoolCounters {
 public:
  explicit EthtoolCounters(std::string ifname) : ifname_(std::move(ifname)) {}
  virtual ~EthtoolCounters() = default;

  bool setupEthtoolCounters();
  bool sampleEthtoolCounters(std::map<std::string, int64_t>& rdmaCounterMap);

 private:
  std::string ifname_;
  dynolog::EthtoolStatsReader reader_;
  std::map<std::string, size_t> eth_counters_;
  std::vector<uint64_t> prevValues_;
  bool first_sample_ = true;
};

} // namespace dynolog::rdmamon
