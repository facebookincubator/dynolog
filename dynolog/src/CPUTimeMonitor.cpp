/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/CPUTimeMonitor.h"
#include <dynolog/src/metric_frame/MetricFrameTsUnit.h>

#include <utility>

enum { IDX_MIN = 0, IDX_SEC = 1, IDX_HUNDRED_MS = 2 };

namespace facebook::dynolog {

constexpr int kRingbufferSizeMinutes = 6;
static const std::string kHostCgroupPath = "/sys/fs/cgroup";

std::array<MetricFrameMap, 3> CPUTimeMonitor::createMetricFrameArray() {
  return {
      MetricFrameMap(
          kRingbufferSizeMinutes,
          "cputime_60s",
          "",
          std::make_shared<MetricFrameTsUnitFixInterval>(
              std::chrono::seconds(60), kRingbufferSizeMinutes)),
      MetricFrameMap(
          kRingbufferSizeMinutes * 60,
          "cputime_1s",
          "",
          std::make_shared<MetricFrameTsUnitFixInterval>(
              std::chrono::seconds(1), kRingbufferSizeMinutes * 60)),
      MetricFrameMap(
          kRingbufferSizeMinutes * 60 * 10,
          "cputime_100ms",
          "",
          std::make_shared<MetricFrameTsUnitFixInterval>(
              std::chrono::milliseconds(100),
              kRingbufferSizeMinutes * 60 * 10))};
}

CPUTimeMonitor::CPUTimeMonitor(
    std::shared_ptr<TTicker> ticker,
    bool readCgroupStat,
    uint64_t coreCount,
    std::string rootDir,
    bool isUnitTest)
    : MonitorBase<TTicker>(std::move(ticker), "CPUTimeMonitor", {1.0}),
      rootDir_(std::move(rootDir)),
      coreCount_(coreCount),
      isUnitTest_(isUnitTest),
      procUsageMetricFrames_(createMetricFrameArray()),
      readCgroupStat_(readCgroupStat),
      cgroupUsageMetricFrames_(createMetricFrameArray()) {
  std::unique_lock lock(dataLock_);

  allotmentToCpuSet_["host"] = {};
  for (auto& frame : procUsageMetricFrames_) {
    frame.addSeries(
        "host",
        std::make_shared<MetricSeries<double>>(frame.maxLength(), "host", ""));
  }
  if (readCgroupStat_) {
    for (auto& frame : cgroupUsageMetricFrames_) {
      frame.addSeries(
          "host",
          std::make_shared<MetricSeries<double>>(
              frame.maxLength(), "host", ""));
    }
    // Set host cgroup path to system root cgroup
    allotmentCgroupPaths_["host"] = kHostCgroupPath;
  }
}

std::optional<double> CPUTimeMonitor::getStat(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& allotmentId,
    Statistic stat,
    double quant,
    DataSource dataSource) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);
  auto frame = getMetricFrame(gran, dataSource);
  if (!frame.has_value()) {
    return std::nullopt;
  }
  auto slice = frame->slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return std::nullopt;
  }
  std::string key = allotmentId.value_or("host");
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return std::nullopt;
  }
  if (stat == Statistic::AVG) {
    return series->avg<double>();
  } else if (stat == Statistic::QUANTILE && quant >= 0.0 && quant <= 1.0) {
    return series->percentile(quant);
  }
  return std::nullopt;
}

std::optional<double> CPUTimeMonitor::getAvgCPUCoresUsage(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& allotmentId,
    DataSource dataSource) {
  return getStat(
      gran, seconds_ago, allotmentId, Statistic::AVG, 0.0, dataSource);
}

std::optional<double> CPUTimeMonitor::getQuantileCPUCoresUsage(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    double quantile,
    const std::optional<std::string>& allotmentId,
    DataSource dataSource) {
  return getStat(
      gran,
      seconds_ago,
      allotmentId,
      Statistic::QUANTILE,
      quantile,
      dataSource);
}

std::vector<double> CPUTimeMonitor::getRawCPUCoresUsage(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& allotmentId,
    DataSource dataSource) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);
  auto frame = getMetricFrame(gran, dataSource);
  if (!frame.has_value()) {
    return {};
  }
  auto slice = frame->slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return {};
  }
  std::string key = allotmentId.value_or("host");
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return {};
  }
  return series->raw();
}

