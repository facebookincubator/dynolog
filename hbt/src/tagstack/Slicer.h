// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/tagstack/Event.h"
#include "hbt/src/tagstack/Stream.h"
#include "hbt/src/tagstack/TagStack.h"

#include <boost/intrusive/list.hpp>

#include <deque>
#include <sstream>
#include <unordered_map>

namespace facebook::hbt::tagstack::slice {

// A unique identifier to each stack id.
// Due to package lost and state restart of the Slicer,
// it may not be dense.
using TagStackId = uint64_t;
constexpr TagStackId kInvalidTagStackId =
    std::numeric_limits<TagStackId>::max();

///
/// Slice of execution time for a TagStack.
///
struct Slice {
  enum class TransitionType : uint8_t {
    // Invalid TransitionType, used to detect errors.
    NA = 0,
    // Means that original Slice was split for analysis purposes.
    // i.e. The transition did not happen in the actual execution.
    Analysis,
    // The slice was created because thread was preempted by OS.
    ThreadPreempted,
    // The slice was created because OS thread yielded.
    ThreadYield,
    // The slice was created because a non-thread tag changed.
    PhaseChange
  };

  TimeStamp tstamp;
  TimeStamp duration;
  TagStackId stack_id;
  TransitionType swin_type;
  TransitionType swout_type;

  static Slice makeSlice(
      TimeStamp tstamp,
      TimeStamp duration,
      TagStackId stack_id,
      TransitionType swin_type,
      TransitionType swout_type) {
    return Slice{
        .tstamp = tstamp,
        .duration = duration,
        .stack_id = stack_id,
        .swin_type = swin_type,
        .swout_type = swout_type};
  }

  bool operator==(const Slice& other) const {
    return tstamp == other.tstamp && duration == other.duration &&
        stack_id == other.stack_id && swin_type == other.swin_type &&
        swout_type == other.swout_type;
  }

  inline TimeStamp tstampEnd() const noexcept {
    return tstamp + duration;
  }

  inline bool hasSwinThread() const noexcept {
    return swin_type == TransitionType::ThreadPreempted ||
        swin_type == TransitionType::ThreadYield;
  }

  inline bool hasSwoutThread() const noexcept {
    return swout_type == TransitionType::ThreadPreempted ||
        swout_type == TransitionType::ThreadYield;
  }
};

// Check layouot assumptions used during serialization.
static_assert(std::is_trivial_v<Slice>);
static_assert(std::is_standard_layout_v<Slice>);

inline std::string toStr(const Slice::TransitionType& type) {
  switch (type) {
    case Slice::TransitionType::NA:
      return "NA";
      break;
    case Slice::TransitionType::Analysis:
      return "Analysis";
      break;
    case Slice::TransitionType::ThreadPreempted:
      return "ThreadPreempted";
      break;
    case Slice::TransitionType::ThreadYield:
      return "ThreadYield";
      break;
    case Slice::TransitionType::PhaseChange:
      return "PhaseChange";
      break;
  }
}

inline std::ostream& operator<<(
    std::ostream& os,
    const Slice::TransitionType& type) {
  return os << toStr(type);
}

inline std::ostream& operator<<(std::ostream& os, const Slice& s) {
  os << "<Slice tstamp: " << tstampToStr(s.tstamp) << " stack_id:" << s.stack_id
     << " duration: " << tstampToStr(s.duration)
     << " swin_type: " << s.swin_type << " swout_type: " << s.swout_type << ">";
  return os;
}

using Slices = std::vector<Slice>;

inline std::optional<size_t> findSliceAt(
    const Slices& slices,
    TimeStamp tstamp) {
  for (auto s = slices.cbegin(); s < slices.cend(); ++s) {
    if (s->tstamp < tstamp || s->tstampEnd() >= tstamp) {
      continue;
    }
    return s - slices.cbegin();
  }
  return std::nullopt;
}

/// A handy container of slices, support efficient interval queries.
/// Follows RingBuffer Producer API.
/// Fully implement it?, currently only used in testing.
class SlicesMap : public std::map<TimeStamp, Slice> {
 public:
  ssize_t write(const Slice& slice) {
    HBT_ARG_CHECK_NE(slice.tstamp, kInvalidTimeStamp) << "Invalid timestamp";
    auto [it, inserted] = this->insert(std::make_pair(slice.tstamp, slice));
    HBT_THROW_ASSERT_IF(!inserted)
        << "Slice with tstamp: " << tstampToStr(slice.tstamp)
        << " already existed.";
    return 0;
  }
};

inline std::ostream& operator<<(std::ostream& os, const SlicesMap& slices) {
  os << slices.size() << " slices: " << std::endl;
  for (const auto& [tstamp, slice] : slices) {
    os << tstamp << ", " << slice << std::endl;
  }
  os << std::endl;
  return os;
}

/// Information and state of a TagStack in the TagStack Event history.
/// This class contains the subset of the information in TagStackState
/// that is useful for snapshots of monitoring data. The split allows
/// to keep Slicer runtime state separated.
struct TagStackStats {
  const TagStackId stack_id;
  // Stack ID of the stack that contains one level less than this one.
  // kInvalidTagStackId if none.
  // XXX: Explore how useful is this for optimizing look ups of substacks.
  const TagStackId parent_stack_id;
  const Stack stack;

