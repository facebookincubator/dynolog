#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "hbt/src/mon/Monitor.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"
#include "hbt/src/perf_event/tests/MockPerCpuCountReader.h"

namespace facebook::hbt::mon {
namespace {
using namespace ::testing;

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
  auto factory = std::make_unique<perf_event::MockPerCpuCountReaderFactory>();
  factory->setExpectation(
      "instructions",
      [](perf_event::MockPerCpuCountReader* instructionsReader) {
        perf_event::PerCpuCountReader::ReadValues instValues(4);
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
      });
  factory->setExpectation(
      "cycles", [](perf_event::MockPerCpuCountReader* cyclesReader) {
        perf_event::PerCpuCountReader::ReadValues cycleValues(4);
        cycleValues.t->count[0] = 200;
        cycleValues.t->time_enabled = 1;
        cycleValues.t->time_running = 1;
        EXPECT_CALL(*cyclesReader, isOpen).WillRepeatedly(Return(true));
        EXPECT_CALL(*cyclesReader, isEnabled).WillRepeatedly(Return(true));
        EXPECT_CALL(*cyclesReader, read)
            .WillOnce(Return(std::make_optional(cycleValues)));
        EXPECT_CALL(*cyclesReader, close).Times(AtLeast(1));
        EXPECT_CALL(*cyclesReader, disable).Times(AtLeast(1));
      });

  Monitor mon(std::move(factory), false, true);
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
  EXPECT_THAT(vals.at("cycles")->getCounts(), ElementsAre(200, 0, 0, 0));
  EXPECT_THAT(vals.at("instructions")->getCounts(), ElementsAre(100, 0, 0, 0));
};

} // namespace
} // namespace facebook::hbt::mon
