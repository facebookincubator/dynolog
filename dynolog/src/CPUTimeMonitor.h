/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <dynolog/src/metric_frame/MetricFrame.h>
#include <memory>
#include <set>
#include <shared_mutex>
#include <thread>
#include "dynolog/src/MonitorBase.h"
#include "dynolog/src/Ticker.h"

namespace facebook::dynolog {

/*
A monitor class for measuring CPU time from multiple data sources according to
periodic ticker schedules (100ms, 1s, and 60s). CPU usage data is stored in
MetricFrame ringbuffers for historical analysis.

SUPPORTED DATA SOURCES:
1. /proc/stat CPU Time: Measures system-wide and per-core idle time from which
   CPU Cores Usage is determined. By default, only whole-host idle time is
   sampled for lower overhead, as the kernel evaluates per-core lines only
   when read.

2. Cgroup CPU Time: Directly measures CPU usage from cgroup cpu.stat files,
   providing more accurate measurements for containerized workloads and
   resource-constrained environments.

MONITORING TARGETS:
The monitor supports tracking various targets, each identified by a unique name:

- Host-level monitoring: Tracks whole-system CPU usage
- CPU set-based monitoring: Tracks usage of specific CPU cores by parsing
  per-core /proc/stat data and aggregating over the specified CPU set
- Cgroup monitoring: Tracks CPU usage of any cgroup by reading its cpu.stat
  file directly, enabling monitoring of containers, systemd services, or any
  cgroup hierarchy

Each registered target maintains its own MetricSeries for each granularity
(100ms, 1s, 60s). Targets can be registered with:
- A CPU set for /proc/stat-based core-specific monitoring
- A cgroup path for direct cgroup cpu.stat monitoring
- Both data sources for comprehensive coverage

The dual data source approach enables accurate monitoring across diverse
deployment scenarios, from bare-metal systems to containerized environments.
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
      uint64_t coreCount,
      std::string rootDir = "",
      bool isUnitTest = false);

  void tick(TMask mask) override;

  void registerTarget(
      const std::string& targetId,
      const std::vector<int64_t>& cpuSet,
      const std::optional<std::string>& path = std::nullopt);

  void deRegisterTarget(const std::string& targetId);

  std::optional<double> getAvgCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& targetId = std::nullopt,
      DataSource dataSource = DataSource::PROC_STAT);

  virtual std::optional<double> getQuantileCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      double quantile,
      const std::optional<std::string>& targetId = std::nullopt,
      DataSource dataSource = DataSource::PROC_STAT);

  std::vector<double> getRawCPUCoresUsage(
      Granularity gran,
      uint64_t seconds_ago,
      const std::optional<std::string>& targetId = std::nullopt,
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
      const std::optional<std::string>& targetId,
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
  std::map<std::string, std::vector<int64_t>> targetToCpuSet_;
  std::set<std::string> targetsNeedPerCore_;
  std::map<std::string, std::string> targetCgroupPaths_;

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
} // namespace facebook::dynolog
