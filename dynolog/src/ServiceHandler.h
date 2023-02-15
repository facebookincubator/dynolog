// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <set>
#include <string>
#include "dynolog/src/LibkinetoConfigManager.h"
#include "dynolog/src/gpumon/DcgmGroupInfo.h"

namespace dynolog {

// Service Handler : acts as a generic handler for requests made to the
//   daemmon. This can be wrapped inside RPC protocols to handle the
//   communication over the network.

class ServiceHandler {
 public:
  explicit ServiceHandler(std::shared_ptr<gpumon::DcgmGroupInfo> dcgm)
      : dcgm_(dcgm) {}
  // returns the state of the service
  int getStatus();
  std::string getVersion();

  GpuProfilerResult setKinetOnDemandRequest(
      int job_id,
      const std::set<int>& pids,
      const std::string& config,
      int limit);
  // ... more to come
  bool dcgmProfPause(int duration_s);
  bool dcgmProfResume();

 private:
  std::shared_ptr<gpumon::DcgmGroupInfo> dcgm_;
};

} // namespace dynolog
