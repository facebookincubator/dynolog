/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/LibkinetoConfigManager.h"
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <glog/logging.h>
#include <exception>
#include <fstream>
#include <iterator>
#include <thread>
#include <utility>
#include "dynolog/src/LibkinetoJobRegistry.h"
#include "hbt/src/common/System.h"
#ifdef __linux__
#include <sys/prctl.h>
#endif

namespace dynolog {

namespace {

constexpr std::chrono::seconds kKeepAliveTimeSecs(60);
constexpr char kConfigFile[] = "/etc/libkineto.conf";

inline void setThreadName(const std::string& name) {
#ifdef __linux__
  constexpr size_t kMaxBuff = 16;
  std::array<char, kMaxBuff> buff;
  std::size_t len = name.copy(buff.begin(), 0, kMaxBuff - 1);
  buff[len] = '\0';
  ::prctl(PR_SET_NAME, buff.begin(), 0, 0, 0);
#endif
}

} // namespace

static std::string addTraceIdToConfigString(
    const std::string& trace_id,
    const std::string& config) {
  const std::string kTraceIdIdentifier = "REQUEST_TRACE_ID";
  return fmt::format(
      R"(
    {}
    {}={})",
      config,
      kTraceIdIdentifier,
      trace_id);
}

static std::string generateTraceId(int32_t pid) {
  // Hostname + PID + timestamp should be a unique trace id in the context
  // of this code's execution
  std::string str_trace_id = fmt::format(
      "{}:{}:{}", facebook::hbt::getHostName(), pid, std::time(nullptr));
  std::size_t hashed_trace_id = std::hash<std::string>{}(str_trace_id);
  return std::to_string(hashed_trace_id);
}

LibkinetoConfigManager::LibkinetoConfigManager() {
  managerThread_ = new std::thread(&LibkinetoConfigManager::start, this);
}

LibkinetoConfigManager::~LibkinetoConfigManager() {
  stopFlag_ = true;
  managerCondVar_.notify_one();
  managerThread_->join();
  delete managerThread_;
  managerThread_ = nullptr;
}

std::shared_ptr<LibkinetoConfigManager> LibkinetoConfigManager::getInstance() {
  static auto instance = std::make_shared<LibkinetoConfigManager>();
  return instance;
}

void LibkinetoConfigManager::start() {
  setThreadName("kinetoConfigMgr");
  // Periodically clean the job table and check base config changes.
  // If a libkineto instance hasn't contacted us for a while, remove it.
  LOG(INFO) << "Starting LibkinetoConfigManager runloop";
  while (true) {
    refreshBaseConfig();
    std::unique_lock<std::mutex> lock(mutex_);
    managerCondVar_.wait_for(lock, kKeepAliveTimeSecs);
    if (stopFlag_) {
      break;
    }
    runGc();
  }
}

