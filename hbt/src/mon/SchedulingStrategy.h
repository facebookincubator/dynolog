// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <optional>
#include <set>
#include <string>
#include <unordered_set>
#include "hbt/src/perf_event/PmuDevices.h"

namespace facebook::hbt::mon {

/// Configuration for scheduling strategies.
/// Different strategies may interpret these fields differently or ignore them.
struct ScheduleConfig {
  /// For TimeSlotStrategy: number of times this group should be enabled per
  /// cycle
  uint32_t enablesPerCycle = 1;

  /// For TimeSlotStrategy: duration of a scheduling cycle in seconds
  uint32_t cycleDurationSeconds = 60;
};

/// Base interface for scheduling strategies used by Monitor.
///
/// A scheduling strategy determines which MuxGroups are enabled at any given
/// time. The default MuxQueueStrategy uses round-robin scheduling, while
/// TimeSlotStrategy provides time-based scheduling with configurable
/// frequencies per group.
///
/// Template parameters:
/// - MuxGroupIdType: Type used to identify mux groups (typically
/// std::optional<std::string>)
/// - ElemIdType: Type used to identify individual elements (typically
/// std::string)
template <
    class MuxGroupIdType = std::optional<std::string>,
    class ElemIdType = std::string>
class SchedulingStrategy {
 public:
  using MuxGroupId = MuxGroupIdType;
  using ElemId = ElemIdType;
  using MuxGroup = std::set<ElemId>;

  virtual ~SchedulingStrategy() = default;

  /// Add an entry to a mux group. If the group doesn't exist, it will be
  /// created and added to the schedule.
  virtual void addEntry(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::optional<perf_event::PmuType> pmu_type) = 0;

  /// Remove an entry from a mux group. If the group becomes empty, it will
  /// be removed from the schedule. Returns true if the entry was found and
  /// removed.
  virtual bool removeEntry(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id) = 0;

  /// Advance to the next scheduling slot.
  /// For MuxQueueStrategy, this rotates the queue.
  /// For TimeSlotStrategy, this advances to the next time slot.
  virtual void advance() = 0;

  /// Get the currently enabled mux group IDs.
  virtual std::unordered_set<MuxGroupId> getEnabledGroupIds() const = 0;

  /// Get all elements in a mux group. Throws if group not found.
  virtual const MuxGroup& getGroup(const MuxGroupId& mux_group_id) const = 0;

  /// Check if the schedule has any groups.
  virtual bool empty() const = 0;

  /// Whether this strategy maintains separate queues per PMU type.
  virtual bool isMuxQueuePerPmuType() const = 0;

  /// Configure scheduling parameters for a specific group.
  /// Not all strategies support configuration; unsupported calls are no-ops.
  /// Returns true if configuration was applied successfully.
  virtual bool configureSchedule(
      const MuxGroupId& mux_group_id,
      const ScheduleConfig& config) {
    // Default implementation: no-op for strategies that don't support config
    (void)mux_group_id;
    (void)config;
    return true;
  }

  /// Called when the Monitor's state changes (enabled/disabled).
  /// Strategies can use this to reset or rebuild their schedule.
  virtual void onStateChange(bool is_enabled) {
    // Default implementation: no-op
    (void)is_enabled;
  }

  /// Print the current schedule status for debugging.
  virtual std::ostream& printStatus(std::ostream& os) const = 0;
};

} // namespace facebook::hbt::mon
