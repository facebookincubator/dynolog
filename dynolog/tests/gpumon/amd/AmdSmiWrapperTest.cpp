/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdSmiWrapper.h"
#include <gtest/gtest.h>

using namespace ::dynolog::gpumon;

TEST(AmdSmiWrapperTest, notInitializedByDefault) {
  AmdSmiWrapper wrapper;
  EXPECT_FALSE(wrapper.isInitialized());
}

TEST(AmdSmiWrapperTest, getMetricsThrowsBeforeInit) {
  AmdSmiWrapper wrapper;
  EXPECT_THROW(wrapper.getMetrics(), std::runtime_error);
}

// Two consecutive 1s samples from a busy MI300X (twshared66282.04.rva3, OAM 0)
// whose pcie_bandwidth_inst read the 18 Mb/s idle floor at the later sample;
// amd-smi metric on the same host reported ~330-400 Mb/s.
TEST(AveragePcieBandwidthTest, averagesAccumulatorOverCounterTicks) {
  const PcieBandwidthAccSample prev{
      .bandwidth_acc = 219059847286, .accumulation_counter = 530961935};
  const PcieBandwidthAccSample cur{
      .bandwidth_acc = 219060304101, .accumulation_counter = 530962934};
  // 456815 accumulated Mb/s over 999 ticks
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(prev, cur), 457);
}

TEST(AveragePcieBandwidthTest, idleLinkIsZero) {
  const PcieBandwidthAccSample prev{
      .bandwidth_acc = 1000, .accumulation_counter = 10};
  const PcieBandwidthAccSample cur{
      .bandwidth_acc = 1000, .accumulation_counter = 1010};
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(prev, cur), 0);
}

TEST(AveragePcieBandwidthTest, counterNotAdvancingIsMissing) {
  const PcieBandwidthAccSample sample{
      .bandwidth_acc = 1000, .accumulation_counter = 10};
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(sample, sample), -1);
}

TEST(AveragePcieBandwidthTest, resetBetweenSamplesIsMissing) {
  const PcieBandwidthAccSample prev{
      .bandwidth_acc = 500000, .accumulation_counter = 1000};
  const PcieBandwidthAccSample counterReset{
      .bandwidth_acc = 600000, .accumulation_counter = 5};
  const PcieBandwidthAccSample accReset{
      .bandwidth_acc = 100, .accumulation_counter = 2000};
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(prev, counterReset), -1);
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(prev, accReset), -1);
}

TEST(AveragePcieBandwidthTest, unsupportedFieldIsMissing) {
  constexpr uint64_t kSentinel = std::numeric_limits<uint64_t>::max();
  const PcieBandwidthAccSample prev{
      .bandwidth_acc = 1000, .accumulation_counter = 10};
  const PcieBandwidthAccSample noAcc{
      .bandwidth_acc = kSentinel, .accumulation_counter = 1010};
  const PcieBandwidthAccSample noCounter{
      .bandwidth_acc = 2000, .accumulation_counter = kSentinel};
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(prev, noAcc), -1);
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(prev, noCounter), -1);
  EXPECT_EQ(averagePcieBandwidthMegabitsPerSec(noAcc, prev), -1);
}
