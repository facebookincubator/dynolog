// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <set>
#include <string>

#include "LibkinetoConfigManager.h"

namespace dynolog {

// Service Handler : acts as a generic handler for requests made to the
//   daemmon. This can be wrapped inside RPC protocols to handle the
//   communication over the network.

class ServiceHandler {
 public:
  // returns the state of the service
  int getStatus();

  GpuProfilerResult setKinetOnDemandRequest(
      int job_id,
      const std::set<int>& pids,
      const std::string& config,
      int limit);
  // ... more to come
};

} // namespace dynolog