std::optional<MetricFrameMap> CPUTimeMonitor::getMetricFrame(
    Granularity gran,
    DataSource dataSource) {
  int level;
  switch (gran) {
    case Granularity::MINUTE:
      level = IDX_MIN;
      break;
    case Granularity::SECOND:
      level = IDX_SEC;
      break;
    case Granularity::HUNDRED_MS:
      level = IDX_HUNDRED_MS;
      break;
    default:
      return std::nullopt;
  }
  // If readCgroupStat_ is disabled, always use PROC_STAT regardless of
  // requested dataSource
  return (readCgroupStat_ && dataSource == DataSource::CGROUP_STAT)
      ? cgroupUsageMetricFrames_[level]
      : procUsageMetricFrames_[level];
}

void CPUTimeMonitor::tick(TMask mask) {
  TimePoint tickTime = std::chrono::steady_clock::now();
  std::vector<uint64_t> idleTime =
      readProcStat(!allotmentsNeedPerCore_.empty());
  TimePoint measureTime = std::chrono::steady_clock::now();

  std::map<std::string, std::tuple<TimePoint, uint64_t>> cgroupCpuStats;
  if (readCgroupStat_) {
    std::shared_lock lock(dataLock_);
    for (const auto& [allotmentId, path] : allotmentCgroupPaths_) {
      auto usage = readCgroupCpuStat(path);
      if (usage.has_value()) {
        cgroupCpuStats.emplace(
            allotmentId,
            std::make_tuple(std::chrono::steady_clock::now(), usage.value()));
      }
    }
  }

  std::unique_lock lock(dataLock_);

  if (TTicker::is_major_tick(mask)) {
    // every 60s
    processProcUsage(IDX_MIN, idleTime, tickTime, measureTime, mask);
    processCgroupUsage(IDX_MIN, cgroupCpuStats, measureTime, mask);
  }
  // a tick can be both major and minor
  if (TTicker::is_minor_tick(mask)) {
    // every 1s
    processProcUsage(IDX_SEC, idleTime, tickTime, measureTime, mask);
    processCgroupUsage(IDX_SEC, cgroupCpuStats, measureTime, mask);
  }
  if (TTicker::is_subminor_tick(mask, 0)) {
    // every 100ms
    processProcUsage(IDX_HUNDRED_MS, idleTime, tickTime, measureTime, mask);
    processCgroupUsage(IDX_HUNDRED_MS, cgroupCpuStats, measureTime, mask);
  }
}

void CPUTimeMonitor::registerAllotment(
    const std::string& allotmentId,
    const std::vector<int64_t>& cpuSet,
    const std::optional<std::string>& path) {
  if (allotmentId == "" || allotmentId == "host") {
    LOG(INFO) << "Invalid allotmentId: " << allotmentId;
    return;
  }
  LOG(INFO) << "Register allotment, allotmentId: " << allotmentId
            << ", cpuSet: "
            << std::accumulate(
                   cpuSet.begin(),
                   cpuSet.end(),
                   std::string(),
                   [](const std::string& a, const int64_t& b) {
                     return a + " " + std::to_string(b);
                   })
            << ", path: " << path.value_or("(none)");
  {
    std::shared_lock lock(dataLock_);
    if (allotmentToCpuSet_.find(allotmentId) != allotmentToCpuSet_.end()) {
      LOG(INFO) << "Allotment is already registered, allotmentId: "
                << allotmentId;
      return;
    }
  }
  std::unique_lock lock(dataLock_);
  allotmentToCpuSet_[allotmentId] = cpuSet;
  if (!cpuSet.empty()) {
    allotmentsNeedPerCore_.insert(allotmentId);
  }
  for (auto& frame : procUsageMetricFrames_) {
    frame.addSeries(
        allotmentId,
        std::make_shared<MetricSeries<double>>(
            frame.maxLength(), allotmentId, ""));
  }
  for (auto& frame : cgroupUsageMetricFrames_) {
    frame.addSeries(
        allotmentId,
        std::make_shared<MetricSeries<double>>(
            frame.maxLength(), allotmentId, ""));
  }
  if (path.has_value()) {
    allotmentCgroupPaths_[allotmentId] = path.value();
  }
}

