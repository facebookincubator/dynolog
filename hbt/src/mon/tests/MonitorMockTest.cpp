#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "hbt/src/mon/Monitor.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"
#include "hbt/src/perf_event/tests/MockPerCpuCountReader.h"
#include "hbt/src/perf_event/tests/MockPerUncoreCountReader.h"

namespace facebook::hbt::mon {
namespace {
using namespace ::testing;
using CpuReadValues = perf_event::PerCpuCountReader::ReadValues;
using UncoreReadValues = perf_event::PerUncoreCountReader::ReadValues;

TEST(CpuCountReader, ReadAllCpuCounts) {
  auto cpu_info = CpuInfo("Intel", 6, 207, 0);
  auto cpu_set = CpuSet::makeFromCpusList("0,1,2,3");
  auto pmu_manager = std::make_shared<perf_event::PmuDeviceManager>(cpu_info);
  pmu_manager->addPmu(std::make_shared<perf_event::PmuDevice>(
      PmuTypeToStr(perf_event::PmuType::generic_hardware),
      perf_event::PmuType::generic_hardware,
      std::nullopt,
      PERF_TYPE_HARDWARE,
      "PMU of Generic Hardware Events",
      false));
  pmu_manager->addEvent(
      std::make_shared<perf_event::EventDef>(
          perf_event::PmuType::generic_hardware,
          "cpu_cycles",
          perf_event::EventDef::Encoding{.code = PERF_COUNT_HW_CPU_CYCLES},
          "CPU cycles.",
          "Actual CPU cycles. Depends on frequency scaling, turbo mode and other effects."),
      std::vector<perf_event::EventId>({"cpu-cycles", "cycles"}));
  pmu_manager->addEvent(
      std::make_shared<perf_event::EventDef>(
          perf_event::PmuType::generic_hardware,
          "instructions",
          perf_event::EventDef::Encoding{.code = PERF_COUNT_HW_INSTRUCTIONS},
          "Instructions retired.",
          "Instructions executed. Does not count speculative execution."),
      std::vector<perf_event::EventId>(
          {"retired_instructions", "retired-instructions"}));

  auto metrics = perf_event::makeAvailableMetrics();
  auto cpu_factory =
      std::make_unique<perf_event::MockPerCpuCountReaderFactory>();
  cpu_factory->setExpectation(
      "instructions",
      [](perf_event::MockPerCpuCountReader* instructionsReader) {
        CpuReadValues instValues = instructionsReader->makeReadValues();
        instValues.t->count[0] = 100;
        instValues.t->time_enabled = 1;
        instValues.t->time_running = 1;
        EXPECT_CALL(*instructionsReader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*instructionsReader, isEnabled)
            .WillRepeatedly(Return(true));
        EXPECT_CALL(*instructionsReader, read)
            .WillOnce(Return(std::make_optional(instValues)));
        EXPECT_CALL(*instructionsReader, close).Times(AtLeast(1));
        EXPECT_CALL(*instructionsReader, disable).Times(AtLeast(1));
        CpuReadValues perCpuValues = instructionsReader->makeReadValues();
        perCpuValues.t->count[0] = 100;
        perCpuValues.t->time_enabled = 1;
        perCpuValues.t->time_running = 1;
        CpuReadValues perCpuValues2 = instructionsReader->makeReadValues();
        perCpuValues2.t->count[0] = 200;
        perCpuValues2.t->time_enabled = 1;
        perCpuValues2.t->time_running = 1;
        std::map<int, CpuReadValues> perCpuValue{
            {0, std::move(perCpuValues)}, {1, std::move(perCpuValues2)}};
        EXPECT_CALL(*instructionsReader, readPerCpu)
            .WillOnce(Return(std::make_optional(perCpuValue)));
      });
  cpu_factory->setExpectation(
      "cycles", [](perf_event::MockPerCpuCountReader* cyclesReader) {
        CpuReadValues cycleValues = cyclesReader->makeReadValues();
        cycleValues.t->count[0] = 200;
        cycleValues.t->time_enabled = 1;
        cycleValues.t->time_running = 1;
        CpuReadValues cycleValues2 = cyclesReader->makeReadValues();
        cycleValues2.t->count[0] = 200;
        cycleValues2.t->time_enabled = 4;
        cycleValues2.t->time_running = 2;
        EXPECT_CALL(*cyclesReader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*cyclesReader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*cyclesReader, read)
            .WillOnce(Return(std::make_optional(cycleValues)))
            .WillOnce(Return(std::make_optional(cycleValues2)));
        EXPECT_CALL(*cyclesReader, close).Times(AtLeast(1));
        EXPECT_CALL(*cyclesReader, disable).Times(AtLeast(1));
        EXPECT_CALL(*cyclesReader, readPerCpu).WillOnce(Return(std::nullopt));
      });
  auto uncore_factory =
      std::make_unique<perf_event::MockPerUncoreCountReaderFactory>();

  Monitor mon(std::move(cpu_factory), std::move(uncore_factory), false, true);
  mon.emplaceCpuCountReader(
      "instructions",
      "instructions",
      metrics->getMetricDesc("instructions"),
      pmu_manager,
      cpu_set,
      nullptr);
  mon.emplaceCpuCountReader(
      "cycles",
      "cycles",
      metrics->getMetricDesc("cycles"),
      pmu_manager,
      cpu_set,
      nullptr);

  EXPECT_TRUE(mon.open());
  EXPECT_TRUE(mon.enable());

  auto vals = mon.readAllCpuCounts();
  EXPECT_THAT(vals, ElementsAre(Key("cycles"), Key("instructions")));
  EXPECT_THAT(vals.at("cycles")->getCounts(), ElementsAre(200));
  EXPECT_THAT(vals.at("instructions")->getCounts(), ElementsAre(100));
  EXPECT_THAT(
      mon.readCpuCounts("cycles"),
      Optional(Property(&CpuReadValues::getCounts, ElementsAre(400))));
  EXPECT_THAT(mon.readCpuCounts("non-existent"), Eq(std::nullopt));

  auto perCpuVals = mon.readAllCpuCountsPerCpu();
  EXPECT_THAT(
      perCpuVals,
      ElementsAre(
          Pair("cycles", Eq(std::nullopt)),
          Pair("instructions", Optional(ElementsAre(Key(0), Key(1))))));
  EXPECT_THAT(
      perCpuVals.at("instructions")->at(0).getCounts(), ElementsAre(100));
};

TEST(UncoreCountReader, ReadAllUncoreCounts) {
  auto cpu_info = CpuInfo("Intel", 6, 207, 0);
  auto cpu_set = CpuSet::makeFromCpusList("0,20");
  auto pmu_manager = std::make_shared<perf_event::PmuDeviceManager>(cpu_info);
  pmu_manager->addPmu(std::make_shared<perf_event::PmuDevice>(
      PmuTypeToStr(perf_event::PmuType::uncore_imc),
      perf_event::PmuType::uncore_imc,
      /*pmu_device_enumeration=*/0,
      /*perf_pmu_id=*/14,
      "uncore_imc_0",
      /*in_sysfs=*/true,
      /*cpu_mask=*/cpu_set.cpu_set));

  pmu_manager->addEvent(std::make_shared<perf_event::EventDef>(
      perf_event::PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD",
      perf_event::EventDef::Encoding{.code = 0x4, .umask = 0x3},
      R"(DRAM RD_CAS and WR_CAS Commands.; All DRAM Reads (RD_CAS + Underfills))",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM Read CAS commands issued on this channel (including underfills).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      perf_event::EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
  pmu_manager->addEvent(std::make_shared<perf_event::EventDef>(
      perf_event::PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR",
      perf_event::EventDef::Encoding{.code = 0x4, .umask = 0xC},
      R"(DRAM RD_CAS and WR_CAS Commands.; All DRAM WR_CAS (both Modes))",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM Write CAS commands issued on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      perf_event::EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  auto metrics = std::make_shared<perf_event::Metrics>();
  perf_event::addIntelUncoreMetrics(metrics);
  auto cpu_factory =
      std::make_unique<perf_event::MockPerCpuCountReaderFactory>();
  auto uncore_factory =
      std::make_unique<perf_event::MockPerUncoreCountReaderFactory>();

  uncore_factory->setExpectation(
      "HW_UNCORE_MEM_BW_READ",
      [](perf_event::MockPerUncoreCountReader* readReader) {
        UncoreReadValues values = readReader->makeReadValues();
        values.t->count[0] = 100;
        values.t->time_enabled = 1;
        values.t->time_running = 1;
        EXPECT_CALL(*readReader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*readReader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*readReader, read)
            .WillOnce(Return(std::make_optional(values)));
        EXPECT_CALL(*readReader, close).Times(AtLeast(1));
        EXPECT_CALL(*readReader, disable).Times(AtLeast(1));
        UncoreReadValues values2 = readReader->makeReadValues();
        values2.t->count[0] = 200;
        values2.t->time_enabled = 1;
        values2.t->time_running = 1;
        EXPECT_CALL(*readReader, readPerPerfEventsGroup)
            .WillOnce(
                Return(std::vector<UncoreReadValues>{std::move(values2)}));
      });
  uncore_factory->setExpectation(
      "HW_UNCORE_MEM_BW_WRITE",
      [](perf_event::MockPerUncoreCountReader* writeReader) {
        UncoreReadValues values = writeReader->makeReadValues();
        values.t->count[0] = 200;
        values.t->time_enabled = 1;
        values.t->time_running = 1;
        UncoreReadValues values2 = writeReader->makeReadValues();
        values2.t->count[0] = 200;
        values2.t->time_enabled = 4;
        values2.t->time_running = 2;
        EXPECT_CALL(*writeReader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*writeReader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*writeReader, close).Times(AtLeast(1));
        EXPECT_CALL(*writeReader, disable).Times(AtLeast(1));
        EXPECT_CALL(*writeReader, read)
            .WillOnce(Return(std::make_optional(values)))
            .WillOnce(Return(std::make_optional(values2)));
        EXPECT_CALL(*writeReader, readPerPerfEventsGroup)
            .WillOnce(Return(std::vector<UncoreReadValues>{}));
      });

  Monitor mon(std::move(cpu_factory), std::move(uncore_factory), false, true);
  mon.emplaceUncoreCountReader(
      std::make_optional<std::string>("imc_bandwidth"),
      "HW_UNCORE_MEM_BW_READ",
      metrics->getMetricDesc("HW_UNCORE_MEM_BW_READ"),
      pmu_manager,
      std::vector<hbt::perf_event::uncore_scope::Scope>{
          hbt::perf_event::uncore_scope::Host{}});

  mon.emplaceUncoreCountReader(
      std::make_optional<std::string>("imc_bandwidth"),
      "HW_UNCORE_MEM_BW_WRITE",
      metrics->getMetricDesc("HW_UNCORE_MEM_BW_WRITE"),
      pmu_manager,
      std::vector<hbt::perf_event::uncore_scope::Scope>{
          hbt::perf_event::uncore_scope::Host{}});

  EXPECT_TRUE(mon.open());
  EXPECT_TRUE(mon.enable());

  auto vals = mon.readAllUncoreCounts();
  EXPECT_THAT(
      vals,
      ElementsAre(Key("HW_UNCORE_MEM_BW_READ"), Key("HW_UNCORE_MEM_BW_WRITE")));
  EXPECT_THAT(vals.at("HW_UNCORE_MEM_BW_READ")->getCounts(), ElementsAre(100));
  EXPECT_THAT(vals.at("HW_UNCORE_MEM_BW_WRITE")->getCounts(), ElementsAre(200));
  EXPECT_THAT(
      mon.readUncoreCounts("HW_UNCORE_MEM_BW_WRITE"),
      Optional(Property(&UncoreReadValues::getCounts, ElementsAre(400))));
  EXPECT_THAT(mon.readUncoreCounts("non-existent"), Eq(std::nullopt));
  auto perEventVals = mon.readAllUncoreCountsPerPerfEvent();
  EXPECT_THAT(
      perEventVals,
      ElementsAre(Key("HW_UNCORE_MEM_BW_READ"), Key("HW_UNCORE_MEM_BW_WRITE")));
  EXPECT_THAT(
      perEventVals.at("HW_UNCORE_MEM_BW_READ").at(0).getCounts(),
      ElementsAre(200));
}

} // namespace
} // namespace facebook::hbt::mon
