// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/CPUTimeMonitor.h"
#include <gtest/gtest.h>

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
  EXPECT_EQ(cpuTime, std::vector<uint64_t>{allCoresReference[0]});
  auto cpuTimePerCore = readProcStat(true);
  EXPECT_EQ(cpuTimePerCore, allCoresReference);
}

TEST_F(CPUTimeMonitorTest, testCgroupCpuStat) {
  std::string allotmentPath("/sys/fs/cgroup");
  auto cpuUsage = readCgroupCpuStat(allotmentPath);
  EXPECT_NE(cpuUsage, std::nullopt);
}
// Test the tick function
TEST_F(CPUTimeMonitorTest, testAllotment) {
  auto now = std::chrono::steady_clock::now();
  monitor->tick(major_tick_60s);
  EXPECT_EQ(procCPUTimeLast_()[0]["host"], allCoresReference[0]);
  EXPECT_EQ(procCPUTimeLast_()[1]["host"], allCoresReference[0]);
  EXPECT_EQ(procCPUTimeLast_()[2]["host"], allCoresReference[0]);

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

  auto checkStats = [&](const std::optional<std::string>& allotmentId =
                            std::nullopt,
                        double expected = coreCount) {
    for (int i = 0; i < 2; i++) {
      // Zero idle delta means maximum CPU usage
      EXPECT_NEAR(
          procCPUTimeMetricFrames_()[i]
              .slice(now, now + 60s)
              ->series<double>(allotmentId.value_or("host"))
              ->avg<double>(),
          expected,
          0.1);
    }

    EXPECT_NEAR(
        *monitor->getAvgCPUCoresUsage(
            CPUTimeMonitor::Granularity::MINUTE, 60, allotmentId),
        expected,
        0.1);
    EXPECT_NEAR(
        *monitor->getAvgCPUCoresUsage(
            CPUTimeMonitor::Granularity::SECOND, 60, allotmentId),
        expected,
        0.1);
    EXPECT_NEAR(
        *monitor->getAvgCPUCoresUsage(
            CPUTimeMonitor::Granularity::HUNDRED_MS, 60, allotmentId),
        expected,
        0.1);

    for (const auto& quant : {0.0, 0.1, 0.5, 0.9, 1.0}) {
      EXPECT_NEAR(
          *monitor->getQuantileCPUCoresUsage(
              CPUTimeMonitor::Granularity::MINUTE, 60, quant, allotmentId),
          expected,
          0.1);
      EXPECT_NEAR(
          *monitor->getQuantileCPUCoresUsage(
              CPUTimeMonitor::Granularity::SECOND, 60, quant, allotmentId),
          expected,
          0.1);
      EXPECT_NEAR(
          *monitor->getQuantileCPUCoresUsage(
              CPUTimeMonitor::Granularity::HUNDRED_MS, 60, quant, allotmentId),
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

  monitor->registerAllotment("allotment1", {});
  monitor->registerAllotment("allotment2", {0, 1, 2, 3, 4, 5, 6, 7});

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 4);
  checkStats();

  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment2"),
      std::nullopt);

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 5);
  checkStats();

  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment2"),
      std::nullopt);

  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment1"),
      coreCount,
      0.1);
  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment2"),
      8.0,
      0.1);

  monitor->tick(major_tick_60s);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 2);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 3);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 6);
  checkStats();

  // still don't expect allotments to have minutely data becase we only have 1
  // sample
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment2"),
      std::nullopt);
  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment1"),
      coreCount,
      0.1);
  EXPECT_NEAR(
      *monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment2"),
      8.0,
      0.1);

  monitor->tick(major_tick_60s);
  EXPECT_EQ(procCPUTimeMetricFrames_()[0].length(), 3);
  EXPECT_EQ(procCPUTimeMetricFrames_()[1].length(), 4);
  EXPECT_EQ(procCPUTimeMetricFrames_()[2].length(), 7);

  // Now all allotments have data for all granularities
  checkStats();
  checkStats("allotment1");
  checkStats("allotment2", 8.0);

  monitor->deRegisterAllotment("allotment1");
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment1"),
      std::nullopt);

  monitor->tick(major_tick_60s);
  checkStats();
  checkStats("allotment2", 8.0);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment1"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment1"),
      std::nullopt);

  monitor->deRegisterAllotment("allotment2");

  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::MINUTE, 60, "allotment2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::SECOND, 60, "allotment2"),
      std::nullopt);
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(
          CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "allotment2"),
      std::nullopt);

  monitor->tick(major_tick_60s);
  checkStats();
  monitor->tick(minor_tick_1s);
  checkStats();
  monitor->tick(subminor_tick_100ms);
  checkStats();
}

