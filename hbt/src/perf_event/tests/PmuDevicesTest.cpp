// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PerCpuCountSampleGenerator.h"

#include <gtest/gtest.h>

#include <array>
#include <future>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

namespace {

constexpr std::array<StaticEventDef, 3> kStaticSoftwareEvents{{
    {
        .pmu_type = PmuType::software,
        .id = "STATIC-ALPHA",
        .encoding = {.code = 0x11},
        .brief_desc = "static alpha",
        .full_desc = "static alpha full",
    },
    {
        .pmu_type = PmuType::software,
        .id = "STATIC_BRAVO",
        .encoding = {.code = 0x22, .msr_values = uint64_t{0x1234}},
        .brief_desc = "static bravo",
        .full_desc = "static bravo full",
    },
    {
        .pmu_type = PmuType::software,
        .id = "static.charlie",
        .encoding =
            {
                .code = 0x33,
                .msr_values = std::array<uint64_t, 2>{0x5678, 0x9abc},
            },
        .brief_desc = "static charlie",
        .full_desc = "static charlie full",
    },
}};

constexpr std::array<StaticEventDef, 2> kMixedStaticEvents{{
    {
        .pmu_type = PmuType::software,
        .id = "mixed_software",
        .encoding = {.code = 0x44},
        .brief_desc = "mixed software",
        .full_desc = "mixed software full",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "mixed_cpu",
        .encoding = {.code = 0x55},
        .brief_desc = "mixed cpu",
        .full_desc = "mixed cpu full",
    },
}};

constexpr std::array<StaticEventDef, 1> kAdditionalStaticEvents{{
    {
        .pmu_type = PmuType::software,
        .id = "static_delta",
        .encoding = {.code = 0x66},
        .brief_desc = "static delta",
        .full_desc = "static delta full",
    },
}};

static_assert(isStaticEventDefTableSorted(kStaticSoftwareEvents));
static_assert(isStaticEventDefTableSorted(kMixedStaticEvents));
static_assert(isStaticEventDefTableSorted(kAdditionalStaticEvents));

std::shared_ptr<PmuDevice> makePmu(
    std::string name,
    PmuType type,
    std::optional<unsigned> enumeration,
    uint32_t perf_pmu_id) {
  return std::make_shared<PmuDevice>(
      std::move(name),
      type,
      enumeration,
      perf_pmu_id,
      "A Dummy PMU device",
      false);
}

std::shared_ptr<PmuDeviceManager> makePmuManager() {
  return std::make_shared<PmuDeviceManager>(CpuInfo::load());
}

} // namespace

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

