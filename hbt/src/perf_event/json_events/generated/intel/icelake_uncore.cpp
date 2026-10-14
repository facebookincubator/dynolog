// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto generated for hbt. Do not manually edit.
// @generated

#include <array>
#include <cstdint>
#include "hbt/src/perf_event/StaticEventDef.h"
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace icelake_uncore {
namespace {

/*
  Events from icelake_uncore.json (3 events).

  Supported SKUs:
      - Arch: x86, Model: ICL id: 125
      - Arch: x86, Model: ICL id: 126
*/
constexpr std::array<StaticEventDef, 0> kAllowlistedEvents{};

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 3> kFullOnlyEvents{{
    {
        .pmu_type = PmuType::uncore_ncu,
        .id = "UNC_CLOCK.SOCKET",
        .encoding =
            {
                .code = 0x0ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "This 48-bit fixed counter counts the UCLK cycles.",
        .full_desc = "This 48-bit fixed counter counts the UCLK cycles.",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_COH_TRK_REQUESTS.ALL",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of entries allocated. Account for Any type: e.g. Snoop,  etc.",
        .full_desc =
            "Number of entries allocated. Account for Any type: e.g. Snoop,  etc.",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_TRK_REQUESTS.ALL",
        .encoding =
            {
                .code = 0x81ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Total number of all outgoing entries allocated. Accounts for Coherent and non-coherent traffic.",
        .full_desc =
            "Total number of all outgoing entries allocated. Accounts for Coherent and non-coherent traffic.",
    },
}};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

} // namespace

void addEvents(PmuDeviceManager& pmu_manager) {
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addStaticEventDefs(kFullOnlyEvents);
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace icelake_uncore
} // namespace facebook::hbt::perf_event::generated