void CPUTimeMonitor::deRegisterAllotment(const std::string& allotmentId) {
  LOG(INFO) << "Deregister allotment, allotmentId: " << allotmentId;
  std::unique_lock lock(dataLock_);
  allotmentToCpuSet_.erase(allotmentId);
  allotmentsNeedPerCore_.erase(allotmentId);
  for (auto& last : procCpuTimeLast_) {
    last.erase(allotmentId);
  }
  for (auto& last : cgroupUsageLast_) {
    last.erase(allotmentId);
  }
  for (auto& frame : procUsageMetricFrames_) {
    frame.eraseSeries(allotmentId);
  }
  for (auto& frame : cgroupUsageMetricFrames_) {
    frame.eraseSeries(allotmentId);
  }
  allotmentCgroupPaths_.erase(allotmentId);
}

std::optional<uint64_t> CPUTimeMonitor::readCgroupCpuStat(
    const std::string& cgroupPath) {
  std::string path = cgroupPath + "/cpu.stat";

  FILE* fp = fopen(path.c_str(), "r");
  if (!fp) {
    LOG(ERROR) << "Error opening " << path;
    return std::nullopt;
  }

  char buf[64];
  if (!fgets(buf, sizeof(buf), fp)) {
    LOG(ERROR) << "Error reading " << path;
    fclose(fp);
    return std::nullopt;
  }

  unsigned long long usage;
  int num = sscanf(buf, "%*s %Lu", &usage);
  if (num != 1) {
    LOG(ERROR) << "Error parsing " << path;
    fclose(fp);
    return std::nullopt;
  }

  fclose(fp);
  return usage;
}

std::vector<uint64_t> CPUTimeMonitor::readProcStat(bool read_per_core) {
  // based on KernelMonitor.cpp
  // For unclear reasons, a C++ implementation is rather slower
  static FILE* fp = nullptr;
  char buf[320];

  std::vector<uint64_t> ret;

  if (!fp) {
    const auto& path = rootDir_ + "/proc/stat";
    LOG(INFO) << "Opening " << path << " for reading";
    if (!(fp = fopen(path.c_str(), "r"))) {
      LOG(ERROR) << "Error opening /proc/stat";
    }
  }

  if (!fp) {
    return {};
  }

  rewind(fp);
  fflush(fp);

  auto readIdle = [&]() -> std::optional<uint64_t> {
    if (!fgets(buf, sizeof(buf), fp)) {
      LOG(ERROR) << "Error reading /proc/stat";
      return std::nullopt;
    }
    unsigned long long idle;
    int num = 0;
    num = sscanf(buf, "%*s %*s %*s %*s %Lu", &idle);
    if (num != 1) {
      LOG(ERROR) << "Error parsing /proc/stat";
      return std::nullopt;
    }
    return idle;
  };

  // First line is an aggregation over all CPUs
  auto system_idle = readIdle();
  if (system_idle != std::nullopt) {
    ret.push_back(*system_idle);
  }
  if (!read_per_core) {
    return ret;
  }

  uint64_t lines = 0;
  while (lines < coreCount_) {
    auto perCoreIdle = readIdle();
    if (!perCoreIdle) {
      return {};
    }
    ret.push_back(*perCoreIdle);
    ++lines;
  }
  return ret;
}

