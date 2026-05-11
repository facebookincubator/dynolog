/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/CPUTimeMonitor.h"

#include <folly/system/HardwareConcurrency.h>
#include <gtest/gtest.h>
#include <atomic>
#include <thread>

using namespace ::testing;
using namespace std::literals::chrono_literals;

namespace facebook {
namespace dynolog {

const unsigned coreCount = 32;

std::shared_ptr<CPUTimeMonitor> createTestMonitor() {
  std::shared_ptr<CPUTimeMonitor::TTicker> ticker =
      std::make_shared<CPUTimeMonitor::TTicker>();
  // hard code the core count to match the testroot file
  return std::make_shared<CPUTimeMonitor>(
      ticker, true, coreCount, getenv("TESTROOT"), true);
}

// idle data from test /proc/stat
std::vector<uint64_t> allCoresReference = std::vector<uint64_t>(
    {41381479016, 1175164067, 1237053439, 1254118253, 1250395923, 1266155504,
     1271383171,  1273541699, 1274886641, 1225418525, 1247327059, 1259202609,
     1261516137,  1268497461, 1272576261, 1274315059, 1275526838, 1327321224,
     1329967352,  1330385515, 1329564997, 1331216843, 1331884010, 1332305479,
     1332387019,  1329147962, 1330415507, 1330895023, 1331026068, 1331391875,
     1332258168,  1332020686, 1332212631});

unsigned short major_tick_60s = 7; // 111
unsigned short minor_tick_1s = 6; // 110
unsigned short subminor_tick_100ms = 4; // 100

class CPUTimeMonitorTest : public ::testing::Test {
 protected:
  auto readProcStat(bool read_per_core = false) {
    return monitor->readProcStat(read_per_core);
  }
  auto readCgroupCpuStat(const std::string& cgroupPath) {
    return monitor->readCgroupCpuStat(cgroupPath);
  }
  auto& procCPUTimeLast_() const {
    return monitor->procCpuTimeLast_;
  }
  auto& procCPUTimeMetricFrames_() const {
    return monitor->procUsageMetricFrames_;
  }
  auto& cgroupUsageLast_() const {
    return monitor->cgroupUsageLast_;
  }
  auto& cgroupUsageMetricFrames_() const {
    return monitor->cgroupUsageMetricFrames_;
  }
  auto& cgroupTimeLast_() const {
    return monitor->cgroupTimeLast_;
  }
  std::shared_ptr<CPUTimeMonitor> monitor = createTestMonitor();
};

// Just check that the monitor can be created and read the data from /proc/stat
TEST_F(CPUTimeMonitorTest, testProcStat) {
  auto cpuTime = readProcStat(false);
  ASSERT_EQ(cpuTime.size(), 1);
  EXPECT_EQ(cpuTime[0].i, allCoresReference[0]);

  // Verify all fields are parsed for the aggregate line (up to softirq)
  EXPECT_EQ(cpuTime[0].u, 938170131);
  EXPECT_EQ(cpuTime[0].n, 135328904);
  EXPECT_EQ(cpuTime[0].s, 418278208);
  EXPECT_EQ(cpuTime[0].w, 109011110);
  EXPECT_EQ(cpuTime[0].x, 18158);
  EXPECT_EQ(cpuTime[0].y, 16782689);

  auto cpuTimePerCore = readProcStat(true);
  ASSERT_EQ(cpuTimePerCore.size(), allCoresReference.size());
  for (size_t j = 0; j < allCoresReference.size(); ++j) {
    EXPECT_EQ(cpuTimePerCore[j].i, allCoresReference[j]);
  }
}

TEST_F(CPUTimeMonitorTest, testCgroupCpuStat) {
  std::string targetPath("/sys/fs/cgroup");
  auto cpuUsage = readCgroupCpuStat(targetPath);
  EXPECT_NE(cpuUsage, std::nullopt);
}
// Test the tick function
TEST_F(CPUTimeMonitorTest, testTarget) {
  auto now = std::chrono::steady_clock::now();
  monitor->tick(major_tick_60s);
  EXPECT_EQ(procCPUTimeLast_()[0]["host"].i, allCoresReference[0]);
  EXPECT_EQ(procCPUTimeLast_()[1]["host"].i, allCoresReference[0]);
  EXPECT_EQ(procCPUTimeLast_()[2]["host"].i, allCoresReference[0]);

  // need at least 2 ticks to get the delta
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 0);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 0);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 0);

  for (int i = 0; i < 2; i++) {
    ASSERT_EQ(
        procCPUTimeMetricFrames_()[i].slice(now, now + 60s), std::nullopt);
  }
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(CPUTimeMonitor::Granularity::MINUTE, 60),
      std::nullopt);

  monitor->tick(major_tick_60s);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 1);

  auto checkStats = [&](const std::optional<std::string>& targetId =
                            std::nullopt,
                        double expected = coreCount) {
    for (int i = 0; i < 2; i++) {
      // Zero idle delta means maximum CPU usage
      EXPECT_NEAR(
          procCPUTimeMetricFrames_()[i]
              .slice(now, now + 60s)
              ->series<double>(targetId.value_or("host"))
              ->avg<double>(),
          expected,
          0.1);
    }

    EXPECT_NEAR(
        *monitor->getAvgCPUCoresUsage(
            CPUTimeMonitor::Granularity::MINUTE, 60, targetId),
        expected,
        0.1);
    EXPECT_NEAR(
        *monitor->getAvgCPUCoresUsage(
            CPUTimeMonitor::Granularity::SECOND, 60, targetId),
        expected,
        0.1);
    EXPECT_NEAR(
        *monitor->getAvgCPUCoresUsage(
            CPUTimeMonitor::Granularity::HUNDRED_MS, 60, targetId),
        expected,
        0.1);

    for (const auto& quant : {0.0, 0.1, 0.5, 0.9, 1.0}) {
      EXPECT_NEAR(
          *monitor->getQuantileCPUCoresUsage(
              CPUTimeMonitor::Granularity::MINUTE, 60, quant, targetId),
          expected,
          0.1);
      EXPECT_NEAR(
          *monitor->getQuantileCPUCoresUsage(
              CPUTimeMonitor::Granularity::SECOND, 60, quant, targetId),
          expected,
          0.1);
      EXPECT_NEAR(
          *monitor->getQuantileCPUCoresUsage(
              CPUTimeMonitor::Granularity::HUNDRED_MS, 60, quant, targetId),
          expected,
          0.1);
    }
  };

  checkStats();

  monitor->tick(minor_tick_1s);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 2);

  checkStats();

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 3);

  checkStats();

  monitor->registerTarget("target1", {});
  monitor->registerTarget("target2", {0, 1, 2, 3, 4, 5, 6, 7});

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 4);
  checkStats();

  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target2"),
      std::nullopt);

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 5);
  checkStats();

  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target2"),
      std::nullopt);

  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target1"),
      coreCount,
      0.1);
  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target2"),
      8.0,
      0.1);

  monitor->tick(major_tick_60s);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 3);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 6);
  checkStats();

  // still don't expect targets to have minutely data becase we only have 1
  // sample
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target2"),
      std::nullopt);
  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target1"),
      coreCount,
      0.1);
  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target2"),
      8.0,
      0.1);

  monitor->tick(major_tick_60s);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 3);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 4);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 7);

  // Now all targets have data for all granularities
  checkStats();
  checkStats("target1");
  checkStats("target2", 8.0);

  monitor->deRegisterTarget("target1");
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target1"),
      std::nullopt);

  monitor->tick(major_tick_60s);
  checkStats();
  checkStats("target2", 8.0);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target1"),
      std::nullopt);

  monitor->deRegisterTarget("target2");

  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "target2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target2"),
      std::nullopt);

  monitor->tick(major_tick_60s);
  checkStats();
  monitor->tick(minor_tick_1s);
  checkStats();
  monitor->tick(subminor_tick_100ms);
  checkStats();
}

