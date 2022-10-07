// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/ringbuffer/Consumer.h"
#include "hbt/src/ringbuffer/Producer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/tagstack/Event.h"
#include "hbt/src/tagstack/Stream.h"
#include "hbt/src/tagstack/TagStack.h"

#include <iostream>
#include <limits>
#include <map>
#include <thread>

#include <boost/intrusive/list.hpp>

///
/// Namespace for stream of tagstack::Event .
///
/// Streams are connected forming a directional graph. Each
/// Stream exposes two methods:
///   - Event* prepareNext(TimeStamp stop_ts)
///   - void complete()
///
/// User must call prepareNext to obtain a pointer to the next event
/// in the stream that has a timestamp less than stop_ts. Then call
/// complete() to allow the stream to release the pointer returned
/// by prepareNext. If prepareNext returns nullptr, then there is no
/// an event in the stream with timestamp less than stop_ts and
/// there is no need to call complete.
///
namespace facebook::hbt::tagstack::stream {

/// Wraps a ringbuffer Consumer to behave like a Stream.
///
/// The implementation leaves transactions open
/// so the RingBuffer should not have multiple
/// consumers.
template <class TExtraData>
class RingBufferStream : protected ringbuffer::Consumer<TExtraData> {
 public:
  using TRingBuffer = ringbuffer::RingBuffer<TExtraData>;

  // Use base class constructor.
  using ringbuffer::Consumer<TExtraData>::Consumer;

  inline const Event* prepareNext() DEXCEPT {
    return prepareNext(kInvalidTimeStamp);
  }

  inline const Event* prepareNext(TimeStamp stop_ts) {
    if (next_event_ != nullptr) {
      if (next_event_->tstamp <= stop_ts) {
        return next_event_;
      } else {
        return nullptr;
      }
    }

    // Poor's man way to retry on temporal failures.
    // It should be extremely rare, so this simple logic is fine.
    constexpr int max_num_retries = 2;
    int num_retries = 0;

  retry_rb_read:
    auto [ret, event] = this->template startReadTx<tagstack::Event>();
    if (ret == -ENODATA) {
      return nullptr;
    } else if (unlikely(ret == -EAGAIN || ret == -EBUSY)) {
      if (ret == -EBUSY) {
        // If busy, then another thread is in the middle of a transaction.
        // Yield and retry.
        std::this_thread::yield();
      }
      if (++num_retries <= max_num_retries) {
        goto retry_rb_read;
      } else {
        return nullptr;
      }
    }

    HBT_THROW_SYSTEM_CODE_IF(0 > ret, toErrorCode(-ret))
        << "RingBuffer read failed due to unexpected causes: "
        << toErrorCode(-ret).message();
    ;
    HBT_THROW_ASSERT_IF(event == nullptr);
    HBT_THROW_ASSERT_IF(
        next_event_ != nullptr && event->happenedBefore(*next_event_));

    next_event_ = event;
    return event->tstamp <= stop_ts ? next_event_ : nullptr;
  }

  inline void complete() DEXCEPT {
    HBT_DCHECK(next_event_ != nullptr);
    auto ret = this->commitTx();
    HBT_LOG_ERROR_IF(ret < 0)
        << "Unexpected error committing transaction. Error: " << ret;
    next_event_ = nullptr;
  }

 protected:
  const Event* next_event_ = nullptr;
};

/// Combines events from streams A and B in-order with (almost) zero-copy.
/// To simplify, enforce that stream A is always set and stream B is almost
/// always set.
template <class TStreamA, class TStreamB>
class Combinator {
 public:
  Combinator(std::shared_ptr<TStreamA> a, std::shared_ptr<TStreamB> b)
      : a_{a}, b_{b} {
    HBT_ARG_CHECK(a_ != nullptr);
  }

