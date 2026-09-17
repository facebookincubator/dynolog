// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/TimeSlotStrategy.h"
#include <gtest/gtest.h>
#include <sstream>

namespace facebook::hbt::mon {
namespace {

using MuxGroupId = std::optional<std::string>;
using ElemId = std::string;

class TimeSlotStrategyTest : public ::testing::Test {
 protected:
  TimeSlotStrategy<MuxGroupId, ElemId> strategy_{
      uint32_t{60}}; // 60-second cycle
};

TEST_F(TimeSlotStrategyTest, EmptyStrategyReturnsNoEnabledGroups) {
  EXPECT_TRUE(strategy_.empty());
  EXPECT_TRUE(strategy_.getEnabledGroupIds().empty());
}

TEST_F(TimeSlotStrategyTest, AddEntryCreatesGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  EXPECT_FALSE(strategy_.empty());
  const auto& group = strategy_.getGroup("group1");
  EXPECT_EQ(group.size(), 1);
  EXPECT_TRUE(group.count("elem1"));
}

TEST_F(TimeSlotStrategyTest, AddMultipleEntriesToSameGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group1", "elem2", std::nullopt);
  strategy_.addEntry("group1", "elem3", std::nullopt);

  const auto& group = strategy_.getGroup("group1");
  EXPECT_EQ(group.size(), 3);
}

TEST_F(TimeSlotStrategyTest, RemoveEntryFromGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group1", "elem2", std::nullopt);

  EXPECT_TRUE(strategy_.removeEntry("group1", "elem1"));

  const auto& group = strategy_.getGroup("group1");
  EXPECT_EQ(group.size(), 1);
  EXPECT_TRUE(group.count("elem2"));
}

TEST_F(TimeSlotStrategyTest, RemoveLastEntryRemovesGroup) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  EXPECT_TRUE(strategy_.removeEntry("group1", "elem1"));
  EXPECT_TRUE(strategy_.empty());
}

TEST_F(TimeSlotStrategyTest, RemoveNonexistentEntryReturnsFalse) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  EXPECT_FALSE(strategy_.removeEntry("group1", "nonexistent"));
  EXPECT_FALSE(strategy_.removeEntry("nonexistent_group", "elem1"));
}

TEST_F(TimeSlotStrategyTest, DefaultConfigurationTwoSamplesPerCycle) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  // Trigger schedule rebuild
  strategy_.advance();

  // Count how many slots the group is enabled in a full cycle
  size_t enabled_count = 0;
  for (size_t i = 0; i < 60; ++i) {
    auto enabled = strategy_.getEnabledGroupIds();
    if (enabled.count("group1")) {
      ++enabled_count;
    }
    strategy_.advance();
  }

  EXPECT_EQ(enabled_count, 2)
      << "Group should be enabled kDefaultEnablesPerCycle times per cycle";
}

TEST_F(TimeSlotStrategyTest, ConfigureScheduleIncreasesFrequency) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  // Configure for 12 enables per cycle (like L3 cache misses)
  ScheduleConfig config;
  config.enablesPerCycle = 12;
  config.cycleDurationSeconds = 60;
  strategy_.configureSchedule("group1", config);

  // Trigger schedule rebuild
  strategy_.advance();

  // Count how many times group1 is enabled in a full cycle
  size_t enable_count = 0;
  for (size_t i = 0; i < 60; ++i) {
    auto enabled = strategy_.getEnabledGroupIds();
    if (enabled.count("group1")) {
      enable_count++;
    }
    strategy_.advance();
  }

  EXPECT_EQ(enable_count, 12) << "Group should be enabled 12 times per cycle";
}