  // Add more stats as needed but keep them separated from control logic.
  TimeStamp cum_active_time = 0;
  size_t num_swins = 0;
  size_t num_swouts = 0;

  TagStackStats(
      TagStackId stack_id,
      TagStackId parent_stack_id,
      const Stack& stack)
      : stack_id{stack_id}, parent_stack_id{parent_stack_id}, stack{stack} {}

  // Constructor used by serialization.
  TagStackStats(
      TagStackId stack_id,
      TagStackId parent_stack_id,
      const Stack& stack,
      TimeStamp cum_active_time,
      size_t num_swins,
      size_t num_swouts)
      : stack_id{stack_id},
        parent_stack_id{parent_stack_id},
        stack{stack},
        cum_active_time{cum_active_time},
        num_swins{num_swins},
        num_swouts{num_swouts} {}
};

using TagStackStatsDump = std::map<TagStackId, TagStackStats>;

// The state of a TagStackState at some point in the stream of events.
//
// A TagStackState is either active in one stream (i.e. the TagStack is
// executing in a compute unit) or it is inactive.
//
// Inactive states can become active in any stream (threads migrate).
//
// Tags in a TagStack may be active in different streams at the same time.
// When this happens, the algorithm will create multiple StackStaces with
// identical TagStack. Note that the number of StackStates created with
// identital TagStack is data dependent. Users will want to aggregate
// all instances to obtain statistics.
using boost_intrusive_list_autounlink_hook = ::boost::intrusive::list_base_hook<
    ::boost::intrusive::link_mode<::boost::intrusive::auto_unlink>>;

/// State of TagStack in the Slicer.
struct TagStackState : public boost_intrusive_list_autounlink_hook {
  TagStackStats stats;

  struct SwitchIn {
    TimeStamp tstamp = kInvalidTimeStamp;
    Slice::TransitionType type = Slice::TransitionType::NA;
  };

  // Last Switch In, one per Group.
  std::vector<SwitchIn> last_swin;

  explicit TagStackState(
      TagStackId stack_id,
      TagStackId parent_stack_id,
      const Stack& s,
      size_t num_streams)
      : stats{stack_id, parent_stack_id, s}, last_swin{num_streams} {}

  void markSwitchIn(
      unsigned group_idx,
      TimeStamp tstamp,
      Slice::TransitionType swin_type) {
    HBT_ARG_CHECK_EQ(last_swin.at(group_idx).tstamp, kInvalidTimeStamp);

    auto& swin = last_swin[group_idx];
    swin.tstamp = tstamp;
    swin.type = swin_type;
    ++stats.num_swins;
  }

  void markSwitchOut(unsigned group_idx, TimeStamp tstamp) {
    HBT_ARG_CHECK_GE(tstamp, last_swin.at(group_idx).tstamp);
    auto& swin = last_swin[group_idx];
    stats.cum_active_time += tstamp - swin.tstamp;
    ++stats.num_swouts;

    // Restart
    swin.tstamp = kInvalidTimeStamp;
    swin.type = Slice::TransitionType::NA;
  }

