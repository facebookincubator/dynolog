/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/CPUTimeMonitor.h"
#include <dynolog/src/metric_frame/MetricFrameTsUnit.h>

#include <algorithm>
#include <utility>

enum { IDX_MIN = 0, IDX_SEC = 1, IDX_HUNDRED_MS = 2 };

namespace facebook::dynolog {

// Series key suffixes for CPU breakdown metrics
static const std::string kBreakdownIdle = ".idle";
static const std::string kBreakdownSoftirq = ".softirq";
static const std::string kBreakdownIowait = ".iowait";
static const std::string kBreakdownHardirq = ".hardirq";
static const std::string kBreakdownNice = ".nice";

// All breakdown suffixes in a single list to avoid iterating in multiple
// places.
static const std::vector<std::string> kBreakdownSuffixes = {
    kBreakdownIdle,
    kBreakdownSoftirq,
    kBreakdownIowait,
    kBreakdownHardirq,
    kBreakdownNice};

// Helper to add breakdown series for a target to a MetricFrameMap.
static void addBreakdownSeries(
    MetricFrameMap& frame,
    const std::string& targetId) {
  for (const auto& suffix : kBreakdownSuffixes) {
    std::string key = targetId + suffix;
    frame.addSeries(
        key,
        std::make_shared<MetricSeries<double>>(frame.maxLength(), key, ""));
  }
}

static const std::string& breakdownSuffix(
    CPUTimeMonitor::CpuBreakdown breakdown) {
  switch (breakdown) {
    case CPUTimeMonitor::CpuBreakdown::IDLE:
      return kBreakdownIdle;
    case CPUTimeMonitor::CpuBreakdown::SOFTIRQ:
      return kBreakdownSoftirq;
    case CPUTimeMonitor::CpuBreakdown::IOWAIT:
      return kBreakdownIowait;
    case CPUTimeMonitor::CpuBreakdown::HARDIRQ:
      return kBreakdownHardirq;
    case CPUTimeMonitor::CpuBreakdown::NICE:
      return kBreakdownNice;
  }
  return kBreakdownIdle; // unreachable
}

constexpr int kRingbufferSizeMinutes = 6;
static const std::string kHostCgroupPath = "/sys/fs/cgroup";

static std::optional<int> granularityToLevel(CPUTimeMonitor::Granularity gran) {
  switch (gran) {
    case CPUTimeMonitor::Granularity::MINUTE:
      return IDX_MIN;
    case CPUTimeMonitor::Granularity::SECOND:
      return IDX_SEC;
    case CPUTimeMonitor::Granularity::HUNDRED_MS:
      return IDX_HUNDRED_MS;
  }
  return std::nullopt;
}

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

  targetToCpuSet_["host"] = {};
  for (auto& frame : procUsageMetricFrames_) {
    frame.addSeries(
        "host",
        std::make_shared<MetricSeries<double>>(frame.maxLength(), "host", ""));
    addBreakdownSeries(frame, "host");
  }
  if (readCgroupStat_) {
    for (auto& frame : cgroupUsageMetricFrames_) {
      frame.addSeries(
          "host",
          std::make_shared<MetricSeries<double>>(
              frame.maxLength(), "host", ""));
    }
    // Set host cgroup path to system root cgroup
    targetCgroupPaths_["host"] = kHostCgroupPath;
  }
}

std::optional<double> CPUTimeMonitor::getStat(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& targetId,
    Statistic stat,
    double quant,
    DataSource dataSource) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);
  const auto* frame = getMetricFrame(gran, dataSource);
  if (frame == nullptr) {
    return std::nullopt;
  }
  auto slice = frame->slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return std::nullopt;
  }
  std::string key = targetId.value_or("host");
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
    const std::optional<std::string>& targetId,
    DataSource dataSource) {
  return getStat(gran, seconds_ago, targetId, Statistic::AVG, 0.0, dataSource);
}

std::optional<double> CPUTimeMonitor::getQuantileCPUCoresUsage(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    double quantile,
    const std::optional<std::string>& targetId,
    DataSource dataSource) {
  return getStat(
      gran, seconds_ago, targetId, Statistic::QUANTILE, quantile, dataSource);
}

