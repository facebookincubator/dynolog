// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/CPUTimeMonitor.h"
#include <dynolog/src/metric_frame/MetricFrameTsUnit.h>

#define IDX_MIN 0
#define IDX_SEC 1
#define IDX_HUNDRED_MS 2

namespace facebook {
namespace dynolog {

constexpr int kRingbufferSizeMinutes = 6;

CPUTimeMonitor::CPUTimeMonitor(
    std::shared_ptr<TTicker> ticker,
    const std::string& rootDir,
    uint64_t coreCount,
    bool isUnitTest)
    : MonitorBase<TTicker>(std::move(ticker), "CPUTimeMonitor", {1.0}),
      rootDir_(rootDir),
      coreCount_(coreCount),
      isUnitTest_(isUnitTest),
      CPUTimeMetricFrames_(
          {MetricFrameMap(
               kRingbufferSizeMinutes,
               "cputime_60s",
               "",
               std::make_shared<MetricFrameTsUnitFixInterval>(
                   std::chrono::seconds(60),
                   kRingbufferSizeMinutes)),
           MetricFrameMap(
               kRingbufferSizeMinutes * 60,
               "cputime_1s",
               "",
               std::make_shared<MetricFrameTsUnitFixInterval>(
                   std::chrono::seconds(1),
                   kRingbufferSizeMinutes * 60)),
           MetricFrameMap(
               kRingbufferSizeMinutes * 60 * 10,
               "cputime_100ms",
               "",
               std::make_shared<MetricFrameTsUnitFixInterval>(
                   std::chrono::milliseconds(100),
                   kRingbufferSizeMinutes * 60 * 10))})

{
  std::unique_lock lock(dataLock_);
  allotmentToCpuSet_["host"] = {};
  for (auto& frame : CPUTimeMetricFrames_) {
    frame.addSeries(
        "host",
        std::make_shared<MetricSeries<double>>(frame.maxLength(), "host", ""));
  }
}

std::optional<double> CPUTimeMonitor::getStat(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& allotmentId,
    Statistic stat,
    double quant) {
  TimePoint now = std::chrono::steady_clock::now();
  int level;
  if (gran == Granularity::MINUTE) {
    level = IDX_MIN;
  } else if (gran == Granularity::SECOND) {
    level = IDX_SEC;
  } else if (gran == Granularity::HUNDRED_MS) {
    level = IDX_HUNDRED_MS;
  } else {
    return std::nullopt;
  }
  std::shared_lock lock(dataLock_);
  auto frame = CPUTimeMetricFrames_[level];
  auto slice = frame.slice(now - std::chrono::seconds(seconds_ago), now);
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
    const std::optional<std::string>& allotmentId) {
  return getStat(gran, seconds_ago, allotmentId, Statistic::AVG, 0.0);
}

std::optional<double> CPUTimeMonitor::getQuantileCPUCoresUsage(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    double quantile,
    const std::optional<std::string>& allotmentId) {
  return getStat(gran, seconds_ago, allotmentId, Statistic::QUANTILE, quantile);
}

std::vector<double> CPUTimeMonitor::getRawCPUCoresUsage(
    CPUTimeMonitor::Granularity gran,
    uint64_t seconds_ago,
    const std::optional<std::string>& allotmentId) {
  TimePoint now = std::chrono::steady_clock::now();
  int level;
  if (gran == Granularity::MINUTE) {
    level = IDX_MIN;
  } else if (gran == Granularity::SECOND) {
    level = IDX_SEC;
  } else if (gran == Granularity::HUNDRED_MS) {
    level = IDX_HUNDRED_MS;
  } else {
    return {};
  }
  std::shared_lock lock(dataLock_);
  auto frame = CPUTimeMetricFrames_[level];
  auto slice = frame.slice(now - std::chrono::seconds(seconds_ago), now);
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

void CPUTimeMonitor::tick(TMask mask) {
  TimePoint measure_time_lo = std::chrono::steady_clock::now();
  std::vector<uint64_t> idleTime =
      readProcStat(!allotmentsNeedPerCore_.empty());
  TimePoint measure_time_hi = std::chrono::steady_clock::now();

  if (idleTime.empty()) {
    return;
  }

  std::unique_lock lock(dataLock_);

  auto make_cores_usage = [&](int level) {
    auto frame = CPUTimeMetricFrames_[level];
    auto& last = CPUTimeLast_[level];
    auto& last_time = TimeLast_[level];
    MapSamplesT line;

    for (const auto& [allotmentId, cpuSet] : allotmentToCpuSet_) {
      uint64_t newVal = idleTime[0];
      uint64_t coreCount = coreCount_;
      if (!cpuSet.empty()) {
        newVal = 0;
        for (auto cpu : cpuSet) {
          newVal += idleTime[cpu + 1]; // zeroth line is system-wide
        }
        coreCount = cpuSet.size();
      }
      if (last.find(allotmentId) == last.end()) {
        last[allotmentId] = newVal;
        continue;
      }
      uint64_t lastVal = last[allotmentId];
      uint64_t idleDelta =
          (newVal - lastVal) * 10; // /proc/stat reports in 10ms, convert to ms
      last[allotmentId] = newVal;

      uint64_t wallDelta =
          std::chrono::duration_cast<std::chrono::milliseconds>(
              measure_time_hi - last_time)
              .count();
      if (isUnitTest_) {
        wallDelta = 100;
      }
      if (wallDelta == 0) {
        // log on major tick only to avoid spam
        if (TTicker::is_major_tick(mask)) {
          LOG(INFO) << "Wall delta is 0, cannot compute CPU cores usage";
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
      frame.addSamples(line, measure_time_lo);
    }
    TimeLast_[level] = measure_time_lo;
  };

  if (TTicker::is_major_tick(mask)) {
    // every 60s
    make_cores_usage(IDX_MIN);
  }
  // a tick can be both major and minor
  if (TTicker::is_minor_tick(mask)) {
    // every 1s
    make_cores_usage(IDX_SEC);
  }
  if (TTicker::is_subminor_tick(mask, 0)) {
    // every 100ms
    make_cores_usage(IDX_HUNDRED_MS);
  }
}

void CPUTimeMonitor::registerAllotment(
    const std::string& allotmentId,
    const std::vector<int64_t>& cpuSet) {
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
                   });
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
  for (auto& frame : CPUTimeMetricFrames_) {
    frame.addSeries(
        allotmentId,
        std::make_shared<MetricSeries<double>>(
            frame.maxLength(), allotmentId, ""));
  }
}

void CPUTimeMonitor::deRegisterAllotment(const std::string& allotmentId) {
  LOG(INFO) << "Deregister allotment, allotmentId: " << allotmentId;
  std::unique_lock lock(dataLock_);
  allotmentToCpuSet_.erase(allotmentId);
  allotmentsNeedPerCore_.erase(allotmentId);
  for (auto& last : CPUTimeLast_) {
    last.erase(allotmentId);
  }
  for (auto& frame : CPUTimeMetricFrames_) {
    frame.eraseSeries(allotmentId);
  }
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

  int lines = 0;
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
} // namespace dynolog
} // namespace facebook