  // Do not restart stats.
  void restart() {
    for (auto& swin : last_swin) {
      swin.tstamp = kInvalidTimeStamp;
      swin.type = Slice::TransitionType::NA;
    }
  }
};

inline std::ostream& operator<<(std::ostream& os, const TagStackStats& ss) {
  return os << "<TagStackStats"
            << " stack_id: " << ss.stack_id
            << " parent_stack_id: " << ss.parent_stack_id
            << " stack: " << ss.stack
            << " cum_active_time: " << ss.cum_active_time
            << " num_swins: " << ss.num_swins
            << " num_swouts: " << ss.num_swouts << ">";
}

/// A container for sets of slices. Underlying type must support operator[]
template <class TSlices>
using GroupedSlices = std::vector<std::shared_ptr<TSlices>>;

struct SlicerStats {
  unsigned long num_processed = 0;
  unsigned long num_error_start = 0;
  unsigned long num_error_end = 0;
  unsigned long num_error_out_sync = 0;
  unsigned long num_dropped = 0;
  unsigned long num_out_of_order = 0;
  unsigned long num_slices_completed = 0;
  unsigned long num_logic_errors = 0;
};

/// Takes mulitple streams of events (wrapped) and outputs slices of TagStacks.
/// and metadata.
///
/// It does not support nesting of TagStacks, so, no two or more
/// SwitchIn at the same level are allowed without a SwitchOut at
/// the same level in between.

// XXX: <kHandleTID0> is a hack to handle Linux 0 PID that is not really a
// process.

// TSC counters of different packages (sockets) may be a bit out-of-sync. This
// would cause failures in multi-socket systems if the time to move a thread is
// less than the drift/offset difference. If we run into this errors we need to
// implement code robust to this by handling the scenario where a thread that is
// recorded to be in a CPU appears in a sched-in in another cpu.
template <class TEventsStream, class TSlices, bool kHandleTID0 = true>
class Slicer {
 public:
  // List of stack states indexed by bottom tag.
  // Each list is sorted with most recent access first so that the last stack
  // is found when a tag that is contained by the stack comes in.
  using TDormantStates = std::map<
      Tag,
      ::boost::intrusive::
          list<TagStackState, ::boost::intrusive::constant_time_size<false>>>;
  // Mapping from Stack to TagStackState.
  using TStackStates = std::unordered_map<Stack, TagStackState>;

  using TGroupIdx = CompUnitId;
  using TGroupedSlices = GroupedSlices<TSlices>;

  // This class has a constant write size.
  static constexpr size_t kWriteByteSize = sizeof(Slice);

  /// Multi-stream constructor. <grouped_slices> must have been populated.
  Slicer(
      std::shared_ptr<TEventsStream> events,
      std::shared_ptr<TGroupedSlices> grouped_slices)
      : events_{events},
        grouped_slices_{grouped_slices},
        active_states_{grouped_slices->size()} {
    HBT_ARG_CHECK_GT(grouped_slices->size(), 0);
  }

  ~Slicer() {
    resetState_();
  }