// Test CPU breakdown API. Since the test fixture is static (same data each
// tick), all deltas are 0 so breakdown values should be 0.
TEST_F(CPUTimeMonitorTest, testCpuBreakdown) {
  // No breakdown data before any ticks
  EXPECT_EQ(
      monitor->getCpuBreakdownAvg(
          CPUTimeMonitor::Granularity::MINUTE,
          60,
          CPUTimeMonitor::CpuBreakdown::IDLE),
      std::nullopt);

  // First tick initializes, second tick produces samples (with 0 deltas)
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);

  // Breakdown values are 0 because static fixture has 0 deltas
  auto idleAvg = monitor->getCpuBreakdownAvg(
      CPUTimeMonitor::Granularity::MINUTE,
      60,
      CPUTimeMonitor::CpuBreakdown::IDLE);
  ASSERT_TRUE(idleAvg.has_value());
  EXPECT_DOUBLE_EQ(idleAvg.value(), 0.0);

  // Register a target and verify breakdown API works
  monitor->registerTarget("breakdown_test", {0, 1, 2, 3});
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);

  for (const auto& bd :
       {CPUTimeMonitor::CpuBreakdown::IDLE,
        CPUTimeMonitor::CpuBreakdown::SOFTIRQ,
        CPUTimeMonitor::CpuBreakdown::IOWAIT,
        CPUTimeMonitor::CpuBreakdown::HARDIRQ}) {
    auto avg = monitor->getCpuBreakdownAvg(
        CPUTimeMonitor::Granularity::MINUTE, 60, bd, "breakdown_test");
    ASSERT_TRUE(avg.has_value());
    EXPECT_DOUBLE_EQ(avg.value(), 0.0);
  }

  monitor->deRegisterTarget("breakdown_test");

  // After deregistration, should return nullopt
  EXPECT_EQ(
      monitor->getCpuBreakdownAvg(
          CPUTimeMonitor::Granularity::MINUTE,
          60,
          CPUTimeMonitor::CpuBreakdown::IDLE,
          "breakdown_test"),
      std::nullopt);
}

