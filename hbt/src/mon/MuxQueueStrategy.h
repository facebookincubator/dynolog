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
#include "hbt/src/perf_event/PmuDevices.h"

namespace facebook::hbt::mon {

/// Round-robin scheduling strategy for Monitor.
///
/// This is the default scheduling strategy that rotates through MuxGroups
/// in a round-robin fashion. Groups are arranged in queues (optionally
/// per-PMU-type), and rotation moves the last group to the front of the queue.
///
/// Template parameters:
/// - MuxGroupIdType: Type used to identify mux groups
/// - ElemIdType: Type used to identify individual elements
template <
    class MuxGroupIdType = std::optional<std::string>,
    class ElemIdType = std::string>
class MuxQueueStrategy : public SchedulingStrategy<MuxGroupIdType, ElemIdType> {
 public:
  using Base = SchedulingStrategy<MuxGroupIdType, ElemIdType>;
  using MuxGroupId = typename Base::MuxGroupId;
  using ElemId = typename Base::ElemId;
  using MuxGroup = typename Base::MuxGroup;

  /// Constructor. If mux_queue_per_pmu_type is true, maintain separate
  /// queues per PMU type.
  explicit MuxQueueStrategy(bool mux_queue_per_pmu_type = false)
      : mux_queue_per_pmu_type_{mux_queue_per_pmu_type} {}

  void addEntry(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::optional<perf_event::PmuType> pmu_type) override {
    auto& g = mux_groups_[mux_group_id];
    if (g.empty()) {
      // New group - add to appropriate queue
      auto queue_key = mux_queue_per_pmu_type_ ? pmu_type : std::nullopt;
      mux_queue_[queue_key].push_back(mux_group_id);
    }
    g.insert(elem_id);
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
      // Group is now empty - remove from queue
      bool removed = false;
      for (auto it = mux_queue_.begin(); it != mux_queue_.end();) {
        auto groupIdIt =
            std::find(it->second.begin(), it->second.end(), mux_group_id);
        if (groupIdIt != it->second.end()) {
          it->second.erase(groupIdIt);
          removed = true;
          // Clean up empty queue entries
          if (it->second.empty()) {
            it = mux_queue_.erase(it);
          } else {
            ++it;
          }
          break;
        }
        ++it;
      }
      HBT_THROW_ASSERT_IF(!removed)
          << "mux_group_id \"" << mux_group_id.value_or("nullopt")
          << "\" exists in mux_groups_ but not in mux_queue_";
      mux_groups_.erase(mux_group_id);
    }

    return true;
  }

  void advance() override {
    for (auto& [pmu_type, queue] : mux_queue_) {
      if (!queue.empty()) {
        std::rotate(queue.rbegin(), queue.rbegin() + 1, queue.rend());
      }
    }
  }

  std::unordered_set<MuxGroupId> getEnabledGroupIds() const override {
    std::unordered_set<MuxGroupId> ret;
    for (const auto& [pmu_type, queue] : mux_queue_) {
      if (!queue.empty()) {
        ret.insert(queue.front());
      }
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
    return mux_queue_.empty();
  }

  bool isMuxQueuePerPmuType() const override {
    return mux_queue_per_pmu_type_;
  }

  std::ostream& printStatus(std::ostream& os) const override {
    os << "MuxQueueStrategy:\n";
    if (mux_queue_.empty()) {
      os << " <No Groups>\n";
      return os;
    }
    for (const auto& [pmu_type, queue] : mux_queue_) {
      if (pmu_type.has_value()) {
        os << '[' << perf_event::PmuTypeToStr(pmu_type.value()) << ']' << '\n';
      } else {
        os << '[' << "all_pmus" << ']' << "\n";
      }
      bool first = true;
      for (const auto& g_id : queue) {
        if (first) {
          os << " *"; // Mark the front (enabled) group
          first = false;
        } else {
          os << "  ";
        }
        os << fmt::format(
            "<{}: {}>",
            g_id.has_value() ? g_id.value() : "<None>",
            fmt::join(mux_groups_.at(g_id), ", "));
        os << "\n";
      }
    }
    return os;
  }

  /// Get direct access to mux_groups_ for Monitor compatibility.
  const std::unordered_map<MuxGroupId, MuxGroup>& getMuxGroups() const {
    return mux_groups_;
  }

  /// Get direct access to mux_queue_ for Monitor compatibility.
  const std::unordered_map<
      std::optional<perf_event::PmuType>,
      std::vector<MuxGroupId>>&
  getMuxQueue() const {
    return mux_queue_;
  }

 private:
  /// Mapping from MuxGroupId to MuxGroup. Each MuxGroup contains
  /// ElemIds of the elements in it.
  std::unordered_map<MuxGroupId, MuxGroup> mux_groups_;

  /// Per-PMU-type (or all-PMU) queues of MuxGroupIds.
  /// Elements at the front of each queue are enabled.
  std::
      unordered_map<std::optional<perf_event::PmuType>, std::vector<MuxGroupId>>
          mux_queue_;

  /// Whether to maintain separate queues per PMU type.
  bool mux_queue_per_pmu_type_;
};

} // namespace facebook::hbt::mon