  /// Retrieves elements in order skipping empty streams.
  /// This is the hottest function in all Heartbeat and is optimized
  /// accordingly.
  inline const Event* prepareNext(TimeStamp stop_ts) DEXCEPT {
    HBT_DCHECK_GE(stop_ts, last_empty_ts_[0]);
    HBT_DCHECK_GE(stop_ts, last_empty_ts_[1]);

    if (last_chosen_ != nullptr) {
      return last_chosen_;
    }

    HBT_THROW_ASSERT_IF(last_chosen_ != nullptr)
        << "Did you forget to call complete?";

    // Try to avoid calling prepareNext if we already have
    // failed to obtain an event up to this stop_ts.
    if (!last_events_[0].isValid() && stop_ts > last_empty_ts_[0]) {
      if (const auto* ev = a_->prepareNext(stop_ts); ev != nullptr) {
        HBT_DCHECK_GE(ev->tstamp, last_empty_ts_[0]);
        HBT_DCHECK_GE(stop_ts, ev->tstamp) << *ev;
        last_events_[0] = *ev;
        a_->complete();
      } else {
        last_empty_ts_[0] = stop_ts;
      }
    }

    if (b_ != nullptr && !last_events_[1].isValid() &&
        stop_ts > last_empty_ts_[1]) {
      if (const auto* ev = b_->prepareNext(stop_ts); ev != nullptr) {
        HBT_DCHECK_GE(ev->tstamp, last_empty_ts_[1]);
        HBT_DCHECK_GE(stop_ts, ev->tstamp) << *ev;
        last_events_[1] = *ev;
        b_->complete();
      } else {
        last_empty_ts_[1] = stop_ts;
      }
    }

    Event& ev_a = last_events_[0];
    Event& ev_b = last_events_[1];

    static_assert(
        kInvalidTimeStamp == std::numeric_limits<TimeStamp>::max(),
        "This comparison relies on happenedBefore choosing any valid event "
        "before one with kInvalidTimeStamp");

    // When none of the events is valid, return last_chosen_'s nullptr.
    HBT_DCHECK(last_chosen_ == nullptr);
    if (ev_a.isValid() || ev_b.isValid()) {
      last_chosen_ = ev_a.happenedBefore(ev_b) ? &ev_a : &ev_b;
      HBT_DCHECK(last_chosen_->isValid());
    }
    return last_chosen_;
  }

  inline void complete() noexcept {
    HBT_DCHECK(last_chosen_ != nullptr);
    // Invalidate the event at <last_chosen_> by setting it to the
    // max of members used in Event::happenedBefore.
    // Note that kInvalidTimeStamp is also the max, this is important
    // for the quick comparison done in prepareNext.
    last_chosen_->tstamp = kInvalidTimeStamp;
    last_chosen_->comp_unit_id = std::numeric_limits<CompUnitId>::max();

    last_chosen_ = nullptr;
  }

 protected:
  std::shared_ptr<TStreamA> a_;
  std::shared_ptr<TStreamB> b_;

  Event last_events_[2] = {
      {.tstamp = kInvalidTimeStamp},
      {.tstamp = kInvalidTimeStamp}};
  TimeStamp last_empty_ts_[2] = {
      std::numeric_limits<TimeStamp>::min(),
      std::numeric_limits<TimeStamp>::min()};
  Event* last_chosen_ = nullptr;
};

template <class TStream>
using BinaryCombinator = Combinator<TStream, TStream>;

/// Creates a binary tree where the leafs are input nodes in stream.
/// Consumes inputs nodes in streams and adds them, pairwise, into
/// a BinaryCombinator, then calls itself recursively to combne the
/// resulting nodes again.
/// TRoot is a nested template of binary combinators.
/// The base case is TRoot == BinaryCombinator<TInputNode>, in which case
/// returns a single BinaryCombinator<TInputNode> that is the root of
/// the binary tree.
template <class TRoot, class TInputNode>
auto makeBinaryTree(std::vector<std::unique_ptr<TInputNode>>& streams) {
  using TNode = BinaryCombinator<TInputNode>;

  const size_t num_streams = streams.size();
  HBT_THROW_ASSERT_IF(num_streams <= 0);

  // Integer ceiling.
  size_t num_nodes = ((streams.size() - 1) / 2) + 1;
  auto nodes = std::vector<std::unique_ptr<TNode>>{};
  nodes.reserve(num_nodes);

  for (size_t i = 0; i < num_streams; i += 2) {
    if (i + 1 < num_streams) {
      nodes.emplace_back(std::make_unique<TNode>(
          std::move(streams.at(i)), std::move(streams.at(i + 1))));
    } else {
      nodes.emplace_back(
          std::make_unique<TNode>(std::move(streams.at(i)), nullptr));
    }
  }

  if constexpr (std::is_same_v<TNode, TRoot>) {
    HBT_THROW_ASSERT_IF(nodes.size() != 1)
        << "More streams than leaf nodes at tree";
    return std::shared_ptr<TRoot>(std::move(nodes.back()));
  } else {
    return makeBinaryTree<TRoot, TNode>(nodes);
  }
}

///
/// Handy function to estimate stop_ts considering
/// the maximum latency in a stream.
/// XXX: Rename pipeline to stream everywhere.
///
template <class T>
TimeStamp toStopTs(TimeStamp ts, const T& pipeline_max_lat) {
  TimeStamp lat = DurationToTimeStamp(pipeline_max_lat);
  if (ts > lat) {
    return ts - lat;
  }
  return 0;
}

} // namespace facebook::hbt::tagstack::stream
