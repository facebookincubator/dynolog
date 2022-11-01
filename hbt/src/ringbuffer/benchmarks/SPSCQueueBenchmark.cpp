// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/benchmarks/SPSCBenchmark.hpp"
#include "hbt/src/ringbuffer/benchmarks/SPSCQueueConsumerWrapper.hpp"
#include "hbt/src/ringbuffer/benchmarks/SPSCQueueProducerWrapper.hpp"

#include <common/init/Init.h>
#include <folly/Benchmark.h>
#include <folly/ProducerConsumerQueue.h>

// Single producer single consumer benchmark transferring data through
// folly::ProducerConsumerQueue

template <class T>
using SPSCQueueBenchmark = SPSCBenchmark<
    T,
    SPSCQueueProducerWrapper<T>,
    SPSCQueueConsumerWrapper<T>,
    folly::ProducerConsumerQueue<T>>;

BENCHMARK(SPSCQueue_int_1K_1M) {
  SPSCQueueBenchmark<int>(1024).run(1024 * 1024);
}

BENCHMARK(SPSCQueue_POD16_1K_1M) {
  SPSCQueueBenchmark<POD16>(1024).run(1024 * 1024);
}

BENCHMARK(SPSCQueue_int_64K_32M) {
  SPSCQueueBenchmark<int>(64 * 1024).run(64 * 1024 * 1024);
}

BENCHMARK(SPSCQueue_POD16_64K_32M) {
  SPSCQueueBenchmark<POD16>(64 * 1024).run(64 * 1024 * 1024);
}

//  Boilerplate....
int main(int argc, char** argv) {
  facebook::initFacebook(&argc, &argv);
  folly::runBenchmarks();
  return 0;
}
