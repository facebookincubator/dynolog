// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/BuiltinMetrics.h"
#include "hbt/src/perf_event/PerCpuCountSampleGenerator.h"

#include <fmt/ostream.h>
#include <gtest/gtest.h>

using namespace facebook::hbt::perf_event;

class BuiltinMetricsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    pmu_manager = makePmuDeviceManager();
    metrics = makeAvailableMetrics();
  }

  std::shared_ptr<PmuDeviceManager> pmu_manager;
  std::shared_ptr<Metrics> metrics;
};

TEST_F(BuiltinMetricsTest, Init) {
  EXPECT_GT(pmu_manager->getNumPmus(), 0);
  const auto& descs = metrics->getMetricDescs();
  EXPECT_GE(descs.size(), 3) << "Have at least ipc, page_faults and topdown";
  for (const auto& [k, d] : descs) {
    EXPECT_GT(d->brief_desc.size(), 0);
    EXPECT_GT(d->full_desc.size(), 0);
    EXPECT_GT(d->default_sampling_period, 0);
  }
  auto ipc_desc = metrics->getMetricDesc("ipc");
  EXPECT_EQ(ipc_desc->id, "ipc");
  EXPECT_EQ(ipc_desc->event_refs_by_arch.size(), 1);
  auto cpuInfo = pmu_manager->cpuInfo;
  HBT_LOG_INFO() << fmt::format(
      "CpuInfo: {} CpuArch: {}", cpuInfo, cpuInfo.cpu_arch);
  EXPECT_EQ(ipc_desc->event_refs_by_arch.at(std::nullopt).size(), 2);
}

TEST_F(BuiltinMetricsTest, HwCacheEvents) {
  // -- test for hw cache events
  auto l1_dcache_load_hits = pmu_manager->findEventDef(
      "l1_dcache_load_hits", std::nullopt, "generic_hw_cache");
  EXPECT_NE(l1_dcache_load_hits, nullptr);
  auto dtlb_load_misses =
      pmu_manager->findEventDef("dTLB-load-misses", std::nullopt);
  EXPECT_NE(dtlb_load_misses, nullptr);
  auto llc_load_misses =
      pmu_manager->findEventDef("LLC-load-misses", std::nullopt);
  EXPECT_NE(llc_load_misses, nullptr);
  uint64_t l1_cache_encoding = (PERF_COUNT_HW_CACHE_L1D) |
      (PERF_COUNT_HW_CACHE_OP_READ << 8) |
      (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);
  EXPECT_EQ(l1_dcache_load_hits->encoding.code, l1_cache_encoding);
  EXPECT_EQ(
      l1_dcache_load_hits->full_desc, "Level 1 data cache load operation hits");
  EXPECT_EQ(l1_dcache_load_hits->isPrecise(), std::nullopt);
}

TEST_F(BuiltinMetricsTest, HwEvents) {
  // -- test for hw events
  auto instructions =
      pmu_manager->findEventDef("instructions", PmuType::generic_hardware);
  EXPECT_NE(instructions, nullptr);
  auto cpu_cycles =
      pmu_manager->findEventDef("cpu_cycles", PmuType::generic_hardware);
  EXPECT_NE(cpu_cycles, nullptr);
  auto cache_references =
      pmu_manager->findEventDef("cache_references", PmuType::generic_hardware);
  EXPECT_NE(cache_references, nullptr);
  auto cache_misses =
      pmu_manager->findEventDef("cache-misses", PmuType::generic_hardware);
  EXPECT_NE(cache_misses, nullptr);
  auto branch_instructions = pmu_manager->findEventDef(
      "branch_instructions", PmuType::generic_hardware);
  EXPECT_NE(branch_instructions, nullptr);
  auto bus_cycles =
      pmu_manager->findEventDef("bus_cycles", PmuType::generic_hardware);
  EXPECT_NE(bus_cycles, nullptr);
  auto branch_misses =
      pmu_manager->findEventDef("branch-misses", PmuType::generic_hardware);
  EXPECT_NE(branch_misses, nullptr);
  auto bus_cycles_hyphen =
      pmu_manager->findEventDef("bus-cycles", PmuType::generic_hardware);
  EXPECT_NE(bus_cycles_hyphen, nullptr);
  auto branch_instructions_hyphen = pmu_manager->findEventDef(
      "branch-instructions", PmuType::generic_hardware);
  EXPECT_NE(branch_instructions_hyphen, nullptr);
  auto cache_references_hyphen =
      pmu_manager->findEventDef("cache-references", PmuType::generic_hardware);
  EXPECT_NE(cache_references_hyphen, nullptr);
  auto retired_instructions = pmu_manager->findEventDef(
      "retired_instructions", PmuType::generic_hardware);
  EXPECT_NE(retired_instructions, nullptr);
  auto ref_cycles =
      pmu_manager->findEventDef("ref-cycles", PmuType::generic_hardware);
  EXPECT_NE(ref_cycles, nullptr);
  auto stalled_cycles_frontend = pmu_manager->findEventDef(
      "stalled-cycles-frontend", PmuType::generic_hardware);
  EXPECT_NE(stalled_cycles_frontend, nullptr);
  auto stalled_cycles_backend = pmu_manager->findEventDef(
      "stalled-cycles-frontend", PmuType::generic_hardware);
  EXPECT_NE(stalled_cycles_frontend, nullptr);
}