  /// Returns number of processed events. Process until stop_ts (inclusive).
  unsigned processNext(unsigned max_num_events, TimeStamp stop_ts) {
    unsigned num_processed = 0;

    // DLOG(INFO) << "Slicer::processNext max_num_events: " << max_num_events
    //           << " stop_ts: " << stop_ts
    while (num_processed < max_num_events) {
      const Event* ev = events_->prepareNext(stop_ts);
      if (unlikely(ev == nullptr)) {
        return num_processed;
      }
      HBT_DCHECK_NE(ev->tstamp, kInvalidTimeStamp);

      // Group by Computation Unit.
      TGroupIdx group_idx = ev->comp_unit_id;

      HBT_THROW_ASSERT_IF(group_idx >= active_states_.size());
      HBT_THROW_ASSERT_IF(group_idx >= grouped_slices_->size());
      HBT_DCHECK(grouped_slices_->at(group_idx) != nullptr)
          << "No valid slice producer for group_idx: " << group_idx;

      // DLOG(INFO) << "Slicer sees next event: "
      //           << *ev << " in stream idx: " << group_idx;
      if (unlikely(ev->tstamp < last_ts_)) {
        // XXX: This case will happen (very rarely) in production.
        // Double check that handling it this way is robust enough.
        HBT_LOG_ERROR()
            << "An event arrived with timestamp prior to latest timestamp. "
            << "Is there an issue with delayed PhaseLoggers? or pipeline's max delay?"
            << "Event : " << *ev << " last_ts_: " << tstampToStr(last_ts_);
        // Reset and start over.
        ++stats_.num_out_of_order;
        resetState_();
        last_ts_ = ev->tstamp;
        continue;
      }

      // Has it reached the stop timestamp?
      if (unlikely(ev->tstamp > stop_ts)) {
        return num_processed;
      }

      // WriteErrors?
      if (unlikely(handleWriteErrors_(ev))) {
        ++num_processed;
        continue;
      }

      // At this point we are only dealing with switch in/out events.
      HBT_THROW_ASSERT_IF(
          !(ev->isThreadLifetime() || ev->isSwitch() || ev->isPhase()));

      if (handleThreadLifetime_(ev)) {
        ++num_processed;
        continue;
      }

      //
      // From this point on, event can only be transition.
      //

      Slice::TransitionType sw_type = eventToTransitionType_(ev);
      ;
      // HBT_LOG_INFO() << "sw_type: " << sw_type;

      auto* last_state = active_states_[group_idx];
      if (handleLastState_(ev, last_state, sw_type, group_idx)) {
        ++num_processed;
        continue;
      }

      auto get_last_stack = [&]() {
        if (last_state) {
          return last_state->stats.stack;
        } else {
          Level num_levels = ev->level + (ev->isOut() ? 1u : 0u);
          return Stack{num_levels, ev->isPhase()};
        }
      };

      Stack last_stack = get_last_stack();

      if (ev->isOut()) {
        if (unlikely(
                handleEventOutPreConditionError_(ev, group_idx, last_stack))) {
          ++num_processed;
          continue;
        }
        activateStackStateExactMatch_(
            group_idx,
            // Switching out means there is nothing on top, so that fixes
            // the number of levels.
            last_stack.copyTruncated(ev->level, true),
            ev->tstamp,
            sw_type);
      } else {
        // Event In.

        if (unlikely(handleEventInPreConditionError_(ev, last_stack))) {
          ++num_processed;
          continue;
        }

        HBT_DCHECK_LT(ev->level, Stack::kMaxNumLevels);
        // Phases cannot have anything on top, so they fix the number of levels.
        bool known_num_levels = last_stack.known_num_levels | ev->isPhase();
        Stack bottom_stack =
            last_stack.copyFillUpTo(ev->level, ev->tag, known_num_levels);

        if (isAliased(bottom_stack) || ev->isPhase()) {
          activateStackStateExactMatch_(
              group_idx, bottom_stack, ev->tstamp, sw_type);
        } else {
          activateStackStateThatContains_(
              group_idx, bottom_stack, ev->level + 1, ev->tstamp, sw_type);
        }
      }

      last_ts_ = ev->tstamp;
      ++num_processed;
      ++stats_.num_processed;
      events_->complete();
    }
    // DLOG(INFO) << "processNext finished num_processed: " << num_processed;
    return num_processed;
  }

  auto getInputStream() {
    return events_;
  }

  auto getSlices() {
    return grouped_slices_;
  }

  const auto& getTagStackStates() const {
    return states_;
  }

  TimeStamp getLastTimeStamp() const {
    return last_ts_;
  }

  /// TagStackStats for each TagStackId.
  std::unique_ptr<TagStackStatsDump> getTagStackStatsDump() const {
    auto stats = std::make_unique<TagStackStatsDump>();

    for (const auto& [key, ss] : states_) {
      stats->emplace(ss.stats.stack_id, ss.stats);
    }
    return stats;
  };

  auto getStats() const {
    return stats_;
  }

 protected:
  std::shared_ptr<TEventsStream> events_;
  std::shared_ptr<TGroupedSlices> grouped_slices_;
  TimeStamp last_ts_ = std::numeric_limits<TimeStamp>::min();

  // All states are in <states_> (the owner).
  // A reference to each state it's kept in either active or inactive.

  // TagStackStates that were active and have not ended.
  std::vector<TagStackState*> active_states_;
  // Inactive states in Most Recently Used order.
  TDormantStates dormant_states_;
  // Owner of all states. Includes the ones in <active_states_>,
  // <dormant_states_> and those that ended. Indexed by stack for fast
  // retrieval.
  TStackStates states_; // Owner of all states.
  // <next_stack_id_> must never restart, or stacks between errors
  // will be confused.
  TagStackId next_stack_id_ = 0;

  unsigned num_active_write_errors_ = 0;

  SlicerStats stats_;

  void activateStackState_(
      TGroupIdx group_idx,
      TagStackState& ss,
      TimeStamp ts,
      Slice::TransitionType swin_type) {
    // HBT_LOG_INFO() << "activateStackState_ idx: " << group_idx << " stack: "
    // <<
    ss.stats.stack;
    HBT_ARG_CHECK(active_states_[group_idx] == nullptr);
    active_states_[group_idx] = &ss;
    ss.markSwitchIn(group_idx, ts, swin_type);
  }