// Test cgroup CPU usage processing
TEST_F(CPUTimeMonitorTest, testCgroupUsageProcessing) {
  auto now = std::chrono::steady_clock::now();
  auto hostAllotment = "host";
  auto allotment2 = "cgroup_allotment2";

  // Register allotments with cgroup paths
  monitor->registerAllotment(allotment2, {0, 1, 2, 3}, "/sys/fs/cgroup");

  // First tick - should initialize but not generate metrics (need delta)
  monitor->tick(major_tick_60s);

  // Check that cgroup data structures are initialized
  for (int i = 0; i < 3; i++) {
    for (const auto& allotmentId : {hostAllotment, allotment2}) {
      EXPECT_TRUE(cgroupUsageLast_()[i].count(allotmentId));
      EXPECT_TRUE(cgroupTimeLast_()[i].count(allotmentId));
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

  auto series1 = slice->series<double>(hostAllotment);
  auto series2 = slice->series<double>(allotment2);
  EXPECT_NE(series1, std::nullopt);
  EXPECT_NE(series2, std::nullopt);
  EXPECT_GT(series1->size(), 0);
  EXPECT_GT(series2->size(), 0);

  // Test deregistration cleans up cgroup data
  monitor->deRegisterAllotment(allotment2);
  EXPECT_FALSE(cgroupUsageLast_()[0].count(allotment2));
  EXPECT_FALSE(cgroupUsageLast_()[1].count(allotment2));
  EXPECT_FALSE(cgroupUsageLast_()[2].count(allotment2));

  // host allotment should still exist
  EXPECT_TRUE(cgroupUsageLast_()[0].count(hostAllotment));
  EXPECT_TRUE(cgroupUsageLast_()[1].count(hostAllotment));
  EXPECT_TRUE(cgroupUsageLast_()[2].count(hostAllotment));
}

// Test cgroup processing with mixed allotments (some with cgroup paths, some
// without)
TEST_F(CPUTimeMonitorTest, testMixedAllotments) {
  // Register mixed allotments
  monitor->registerAllotment("proc_only", {0, 1});
  monitor->registerAllotment("both_no_cpuset", {}, "/sys/fs/cgroup");
  monitor->registerAllotment("both", {2, 3, 4}, "/sys/fs/cgroup");

  // Multiple ticks to generate data
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);
  monitor->tick(minor_tick_1s);
  monitor->tick(subminor_tick_100ms);

  // Verify proc-only allotment has CPU time data but no cgroup data
  EXPECT_TRUE(procCPUTimeLast_()[0].count("proc_only"));
  EXPECT_FALSE(cgroupUsageLast_()[0].count("proc_only"));

  // Verify cgroup allotments have both types of data
  EXPECT_TRUE(procCPUTimeLast_()[0].count("both_no_cpuset"));
  EXPECT_TRUE(cgroupUsageLast_()[0].count("both_no_cpuset"));

  EXPECT_TRUE(procCPUTimeLast_()[0].count("both"));
  EXPECT_TRUE(cgroupUsageLast_()[0].count("both"));

  // Clean up
  monitor->deRegisterAllotment("proc_only");
  monitor->deRegisterAllotment("both_no_cpuset");
  monitor->deRegisterAllotment("both");
}

TEST_F(CPUTimeMonitorTest, testInvalidCgroupPath) {
  // Test with invalid cgroup path
  monitor->registerAllotment("invalid_path", {}, "/invalid/cgroup/path");

  // Should not crash, but won't generate cgroup metrics
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);

  // Should have proc data but no cgroup data
  EXPECT_TRUE(procCPUTimeLast_()[0].count("invalid_path"));
  EXPECT_FALSE(cgroupUsageLast_()[0].count("invalid_path"));

  monitor->deRegisterAllotment("invalid_path");
}

