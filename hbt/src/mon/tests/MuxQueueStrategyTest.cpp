// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/MuxQueueStrategy.h"
#include <gtest/gtest.h>

namespace facebook::hbt::mon {
namespace {

using MuxGroupId = std::optional<std::string>;
using ElemId = std::string;

class MuxQueueStrategyTest : public ::testing::Test {
 protected:
  MuxQueueStrategy<MuxGroupId, ElemId> strategy_;
};

TEST_F(MuxQueueStrategyTest, EmptyStrategyReturnsNoEnabledGroups) {
  EXPECT_TRUE(strategy_.empty());
  EXPECT_TRUE(strategy_.getEnabledGroupIds().empty());
}

TEST_F(MuxQueueStrategyTest, AddEntryCreatesGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  EXPECT_FALSE(strategy_.empty());
  const auto& group = strategy_.getGroup("group1");
  EXPECT_EQ(group.size(), 1);
  EXPECT_TRUE(group.count("elem1"));
}

TEST_F(MuxQueueStrategyTest, AddMultipleEntriesToSameGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group1", "elem2", std::nullopt);
  strategy_.addEntry("group1", "elem3", std::nullopt);

  const std::set<std::string> expected{"elem1", "elem2", "elem3"};
  EXPECT_EQ(strategy_.getGroup("group1"), expected);
}

TEST_F(MuxQueueStrategyTest, SingleGroupAlwaysEnabled) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  auto enabled = strategy_.getEnabledGroupIds();
  EXPECT_EQ(enabled.size(), 1);
  EXPECT_TRUE(enabled.count("group1"));

  // After advance, still the same group (only one in queue)
  strategy_.advance();
  enabled = strategy_.getEnabledGroupIds();
  EXPECT_EQ(enabled.size(), 1);
  EXPECT_TRUE(enabled.count("group1"));
}

TEST_F(MuxQueueStrategyTest, RoundRobinRotation) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group2", "elem2", std::nullopt);
  strategy_.addEntry("group3", "elem3", std::nullopt);

  // Initially the first added group should be enabled
  auto enabled = strategy_.getEnabledGroupIds();
  EXPECT_EQ(enabled.size(), 1);
  MuxGroupId first = *enabled.begin();

  // After 3 rotations, should cycle back to the original group
  std::set<MuxGroupId> seen;
  seen.insert(first);
  for (int i = 0; i < 3; ++i) {
    strategy_.advance();
    enabled = strategy_.getEnabledGroupIds();
    EXPECT_EQ(enabled.size(), 1);
    seen.insert(*enabled.begin());
  }

  const std::set<MuxGroupId> expected{"group1", "group2", "group3"};
  EXPECT_EQ(seen, expected);

  // After full cycle, back to original
  enabled = strategy_.getEnabledGroupIds();
  EXPECT_EQ(*enabled.begin(), first);
}

TEST_F(MuxQueueStrategyTest, RemoveEntryFromGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group1", "elem2", std::nullopt);

  EXPECT_TRUE(strategy_.removeEntry("group1", "elem1"));

  const auto& group = strategy_.getGroup("group1");
  EXPECT_EQ(group.size(), 1);
  EXPECT_TRUE(group.count("elem2"));
  EXPECT_FALSE(strategy_.empty());
}

TEST_F(MuxQueueStrategyTest, RemoveLastEntryRemovesGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  EXPECT_TRUE(strategy_.removeEntry("group1", "elem1"));
  EXPECT_TRUE(strategy_.empty());

  // getGroup on removed group throws
  EXPECT_THROW(strategy_.getGroup("group1"), std::runtime_error);
}

TEST_F(MuxQueueStrategyTest, RemoveNonexistentReturnsFalse) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  EXPECT_FALSE(strategy_.removeEntry("group1", "nonexistent"));
  EXPECT_FALSE(strategy_.removeEntry("nonexistent_group", "elem1"));
}

TEST_F(MuxQueueStrategyTest, RemoveGroupUpdatesRotation) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group2", "elem2", std::nullopt);
  strategy_.addEntry("group3", "elem3", std::nullopt);

  // Remove group2
  EXPECT_TRUE(strategy_.removeEntry("group2", "elem2"));

  // Should still rotate between group1 and group3
  std::set<MuxGroupId> seen;
  for (int i = 0; i < 3; ++i) {
    auto enabled = strategy_.getEnabledGroupIds();
    EXPECT_EQ(enabled.size(), 1);
    seen.insert(*enabled.begin());
    strategy_.advance();
  }

  const std::set<MuxGroupId> expected{"group1", "group3"};
  EXPECT_EQ(seen, expected);
}

TEST_F(MuxQueueStrategyTest, GetGroupThrowsForUnknown) {
  EXPECT_THROW(strategy_.getGroup("nonexistent"), std::runtime_error);
}

TEST_F(MuxQueueStrategyTest, PerPmuTypeQueues) {
  MuxQueueStrategy<MuxGroupId, ElemId> per_pmu_strategy(
      /*mux_queue_per_pmu_type=*/true);

  // Add groups with different PMU types
  per_pmu_strategy.addEntry(
      "cpu_group1", "elem1", perf_event::PmuType::generic_hardware);
  per_pmu_strategy.addEntry(
      "cpu_group2", "elem2", perf_event::PmuType::generic_hardware);
  per_pmu_strategy.addEntry(
      "uncore_group1", "elem3", perf_event::PmuType::uncore_imc);

  // Both queues should have their front group enabled
  auto enabled = per_pmu_strategy.getEnabledGroupIds();
  EXPECT_EQ(enabled.size(), 2);

  // After advance, cpu queue rotates but uncore stays (only 1 group)
  per_pmu_strategy.advance();
  enabled = per_pmu_strategy.getEnabledGroupIds();
  EXPECT_EQ(enabled.size(), 2);
  EXPECT_TRUE(enabled.count("uncore_group1"));
}

TEST_F(MuxQueueStrategyTest, ConfigureScheduleIsNoOp) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  // configureSchedule should be a no-op for MuxQueueStrategy (returns true)
  ScheduleConfig config;
  config.enablesPerCycle = 12;
  EXPECT_TRUE(strategy_.configureSchedule("group1", config));

  // Behavior should not change - still round-robin
  auto enabled = strategy_.getEnabledGroupIds();
  EXPECT_EQ(enabled.size(), 1);
  EXPECT_TRUE(enabled.count("group1"));
}

TEST_F(MuxQueueStrategyTest, PrintStatusEmpty) {
  std::ostringstream os;
  strategy_.printStatus(os);
  EXPECT_NE(os.str().find("No Groups"), std::string::npos);
}

TEST_F(MuxQueueStrategyTest, PrintStatusWithGroups) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group1", "elem2", std::nullopt);

  std::ostringstream os;
  strategy_.printStatus(os);
  std::string output = os.str();
  EXPECT_NE(output.find("MuxQueueStrategy"), std::string::npos);
  EXPECT_NE(output.find("group1"), std::string::npos);
}

} // namespace
} // namespace facebook::hbt::mon