TEST_F(BuiltinMetricsTest, SwEvents) {
  // -- test for sw events
  auto task_clock = pmu_manager->findEventDef("task_clock", PmuType::software);
  EXPECT_NE(task_clock, nullptr);
  auto context_switches =
      pmu_manager->findEventDef("context-switches", PmuType::software);
  EXPECT_NE(context_switches, nullptr);
  auto task_clock_hyphen =
      pmu_manager->findEventDef("task-clock", PmuType::software);
  EXPECT_NE(task_clock_hyphen, nullptr);
  auto cpu_migrations =
      pmu_manager->findEventDef("cpu-migrations", PmuType::software);
  EXPECT_NE(cpu_migrations, nullptr);
  auto minor_faults =
      pmu_manager->findEventDef("minor-faults", PmuType::software);
  EXPECT_NE(minor_faults, nullptr);
  auto major_faults =
      pmu_manager->findEventDef("major-faults", PmuType::software);
  EXPECT_NE(major_faults, nullptr);
  auto alignment_faults =
      pmu_manager->findEventDef("alignment-faults", PmuType::software);
  EXPECT_NE(alignment_faults, nullptr);
  auto emulation_faults =
      pmu_manager->findEventDef("emulation-faults", PmuType::software);
  EXPECT_NE(emulation_faults, nullptr);
  auto page_faults =
      pmu_manager->findEventDef("page-faults", PmuType::software);
  EXPECT_NE(page_faults, nullptr);
  auto cpu_clock = pmu_manager->findEventDef("cpu_clock", PmuType::software);
  EXPECT_NE(cpu_clock, nullptr);
  auto cpu_clock_hyphen =
      pmu_manager->findEventDef("cpu-clock", PmuType::software);
  EXPECT_NE(cpu_clock_hyphen, nullptr);
}

TEST_F(BuiltinMetricsTest, TracepointEvents) {
  // -- test for tracepoint events
  /*
   * XXX: Temporarily disable because this test requires
   * tracing capabilities that are not always present in SandCastle.
  auto tracepoint = pmu_manager->findEventDef("syscalls:sys_enter_mmap",
  PmuType::tracepoint); EXPECT_NE(tracepoint, nullptr); tracepoint =
  pmu_manager->findEventDef("syscalls:sys_enter_clone", PmuType::tracepoint);
  EXPECT_NE(tracepoint, nullptr);
  tracepoint = pmu_manager->findEventDef("exceptions:page_fault_user",
  PmuType::tracepoint); EXPECT_NE(tracepoint, nullptr); tracepoint =
  pmu_manager->findEventDef("irq:softirq_entry", PmuType::tracepoint);
  EXPECT_NE(tracepoint, nullptr);
  tracepoint = pmu_manager->findEventDef("migrate:mm_migrate_pages",
  PmuType::tracepoint); EXPECT_NE(tracepoint, nullptr); tracepoint =
  pmu_manager->findEventDef("net:netif_receive_skb_entry", PmuType::tracepoint);
  EXPECT_NE(tracepoint, nullptr);
  tracepoint = pmu_manager->findEventDef("net:net_dev_start_xmit",
  PmuType::tracepoint); EXPECT_NE(tracepoint, nullptr); tracepoint =
  pmu_manager->findEventDef("random:urandom_read", PmuType::tracepoint);
  EXPECT_NE(tracepoint, nullptr);
  tracepoint = pmu_manager->findEventDef("sched:sched_switch",
  PmuType::tracepoint); EXPECT_NE(tracepoint, nullptr); tracepoint =
  pmu_manager->findEventDef("sched:sched_wakeup", PmuType::tracepoint);
  EXPECT_NE(tracepoint, nullptr);
  tracepoint = pmu_manager->findEventDef("tlb:tlb_flush", PmuType::tracepoint);
  EXPECT_NE(tracepoint, nullptr);
  tracepoint = pmu_manager->findEventDef("workqueue:workqueue_queue_work",
  PmuType::tracepoint); EXPECT_NE(tracepoint, nullptr); tracepoint =
  pmu_manager->findEventDef("workqueue:workqueue_execute_start",
  PmuType::tracepoint); EXPECT_NE(tracepoint, nullptr); tracepoint =
  pmu_manager->findEventDef("xfs:xfs_extent_busy", PmuType::tracepoint);
  EXPECT_NE(tracepoint, nullptr);
  */
}

