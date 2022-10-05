// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/AmdEvents.h"

namespace facebook::hbt::perf_event {

namespace milan {
void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "cpu_cycles",
          EventDef::Encoding{.code = amd_msr::kUnhaltedCycles.val},
          "CPU cycles.",
          "Actual CPU cycles. Depends on frequency scaling, turbo mode and other effects."),
      std::vector<EventId>({"cpu-cycles", "cycles"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "instructions",
          EventDef::Encoding{.code = amd_msr::kRetiredInstructions.val},
          "Instructions retired.",
          "Instructions executed. Does not count speculative execution."),
      std::vector<EventId>({"retired_instructions", "retired-instructions"}));
}
} // namespace milan

void addAmdEvents(const CpuInfo& cpu_info, PmuDeviceManager& pmu_manager) {
  // When multiple families/models are in the fleet, add a switch stmt similar
  // to addEvents in json_events/generated/intel/JsonEvents.h
  switch (cpu_info.cpu_arch) {
    case CpuArch::MILAN:
      milan::addEvents(pmu_manager);
      break;
    default:
      HBT_LOG_ERROR()
          << "Attempting to add AMD events, but model is not supported";
      break;
  }
}

} // namespace facebook::hbt::perf_event
