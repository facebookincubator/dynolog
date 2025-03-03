// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <dynolog/src/metric_frame/MetricFrame.h>
#include <memory>
#include <set>
#include <shared_mutex>
#include <thread>
#include "dynolog/src/MonitorBase.h"
#include "dynolog/src/Ticker.h"

namespace facebook {
namespace dynolog {

/*
A monitor class for measuring /proc/stat CPU Time according to periodic ticker
schedules 100ms, 1s and 60s. Only idle time is measured, from which CPU Cores
Usage is determined and stored in a MetricFrame (ringbuffer). By default only
whole-host idle time is sampled, this is significantly less overhead because the
Kernel appears to not evaluate the per-core lines of /proc/stat unless they are
read.

Allotments are akin to named CPU sets. They can be registered along with an
optional CPU set. A registered allotment will have its own MetricSeries for each
granularity 100ms, 1s and 60s. If the CPU set is empty the allotment is assumed
to be whole-host and will have the same CPU data as host level (albeit with a
different start time). If the CPU set is non-empty then the entire per-core
/proc/stat file is parsed and the CPU Cores Usage of the allotment cores is
determined by aggregation over its CPU set. */

class CPUTimeMonitor : MonitorBase<Ticker<60000, 1000, 10, 3>> {
 public:
  using TTicker = Ticker<60000, 1000, 10, 3>;
  using typename MonitorBase<TTicker>::TMask;

  enum class Granularity { MINUTE, SECOND, HUNDRED_MS };

  explicit CPUTimeMonitor(
      std::shared_ptr<TTicker> ticker,
      const std::string& rootDir = "",
      uint64_t coreCount = std::thread::hardware_concurrency(),
      bool isUnitTest = false);

  void tick(TMask mask) override;

  void registerAllotment(
      const std::string& allotmentId,
      const std::vector<int64_t>& cpuSet);

  void deRegisterAllotment(const std::string& allotmentId);

  std::optional<double> getAvgCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& allotmentId = std::nullopt);

  std::optional<double> getQuantileCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      double quantile,
      const std::optional<std::string>& allotmentId = std::nullopt);

  std::vector<double> getRawCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& allotmentId = std::nullopt);

 private:
  // Reads Idle time from /proc/stat
  // If read_per_core is true, reads per-core data in addition to the
  // all-core data (first element)
  enum class Statistic { AVG, QUANTILE };

  std::vector<uint64_t> readProcStat(bool read_per_core = false);
  std::optional<double> getStat(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& allotmentId,
      Statistic stat,
      double quant);
  std::string const rootDir_;
  uint64_t const coreCount_;
  bool const isUnitTest_;
  std::map<std::string, std::vector<int64_t>> allotmentToCpuSet_;
  std::set<std::string> allotmentsNeedPerCore_;

  // Index 0 is minute, 1 is second, 2 is 100ms
  std::array<MetricFrameMap, 3> CPUTimeMetricFrames_;
  std::array<std::map<std::string, uint64_t>, 3> CPUTimeLast_;
  std::array<TimePoint, 3> TimeLast_;

  std::shared_mutex dataLock_;

  friend class CPUTimeMonitorTest;
};
} // namespace dynolog

} // namespace facebook
// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.
