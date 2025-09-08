/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/procfs/parser/InterruptStatsMonitor.h"
#include <gtest/gtest.h>

namespace facebook::dynolog {

namespace {

class MockSystemInfo : public ::testing::Test {};
} // namespace

using namespace ::testing;

class InterruptStatsMonitorTest : public Test {};

/*-- how to check : use this script
 * cat dyno/cpp/server/test/root_files/proc/interrupts  | \
 *  awk '{ sum = 0; for(i = 2; i < 32+2; i++) {sum+=$i;}; print $1, sum}'
 */
TEST_F(InterruptStatsMonitorTest, testInterruptsRefresh) {
  auto intStats = InterruptStatsMonitor::makeTestClass(std::getenv("TESTROOT"));
  intStats.cpuCount_ = 32;
  intStats.interruptsRefresh();
  // Since implementation relies on integer division by UINT32_MAX
  // the exact value is compiler/architecture dependent
  EXPECT_NEAR(intStats.stats.tlbshootdowns, 12808065226, 1000000);
  EXPECT_NEAR(intStats.stats.tlbshootdownsPrev, 12808065226, 1000000);
  EXPECT_NEAR(intStats.stats.eth0Intrps, 13445742397, 1000000);
  EXPECT_NEAR(intStats.stats.eth0IntrpsPrev, 13445742397, 1000000);
}

TEST_F(InterruptStatsMonitorTest, testInterruptsRefreshInvalidPath) {
  std::string rootPath = std::getenv("TESTROOT");
  auto intStats =
      InterruptStatsMonitor::makeTestClass(rootPath + "invalid/path");
  intStats.cpuCount_ = 32;
  intStats.interruptsRefresh();
  // expect previous stats
  EXPECT_EQ(intStats.stats.tlbshootdowns, 0);
  EXPECT_EQ(intStats.stats.tlbshootdownsPrev, 0);
  EXPECT_EQ(intStats.stats.eth0Intrps, 0);
  EXPECT_EQ(intStats.stats.eth0IntrpsPrev, 0);
}

TEST_F(InterruptStatsMonitorTest, testInterruptsRefreshIncorrectCoreCount) {
  auto intStats = InterruptStatsMonitor::makeTestClass(std::getenv("TESTROOT"));
  intStats.cpuCount_ = 16; // incorrect #cores
  intStats.interruptsRefresh();
  EXPECT_EQ(intStats.stats.tlbshootdowns, 0);
  EXPECT_EQ(intStats.stats.tlbshootdownsPrev, 0);
  EXPECT_EQ(intStats.stats.eth0Intrps, 0);
  EXPECT_EQ(intStats.stats.eth0IntrpsPrev, 0);

  auto intStats1 =
      InterruptStatsMonitor::makeTestClass(std::getenv("TESTROOT"));
  intStats1.cpuCount_ = 32; // correct #cores
  intStats1.interruptsRefresh();
  EXPECT_NEAR(intStats1.stats.tlbshootdowns, 12808065226, 1000000);
  EXPECT_NEAR(intStats1.stats.tlbshootdownsPrev, 12808065226, 1000000);
  EXPECT_NEAR(intStats1.stats.eth0Intrps, 13445742397, 1000000);
  EXPECT_NEAR(intStats1.stats.eth0IntrpsPrev, 13445742397, 1000000);
}

} // namespace facebook::dynolog
