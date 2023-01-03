// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/LibkinetoConfigManager.h"
#include <fmt/core.h>
#include <fmt/format.h>
#include <glog/logging.h>
#include <exception>
#include <fstream>
#include <iterator>
#include <thread>
#include <type_traits>
#include <utility>
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
  auto t = std::chrono::system_clock::now();
  int job_count = jobs_.size();
  for (auto job_it = jobs_.begin(); job_it != jobs_.end();) {
    auto& procs = job_it->second;
    for (auto proc_it = procs.begin(); proc_it != procs.end();) {
      struct LibkinetoProcess& proc = proc_it->second;
      if ((t - proc.lastRequestTime) > kKeepAliveTimeSecs) {
        LOG(INFO) << fmt::format(
            "Stopped tracking process ({}) from job {}",
            fmt::join(proc_it->first, ","),
            job_it->first);
        onProcessCleanup(proc_it->first);
        proc_it = procs.erase(proc_it);
      } else {
        proc_it++;
      }
    }
    if (procs.empty()) {
      LOG(INFO) << "Stopped tracking job " << job_it->first;
      jobInstancesPerGpu_.erase(job_it->first);
      job_it = jobs_.erase(job_it);
    } else {
      job_it++;
    }
  }
  if (job_count != jobs_.size()) {
    LOG(INFO) << "Tracked jobs: " << jobs_.size();
  }
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
    int32_t configType) {
  VLOG(2) << fmt::format(
      "obtainOnDemandConfig({}, ({}), {})",
      jobId,
      fmt::join(pids, ","),
      configType);
  std::string ret;
  std::set<int32_t> pids_set(pids.begin(), pids.end());
  std::lock_guard<std::mutex> guard(mutex_);

  auto _emplace_result = jobs_[jobId].emplace(pids_set, LibkinetoProcess{});
  const auto& it = _emplace_result.first;
  bool newProcess = _emplace_result.second;
  struct LibkinetoProcess& process = it->second;

  if (newProcess) {
    // First time - intialize!
    // 'pids' is an ordered ancestor list starting with the
    // child (leaf) process, i.e. the one making this request.
    // Keep a copy of this pid so that clients can know which
    // pids are being profiled.
    process.pid = pids[0]; // Remember child (leaf) process
    LOG(INFO) << fmt::format(
        "Registered process ({}) for job {}.", fmt::join(pids, ", "), jobId);

    onRegisterProcess(pids_set);
  }
  if (configType & int(LibkinetoConfigType::EVENTS) &&
      !process.eventProfilerConfig.empty()) {
    ret += process.eventProfilerConfig + "\n";
    process.eventProfilerConfig.clear();
  }

  if (configType & int(LibkinetoConfigType::ACTIVITIES) &&
      !process.activityProfilerConfig.empty()) {
    ret += process.activityProfilerConfig + "\n";
    process.activityProfilerConfig.clear();
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

      process.activityProfilerConfig = config;
      res.activityProfilersTriggered.push_back(process.pid);
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

  size_t nPids = pids.size();
  // For backwards compatibility with older versions of the dyno CLI,
  // there are two conditions under which all processes should be traced:
  // 1. target PIDs are empty
  // 2. target PIDs contain a single PID, 0.
  // As older versions of the CLI are phased out, 2) will no longer need to be
  // accounted for.
  bool traceAllPids = nPids == 0 || (nPids == 1 && *pids.begin() == 0);
  {
    std::lock_guard<std::mutex> guard(mutex_);
    auto& processes = jobs_[jobId];
    for (auto& pair : processes) {
      for (const auto& pid : pair.first) {
        // Trace the process if we find a match or target pids is empty.
        if (traceAllPids || pids.find(pid) != pids.end()) {
          auto& process = pair.second;
          setOnDemandConfigForProcess(res, process, config, configType, limit);
          // the user could provide multiple pids that belong to the same the
          // LibkientoProcess object, so we break after the first match for
          // the LibkinetoProcess.
          break;
        }
      }
      if (res.activityProfilersTriggered.size() > 0) {
        onSetOnDemandConfig(pids);
      }
    }
  }

  LOG(INFO) << "On-demand request: " << res.processesMatched.size()
            << " matching processes";
  if (configType & int(LibkinetoConfigType::EVENTS)) {
    LOG(INFO) << "Installed event profiler config for "
              << res.eventProfilersTriggered.size() << " process(es) "
              << "(" << res.eventProfilersBusy << " busy)";
  }
  if (configType & int(LibkinetoConfigType::ACTIVITIES)) {
    LOG(INFO) << "Installed activity profiler config for "
              << res.activityProfilersTriggered.size() << " process(es) "
              << "(" << res.activityProfilersBusy << " busy)";
  }

  return res;
}

int LibkinetoConfigManager::processCount(const std::string& jobId) const {
  int count = 0;
  std::lock_guard<std::mutex> guard(mutex_);
  auto it = jobs_.find(jobId);
  if (it != jobs_.end()) {
    count = it->second.size();
  }
  LOG(INFO) << "Process count for job ID " << jobId << ": " << count;
  return count;
}

} // namespace dynolog
