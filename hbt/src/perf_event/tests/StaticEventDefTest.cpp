// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include "hbt/src/perf_event/PmuEvent.h"
#include "hbt/src/perf_event/StaticEventDef.h"

#include <array>
#include <string>
#include <vector>

using namespace facebook::hbt::perf_event;

namespace {

constexpr std::array<StaticEventDef, 4> kEvents{{
    {
        .pmu_type = PmuType::cpu,
        .id = "ALPHA",
        .encoding =
            {
                .code = 0x11,
                .umask = 0x22,
                .cmask = 3,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "alpha brief",
        .full_desc = "alpha full",
        .default_sampling_period = 100003,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ZULU",
        .encoding =
            {
                .code = 0xB7,
                .umask = 0x01,
                .edge = true,
                .any = true,
                .inv = true,
                .msr_values = std::array<uint64_t, 2>{0x8003C07F7ULL, 0xA5ULL},
            },
        .scale_data =
            StaticEventDef::ScaleData{
                .scale_factor = 0.5,
                .scale_unit = ScaleUnit::MiB,
            },
        .features =
            StaticEventDef::IntelFeatures{
                .data_la = true,
                .l1_hit_indication = true,
                .ellc = true,
                .pebs = 2,
            },
        .brief_desc = "zulu brief",
        .full_desc = "zulu full",
        .errata = "BDM69",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "BRAVO",
        .encoding =
            {
                .code = 0x35,
                .umask_ext = 0x78CC6FFE,
                .msr_values = uint64_t{0},
            },
        .scale_data =
            StaticEventDef::ScaleData{
                .scale_factor = 64,
                .scale_unit = ScaleUnit::Bytes,
            },
        .brief_desc = "bravo brief",
        .full_desc = "bravo full",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "CHARLIE",
        .encoding =
            {
                .code = 0x36,
                .umask = 0x01,
            },
        .brief_desc = "charlie brief",
        .full_desc = "charlie full",
    },
}};

static_assert(isStaticEventDefTableSorted(kEvents));
static_assert(findStaticEventDef(kEvents, PmuType::cpu, "ALPHA") != nullptr);
static_assert(
    findStaticEventDef(kEvents, PmuType::cpu, "ALPHA")
        ->default_sampling_period == 100003);
static_assert(makeEventConfigs(kEvents[1], 7).config1 == 0x8003C07F7ULL);
static_assert(makeEventConfigs(kEvents[1], 7).config2 == 0xA5ULL);

void expectConfigsEqual(
    const EventConfigs& expected,
    const EventConfigs& actual) {
  EXPECT_EQ(actual.type, expected.type);
  EXPECT_EQ(actual.config, expected.config);
  EXPECT_EQ(actual.config1, expected.config1);
  EXPECT_EQ(actual.config2, expected.config2);
}

} // namespace

TEST(StaticEventDefTest, FindsDefinitionsAndReturnsNullptrOnMiss) {
  const StaticEventDef* alpha =
      findStaticEventDef(kEvents, PmuType::cpu, "ALPHA");
  ASSERT_NE(alpha, nullptr);
  EXPECT_EQ(alpha->brief_desc, "alpha brief");

  EXPECT_EQ(findStaticEventDef(kEvents, PmuType::cpu, "NOPE"), nullptr);
  EXPECT_EQ(findStaticEventDef(kEvents, PmuType::uncore_cha, "ALPHA"), nullptr);
  EXPECT_NE(findStaticEventDef(kEvents, PmuType::uncore_cha, "BRAVO"), nullptr);
  EXPECT_EQ(findStaticEventDef({}, PmuType::cpu, "ALPHA"), nullptr);
}

TEST(StaticEventDefTest, SortednessCheckRejectsOrderAndDuplicateKeys) {
  constexpr std::array<StaticEventDef, 2> misordered{{kEvents[2], kEvents[0]}};
  constexpr std::array<StaticEventDef, 2> duplicate{{kEvents[0], kEvents[0]}};

  EXPECT_FALSE(isStaticEventDefTableSorted(misordered));
  EXPECT_FALSE(isStaticEventDefTableSorted(duplicate));
  EXPECT_TRUE(isStaticEventDefTableSorted(kEvents));
}

TEST(StaticEventDefTest, ConfigEncodingMatchesOwningDefinition) {
  for (const StaticEventDef& event : kEvents) {
    const EventDef owning = materializeEventDef(event);
    expectConfigsEqual(owning.makeConfigs(7), makeEventConfigs(event, 7));
  }

  const EventConfigs twoMsrs = makeEventConfigs(kEvents[1], 7);
  EXPECT_EQ(twoMsrs.config1, 0x8003C07F7ULL);
  EXPECT_EQ(twoMsrs.config2, 0xA5ULL);

  const EventConfigs explicitZeroMsr = makeEventConfigs(kEvents[2], 7);
  EXPECT_EQ(explicitZeroMsr.config1, 0);
  EXPECT_EQ(explicitZeroMsr.config2, 0);
}

TEST(StaticEventDefTest, MaterializationPreservesAllMetadata) {
  const EventDef event = materializeEventDef(kEvents[1]);

  EXPECT_EQ(event.pmu_type, PmuType::cpu);
  EXPECT_EQ(event.id, "ZULU");
  EXPECT_EQ(event.encoding.code, 0xB7);
  EXPECT_EQ(event.encoding.umask, 0x01);
  EXPECT_TRUE(event.encoding.edge);
  EXPECT_TRUE(event.encoding.any);
  EXPECT_TRUE(event.encoding.inv);
  EXPECT_EQ(
      event.encoding.msr_values,
      (std::vector<uint64_t>{0x8003C07F7ULL, 0xA5ULL}));
  ASSERT_TRUE(event.scale_data.has_value());
  EXPECT_DOUBLE_EQ(std::get<double>(event.scale_data->scale_factor), 0.5);
  EXPECT_EQ(event.scale_data->scale_unit, ScaleUnit::MiB);
  ASSERT_TRUE(event.features.has_value());
  EXPECT_TRUE(event.features->data_la);
  EXPECT_TRUE(event.features->l1_hit_indication);
  EXPECT_TRUE(event.features->ellc);
  EXPECT_EQ(event.features->pebs, 2);
  EXPECT_EQ(event.isPrecise(), std::optional<bool>{true});
  EXPECT_EQ(event.brief_desc, "zulu brief");
  EXPECT_EQ(event.full_desc, "zulu full");
  EXPECT_EQ(event.default_sampling_period, std::nullopt);
  EXPECT_EQ(event.errata, std::optional<std::string>{"BDM69"});
}

TEST(StaticEventDefTest, MaterializationPreservesOptionalStates) {
  const EventDef absent = materializeEventDef(kEvents[3]);
  EXPECT_TRUE(absent.encoding.msr_values.empty());
  EXPECT_EQ(absent.scale_data, std::nullopt);
  EXPECT_EQ(absent.features, std::nullopt);
  EXPECT_EQ(absent.isPrecise(), std::nullopt);
  EXPECT_EQ(absent.default_sampling_period, std::nullopt);
  EXPECT_EQ(absent.errata, std::nullopt);

  const EventDef explicitZeroMsr = materializeEventDef(kEvents[2]);
  EXPECT_EQ(explicitZeroMsr.encoding.msr_values, std::vector<uint64_t>{0});
  ASSERT_TRUE(explicitZeroMsr.scale_data.has_value());
  EXPECT_EQ(std::get<int>(explicitZeroMsr.scale_data->scale_factor), 64);

  const EventDef knownNotPrecise = materializeEventDef(kEvents[0]);
  EXPECT_EQ(knownNotPrecise.isPrecise(), std::optional<bool>{false});
  EXPECT_EQ(
      knownNotPrecise.default_sampling_period, std::optional<uint64_t>{100003});
}
