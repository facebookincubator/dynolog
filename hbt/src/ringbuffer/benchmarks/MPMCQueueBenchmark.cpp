// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/benchmarks/Consumer.hpp"
#include "hbt/src/ringbuffer/benchmarks/Data.hpp"
#include "hbt/src/ringbuffer/benchmarks/MPMCBenchmark.hpp"
#include "hbt/src/ringbuffer/benchmarks/MPMCQueueConsumerWrapper.hpp"
#include "hbt/src/ringbuffer/benchmarks/MPMCQueueProducerWrapper.hpp"
#include "hbt/src/ringbuffer/benchmarks/Producer.hpp"

#include <common/init/Init.h>
#include <folly/Benchmark.h>
#include <folly/MPMCQueue.h>

// Multi-producer Multi-consumer benchmark transferring data through
// folly::MPMCQueue

template <class T>
using MPMCQueueBenchmark = MPMCBenchmark<
    T,
    MPMCQueueProducerWrapper<T>,
    MPMCQueueConsumerWrapper<T>,
    folly::MPMCQueue<T>>;

BENCHMARK(MPMCQueue_1P1C_int_1K_1M) {
  MPMCQueueBenchmark<int>(1024).run(1024 * 1024, 1, 1);
}

BENCHMARK(MPMCQueue_2P13C_int_1K_1M) {
  MPMCQueueBenchmark<int>(1024).run(1024 * 1024, 2, 13);
}

BENCHMARK(MPMCQueue_17P3C_POD16_1K_1M) {
  MPMCQueueBenchmark<POD16>(1024).run(1024 * 1024, 17, 3);
}

BENCHMARK(MPMCQueue_14P14C_POD16_1K_1M) {
  MPMCQueueBenchmark<POD16>(1024).run(1024 * 1024, 14, 14);
}

BENCHMARK(MPMCQueue_14P14C_POD16_1K_1M_CPU_13_13) {
  MPMCQueueBenchmark<POD16>(1024)
      .setProducerCpuSet({13})
      .setConsumerCpuSet({13})
      .run(1024 * 1024, 14, 14);
}

BENCHMARK(MPMCQueue_14P14C_POD16_1K_1M_CPU_0_7) {
  MPMCQueueBenchmark<POD16>(1024)
      .setProducerCpuSet({0})
      .setConsumerCpuSet({7})
      .run(1024 * 1024, 14, 14);
}

//  Boilerplate
int main(int argc, char** argv) {
  facebook::initFacebook(&argc, &argv);
  folly::runBenchmarks();
  return 0;
}