TEST_F(TimeSlotStrategyTest, EvenDistributionOfSlots) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  // Configure for 12 enables per cycle
  ScheduleConfig config;
  config.enablesPerCycle = 12;
  strategy_.configureSchedule("group1", config);

  // Trigger rebuild
  strategy_.rebuildSchedule();

  // Collect the slot indices where group1 is enabled
  std::vector<size_t> enabled_slots;
  for (size_t i = 0; i < 60; ++i) {
    auto enabled = strategy_.getEnabledGroupIds();
    if (enabled.count("group1")) {
      enabled_slots.push_back(i);
    }
    strategy_.advance();
  }

  ASSERT_EQ(enabled_slots.size(), 12);

  // Check that slots are evenly distributed (interval should be ~5)
  for (size_t i = 1; i < enabled_slots.size(); ++i) {
    size_t interval = enabled_slots[i] - enabled_slots[i - 1];
    // Allow some tolerance for conflict resolution
    EXPECT_GE(interval, 3) << "Slots should be reasonably spaced";
    EXPECT_LE(interval, 7) << "Slots should be reasonably spaced";
  }
}

TEST_F(TimeSlotStrategyTest, MultipleGroupsWithDifferentFrequencies) {
  strategy_.addEntry("high_freq", "elem1", std::nullopt);
  strategy_.addEntry("low_freq", "elem2", std::nullopt);

  // High frequency: 12 per cycle
  ScheduleConfig highConfig;
  highConfig.enablesPerCycle = 12;
  strategy_.configureSchedule("high_freq", highConfig);

  // Low frequency: 2 per cycle
  ScheduleConfig lowConfig;
  lowConfig.enablesPerCycle = 2;
  strategy_.configureSchedule("low_freq", lowConfig);

  // Trigger rebuild
  strategy_.rebuildSchedule();

  // Count enables for each group
  size_t high_count = 0;
  size_t low_count = 0;

  for (size_t i = 0; i < 60; ++i) {
    auto enabled = strategy_.getEnabledGroupIds();
    if (enabled.count("high_freq")) {
      high_count++;
    }
    if (enabled.count("low_freq")) {
      low_count++;
    }
    strategy_.advance();
  }

  EXPECT_EQ(high_count, 12);
  EXPECT_EQ(low_count, 2);
}

TEST_F(TimeSlotStrategyTest, OnStateChangeTriggersRebuild) {
  strategy_.addEntry("group1", "elem1", std::nullopt);

  // Configure and mark for rebuild
  ScheduleConfig config;
  config.enablesPerCycle = 5;
  strategy_.configureSchedule("group1", config);

  // State change should trigger rebuild
  strategy_.onStateChange(true);

  // Count enables
  size_t enable_count = 0;
  for (size_t i = 0; i < 60; ++i) {
    auto enabled = strategy_.getEnabledGroupIds();
    if (enabled.count("group1")) {
      enable_count++;
    }
    strategy_.advance();
  }

  EXPECT_EQ(enable_count, 5);
}

TEST_F(TimeSlotStrategyTest, AdvanceWrapsAroundCycle) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.rebuildSchedule();

  // Advance through more than one full cycle
  for (size_t i = 0; i < 100; ++i) {
    strategy_.advance();
  }

  // Should wrap around - current index should be 100 % 60 = 40
  EXPECT_EQ(strategy_.getCurrentSlotIndex(), 40);
}

TEST_F(TimeSlotStrategyTest, ConfiguredScheduleSurvivesLastElementRemoval) {
  strategy_.addEntry("cache_misses", "task1", std::nullopt);
  ScheduleConfig config;
  config.enablesPerCycle = 12;
  strategy_.configureSchedule("cache_misses", config);
  strategy_.rebuildSchedule();

  // A single-element group empties and refills whenever its one owner is
  // retired and re-tracked. The configured rate has to outlive that.
  ASSERT_TRUE(strategy_.removeEntry("cache_misses", "task1"));
  strategy_.addEntry("cache_misses", "task1", std::nullopt);
  strategy_.rebuildSchedule();

  size_t enables = 0;
  for (size_t i = 0; i < 60; ++i) {
    if (strategy_.getEnabledGroupIds().count("cache_misses")) {
      ++enables;
    }
    strategy_.advance();
  }
  EXPECT_EQ(enables, 12);
}