std::vector<double> CPUTimeMonitor::getRawCPUCoresUsage(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& targetId,
    DataSource dataSource) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);
  const auto* frame = getMetricFrame(gran, dataSource);
  if (frame == nullptr) {
    return {};
  }
  auto slice = frame->slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return {};
  }
  std::string key = targetId.value_or("host");
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return {};
  }
  return series->raw();
}

std::optional<double> CPUTimeMonitor::getCpuBreakdownAvg(
    Granularity gran,
    uint64_t seconds_ago,
    CpuBreakdown breakdown,
    const std::optional<std::string>& targetId) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);

  auto levelOpt = granularityToLevel(gran);
  if (!levelOpt.has_value()) {
    return std::nullopt;
  }
  int level = *levelOpt;

  auto& frame = procUsageMetricFrames_[level];
  auto slice = frame.slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return std::nullopt;
  }
  // targetId identifies the monitoring target (e.g., an allotment UUID).
  // "host" is the default prefix representing whole-host aggregate data.
  std::string key = targetId.value_or("host") + breakdownSuffix(breakdown);
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return std::nullopt;
  }
  return series->avg<double>();
}

const MetricFrameMap* CPUTimeMonitor::getMetricFrame(
    Granularity gran,
    DataSource dataSource) const {
  int level = 0;
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
      return nullptr;
  }
  // If readCgroupStat_ is disabled, always use PROC_STAT regardless of
  // requested dataSource
  return (readCgroupStat_ && dataSource == DataSource::CGROUP_STAT)
      ? &cgroupUsageMetricFrames_[level]
      : &procUsageMetricFrames_[level];
}

std::optional<double> CPUTimeMonitor::getCpuBreakdownMin(
    Granularity gran,
    uint64_t seconds_ago,
    CpuBreakdown breakdown,
    const std::optional<std::string>& targetId) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);

  auto levelOpt = granularityToLevel(gran);
  if (!levelOpt.has_value()) {
    return std::nullopt;
  }
  int level = *levelOpt;

  auto& frame = procUsageMetricFrames_[level];
  auto slice = frame.slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return std::nullopt;
  }
  std::string key = targetId.value_or("host") + breakdownSuffix(breakdown);
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return std::nullopt;
  }
  auto data = series->raw();
  return *std::min_element(data.begin(), data.end());
}

std::optional<double> CPUTimeMonitor::getCpuBreakdownMax(
    Granularity gran,
    uint64_t seconds_ago,
    CpuBreakdown breakdown,
    const std::optional<std::string>& targetId) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);

  auto levelOpt = granularityToLevel(gran);
  if (!levelOpt.has_value()) {
    return std::nullopt;
  }
  int level = *levelOpt;

  auto& frame = procUsageMetricFrames_[level];
  auto slice = frame.slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return std::nullopt;
  }
  std::string key = targetId.value_or("host") + breakdownSuffix(breakdown);
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return std::nullopt;
  }
  auto data = series->raw();
  return *std::max_element(data.begin(), data.end());
}

std::optional<double> CPUTimeMonitor::getMinCPUCoresUsage(
    Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& targetId,
    DataSource dataSource) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);

  auto levelOpt = granularityToLevel(gran);
  if (!levelOpt.has_value()) {
    return std::nullopt;
  }
  int level = *levelOpt;

  auto& frame = (readCgroupStat_ && dataSource == DataSource::CGROUP_STAT)
      ? cgroupUsageMetricFrames_[level]
      : procUsageMetricFrames_[level];
  auto slice = frame.slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return std::nullopt;
  }
  std::string key = targetId.value_or("host");
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return std::nullopt;
  }
  auto data = series->raw();
  return *std::min_element(data.begin(), data.end());
}

std::optional<double> CPUTimeMonitor::getMaxCPUCoresUsage(
    Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& targetId,
    DataSource dataSource) {
  TimePoint now = std::chrono::steady_clock::now();
  std::shared_lock lock(dataLock_);

  auto levelOpt = granularityToLevel(gran);
  if (!levelOpt.has_value()) {
    return std::nullopt;
  }
  int level = *levelOpt;

  auto& frame = (readCgroupStat_ && dataSource == DataSource::CGROUP_STAT)
      ? cgroupUsageMetricFrames_[level]
      : procUsageMetricFrames_[level];
  auto slice = frame.slice(now - std::chrono::seconds(seconds_ago), now);
  if (slice == std::nullopt) {
    return std::nullopt;
  }
  std::string key = targetId.value_or("host");
  auto series = slice->series<double>(key);
  if (series == std::nullopt || series->size() == 0) {
    return std::nullopt;
  }
  auto data = series->raw();
  return *std::max_element(data.begin(), data.end());
}

