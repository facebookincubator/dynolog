// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/ringbuffer/benchmarks/Data.hpp"

#include <cstddef>
#include <memory>

// Consumer class is a functor which reads from readable endpoint represented
// by TReadableEntPoint type. The endpoint is constructable form TQueuePtr
// which supposed to be C++ shared pointer pointing to a queue serving
// as a media for data transfer between endpoints.
//
// Consumer reads and count data tokens until
// certain amount of termination tokens were met.
// The amount of termination tokens required to be met before functor exit is
// passed to ctor as initialTermCnt parameter.
//
// The amount of data tokens reads bu consumer is available
// through getReadCount() function.

namespace {

template <class T, class TReadableEndPoint>
class Consumer {
 private:
  using TQueuePtr = typename TReadableEndPoint::TQueuePtr;
  TReadableEndPoint endPoint;
  size_t initialTermCnt;
  size_t readCount = 0;

 protected:
  void read(T& value) {
    while (!endPoint.tryRead(value))
      ;
  }

 public:
  Consumer(TQueuePtr& queuePtr, size_t initialTermCnt = 1)
      : endPoint(queuePtr), initialTermCnt(initialTermCnt) {}
  Consumer(const Consumer&) = delete;
  Consumer(Consumer&&) = default;
  Consumer& operator=(Consumer&&) = default;
  Consumer& operator=(const Consumer&) = delete;

  void operator()() {
    size_t termCnt = initialTermCnt;
    readCount = 0;
    while (true) {
      T value;
      read(value);
      if (!DataTraits<T>::isTerminationToken(value)) {
        ++readCount;
        continue;
      }
      if (--termCnt == 0) {
        break;
      }
    }
  }

  size_t getReadCount() const {
    return readCount;
  }
};

} // end of namespace
