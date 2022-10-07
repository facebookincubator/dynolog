// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <folly/ProducerConsumerQueue.h>

// SPSCQueueConsumerWrapper is a readable end point reading data from
// folly::ProducerConsumerQueue.

namespace {

template <class T>
class SPSCQueueConsumerWrapper {
 public:
  using TQueue = folly::ProducerConsumerQueue<T>;
  using TQueuePtr = std::shared_ptr<TQueue>;

 private:
  TQueuePtr queuePtr;

 public:
  SPSCQueueConsumerWrapper(TQueuePtr qPtr) : queuePtr(qPtr) {}
  SPSCQueueConsumerWrapper(const SPSCQueueConsumerWrapper&) = delete;
  SPSCQueueConsumerWrapper(SPSCQueueConsumerWrapper&&) = default;
  SPSCQueueConsumerWrapper& operator=(SPSCQueueConsumerWrapper&&) = default;
  SPSCQueueConsumerWrapper& operator=(const SPSCQueueConsumerWrapper&) =
      default;

  size_t tryRead(T& data) {
    return queuePtr->read(data);
  }
};

} // end of namespace
