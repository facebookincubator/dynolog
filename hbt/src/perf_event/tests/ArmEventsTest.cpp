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