// Verify that CPU saturation (usage) values are unchanged after adding
// breakdown series to the same MetricFrameMap. The static fixture produces 0
// idle delta, so CPU usage = coreCount for host and cpuSet.size() for targets.
TEST_F(CPUTimeMonitorTest, testSaturationUnchangedWithBreakdown) {
  // Register targets with different cpuSets
  monitor->registerTarget("target_4cores", {0, 1, 2, 3});
  monitor->registerTarget("target_8cores", {0, 1, 2, 3, 4, 5, 6, 7});
  monitor->registerTarget("target_no_cpuset", {});

  // Need 2 ticks at each granularity to produce data
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);
  monitor->tick(minor_tick_1s);
  monitor->tick(subminor_tick_100ms);

  // Host should report coreCount (32) cores usage at all granularities
  for (const auto& gran :
       {CPUTimeMonitor::Granularity::MINUTE,
        CPUTimeMonitor::Granularity::SECOND,
        CPUTimeMonitor::Granularity::HUNDRED_MS}) {
    auto hostAvg = monitor->getAvgCPUCoresUsage(gran, 60);
    ASSERT_TRUE(hostAvg.has_value());
    EXPECT_NEAR(hostAvg.value(), coreCount, 0.1);
  }

  // target_4cores should report 4.0 cores usage
  auto avg4 = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target_4cores");
  ASSERT_TRUE(avg4.has_value());
  EXPECT_NEAR(avg4.value(), 4.0, 0.1);

  // target_8cores should report 8.0 cores usage
  auto avg8 = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target_8cores");
  ASSERT_TRUE(avg8.has_value());
  EXPECT_NEAR(avg8.value(), 8.0, 0.1);

  // target_no_cpuset (empty cpuSet) should report coreCount
  auto avgNoCpuSet = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target_no_cpuset");
  ASSERT_TRUE(avgNoCpuSet.has_value());
  EXPECT_NEAR(avgNoCpuSet.value(), coreCount, 0.1);

  // Quantile queries should also still work
  auto p50 = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::SECOND, 60, 0.5, "target_8cores");
  ASSERT_TRUE(p50.has_value());
  EXPECT_NEAR(p50.value(), 8.0, 0.1);

  auto p99 = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::SECOND, 60, 0.99, "target_4cores");
  ASSERT_TRUE(p99.has_value());
  EXPECT_NEAR(p99.value(), 4.0, 0.1);

  // Raw data should also work
  auto raw = monitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "target_8cores");
  EXPECT_FALSE(raw.empty());
  for (double val : raw) {
    EXPECT_NEAR(val, 8.0, 0.1);
  }

  // Verify breakdown values exist alongside usage values (both should be 0
  // since fixture is static)
  for (const auto& bd :
       {CPUTimeMonitor::CpuBreakdown::IDLE,
        CPUTimeMonitor::CpuBreakdown::SOFTIRQ,
        CPUTimeMonitor::CpuBreakdown::IOWAIT,
        CPUTimeMonitor::CpuBreakdown::HARDIRQ}) {
    auto hostBd = monitor->getCpuBreakdownAvg(
        CPUTimeMonitor::Granularity::SECOND, 60, bd);
    ASSERT_TRUE(hostBd.has_value());
    EXPECT_DOUBLE_EQ(hostBd.value(), 0.0);

    auto target4Bd = monitor->getCpuBreakdownAvg(
        CPUTimeMonitor::Granularity::SECOND, 60, bd, "target_4cores");
    ASSERT_TRUE(target4Bd.has_value());
    EXPECT_DOUBLE_EQ(target4Bd.value(), 0.0);
  }

  // Deregister targets and verify cleanup
  monitor->deRegisterTarget("target_4cores");
  monitor->deRegisterTarget("target_8cores");
  monitor->deRegisterTarget("target_no_cpuset");

  // Usage and breakdown should return nullopt after deregistration
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "target_4cores"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getCpuBreakdownAvg(
          CPUTimeMonitor::Granularity::MINUTE,
          60,
          CPUTimeMonitor::CpuBreakdown::IDLE,
          "target_4cores"),
      std::nullopt);

  // Host should still work after target cleanup
  auto hostAfter =
      monitor->getAvgCPUCoresUsage(CPUTimeMonitor::Granularity::MINUTE, 60);
  ASSERT_TRUE(hostAfter.has_value());
  EXPECT_NEAR(hostAfter.value(), coreCount, 0.1);
}