void CPUTimeMonitor::tick(TMask mask) {
  TimePoint tickTime = std::chrono::steady_clock::now();
  bool readPerCore = false;
  {
    std::shared_lock lock(dataLock_);
    readPerCore = !targetsNeedPerCore_.empty();
  }
  std::vector<::dynolog::CpuTime> cpuTimeData = readProcStat(readPerCore);
  TimePoint measureTime = std::chrono::steady_clock::now();

  std::map<std::string, std::tuple<TimePoint, uint64_t>> cgroupCpuStats;
  if (readCgroupStat_) {
    std::shared_lock lock(dataLock_);
    for (const auto& [targetId, path] : targetCgroupPaths_) {
      auto usage = readCgroupCpuStat(path);
      if (usage.has_value()) {
        cgroupCpuStats.emplace(
            targetId,
            std::make_tuple(std::chrono::steady_clock::now(), usage.value()));
      }
    }
  }

  std::unique_lock lock(dataLock_);
  const bool hasPerCoreData = cpuTimeData.size() > coreCount_;
  const bool canProcessProcUsage =
      cpuTimeData.empty() || targetsNeedPerCore_.empty() || hasPerCoreData;

  if (TTicker::is_major_tick(mask)) {
    // every 60s
    if (canProcessProcUsage) {
      processProcUsage(IDX_MIN, cpuTimeData, tickTime, measureTime, mask);
    }
    processCgroupUsage(IDX_MIN, cgroupCpuStats, measureTime, mask);
  }
  // a tick can be both major and minor
  if (TTicker::is_minor_tick(mask)) {
    // every 1s
    if (canProcessProcUsage) {
      processProcUsage(IDX_SEC, cpuTimeData, tickTime, measureTime, mask);
    }
    processCgroupUsage(IDX_SEC, cgroupCpuStats, measureTime, mask);
  }
  if (TTicker::is_subminor_tick(mask, 0)) {
    // every 100ms
    if (canProcessProcUsage) {
      processProcUsage(
          IDX_HUNDRED_MS, cpuTimeData, tickTime, measureTime, mask);
    }
    processCgroupUsage(IDX_HUNDRED_MS, cgroupCpuStats, measureTime, mask);
  }
}

void CPUTimeMonitor::registerTarget(
    const std::string& targetId,
    const std::vector<int64_t>& cpuSet,
    const std::optional<std::string>& path) {
  if (targetId.empty() || targetId == "host") {
    LOG(INFO) << "Invalid targetId: " << targetId;
    return;
  }
  LOG(INFO) << "Register target, targetId: " << targetId << ", cpuSet: "
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
    if (targetToCpuSet_.find(targetId) != targetToCpuSet_.end()) {
      LOG(INFO) << "Target is already registered, targetId: " << targetId;
      return;
    }
  }
  std::unique_lock lock(dataLock_);
  targetToCpuSet_[targetId] = cpuSet;
  if (!cpuSet.empty()) {
    targetsNeedPerCore_.insert(targetId);
  }
  for (auto& frame : procUsageMetricFrames_) {
    frame.addSeries(
        targetId,
        std::make_shared<MetricSeries<double>>(
            frame.maxLength(), targetId, ""));
    addBreakdownSeries(frame, targetId);
  }
  for (auto& frame : cgroupUsageMetricFrames_) {
    frame.addSeries(
        targetId,
        std::make_shared<MetricSeries<double>>(
            frame.maxLength(), targetId, ""));
  }
  if (path.has_value()) {
    targetCgroupPaths_[targetId] = path.value();
  }
}

