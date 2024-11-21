// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/BPerfEventsGroup.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"

#include <gtest/gtest.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

// TODO it's not guaranteed that a process in /sys/fs/cgroup/system.slice/ get
// scheduled during a 10ms window so change EXPECT_GT to EXPECT_GE for now. We
// should use a dedicated cgroup for testing in the future.
namespace {
void checkReading(
    struct bpf_perf_event_value* val,
    struct bpf_perf_event_value* prev,
    int n) {
  for (int i = 0; i < n; i++) {
    EXPECT_GE(val[i].counter, prev[i].counter);
    EXPECT_GE(val[i].enabled, prev[i].enabled);
    EXPECT_GE(val[i].running, prev[i].running);
  }
}
} // namespace

TEST(BPerfEventsGroupTest, RunSystemWide) {
  auto pmu_manager = makePmuDeviceManager();
  auto pmu = pmu_manager->findPmuDeviceByName("generic_hardware");
  auto ev_def = pmu_manager->findEventDef("cycles");
  if (!ev_def) {
    GTEST_SKIP() << "Cannot find event cycles";
  }
  auto ev_conf =
      pmu->makeConf(ev_def->id, EventExtraAttr(), EventValueTransforms());

  auto system = BPerfEventsGroup(EventConfs({ev_conf}), 0);
  struct bpf_perf_event_value val[BPERF_MAX_GROUP_SIZE];
  struct bpf_perf_event_value prev[BPERF_MAX_GROUP_SIZE] = {};
  if (!system.open() || !system.enable()) {
    GTEST_SKIP() << "Skip RunSystemWide test, do we have CAP_PERFMON?";
  }
  for (auto i = 0; i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto n = system.readGlobal(val);
    EXPECT_GT(n, 0);
    checkReading(val, prev, n);
    ::memcpy(prev, val, sizeof(prev));
  }

  std::map<int, std::array<struct bpf_perf_event_value, BPERF_MAX_GROUP_SIZE>>
      perCpuValues;
  auto n = system.readGlobalPerCpu(perCpuValues);
  EXPECT_GT(n, 0);
  EXPECT_EQ(perCpuValues.size(), CpuSet::makeAllOnline().numCpus());
  for (const auto& [cpu, values] : perCpuValues) {
    EXPECT_GE(values[0].counter, 0);
  }
}

TEST(BPerfEventsGroupTest, RunCgroup) {
  auto pmu_manager = makePmuDeviceManager();
  auto pmu = pmu_manager->findPmuDeviceByName("generic_hardware");
  auto cycles_def = pmu_manager->findEventDef("cycles");
  auto instructions_def = pmu_manager->findEventDef("instructions");
  if (!cycles_def || !instructions_def) {
    GTEST_SKIP() << "Cannot find event cycles/instructions";
  }
  auto cycles_conf =
      pmu->makeConf(cycles_def->id, EventExtraAttr(), EventValueTransforms());
  auto instructions_conf = pmu->makeConf(
      instructions_def->id, EventExtraAttr(), EventValueTransforms());
  auto cgrpFdPtr = std::make_shared<FdWrapper>("/sys/fs/cgroup/system.slice/");
  auto cgrp = BPerfEventsGroup(EventConfs({cycles_conf, instructions_conf}), 1);
  struct bpf_perf_event_value val[BPERF_MAX_GROUP_SIZE];
  struct bpf_perf_event_value prev[BPERF_MAX_GROUP_SIZE] = {};

  if (!cgrp.open() || !cgrp.enable()) {
    GTEST_SKIP() << "Skip RunCgroup test, do we have CAP_PERFMON?";
  }

  cgrp.addCgroup(cgrpFdPtr, 1);

  cgrp.disable();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  cgrp.enable();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  for (auto i = 0; i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto n = cgrp.readCgroup(val, cgrpFdPtr->getInode());
    EXPECT_GT(n, 0);
    checkReading(val, prev, n);
    ::memcpy(prev, val, sizeof(prev));
  }
}

TEST(BPerfEventsGroupTest, MetricConstructor) {
  auto pmu_manager = makePmuDeviceManager();
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

  auto eg = BPerfEventsGroup(*m, *pmu_manager, 0);
  if (!eg.open() || !eg.enable()) {
    GTEST_SKIP() << "Skip RunSystemWide test, do we have CAP_PERFMON?";
  }
  struct bpf_perf_event_value val[BPERF_MAX_GROUP_SIZE];
  struct bpf_perf_event_value prev[BPERF_MAX_GROUP_SIZE] = {};
  for (auto i = 0; i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto n = eg.readGlobal(val);
    EXPECT_GT(n, 0);
    checkReading(val, prev, n);
    ::memcpy(prev, val, sizeof(prev));
  }
}

TEST(BPerfEventsGroupTest, EnableDisable) {
  auto pmu_manager = makePmuDeviceManager();
  auto pmu = pmu_manager->findPmuDeviceByName("generic_hardware");
  auto cycles_def = pmu_manager->findEventDef("cycles");
  auto instructions_def = pmu_manager->findEventDef("instructions");
  if (!cycles_def || !instructions_def) {
    GTEST_SKIP() << "Cannot find event cycles/instructions";
  }
  auto cycles_conf =
      pmu->makeConf(cycles_def->id, EventExtraAttr(), EventValueTransforms());
  auto instructions_conf = pmu->makeConf(
      instructions_def->id, EventExtraAttr(), EventValueTransforms());
  auto eg = BPerfEventsGroup(EventConfs({cycles_conf, instructions_conf}), 0);
  struct bpf_perf_event_value val[BPERF_MAX_GROUP_SIZE] = {};
  struct bpf_perf_event_value prev[BPERF_MAX_GROUP_SIZE] = {};

  if (!eg.open()) {
    GTEST_SKIP() << "Skip RunCgroup test, do we have CAP_PERFMON?";
  }

  EXPECT_TRUE(eg.enable());
  EXPECT_TRUE(eg.enable());
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  eg.disable();
  eg.readGlobal(prev);
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  eg.readGlobal(val);

  EXPECT_EQ(prev[0].counter, val[0].counter);
  EXPECT_EQ(prev[0].enabled, val[0].enabled);
  EXPECT_EQ(prev[0].running, val[0].running);
}

TEST(BPerfEventsGroupTest, cgroup_update_level) {
  auto pmu_manager = makePmuDeviceManager();
  auto pmu = pmu_manager->findPmuDeviceByName("generic_hardware");
  auto cycles_def = pmu_manager->findEventDef("cycles");
  auto instructions_def = pmu_manager->findEventDef("instructions");
  if (!cycles_def || !instructions_def) {
    GTEST_SKIP() << "Cannot find event cycles/instructions";
  }
  auto cycles_conf =
      pmu->makeConf(cycles_def->id, EventExtraAttr(), EventValueTransforms());
  auto instructions_conf = pmu->makeConf(
      instructions_def->id, EventExtraAttr(), EventValueTransforms());
  auto cgrpFdPtr = std::make_shared<FdWrapper>("/sys/fs/cgroup/system.slice/");
  auto cgrp = BPerfEventsGroup(EventConfs({cycles_conf, instructions_conf}), 2);

  if (!cgrp.open() || !cgrp.enable()) {
    GTEST_SKIP() << "Skip RunCgroup test, do we have CAP_PERFMON?";
  }

  EXPECT_FALSE(cgrp.addCgroup(cgrpFdPtr, 1))
      << "BPerfEvents should only be able to track cgroup at level 3";
}
