// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <optional>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "hbt/src/common/Defs.h"
#include "hbt/src/mon/SchedulingStrategy.h"

namespace facebook::hbt::mon {

/// A time slot in the schedule, containing which group is enabled.
template <class MuxGroupIdType>
struct TimeSlot {
  std::optional<MuxGroupIdType> groupId;
};

/// Time-slot based scheduling strategy for Monitor.
///
/// This strategy allows configuring different sampling frequencies for
/// different MuxGroups. It distributes samples evenly across a scheduling
/// cycle (default 60 seconds).
///
/// Use case: Fine-grained memory bandwidth estimation requires L3 cache miss
/// counters at higher frequency (12-30 samples/min) than other counters
/// (1-2 samples/min).
///
/// Template parameters:
/// - MuxGroupIdType: Type used to identify mux groups
/// - ElemIdType: Type used to identify individual elements
template <
    class MuxGroupIdType = std::optional<std::string>,
    class ElemIdType = std::string>
class TimeSlotStrategy : public SchedulingStrategy<MuxGroupIdType, ElemIdType> {
 public:
  using Base = SchedulingStrategy<MuxGroupIdType, ElemIdType>;
  using MuxGroupId = typename Base::MuxGroupId;
  using ElemId = typename Base::ElemId;
  using MuxGroup = typename Base::MuxGroup;

  /// Constructor. cycle_duration_seconds is the duration of a scheduling
  /// cycle in seconds.
  explicit TimeSlotStrategy(uint32_t cycle_duration_seconds = 60)
      : cycle_duration_seconds_{cycle_duration_seconds} {}

  /// Constructor for Monitor compatibility (ignores bool, uses default cycle).
  /// This matches the MuxQueueStrategy constructor signature that Monitor uses.
  /// NOLINTNEXTLINE(google-explicit-constructor)
  explicit TimeSlotStrategy(bool /* mux_queue_per_pmu_type */)
      : cycle_duration_seconds_{60} {}

  void addEntry(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::optional<perf_event::PmuType> /* pmu_type */) override {
    auto& g = mux_groups_[mux_group_id];
    bool was_empty = g.empty();
    g.insert(elem_id);

    if (was_empty) {
      // New group - add with default configuration (1 enable per cycle)
      if (!schedule_configs_.count(mux_group_id)) {
        schedule_configs_[mux_group_id] =
            ScheduleConfig{1, cycle_duration_seconds_};
      }
      needs_rebuild_ = true;
    }
  }

  bool removeEntry(const MuxGroupId& mux_group_id, const ElemId& elem_id)
      override {
    auto group_it = mux_groups_.find(mux_group_id);
    if (group_it == mux_groups_.end()) {
      return false;
    }

    auto& g = group_it->second;
    if (g.find(elem_id) == g.end()) {
      return false;
    }

    g.erase(elem_id);

    if (g.empty()) {
      mux_groups_.erase(mux_group_id);
      schedule_configs_.erase(mux_group_id);
      needs_rebuild_ = true;
    }

    return true;
  }

  void advance() override {
    if (needs_rebuild_) {
      rebuildSchedule_();
    }

    if (schedule_.empty()) {
      return;
    }

    current_slot_index_ = (current_slot_index_ + 1) % schedule_.size();
  }

  std::unordered_set<MuxGroupId> getEnabledGroupIds() const override {
    std::unordered_set<MuxGroupId> ret;

    if (schedule_.empty() || current_slot_index_ >= schedule_.size()) {
      return ret;
    }

    const auto& slot = schedule_[current_slot_index_];
    if (slot.groupId.has_value() &&
        mux_groups_.count(slot.groupId.value()) > 0) {
      ret.insert(slot.groupId.value());
    }

    return ret;
  }

  const MuxGroup& getGroup(const MuxGroupId& mux_group_id) const override {
    auto it = mux_groups_.find(mux_group_id);
    HBT_THROW_ASSERT_IF(it == mux_groups_.end())
        << "mux_group_id \"" << mux_group_id.value_or("nullopt")
        << "\" not found in mux_groups_";
    return it->second;
  }

  bool empty() const override {
    return mux_groups_.empty();
  }

  bool isMuxQueuePerPmuType() const override {
    // TimeSlotStrategy does not use per-PMU-type queues
    return false;
  }

  bool configureSchedule(
      const MuxGroupId& mux_group_id,
      const ScheduleConfig& config) override {
    schedule_configs_[mux_group_id] = config;
    needs_rebuild_ = true;
    return true;
  }

  void onStateChange(bool is_enabled) override {
    if (is_enabled && needs_rebuild_) {
      rebuildSchedule_();
    }
  }