  // Switch out front of active states and generate a slice if duration > 0.
  void completeSlice_(
      TGroupIdx group_idx,
      TimeStamp ts,
      Slice::TransitionType swout_type) {
    HBT_ARG_CHECK_NE(ts, kInvalidTimeStamp);
    HBT_ARG_CHECK(!states_.empty());
    HBT_ARG_CHECK(active_states_[group_idx] != nullptr)
        << "Trying to complete an inexistent slices at timestamp: " << ts
        << " group_idx: " << group_idx << "swout_type: " << swout_type;

    TagStackState& ss = *active_states_[group_idx];
    const auto& last_swin = ss.last_swin.at(group_idx);
    TimeStamp last_swin_tstamp = last_swin.tstamp;
    HBT_ARG_CHECK_NE(last_swin_tstamp, kInvalidTimeStamp);
    HBT_ARG_CHECK_GE(ts, last_swin_tstamp);
    TimeStamp dur = ts - last_swin_tstamp;
    // Discard slices with 0 duration as they provide no information about what
    // actually ran. They are artifacs of the way Events are encoded.
    if (dur > 0) {
      Slice s{
          last_swin_tstamp, dur, ss.stats.stack_id, last_swin.type, swout_type};
      ssize_t ret = (*grouped_slices_)[group_idx]->write(s);
      HBT_THROW_SYSTEM_CODE_IF(0 > ret, toErrorCode(-ret))
          << "Buffer back-pressure when generating slices is not yet supported. "
          << "The implementer must rollback the uncommited slice.";
    }

    ss.markSwitchOut(group_idx, ts);
    ++stats_.num_slices_completed;
  }

  TagStackState& createStackState_(const Stack& s) {
    Level n = s.num_set_tags;
    TagStackId parent_sid = kInvalidTagStackId;

    // Recursively create parent stacks that do not exist yet.
    if (n > 0) {
      auto parent_stack = s.copyTruncated(n - 1, s.known_num_levels);
      if (auto s_iter = states_.find(parent_stack); s_iter != states_.end()) {
        parent_sid = s_iter->second.stats.stack_id;
      } else {
        parent_sid = createStackState_(parent_stack).stats.stack_id;
      }
    }
    auto [it, inserted] = states_.emplace(
        s,
        TagStackState{
            next_stack_id_++, parent_sid, s, grouped_slices_->size()});
    HBT_DCHECK(inserted)
        << "A TagStackState with Stack " << s << " already exists. "
        << " Unaliased TagStacks (non-empty and with no NAs) must be unique."
        << " Has an active phase changed threads? (that's currently unsupported)."
        << " Non-aliased tag stacks can only be active in one CPU at a time.";

    return it->second;
  }

  inline void activateStackStateExactMatch_(
      TGroupIdx group_idx,
      const Stack& new_stack,
      TimeStamp tstamp,
      Slice::TransitionType swin_type) {
    if (auto s_iter = states_.find(new_stack); s_iter == states_.end()) {
      // This stack has never been seen before, create it and activate it.
      activateStackState_(
          group_idx, createStackState_(new_stack), tstamp, swin_type);
    } else {
      // This stack has been seen before, activate it.
      HBT_DCHECK_EQ(s_iter->first, s_iter->second.stats.stack);
      HBT_DCHECK_EQ(s_iter->second.stats.stack, new_stack);
      // XXX: This is not true due to resets. Verify.
      // CHECK_EQ(isAliased(new_stack), !s_iter->second.is_linked())
      //     << "Non-active TagStackState must be in dormant_states_ unless it
      //     has NAs. Found violation with stack: " <<
      //     s_iter->second.stats.stack;
      if (s_iter->second.is_linked()) {
        s_iter->second.unlink();
      }
      activateStackState_(group_idx, s_iter->second, tstamp, swin_type);
    }
  }

