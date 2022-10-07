// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/System.h"
#include "hbt/src/ringbuffer/benchmarks/Consumer.hpp"
#include "hbt/src/ringbuffer/benchmarks/Data.hpp"
#include "hbt/src/ringbuffer/benchmarks/Producer.hpp"
#include "hbt/src/ringbuffer/benchmarks/ThreadBind.hpp"
#include "hbt/src/ringbuffer/benchmarks/TriggerableThread.hpp"

#include <thread>
#include <vector>

#include <gtest/gtest.h>

#include <common/init/Init.h>
#include <folly/Benchmark.h>
#include <folly/MPMCQueue.h>

// MPMCBenchmark is a benchmarking class. It constructs multiple readable and
// multiple writable endpoints attached to the same queue.
// The size of the queue is passed as a parameter to benchmarks constructor.
// The benchmark starts by a call of run(problemSize, nProducers, nConsumers)
// method. The problemSize parameter passed to the method represents the
//  amount of data tokens to write to writable end points. The same amount is
// supposed to be receiver on the readable end points before termination
// tokens been received.
//
// Data as well as termination tokens are distributed almost evenly across
// writable end points. On the receiving side readable endpoints are
// configured in the manner to receive even amount of termination tokens,
// total amount of those matches amount of sent ones through writable end
// points.
//
// The benchmarks does validation of amount of received data tokens and
// reports an error in case if amount of received tokens differs from
// problem size.
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
class MPMCBenchmark {
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
  explicit MPMCBenchmark(uint32_t queueSize)
      : queuePtr(std::make_shared<TQueue>(queueSize)),
        producerCpuSet(std::make_unique<TCpuSet>(TCpuSet::makeAllOnline())),
        consumerCpuSet(std::make_unique<TCpuSet>(TCpuSet::makeAllOnline())) {}

  MPMCBenchmark(const MPMCBenchmark&) = delete;
  MPMCBenchmark(MPMCBenchmark&&) = delete;
  MPMCBenchmark& operator=(MPMCBenchmark&&) = default;
  MPMCBenchmark& operator=(const MPMCBenchmark&) = delete;

  MPMCBenchmark& setProducerCpuSet(const std::vector<unsigned>& cpuSet) {
    producerCpuSet = std::make_unique<TCpuSet>(TCpuSet::makeFromCont(cpuSet));
    return *this;
  }

  MPMCBenchmark& setConsumerCpuSet(const std::vector<unsigned>& cpuSet) {
    consumerCpuSet = std::make_unique<TCpuSet>(TCpuSet::makeFromCont(cpuSet));
    return *this;
  }

  void run(size_t problemSize, uint32_t nProducers, uint32_t nConsumers) {
    ASSERT_GT(nProducers, 0);
    ASSERT_GT(nConsumers, 0);

    // First create threads and bind them to proper cores. Until "latch" is
    // non-zero the threads are executing spin loops.

    std::vector<TriggerableThread> threads;
    auto latchPtr = std::make_shared<std::atomic<int>>(0);
    size_t chunkSize = problemSize / nProducers;
    size_t reminderPS = problemSize - nProducers * chunkSize;

    uint32_t totalTermTokens = std::max(nProducers, nConsumers);
    uint32_t termTokensPerProducer = totalTermTokens / nProducers;
    uint32_t remProdTT = totalTermTokens % nProducers;

    for (uint32_t i = 0; i < nProducers; i++) {
      // Now we have amount of chunks equal to the amount of producers
      // It is require to distribute reminder part evenly among the producers,
      // Otherwise an imbalance can impact execution time if whole reminding
      // data would added to only one of the producers.
      // The strategy to distribute the work among producers is to add
      // one element to each producer's chunk until no data remains
      // in reminderPS.
      // The same approach is applied to equalize amount of termination tokens
      // among consumers.
      size_t adjustedChunkSize = chunkSize + ((i < reminderPS) ? 1 : 0);
      uint32_t adjustedTTCount =
          termTokensPerProducer + ((i < remProdTT) ? 1 : 0);
      auto pPtr = std::make_shared<TProducer>(
          queuePtr, adjustedChunkSize, adjustedTTCount);
      auto pProcFunc = [=]() { (*pPtr)(); };
      auto& thr = threads.emplace_back(latchPtr, pProcFunc);
      threadBind(thr, *producerCpuSet);
    }

    std::vector<std::shared_ptr<TConsumer>> consumers;
    uint32_t termTokensPerConsumer = totalTermTokens / nConsumers;
    uint32_t remConsTT = totalTermTokens % nConsumers;

    for (int i = 0; i < nConsumers; i++) {
      uint32_t adjustedTTCount =
          termTokensPerConsumer + ((i < remConsTT) ? 1 : 0);
      auto cPtr = consumers.emplace_back(
          std::make_shared<TConsumer>(queuePtr, adjustedTTCount));
      auto cProcFn = [=]() { (*cPtr)(); };
      auto& thr = threads.emplace_back(latchPtr, cProcFn);
      threadBind(thr, *consumerCpuSet);
    }

    // Release threads from spin loop execution
    latchPtr->store(1);

    for (auto& t : threads) {
      t.join();
    }

    // Verification that all the data have been received
    size_t totalReadCount = 0;
    for (auto const& c : consumers) {
      totalReadCount += c->getReadCount();
    }
    EXPECT_EQ(totalReadCount, problemSize);
  }
};

} // end of namespace
