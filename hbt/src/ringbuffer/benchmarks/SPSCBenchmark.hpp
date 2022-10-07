// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/System.h"
#include "hbt/src/ringbuffer/benchmarks/Consumer.hpp"
#include "hbt/src/ringbuffer/benchmarks/Producer.hpp"
#include "hbt/src/ringbuffer/benchmarks/ThreadBind.hpp"
#include "hbt/src/ringbuffer/benchmarks/TriggerableThread.hpp"

#include <thread>
#include <vector>

#include <gtest/gtest.h>

// SPSCBenchmark is a benchmarking class. It constructs one readable and
// one writable endpoints attached to the same queue. The size of the queue is
// passed as a parameter to benchmarks constructor.
// The benchmark starts by a call of run(problemSize) method. The parameter
// passed to the method represents the amount of data tokens to write
// to writable end point. The same amount is supposed to be receiver on the
// readable end point before termination token been received.
// The benchmarks does validation of this fact and reports an error in case if
// amount of received tokens differs from problem size.
//
// TWritableEndPoint is supposed to be a class having a constructor from
// shared_ptr<TQueue>&. And the end point should provide
// size_t tryWrite(const T&) method to write a data to the queue.
// The method should return non-zero in case of success and zero on error.
//
// TReadableEndPoint is supposed to be a class having a constructor from
// shared_ptr<TQueue>&. And the end point should provide
// size_t tryRead(T&) method to read a data from the queue.
// The method should return non-zero in case of success and zero on error.

namespace {

template <
    class T,
    class TWritableEndPoint,
    class TReadableEndPoint,
    class TQueue>
class SPSCBenchmark {
 private:
  using TProducer = Producer<T, TWritableEndPoint>;
  using TConsumer = Consumer<T, TReadableEndPoint>;
  using TCpuSet = facebook::hbt::CpuSet;

  std::shared_ptr<TQueue> queuePtr;

  // Smart pointers are used here in order to provide 'builder' like API.
  // Namely 2 methods setProducerCpuSet and setConsumerCpuSet are provided.
  // Direct use of facebook::hbt::CpuSet type w/o smart pointers is infeasible
  // due to constantness of the fields of CpuSet, which inhibits assignment
  // operators.
  std::unique_ptr<TCpuSet> producerCpuSet;
  std::unique_ptr<TCpuSet> consumerCpuSet;

 public:
  explicit SPSCBenchmark(uint32_t queueSize)
      : queuePtr(std::make_shared<TQueue>(queueSize)),
        producerCpuSet(std::make_unique<TCpuSet>(TCpuSet::makeAllOnline())),
        consumerCpuSet(std::make_unique<TCpuSet>(TCpuSet::makeAllOnline())) {}

  SPSCBenchmark(const SPSCBenchmark&) = delete;
  SPSCBenchmark(SPSCBenchmark&&) = delete;
  SPSCBenchmark& operator=(SPSCBenchmark&&) = default;
  SPSCBenchmark& operator=(const SPSCBenchmark&) = delete;

  SPSCBenchmark& setProducerCpuSet(const std::vector<unsigned>& cpuSet) {
    producerCpuSet = std::make_unique<TCpuSet>(TCpuSet::makeFromCont(cpuSet));
    return *this;
  }

  SPSCBenchmark& setConsumerCpuSet(const std::vector<unsigned>& cpuSet) {
    consumerCpuSet = std::make_unique<TCpuSet>(TCpuSet::makeFromCont(cpuSet));
    return *this;
  }

  void run(size_t problemSize) {
    // First create threads and bind them to proper cores. Until "latch" is
    // non-zero the threads are executing spin loops.
    std::shared_ptr<std::atomic<int>> latchPtr =
        std::make_shared<std::atomic<int>>(0);

    auto pPtr = std::make_shared<TProducer>(queuePtr, problemSize);
    TriggerableThread producerThread(latchPtr, [&]() { (*pPtr)(); });
    threadBind(producerThread, *producerCpuSet);

    auto cPtr = std::make_shared<TConsumer>(queuePtr);
    TriggerableThread consumerThread(latchPtr, [&]() { (*cPtr)(); });
    threadBind(consumerThread, *consumerCpuSet);

    // Release threads from spin loop execution
    latchPtr->store(1);

    producerThread.join();
    consumerThread.join();

    EXPECT_EQ(cPtr->getReadCount(), problemSize);
  }
};

} // end of namespace
