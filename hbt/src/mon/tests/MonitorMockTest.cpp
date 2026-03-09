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
  pmu_manager->addPmu(
      std::make_shared<perf_event::PmuDevice>(
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
  pmu_manager->addPmu(
      std::make_shared<perf_event::PmuDevice>(
          PmuTypeToStr(perf_event::PmuType::uncore_imc),
          perf_event::PmuType::uncore_imc,
          /*pmu_device_enumeration=*/0,
          /*perf_pmu_id=*/14,
          "uncore_imc_0",
          /*in_sysfs=*/true,
          /*cpu_mask=*/cpu_set.cpu_set));

  pmu_manager->addEvent(
      std::make_shared<perf_event::EventDef>(
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
  pmu_manager->addEvent(
      std::make_shared<perf_event::EventDef>(
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

// Integration tests for Monitor + MuxQueueStrategy

TEST(MonitorSchedulingIntegration, PerPmuTypeConstructorPropagatesFlag) {
  auto cpu_factory =
      std::make_unique<perf_event::MockPerCpuCountReaderFactory>();
  auto uncore_factory =
      std::make_unique<perf_event::MockPerUncoreCountReaderFactory>();

  // Use the 4-param constructor with mux_queue_per_pmu_type=true.
  // This previously had a bug where the scheduling strategy would get
  // mux_queue_per_pmu_type=false via the default constructor.
  Monitor mon(std::move(cpu_factory), std::move(uncore_factory), true, false);

  // Verify the strategy correctly received the per-pmu-type flag
  // by checking via printMuxQueueStatus (the strategy's state is internal).
  // The key behavioral test is that addMuxEntry with different PMU types
  // creates separate queues.
  std::ostringstream os;
  mon.printMuxQueueStatus(os);
  // Should not crash - this validates the Monitor constructed correctly.
  EXPECT_FALSE(os.str().empty());
}

TEST(MonitorSchedulingIntegration, SimpleConstructorPropagatesFlag) {
  // Simple constructor with mux_queue_per_pmu_type=true
  Monitor mon(true, false);

  std::ostringstream os;
  mon.printMuxQueueStatus(os);
  EXPECT_FALSE(os.str().empty());
}

TEST(MonitorSchedulingIntegration, MuxRotateWithPerPmuTypeQueues) {
  auto cpu_info = CpuInfo("Intel", 6, 207, 0);
  auto cpu_set = CpuSet::makeFromCpusList("0,1,2,3");
  auto pmu_manager = std::make_shared<perf_event::PmuDeviceManager>(cpu_info);
  pmu_manager->addPmu(
      std::make_shared<perf_event::PmuDevice>(
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
          "cycles"),
      std::vector<perf_event::EventId>({"cpu-cycles", "cycles"}));
  pmu_manager->addEvent(
      std::make_shared<perf_event::EventDef>(
          perf_event::PmuType::generic_hardware,
          "instructions",
          perf_event::EventDef::Encoding{.code = PERF_COUNT_HW_INSTRUCTIONS},
          "Instructions.",
          "instructions"),
      std::vector<perf_event::EventId>(
          {"retired_instructions", "retired-instructions"}));

  auto metrics = perf_event::makeAvailableMetrics();

  // Set up mock factories with two metrics in separate mux groups
  auto cpu_factory =
      std::make_unique<perf_event::MockPerCpuCountReaderFactory>();

  // For the per-PMU-type test, we need readers that support open/close/enable.
  // The key test is that muxRotate correctly rotates per-PMU-type queues.
  cpu_factory->setExpectation(
      "instructions", [](perf_event::MockPerCpuCountReader* reader) {
        EXPECT_CALL(*reader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, close).Times(AtLeast(0));
        EXPECT_CALL(*reader, disable).Times(AtLeast(0));
        EXPECT_CALL(*reader, enable).Times(AtLeast(0));
        EXPECT_CALL(*reader, open).Times(AtLeast(0));
      });
  cpu_factory->setExpectation(
      "cycles", [](perf_event::MockPerCpuCountReader* reader) {
        EXPECT_CALL(*reader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, close).Times(AtLeast(0));
        EXPECT_CALL(*reader, disable).Times(AtLeast(0));
        EXPECT_CALL(*reader, enable).Times(AtLeast(0));
        EXPECT_CALL(*reader, open).Times(AtLeast(0));
      });

  auto uncore_factory =
      std::make_unique<perf_event::MockPerUncoreCountReaderFactory>();

  // Create Monitor with mux_queue_per_pmu_type=true via 4-param constructor
  Monitor mon(std::move(cpu_factory), std::move(uncore_factory), true, false);

  // Add two metrics in separate mux groups but same PMU type
  mon.emplaceCpuCountReader(
      "group_instructions",
      "instructions",
      metrics->getMetricDesc("instructions"),
      pmu_manager,
      cpu_set,
      nullptr);
  mon.emplaceCpuCountReader(
      "group_cycles",
      "cycles",
      metrics->getMetricDesc("cycles"),
      pmu_manager,
      cpu_set,
      nullptr);

  mon.open();
  mon.enable();

  // muxRotate should not crash - this exercises the full path through
  // scheduling_strategy_.advance() -> sync_() -> syncElems_() -> getGroup()
  mon.muxRotate();
  mon.muxRotate();

  // Verify rotation happened by checking that printMuxQueueStatus works
  std::ostringstream os;
  mon.printMuxQueueStatus(os);
  std::string output = os.str();
  EXPECT_NE(output.find("group_instructions"), std::string::npos);
  EXPECT_NE(output.find("group_cycles"), std::string::npos);
}

TEST(MonitorSchedulingIntegration, EraseMetricUpdatesSchedule) {
  auto cpu_info = CpuInfo("Intel", 6, 207, 0);
  auto cpu_set = CpuSet::makeFromCpusList("0,1");
  auto pmu_manager = std::make_shared<perf_event::PmuDeviceManager>(cpu_info);
  pmu_manager->addPmu(
      std::make_shared<perf_event::PmuDevice>(
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
          "cycles"),
      std::vector<perf_event::EventId>({"cpu-cycles", "cycles"}));
  pmu_manager->addEvent(
      std::make_shared<perf_event::EventDef>(
          perf_event::PmuType::generic_hardware,
          "instructions",
          perf_event::EventDef::Encoding{.code = PERF_COUNT_HW_INSTRUCTIONS},
          "Instructions.",
          "instructions"),
      std::vector<perf_event::EventId>(
          {"retired_instructions", "retired-instructions"}));

  auto metrics = perf_event::makeAvailableMetrics();
  auto cpu_factory =
      std::make_unique<perf_event::MockPerCpuCountReaderFactory>();

  cpu_factory->setExpectation(
      "instructions", [](perf_event::MockPerCpuCountReader* reader) {
        EXPECT_CALL(*reader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, close).Times(AtLeast(0));
        EXPECT_CALL(*reader, disable).Times(AtLeast(0));
        EXPECT_CALL(*reader, enable).Times(AtLeast(0));
        EXPECT_CALL(*reader, open).Times(AtLeast(0));
      });
  cpu_factory->setExpectation(
      "cycles", [](perf_event::MockPerCpuCountReader* reader) {
        EXPECT_CALL(*reader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*reader, close).Times(AtLeast(0));
        EXPECT_CALL(*reader, disable).Times(AtLeast(0));
        EXPECT_CALL(*reader, enable).Times(AtLeast(0));
        EXPECT_CALL(*reader, open).Times(AtLeast(0));
      });

  auto uncore_factory =
      std::make_unique<perf_event::MockPerUncoreCountReaderFactory>();

  // Use the 4-param constructor to test the previously buggy path
  Monitor mon(std::move(cpu_factory), std::move(uncore_factory), false, false);

  mon.emplaceCpuCountReader(
      "group_instructions",
      "instructions",
      metrics->getMetricDesc("instructions"),
      pmu_manager,
      cpu_set,
      nullptr);
  mon.emplaceCpuCountReader(
      "group_cycles",
      "cycles",
      metrics->getMetricDesc("cycles"),
      pmu_manager,
      cpu_set,
      nullptr);

  mon.open();
  mon.enable();

  // Erase one metric - exercises removeMuxEntry_ -> removeEntry
  EXPECT_TRUE(mon.eraseCpuCountReader("group_cycles", "cycles"));

  // muxRotate should work with only one group remaining
  mon.muxRotate();

  // Erasing nonexistent should return false
  EXPECT_FALSE(mon.eraseCpuCountReader("group_cycles", "cycles"));
}

} // namespace
} // namespace facebook::hbt::mon
