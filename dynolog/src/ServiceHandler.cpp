// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/ServiceHandler.h"
#include "dynolog/src/LibkinetoConfigManager.h"

namespace dynolog {

int ServiceHandler::getStatus() {
  return 1;
}

GpuProfilerResult ServiceHandler::setKinetOnDemandRequest(
    int job_id,
    const std::set<int>& pids,
    const std::string& config,
    int limit) {
  return LibkinetoConfigManager::getInstance()->setOnDemandConfig(
      // Temporarily cast to string while we iteratively migrate to string job
      // id
      std::to_string(job_id),
      pids,
      config,
      (int)LibkinetoConfigType::ACTIVITIES,
      limit);
}

} // namespace dynolog