// Verify that procCpuTimeLast_ stores full CpuTime and all fields are
// correctly aggregated over cpuSet for per-allotment targets.
TEST_F(CPUTimeMonitorTest, testCpuTimeLastStoresFullCpuTime) {
  monitor->registerTarget("target_2cores", {0, 1});

  monitor->tick(major_tick_60s);

  // Host should have system-wide aggregate CpuTime
  auto& hostCt = procCPUTimeLast_()[0]["host"];
  EXPECT_EQ(hostCt.i, allCoresReference[0]); // idle
  EXPECT_EQ(hostCt.u, 938170131); // user
  EXPECT_EQ(hostCt.s, 418278208); // system
  EXPECT_EQ(hostCt.y, 16782689); // softirq

  // Target should have aggregated CpuTime over cores 0+1
  auto& targetCt = procCPUTimeLast_()[0]["target_2cores"];
  // idle for core0 + core1
  EXPECT_EQ(targetCt.i, allCoresReference[1] + allCoresReference[2]);
  // user for core0 + core1 (from fixture: 85923288 + 62851079)
  EXPECT_EQ(targetCt.u, 85923288 + 62851079);
  // softirq for core0 + core1 (from fixture: 4746442 + 2381064)
  EXPECT_EQ(targetCt.y, 4746442 + 2381064);

  monitor->deRegisterTarget("target_2cores");
}

// Verify that breakdown data is populated independently at each granularity
// (60s, 1s, 100ms) based on which tick type fires.
TEST_F(CPUTimeMonitorTest, testBreakdownAtAllGranularities) {
  monitor->registerTarget("gran_test", {0, 1, 2, 3});

  // First tick at all granularities to initialize
  monitor->tick(major_tick_60s);

  // Second major tick — populates MINUTE, SECOND, and HUNDRED_MS
  monitor->tick(major_tick_60s);

  // All granularities should have breakdown data for host
  for (const auto& gran :
       {CPUTimeMonitor::Granularity::MINUTE,
        CPUTimeMonitor::Granularity::SECOND,
        CPUTimeMonitor::Granularity::HUNDRED_MS}) {
    auto idle = monitor->getCpuBreakdownAvg(
        gran, 60, CPUTimeMonitor::CpuBreakdown::IDLE);
    ASSERT_TRUE(idle.has_value()) << "Host idle missing at granularity";
    EXPECT_DOUBLE_EQ(idle.value(), 0.0);
  }

  // Minor tick — adds to SECOND and HUNDRED_MS only
  monitor->tick(minor_tick_1s);

  // MINUTE should still have 1 sample, SECOND should have 2
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1); // minute: unchanged
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2); // second: 1 + 1 minor
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 2); // 100ms: same as second

  // Subminor tick — adds to HUNDRED_MS only
  monitor->tick(subminor_tick_100ms);

  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 3); // 100ms: +1

  // Breakdown should be available at all granularities for the target too
  for (const auto& gran :
       {CPUTimeMonitor::Granularity::MINUTE,
        CPUTimeMonitor::Granularity::SECOND,
        CPUTimeMonitor::Granularity::HUNDRED_MS}) {
    for (const auto& bd :
         {CPUTimeMonitor::CpuBreakdown::IDLE,
          CPUTimeMonitor::CpuBreakdown::SOFTIRQ,
          CPUTimeMonitor::CpuBreakdown::IOWAIT,
          CPUTimeMonitor::CpuBreakdown::HARDIRQ}) {
      auto val = monitor->getCpuBreakdownAvg(gran, 60, bd, "gran_test");
      ASSERT_TRUE(val.has_value());
      EXPECT_DOUBLE_EQ(val.value(), 0.0);
    }
  }

  monitor->deRegisterTarget("gran_test");
}

