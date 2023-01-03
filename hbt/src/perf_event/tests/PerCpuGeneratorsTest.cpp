// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/System.h"
#include "hbt/src/intel_pt/IptEventBuilder.h"
#include "hbt/src/perf_event/BPerfCountReader.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"
#include "hbt/src/perf_event/PerCpuCountReader.h"
#include "hbt/src/perf_event/PerCpuCountSampleGenerator.h"
#include "hbt/src/perf_event/PerCpuDummyGenerator.h"
#include "hbt/src/perf_event/PerCpuThreadSwitchGenerator.h"
#include "hbt/src/perf_event/PerCpuTraceAuxGenerator.h"

#include <gtest/gtest.h>
#include <sched.h>
#include <chrono>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

void spin(std::chrono::milliseconds duration) {
  auto start = std::chrono::steady_clock::now();
  while (std::chrono::steady_clock::now() - start <= duration)
    ;
}

TEST(PerCpuThreadSwitchGenerator, SmokeTest) {
  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);

  CPU_SET(1, &cpu_set);
  CPU_SET(3, &cpu_set);

  PerCpuThreadSwitchGenerator g(
      CpuSet::makeFromCpuSet(cpu_set), nullptr, 2, 100);

  g.open(2);
  g.enable();
  ASSERT_TRUE(g.isEnabled());

  g.getCpuGenerator(1).consume(10);
  g.getCpuGenerator(3).consume(10);

  g.disable();
  g.close();
}

TEST(PerCpuCountSampleGenerator, SmokeTest) {
  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);

  CPU_SET(1, &cpu_set);
  CPU_SET(3, &cpu_set);

  auto pmu_manager = makePmuDeviceManager();
  auto metrics = makeAvailableMetrics();

  PerCpuCountSampleGenerator g(
      CpuSet::makeFromCpuSet(cpu_set),
      metrics->getMetricDesc("ipc"),
      pmu_manager,
      nullptr,
      1000,
      0);

  g.open(2, 2 * 1024 * 1024);
  g.enable();
  ASSERT_TRUE(g.isEnabled());

  g.getCpuGenerator(1).consume(10);
  g.getCpuGenerator(3).consume(10);

  auto& cpu_g = g.getCpuGenerator(1);
  size_t n = cpu_g.getNumEntries();
  std::cout << "num entries: " << n;
  auto rb = cpu_g.getOutput();
  std::cout << "rb size: " << rb->getHeader().usedSizeWeak();

  g.accumUntil(10, g.now());

  g.disable();
  g.close();
}

TEST(PerCpuCountReader, SmokeTest) {
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
  auto cpu_set = CpuSet::makeAllOnline();

  // User's slice.
  auto cgroup_path = "/sys/fs/cgroup/user.slice";

  HBT_LOG_INFO() << cgroup_path;
  PerCpuCountReader g(
      cpu_set,
      m,
      pmu_manager,
      // cgroup for current tid.
      std::make_unique<FdWrapper>(cgroup_path));

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

  uint64_t total_count_instructions = 0;
  uint64_t total_count_cycles = 0;
  uint64_t total_time_running = 0;
  uint64_t total_time_enabled = 0;

  {
    // Read counts of cgroup counters in CPU 1.
    // Reading overwrites rv.
    auto success = g.getCpuGenerator(1).read(rv);
    ASSERT_TRUE(success);
    total_count_instructions += rv.getCount(inst_ev_idx);
    total_count_cycles += rv.getCount(cycles_ev_idx);
    total_time_running += rv.getTimeRunning();
    total_time_enabled += rv.getTimeEnabled();
  }
  {
    // Read counts of cgroup counters in CPU 1.
    // Reading overwrites rv.
    auto success = g.getCpuGenerator(3).read(rv);
    ASSERT_TRUE(success);
    total_count_instructions += rv.getCount(inst_ev_idx);
    total_count_cycles += rv.getCount(cycles_ev_idx);
    total_time_running += rv.getTimeRunning();
    total_time_enabled += rv.getTimeEnabled();
  }

  // Read from all CPUs, sums must be larger than the sum of only CPU 1 and 3.
  // User can call this method directly rather than reading from each CPU.
  // Reading overwrites rv.
  auto v = g.read(rv);
  ASSERT_TRUE(v);
  ASSERT_GT(rv.getCount(inst_ev_idx), total_count_instructions);
  ASSERT_GT(rv.getCount(cycles_ev_idx), total_count_cycles);
  ASSERT_GT(rv.getTimeRunning(), total_time_running);
  ASSERT_GT(rv.getTimeEnabled(), total_time_enabled);

  // Easy to use version that always creates a ReadValues objecct.
  auto rrv = g.read();
  ASSERT_TRUE(rrv.has_value());
  ASSERT_EQ(rrv->getNumEvents(), rv.getNumEvents());

  g.disable();
  g.close();
}

