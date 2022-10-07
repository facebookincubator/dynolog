// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/tagstack/Event.h"

namespace facebook::hbt::tagstack::stream {

/// Wraps a ringbuffer Consumer whose RingBuffer's ExtraData
/// has an ErrorCtxt. The Consumer behaves like a stream that
/// generates WriteError Events when ringbuffer is in error.
//
/// If <kTscConversion> is true, it also converts timestamps from TSC to
/// perf_event kernel clock (nanoseconds from boot) by using the sched_clock
/// conversion variables exposed in perf_event mmap's header page.
///
/// If the RingBuffer is in error, use the number of errors to
/// produce WriteError events.
///
/// Note: This class uses rdtscp to obtain times. The template
/// parameter kTscConversion indicates if it would be converted
/// to system time to be used together with perf_event
/// events or another data with different time source.
template <class TCpuEventsGroup, class TErrorCtxt>
class TscConverterStream {
 public:
  using TRingBufferStream = RingBufferStream<TErrorCtxt>;
  using TRingBuffer = typename TRingBufferStream::TRingBuffer;

  TscConverterStream(const TscConverterStream&) = delete;
  TscConverterStream(TscConverterStream&&) = delete;

  TscConverterStream(
      std::shared_ptr<TRingBuffer> rb,
      std::shared_ptr<TCpuEventsGroup> tsc_converter)
      : rb_stream_{rb}, tsc_converter_{tsc_converter} {
    HBT_DCHECK(rb != nullptr);
    HBT_DCHECK(tsc_converter != nullptr);
  }

  inline const Event* prepareNext(TimeStamp stop_ts) {
    if (aux_.tstamp != kInvalidTimeStamp && aux_.tstamp <= stop_ts) {
      return &aux_;
    }
    // The ringbuffer's timestamp is in TSC time, so always
    // get the event, convert timestamp and then enforce stop_ts.
    const auto* ev_ptr = rb_stream_.prepareNext(kMaxTimeStamp);
    if (ev_ptr == nullptr) {
      return nullptr;
    }
    aux_ = *ev_ptr;
    rb_stream_.complete();
    aux_.tstamp = tsc_converter_->kernelTimeFromTsc(aux_.tstamp);

    return ((aux_.tstamp <= stop_ts) ? &aux_ : nullptr);
  }

  inline void complete() DEXCEPT {
    HBT_DCHECK_NE(aux_.tstamp, kInvalidTimeStamp);
    aux_.tstamp = kInvalidTimeStamp;
  }

 protected:
  TRingBufferStream rb_stream_;
  std::shared_ptr<TCpuEventsGroup> tsc_converter_;
  tagstack::Event aux_ = {.tstamp = kInvalidTimeStamp};
};

} // namespace facebook::hbt::tagstack::stream