// Verify readProcStat correctly parses per-core fields beyond idle
// (softirq, iowait, hardirq) from the fixture /proc/stat.
TEST_F(CPUTimeMonitorTest, testReadProcStatPerCoreFields) {
  auto cpuTimePerCore = readProcStat(true);
  ASSERT_EQ(cpuTimePerCore.size(), coreCount + 1); // aggregate + 32 cores

  // Verify aggregate line (index 0)
  EXPECT_EQ(cpuTimePerCore[0].u, 938170131);
  EXPECT_EQ(cpuTimePerCore[0].n, 135328904);
  EXPECT_EQ(cpuTimePerCore[0].s, 418278208);
  EXPECT_EQ(cpuTimePerCore[0].i, 41381479016);
  EXPECT_EQ(cpuTimePerCore[0].w, 109011110);
  EXPECT_EQ(cpuTimePerCore[0].x, 18158); // irq (hardirq)
  EXPECT_EQ(cpuTimePerCore[0].y, 16782689); // softirq

  // Verify cpu0 (index 1) — from fixture:
  // cpu0 85923288 7559744 25071792 1175164067 39404260 4319 4746442 0 ...
  EXPECT_EQ(cpuTimePerCore[1].u, 85923288);
  EXPECT_EQ(cpuTimePerCore[1].n, 7559744);
  EXPECT_EQ(cpuTimePerCore[1].s, 25071792);
  EXPECT_EQ(cpuTimePerCore[1].i, 1175164067);
  EXPECT_EQ(cpuTimePerCore[1].w, 39404260);
  EXPECT_EQ(cpuTimePerCore[1].x, 4319); // irq
  EXPECT_EQ(cpuTimePerCore[1].y, 4746442); // softirq

  // Verify cpu1 (index 2) — from fixture:
  // cpu1 62851079 6305706 22821019 1237053439 8943017 1839 2381064 0 ...
  EXPECT_EQ(cpuTimePerCore[2].u, 62851079);
  EXPECT_EQ(cpuTimePerCore[2].n, 6305706);
  EXPECT_EQ(cpuTimePerCore[2].s, 22821019);
  EXPECT_EQ(cpuTimePerCore[2].i, 1237053439);
  EXPECT_EQ(cpuTimePerCore[2].w, 8943017);
  EXPECT_EQ(cpuTimePerCore[2].x, 1839);
  EXPECT_EQ(cpuTimePerCore[2].y, 2381064);

  // Verify a later core cpu16 (index 17) — from fixture:
  // cpu16 10457382 2821311 4970728 1327321224 470632 0 46151 0 ...
  EXPECT_EQ(cpuTimePerCore[17].u, 10457382);
  EXPECT_EQ(cpuTimePerCore[17].s, 4970728);
  EXPECT_EQ(cpuTimePerCore[17].i, 1327321224);
  EXPECT_EQ(cpuTimePerCore[17].w, 470632);
  EXPECT_EQ(cpuTimePerCore[17].x, 0); // irq = 0
  EXPECT_EQ(cpuTimePerCore[17].y, 46151);
}

