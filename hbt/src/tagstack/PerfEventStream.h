// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/CpuEventsGroup.h"
#include "hbt/src/ringbuffer/Consumer.h"
#include "hbt/src/tagstack/Event.h"

namespace facebook::hbt::tagstack::stream {

template <class TCpuEventsGroup, class TRingBufferExtraData>
class PerfEventStream {
  using TRingBuffer = ringbuffer::RingBuffer<TRingBufferExtraData>;
  using TRingBufferStream = RingBufferStream<TRingBufferExtraData>;

 public:
  PerfEventStream(const PerfEventStream&) = delete;
  PerfEventStream(PerfEventStream&&) = delete;

  PerfEventStream(
      std::shared_ptr<TRingBuffer> rb,
      std::shared_ptr<TCpuEventsGroup> events_gen)
      : rb_{rb},
        rb_stream_{rb_},
        kBatchSize_{static_cast<unsigned>(
            rb->getHeader().kDataPoolByteSize / sizeof(Event))},
        events_gen_{events_gen} {}

  // XXX: Articulate the stream API.
  inline const Event* prepareNext(TimeStamp stop_ts) noexcept {
    if (unlikely(rb_->getHeader().usedSizeWeak() == 0)) {
      ssize_t ret = events_gen_->consume(kBatchSize_);
      HBT_LOG_ERROR_IF(0 > ret && ret != -ENODATA && ret != -ENOSPC)
          << "Unexpected error consuming perf_event ringbuffer data. "
          << "Error: " << toErrorCode(-ret);
    }

    return rb_stream_.prepareNext(stop_ts);
  }

  void complete() noexcept {
    rb_stream_.complete();
  }

 protected:
  std::shared_ptr<TRingBuffer> rb_;
  TRingBufferStream rb_stream_;
  const unsigned kBatchSize_;
  std::shared_ptr<TCpuEventsGroup> events_gen_;
};

} // namespace facebook::hbt::tagstack::stream
