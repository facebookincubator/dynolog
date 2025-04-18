// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/ArmEvents.h"
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iomanip>

namespace facebook::hbt::perf_event {

namespace neoverse_v2 {

std::string rootDir_;

void setTestRootDir(const std::string& rootDir) {
  rootDir_ = rootDir;
}

namespace {

std::string getPmuName(const PmuType& pmu_type) {
  auto res = PmuTypeToStr(pmu_type);
  if (pmu_type != PmuType::cs_etm) {
    res += "_0";
  }
  return res;
}

} // namespace

void scanPmu(PmuDeviceManager& pmu_manager, PmuType pmu_type) {
  const std::string pmu_events_path = rootDir_ +
      "/sys/bus/event_source/devices/" + getPmuName(pmu_type) + "/events";

  if (!std::filesystem::is_directory(pmu_events_path)) {
    HBT_LOG_WARNING() << "No events found for "
                      << std::quoted(getPmuName(pmu_type)) << " in sysfs";
    return;
  }

  // TODO: Don't assume event:0-32 is only field
  for (const auto& event :
       std::filesystem::directory_iterator(pmu_events_path)) {
    const std::string& event_name = event.path().filename();
    HBT_LOG_INFO() << "Found event: " << event_name;
    std::ifstream eventConf;
    std::string configEntry;
    eventConf.open(event.path().string());
    if (!eventConf.is_open()) {
      HBT_LOG_WARNING() << "Failed to open event config: " << event_name;
      continue;
    }
    uint64_t code = std::numeric_limits<uint64_t>::max();
    bool isValidConfig = true;
    // Config uses the format: field1=<val>,field2=<val>,field3=<val>,...
    // For Neoverse v2 and Nvidia Grace uncores, all perf_events are:
    // event=<val>
    while (std::getline(eventConf, configEntry, ',')) {
      auto pos = configEntry.find('=');
      if (pos == std::string::npos) {
        HBT_LOG_WARNING() << "Invalid event config: " << event.path().filename()
                          << " -- " << configEntry;
        isValidConfig = false;
        break;
      }
      auto field = configEntry.substr(0, pos);
      if (field != "event" && field != "configid") {
        HBT_LOG_WARNING()
            << "HBT does not support the perf_event config field: " << field;
        isValidConfig = false;
        break;
      }
      // Assume config is only event=<value>
      code = std::stoul(configEntry.substr(pos + 1), nullptr, 16);
    }
    if (isValidConfig && code != std::numeric_limits<uint64_t>::max()) {
      pmu_manager.addEvent(std::make_shared<EventDef>(
          pmu_type,
          event_name,
          EventDef::Encoding{.code = code},
          event_name + " (auto-generated)",
          "Event auto-generate from /sys/devices/<pmu>/events/<event>, please see architecure documentation for event details."));
    } else {
      HBT_LOG_WARNING() << "Failed to parse config " << configEntry << " for "
                        << event_name;
    }
  }
}

void addEvents(PmuDeviceManager& pmu_manager) {
  scanPmu(pmu_manager, PmuType::armv8_pmuv3);
  scanPmu(pmu_manager, PmuType::cs_etm);
  scanPmu(pmu_manager, PmuType::nvidia_scf_pmu);
  scanPmu(pmu_manager, PmuType::nvidia_nvlink_c2c0_pmu);
  scanPmu(pmu_manager, PmuType::nvidia_nvlink_c2c1_pmu);
  scanPmu(pmu_manager, PmuType::nvidia_pcie_pmu);

  // Add Neoverse v2 PMU events not found in sysfs
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::armv8_pmuv3,
      "FP_HP_SPEC",
      EventDef::Encoding{.code = 0x8014},
      "Floating-point operation speculatively executed, half precision",
      "Counts speculatively executed half precision floating point operations."));
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::armv8_pmuv3,
      "FP_SP_SPEC",
      EventDef::Encoding{.code = 0x8018},
      "Floating-point operation speculatively executed, single precision",
      "Counts speculatively executed single precision floating point operations."));
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::armv8_pmuv3,
      "FP_DP_SPEC",
      EventDef::Encoding{.code = 0x801C},
      "Floating-point operation speculatively executed, double precision",
      "Counts speculatively executed double precision floating point operations."));
}

} // namespace neoverse_v2

void addArmEvents(const CpuInfo& cpu_info, PmuDeviceManager& pmu_manager) {
  // When multiple families/models are in the fleet, add a switch stmt similar
  // to addEvents in json_events/generated/intel/JsonEvents.h
  switch (cpu_info.cpu_arch) {
    case CpuArch::NEOVERSE_V2:
      // With ARM, multiple CPUs can use the same CPU Core, but have different
      // uncores
      // TODO: Provide SoC breakdown in addition to CPU model
      neoverse_v2::addEvents(pmu_manager);
      break;
    default:
      HBT_LOG_ERROR()
          << "Attempting to add ARM events, but model is not supported";
      break;
  }
}

} // namespace facebook::hbt::perf_event