TEST_F(TimeSlotStrategyTest, PrintStatusReportsAllocatedSlots) {
  strategy_.addEntry("cache_misses", "elem1", std::nullopt);
  ScheduleConfig config;
  config.enablesPerCycle = 30;
  strategy_.configureSchedule("cache_misses", config);
  strategy_.rebuildSchedule();

  std::ostringstream os;
  strategy_.printStatus(os);

  EXPECT_NE(
      os.str().find("30 enables/cycle requested, 30 slots allocated"),
      std::string::npos)
      << os.str();
}

TEST_F(TimeSlotStrategyTest, StarvedGroupIsLoggedWithZeroSlots) {
  ScheduleConfig hog;
  hog.enablesPerCycle = 60; // claims the entire cycle
  strategy_.addEntry("hog", "elem1", std::nullopt);
  strategy_.configureSchedule("hog", hog);
  strategy_.rebuildSchedule();

  // A group added to a full cycle receives nothing. Complete starvation is the
  // case most worth reporting, so it has to register as a change rather than
  // being absent from the comparison.
  testing::internal::CaptureStderr();
  strategy_.addEntry("starved", "elem2", std::nullopt);
  strategy_.rebuildSchedule();
  const std::string logged = testing::internal::GetCapturedStderr();

  EXPECT_NE(
      logged.find("starved: 2 enables/cycle requested, 0 slots allocated"),
      std::string::npos)
      << logged;
}

TEST_F(TimeSlotStrategyTest, RebuildWithUnchangedAllocationIsNotLogged) {
  strategy_.addEntry("group1", "elem1", std::nullopt);
  strategy_.addEntry("group1", "elem2", std::nullopt);
  strategy_.rebuildSchedule();

  // One of two elements leaves. The group survives with the same slot count, so
  // the log, being a change journal, has nothing to report.
  testing::internal::CaptureStderr();
  strategy_.removeEntry("group1", "elem1");
  strategy_.rebuildSchedule();
  const std::string logged = testing::internal::GetCapturedStderr();

  EXPECT_EQ(logged.find("TimeSlotStrategy"), std::string::npos) << logged;
}

TEST_F(TimeSlotStrategyTest, PrintStatusClampsRequestedToCycleLength) {
  strategy_.addEntry("greedy", "elem1", std::nullopt);
  ScheduleConfig config;
  config.enablesPerCycle = 120; // more than a 60 slot cycle can hold
  strategy_.configureSchedule("greedy", config);
  strategy_.rebuildSchedule();

  std::ostringstream os;
  strategy_.printStatus(os);

  // The allocator clamps the request to the cycle length, so the reported
  // request has to be clamped too. Printing the raw 120 would make a clamp
  // indistinguishable from a genuine 60 slot shortfall.
  EXPECT_NE(
      os.str().find("60 enables/cycle requested, 60 slots allocated"),
      std::string::npos)
      << os.str();
}

TEST_F(TimeSlotStrategyTest, PrintStatusReportsShortfallWhenOversubscribed) {
  // 40 + 40 slots requested into a 60 slot cycle. One group is served in full
  // and the other is capped at the 20 left over. Which one wins is
  // unspecified -- std::sort is not stable and unordered_map iteration order is
  // undefined -- so assert only that some group reports the shortfall.
  strategy_.addEntry("group_a", "elem1", std::nullopt);
  strategy_.addEntry("group_b", "elem2", std::nullopt);
  ScheduleConfig config;
  config.enablesPerCycle = 40;
  strategy_.configureSchedule("group_a", config);
  strategy_.configureSchedule("group_b", config);
  strategy_.rebuildSchedule();

  std::ostringstream os;
  strategy_.printStatus(os);

  EXPECT_NE(
      os.str().find("40 enables/cycle requested, 20 slots allocated"),
      std::string::npos)
      << os.str();
}

} // namespace
} // namespace facebook::hbt::mon
