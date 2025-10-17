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
#include <optional>
#include <set>
#include <string>

namespace dynolog {

// Represents a single libkineto process instance
struct LibkinetoProcess {
  int32_t pid = 0; // Leaf process ID
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
      const std::set<int32_t>& pids);

  // Find processes for a job
  // Returns optional reference to the process map for the job, or nullopt if
  // not found
  std::optional<
      std::reference_wrapper<std::map<std::set<int32_t>, LibkinetoProcess>>>
  findJob(const std::string& jobId);

  // Get all jobs (for iteration)
  std::map<std::string, std::map<std::set<int32_t>, LibkinetoProcess>>&
  getAllJobs();

  // Remove a job entirely
  void removeJob(const std::string& jobId);

  // Remove a specific process group from a job
  void removeProcess(const std::string& jobId, const std::set<int32_t>& pids);

  // Get count of process groups for a job
  size_t getProcessCount(const std::string& jobId) const;

  // Get total number of jobs
  size_t getJobCount() const;

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