TEST_F(BuiltinMetricsTest, CanonicalEventName) {
  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "Dummy-EVENT",
      EventDef::Encoding{.code = PERF_COUNT_HW_BRANCH_MISSES},
      "Dummy event for testing canonical name.",
      "Dummy event for testing canonical name."));
  auto dummy_event = pmu_manager->findEventDef(
      "dummy_event", std::nullopt, "generic_hardware");
  EXPECT_NE(dummy_event, nullptr);
  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "dummy-event2",
      EventDef::Encoding{.code = PERF_COUNT_HW_BRANCH_MISSES},
      "Dummy event2 for testing canonical name.",
      "Dummy event2 for testing canonical name."));
  // test duplicated aliases would not fail
  std::vector<EventId> aliases = {"alias", "alias"};
  pmu_manager->addAliases("dummy-event2", aliases);
  auto dummy_event2 = pmu_manager->findEventDef("dummy_event2");
  EXPECT_NE(dummy_event2, nullptr);
  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "DUMMYEVENT3",
      EventDef::Encoding{.code = PERF_COUNT_HW_BRANCH_MISSES},
      "Dummy event3 for testing canonical name.",
      "Dummy event3 for testing canonical name."));
  auto dummy_event3 = pmu_manager->findEventDef("dummyevent3");
  EXPECT_NE(dummy_event3, nullptr);
  // test when user enters non-canonical event alias
  auto dummy_event4 = pmu_manager->findEventDef("dummyEvent3");
  EXPECT_NE(dummy_event4, nullptr);
}

TEST_F(BuiltinMetricsTest, PerfEventAttrPrecise) {
  auto ev_def = pmu_manager->findEventDef("cycles");
  EXPECT_TRUE(ev_def != nullptr);
  EXPECT_EQ(ev_def->id, "cpu_cycles");
  EXPECT_EQ(ev_def->isPrecise(), std::nullopt);

  auto ipc_desc = metrics->getMetricDesc("ipc");
  EXPECT_EQ(ipc_desc->id, "ipc");

  // A map of CPU ID: Event Configuration.
  PerCpuEventConfs per_cpu_confs;

  // Set CPU 0. An alternative is to use CpuSet.
  cpu_set_t cpus;
  CPU_ZERO(&cpus);
  CPU_SET(0, &cpus);

  // Build the event configuration for each CPU in mon_cpus.
  pmu_manager->makePerCpuConfs(
      ev_def->pmu_type,
      ev_def->id,
      // Make it track user-space only.
      EventExtraAttr::makeUserOnly(PreciseIpLevel::kRequireZeroSkid),
      // No transformations for values.
      EventValueTransforms(),
      cpus,
      per_cpu_confs);

  // One event.
  EXPECT_EQ(per_cpu_confs.size(), 1);

  // Event at CPU 0.
  auto ev_conf = per_cpu_confs[0];

  struct perf_event_attr attr;
  CpuCountSampleGenerator::init_perf_event_attrs(
      {ev_conf}, 1'000'000, &attr, true);

  // Verify that perf_event_attr was set correctly.
  EXPECT_EQ(attr.type, PERF_TYPE_HARDWARE);
  EXPECT_EQ(attr.sample_period, 1'000'000);
  EXPECT_EQ(attr.precise_ip, 3);
}

