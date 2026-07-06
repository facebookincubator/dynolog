// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PerCpuCountSampleGenerator.h"

#include <gtest/gtest.h>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

class PmuDevicesTest : public ::testing::Test {};

auto default_pmu_manager() {
  // Load CPU Info
  auto cpu_info = CpuInfo::load();
  auto pmu_manager = std::make_shared<PmuDeviceManager>(cpu_info);
  EXPECT_EQ(pmu_manager->getNumPmus(), 0);

  // Create a PMU.
  auto pmu = std::make_shared<PmuDevice>(
      "dummy_pmu",
      PmuType::software,
      std::nullopt,
      PERF_TYPE_SOFTWARE,
      "A Dummy PMU device",
      true);
  // Create an event.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy_event", // Event ID,
          EventDef::Encoding{
              .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
          "dummy brief desc",
          "dummy full desc"));

  // Create an event with aliases.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy_event_2", // Event ID,
          EventDef::Encoding{
              .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
          "dummy brief desc",
          "dummy full desc"),
      std::vector<EventId>({"alias1", "alias-2"}));
  pmu_manager->addPmu(pmu);
  return pmu_manager;
}

TEST_F(PmuDevicesTest, Init) {
  auto pmu_manager = default_pmu_manager();
  EXPECT_EQ(pmu_manager->getNumPmus(), 1);
}

TEST_F(PmuDevicesTest, EventRegistration) {
  // Load CPU Info
  auto cpu_info = CpuInfo::load();
  auto pmu_manager = std::make_shared<PmuDeviceManager>(cpu_info);
  auto pmu = std::make_shared<PmuDevice>(
      "dummy_pmu",
      PmuType::software,
      std::nullopt,
      PERF_TYPE_SOFTWARE,
      "A Dummy PMU device",
      false);
  pmu_manager->addPmu(pmu);

  // An event with an invalid name.
  ASSERT_THROW(
      pmu->addEvent(
          std::make_unique<EventDef>(
              PmuType::software,
              "dummy_ev ent", // Event ID,
              EventDef::Encoding{
                  .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
              "dummy brief desc",
              "dummy full desc")),
      std::invalid_argument);

  // Create an event.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy_event", // Event ID,
          EventDef::Encoding{
              .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
          "dummy brief desc",
          "dummy full desc"));

  ASSERT_THROW(
      pmu->addEvent(
          std::make_unique<EventDef>(
              PmuType::software,
              "dummy_event", // Event ID,
              EventDef::Encoding{
                  .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
              "dummy brief desc",
              "dummy full desc")),
      std::invalid_argument);

  // Find the event definition, the PMU name is optional.
  // Passing it makes the search faster (e.g. "cpu").
  auto ev_def = pmu_manager->findEventDef("dummy_event", std::nullopt);
  EXPECT_TRUE(ev_def != nullptr);

  // Default alias with dash instead of underscore.
  ev_def = pmu_manager->findEventDef("dummy-event", std::nullopt);
  EXPECT_TRUE(ev_def != nullptr);
  EXPECT_EQ(ev_def->id, "dummy_event");
}

TEST_F(PmuDevicesTest, FindingEvents) {
  auto pmu_manager = default_pmu_manager();
  // An invalid event name.
  auto ev_def =
      pmu_manager->findEventDef("an_event_that_doesntexist", std::nullopt);
  EXPECT_TRUE(ev_def == nullptr);

  // An valid name in an invalid pmu name.
  ev_def = pmu_manager->findEventDef(
      "cpu_cycles", std::nullopt, "an_invalid_pmu_name");
  EXPECT_TRUE(ev_def == nullptr);

  // A valid name in an invalid pmu name.
  ev_def = pmu_manager->findEventDef(
      "cpu-cycles", std::nullopt, "an_invalid_pmu_name");
  EXPECT_TRUE(ev_def == nullptr);
}

TEST_F(PmuDevicesTest, Aliases) {
  auto pmu_manager = default_pmu_manager();
  // Test aliases.
  auto ev_def_alias1 = pmu_manager->findEventDef("alias1", std::nullopt);
  EXPECT_TRUE(ev_def_alias1 != nullptr);
  auto ev_def_alias2 = pmu_manager->findEventDef("alias-2", std::nullopt);
  EXPECT_TRUE(ev_def_alias2 != nullptr);
  EXPECT_EQ(ev_def_alias1->id, ev_def_alias2->id);
}

TEST_F(PmuDevicesTest, PerfEventAttr) {
  // Load CPU Info
  auto cpu_info = CpuInfo::load();
  auto pmu_manager = std::make_shared<PmuDeviceManager>(cpu_info);
  // Create a PMU.
  auto pmu = std::make_shared<PmuDevice>(
      "dummy_pmu",
      PmuType::software,
      std::nullopt,
      PERF_TYPE_SOFTWARE,
      "A Dummy PMU device",
      true);
  pmu_manager->addPmu(pmu);

  // Create an event.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy_event", // Event ID,
          EventDef::Encoding{
              .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
          "dummy brief desc",
          "dummy full desc"));

  auto ev_def = pmu_manager->findEventDef("dummy-event", std::nullopt);
  EXPECT_TRUE(ev_def != nullptr);
  // Got event through alias, this is the real event name.
  EXPECT_EQ(ev_def->id, "dummy_event");

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
      EventExtraAttr::makeUserOnly(),
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
  EXPECT_EQ(attr.type, PERF_TYPE_SOFTWARE);
  EXPECT_EQ(attr.sample_period, 1'000'000);
  EXPECT_EQ(attr.precise_ip, 0);
}

