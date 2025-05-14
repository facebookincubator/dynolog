// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <dynolog/src/metric_frame/MetricFrame.h>
#include <gtest/gtest_prod.h>
#include <memory>
#include <shared_mutex>
#include "dyno/cpp/server/DynoCommon.h"
#include "dynolog/src/MonitorBase.h"
#include "dynolog/src/Ticker.h"

namespace facebook {
namespace dynolog {

struct InterruptStats {
  int64_t tlbshootdowns, tlbshootdownsPrev;
  int64_t eth0Intrps, eth0IntrpsPrev;
};

class InterruptStatsMonitor : MonitorBase<Ticker<60000, 1000, 1, 2>> {
 private:
  std::string const rootDir_;
  int16_t cpuCount_;
  std::shared_mutex dataLock_;
  InterruptStats stats{};
  // level wise stats ( 0 - major, 1 - minor, ...)
  std::unordered_map<int8_t, InterruptStats> interruptStats_;
  InterruptStats interruptsRefresh();
  InterruptStats getInterruptStatsPerMinute();
  InterruptStats getInterruptStatsPerSecond();

  explicit InterruptStatsMonitor(const std::string& rootDir = "");

 public:
  using TTicker = Ticker<60000, 1000, 1, 2>;
  using typename MonitorBase<TTicker>::TMask;
  // maps client req granularity with level wise stats (interruptStats_)
  enum class Granularity { MINUTE = 0, SECOND = 1 };
  void tick(TMask mask) override;
  InterruptStats getInterruptStats(Granularity granularity);

  explicit InterruptStatsMonitor(
      std::shared_ptr<TTicker> ticker,
      const std::string& rootDir = "");

  static InterruptStatsMonitor makeTestClass(const std::string& rootDir);

  FRIEND_TEST(InterruptStatsMonitorTest, testInterruptsRefresh);
  FRIEND_TEST(InterruptStatsMonitorTest, testInterruptsRefreshInvalidPath);
  FRIEND_TEST(
      InterruptStatsMonitorTest,
      testInterruptsRefreshIncorrectCoreCount);
};

} // namespace dynolog

} // namespace facebook
