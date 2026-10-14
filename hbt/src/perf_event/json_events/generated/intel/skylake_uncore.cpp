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
namespace skylake_uncore {
namespace {

/*
  Events from skylake_uncore.json (23 events).

  Supported SKUs:
      - Arch: x86, Model: SKL id: 78
      - Arch: x86, Model: SKL id: 94
      - Arch: x86, Model: SKL id: 142
      - Arch: x86, Model: SKL id: 158
      - Arch: x86, Model: SKL id: 165
      - Arch: x86, Model: SKL id: 166
*/
constexpr std::array<StaticEventDef, 0> kAllowlistedEvents{};

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 23> kFullOnlyEvents{{
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.ANY_ES",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x86ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup any request that access cache and found line in E or S-state",
        .full_desc =
            "L3 Lookup any request that access cache and found line in E or S-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.ANY_I",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x88ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup any request that access cache and found line in I-state",
        .full_desc =
            "L3 Lookup any request that access cache and found line in I-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.ANY_M",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x81ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup any request that access cache and found line in M-state",
        .full_desc =
            "L3 Lookup any request that access cache and found line in M-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.ANY_MESI",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x8FULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup any request that access cache and found line in MESI-state",
        .full_desc =
            "L3 Lookup any request that access cache and found line in MESI-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.READ_ES",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x16ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup read request that access cache and found line in E or S-state",
        .full_desc =
            "L3 Lookup read request that access cache and found line in E or S-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.READ_I",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x18ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup read request that access cache and found line in I-state",
        .full_desc =
            "L3 Lookup read request that access cache and found line in I-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.READ_MESI",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x1FULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup read request that access cache and found line in any MESI-state",
        .full_desc =
            "L3 Lookup read request that access cache and found line in any MESI-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.WRITE_ES",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x26ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup write request that access cache and found line in E or S-state",
        .full_desc =
            "L3 Lookup write request that access cache and found line in E or S-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.WRITE_M",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x21ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup write request that access cache and found line in M-state",
        .full_desc =
            "L3 Lookup write request that access cache and found line in M-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_CACHE_LOOKUP.WRITE_MESI",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x2FULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "L3 Lookup write request that access cache and found line in MESI-state",
        .full_desc =
            "L3 Lookup write request that access cache and found line in MESI-state.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_XSNP_RESPONSE.HITM_XCORE",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x48ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "A cross-core snoop initiated by this Cbox due to processor core memory request which hits a modified line in some processor core.",
        .full_desc =
            "A cross-core snoop initiated by this Cbox due to processor core memory request which hits a modified line in some processor core.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_XSNP_RESPONSE.HIT_XCORE",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x44ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "A cross-core snoop initiated by this Cbox due to processor core memory request which hits a non-modified line in some processor core.",
        .full_desc =
            "A cross-core snoop initiated by this Cbox due to processor core memory request which hits a non-modified line in some processor core.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_XSNP_RESPONSE.MISS_EVICTION",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x81ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "A cross-core snoop resulted from L3 Eviction which misses in some processor core.",
        .full_desc =
            "A cross-core snoop resulted from L3 Eviction which misses in some processor core.",
    },
    {
        .pmu_type = PmuType::uncore_cbox,
        .id = "UNC_CBO_XSNP_RESPONSE.MISS_XCORE",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x41ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "A cross-core snoop initiated by this Cbox due to processor core memory request which misses in some processor core.",
        .full_desc =
            "A cross-core snoop initiated by this Cbox due to processor core memory request which misses in some processor core.",
    },
    {
        .pmu_type = PmuType::uncore_ncu,
        .id = "UNC_CLOCK.SOCKET",
        .encoding =
            {
                .code = 0x0ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "This 48-bit fixed counter counts the UCLK cycles",
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
            "Number of entries allocated. Account for Any type: e.g. Snoop, Core aperture, etc.",
        .full_desc =
            "Number of entries allocated. Account for Any type: e.g. Snoop, Core aperture, etc.",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_TRK_OCCUPANCY.ALL",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of all Core entries outstanding for the memory controller. The outstanding interval starts after LLC miss till return of first data chunk. Accounts for Coherent and non-coherent traffic.",
        .full_desc =
            "Number of all Core entries outstanding for the memory controller. The outstanding interval starts after LLC miss till return of first data chunk. Accounts for Coherent and non-coherent traffic.",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_TRK_OCCUPANCY.CYCLES_WITH_ANY_REQUEST",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles with at least one request outstanding is waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.",
        .full_desc =
            "Cycles with at least one request outstanding is waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_TRK_OCCUPANCY.DATA_READ",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of Core Data Read entries outstanding for the memory controller. The outstanding interval starts after LLC miss till return of first data chunk.",
        .full_desc =
            "Number of Core Data Read entries outstanding for the memory controller. The outstanding interval starts after LLC miss till return of first data chunk.",
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
        .brief_desc = "UNC_ARB_TRK_REQUESTS.ALL",
        .full_desc = "UNC_ARB_TRK_REQUESTS.ALL",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_TRK_REQUESTS.DATA_READ",
        .encoding =
            {
                .code = 0x81ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of Core coherent Data Read requests sent to memory controller whose data is returned directly to requesting agent.",
        .full_desc =
            "Number of Core coherent Data Read requests sent to memory controller whose data is returned directly to requesting agent.",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_TRK_REQUESTS.DRD_DIRECT",
        .encoding =
            {
                .code = 0x81ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of Core coherent Data Read requests sent to memory controller whose data is returned directly to requesting agent.",
        .full_desc =
            "Number of Core coherent Data Read requests sent to memory controller whose data is returned directly to requesting agent.",
    },
    {
        .pmu_type = PmuType::uncore_arb,
        .id = "UNC_ARB_TRK_REQUESTS.WRITES",
        .encoding =
            {
                .code = 0x81ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of Writes allocated - any write transactions: full/partials writes and evictions.",
        .full_desc =
            "Number of Writes allocated - any write transactions: full/partials writes and evictions.",
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

} // namespace skylake_uncore
} // namespace facebook::hbt::perf_event::generated
