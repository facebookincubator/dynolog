// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/benchmarks/RingBufferConsumerWrapper.hpp"
#include "hbt/src/ringbuffer/benchmarks/RingBufferProducerWrapper.hpp"
#include "hbt/src/ringbuffer/benchmarks/SPSCBenchmark.hpp"

#include <common/init/Init.h>
#include <folly/Benchmark.h>
#include <folly/ProducerConsumerQueue.h>

// Single producer single consumer benchmark transferring data through
// HBT/RingBuffer

template <class T, class TExtra = int>
using SPSCRingBufferBenchmark = SPSCBenchmark<
    T,
    RingBufferProducerWrapper<T, TExtra>,
    RingBufferConsumerWrapper<T, TExtra>,
    facebook::hbt::ringbuffer::RingBuffer<TExtra>>;

BENCHMARK(SPSCRingBuffer_int_1K_1M) {
  SPSCRingBufferBenchmark<int>(1024).run(1024 * 1024);
}

BENCHMARK(SPSCRingBuffer_POD16_1K_1M) {
  SPSCRingBufferBenchmark<POD16>(1024).run(1024 * 1024);
}

BENCHMARK(SPSCRingBuffer_int_64K_32M) {
  SPSCRingBufferBenchmark<int>(64 * 1024).run(64 * 1024 * 1024);
}

BENCHMARK(SPSCRingBuffer_POD16_64K_32M) {
  SPSCRingBufferBenchmark<POD16>(64 * 1024).run(64 * 1024 * 1024);
}

//  Boilerplate....
int main(int argc, char** argv) {
  facebook::initFacebook(&argc, &argv);
  folly::runBenchmarks();
  return 0;
}