TEST_F(PmuDevicesTest, StaticMakeConfDoesNotRequireMaterialization) {
  auto pmu_manager = makePmuManager();
  auto pmu =
      makePmu("dummy_pmu", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  pmu_manager->addPmu(pmu);
  ASSERT_EQ(pmu_manager->addStaticEventDefs(kStaticSoftwareEvents), 0);

  const EventConf noMsr =
      pmu->makeConf("static_alpha", EventExtraAttr{}, EventValueTransforms{});
  EXPECT_EQ(noMsr.id, "static_alpha");
  EXPECT_EQ(noMsr.configs.type, PERF_TYPE_SOFTWARE);
  EXPECT_EQ(noMsr.configs.config, 0x11);
  EXPECT_EQ(noMsr.configs.config1, 0);
  EXPECT_EQ(noMsr.configs.config2, 0);

  const EventConf oneMsr =
      pmu->makeConf("STATIC_BRAVO", EventExtraAttr{}, EventValueTransforms{});
  EXPECT_EQ(oneMsr.configs.config, 0x22);
  EXPECT_EQ(oneMsr.configs.config1, 0x1234);
  EXPECT_EQ(oneMsr.configs.config2, 0);

  const EventConf twoMsrs =
      pmu->makeConf("static.charlie", EventExtraAttr{}, EventValueTransforms{});
  EXPECT_EQ(twoMsrs.configs.config, 0x33);
  EXPECT_EQ(twoMsrs.configs.config1, 0x5678);
  EXPECT_EQ(twoMsrs.configs.config2, 0x9abc);
}

TEST_F(PmuDevicesTest, StaticLookupSharesLazyMaterializationAcrossDevices) {
  auto pmu_manager = makePmuManager();
  auto pmu0 = makePmu("software_0", PmuType::software, 0, 101);
  auto pmu1 = makePmu("software_1", PmuType::software, 1, 102);
  pmu_manager->addPmu(pmu0);
  pmu_manager->addPmu(pmu1);
  ASSERT_EQ(pmu_manager->addStaticEventDefs(kStaticSoftwareEvents), 0);

  auto primary = pmu0->findEventDef("STATIC-ALPHA");
  auto alias = pmu0->findEventDef("static_alpha");
  auto other_device = pmu1->findEventDef("STATIC-ALPHA");
  ASSERT_NE(primary, nullptr);
  EXPECT_EQ(primary, alias);
  EXPECT_EQ(primary, other_device);
  EXPECT_EQ(primary->id, "STATIC-ALPHA");
}

TEST_F(PmuDevicesTest, StaticConcurrentFirstLookupSharesOnePointer) {
  auto pmu_manager = makePmuManager();
  auto pmu0 = makePmu("software_0", PmuType::software, 0, 101);
  auto pmu1 = makePmu("software_1", PmuType::software, 1, 102);
  pmu_manager->addPmu(pmu0);
  pmu_manager->addPmu(pmu1);
  ASSERT_EQ(pmu_manager->addStaticEventDefs(kStaticSoftwareEvents), 0);

  constexpr size_t kNumLookups = 16;
  std::array<std::future<std::shared_ptr<EventDef>>, kNumLookups> futures;
  for (size_t i = 0; i < futures.size(); ++i) {
    const auto& pmu = i % 2 == 0 ? pmu0 : pmu1;
    futures[i] = std::async(std::launch::async, [pmu, i] {
      return pmu->findEventDef(i % 3 == 0 ? "static_alpha" : "STATIC-ALPHA");
    });
  }

  const auto expected = futures[0].get();
  ASSERT_NE(expected, nullptr);
  for (size_t i = 1; i < futures.size(); ++i) {
    EXPECT_EQ(futures[i].get(), expected);
  }
}

TEST_F(PmuDevicesTest, StaticRegistrationSupportsMultipleSpansAndPmuTypes) {
  auto pmu_manager = makePmuManager();
  auto software =
      makePmu("software", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  auto cpu = makePmu("cpu", PmuType::cpu, std::nullopt, PERF_TYPE_RAW);
  pmu_manager->addPmu(software);
  pmu_manager->addPmu(cpu);

  ASSERT_EQ(pmu_manager->addStaticEventDefs(kStaticSoftwareEvents), 0);
  ASSERT_EQ(pmu_manager->addStaticEventDefs(kAdditionalStaticEvents), 0);
  ASSERT_EQ(pmu_manager->addStaticEventDefs(kMixedStaticEvents), 0);

  EXPECT_NE(software->findEventDef("static_delta"), nullptr);
  EXPECT_NE(software->findEventDef("mixed_software"), nullptr);
  EXPECT_EQ(software->findEventDef("mixed_cpu"), nullptr);
  EXPECT_NE(cpu->findEventDef("mixed_cpu"), nullptr);
  EXPECT_EQ(cpu->findEventDef("mixed_software"), nullptr);
}

TEST_F(PmuDevicesTest, StaticAndOwningEventsCoexistAndEnumerate) {
  auto pmu_manager = makePmuManager();
  auto pmu =
      makePmu("software", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  pmu_manager->addPmu(pmu);
  auto owning = std::make_shared<EventDef>(
      PmuType::software,
      "owning.event",
      EventDef::Encoding{.code = 0x77},
      "owning",
      "owning full");
  ASSERT_EQ(pmu_manager->addEvent(owning), 0);
  ASSERT_EQ(pmu_manager->addStaticEventDefs(kStaticSoftwareEvents), 0);

  const auto& event_defs = pmu->getEventDefs();
  EXPECT_EQ(event_defs.size(), 4);
  EXPECT_EQ(event_defs.at("owning.event"), owning);
  const auto static_event = event_defs.at("static.charlie");
  EXPECT_EQ(static_event, pmu->findEventDef("static.charlie"));
  EXPECT_EQ(&pmu->getEventDefs(), &event_defs);
  EXPECT_EQ(pmu->getEventDefs().at("static.charlie"), static_event);

  const auto groups = pmu->makeLibPfm4Groups();
  EXPECT_EQ(groups->size(), 4);
  EXPECT_EQ(groups->at("static").ev_defs.size(), 1);
}

TEST_F(PmuDevicesTest, AddsExplicitAliasesWithoutMaterializingStaticEvent) {
  auto pmu_manager = makePmuManager();
  auto pmu =
      makePmu("software", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  pmu_manager->addPmu(pmu);
  ASSERT_EQ(pmu_manager->addStaticEventDefs(kStaticSoftwareEvents), 0);

  EXPECT_EQ(
      pmu_manager->addAliases(
          "static_alpha", {"explicit_alias", "explicit_alias"}),
      0);
  const EventConf conf =
      pmu->makeConf("explicit_alias", EventExtraAttr{}, EventValueTransforms{});
  EXPECT_EQ(conf.id, "explicit_alias");
  EXPECT_EQ(conf.configs.config, 0x11);
  EXPECT_EQ(
      pmu->findEventDef("explicit_alias"), pmu->findEventDef("STATIC-ALPHA"));
}

TEST_F(PmuDevicesTest, RejectsInvalidStaticTablesWithoutPartialRegistration) {
  auto pmu_manager = makePmuManager();
  auto software =
      makePmu("software", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  auto cpu = makePmu("cpu", PmuType::cpu, std::nullopt, PERF_TYPE_RAW);
  pmu_manager->addPmu(software);
  pmu_manager->addPmu(cpu);
  cpu->addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "mixed_cpu",
          EventDef::Encoding{.code = 0x99},
          "collision",
          "collision full"));

  constexpr std::array<StaticEventDef, 2> unsorted{{
      kMixedStaticEvents[1],
      kMixedStaticEvents[0],
  }};
  EXPECT_THROW(
      pmu_manager->addStaticEventDefs(unsorted), std::invalid_argument);
  EXPECT_EQ(software->findEventDef("mixed_software"), nullptr);

  EXPECT_THROW(
      pmu_manager->addStaticEventDefs(kMixedStaticEvents),
      std::invalid_argument);
  EXPECT_EQ(software->findEventDef("mixed_software"), nullptr);
  EXPECT_EQ(cpu->findEventDef("mixed_cpu")->encoding.code, 0x99);

  ASSERT_EQ(pmu_manager->addStaticEventDefs(kStaticSoftwareEvents), 0);
  EXPECT_THROW(
      pmu_manager->addStaticEventDefs(kStaticSoftwareEvents),
      std::invalid_argument);
  EXPECT_THROW(
      software->addEvent(
          std::make_shared<EventDef>(
              PmuType::software,
              "STATIC-ALPHA",
              EventDef::Encoding{.code = 0xaa},
              "primary collision",
              "primary collision full")),
      std::invalid_argument);
  EXPECT_THROW(
      software->addEvent(
          std::make_shared<EventDef>(
              PmuType::software,
              "owning_with_alias",
              EventDef::Encoding{.code = 0xab},
              "explicit alias collision",
              "explicit alias collision full"),
          std::vector<EventId>{"STATIC_BRAVO"}),
      std::invalid_argument);
  EXPECT_THROW(
      software->addEvent(
          std::make_shared<EventDef>(
              PmuType::software,
              "STATIC-BRAVO",
              EventDef::Encoding{.code = 0xac},
              "canonical alias collision",
              "canonical alias collision full")),
      std::invalid_argument);
  EXPECT_EQ(software->getEventDefs().size(), kStaticSoftwareEvents.size());
}

TEST_F(PmuDevicesTest, RejectsStaticPrimaryAndCanonicalAliasCollisions) {
  auto pmu_manager = makePmuManager();
  auto software =
      makePmu("software", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  pmu_manager->addPmu(software);
  software->addEvent(
      std::make_shared<EventDef>(
          PmuType::software,
          "owning_event",
          EventDef::Encoding{.code = 0x88},
          "owning",
          "owning full"),
      std::vector<EventId>{"existing_alias"});

  constexpr std::array<StaticEventDef, 1> primaryAliasCollision{{
      {
          .pmu_type = PmuType::software,
          .id = "existing_alias",
          .encoding = {.code = 0x89},
          .brief_desc = "primary alias collision",
          .full_desc = "primary alias collision full",
      },
  }};
  EXPECT_THROW(
      pmu_manager->addStaticEventDefs(primaryAliasCollision),
      std::invalid_argument);

  constexpr std::array<StaticEventDef, 1> canonicalPrimaryCollision{{
      {
          .pmu_type = PmuType::software,
          .id = "OWNING-EVENT",
          .encoding = {.code = 0x8a},
          .brief_desc = "canonical primary collision",
          .full_desc = "canonical primary collision full",
      },
  }};
  EXPECT_THROW(
      pmu_manager->addStaticEventDefs(canonicalPrimaryCollision),
      std::invalid_argument);
  EXPECT_EQ(software->getEventDefs().size(), 1);
}

TEST_F(PmuDevicesTest, SkipsUnavailablePmuTypes) {
  auto pmu_manager = makePmuManager();
  auto software =
      makePmu("software", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  pmu_manager->addPmu(software);

  ASSERT_EQ(pmu_manager->addStaticEventDefs(kMixedStaticEvents), 0);
  EXPECT_NE(software->findEventDef("mixed_software"), nullptr);
  EXPECT_EQ(software->findEventDef("mixed_cpu"), nullptr);

  constexpr std::array<StaticEventDef, 1> unavailable{{
      kMixedStaticEvents[1],
  }};
  EXPECT_EQ(pmu_manager->addStaticEventDefs(unavailable), -ENXIO);
  EXPECT_EQ(software->getEventDefs().count("mixed_cpu"), 0);
  EXPECT_EQ(pmu_manager->addStaticEventDefs({}), 0);
}

TEST_F(PmuDevicesTest, RejectsStaticDefinitionsThatCannotMaterialize) {
  auto pmu_manager = makePmuManager();
  auto software =
      makePmu("software", PmuType::software, std::nullopt, PERF_TYPE_SOFTWARE);
  pmu_manager->addPmu(software);

  constexpr std::array<StaticEventDef, 1> invalid{{
      {
          .pmu_type = PmuType::software,
          .id = "invalid event",
          .encoding = {.code = 0x77},
          .brief_desc = "invalid",
          .full_desc = "invalid full",
      },
  }};
  EXPECT_THROW(pmu_manager->addStaticEventDefs(invalid), std::invalid_argument);
  EXPECT_EQ(software->findEventDef("invalid event"), nullptr);
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

TEST_F(PmuDevicesTest, NeoverseV3UncorePmuTypeRoundTrip) {
  const std::vector<std::pair<PmuType, std::string>> expected{
      {PmuType::arm_cspmu_mc, "arm_cspmu_mc"},
      {PmuType::arm_cmn, "arm_cmn"},
  };
  for (const auto& [type, name] : expected) {
    EXPECT_EQ(PmuTypeToStr(type), name);
    EXPECT_EQ(PmuTypeFromStr(name), type);
  }
}

TEST_F(PmuDevicesTest, ParseNeoverseV3UncoreDeviceNames) {
  const std::vector<std::tuple<std::string, PmuType, std::optional<uint32_t>>>
      expected{
          {"arm_cspmu_mc_0", PmuType::arm_cspmu_mc, 0},
          {"arm_cspmu_mc_3", PmuType::arm_cspmu_mc, 3},
          {"arm_cmn_0", PmuType::arm_cmn, 0},
          {"arm_cmn_1", PmuType::arm_cmn, 1},
      };
  for (const auto& [name, expectedType, expectedIndex] : expected) {
    const auto [type, index] = parseDeviceTypeFromStr(name);
    EXPECT_EQ(type, expectedType);
    EXPECT_EQ(index, expectedIndex);
  }
}

TEST_F(PmuDevicesTest, LoadNeoverseV3UncorePmusFromSysFs) {
  const char* testRoot = getenv("testroot");
  ASSERT_NE(testRoot, nullptr);

  auto cpuInfo = CpuInfo::load();
  PmuDeviceManager pmuManager(cpuInfo, testRoot);
  pmuManager.loadSysFsPmus();

  auto dmc = pmuManager.findPmuDeviceByName("arm_cspmu_mc_0");
  ASSERT_NE(dmc, nullptr);
  EXPECT_EQ(dmc->getPmuType(), PmuType::arm_cspmu_mc);
  EXPECT_EQ(dmc->getPmuDevEnumeration(), 0);
  const auto dmcCpuMask = dmc->getCpuMask();
  ASSERT_TRUE(dmcCpuMask.has_value());
  EXPECT_TRUE(CPU_ISSET(0, &dmcCpuMask.value()));
  EXPECT_TRUE(dmc->format.contains("event"));

  auto cmn = pmuManager.findPmuDeviceByName("arm_cmn_0");
  ASSERT_NE(cmn, nullptr);
  EXPECT_EQ(cmn->getPmuType(), PmuType::arm_cmn);
  EXPECT_EQ(cmn->getPmuDevEnumeration(), 0);
  const auto cmnCpuMask = cmn->getCpuMask();
  ASSERT_TRUE(cmnCpuMask.has_value());
  EXPECT_TRUE(CPU_ISSET(0, &cmnCpuMask.value()));
  EXPECT_TRUE(cmn->format.contains("eventid"));
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

TEST_F(PmuDevicesTest, ArmCpuArchMapping) {
  // Phoenix reports the Neoverse V3AE part number.
  EXPECT_EQ(makeCpuArchArm(0x41, 0, 0xD83, 0), CpuArch::NEOVERSE_V3);
  EXPECT_EQ(makeCpuArchArm(0x41, 0, 0xD84, 0), CpuArch::NEOVERSE_V3);
  // Regression: Arm-implemented Neoverse V2 (Grace-Hopper) still maps.
  EXPECT_EQ(makeCpuArchArm(0x41, 0, 0xD4F, 0), CpuArch::NEOVERSE_V2);
  // Vera (VR200 / Vera-Rubin): NVIDIA implementer 0x4E, part 0x010.
  EXPECT_EQ(makeCpuArchArm(0x4E, 0, 0x010, 0), CpuArch::NEOVERSE_V2);
  // Unknown NVIDIA part number -> UNKNOWN.
  EXPECT_EQ(makeCpuArchArm(0x4E, 0, 0x999, 0), CpuArch::UNKNOWN);
}