  inline void activateStackStateThatContains_(
      TGroupIdx group_idx,
      const Stack& stack,
      Level num_levels,
      TimeStamp tstamp,
      Slice::TransitionType swin_type) {
    HBT_ARG_CHECK(!isAliased(stack));
    HBT_ARG_CHECK_GT(stack.num_set_tags, 0);
    for (auto& ss : dormant_states_[stack.tags[0]]) {
      // HBT_LOG_INFO() << "dormant_state : " << ss.stats.stack;
      if (ss.stats.stack.contains(stack, num_levels)) {
        ss.unlink();
        activateStackState_(group_idx, ss, tstamp, swin_type);
        return;
      }
    }

    // This code path comes from SwitchIn only. Not having found the stack in
    // <dormant_states_> implies that we cannot be certain on the number of
    // levels. The state may have been removed from <dormant_states_> in a
    // reset.
    Stack new_stack{stack.tags, stack.num_set_tags, false};
    activateStackStateExactMatch_(group_idx, new_stack, tstamp, swin_type);
  }

  void resetState_() {
    // Reference because we'll modify the pointer.
    for (auto& s : active_states_) {
      if (s == nullptr) {
        continue;
      }
      HBT_DCHECK(!s->is_linked());
      s = nullptr;
    }

    // dormant_states_'s order is state, needs to be erased.
    dormant_states_.clear();

    for (auto& [k, s] : states_) {
      s.restart();
    }
  }

  // Return true if s can appear in mulitple groups at the same time.
  bool isAliased(const Stack& s) const {
    // The stack with virtual TID 0.
    bool isTid0 = s.num_set_tags == 1 && s.tags[0] == 0;
    // An empty TagStack (no tags).
    bool isEmptyCallStack = s.num_set_tags == 0;
    if constexpr (kHandleTID0) {
      return isTid0 || isEmptyCallStack || s.hasNAs();
    } else {
      return isEmptyCallStack || s.hasNAs();
    }
  }

  /// Return true if an error was handled
  inline bool handleWriteErrors_(const Event* ev) {
    // WriteErrors?
    if (unlikely(ev->type == Event::Type::WriteErrorsEnd)) {
      HBT_LOG_WARNING() << "Slicer has found WriteErrorsEnd " << *ev;
      last_ts_ = ev->tstamp;
      ++stats_.num_processed;
      ++stats_.num_error_end;
      events_->complete();
      --num_active_write_errors_;
      return true;
    }

    if (unlikely(ev->type == Event::Type::WriteErrorsStart)) {
      HBT_LOG_WARNING() << "Slicer has found WriteErrorsStart " << *ev;
      last_ts_ = ev->tstamp;
      ++stats_.num_processed;
      ++stats_.num_error_start;
      events_->complete();
      resetState_();
      ++num_active_write_errors_;
      return true;
    }

    if (unlikely(num_active_write_errors_)) {
      // HBT_LOG_WARNING() << "Slicer received event: " << *ev << " while in
      // write error";
      // Cannot process events while in error because we don't know
      // what happened prior to them.
      last_ts_ = ev->tstamp;
      ++stats_.num_processed;
      ++stats_.num_dropped;
      events_->complete();
      return true;
    }
    return false;
  }

  inline bool handleThreadLifetime_(const Event* ev) {
    if (ev->isThreadLifetime()) {
      HBT_DCHECK(
          ev->type == Event::Type::ThreadCreation ||
          ev->type == Event::Type::ThreadDestruction);

      if (unlikely(ev->level != 0)) {
        HBT_LOG_ERROR() << "Thread event level was " << ev->level
                        << "but was expected to be zero";
        last_ts_ = ev->tstamp;
        ++stats_.num_processed;
        ++stats_.num_dropped;
        ++stats_.num_logic_errors;
        events_->complete();
        return true;
      }

      if (ev->type == Event::Type::ThreadCreation) {
        // It's a new thread so we are certain that no
        // phase is running on top of it.
        Stack s({ev->tag}, 1, true);

        HBT_DCHECK_GT(s.num_set_tags, 0);
        HBT_DCHECK(states_.find(s) == states_.end());

        auto& new_state = createStackState_(s);
        dormant_states_[s.tags[0]].push_front(new_state);
      } else {
        // Here we have a ThreadLifetime Event that is not creation.
        // XXX: Handle this case. Here threads are being destroyed and ideally
        // we would disable them. This will allow better error detection. It's
        // a bit tricky because perf_event may log the Exit event while the
        // thread is still scheduled.
      }
      last_ts_ = ev->tstamp;
      ++stats_.num_processed;
      events_->complete();
      return true;
    }
    return false;
  }