  std::ostream& printStatus(std::ostream& os) const override {
    os << "TimeSlotStrategy:\n";
    os << "  Cycle duration: " << cycle_duration_seconds_ << " seconds\n";
    os << "  Current slot: " << current_slot_index_ << "/" << schedule_.size()
       << "\n";

    if (mux_groups_.empty()) {
      os << "  <No Groups>\n";
      return os;
    }

    os << "  Groups:\n";
    for (const auto& [group_id, group] : mux_groups_) {
      auto config_it = schedule_configs_.find(group_id);
      uint32_t enables = config_it != schedule_configs_.end()
          ? config_it->second.enablesPerCycle
          : 1;
      os << "    - " << (group_id.has_value() ? group_id.value() : "<None>")
         << ": " << enables << " enables/cycle, " << group.size()
         << " elements\n";
    }

    // Show current schedule slots (abbreviated)
    os << "  Schedule (first 20 slots):\n";
    for (size_t i = 0; i < std::min(schedule_.size(), size_t(20)); ++i) {
      const auto& slot = schedule_[i];
      os << "    [" << i << "] ";
      if (slot.groupId.has_value()) {
        os
            << (slot.groupId.value().has_value() ? slot.groupId.value().value()
                                                 : "<None>");
      } else {
        os << "-";
      }
      if (i == current_slot_index_) {
        os << " <-- current";
      }
      os << "\n";
    }
    if (schedule_.size() > 20) {
      os << "    ... (" << (schedule_.size() - 20) << " more slots)\n";
    }

    return os;
  }

  /// Force a schedule rebuild (useful for testing)
  void rebuildSchedule() {
    rebuildSchedule_();
  }

  /// Get current slot index (useful for testing/debugging)
  size_t getCurrentSlotIndex() const {
    return current_slot_index_;
  }

 private:
  void rebuildSchedule_() {
    needs_rebuild_ = false;
    schedule_.clear();
    current_slot_index_ = 0;

    if (cycle_duration_seconds_ == 0 || mux_groups_.empty()) {
      return;
    }

    // Create empty schedule
    schedule_.resize(cycle_duration_seconds_);

    // Collect requirements: (group_id, slots_needed)
    std::vector<std::pair<MuxGroupId, uint32_t>> requirements;
    for (const auto& [group_id, _] : mux_groups_) {
      auto config_it = schedule_configs_.find(group_id);
      uint32_t slots_needed = 1; // default
      if (config_it != schedule_configs_.end()) {
        slots_needed = std::min(
            config_it->second.enablesPerCycle, cycle_duration_seconds_);
      }
      if (slots_needed > 0) {
        requirements.emplace_back(group_id, slots_needed);
      }
    }

    // Sort by slots needed (descending) - assign groups with more slots first
    std::sort(
        requirements.begin(),
        requirements.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });

    // Track which slots are used
    std::vector<bool> slots_used(cycle_duration_seconds_, false);

    // Assign slots to each group
    for (const auto& [group_id, slots_needed] : requirements) {
      auto available_slots = findAvailableSlots_(
          slots_used, slots_needed, cycle_duration_seconds_);

      for (size_t slot_index : available_slots) {
        if (slot_index < schedule_.size()) {
          schedule_[slot_index].groupId = group_id;
          slots_used[slot_index] = true;
        }
      }
    }
  }

  /// Find available slots for a group, distributing them evenly
  std::vector<size_t> findAvailableSlots_(
      const std::vector<bool>& slots_used,
      uint32_t slots_needed,
      uint32_t total_slots) {
    std::vector<size_t> result;

    if (slots_needed == 0) {
      return result;
    }

    // First, try ideal even distribution
    double ideal_interval = static_cast<double>(total_slots) / slots_needed;
    std::vector<size_t> ideal_slots;

    for (uint32_t i = 0; i < slots_needed; ++i) {
      size_t slot_index =
          static_cast<size_t>(static_cast<double>(i) * ideal_interval);
      if (slot_index < total_slots) {
        ideal_slots.push_back(slot_index);
      }
    }

    // Check if ideal distribution is conflict-free
    bool ideal_feasible = true;
    for (size_t slot : ideal_slots) {
      if (slots_used[slot]) {
        ideal_feasible = false;
        break;
      }
    }

    if (ideal_feasible) {
      return ideal_slots;
    }

    // Find alternative slots if ideal has conflicts
    result.reserve(slots_needed);

    // Get all available slots
    std::vector<size_t> available_slots;
    for (size_t i = 0; i < total_slots; ++i) {
      if (!slots_used[i]) {
        available_slots.push_back(i);
      }
    }

    size_t actual_slots =
        std::min(static_cast<size_t>(slots_needed), available_slots.size());

    if (actual_slots == available_slots.size()) {
      result = available_slots;
    } else {
      // Distribute evenly among available slots
      double step = static_cast<double>(available_slots.size()) /
          static_cast<double>(actual_slots);
      for (size_t i = 0; i < actual_slots; ++i) {
        size_t index = static_cast<size_t>(static_cast<double>(i) * step);
        if (index < available_slots.size()) {
          result.push_back(available_slots[index]);
        }
      }
    }

    return result;
  }

  /// Mapping from MuxGroupId to MuxGroup
  std::unordered_map<MuxGroupId, MuxGroup> mux_groups_;

  /// Schedule configuration per group
  std::unordered_map<MuxGroupId, ScheduleConfig> schedule_configs_;

  /// The built schedule - one slot per second in the cycle
  std::vector<TimeSlot<MuxGroupId>> schedule_;

  /// Current position in the schedule
  size_t current_slot_index_ = 0;

  /// Duration of scheduling cycle in seconds
  uint32_t cycle_duration_seconds_;

  /// Whether schedule needs rebuilding
  bool needs_rebuild_ = false;
};

} // namespace facebook::hbt::mon
