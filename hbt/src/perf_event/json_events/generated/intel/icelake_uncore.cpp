// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto generated for hbt. Do not manually edit.
// @generated

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace icelake_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
/*
  Events from icelake_uncore.json (3 events).

  Supported SKUs:
      - Arch: x86, Model: ICL id: 125
      - Arch: x86, Model: ICL id: 126
*/
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.ALL",
      EventDef::Encoding{.code = 0x81, .umask = 0x01, .cmask = 0},
      R"(Total number of all outgoing entries allocated. Accounts for Coherent and non-coherent traffic.)",
      R"(Total number of all outgoing entries allocated. Accounts for Coherent and non-coherent traffic.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_COH_TRK_REQUESTS.ALL",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .cmask = 0},
      R"(Number of entries allocated. Account for Any type: e.g. Snoop,  etc.)",
      R"(Number of entries allocated. Account for Any type: e.g. Snoop,  etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ncu,
      "UNC_CLOCK.SOCKET",
      EventDef::Encoding{.code = 0x00, .umask = 0x01, .cmask = 0},
      R"(This 48-bit fixed counter counts the UCLK cycles.)",
      R"(This 48-bit fixed counter counts the UCLK cycles.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace icelake_uncore
} // namespace facebook::hbt::perf_event::generated
