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
      ticker, getenv("TESTROOT"), coreCount, true);
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
  auto& CPUTimeLast_() const {
    return monitor->CPUTimeLast_;
  }
  auto& CPUTimeMetricFrames_() const {
    return monitor->CPUTimeMetricFrames_;
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

// Test the tick function
TEST_F(CPUTimeMonitorTest, testAllotment) {
  auto now = std::chrono::steady_clock::now();
  monitor->tick(major_tick_60s);
  EXPECT_EQ(CPUTimeLast_()[0]["host"], allCoresReference[0]);
  EXPECT_EQ(CPUTimeLast_()[1]["host"], allCoresReference[0]);
  EXPECT_EQ(CPUTimeLast_()[2]["host"], allCoresReference[0]);

  // need at least 2 ticks to get the delta
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 0);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 0);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 0);

  for (int i = 0; i < 2; i++) {
    ASSERT_EQ(CPUTimeMetricFrames_()[i].slice(now, now + 60s), std::nullopt);
  }
  EXPECT_EQ(
      monitor->getAvgCPUCoresUsage(CPUTimeMonitor::Granularity::MINUTE, 60),
      std::nullopt);

  monitor->tick(major_tick_60s);
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 1);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 1);

  auto checkStats = [&](const std::optional<std::string>& allotmentId =
                            std::nullopt,
                        double expected = coreCount) {
    for (int i = 0; i < 2; i++) {
      // Zero idle delta means maximum CPU usage
      EXPECT_NEAR(
          CPUTimeMetricFrames_()[i]
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
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 2);

  checkStats();

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 3);

  checkStats();

  monitor->registerAllotment("allotment1", {});
  monitor->registerAllotment("allotment2", {0, 1, 2, 3, 4, 5, 6, 7});

  monitor->tick(subminor_tick_100ms);
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 4);
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
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 1);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 2);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 5);
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
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 2);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 3);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 6);
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
  EXPECT_EQ(CPUTimeMetricFrames_()[0].length(), 3);
  EXPECT_EQ(CPUTimeMetricFrames_()[1].length(), 4);
  EXPECT_EQ(CPUTimeMetricFrames_()[2].length(), 7);

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

} // namespace dynolog
} // namespace facebook