void CPUTimeMonitor::deRegisterTarget(const std::string& targetId) {
  LOG(INFO) << "Deregister target, targetId: " << targetId;
  std::unique_lock lock(dataLock_);
  targetToCpuSet_.erase(targetId);
  targetsNeedPerCore_.erase(targetId);
  for (auto& last : procCpuTimeLast_) {
    last.erase(targetId);
  }
  for (auto& last : cgroupUsageLast_) {
    last.erase(targetId);
  }
  for (auto& frame : procUsageMetricFrames_) {
    frame.eraseSeries(targetId);
    for (const auto& suffix : kBreakdownSuffixes) {
      frame.eraseSeries(targetId + suffix);
    }
  }
  for (auto& frame : cgroupUsageMetricFrames_) {
    frame.eraseSeries(targetId);
  }
  targetCgroupPaths_.erase(targetId);
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

  unsigned long long usage = 0;
  int num = sscanf(buf, "%*s %Lu", &usage);
  if (num != 1) {
    LOG(ERROR) << "Error parsing " << path;
    fclose(fp);
    return std::nullopt;
  }

  fclose(fp);
  return usage;
}

std::vector<::dynolog::CpuTime> CPUTimeMonitor::readProcStat(
    bool read_per_core) {
  // based on KernelMonitor.cpp
  // For unclear reasons, a C++ implementation is rather slower
  static FILE* fp = nullptr;
  char buf[320];

  std::vector<::dynolog::CpuTime> ret;
  ret.reserve(read_per_core ? 1 + coreCount_ : 1);

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

  errno = 0;
  rewind(fp);
  if (errno != 0) {
    LOG(ERROR) << "Error rewind /proc/stat";
    return {};
  }
  auto res = fflush(fp);
  if (res != 0) {
    LOG(ERROR) << "Error fflush /proc/stat";
    return {};
  }

  auto readCpuLine = [&]() -> std::optional<::dynolog::CpuTime> {
    if (!fgets(buf, sizeof(buf), fp)) {
      LOG(ERROR) << "Error reading /proc/stat";
      return std::nullopt;
    }
    ::dynolog::CpuTime ct{};
    // /proc/stat format: cpu[N] user nice system idle iowait irq softirq
    // [steal] [guest] [guest_nice]
    // We only parse through softirq (field 7) since we don't need
    // steal/guest/guest_nice.
    int num = sscanf(
        buf,
        "%*s %Lu %Lu %Lu %Lu %Lu %Lu %Lu",
        &ct.u,
        &ct.n,
        &ct.s,
        &ct.i,
        &ct.w,
        &ct.x,
        &ct.y);
    if (num < 4) {
      LOG(ERROR) << "Error parsing /proc/stat, got " << num << " fields";
      return std::nullopt;
    }
    return ct;
  };

  // First line is an aggregation over all CPUs
  auto systemCpuTime = readCpuLine();
  if (systemCpuTime != std::nullopt) {
    ret.push_back(*systemCpuTime);
  }
  if (!read_per_core) {
    return ret;
  }

  uint64_t lines = 0;
  while (lines < coreCount_) {
    auto perCoreCpuTime = readCpuLine();
    if (!perCoreCpuTime) {
      return {};
    }
    ret.push_back(*perCoreCpuTime);
    ++lines;
  }
  return ret;
}