void CPUTimeMonitor::processProcUsage(
    int level,
    const std::vector<uint64_t>& idleTime,
    TimePoint tickTime,
    TimePoint measureTime,
    TMask mask) {
  if (idleTime.empty()) {
    return;
  }
  auto& frame = procUsageMetricFrames_[level];
  auto& lastCpuTime = procCpuTimeLast_[level];
  auto& lastTickTime = procTimeLast_[level];
  MapSamplesT line;

  for (const auto& [allotmentId, cpuSet] : allotmentToCpuSet_) {
    uint64_t newVal = idleTime[0];
    uint64_t coreCount = coreCount_;
    if (!cpuSet.empty()) {
      newVal = 0;
      for (const auto& cpu : cpuSet) {
        newVal += idleTime[cpu + 1]; // zeroth line is system-wide
      }
      coreCount = cpuSet.size();
    }
    if (lastCpuTime.find(allotmentId) == lastCpuTime.end()) {
      lastCpuTime[allotmentId] = newVal;
      continue;
    }
    uint64_t lastVal = lastCpuTime[allotmentId];
    uint64_t idleDelta =
        (newVal - lastVal) * 10; // /proc/stat reports in 10ms, convert to ms
    lastCpuTime[allotmentId] = newVal;

    uint64_t wallDelta = std::chrono::duration_cast<std::chrono::milliseconds>(
                             measureTime - lastTickTime)
                             .count();
    if (isUnitTest_) {
      wallDelta = 100;
    }
    if (wallDelta == 0) {
      // log on major tick only to avoid spam
      if (TTicker::is_major_tick(mask)) {
        LOG(WARNING) << "Wall delta is 0, cannot compute CPU cores usage";
      }
      continue;
    }
    uint64_t usageDelta = (coreCount * wallDelta) - idleDelta;

    double CPUCoresUsage = (double)usageDelta / wallDelta;

    if (CPUCoresUsage < 0 || CPUCoresUsage > (double)coreCount) {
      // log on major tick only to avoid spam
      if (TTicker::is_major_tick(mask)) {
        LOG(ERROR) << "Invalid CPU cores usage at level: " << level
                   << " allotmentId: " << allotmentId
                   << " wallDelta: " << wallDelta
                   << " CPUCoresUsage: " << CPUCoresUsage
                   << " idleDelta: " << idleDelta << " newVal: " << newVal
                   << " lastVal: " << lastVal << " coreCount: " << coreCount
                   << " data: "
                   << std::accumulate(
                          idleTime.begin(),
                          idleTime.end(),
                          std::string(),
                          [](const std::string& a, const uint64_t& b) {
                            return a + " " + std::to_string(b);
                          });
      }
      continue;
    }

    line.emplace_back(allotmentId, CPUCoresUsage);
  }
  if (!line.empty()) {
    frame.addSamples(line, tickTime);
  }
  procTimeLast_[level] = tickTime;
}

void CPUTimeMonitor::processCgroupUsage(
    int level,
    const std::map<std::string, std::tuple<TimePoint, uint64_t>>&
        cgroupCpuStats,
    TimePoint tickTime,
    TMask mask) {
  if (!readCgroupStat_) {
    return;
  }

  auto& frame = cgroupUsageMetricFrames_[level];
  auto& lastUsage = cgroupUsageLast_[level];
  auto& lastTime = cgroupTimeLast_[level];
  MapSamplesT line;

  for (const auto& [allotmentId, cpuStat] : cgroupCpuStats) {
    auto [readTime, newUsage] = cpuStat;
    if (lastUsage.find(allotmentId) == lastUsage.end() ||
        lastTime.find(allotmentId) == lastTime.end()) {
      lastUsage[allotmentId] = newUsage;
      lastTime[allotmentId] = readTime;
      continue;
    }

    uint64_t oldUsage = lastUsage[allotmentId];
    TimePoint oldTime = lastTime[allotmentId];
    lastUsage[allotmentId] = newUsage;
    lastTime[allotmentId] = readTime;

    uint64_t wallDelta = std::chrono::duration_cast<std::chrono::microseconds>(
                             readTime - oldTime)
                             .count(); // cpu.stat reports in microseconds
    if (wallDelta == 0) {
      // log on major tick only to avoid spam
      if (TTicker::is_major_tick(mask)) {
        LOG(INFO) << "Wall delta is 0, cannot compute CPU cores usage";
      }
      continue;
    }
    double cgroupUsage = (double)(newUsage - oldUsage) / wallDelta;

    if (cgroupUsage < 0 || cgroupUsage > (double)coreCount_) {
      // log on major tick only to avoid spam
      if (TTicker::is_major_tick(mask)) {
        LOG(ERROR) << "Invalid cgroup usage at level: " << level
                   << " allotmentId: " << allotmentId
                   << " wallDelta: " << wallDelta
                   << " cgroupUsage: " << cgroupUsage
                   << " newUsage: " << newUsage << " oldUsage: " << oldUsage
                   << " coreCount: " << coreCount_;
      }
      continue;
    }

    line.emplace_back(allotmentId, cgroupUsage);
  }
  if (!line.empty()) {
    frame.addSamples(line, tickTime);
  }
}

} // namespace facebook::dynolog
