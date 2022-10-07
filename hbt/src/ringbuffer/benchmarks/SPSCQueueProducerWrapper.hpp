// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <folly/ProducerConsumerQueue.h>

// SPSCQueueProducerWrapper is writable end point writing data
// to folly::ProducerConsumerQueue.

namespace {

template <class T>
class SPSCQueueProducerWrapper {
 public:
  using TQueue = folly::ProducerConsumerQueue<T>;
  using TQueuePtr = std::shared_ptr<TQueue>;

 private:
  TQueuePtr queuePtr;

 public:
  SPSCQueueProducerWrapper(TQueuePtr qPtr) : queuePtr(qPtr) {}
  SPSCQueueProducerWrapper(const SPSCQueueProducerWrapper&) = delete;
  SPSCQueueProducerWrapper(SPSCQueueProducerWrapper&&) = default;
  SPSCQueueProducerWrapper& operator=(SPSCQueueProducerWrapper&&) = default;
  SPSCQueueProducerWrapper& operator=(const SPSCQueueProducerWrapper&) =
      default;

  size_t tryWrite(const T& data) {
    return queuePtr->write(data);
  }
};

} // end of namespace
