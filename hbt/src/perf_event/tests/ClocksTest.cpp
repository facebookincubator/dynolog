// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"
#include "hbt/src/perf_event/PerCpuCountSampleGenerator.h"
#include "hbt/src/perf_event/PerCpuThreadSwitchGenerator.h"
#include "hbt/src/ringbuffer/Consumer.h"
#include "hbt/src/ringbuffer/Producer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"

#include <gtest/gtest.h>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

struct MockExtraData {};

//
// Test that inconsistencies between TSC in different CPUs is too small to
// matter, i.e. that succesive reads will find strictly increasing time as long
// as reads don't happen too close to each other. "Too close" in hbt means less
// than the time it takes to migrate a thread between CPUs.
//
TEST(Clocks, TscVsKernelClocks) {
  auto pmu_manager = makePmuDeviceManager();
  auto m = makeAvailableMetrics()->getMetricDesc("ipc");

  auto cpu_set = CpuSet::makeAllOnline();

  PerCpuCountSampleGenerator gen(cpu_set, m, pmu_manager, nullptr, 1000000, 0);
  gen.open(8, 100000000000);
  gen.enable();

  {
    const size_t kNumSamples = 100000;
    TimeStamp last_tstamp = std::numeric_limits<TimeStamp>::min();
    std::vector<TimeStamp> samples(kNumSamples);

    // Check that TSC is strictly monotonically increasing even accross CPUs.
    // We can assume strictly increasing because the loop takes long.
    for (int i = 0; i < kNumSamples; ++i) {
      // rand() always returns >0 numbers.
      CpuId cpu = static_cast<CpuId>(rand()) % (cpu_set.max_cpu_id + 1);
      auto& cpu_gen = gen.getCpuGenerator(cpu);
      TimeStamp new_tstamp = cpu_gen.now();
      EXPECT_LT(last_tstamp, new_tstamp);
      last_tstamp = new_tstamp;
    }

    // Now sequentially.
    for (int i = 0; i < kNumSamples; ++i) {
      auto& cpu_gen =
          gen.getCpuGenerator(static_cast<CpuId>(i) % (cpu_set.max_cpu_id + 1));
      TimeStamp new_tstamp = cpu_gen.now();
      EXPECT_LT(last_tstamp, new_tstamp);
      last_tstamp = new_tstamp;
    }
  }
}

TEST(Clocks, TscVsKernelClocksConversion) {
  auto pmu_manager = makePmuDeviceManager();
  auto m = makeAvailableMetrics()->getMetricDesc("ipc");

  auto cpu_set = CpuSet::makeAllOnline();

  PerCpuCountSampleGenerator gen(cpu_set, m, pmu_manager, nullptr, 1000000, 0);
  gen.open(0, 100000000000);

  // Conversion logic is integer based and not perfect, so test that it is
  // within one of the expected number.

  {
    auto tsc = gen.tscFromTimeStamp(0);
    auto tstamp = gen.tstampFromTsc(tsc);
    EXPECT_TRUE(tstamp == 0 || tstamp + 1 == 0);
  }
  {
    auto tsc = gen.tscFromTimeStamp(82380);
    auto tstamp = gen.tstampFromTsc(tsc);
    // Tolerate rounding error.
    EXPECT_TRUE(82380 - 2 <= tstamp && tstamp <= 82380 + 2);
  }

  {
    auto tstamp = gen.tstampFromTsc(18230);
    auto tsc = gen.tscFromTimeStamp(tstamp);
    // Tolerate rounding error.
    EXPECT_TRUE(18230 - 2 <= tsc && tsc <= 18230 + 2) << "Got tsc: " << tsc;
  }
}