// Test cgroup CPU usage processing.
// This test reads real /sys/fs/cgroup/cpu.stat, so it needs the actual host
// core count to pass the cgroup usage validation (usage <= coreCount).
TEST_F(CPUTimeMonitorTest, testCgroupUsageProcessing) {
  // Replace the fixture monitor with one using the real host core count so
  // cgroup usage validation passes. The default fixture uses coreCount=32
  // which may be less than the actual host cores, causing valid cgroup usage
  // to be rejected.
  uint64_t hostCoreCount = folly::available_concurrency();
  std::shared_ptr<CPUTimeMonitor::TTicker> cgroupTicker =
      std::make_shared<CPUTimeMonitor::TTicker>();
  monitor = std::make_shared<CPUTimeMonitor>(
      cgroupTicker, true, hostCoreCount, getenv("TESTROOT"), true);

  auto now = std::chrono::steady_clock::now();
  auto hostTarget = "host";
  auto target2 = "cgroup_target2";

  // Register targets with cgroup paths
  monitor->registerTarget(target2, {0, 1, 2, 3}, "/sys/fs/cgroup");

  // First tick - should initialize but not generate metrics (need delta)
  monitor->tick(major_tick_60s);

  // Check that cgroup data structures are initialized
  for (int i = 0; i < 3; i++) {
    for (const auto& targetId : {hostTarget, target2}) {
      EXPECT_TRUE(cgroupUsageLast_()[i].count(targetId));
      EXPECT_TRUE(cgroupTimeLast_()[i].count(targetId));
    }
    // No metrics should be generated yet (need at least 2 ticks for delta)
    EXPECT_EQ(cgroupUsageMetricFrames_()[i].length(), 0);
  }

  // Second tick - should generate metrics
  monitor->tick(major_tick_60s);

  // Now we should have cgroup metrics
  EXPECT_EQ(cgroupUsageMetricFrames_()[0].length(), 1);
  EXPECT_EQ(cgroupUsageMetricFrames_()[1].length(), 1);
  EXPECT_EQ(cgroupUsageMetricFrames_()[2].length(), 1);

  // Test different granularities
  monitor->tick(minor_tick_1s);
  EXPECT_EQ(cgroupUsageMetricFrames_()[0].length(), 1);
  EXPECT_EQ(cgroupUsageMetricFrames_()[1].length(), 2);
  EXPECT_EQ(cgroupUsageMetricFrames_()[2].length(), 2);

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(cgroupUsageMetricFrames_()[0].length(), 1);
  EXPECT_EQ(cgroupUsageMetricFrames_()[1].length(), 2);
  EXPECT_EQ(cgroupUsageMetricFrames_()[2].length(), 3);

  // Verify that cgroup metrics are accessible
  auto slice = cgroupUsageMetricFrames_()[2].slice(now, now + 60s);
  EXPECT_NE(slice, std::nullopt);

  auto series1 = slice->series<double>(hostTarget);
  auto series2 = slice->series<double>(target2);
  EXPECT_NE(series1, std::nullopt);
  EXPECT_NE(series2, std::nullopt);
  EXPECT_GT(series1->size(), 0);
  EXPECT_GT(series2->size(), 0);

  // Test deregistration cleans up cgroup data
  monitor->deRegisterTarget(target2);
  EXPECT_FALSE(cgroupUsageLast_()[0].count(target2));
  EXPECT_FALSE(cgroupUsageLast_()[1].count(target2));
  EXPECT_FALSE(cgroupUsageLast_()[2].count(target2));

  // host target should still exist
  EXPECT_TRUE(cgroupUsageLast_()[0].count(hostTarget));
  EXPECT_TRUE(cgroupUsageLast_()[1].count(hostTarget));
  EXPECT_TRUE(cgroupUsageLast_()[2].count(hostTarget));
}

// Test cgroup processing with mixed targets (some with cgroup paths, some
// without)
TEST_F(CPUTimeMonitorTest, testMixedTargets) {
  // Register mixed targets
  monitor->registerTarget("proc_only", {0, 1});
  monitor->registerTarget("both_no_cpuset", {}, "/sys/fs/cgroup");
  monitor->registerTarget("both", {2, 3, 4}, "/sys/fs/cgroup");

  // Multiple ticks to generate data
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);
  monitor->tick(minor_tick_1s);
  monitor->tick(subminor_tick_100ms);

  // Verify proc-only target has CPU time data but no cgroup data
  EXPECT_TRUE(procCPUTimeLast_()[0].count("proc_only"));
  EXPECT_FALSE(cgroupUsageLast_()[0].count("proc_only"));

  // Verify cgroup targets have both types of data
  EXPECT_TRUE(procCPUTimeLast_()[0].count("both_no_cpuset"));
  EXPECT_TRUE(cgroupUsageLast_()[0].count("both_no_cpuset"));

  EXPECT_TRUE(procCPUTimeLast_()[0].count("both"));
  EXPECT_TRUE(cgroupUsageLast_()[0].count("both"));

  // Clean up
  monitor->deRegisterTarget("proc_only");
  monitor->deRegisterTarget("both_no_cpuset");
  monitor->deRegisterTarget("both");
}

TEST_F(CPUTimeMonitorTest, testInvalidCgroupPath) {
  // Test with invalid cgroup path
  monitor->registerTarget("invalid_path", {}, "/invalid/cgroup/path");

  // Should not crash, but won't generate cgroup metrics
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);

  // Should have proc data but no cgroup data
  EXPECT_TRUE(procCPUTimeLast_()[0].count("invalid_path"));
  EXPECT_FALSE(cgroupUsageLast_()[0].count("invalid_path"));

  monitor->deRegisterTarget("invalid_path");
}

