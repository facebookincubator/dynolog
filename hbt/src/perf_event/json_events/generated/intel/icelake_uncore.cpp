// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

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
        - Arch: x86, Model: ICL id: 167
  */
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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ncu,
      "UNC_CLOCK.SOCKET",
      EventDef::Encoding{.code = 0x00, .umask = 0x01, .cmask = 0},
      R"(UNC_CLOCK.SOCKET)",
      R"(UNC_CLOCK.SOCKET)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace icelake_uncore
} // namespace facebook::hbt::perf_event::generated
