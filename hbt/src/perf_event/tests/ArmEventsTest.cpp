// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/ArmEvents.h"
#include <cstdlib>
#include "hbt/src/perf_event/PmuDevices.h"

#include <gtest/gtest.h>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

std::string kTestRootEnvKey = "testroot";

unsigned int kDeviceEnum = 0;

auto default_pmu_manager(facebook::hbt::CpuInfo cpu_info) {
  // Load CPU Info
  auto pmu_manager = PmuDeviceManager(cpu_info);
  EXPECT_EQ(pmu_manager.getNumPmus(), 0);

  // Create a PMU.
  auto pmu = std::make_shared<PmuDevice>(
      "armv8_pmuv3",
      PmuType::armv8_pmuv3,
      kDeviceEnum,
      PERF_TYPE_RAW,
      "A Dummy armv8_pmuv3 device",
      true);

  pmu_manager.addPmu(pmu);
  EXPECT_EQ(pmu_manager.getNumPmus(), 1);

  return pmu_manager;
}

auto neoverse_v3_pmu_manager(facebook::hbt::CpuInfo cpu_info) {
  auto pmu_manager = default_pmu_manager(cpu_info);
  pmu_manager.addPmu(
      std::make_shared<PmuDevice>(
          "arm_cspmu_mc",
          PmuType::arm_cspmu_mc,
          kDeviceEnum,
          200,
          "A dummy Phoenix memory-controller PMU",
          true));
  pmu_manager.addPmu(
      std::make_shared<PmuDevice>(
          "arm_cmn",
          PmuType::arm_cmn,
          kDeviceEnum,
          201,
          "A dummy Phoenix CMN PMU",
          true));
  return pmu_manager;
}

TEST(ArmEventsTest, ScanPmu) {
  neoverse_v2::setTestRootDir(getenv(kTestRootEnvKey.c_str()));
  auto cpu_info = CpuInfo::load();
  cpu_info.cpu_arch = CpuArch::NEOVERSE_V2;
  auto pmu_manager = default_pmu_manager(cpu_info);

  addArmEvents(cpu_info, pmu_manager);

  auto pmu = pmu_manager.getPmuGroups().at(PmuType::armv8_pmuv3);
  EXPECT_EQ(pmu.at(kDeviceEnum)->getEventDefs().size(), 4);

  auto event1 = pmu_manager.findEventDef("cpu_cycles");
  EXPECT_TRUE(event1 != nullptr);
  EXPECT_EQ(event1->id, "cpu_cycles");
  EXPECT_EQ(event1->pmu_type, PmuType::armv8_pmuv3);
  EXPECT_EQ(event1->encoding.code, 0x11);

  auto event2 = pmu_manager.findEventDef("bad_event_config");
  EXPECT_TRUE(event2 == nullptr);

  auto event3 = pmu_manager.findEventDef("bad_event_field");
  EXPECT_TRUE(event3 == nullptr);
}

TEST(ArmEventsTest, AddArmEvents) {
  neoverse_v2::setTestRootDir(getenv(kTestRootEnvKey.c_str()));

  auto cpu_info = CpuInfo::load();
  cpu_info.cpu_arch = CpuArch::UNKNOWN;

  auto pmu_manager = default_pmu_manager(cpu_info);

  addArmEvents(cpu_info, pmu_manager);

  auto pmu = pmu_manager.getPmuGroups().at(PmuType::armv8_pmuv3);
  EXPECT_EQ(pmu.at(kDeviceEnum)->getEventDefs().size(), 0);
}

TEST(ArmEventsTest, AddNeoverseV3MemoryEvents) {
  neoverse_v2::setTestRootDir(getenv(kTestRootEnvKey.c_str()));

  auto cpu_info = CpuInfo::load();
  cpu_info.cpu_arch = CpuArch::NEOVERSE_V3;
  auto pmu_manager = neoverse_v3_pmu_manager(cpu_info);

  addArmEvents(cpu_info, pmu_manager);

  struct ExpectedEvent {
    const char* id;
    PmuType pmuType;
    uint64_t code;
    int scaleFactor;
  };
  const std::vector<ExpectedEvent> expected{
      {"total_data_beats", PmuType::arm_cspmu_mc, 0, 32},
      {"hns_mc_reqs_local_sn", PmuType::arm_cmn, 0x080D0200, 64},
      {"hns_mc_reqs_remote_sn", PmuType::arm_cmn, 0x083B0200, 64},
  };

  for (const auto& expectedEvent : expected) {
    const auto event = pmu_manager.findEventDef(expectedEvent.id);
    ASSERT_NE(event, nullptr) << expectedEvent.id;
    EXPECT_EQ(event->pmu_type, expectedEvent.pmuType) << expectedEvent.id;
    EXPECT_EQ(event->encoding.code, expectedEvent.code) << expectedEvent.id;
    ASSERT_TRUE(event->scale_data.has_value()) << expectedEvent.id;
    EXPECT_EQ(
        std::get<int>(event->scale_data->scale_factor),
        expectedEvent.scaleFactor)
        << expectedEvent.id;
    EXPECT_EQ(event->scale_data->scale_unit, ScaleUnit::Bytes)
        << expectedEvent.id;
  }
}

TEST(ArmEventsTest, DoesNotAddNeoverseV3MemoryEventsOnV2) {
  neoverse_v2::setTestRootDir(getenv(kTestRootEnvKey.c_str()));

  auto cpu_info = CpuInfo::load();
  cpu_info.cpu_arch = CpuArch::NEOVERSE_V2;
  auto pmu_manager = neoverse_v3_pmu_manager(cpu_info);

  addArmEvents(cpu_info, pmu_manager);

  EXPECT_EQ(pmu_manager.findEventDef("total_data_beats"), nullptr);
  EXPECT_EQ(pmu_manager.findEventDef("hns_mc_reqs_local_sn"), nullptr);
  EXPECT_EQ(pmu_manager.findEventDef("hns_mc_reqs_remote_sn"), nullptr);
}

TEST(ArmEventsTest, DoesNotAddPhoenixMemoryEventsWithoutDmcPmu) {
  neoverse_v2::setTestRootDir(getenv(kTestRootEnvKey.c_str()));

  auto cpu_info = CpuInfo::load();
  cpu_info.cpu_arch = CpuArch::NEOVERSE_V3;
  auto pmu_manager = default_pmu_manager(cpu_info);
  pmu_manager.addPmu(
      std::make_shared<PmuDevice>(
          "arm_cmn",
          PmuType::arm_cmn,
          kDeviceEnum,
          201,
          "A non-Phoenix CMN PMU",
          true));

  addArmEvents(cpu_info, pmu_manager);

  EXPECT_EQ(pmu_manager.findEventDef("total_data_beats"), nullptr);
  EXPECT_EQ(pmu_manager.findEventDef("hns_mc_reqs_local_sn"), nullptr);
  EXPECT_EQ(pmu_manager.findEventDef("hns_mc_reqs_remote_sn"), nullptr);
}
