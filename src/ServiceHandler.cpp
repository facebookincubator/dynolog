// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "ServiceHandler.h"
#include "LibkinetoConfigManager.h"

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
      job_id, pids, config, (int)LibkinetoConfigType::ACTIVITIES, limit);
}

} // namespace dynolog
