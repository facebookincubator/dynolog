// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/ringbuffer/Consumer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"

#include <limits>

// RingBufferConsumerWrapper is a readable endpoint reading from
// facebook::hbt::ringbuffer::RingBuffer

namespace {

template <class T, class TExtra = int>
class RingBufferConsumerWrapper
    : public facebook::hbt::ringbuffer::Consumer<TExtra> {
  using TParent = facebook::hbt::ringbuffer::Consumer<TExtra>;

 public:
  using TQueue = facebook::hbt::ringbuffer::RingBuffer<TExtra>;
  using TQueuePtr = std::shared_ptr<TQueue>;

  RingBufferConsumerWrapper(TQueuePtr qPtr) : TParent(qPtr) {}
  RingBufferConsumerWrapper(const RingBufferConsumerWrapper&) = delete;
  RingBufferConsumerWrapper(RingBufferConsumerWrapper&&) = default;
  RingBufferConsumerWrapper& operator=(RingBufferConsumerWrapper&&) = default;
  RingBufferConsumerWrapper& operator=(const RingBufferConsumerWrapper&) =
      delete;

  size_t tryRead(T& data) {
    // Ring buffer encodes errors in the upper part of numeric range of size_t.
    // In a case of an error zero is returned since none of data were red.
    // This lets Consumer to reiterate read cycle.
    size_t rc = this->template copy<T>(data);
    if (rc >= std::numeric_limits<size_t>::max() - 1024)
      return 0;
    return rc;
  }
};

} // end of namespace
