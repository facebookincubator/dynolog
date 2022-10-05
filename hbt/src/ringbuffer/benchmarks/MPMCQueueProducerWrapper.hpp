#pragma once

#include <folly/MPMCQueue.h>

// MPMCQueueProducerWrapper is writable end point writing data
// to folly::MPMCQueue.

namespace {

template <class T>
class MPMCQueueProducerWrapper {
 public:
  using TQueue = folly::MPMCQueue<T>;
  using TQueuePtr = std::shared_ptr<TQueue>;

 private:
  TQueuePtr queuePtr;

 public:
  MPMCQueueProducerWrapper(TQueuePtr qPtr) : queuePtr(qPtr) {}
  MPMCQueueProducerWrapper(const MPMCQueueProducerWrapper&) = delete;
  MPMCQueueProducerWrapper(MPMCQueueProducerWrapper&&) = default;
  MPMCQueueProducerWrapper& operator=(MPMCQueueProducerWrapper&&) = default;
  MPMCQueueProducerWrapper& operator=(const MPMCQueueProducerWrapper&) =
      default;

  size_t tryWrite(const T& data) {
    return queuePtr->write(data);
  }
};

} // end of namespace
