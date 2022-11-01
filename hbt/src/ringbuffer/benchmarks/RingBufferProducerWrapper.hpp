// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/ringbuffer/Producer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"

#include <limits>

// RingBufferProducerWrapper is writable end point writing to
// facebook::hbt::ringbuffer::RingBuffer

namespace {

template <class T, class TExtra = int>
class RingBufferProducerWrapper
    : public facebook::hbt::ringbuffer::Producer<TExtra> {
  using TParent = facebook::hbt::ringbuffer::Producer<TExtra>;

 public:
  using TQueue = facebook::hbt::ringbuffer::RingBuffer<TExtra>;
  using TQueuePtr = std::shared_ptr<TQueue>;

  RingBufferProducerWrapper(TQueuePtr qPtr) : TParent(qPtr) {}
  RingBufferProducerWrapper(const RingBufferProducerWrapper&) = delete;
  RingBufferProducerWrapper(RingBufferProducerWrapper&&) = default;
  RingBufferProducerWrapper& operator=(RingBufferProducerWrapper&&) = default;
  RingBufferProducerWrapper& operator=(const RingBufferProducerWrapper&) =
      default;

  size_t tryWrite(const T& data) {
    // Ring buffer encodes errors in the upper part of numeric range of size_t.
    // In a case of an error zero is returned since none of data were written.
    // This let Producer to reiterate write cycle.
    size_t rc = this->template write<T>(data);
    if (rc >= std::numeric_limits<size_t>::max() - 1024)
      return 0;
    return rc;
  }
};

} // end of namespace