TEST_F(PmuDevicesTest, PerfEventAttrPrecise) {
  // Load CPU Info
  auto cpu_info = CpuInfo::load();
  auto pmu_manager = std::make_shared<PmuDeviceManager>(cpu_info);
  EXPECT_EQ(pmu_manager->getNumPmus(), 0);

  // Create a PMU.
  auto pmu = std::make_shared<PmuDevice>(
      "dummy_pmu",
      PmuType::software,
      std::nullopt,
      PERF_TYPE_SOFTWARE,
      "A Dummy PMU device",
      false);
  pmu_manager->addPmu(pmu);

  // Create an event.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy_event", // Event ID,
          EventDef::Encoding{
              .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
          "dummy brief desc",
          "dummy full desc"));

  auto ev_def = pmu_manager->findEventDef("dummy-event", std::nullopt);
  EXPECT_TRUE(ev_def != nullptr);
  EXPECT_EQ(ev_def->id, "dummy_event");

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
  EXPECT_EQ(attr.type, PERF_TYPE_SOFTWARE);
  EXPECT_EQ(attr.sample_period, 1'000'000);
  EXPECT_EQ(attr.precise_ip, 3);
}

TEST_F(PmuDevicesTest, LibPfm4Groups) {
  // Load CPU Info
  auto cpu_info = CpuInfo::load();
  auto pmu_manager = std::make_shared<PmuDeviceManager>(cpu_info);

  // A PMU that makes no sense (CPU and software), but
  // does not fail because it is not really used.
  auto pmu = std::make_shared<PmuDevice>(
      "dummy_pmu",
      PmuType::cpu,
      1,
      PERF_TYPE_SOFTWARE,
      "A Dummy PMU device",
      true);
  pmu_manager->addPmu(pmu);

  // Create an event.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy.event0", // Event ID,
          EventDef::Encoding{
              .code = 10, .umask = 0x3, .inv = true, .cmask = 0xcc},
          "desc; ev0",
          "dummy full desc"));

  // Create an event.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy.event1", // Event ID,
          EventDef::Encoding{
              .code = 10, .umask = 0x4, .inv = false, .cmask = 0xcc},
          "desc; ev1",
          "dummy full desc"));

  // Create an event.
  pmu->addEvent(
      std::make_unique<EventDef>(
          PmuType::software,
          "dummy.nosamegroup", // Event ID,
          EventDef::Encoding{
              .code = 11, .umask = 0x4, .inv = false, .cmask = 0xcc},
          "desc other group",
          "dummy full desc"));

  {
    auto ev_def = pmu_manager->findEventDef("dummy.event0", std::nullopt);
    EXPECT_TRUE(ev_def != nullptr);
    EXPECT_EQ(ev_def->id, "dummy.event0");
    EXPECT_EQ(ev_def->encoding.code, 10);
    EXPECT_EQ(ev_def->encoding.umask, 0x3);
    EXPECT_EQ(ev_def->encoding.inv, true);
    EXPECT_EQ(ev_def->encoding.cmask, 0xcc);
  }
  {
    auto ev_def = pmu_manager->findEventDef("dummy.event1", std::nullopt);
    EXPECT_TRUE(ev_def != nullptr);
    EXPECT_EQ(ev_def->id, "dummy.event1");
    EXPECT_EQ(ev_def->encoding.code, 10);
    EXPECT_EQ(ev_def->encoding.umask, 0x4);
    EXPECT_EQ(ev_def->encoding.inv, false);
    EXPECT_EQ(ev_def->encoding.cmask, 0xcc);
  }
  {
    // Event with same name preffix but different code will
    // be added to a different group with name made of name preffix __ code
    auto ev_def = pmu_manager->findEventDef("dummy.nosamegroup", std::nullopt);
    EXPECT_TRUE(ev_def != nullptr);
    EXPECT_EQ(ev_def->id, "dummy.nosamegroup");
    EXPECT_EQ(ev_def->encoding.code, 11);
    EXPECT_EQ(ev_def->encoding.umask, 0x4);
    EXPECT_EQ(ev_def->encoding.inv, false);
    EXPECT_EQ(ev_def->encoding.cmask, 0xcc);
  }

  auto qpmu = pmu_manager->findPmuDeviceByName("dummy_pmu");
  EXPECT_EQ(qpmu.get(), pmu.get());
  auto groups = qpmu->makeLibPfm4Groups();
  EXPECT_EQ(groups->size(), 2);

  const auto& g0 = groups->at("dummy");
  EXPECT_EQ(g0.key, "dummy");
  EXPECT_EQ(g0.code, 10);
  EXPECT_EQ(g0.getDescription(), "desc");
  EXPECT_EQ(g0.ev_defs.size(), 2);

  const auto& g1 = groups->at("dummy__11");
  EXPECT_EQ(g1.key, "dummy__11");
  EXPECT_EQ(g1.code, 11);
  EXPECT_EQ(g1.getDescription(), "desc other group");
  EXPECT_EQ(g1.ev_defs.size(), 1);
}