// Test data source selection functionality
TEST_F(CPUTimeMonitorTest, testDataSourceSelection) {
  // Register target with cgroup path
  monitor->registerTarget("test_target", {}, "/sys/fs/cgroup");

  // Generate some data
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);
  monitor->tick(minor_tick_1s);
  monitor->tick(subminor_tick_100ms);

  // Test default behavior (should use PROC_STAT)
  auto procAvg = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "test_target");
  auto procQuantile = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, 0.5, "test_target");
  auto procRaw = monitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "test_target");

  // Test explicit PROC_STAT
  auto procAvgExplicit = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::PROC_STAT);
  auto procQuantileExplicit = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_target",
      CPUTimeMonitor::DataSource::PROC_STAT);
  auto procRawExplicit = monitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::PROC_STAT);

  // Default and explicit PROC_STAT should be the same
  EXPECT_EQ(procAvg, procAvgExplicit);
  EXPECT_EQ(procQuantile, procQuantileExplicit);
  EXPECT_EQ(procRaw, procRawExplicit);

  // Test CGROUP_STAT
  auto cgroupAvg = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::CGROUP_STAT);
  auto cgroupQuantile = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_target",
      CPUTimeMonitor::DataSource::CGROUP_STAT);
  auto cgroupRaw = monitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::CGROUP_STAT);

  // All should have values (assuming cgroup data is available)
  EXPECT_NE(procAvg, std::nullopt);
  EXPECT_NE(procQuantile, std::nullopt);
  EXPECT_FALSE(procRaw.empty());

  EXPECT_NE(cgroupAvg, std::nullopt);
  EXPECT_NE(cgroupQuantile, std::nullopt);
  EXPECT_FALSE(cgroupRaw.empty());

  // Proc and cgroup values should be different (as mentioned in the commit
  // message)
  EXPECT_NE(procAvg, cgroupAvg);
  EXPECT_NE(procQuantile, cgroupQuantile);

  // Test with host target (should work with both data sources)
  auto hostProcAvg = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      std::nullopt,
      CPUTimeMonitor::DataSource::PROC_STAT);
  EXPECT_NE(hostProcAvg, std::nullopt);

  auto hostCgroupAvg = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      std::nullopt,
      CPUTimeMonitor::DataSource::CGROUP_STAT);
  EXPECT_NE(hostCgroupAvg, std::nullopt);

  monitor->deRegisterTarget("test_target");
}

TEST_F(CPUTimeMonitorTest, testConcurrentTickAndTargetUpdates) {
  std::atomic<bool> start{false};
  std::atomic<int> completedReads{0};
  std::atomic<int> completedUpdates{0};
  constexpr int kIterations = 200;

  std::thread ticker([&] {
    while (!start.load(std::memory_order_acquire)) {
      std::this_thread::yield();
    }
    for (int i = 0; i < kIterations; ++i) {
      monitor->tick(subminor_tick_100ms);
      monitor->getQuantileCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, 0.95, "race_target");
      completedReads.fetch_add(1, std::memory_order_relaxed);
    }
  });

  std::thread targetUpdater([&] {
    while (!start.load(std::memory_order_acquire)) {
      std::this_thread::yield();
    }
    for (int i = 0; i < kIterations; ++i) {
      monitor->registerTarget("race_target", {0, 1, 2, 3});
      monitor->deRegisterTarget("race_target");
      completedUpdates.fetch_add(1, std::memory_order_relaxed);
    }
  });

  start.store(true, std::memory_order_release);
  ticker.join();
  targetUpdater.join();

  EXPECT_EQ(completedReads.load(), kIterations);
  EXPECT_EQ(completedUpdates.load(), kIterations);

  monitor->registerTarget("race_target", {0, 1, 2, 3});
  monitor->tick(subminor_tick_100ms);
  monitor->tick(subminor_tick_100ms);
  const auto usage = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, 0.95, "race_target");
  ASSERT_TRUE(usage.has_value());
  EXPECT_NEAR(usage.value(), 4.0, 0.1);
}