TEST(BPerfCountReader, SmokeTest) {
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

  // User's slice.
  auto cgroup_path = "/sys/fs/cgroup/user.slice";

  HBT_LOG_INFO() << cgroup_path;
  BPerfCountReader g(
      "myperfunittest",
      m,
      pmu_manager,
      // cgroup for current tid.
      std::make_unique<FdWrapper>(cgroup_path));

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

  uint64_t total_count_instructions = 0;
  uint64_t total_count_cycles = 0;
  uint64_t total_time_running = 0;
  uint64_t total_time_enabled = 0;

  // Read from all CPUs, sums must be larger than the sum of only CPU 1 and 3.
  // User can call this method directly rather than reading from each CPU.
  // Reading overwrites rv.
  auto succeed = g.read(rv);
  ASSERT_TRUE(succeed);
  ASSERT_GT(rv.getCount(inst_ev_idx), total_count_instructions);
  ASSERT_GT(rv.getCount(cycles_ev_idx), total_count_cycles);
  ASSERT_GT(rv.getTimeRunning(), total_time_running);
  ASSERT_GT(rv.getTimeEnabled(), total_time_enabled);

  // Easy to use version that always creates a ReadValues objecct.
  auto rrv = g.read();
  ASSERT_TRUE(rrv.has_value());
  ASSERT_EQ(rrv->getNumEvents(), rv.getNumEvents());
}

TEST(PerCpuCountSampleGenerator, TracePointTest) {
  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);

  CPU_SET(1, &cpu_set);
  CPU_SET(3, &cpu_set);

  auto pmu_manager = makePmuDeviceManager();
  auto metrics = makeAvailableMetrics();

  PerCpuCountSampleGenerator g(
      CpuSet::makeFromCpuSet(cpu_set),
      metrics->getMetricDesc("system_calls"),
      pmu_manager,
      nullptr,
      1000,
      0);

  g.open(2, 2 * 1024 * 1024);
  g.enable();
  ASSERT_TRUE(g.isEnabled());

  g.getCpuGenerator(1).consume(10);
  g.getCpuGenerator(3).consume(10);

  auto& cpu_g = g.getCpuGenerator(1);
  size_t n = cpu_g.getNumEntries();
  std::cout << "num entries: " << n;
  auto rb = cpu_g.getOutput();
  std::cout << "rb size: " << rb->getHeader().usedSizeWeak();

  g.accumUntil(10, g.now());

  g.disable();
  g.close();
}

TEST(PerCpuDummyGenerator, SmokeTest) {
  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);

  CPU_SET(1, &cpu_set);
  CPU_SET(3, &cpu_set);

  PerCpuDummyGenerator g(CpuSet::makeFromCpuSet(cpu_set));

  g.open();
  g.enable();
  ASSERT_TRUE(g.isEnabled());

  g.now();
  g.tstampFromTsc(1000000);

  g.accumUntil(1, g.now());

  g.disable();
  g.close();
}

