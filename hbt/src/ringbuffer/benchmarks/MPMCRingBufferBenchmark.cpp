// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/ringbuffer/benchmarks/Data.hpp"
#include "hbt/src/ringbuffer/benchmarks/MPMCBenchmark.hpp"
#include "hbt/src/ringbuffer/benchmarks/RingBufferConsumerWrapper.hpp"
#include "hbt/src/ringbuffer/benchmarks/RingBufferProducerWrapper.hpp"

#include <common/init/Init.h>
#include <folly/Benchmark.h>
#include <folly/MPMCQueue.h>

template <class T, class TExtra = int>
using MPMCRingBufferBenchmark = MPMCBenchmark<
    T,
    RingBufferProducerWrapper<T, TExtra>,
    RingBufferConsumerWrapper<T, TExtra>,
    facebook::hbt::ringbuffer::RingBuffer<TExtra>>;

BENCHMARK(MPMCRingBuffer_1P1C_int_1K_1M) {
  MPMCRingBufferBenchmark<int>(1024).run(1024 * 1024, 1, 1);
}

BENCHMARK(MPMCRingBuffer_2P13C_int_1K_1M) {
  MPMCRingBufferBenchmark<int>(1024).run(1024 * 1024, 2, 13);
}

BENCHMARK(MPMCRingBuffer_17P3C_POD16_1K_1M) {
  MPMCRingBufferBenchmark<POD16>(1024).run(1024 * 1024, 17, 3);
}

BENCHMARK(MPMCRingBuffer_14P14C_POD16_1K_1M) {
  MPMCRingBufferBenchmark<POD16>(1024).run(1024 * 1024, 14, 14);
}

//  Boilerplate
int main(int argc, char** argv) {
  facebook::initFacebook(&argc, &argv);
  folly::runBenchmarks();
  return 0;
}
