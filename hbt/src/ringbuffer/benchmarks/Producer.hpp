// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/ringbuffer/benchmarks/Data.hpp"

// The Producer sends to a writable end point initialDataCnt elements
// representing data tokens and initialTermCnt elements representing
// termination tokens.
// Data termination token signals a Consumer that data transfer has finished.
// Multiple termination tokens are needed for the case imbalanced amount
// of producers vs. consumers.

namespace {

template <class T, class TWritableEndPoint>
class Producer {
 private:
  // using TWritableEndPointTraits = WritableEndPointTraits<T, Producer<T,
  // TWritableEndPoint>>;
  // using TWritableEndPointPtr = typename std::shared_ptr<TWritableEndPoint>;
  using TQueuePtr = typename TWritableEndPoint::TQueuePtr;
  TWritableEndPoint endPoint;
  size_t initialDataCnt;
  size_t initialTermCnt;

 protected:
  void write(const T& data) {
    while (!endPoint.tryWrite(data))
      ;
  }

 public:
  Producer(
      TQueuePtr& queuePtr,
      size_t initialDataCnt,
      size_t initialTermCnt = 1)
      : endPoint(queuePtr),
        initialDataCnt(initialDataCnt),
        initialTermCnt(initialTermCnt) {}

  Producer(const Producer&) = delete;
  Producer(Producer&&) = default;
  Producer& operator=(Producer&&) = default;
  Producer& operator=(const Producer&) = delete;

  void operator()() {
    size_t dataCnt = initialDataCnt;
    size_t termCnt = initialTermCnt;

    while (dataCnt) {
      write(DataTraits<T>::data);
      --dataCnt;
    }
    while (termCnt) {
      write(DataTraits<T>::terminationToken);
      --termCnt;
    }
  }
};

} // end of namespace