TEST(CpuTraceAuxGenerator, SmokeTest) {
  auto pmuManager = makePmuDeviceManager();
  assert(pmuManager != nullptr);
  auto builder = intel_pt::IptEventBuilder::createIptEventBuilder(*pmuManager);

  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);

  CPU_SET(1, &cpu_set);

  auto pid = fork();
  ASSERT_GE(pid, 0) << "fork() failed with errno: " << errno << std::endl;

  if (pid == 0) {
    if (sched_setaffinity(getpid(), sizeof(cpu_set), &cpu_set) != 0) {
      std::cout << "sched_setaffinity() failed with errno: " << errno
                << std::endl;
      return;
    }
    sched_yield();
    while (true)
      ;
  }

  CpuTraceAuxGenerator g(
      1,
      pid,
      -1,
      *builder->setBranch(true).setTsc(true).createHbtEventConf(
          "test_aux_cpu_generator"));
  g.open(16, CpuTraceAuxGenerator::AUXBufferMode::OVERWRITABLE);
  g.enable();
  ASSERT_TRUE(g.isEnabled());

  sleep(1);
  g.disable();
  // we should receive a itrace start perf event
  EXPECT_EQ(g.consume(1), 1);
  kill(pid, SIGKILL);
}

TEST(PerCpuTraceAuxGenerator, SmokeTest) {
  auto pmuManager = makePmuDeviceManager();
  assert(pmuManager != nullptr);
  auto builder = intel_pt::IptEventBuilder::createIptEventBuilder(*pmuManager);
  auto shm = mmap(
      nullptr,
      sizeof(std::atomic<char>),
      PROT_READ | PROT_WRITE,
      MAP_SHARED | MAP_ANONYMOUS,
      -1,
      0);
  ASSERT_NE(shm, MAP_FAILED);

  auto phase = new (shm) std::atomic<char>;
  *phase = 0;
  cpu_set_t cpu_set;

  auto pid = fork();
  ASSERT_GE(pid, 0) << "fork() failed with errno: " << errno << std::endl;

  if (pid == 0) {
    while (*phase == 0)
      ;
    CPU_ZERO(&cpu_set);
    CPU_SET(1, &cpu_set);
    ASSERT_EQ(sched_setaffinity(getpid(), sizeof(cpu_set), &cpu_set), 0)
        << "sched_setaffinity() failed with errno: " << errno << std::endl;
    sched_yield();
    spin(std::chrono::milliseconds(200));
    CPU_ZERO(&cpu_set);
    CPU_SET(2, &cpu_set);
    ASSERT_EQ(sched_setaffinity(getpid(), sizeof(cpu_set), &cpu_set), 0)
        << "sched_setaffinity() failed with errno: " << errno << std::endl;
    sched_yield();
    spin(std::chrono::milliseconds(200));
    *phase = 2;
    exit(0);
  }

  auto allCpus = CpuSet::makeAllOnline();
  PerCpuTraceAuxGenerator g(
      allCpus,
      pid,
      nullptr,
      *builder->setBranch(true).setTsc(true).createHbtEventConf(
          "test_aux_cpu_generator"));
  g.open(16, CpuTraceAuxGenerator::AUXBufferMode::OVERWRITABLE);
  g.enable();
  ASSERT_TRUE(g.isEnabled());

  *phase = 1;
  while (*phase == 1)
    ;

  size_t itraceStartEventCount = 0;
  for_each_cpu(cpu, allCpus) {
    auto& cpuG = g.getCpuGenerator(cpu);
    cpuG.consume(10);
    auto coreItraceStartNum = g.getCpuGenerator(cpu).getNumItraceStart();
    if (coreItraceStartNum > 0) {
      std::cout << "cpu " << cpu << ": " << coreItraceStartNum << std::endl;
    }
    itraceStartEventCount += coreItraceStartNum;
  }

  // cpu1 -> cpu2 -> cpu1
  EXPECT_GE(itraceStartEventCount, 2);

  g.disable();
  g.close();
}
