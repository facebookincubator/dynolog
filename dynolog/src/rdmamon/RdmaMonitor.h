// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <map>
#include "dynolog/src/rdmamon/EthtoolCounters.h"
#include "dynolog/src/rdmamon/RdmaCounters.h"

namespace dynolog {
namespace rdmamon {

class RdmaPortMonitor {
 public:
  explicit RdmaPortMonitor(const std::string& ifname) : ifname_(ifname) {
    eth_counters_ = std::make_unique<EthtoolCounters>(ifname);
    rdma_counters_ = std::make_unique<RdmaCounters>(ifname);
  }

  [[nodiscard]] bool setupRdmaPortMonitor();
  [[nodiscard]] bool sampleRdmaPortMonitor(
      std::map<std::string, int64_t>& rdmaPortCounterMap);

  std::string getRdmaIfname() const {
    return ifname_;
  }

 private:
  std::string ifname_;
  std::unique_ptr<EthtoolCounters> eth_counters_;
  std::unique_ptr<RdmaCounters> rdma_counters_;
};

class RdmaMonitor {
 public:
  explicit RdmaMonitor() {
    std::string path = "/sys/class/net/";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
      std::string ifname = entry.path().stem();
      if (0 == ifname.compare("lo")) {
        continue;
      }
      auto monitor = std::make_unique<RdmaPortMonitor>(ifname);
      monitors_.push_back(std::move(monitor));
    }
  }

  virtual ~RdmaMonitor() {
    monitors_.clear();
  }

  [[nodiscard]] bool setupRdmaMonitor();
  [[nodiscard]] bool sampleRdmaMonitor(
      std::map<std::string, int64_t>& rdmaCounterMap);

 private:
  std::vector<std::unique_ptr<RdmaPortMonitor>> monitors_;
};

} // namespace rdmamon
} // namespace dynolog
