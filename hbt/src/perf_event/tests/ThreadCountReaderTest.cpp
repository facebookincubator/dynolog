// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/ThreadCountReader.h"
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"

#include <gtest/gtest.h>
#include <sched.h>
#include <chrono>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

int64_t myRand() {
  // seed the generator with the current time
  static int64_t seed =
      std::chrono::system_clock::now().time_since_epoch().count() / 1000000;

  // constants for the linear congruential method
  const int64_t a = 1664525;
  const int64_t c = 1013904223;
  const int64_t m = 4294967296; // 2^32

  // calculate the next random number
  seed = (a * seed + c) % m;

  return seed;
}

TEST(ThreadCountReader, SmokeTest) {
  // XXX duplicated in PerCpuGeneratorsTest.cpp, refactor to common file?

  // Create a metric to use in this test.
  // Alternatively, you can create a Metrics object
  // with makeAvailableMetrics() and call
  // Metrics::getMetricDesc(metric_id).
  // Default metrics are populated in hbt/src/perf_event/BuiltinMetrics.cpp
  auto m = std::make_shared<MetricDesc>(
      "ipc",
      "IPC including user but excluding kernel, and hypervisor.",
      "Intructions-per-Cycle (IPC) including user but excluding kernel, and hypervisor. ",
      std::map<TOptCpuArch, EventRefs>{
          {// We'll use generic events so no need to specify CPU architecture.
           std::nullopt,
           EventRefs{
               EventRef{
                   .nickname = "inst",
                   // Using Linux's kernel generic events.
                   .pmu_type = PmuType::generic_hardware,
                   // The event-name as defined in PMU of generic events.
                   .event_id = "retired_instructions",
                   // Capture user-space only.
                   // See EventExtraAttr for other convenience factory
                   // functions. Or create your own EventExtraAttr.
                   .extra_attr = EventExtraAttr::makeUserOnly()},
               EventRef{
                   .nickname = "cycles",
                   // Using Linux's kernel generic events.
                   .pmu_type = PmuType::generic_hardware,
                   // The event-name as defined in PMU of generic events.
                   .event_id = "cpu_cycles",
                   // Capture user-space only.
                   // See EventExtraAttr for other convenience factory
                   // functions. Or create your own EventExtraAttr.
                   .extra_attr = EventExtraAttr::makeUserOnly()}}}},
      0, // 0 sampling_period is ok because we do not require sampling.
      System::Permissions{}, // No special system permissions required for these
                             // events.
      std::vector<std::string>{} // No post-processing dives
  );

  auto pmu_manager = makePmuDeviceManager();
  auto cpu_arch = pmu_manager->cpuInfo.cpu_arch;

  HBT_DCHECK(pmu_manager != nullptr);

  // Monitor events for current thread.
  ThreadCountReader g(m, pmu_manager);

  // Open without pinning the events.
  g.open(false);
  g.enable();
  ASSERT_TRUE(g.isEnabled());

  // Object to store data read from counters.
  // Definition comes from GroupReadValues<>.
  auto rv = g.makeReadValues();
  ASSERT_TRUE(m->getNumEvents(cpu_arch).has_value());

  // Events always keep creation order in EventRefs,
  // so we could also just use 0 and 1 rather than query the indices.
  ASSERT_TRUE(m->eventIdxFromNicknames(cpu_arch, "cycles").has_value());
  auto cycles_ev_idx = m->eventIdxFromNicknames(cpu_arch, "cycles").value();
  ASSERT_TRUE(m->eventIdxFromNicknames(cpu_arch, "inst").has_value());
  auto inst_ev_idx = m->eventIdxFromNicknames(cpu_arch, "inst").value();
  ASSERT_EQ(cycles_ev_idx, 1);
  ASSERT_EQ(inst_ev_idx, 0);

  // Do some work
  int iters = 1000;
  int64_t cur_rand = 0, prev_rand = 0;
  while (iters--) {
    prev_rand = cur_rand;
    cur_rand = myRand();
  }

  // Random numbers should not be same in a row
  ASSERT_NE(prev_rand, cur_rand);

  // Read thread level counters.
  auto v = g.read(rv);
  ASSERT_TRUE(v);
  ASSERT_GT(rv.getTimeRunning(), 0);
  ASSERT_GT(rv.getTimeEnabled(), 0);
  ASSERT_GT(rv.getCount(inst_ev_idx), 100);
  ASSERT_GT(rv.getCount(cycles_ev_idx), 100);
  ASSERT_LE(rv.getTimeEnabled(), rv.getTimeRunning());

  // Easy to use version that always creates a ReadValues objecct.
  auto rrv = g.read();
  ASSERT_TRUE(rrv.has_value());
  ASSERT_EQ(rrv->getNumEvents(), rv.getNumEvents());

  g.disable();
  g.close();
}
