/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <chrono>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <string>
#include <vector>

namespace dynolog {

// Represents a single libkineto process instance
struct LibkinetoProcess {
  int32_t pid = 0; // Leaf process ID
  std::vector<int32_t> pids; // Ordered PID ancestry (leaf at index 0)
  std::string eventProfilerConfig;
  std::string activityProfilerConfig;
  std::chrono::time_point<std::chrono::system_clock> lastRequestTime;
};

// Shared singleton registry for tracking libkineto processes across jobs
// This registry is used by both LibkinetoConfigManager (OSS) and
// LibkinetoConfigManagerMeta (Meta-specific) to ensure both see the same
// registered processes regardless of whether they registered via IpcFabric
// or Thrift.
class LibkinetoJobRegistry {
 public:
  static std::shared_ptr<LibkinetoJobRegistry> getInstance();

  // Register or update a process group for a job
  // Returns: pair<LibkinetoProcess&, bool> where bool is true if new process
  std::pair<LibkinetoProcess&, bool> registerOrUpdateProcess(
      const std::string& jobId,
      const std::set<int32_t>& pids_set,
      const std::vector<int32_t>& pids);

  // Get all jobs (for iteration)
  std::map<std::string, std::map<std::set<int32_t>, LibkinetoProcess>>&
  getAllJobs();

  // Get count of process groups for a job
  size_t getProcessCount(const std::string& jobId) const;

  // Get the mutex for external synchronization if needed
  std::mutex& getMutex() {
    return mutex_;
  }

 private:
  LibkinetoJobRegistry() = default;

  mutable std::mutex mutex_;
  // Map: jobId -> (pids -> LibkinetoProcess)
  std::map<std::string, std::map<std::set<int32_t>, LibkinetoProcess>> jobs_;
};

} // namespace dynolog