// return "" on errors. Otherwise a config string.
static std::string readConfigFromConfigFile(const char* filename) {
  // Read whole file into a string.
  std::ifstream file(filename);
  if (!file) {
    return "";
  }
  std::string conf;
  try {
    conf.assign(
        std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
  } catch (std::exception& e) {
    LOG(ERROR) << "Error in reading libkineto config from config file: "
               << e.what();
  }
  return conf;
}

void LibkinetoConfigManager::refreshBaseConfig() {
  auto cfg = readConfigFromConfigFile(kConfigFile);
  if (!cfg.empty() && cfg != baseConfig_) {
    std::lock_guard<std::mutex> guard(mutex_);
    baseConfig_ = cfg;
  }
}

void LibkinetoConfigManager::runGc() {
  auto registry = LibkinetoJobRegistry::getInstance();
  std::lock_guard<std::mutex> guard(registry->getMutex());

  auto& jobs = registry->getAllJobs();
  auto t = std::chrono::system_clock::now();
  int job_count = static_cast<int>(jobs.size());
  int total_processes_before = 0;
  int total_processes_after = 0;
  int processes_removed = 0;

  // Count total processes before GC
  for (const auto& [jobId, procs] : jobs) {
    total_processes_before += static_cast<int>(procs.size());
  }

  LOG(INFO) << fmt::format(
      "Starting GC: {} job(s), {} total process group(s)",
      job_count,
      total_processes_before);

  for (auto job_it = jobs.begin(); job_it != jobs.end();) {
    auto& procs = job_it->second;
    LOG(INFO) << fmt::format(
        "GC: Checking job '{}' with {} process group(s)",
        job_it->first,
        procs.size());

    for (auto proc_it = procs.begin(); proc_it != procs.end();) {
      struct LibkinetoProcess& proc = proc_it->second;
      auto time_since_last_request =
          std::chrono::duration_cast<std::chrono::seconds>(
              t - proc.lastRequestTime);

      if (time_since_last_request > kKeepAliveTimeSecs) {
        LOG(INFO) << fmt::format(
            "GC: Removing process ({}) from job '{}' (last seen {} seconds ago, threshold is {} seconds)",
            fmt::join(proc_it->first, ","),
            job_it->first,
            time_since_last_request.count(),
            kKeepAliveTimeSecs.count());
        onProcessCleanup(proc_it->first);
        proc_it = procs.erase(proc_it);
        processes_removed++;
      } else {
        LOG(INFO) << fmt::format(
            "GC: Keeping process ({}) from job '{}' (last seen {} seconds ago)",
            fmt::join(proc_it->first, ","),
            job_it->first,
            time_since_last_request.count());
        proc_it++;
      }
    }
    if (procs.empty()) {
      LOG(INFO) << fmt::format("GC: Removing empty job '{}'", job_it->first);
      jobInstancesPerGpu_.erase(job_it->first);
      job_it = jobs.erase(job_it);
    } else {
      job_it++;
    }
  }

  // Count total processes after GC
  for (const auto& [jobId, procs] : jobs) {
    total_processes_after += static_cast<int>(procs.size());
  }

  LOG(INFO) << fmt::format(
      "GC completed: Removed {} process group(s), {} job(s) remaining with {} total process group(s)",
      processes_removed,
      jobs.size(),
      total_processes_after);
}

int32_t LibkinetoConfigManager::registerLibkinetoContext(
    const std::string& jobId,
    int32_t pid,
    int32_t gpu) {
  std::lock_guard<std::mutex> guard(mutex_);
  auto& instances = jobInstancesPerGpu_[jobId][gpu];
  instances.insert(pid);
  LOG(INFO) << fmt::format("Registered process ({}) for job {}.", pid, jobId);
  return instances.size();
}

// Called by libkineto instances periodically.
// In addition to returning a configuration string if one is found,
// register the jobId and set of pids with the config manager.
// This is how we keep track of running instances of libkineto.
// LibkinetoConfigManager::run() periodically scans the table
// for processes no longer calling this function and removes them.
std::string LibkinetoConfigManager::obtainOnDemandConfig(
    const std::string& jobId,
    const std::vector<int32_t>& pids,
    int32_t configType,
    const std::string& category) {
  VLOG(2) << fmt::format(
      "obtainOnDemandConfig({}, ({}), {}, {})",
      jobId,
      fmt::join(pids, ","),
      configType,
      category);

  std::string ret;
  std::set<int32_t> pids_set(pids.begin(), pids.end());
  auto registry = LibkinetoJobRegistry::getInstance();
  std::lock_guard<std::mutex> guard(registry->getMutex());

  auto [process, newProcess] =
      registry->registerOrUpdateProcess(jobId, pids_set, pids);

  if (newProcess) {
    // First time - intialize!
    // 'pids' is an ordered ancestor list starting with the
    // child (leaf) process, i.e. the one making this request.
    process.pid_ipc_channel_used = category;
    LOG(INFO) << fmt::format(
        "Registered process ({}) for job '{}'. Leaf PID: {}. Request channel: {}",
        fmt::join(pids, ", "),
        jobId,
        process.pid,
        category);

    onRegisterProcess(pids_set);
  }

  bool hasEventConfig = !process.eventProfilerConfig.empty();
  bool hasActivityConfig = !process.activityProfilerConfig.empty();

  if (configType & int(LibkinetoConfigType::EVENTS)) {
    if (hasEventConfig) {
      LOG(INFO) << fmt::format(
          "Returning event profiler config for process ({}) in job '{}'",
          fmt::join(pids, ", "),
          jobId);
      ret += process.eventProfilerConfig + "\n";
      process.eventProfilerConfig.clear();
    }
  }

  if (configType & int(LibkinetoConfigType::ACTIVITIES)) {
    if (hasActivityConfig) {
      LOG(INFO) << fmt::format(
          "Returning activity profiler config for process ({}) in job '{}'",
          fmt::join(pids, ", "),
          jobId);
      ret += process.activityProfilerConfig + "\n";
      process.activityProfilerConfig.clear();
    }
  }

  // Track last request time so we know which libkineto instances
  // are currently active.
  process.lastRequestTime = std::chrono::system_clock::now();

  return ret;
}

void LibkinetoConfigManager::setOnDemandConfigForProcess(
    GpuProfilerResult& res,
    LibkinetoProcess& process,
    const std::string& config,
    int32_t configType /* LibkinetoConfigType */,
    int32_t limit) {
  res.processesMatched.push_back(process.pid);

  if (res.eventProfilersTriggered.size() < limit &&
      configType & int(LibkinetoConfigType::EVENTS)) {
    if (process.eventProfilerConfig.empty()) {
      process.eventProfilerConfig = config;
      res.eventProfilersTriggered.push_back(process.pid);
    } else {
      res.eventProfilersBusy++;
    }
  }
  if (res.activityProfilersTriggered.size() < limit &&
      configType & int(LibkinetoConfigType::ACTIVITIES)) {
    if (process.activityProfilerConfig.empty()) {
      preCheckOnDemandConfig(process);

      std::string trace_id = generateTraceId(process.pid);
      std::string updatedConfig = addTraceIdToConfigString(trace_id, config);

      res.activityProfilersTriggered.push_back(process.pid);
      process.activityProfilerConfig = updatedConfig;
      res.traceIds.push_back(trace_id);

      LOG(INFO) << " PID: " << process.pid << ", Trace Id: " << trace_id;
    } else {
      res.activityProfilersBusy++;
    }
  }
}

// Called by clients to control one or more libkineto instances.
// The config is any legal libkineto on-demand config (see wiki).
// Set config type to indicate whether this request is for
// event profiling, activity profiling or both.
// The limit argument is used when the job uses multiple processes or
// the pid is a parent pid of multiple processes with libkineto.
// For example, when specifying a pid with 8 child processes,
// the limit argument can be used to profile 2 of those.
GpuProfilerResult LibkinetoConfigManager::setOnDemandConfig(
    const std::string& jobId,
    const std::set<int32_t>& pids,
    const std::string& config,
    int32_t configType /* LibkinetoConfigType */,
    int32_t limit) {
  LOG(INFO) << fmt::format(
      "Initiating on-demand GPU profiling for job ID {}, pids [{}]",
      jobId,
      fmt::join(pids, ","));

  GpuProfilerResult res;
  res.activityProfilersBusy = 0;
  res.eventProfilersBusy = 0;
  res.manifoldChromeTrace = false; // Default to false

  size_t nPids = pids.size();
  // For backwards compatibility with older versions of the dyno CLI,
  // there are two conditions under which all processes should be traced:
  // 1. target PIDs are empty
  // 2. target PIDs contain a single PID, 0.
  // As older versions of the CLI are phased out, 2) will no longer need to be
  // accounted for.
  bool traceAllPids = nPids == 0 || (nPids == 1 && *pids.begin() == 0);
  {
    auto registry = LibkinetoJobRegistry::getInstance();
    std::lock_guard<std::mutex> guard(registry->getMutex());
    auto& jobs = registry->getAllJobs();

    // Debug: Log all currently tracked jobs and processes INSIDE the lock
    LOG(INFO) << fmt::format("Currently tracking {} job(s)", jobs.size());
    for (const auto& [tracked_jobId, processMap] : jobs) {
      LOG(INFO) << fmt::format(
          "  Job ID '{}': {} process group(s)",
          tracked_jobId,
          processMap.size());
      for (const auto& [pids_set, proc] : processMap) {
        LOG(INFO) << fmt::format(
            "    Process: ({}) [leaf PID: {}]",
            fmt::join(pids_set, ","),
            proc.pid);
      }
    }

    if (auto it = jobs.find(jobId); it != jobs.end()) {
      auto& processes = it->second;
      for (auto& pair : processes) {
        for (const auto& pid : pair.first) {
          // Trace the process if we find a match or target pids is empty.
          if (traceAllPids || pids.find(pid) != pids.end()) {
            auto& process = pair.second;
            // Set manifoldChromeTrace to true if category is "thrift"
            if (process.pid_ipc_channel_used == "thrift") {
              res.manifoldChromeTrace = true;
            }
            setOnDemandConfigForProcess(
                res, process, config, configType, limit);
            // the user could provide multiple pids that belong to the same the
            // LibkientoProcess object, so we break after the first match for
            // the LibkinetoProcess.
            break;
          }
        }
      }
      if (!res.activityProfilersTriggered.empty()) {
        onSetOnDemandConfig(pids);
      }
    }
  }

  LOG(INFO) << "On-demand request: " << res.processesMatched.size()
            << " matching processes";
  if (configType & int(LibkinetoConfigType::EVENTS)) {
    LOG(INFO) << "Installed event profiler config for "
              << res.eventProfilersTriggered.size() << " process(es) " << "("
              << res.eventProfilersBusy << " busy)";
  }
  if (configType & int(LibkinetoConfigType::ACTIVITIES)) {
    LOG(INFO) << "Installed activity profiler config for "
              << res.activityProfilersTriggered.size() << " process(es) " << "("
              << res.activityProfilersBusy << " busy)";
  }
  return res;
}

int LibkinetoConfigManager::processCount(const std::string& jobId) const {
  auto registry = LibkinetoJobRegistry::getInstance();
  int count = static_cast<int>(registry->getProcessCount(jobId));
  LOG(INFO) << "Process count for job ID " << jobId << ": " << count;
  return count;
}

} // namespace dynolog
