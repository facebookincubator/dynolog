/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/LibkinetoJobRegistry.h"

namespace dynolog {

std::shared_ptr<LibkinetoJobRegistry> LibkinetoJobRegistry::getInstance() {
  // Use a helper struct with public constructor to work with std::make_shared
  struct EnableMakeShared : public LibkinetoJobRegistry {};
  static auto instance = std::make_shared<EnableMakeShared>();
  return instance;
}

std::pair<LibkinetoProcess&, bool>
LibkinetoJobRegistry::registerOrUpdateProcess(
    const std::string& jobId,
    const std::set<int32_t>& pids_set,
    const std::vector<int32_t>& pids) {
  // Caller must hold mutex_, ie acquire it separately via getMutex()
  auto result = jobs_[jobId].emplace(pids_set, LibkinetoProcess{});
  if (result.second) {
    // New process - store the ordered PID ancestry
    result.first->second.pids = pids;
    result.first->second.pid = pids[0]; // Leaf PID
  }
  return {result.first->second, result.second};
}

std::map<std::string, std::map<std::set<int32_t>, LibkinetoProcess>>&
LibkinetoJobRegistry::getAllJobs() {
  // Caller must hold mutex_, ie acquire it separately via getMutex()
  return jobs_;
}

size_t LibkinetoJobRegistry::getProcessCount(const std::string& jobId) const {
  std::lock_guard<std::mutex> guard(mutex_);
  auto it = jobs_.find(jobId);
  return it != jobs_.end() ? it->second.size() : 0;
}

} // namespace dynolog