// Test feature flag behavior - when readCgroupStat is disabled, should always
// use PROC_STAT
TEST_F(CPUTimeMonitorTest, testFeatureFlagFallback) {
  // Create monitor with readCgroupStat disabled
  std::shared_ptr<CPUTimeMonitor::TTicker> disabledTicker =
      std::make_shared<CPUTimeMonitor::TTicker>();
  auto disabledMonitor = std::make_shared<CPUTimeMonitor>(
      disabledTicker,
      false /* readCgroupStat disabled */,
      coreCount,
      getenv("TESTROOT"),
      true);

  // Register target with cgroup path
  disabledMonitor->registerTarget("test_target", {}, "/sys/fs/cgroup");

  // Generate some data
  disabledMonitor->tick(major_tick_60s);
  disabledMonitor->tick(major_tick_60s);
  disabledMonitor->tick(minor_tick_1s);
  disabledMonitor->tick(subminor_tick_100ms);

  // Request CGROUP_STAT data source, but should get PROC_STAT due to feature
  // flag
  auto procAvg = disabledMonitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::PROC_STAT);

  auto cgroupRequestedAvg = disabledMonitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::CGROUP_STAT);

  // Both should return the same value (proc data) since feature flag is
  // disabled
  EXPECT_EQ(procAvg, cgroupRequestedAvg);

  // Same test for quantile
  auto procQuantile = disabledMonitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_target",
      CPUTimeMonitor::DataSource::PROC_STAT);

  auto cgroupRequestedQuantile = disabledMonitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_target",
      CPUTimeMonitor::DataSource::CGROUP_STAT);

  EXPECT_EQ(procQuantile, cgroupRequestedQuantile);

  // Same test for raw data
  auto procRaw = disabledMonitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::PROC_STAT);

  auto cgroupRequestedRaw = disabledMonitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_target",
      CPUTimeMonitor::DataSource::CGROUP_STAT);

  EXPECT_EQ(procRaw, cgroupRequestedRaw);

  disabledMonitor->deRegisterTarget("test_target");
}

// Verify that breakdown series keys in the MetricFrameMap use the correct
// pattern: "targetId.suffix" (e.g., "host.idle", "myTarget.softirq").
// The ODS key pattern "dyno.allotment.cpu.idle" (without ".avg.60") is used
// by AllotmentMetricsPublisher with ODSSimpleConfig, which appends the
// aggregation suffix automatically.
TEST_F(CPUTimeMonitorTest, testBreakdownSeriesKeyPattern) {
  monitor->registerTarget("key_test", {0, 1});

  // Generate data
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);

  auto now = std::chrono::steady_clock::now();

  // Verify breakdown series exist with correct key pattern in the frame
  auto& frame = procCPUTimeMetricFrames_()[0];
  auto slice = frame.slice(now - 60s, now);
  ASSERT_NE(slice, std::nullopt);

  // Host breakdown keys: "host.idle", "host.softirq", "host.iowait",
  // "host.hardirq"
  for (const auto& suffix : {".idle", ".softirq", ".iowait", ".hardirq"}) {
    std::string key = std::string("host") + suffix;
    auto series = slice->series<double>(key);
    ASSERT_NE(series, std::nullopt) << "Missing series for key: " << key;
    EXPECT_GT(series->size(), 0) << "Empty series for key: " << key;
  }

  // Target breakdown keys: "key_test.idle", etc.
  for (const auto& suffix : {".idle", ".softirq", ".iowait", ".hardirq"}) {
    std::string key = std::string("key_test") + suffix;
    auto series = slice->series<double>(key);
    ASSERT_NE(series, std::nullopt) << "Missing series for key: " << key;
    EXPECT_GT(series->size(), 0) << "Empty series for key: " << key;
  }

  // Verify that keys with ".avg.60" suffix do NOT exist in the frame
  // (the suffix is added by ODSSimpleConfig, not stored in MetricFrameMap)
  for (const auto& suffix :
       {".idle.avg.60",
        ".softirq.avg.60",
        ".iowait.avg.60",
        ".hardirq.avg.60"}) {
    std::string key = std::string("host") + suffix;
    auto series = slice->series<double>(key);
    EXPECT_EQ(series, std::nullopt)
        << "Unexpected series with .avg.60 suffix: " << key;
  }

  // Verify getCpuBreakdownAvg maps correctly to these keys
  auto idle = monitor->getCpuBreakdownAvg(
      CPUTimeMonitor::Granularity::MINUTE,
      60,
      CPUTimeMonitor::CpuBreakdown::IDLE,
      "key_test");
  ASSERT_TRUE(idle.has_value());

  auto softirq = monitor->getCpuBreakdownAvg(
      CPUTimeMonitor::Granularity::MINUTE,
      60,
      CPUTimeMonitor::CpuBreakdown::SOFTIRQ,
      "key_test");
  ASSERT_TRUE(softirq.has_value());

  auto iowait = monitor->getCpuBreakdownAvg(
      CPUTimeMonitor::Granularity::MINUTE,
      60,
      CPUTimeMonitor::CpuBreakdown::IOWAIT,
      "key_test");
  ASSERT_TRUE(iowait.has_value());

  auto hardirq = monitor->getCpuBreakdownAvg(
      CPUTimeMonitor::Granularity::MINUTE,
      60,
      CPUTimeMonitor::CpuBreakdown::HARDIRQ,
      "key_test");
  ASSERT_TRUE(hardirq.has_value());

  monitor->deRegisterTarget("key_test");
}

} // namespace dynolog
} // namespace facebook
