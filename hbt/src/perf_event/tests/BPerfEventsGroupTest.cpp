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

namespace {
void checkReading(
    struct bpf_perf_event_value* val,
    struct bpf_perf_event_value* prev,
    int n) {
  for (int i = 0; i < n; i++) {
    EXPECT_GT(val[i].counter, prev[i].counter);
    EXPECT_GT(val[i].enabled, prev[i].enabled);
    EXPECT_GT(val[i].running, prev[i].running);
  }
}
} // namespace

TEST(BPerfEventsGroupTest, attr_map_path) {
  auto attr_map_path = BPerfEventsGroup::attrMapPath();

  EXPECT_EQ(attr_map_path.find("/sys/fs/bpf/bperf_attr_map_v"), 0);
}

TEST(BPerfEventsGroupTest, RunSystemWide) {
  auto pmu_manager = makePmuDeviceManager();
  auto pmu = pmu_manager->findPmuDeviceByName("generic_hardware");
  auto ev_def = pmu_manager->findEventDef("cycles");
  if (!ev_def) {
    GTEST_SKIP() << "Cannot find event cycles";
  }
  auto ev_conf =
      pmu->makeConf(ev_def->id, EventExtraAttr(), EventValueTransforms());

  auto system = BPerfEventsGroup(
      "cycles", EventConfs({ev_conf}), BPerfEventType::SystemWide, 0);
  struct bpf_perf_event_value val[BPERF_MAX_GROUP_SIZE];
  struct bpf_perf_event_value prev[BPERF_MAX_GROUP_SIZE] = {};

  if (!system.enable()) {
    GTEST_SKIP() << "Skip RunSystemWide test, do we have CAP_PERFMON?";
  }
  for (auto i = 0; i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto n = system.read(val);
    EXPECT_GT(n, 0);
    checkReading(val, prev, n);
    ::memcpy(prev, val, sizeof(prev));
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
  __u64 ino = FdWrapper("/sys/fs/cgroup/system.slice/").getInode();
  auto cgrp = BPerfEventsGroup(
      "ipc",
      EventConfs({cycles_conf, instructions_conf}),
      BPerfEventType::Cgroup,
      ino);
  struct bpf_perf_event_value val[BPERF_MAX_GROUP_SIZE];
  struct bpf_perf_event_value prev[BPERF_MAX_GROUP_SIZE] = {};

  if (!cgrp.enable()) {
    GTEST_SKIP() << "Skip RunCgroup test, do we have CAP_PERFMON?";
  }

  cgrp.disable();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  cgrp.enable();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  for (auto i = 0; i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto n = cgrp.read(val);
    EXPECT_GT(n, 0);
    checkReading(val, prev, n);
    ::memcpy(prev, val, sizeof(prev));
  }
}
