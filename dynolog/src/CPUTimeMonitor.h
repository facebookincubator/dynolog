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
determined by aggregation over its CPU set.

As of July 2025, we began testing a new cgroup-based CPU time monitoringfor more
accurate measurements of cgroup CPU time usage.
*/

class CPUTimeMonitor : MonitorBase<Ticker<60000, 1000, 10, 3>> {
 public:
  using TTicker = Ticker<60000, 1000, 10, 3>;
  using typename MonitorBase<TTicker>::TMask;

  enum class Granularity { MINUTE, SECOND, HUNDRED_MS };
  enum class DataSource { PROC_STAT, CGROUP_STAT };

  explicit CPUTimeMonitor(
      std::shared_ptr<TTicker> ticker,
      bool readCgroupStat,
      std::string rootDir = "",
      uint64_t coreCount = std::thread::hardware_concurrency(),
      bool isUnitTest = false);

  void tick(TMask mask) override;

  void registerAllotment(
      const std::string& allotmentId,
      const std::vector<int64_t>& cpuSet,
      const std::optional<std::string>& path = std::nullopt);

  void deRegisterAllotment(const std::string& allotmentId);

  std::optional<double> getAvgCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& allotmentId = std::nullopt,
      DataSource dataSource = DataSource::PROC_STAT);

  std::optional<double> getQuantileCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      double quantile,
      const std::optional<std::string>& allotmentId = std::nullopt,
      DataSource dataSource = DataSource::PROC_STAT);

  std::vector<double> getRawCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& allotmentId = std::nullopt,
      DataSource dataSource = DataSource::PROC_STAT);

 private:
  // Reads Idle time from /proc/stat
  // If read_per_core is true, reads per-core data in addition to the
  // all-core data (first element)
  enum class Statistic { AVG, QUANTILE };

  std::vector<uint64_t> readProcStat(bool read_per_core = false);
  std::optional<uint64_t> readCgroupCpuStat(const std::string& cgroupPath);
  std::optional<double> getStat(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& allotmentId,
      Statistic stat,
      double quant,
      DataSource dataSource = DataSource::PROC_STAT);

  void processProcUsage(
      int level,
      const std::vector<uint64_t>& idleTime,
      TimePoint measure_time_lo,
      TimePoint measure_time_hi,
      TMask mask);

  void processCgroupUsage(
      int level,
      const std::map<std::string, std::tuple<TimePoint, uint64_t>>&
          cgroupCpuStats,
      TimePoint measure_time_lo,
      TMask mask);

  static std::array<MetricFrameMap, 3> createMetricFrameArray();
  std::optional<MetricFrameMap> getMetricFrame(
      Granularity gran,
      DataSource dataSource);

  std::string const rootDir_;
  uint64_t const coreCount_;
  bool const isUnitTest_;
  std::map<std::string, std::vector<int64_t>> allotmentToCpuSet_;
  std::set<std::string> allotmentsNeedPerCore_;
  std::map<std::string, std::string> allotmentCgroupPaths_;

  // Proc stat tracking. Index 0 is minute, 1 is second, 2 is 100ms
  std::array<MetricFrameMap, 3> procUsageMetricFrames_;
  std::array<std::map<std::string, uint64_t>, 3> procCpuTimeLast_;
  std::array<TimePoint, 3> procTimeLast_;

  // Cgroup stat tracking. Index 0 is minute, 1 is second, 2 is 100ms
  bool readCgroupStat_;
  std::array<MetricFrameMap, 3> cgroupUsageMetricFrames_;
  std::array<std::map<std::string, uint64_t>, 3> cgroupUsageLast_;
  std::array<std::map<std::string, TimePoint>, 3> cgroupTimeLast_;

  std::shared_mutex dataLock_;

  friend class CPUTimeMonitorTest;
};
} // namespace dynolog

} // namespace facebook
// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.