// --- Vera-Rubin uncore PMU support ---

TEST_F(PmuDevicesTest, VeraPmuTypeRoundTrip) {
  const std::vector<std::pair<PmuType, std::string>> expected{
      {PmuType::nvidia_ucf_pmu, "nvidia_ucf_pmu"},
      {PmuType::nvidia_nvlink_c2c_pmu, "nvidia_nvlink_c2c_pmu"},
      {PmuType::nvidia_cmem_latency_pmu, "nvidia_cmem_latency_pmu"},
      {PmuType::nvidia_nvclink_pmu, "nvidia_nvclink_pmu"},
      {PmuType::nvidia_nvdlink_pmu, "nvidia_nvdlink_pmu"},
      {PmuType::nvidia_pcie_tgt_pmu, "nvidia_pcie_tgt_pmu"},
  };
  for (const auto& [type, name] : expected) {
    EXPECT_EQ(PmuTypeToStr(type), name);
    EXPECT_EQ(PmuTypeFromStr(name), type);
  }
}

TEST_F(PmuDevicesTest, ParseVeraDeviceNames) {
  // Regular single-index devices (per-socket suffix).
  {
    auto [type, id] = parseDeviceTypeFromStr("nvidia_ucf_pmu_0");
    EXPECT_EQ(type, PmuType::nvidia_ucf_pmu);
    EXPECT_EQ(id, std::optional<uint32_t>(0));
  }
  {
    auto [type, id] = parseDeviceTypeFromStr("nvidia_nvlink_c2c_pmu_1");
    EXPECT_EQ(type, PmuType::nvidia_nvlink_c2c_pmu);
    EXPECT_EQ(id, std::optional<uint32_t>(1));
  }
  // Per-root-complex devices: <pmu>_<socket>_rc_<rc> -> enum = socket * 64 +
  // rc.
  {
    auto [type, id] = parseDeviceTypeFromStr("nvidia_pcie_pmu_0_rc_0");
    EXPECT_EQ(type, PmuType::nvidia_pcie_pmu);
    EXPECT_EQ(id, std::optional<uint32_t>(0));
  }
  {
    auto [type, id] = parseDeviceTypeFromStr("nvidia_pcie_pmu_0_rc_3");
    EXPECT_EQ(type, PmuType::nvidia_pcie_pmu);
    EXPECT_EQ(id, std::optional<uint32_t>(3));
  }
  {
    auto [type, id] = parseDeviceTypeFromStr("nvidia_pcie_tgt_pmu_1_rc_5");
    EXPECT_EQ(type, PmuType::nvidia_pcie_tgt_pmu);
    EXPECT_EQ(id, std::optional<uint32_t>(1u * 64 + 5));
  }
  // Unrecognized PMU type still throws (unchanged behavior).
  EXPECT_THROW(
      parseDeviceTypeFromStr("not_a_real_pmu_0_rc_0"), std::invalid_argument);
}

TEST_F(PmuDevicesTest, VeraCpuArchMapping) {
  // Vera (VR200 / Vera-Rubin): NVIDIA implementer 0x4E, part 0x010.
  EXPECT_EQ(makeCpuArchArm(0x4E, 0, 0x010, 0), CpuArch::NEOVERSE_V2);
  // Unknown NVIDIA part number -> UNKNOWN.
  EXPECT_EQ(makeCpuArchArm(0x4E, 0, 0x999, 0), CpuArch::UNKNOWN);
  // Regression: Arm-implemented Neoverse V2 (Grace-Hopper) still maps.
  EXPECT_EQ(makeCpuArchArm(0x41, 0, 0xD4F, 0), CpuArch::NEOVERSE_V2);
}