TEST_F(BuiltinMetricsTest, PerfEventAttrPreciseJson) {
  if (facebook::hbt::CpuInfo::load().cpu_family != CpuFamily::INTEL) {
    GTEST_SKIP() << "Unsupported cpu_family "
                 << facebook::hbt::CpuInfo::load().cpu_family
                 << " (run this test on Intel)";
  }

  auto ev_def = pmu_manager->findEventDef("UOPS_RETIRED.ALL");
  if (!ev_def) {
    ev_def = pmu_manager->findEventDef("UOPS_RETIRED.RETIRE_SLOTS");
  }

  ASSERT_TRUE(ev_def != nullptr);
  EXPECT_TRUE(
      ev_def->id == "UOPS_RETIRED.ALL" ||
      ev_def->id == "UOPS_RETIRED.RETIRE_SLOTS");

  // UOPS_RETIRED.RETIRE_SLOTS is only precise on systems where UOPS_RETIRED.ALL
  // is already present.
  EXPECT_EQ(
      ev_def->isPrecise(), ev_def->id == "UOPS_RETIRED.ALL" ? true : false);

  // A map of CPU ID: Event Configuration.
  PerCpuEventConfs per_cpu_confs;

  // Set CPU 0. An alternative is to use CpuSet.
  cpu_set_t cpus;
  CPU_ZERO(&cpus);
  CPU_SET(0, &cpus);

  // Build the event configuration for each CPU in mon_cpus.
  pmu_manager->makePerCpuConfs(
      ev_def->pmu_type,
      ev_def->id,
      // Make it track user-space only.
      EventExtraAttr::makeUserOnly(PreciseIpLevel::kRequireZeroSkid),
      // No transformations for values.
      EventValueTransforms(),
      cpus,
      per_cpu_confs);

  // One event.
  EXPECT_EQ(per_cpu_confs.size(), 1);

  // Event at CPU 0.
  auto ev_conf = per_cpu_confs[0];

  struct perf_event_attr attr;
  CpuCountSampleGenerator::init_perf_event_attrs(
      {ev_conf}, 1'000'000, &attr, false);

  // Verify that perf_event_attr was set correctly.
  EXPECT_EQ(attr.type, PERF_TYPE_RAW);
  EXPECT_EQ(attr.sample_period, 1'000'000);
  EXPECT_EQ(attr.precise_ip, 3);
}

TEST_F(BuiltinMetricsTest, LibPfm4) {
  // Get generic events.
  auto hw_pmu = pmu_manager->findPmuDeviceByName("generic_hardware");
  EXPECT_TRUE(hw_pmu != nullptr);
  auto generic_events = hw_pmu->makeLibPfm4Groups();
  EXPECT_GT(generic_events->size(), 8);
  // Get raw events (like Intel JSON ones).
  auto cpu_pmu = pmu_manager->findPmuDeviceByName("cpu");
  EXPECT_TRUE(cpu_pmu != nullptr);
  auto raw_events = cpu_pmu->makeLibPfm4Groups();
  EXPECT_GT(raw_events->size(), 60);
}

TEST_F(BuiltinMetricsTest, IntelPtPmu) {
  auto ipt_pmu = pmu_manager->findPmuDeviceByName("intel_pt");
  if (!ipt_pmu) {
    HBT_LOG_WARNING() << "Skip IntelPtPmu test as machine doesn't support";
    return;
  }
  EXPECT_TRUE(ipt_pmu->inSysFs());
  EXPECT_FALSE(ipt_pmu->format.empty());
  EXPECT_FALSE(ipt_pmu->caps.empty());
  // "pt" format entry should present if intel pt feature is supported.
  EXPECT_EQ(ipt_pmu->format.count("pt"), 1);
  EXPECT_EQ(ipt_pmu->format["pt"].name, "pt");
  EXPECT_EQ(ipt_pmu->format["pt"].type, PmuDevice::ConfigType::config);
  EXPECT_EQ(ipt_pmu->format["pt"].msb, 0);
}

TEST_F(BuiltinMetricsTest, IntelPtDefaultEvent) {
  auto ipt_pmu = pmu_manager->findPmuDeviceByName("intel_pt");
  if (!ipt_pmu) {
    HBT_LOG_WARNING() << "Skip IntelPtPmu test as machine doesn't support";
    return;
  }
  auto eventDefPtr = ipt_pmu->findEventDef("ipt-default");
  ASSERT_TRUE(eventDefPtr);

  auto eventConfig = eventDefPtr->makeConfigs(ipt_pmu->getPmuId());
  EXPECT_NE(eventConfig.config, 0x0);
}
