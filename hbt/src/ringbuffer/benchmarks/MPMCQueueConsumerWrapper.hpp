// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <folly/MPMCQueue.h>

// MPMCQueueConsumerWrapper is a readable end point reading data from
// folly::MPMCQueue.

namespace {

template <class T>
class MPMCQueueConsumerWrapper {
 public:
  using TQueue = folly::MPMCQueue<T>;
  using TQueuePtr = std::shared_ptr<TQueue>;

 private:
  TQueuePtr queuePtr;

 public:
  MPMCQueueConsumerWrapper(TQueuePtr qPtr) : queuePtr(qPtr) {}
  MPMCQueueConsumerWrapper(const MPMCQueueConsumerWrapper&) = delete;
  MPMCQueueConsumerWrapper(MPMCQueueConsumerWrapper&&) = default;
  MPMCQueueConsumerWrapper& operator=(MPMCQueueConsumerWrapper&&) = default;
  MPMCQueueConsumerWrapper& operator=(const MPMCQueueConsumerWrapper&) =
      default;

  size_t tryRead(T& data) {
    return queuePtr->read(data);
  }
};

} // end of namespace
