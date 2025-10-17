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
    const std::set<int32_t>& pids) {
  std::lock_guard<std::mutex> guard(mutex_);
  auto result = jobs_[jobId].emplace(pids, LibkinetoProcess{});
  return {result.first->second, result.second};
}

std::optional<
    std::reference_wrapper<std::map<std::set<int32_t>, LibkinetoProcess>>>
LibkinetoJobRegistry::findJob(const std::string& jobId) {
  std::lock_guard<std::mutex> guard(mutex_);
  auto it = jobs_.find(jobId);
  if (it != jobs_.end()) {
    return std::ref(it->second);
  }
  return std::nullopt;
}

std::map<std::string, std::map<std::set<int32_t>, LibkinetoProcess>>&
LibkinetoJobRegistry::getAllJobs() {
  // Caller must hold mutex or acquire it separately via getMutex()
  return jobs_;
}

void LibkinetoJobRegistry::removeJob(const std::string& jobId) {
  std::lock_guard<std::mutex> guard(mutex_);
  jobs_.erase(jobId);
}

void LibkinetoJobRegistry::removeProcess(
    const std::string& jobId,
    const std::set<int32_t>& pids) {
  std::lock_guard<std::mutex> guard(mutex_);
  auto it = jobs_.find(jobId);
  if (it != jobs_.end()) {
    it->second.erase(pids);
    if (it->second.empty()) {
      jobs_.erase(it);
    }
  }
}

size_t LibkinetoJobRegistry::getProcessCount(const std::string& jobId) const {
  std::lock_guard<std::mutex> guard(mutex_);
  auto it = jobs_.find(jobId);
  return it != jobs_.end() ? it->second.size() : 0;
}

size_t LibkinetoJobRegistry::getJobCount() const {
  std::lock_guard<std::mutex> guard(mutex_);
  return jobs_.size();
}

} // namespace dynolog