// Test data source selection functionality
TEST_F(CPUTimeMonitorTest, testDataSourceSelection) {
  // Register allotment with cgroup path
  monitor->registerAllotment("test_allotment", {}, "/sys/fs/cgroup");

  // Generate some data
  monitor->tick(major_tick_60s);
  monitor->tick(major_tick_60s);
  monitor->tick(minor_tick_1s);
  monitor->tick(subminor_tick_100ms);

  // Test default behavior (should use PROC_STAT)
  auto procAvg = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "test_allotment");
  auto procQuantile = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, 0.5, "test_allotment");
  auto procRaw = monitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS, 60, "test_allotment");

  // Test explicit PROC_STAT
  auto procAvgExplicit = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_allotment",
      CPUTimeMonitor::DataSource::PROC_STAT);
  auto procQuantileExplicit = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_allotment",
      CPUTimeMonitor::DataSource::PROC_STAT);
  auto procRawExplicit = monitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_allotment",
      CPUTimeMonitor::DataSource::PROC_STAT);

  // Default and explicit PROC_STAT should be the same
  EXPECT_EQ(procAvg, procAvgExplicit);
  EXPECT_EQ(procQuantile, procQuantileExplicit);
  EXPECT_EQ(procRaw, procRawExplicit);

  // Test CGROUP_STAT
  auto cgroupAvg = monitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_allotment",
      CPUTimeMonitor::DataSource::CGROUP_STAT);
  auto cgroupQuantile = monitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_allotment",
      CPUTimeMonitor::DataSource::CGROUP_STAT);
  auto cgroupRaw = monitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_allotment",
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

  // Test with host allotment (should work with both data sources)
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

  monitor->deRegisterAllotment("test_allotment");
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

  // Register allotment with cgroup path
  disabledMonitor->registerAllotment("test_allotment", {}, "/sys/fs/cgroup");

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
      "test_allotment",
      CPUTimeMonitor::DataSource::PROC_STAT);

  auto cgroupRequestedAvg = disabledMonitor->getAvgCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_allotment",
      CPUTimeMonitor::DataSource::CGROUP_STAT);

  // Both should return the same value (proc data) since feature flag is
  // disabled
  EXPECT_EQ(procAvg, cgroupRequestedAvg);

  // Same test for quantile
  auto procQuantile = disabledMonitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_allotment",
      CPUTimeMonitor::DataSource::PROC_STAT);

  auto cgroupRequestedQuantile = disabledMonitor->getQuantileCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      0.5,
      "test_allotment",
      CPUTimeMonitor::DataSource::CGROUP_STAT);

  EXPECT_EQ(procQuantile, cgroupRequestedQuantile);

  // Same test for raw data
  auto procRaw = disabledMonitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_allotment",
      CPUTimeMonitor::DataSource::PROC_STAT);

  auto cgroupRequestedRaw = disabledMonitor->getRawCPUCoresUsage(
      CPUTimeMonitor::Granularity::HUNDRED_MS,
      60,
      "test_allotment",
      CPUTimeMonitor::DataSource::CGROUP_STAT);

  EXPECT_EQ(procRaw, cgroupRequestedRaw);

  disabledMonitor->deRegisterAllotment("test_allotment");
}

} // namespace dynolog
} // namespace facebook