  inline bool handleLastState_(
      const Event* ev,
      TagStackState* last_state,
      Slice::TransitionType sw_type,
      TGroupIdx group_idx) {
    if (last_state == nullptr) {
      return false;
    }

    // There was an active_state in this group_idx. Make it dormant.

    // HBT_LOG_INFO() << "Last state about to become inactive. stack: " <<
    //    last_state->stats.stack << " isAliased: " <<
    //    isAliased(last_state->stats.stack);
    if (!isAliased(last_state->stats.stack)) {
      HBT_DCHECK(!last_state->is_linked())
          << "Unaliased TagStackState to deactivate cannot be already "
          << "in dormant list. Stack: " << last_state->stats.stack;
      const auto& tags = last_state->stats.stack.tags;
      HBT_DCHECK_GT(last_state->stats.stack.num_set_tags, 0);
      dormant_states_[tags[0]].push_front(*last_state);
      HBT_DCHECK(last_state->is_linked());
      if (unlikely(!last_state->is_linked())) {
        HBT_LOG_ERROR()
            << "Inconsistent state: "
            << "Last state was expected to be in list of active states";
        last_ts_ = ev->tstamp;
        ++stats_.num_processed;
        ++stats_.num_dropped;
        ++stats_.num_logic_errors;
        events_->complete();
        return true;
      }
      // HBT_LOG_INFO() << "Deactivated " << last_state->stats.stack;
    }

    // Record that the previous slice is terminating.
    completeSlice_(group_idx, ev->tstamp, sw_type);
    active_states_[group_idx] = nullptr;
    return false;
  }

  inline auto eventToTransitionType_(const Event* ev) const {
    Slice::TransitionType sw_type;
    switch (ev->type) {
      case Event::Type::Start:
      case Event::Type::End:
        return Slice::TransitionType::PhaseChange;
      case Event::Type::SwitchIn: // kernel's scheduler starting a thread is a
                                  // yield.
      case Event::Type::SwitchOutYield:
        return Slice::TransitionType::ThreadYield;
      case Event::Type::SwitchOutPreempt:
        return Slice::TransitionType::ThreadPreempted;
      default:
        HBT_THROW_ASSERT() << "event type: " << ev->type
                           << " should've not be here";
        __builtin_unreachable();
    }
  }

  // True if event has been handled.
  inline bool handleEventOutPreConditionError_(
      const Event* ev,
      TGroupIdx group_idx,
      const Stack& last_stack) {
    // When switching out or terminating a phase there is no context on top
    // of event's level to load, so next active stack must be an exact
    // match, unless we are starting.
    if (last_stack.known_num_levels && last_stack.num_set_tags > 0) {
      auto l = static_cast<int>(ev->level);
      if (unlikely(last_stack.num_set_tags <= l)) {
        std::ostringstream oss;
        oss << "Event that pop a Tag from TagStack at level: " << l
            << " was received but the last stack for group_idx " << group_idx
            << " has only " << last_stack.num_set_tags << " levels ("
            << last_stack << "). Is pipeline_max_delay too small for actual "
            << "pipeline latency? Event: " << *ev;
        oss << " Or has a generator been disabled?";
        // XXX: Drain of events on error is not complete and that is causing the
        // problem.
        HBT_LOG_WARNING() << oss.str();
        last_ts_ = ev->tstamp;
        ++stats_.num_processed;
        ++stats_.num_error_out_sync;
        events_->complete();
        resetState_();
        return true;
      }
    }
    return false;
  }

  inline bool handleEventInPreConditionError_(
      const Event* ev,
      const Stack& last_stack) {
    // When switching in, Tags at top of event's level should be loaded (if
    // present) from the dormant_states_, unless it's a Phase start or the
    // TagStack is aliased.
    HBT_DCHECK(ev->isIn());
    if (unlikely(
            last_stack.num_set_tags > ev->level &&
            last_stack.tags[ev->level] != kNA)) {
      Tag old_tag = last_stack.tags[ev->level];

      std::ostringstream oss;

      oss << "Unexpected TagStack event. "
          << "Attempt to switch in tag: \"" << tagToStr(ev->tag)
          << "\" when tag \"" << tagToStr(old_tag) << "\" is active."
          << " Last stack: " << last_stack << " Event: " << *ev
          << ". Reseting state.";

      HBT_LOG_ERROR() << oss.str();

      last_ts_ = ev->tstamp;
      events_->complete();
      resetState_();
      ++stats_.num_processed;
      return true;
      ;
      // XXX: Keeps stats of failures like these.
    }
    return false;
  }
};

} // namespace facebook::hbt::tagstack::slice
