// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/rdmamon/RdmaMonitor.h"

namespace dynolog {
namespace rdmamon {

bool RdmaPortMonitor::setupRdmaPortMonitor() {
  bool r1 = eth_counters_->setupEthtoolCounters();
  bool r2 = rdma_counters_->setupRdmaCounters();
  return (r1 && r2);
}

bool RdmaPortMonitor::sampleRdmaPortMonitor(
    std::map<std::string, int64_t>& rdmaPortCounterMap) {
  bool r1 = eth_counters_->sampleEthtoolCounters(rdmaPortCounterMap);
  bool r2 = rdma_counters_->sampleRdmaCounters(rdmaPortCounterMap);
  return (r1 && r2);
}

bool RdmaMonitor::setupRdmaMonitor() {
  bool ret = true;
  for (auto const& monitor : monitors_) {
    if (!monitor->setupRdmaPortMonitor()) {
      LOG(ERROR) << "Unable to setup RDMA monitor for "
                 << monitor->getRdmaIfname();
      ret = false;
    }
  }
  return ret;
}

bool RdmaMonitor::sampleRdmaMonitor(
    std::map<std::string, int64_t>& rdmaCounterMap) {
  bool ret = true;
  for (auto const& monitor : monitors_) {
    if (!monitor->sampleRdmaPortMonitor(rdmaCounterMap)) {
      LOG(ERROR) << "Unable to sample RDMA monitor for "
                 << monitor->getRdmaIfname();
      ret = false;
    }
  }
  return ret;
}

} // namespace rdmamon
} // namespace dynolog
