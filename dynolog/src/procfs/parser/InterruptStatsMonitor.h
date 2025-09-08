/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <fstream>
#include <memory>
#include <shared_mutex>

#include <gtest/gtest_prod.h>

#include "dynolog/src/MonitorBase.h"
#include "dynolog/src/Ticker.h"
#include "dynolog/src/metric_frame/MetricFrame.h"

namespace facebook {
namespace dynolog {

struct InterruptStats {
  int64_t tlbshootdowns, tlbshootdownsPrev;
  int64_t eth0Intrps, eth0IntrpsPrev;
};

// The Ticket template is configured to have the major tick at 60sec, minor at
// 1sec intervals
class InterruptStatsMonitor : MonitorBase<Ticker<60000, 1000, 1, 2>> {
 private:
  int16_t cpuCount_;
  std::shared_mutex dataLock_;
  std::ifstream procInterrupts_;
  InterruptStats stats{};
  InterruptStats statsAtMinuteTick_{};
  InterruptStats statsAtSecondTick_{};
  InterruptStats interruptsRefresh();
  InterruptStats getInterruptStatsPerMinute();
  InterruptStats getInterruptStatsPerSecond();

  explicit InterruptStatsMonitor(const std::string& rootDir = "");

 public:
  using TTicker = Ticker<60000, 1000, 1, 2>;
  using typename MonitorBase<TTicker>::TMask;
  enum class Granularity { MINUTE, SECOND };
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