void CPUTimeMonitor::processProcUsage(
    int level,
    const std::vector<::dynolog::CpuTime>& cpuTimeData,
    TimePoint tickTime,
    TimePoint measureTime,
    TMask mask) {
  if (cpuTimeData.empty()) {
    return;
  }
  auto& frame = procUsageMetricFrames_[level];
  auto& lastCpuTime = procCpuTimeLast_[level];
  auto& lastTickTime = procTimeLast_[level];
  MapSamplesT line;

  for (const auto& [targetId, cpuSet] : targetToCpuSet_) {
    // Aggregate CpuTime over the target's assigned cores
    ::dynolog::CpuTime newCt;
    uint64_t coreCount = coreCount_;
    if (cpuSet.empty()) {
      newCt = cpuTimeData[0];
    } else {
      bool missingCpuData = false;
      for (const auto& cpu : cpuSet) {
        if (cpu < 0 || static_cast<size_t>(cpu) + 1 >= cpuTimeData.size()) {
          if (TTicker::is_major_tick(mask)) {
            LOG(WARNING) << "Skipping CPU time sample for targetId: "
                         << targetId << " because CPU " << cpu
                         << " is missing from /proc/stat data with "
                         << cpuTimeData.size() << " entries";
          }
          missingCpuData = true;
          break;
        }
        newCt += cpuTimeData[cpu + 1]; // zeroth entry is system-wide
      }
      if (missingCpuData) {
        continue;
      }
      coreCount = cpuSet.size();
    }

    if (lastCpuTime.find(targetId) == lastCpuTime.end()) {
      lastCpuTime[targetId] = newCt;
      continue;
    }
    ::dynolog::CpuTime lastCt = lastCpuTime[targetId];
    uint64_t idleDelta =
        (newCt.i - lastCt.i) * 10; // /proc/stat reports in 10ms, convert to ms
    lastCpuTime[targetId] = newCt;

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
                   << " targetId: " << targetId << " wallDelta: " << wallDelta
                   << " CPUCoresUsage: " << CPUCoresUsage
                   << " idleDelta: " << idleDelta << " newVal: " << newCt.i
                   << " lastVal: " << lastCt.i << " coreCount: " << coreCount
                   << " data: "
                   << std::accumulate(
                          cpuTimeData.begin(),
                          cpuTimeData.end(),
                          std::string(),
                          [](const std::string& a,
                             const ::dynolog::CpuTime& b) {
                            return a + " " + std::to_string(b.i);
                          });
      }
      continue;
    }

    line.emplace_back(targetId, CPUCoresUsage);

    // Compute raw CPU breakdown values (in cores) for idle, softirq, iowait,
    // hardirq. Each is: field_delta_jiffies * 10ms / wallDelta_ms = cores.
    // Counter wrap is extremely unlikely for /proc/stat jiffies counters but
    // skip if detected to avoid producing incorrect values.
    double msPerJiffy = 10.0;
    auto safeDelta = [](uint64_t newVal,
                        uint64_t oldVal) -> std::optional<uint64_t> {
      if (newVal < oldVal) {
        return std::nullopt;
      }
      return newVal - oldVal;
    };

    auto idleDeltaOpt = safeDelta(newCt.i, lastCt.i);
    auto softirqDeltaOpt = safeDelta(newCt.y, lastCt.y);
    auto iowaitDeltaOpt = safeDelta(newCt.w, lastCt.w);
    auto hardirqDeltaOpt = safeDelta(newCt.x, lastCt.x);
    auto niceDeltaOpt = safeDelta(newCt.n, lastCt.n);

    if (idleDeltaOpt && softirqDeltaOpt && iowaitDeltaOpt && hardirqDeltaOpt &&
        niceDeltaOpt) {
      double idleCores =
          static_cast<double>(*idleDeltaOpt) * msPerJiffy / wallDelta;
      double softirqCores =
          static_cast<double>(*softirqDeltaOpt) * msPerJiffy / wallDelta;
      double iowaitCores =
          static_cast<double>(*iowaitDeltaOpt) * msPerJiffy / wallDelta;
      double hardirqCores =
          static_cast<double>(*hardirqDeltaOpt) * msPerJiffy / wallDelta;
      double niceCores =
          static_cast<double>(*niceDeltaOpt) * msPerJiffy / wallDelta;

      line.emplace_back(targetId + kBreakdownIdle, idleCores);
      line.emplace_back(targetId + kBreakdownSoftirq, softirqCores);
      line.emplace_back(targetId + kBreakdownIowait, iowaitCores);
      line.emplace_back(targetId + kBreakdownHardirq, hardirqCores);
      line.emplace_back(targetId + kBreakdownNice, niceCores);
    }
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

  for (const auto& [targetId, cpuStat] : cgroupCpuStats) {
    auto [readTime, newUsage] = cpuStat;
    if (lastUsage.find(targetId) == lastUsage.end() ||
        lastTime.find(targetId) == lastTime.end()) {
      lastUsage[targetId] = newUsage;
      lastTime[targetId] = readTime;
      continue;
    }

    uint64_t oldUsage = lastUsage[targetId];
    TimePoint oldTime = lastTime[targetId];
    lastUsage[targetId] = newUsage;
    lastTime[targetId] = readTime;

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
                   << " targetId: " << targetId << " wallDelta: " << wallDelta
                   << " cgroupUsage: " << cgroupUsage
                   << " newUsage: " << newUsage << " oldUsage: " << oldUsage
                   << " coreCount: " << coreCount_;
      }
      continue;
    }

    line.emplace_back(targetId, cgroupUsage);
  }
  if (!line.empty()) {
    frame.addSamples(line, tickTime);
  }
}

} // namespace facebook::dynolog
