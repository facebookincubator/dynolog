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
namespace knightslanding_uncore {
namespace {

/*
  Events from knightslanding_uncore.json (459 events).

  Supported SKUs:
      - Arch: x86, Model: KNL id: 87
      - Arch: x86, Model: KNL id: 133
*/
constexpr std::array<StaticEventDef, 2> kAllowlistedEvents{{
    {
        .pmu_type = PmuType::uncore_imc_dclk,
        .id = "UNC_M_CAS_COUNT.RD",
        .encoding =
            {
                .code = 0x3ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CAS Reads",
        .full_desc = "CAS Reads",
    },
    {
        .pmu_type = PmuType::uncore_imc_dclk,
        .id = "UNC_M_CAS_COUNT.WR",
        .encoding =
            {
                .code = 0x3ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CAS Writes",
        .full_desc = "CAS Writes",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 457> kFullOnlyEvents{{
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_C_TOR_INSERTS.IPQ_HIT",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x18ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IPQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IPQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_C_TOR_INSERTS.IPQ_MISS",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x28ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IPQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IPQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_C_TOR_INSERTS.IRQ_HIT",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x11ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_C_TOR_INSERTS.IRQ_MISS",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x21ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_C_TOR_INSERTS.LOC_ALL",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x37ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ or PRQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ or PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_C_TOR_INSERTS.PRQ_HIT",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x14ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -PRQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_C_TOR_INSERTS.PRQ_MISS",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x24ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -PRQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR0",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 0",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR1",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 1",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR2",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 2",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR3",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 3",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR4",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 4",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR5",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 5",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR6",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 6",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED.TGR7",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 7",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x81ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 0-7",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_ACQUIRED_EXT.TGR8",
        .encoding =
            {
                .code = 0x81ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Acquired For Transgress 8",
        .full_desc = "CMS Agent0 AD Credits Acquired For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR0",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 0",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR1",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 1",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR2",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 2",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR3",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 3",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR4",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 4",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR5",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 5",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR6",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 6",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR7",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 7",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x83ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 0-7",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_AD_CRD_OCCUPANCY_EXT.TGR8",
        .encoding =
            {
                .code = 0x83ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 AD Credits Occupancy For Transgress 8",
        .full_desc = "CMS Agent0 AD Credits Occupancy For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR0",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 0",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR1",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 1",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR2",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 2",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR3",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 3",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR4",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 4",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR5",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 5",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR6",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 6",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED.TGR7",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 7",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 0-7",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_ACQUIRED_EXT.TGR8",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Acquired For Transgress 8",
        .full_desc = "CMS Agent0 BL Credits Acquired For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR0",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 0",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR1",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 1",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR2",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 2",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR3",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 3",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR4",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 4",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR5",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 5",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR6",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 6",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR7",
        .encoding =
            {
                .code = 0x8AULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 7",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x8BULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 0-7",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_BL_CRD_OCCUPANCY_EXT.TGR8",
        .encoding =
            {
                .code = 0x8BULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent0 BL Credits Occupancy For Transgress 8",
        .full_desc = "CMS Agent0 BL Credits Occupancy For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR0",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR1",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 1",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR2",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 2",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR3",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 3",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR4",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 4",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR5",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 5",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR6",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 6",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR7",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.TGR8",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 8",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR0",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR1",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 1",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR2",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 2",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR3",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 3",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR4",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 4",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR5",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 5",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR6",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 6",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR7",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0xD5ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.TGR8",
        .encoding =
            {
                .code = 0xD5ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 8",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR0",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 0",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR1",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 1",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR2",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 2",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR3",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 3",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR4",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 4",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR5",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 5",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR6",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 6",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED.TGR7",
        .encoding =
            {
                .code = 0x84ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 7",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 0-7",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_ACQUIRED_EXT.TGR8",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Acquired For Transgress 8",
        .full_desc = "CMS Agent1 AD Credits Acquired For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR0",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 0",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR1",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 1",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR2",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 2",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR3",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 3",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR4",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 4",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR5",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 5",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR6",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 6",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR7",
        .encoding =
            {
                .code = 0x86ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 7",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x87ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 0-7",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_AD_CRD_OCCUPANCY_EXT.TGR8",
        .encoding =
            {
                .code = 0x87ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 AD Credits Occupancy For Transgress 8",
        .full_desc = "CMS Agent1 AD Credits Occupancy For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR0",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 0",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR1",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 1",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR2",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 2",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR3",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 3",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR4",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 4",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR5",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 5",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR6",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 6",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED.TGR7",
        .encoding =
            {
                .code = 0x8CULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 7",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x8DULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 0-7",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_ACQUIRED_EXT.TGR8",
        .encoding =
            {
                .code = 0x8DULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Acquired For Transgress 8",
        .full_desc = "CMS Agent1 BL Credits Acquired For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR0",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 0",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR1",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 1",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR2",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 2",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR3",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 3",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR4",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 4",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR5",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 5",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR6",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 6",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR7",
        .encoding =
            {
                .code = 0x8EULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 7",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0x8FULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 0-7",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_BL_CRD_OCCUPANCY_EXT.TGR8",
        .encoding =
            {
                .code = 0x8FULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Agent1 BL Credits Occupancy For Transgress 8",
        .full_desc = "CMS Agent1 BL Credits Occupancy For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR0",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR1",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 1",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR2",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 2",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR3",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 3",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR4",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 4",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR5",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 5",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR6",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 6",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR7",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0xD3ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.TGR8",
        .encoding =
            {
                .code = 0xD3ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 8",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR0",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR1",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 1",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR2",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 2",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 2",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR3",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 3",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 3",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR4",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 4",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 4",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR5",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 5",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 5",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR6",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 6",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 6",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR7",
        .encoding =
            {
                .code = 0xD6ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.ANY_OF_TGR0_THRU_TGR7",
        .encoding =
            {
                .code = 0xD7ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 0-7",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.TGR8",
        .encoding =
            {
                .code = 0xD7ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall on No AD Transgress Credits For Transgress 8",
        .full_desc = "Stall on No AD Transgress Credits For Transgress 8",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_CACHE_LINES_VICTIMIZED.E_STATE",
        .encoding =
            {
                .code = 0x37ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cacheable and UC.",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cacheable and UC.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_CACHE_LINES_VICTIMIZED.F_STATE",
        .encoding =
            {
                .code = 0x37ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_CACHE_LINES_VICTIMIZED.LOCAL",
        .encoding =
            {
                .code = 0x37ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Lines Victimized that Match NID",
        .full_desc = "Lines Victimized that Match NID",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_CACHE_LINES_VICTIMIZED.M_STATE",
        .encoding =
            {
                .code = 0x37ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Read transactions",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Read transactions",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_CACHE_LINES_VICTIMIZED.REMOTE",
        .encoding =
            {
                .code = 0x37ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Lines Victimized that Does Not Match NID",
        .full_desc = "Lines Victimized that Does Not Match NID",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_CACHE_LINES_VICTIMIZED.S_STATE",
        .encoding =
            {
                .code = 0x37ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_CLOCK",
        .encoding =
            {
                .code = 0xC0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uncore Clocks",
        .full_desc = "Uncore Clocks",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_ADS_USED.AD",
        .encoding =
            {
                .code = 0x9DULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal ADS Used",
        .full_desc = "CMS Horizontal ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_ADS_USED.AK",
        .encoding =
            {
                .code = 0x9DULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal ADS Used",
        .full_desc = "CMS Horizontal ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_ADS_USED.BL",
        .encoding =
            {
                .code = 0x9DULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal ADS Used",
        .full_desc = "CMS Horizontal ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_BYPASS.AD",
        .encoding =
            {
                .code = 0x9FULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Bypass. AD ring",
        .full_desc = "CMS Horizontal Egress Bypass. AD ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_BYPASS.AK",
        .encoding =
            {
                .code = 0x9FULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Bypass. AK ring",
        .full_desc = "CMS Horizontal Egress Bypass. AK ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_BYPASS.BL",
        .encoding =
            {
                .code = 0x9FULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Bypass. BL ring",
        .full_desc = "CMS Horizontal Egress Bypass. BL ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_BYPASS.IV",
        .encoding =
            {
                .code = 0x9FULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Bypass. IV ring",
        .full_desc = "CMS Horizontal Egress Bypass. IV ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_FULL.AD",
        .encoding =
            {
                .code = 0x96ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Full AD",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Full AD",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_FULL.AK",
        .encoding =
            {
                .code = 0x96ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Full AK",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Full AK",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_FULL.BL",
        .encoding =
            {
                .code = 0x96ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Full BL",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Full BL",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_FULL.IV",
        .encoding =
            {
                .code = 0x96ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Full IV",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Full IV",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_NE.AD",
        .encoding =
            {
                .code = 0x97ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Not Empty AD",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Not Empty AD",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_NE.AK",
        .encoding =
            {
                .code = 0x97ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Not Empty AK",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Not Empty AK",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_NE.BL",
        .encoding =
            {
                .code = 0x97ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Not Empty BL",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Not Empty BL",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_CYCLES_NE.IV",
        .encoding =
            {
                .code = 0x97ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Horizontal Egress Queue is Not Empty IV",
        .full_desc = "Cycles CMS Horizontal Egress Queue is Not Empty IV",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_INSERTS.AD",
        .encoding =
            {
                .code = 0x95ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Inserts AD",
        .full_desc = "CMS Horizontal Egress Inserts AD",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_INSERTS.AK",
        .encoding =
            {
                .code = 0x95ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Inserts AK",
        .full_desc = "CMS Horizontal Egress Inserts AK",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_INSERTS.BL",
        .encoding =
            {
                .code = 0x95ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Inserts BL",
        .full_desc = "CMS Horizontal Egress Inserts BL",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_INSERTS.IV",
        .encoding =
            {
                .code = 0x95ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Inserts IV",
        .full_desc = "CMS Horizontal Egress Inserts IV",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_NACK.AD",
        .encoding =
            {
                .code = 0x99ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress NACKs",
        .full_desc = "CMS Horizontal Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_NACK.AK",
        .encoding =
            {
                .code = 0x99ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress NACKs",
        .full_desc = "CMS Horizontal Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_NACK.BL",
        .encoding =
            {
                .code = 0x99ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress NACKs",
        .full_desc = "CMS Horizontal Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_NACK.IV",
        .encoding =
            {
                .code = 0x99ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress NACKs",
        .full_desc = "CMS Horizontal Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_OCCUPANCY.AD",
        .encoding =
            {
                .code = 0x94ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Occupancy AD",
        .full_desc = "CMS Horizontal Egress Occupancy AD",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_OCCUPANCY.AK",
        .encoding =
            {
                .code = 0x94ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Occupancy AK",
        .full_desc = "CMS Horizontal Egress Occupancy AK",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_OCCUPANCY.BL",
        .encoding =
            {
                .code = 0x94ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Occupancy BL",
        .full_desc = "CMS Horizontal Egress Occupancy BL",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_OCCUPANCY.IV",
        .encoding =
            {
                .code = 0x94ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Occupancy IV",
        .full_desc = "CMS Horizontal Egress Occupancy IV",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_STARVED.AD",
        .encoding =
            {
                .code = 0x9BULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Injection Starvation",
        .full_desc = "CMS Horizontal Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_STARVED.AK",
        .encoding =
            {
                .code = 0x9BULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Injection Starvation",
        .full_desc = "CMS Horizontal Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_STARVED.BL",
        .encoding =
            {
                .code = 0x9BULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Injection Starvation",
        .full_desc = "CMS Horizontal Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_HORZ_STARVED.IV",
        .encoding =
            {
                .code = 0x9BULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Horizontal Egress Injection Starvation",
        .full_desc = "CMS Horizontal Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_ORDERING.IV_SNP_GO_DN",
        .encoding =
            {
                .code = 0xAEULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements",
        .full_desc =
            "Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_ORDERING.IV_SNP_GO_UP",
        .encoding =
            {
                .code = 0xAEULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements",
        .full_desc =
            "Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_ADS_USED.AD_AG0",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical ADS Used",
        .full_desc = "CMS Vertical ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_ADS_USED.AD_AG1",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical ADS Used",
        .full_desc = "CMS Vertical ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_ADS_USED.AK_AG0",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical ADS Used",
        .full_desc = "CMS Vertical ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_ADS_USED.AK_AG1",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical ADS Used",
        .full_desc = "CMS Vertical ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_ADS_USED.BL_AG0",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical ADS Used",
        .full_desc = "CMS Vertical ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_ADS_USED.BL_AG1",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical ADS Used",
        .full_desc = "CMS Vertical ADS Used",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_BYPASS.AD_AG0",
        .encoding =
            {
                .code = 0x9EULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Bypass. AD ring agent 0",
        .full_desc = "CMS Vertical Egress Bypass. AD ring agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_BYPASS.AD_AG1",
        .encoding =
            {
                .code = 0x9EULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Bypass. AD ring agent 1",
        .full_desc = "CMS Vertical Egress Bypass. AD ring agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_BYPASS.AK_AG0",
        .encoding =
            {
                .code = 0x9EULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Bypass. AK ring agent 0",
        .full_desc = "CMS Vertical Egress Bypass. AK ring agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_BYPASS.AK_AG1",
        .encoding =
            {
                .code = 0x9EULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Bypass. AK ring agent 1",
        .full_desc = "CMS Vertical Egress Bypass. AK ring agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_BYPASS.BL_AG0",
        .encoding =
            {
                .code = 0x9EULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Bypass. BL ring agent 0",
        .full_desc = "CMS Vertical Egress Bypass. BL ring agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_BYPASS.BL_AG1",
        .encoding =
            {
                .code = 0x9EULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Bypass. BL ring agent 1",
        .full_desc = "CMS Vertical Egress Bypass. BL ring agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_BYPASS.IV",
        .encoding =
            {
                .code = 0x9EULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Bypass. IV ring agent 0",
        .full_desc = "CMS Vertical Egress Bypass. IV ring agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_FULL.AD_AG0",
        .encoding =
            {
                .code = 0x92ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Vertical Egress Queue Is Full AD - Agent 0",
        .full_desc = "Cycles CMS Vertical Egress Queue Is Full AD - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_FULL.AD_AG1",
        .encoding =
            {
                .code = 0x92ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Vertical Egress Queue Is Full AD - Agent 1",
        .full_desc = "Cycles CMS Vertical Egress Queue Is Full AD - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_FULL.AK_AG0",
        .encoding =
            {
                .code = 0x92ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Vertical Egress Queue Is Full AK - Agent 0",
        .full_desc = "Cycles CMS Vertical Egress Queue Is Full AK - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_FULL.AK_AG1",
        .encoding =
            {
                .code = 0x92ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Vertical Egress Queue Is Full AK - Agent 1",
        .full_desc = "Cycles CMS Vertical Egress Queue Is Full AK - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_FULL.BL_AG0",
        .encoding =
            {
                .code = 0x92ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Vertical Egress Queue Is Full BL - Agent 0",
        .full_desc = "Cycles CMS Vertical Egress Queue Is Full BL - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_FULL.BL_AG1",
        .encoding =
            {
                .code = 0x92ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Vertical Egress Queue Is Full BL - Agent 1",
        .full_desc = "Cycles CMS Vertical Egress Queue Is Full BL - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_FULL.IV_AG0",
        .encoding =
            {
                .code = 0x92ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles CMS Vertical Egress Queue Is Full IV - Agent 0",
        .full_desc = "Cycles CMS Vertical Egress Queue Is Full IV - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_NE.AD_AG0",
        .encoding =
            {
                .code = 0x93ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 0",
        .full_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_NE.AD_AG1",
        .encoding =
            {
                .code = 0x93ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 1",
        .full_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_NE.AK_AG0",
        .encoding =
            {
                .code = 0x93ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 0",
        .full_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_NE.AK_AG1",
        .encoding =
            {
                .code = 0x93ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 1",
        .full_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_NE.BL_AG0",
        .encoding =
            {
                .code = 0x93ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 0",
        .full_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_NE.BL_AG1",
        .encoding =
            {
                .code = 0x93ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 1",
        .full_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_CYCLES_NE.IV_AG0",
        .encoding =
            {
                .code = 0x93ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty IV - Agent 0",
        .full_desc =
            "Cycles CMS Vertical Egress Queue Is Not Empty IV - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_INSERTS.AD_AG0",
        .encoding =
            {
                .code = 0x91ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Allocations AD - Agent 0",
        .full_desc = "CMS Vert Egress Allocations AD - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_INSERTS.AD_AG1",
        .encoding =
            {
                .code = 0x91ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Allocations AD - Agent 1",
        .full_desc = "CMS Vert Egress Allocations AD - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_INSERTS.AK_AG0",
        .encoding =
            {
                .code = 0x91ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Allocations AK - Agent 0",
        .full_desc = "CMS Vert Egress Allocations AK - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_INSERTS.AK_AG1",
        .encoding =
            {
                .code = 0x91ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Allocations AK - Agent 1",
        .full_desc = "CMS Vert Egress Allocations AK - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_INSERTS.BL_AG0",
        .encoding =
            {
                .code = 0x91ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Allocations BL - Agent 0",
        .full_desc = "CMS Vert Egress Allocations BL - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_INSERTS.BL_AG1",
        .encoding =
            {
                .code = 0x91ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Allocations BL - Agent 1",
        .full_desc = "CMS Vert Egress Allocations BL - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_INSERTS.IV_AG0",
        .encoding =
            {
                .code = 0x91ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Allocations IV - Agent 0",
        .full_desc = "CMS Vert Egress Allocations IV - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_NACK.AD_AG0",
        .encoding =
            {
                .code = 0x98ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress NACKs",
        .full_desc = "CMS Vertical Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_NACK.AD_AG1",
        .encoding =
            {
                .code = 0x98ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress NACKs",
        .full_desc = "CMS Vertical Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_NACK.AK_AG0",
        .encoding =
            {
                .code = 0x98ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress NACKs Onto AK Ring",
        .full_desc = "CMS Vertical Egress NACKs Onto AK Ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_NACK.AK_AG1",
        .encoding =
            {
                .code = 0x98ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress NACKs",
        .full_desc = "CMS Vertical Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_NACK.BL_AG0",
        .encoding =
            {
                .code = 0x98ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress NACKs Onto BL Ring",
        .full_desc = "CMS Vertical Egress NACKs Onto BL Ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_NACK.BL_AG1",
        .encoding =
            {
                .code = 0x98ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress NACKs",
        .full_desc = "CMS Vertical Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_NACK.IV_AG0",
        .encoding =
            {
                .code = 0x98ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress NACKs",
        .full_desc = "CMS Vertical Egress NACKs",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_OCCUPANCY.AD_AG0",
        .encoding =
            {
                .code = 0x90ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Occupancy AD - Agent 0",
        .full_desc = "CMS Vert Egress Occupancy AD - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_OCCUPANCY.AD_AG1",
        .encoding =
            {
                .code = 0x90ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Occupancy AD - Agent 1",
        .full_desc = "CMS Vert Egress Occupancy AD - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_OCCUPANCY.AK_AG0",
        .encoding =
            {
                .code = 0x90ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Occupancy AK - Agent 0",
        .full_desc = "CMS Vert Egress Occupancy AK - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_OCCUPANCY.AK_AG1",
        .encoding =
            {
                .code = 0x90ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Occupancy AK - Agent 1",
        .full_desc = "CMS Vert Egress Occupancy AK - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_OCCUPANCY.BL_AG0",
        .encoding =
            {
                .code = 0x90ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Occupancy BL - Agent 0",
        .full_desc = "CMS Vert Egress Occupancy BL - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_OCCUPANCY.BL_AG1",
        .encoding =
            {
                .code = 0x90ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Occupancy BL - Agent 1",
        .full_desc = "CMS Vert Egress Occupancy BL - Agent 1",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_OCCUPANCY.IV_AG0",
        .encoding =
            {
                .code = 0x90ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vert Egress Occupancy IV - Agent 0",
        .full_desc = "CMS Vert Egress Occupancy IV - Agent 0",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_STARVED.AD_AG0",
        .encoding =
            {
                .code = 0x9AULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Injection Starvation",
        .full_desc = "CMS Vertical Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_STARVED.AD_AG1",
        .encoding =
            {
                .code = 0x9AULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Injection Starvation",
        .full_desc = "CMS Vertical Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_STARVED.AK_AG0",
        .encoding =
            {
                .code = 0x9AULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Injection Starvation Onto AK Ring",
        .full_desc = "CMS Vertical Egress Injection Starvation Onto AK Ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_STARVED.AK_AG1",
        .encoding =
            {
                .code = 0x9AULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Injection Starvation",
        .full_desc = "CMS Vertical Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_STARVED.BL_AG0",
        .encoding =
            {
                .code = 0x9AULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Injection Starvation Onto BL Ring",
        .full_desc = "CMS Vertical Egress Injection Starvation Onto BL Ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_STARVED.BL_AG1",
        .encoding =
            {
                .code = 0x9AULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Injection Starvation",
        .full_desc = "CMS Vertical Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_EGRESS_VERT_STARVED.IV_AG0",
        .encoding =
            {
                .code = 0x9AULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CMS Vertical Egress Injection Starvation",
        .full_desc = "CMS Vertical Egress Injection Starvation",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_FAST_ASSERTED.HORZ",
        .encoding =
            {
                .code = 0xA5ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts cycles source throttling is asserted - horizontal",
        .full_desc = "Counts cycles source throttling is asserted - horizontal",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_FAST_ASSERTED.VERT",
        .encoding =
            {
                .code = 0xA5ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts cycles source throttling is asserted - vertical",
        .full_desc = "Counts cycles source throttling is asserted - vertical",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AD_IN_USE.LEFT_EVEN",
        .encoding =
            {
                .code = 0xA7ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Even",
        .full_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AD_IN_USE.LEFT_ODD",
        .encoding =
            {
                .code = 0xA7ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Odd",
        .full_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AD_IN_USE.RIGHT_EVEN",
        .encoding =
            {
                .code = 0xA7ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Even",
        .full_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AD_IN_USE.RIGHT_ODD",
        .encoding =
            {
                .code = 0xA7ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Odd",
        .full_desc =
            "Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AK_IN_USE.LEFT_EVEN",
        .encoding =
            {
                .code = 0xA9ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Even",
        .full_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AK_IN_USE.LEFT_ODD",
        .encoding =
            {
                .code = 0xA9ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Odd",
        .full_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AK_IN_USE.RIGHT_EVEN",
        .encoding =
            {
                .code = 0xA9ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Even",
        .full_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_AK_IN_USE.RIGHT_ODD",
        .encoding =
            {
                .code = 0xA9ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Odd",
        .full_desc =
            "Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_BL_IN_USE.LEFT_EVEN",
        .encoding =
            {
                .code = 0xABULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Even",
        .full_desc =
            "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_BL_IN_USE.LEFT_ODD",
        .encoding =
            {
                .code = 0xABULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Odd",
        .full_desc =
            "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_BL_IN_USE.RIGHT_EVEN",
        .encoding =
            {
                .code = 0xABULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Even",
        .full_desc =
            "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_BL_IN_USE.RIGHT_ODD",
        .encoding =
            {
                .code = 0xABULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Odd",
        .full_desc =
            "Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_IV_IN_USE.LEFT",
        .encoding =
            {
                .code = 0xADULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Left",
        .full_desc =
            "Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Left",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_HORZ_RING_IV_IN_USE.RIGHT",
        .encoding =
            {
                .code = 0xADULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Right",
        .full_desc =
            "Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Right",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INSERTS.IPQ",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IPQ",
        .full_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IPQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INSERTS.IRQ",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ",
        .full_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INSERTS.IRQ_REJ",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ Rejected",
        .full_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ Rejected",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INSERTS.PRQ",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ",
        .full_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INSERTS.PRQ_REJ",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ Rejected",
        .full_desc =
            "Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ Rejected",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INT_STARVED.IPQ",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with the IPQ in Internal Starvation.",
        .full_desc = "Cycles with the IPQ in Internal Starvation.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INT_STARVED.IRQ",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with the IRQ in Internal Starvation.",
        .full_desc = "Cycles with the IRQ in Internal Starvation.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INT_STARVED.ISMQ",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with the ISMQ in Internal Starvation.",
        .full_desc = "Cycles with the ISMQ in Internal Starvation.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_INT_STARVED.PRQ",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress internal starvation cycles. Counts cycles in internal starvation. This occurs when one or more of the entries in the ingress queue are being starved out by other entries in the queue.",
        .full_desc =
            "Ingress internal starvation cycles. Counts cycles in internal starvation. This occurs when one or more of the entries in the ingress queue are being starved out by other entries in the queue.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_OCCUPANCY.IPQ",
        .encoding =
            {
                .code = 0x11ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IPQ",
        .full_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IPQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_OCCUPANCY.IRQ",
        .encoding =
            {
                .code = 0x11ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ",
        .full_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_OCCUPANCY.IRQ_REJ",
        .encoding =
            {
                .code = 0x11ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ Rejected",
        .full_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ Rejected",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_OCCUPANCY.PRQ",
        .encoding =
            {
                .code = 0x11ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ",
        .full_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_OCCUPANCY.PRQ_REJ",
        .encoding =
            {
                .code = 0x11ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ Rejected",
        .full_desc =
            "Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ Rejected",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.AD_REQ_VN0",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.AD_RSP_VN0",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.AK_NON_UPI",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_NCB_VN0",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_NCS_VN0",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_RSP_VN0",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_WB_VN0",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ0_REJECT.IV_NON_UPI",
        .encoding =
            {
                .code = 0x22ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ1_REJECT.ALLOW_SNP",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ1_REJECT.ANY_REJECT_IPQ0",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ1_REJECT.PA_MATCH",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ1_REJECT.SF_VICTIM",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IPQ1_REJECT.SF_WAY",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Probe Queue Rejects",
        .full_desc = "Ingress Probe Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.AD_REQ_VN0",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.AD_RSP_VN0",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.AK_NON_UPI",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_NCB_VN0",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_NCS_VN0",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_RSP_VN0",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_WB_VN0",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ0_REJECT.IV_NON_UPI",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ1_REJECT.ALLOW_SNP",
        .encoding =
            {
                .code = 0x19ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ1_REJECT.ANY_REJECT_IRQ0",
        .encoding =
            {
                .code = 0x19ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ1_REJECT.PA_MATCH",
        .encoding =
            {
                .code = 0x19ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ1_REJECT.SF_VICTIM",
        .encoding =
            {
                .code = 0x19ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_IRQ1_REJECT.SF_WAY",
        .encoding =
            {
                .code = 0x19ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.AD_REQ_VN0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.AD_RSP_VN0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.AK_NON_UPI",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_NCB_VN0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_NCS_VN0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_RSP_VN0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_WB_VN0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.IV_NON_UPI",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Rejects",
        .full_desc = "ISMQ Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.AD_REQ_VN0",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.AD_RSP_VN0",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.AK_NON_UPI",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_NCB_VN0",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_NCS_VN0",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_RSP_VN0",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_WB_VN0",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.IV_NON_UPI",
        .encoding =
            {
                .code = 0x2CULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ISMQ Retries",
        .full_desc = "ISMQ Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.AD_REQ_VN0",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.AD_RSP_VN0",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.AK_NON_UPI",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_NCB_VN0",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_NCS_VN0",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_RSP_VN0",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_WB_VN0",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER0_RETRY.IV_NON_UPI",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER1_RETRY.ALLOW_SNP",
        .encoding =
            {
                .code = 0x2FULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER1_RETRY.ANY_REJECT_IRQ0",
        .encoding =
            {
                .code = 0x2FULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER1_RETRY.PA_MATCH",
        .encoding =
            {
                .code = 0x2FULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER1_RETRY.SF_VICTIM",
        .encoding =
            {
                .code = 0x2FULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_OTHER1_RETRY.SF_WAY",
        .encoding =
            {
                .code = 0x2FULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Queue Retries",
        .full_desc = "Other Queue Retries",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.AD_REQ_VN0",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.AD_RSP_VN0",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.AK_NON_UPI",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_NCB_VN0",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_NCS_VN0",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_RSP_VN0",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_WB_VN0",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ0_REJECT.IV_NON_UPI",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ1_REJECT.ALLOW_SNP",
        .encoding =
            {
                .code = 0x21ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ1_REJECT.ANY_REJECT_IRQ0",
        .encoding =
            {
                .code = 0x21ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ1_REJECT.PA_MATCH",
        .encoding =
            {
                .code = 0x21ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ1_REJECT.SF_VICTIM",
        .encoding =
            {
                .code = 0x21ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_PRQ1_REJECT.SF_WAY",
        .encoding =
            {
                .code = 0x21ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Ingress Request Queue Rejects",
        .full_desc = "Ingress Request Queue Rejects",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.AD_REQ_VN0",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.AD_RSP_VN0",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.AK_NON_UPI",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_NCB_VN0",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_NCS_VN0",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_RSP_VN0",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_WB_VN0",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.IV_NON_UPI",
        .encoding =
            {
                .code = 0x2AULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.ALLOW_SNP",
        .encoding =
            {
                .code = 0x2BULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.ANY_REJECT_IRQ0",
        .encoding =
            {
                .code = 0x2BULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.PA_MATCH",
        .encoding =
            {
                .code = 0x2BULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.SF_VICTIM",
        .encoding =
            {
                .code = 0x2BULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.SF_WAY",
        .encoding =
            {
                .code = 0x2BULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
        .full_desc =
            "REQUESTQ includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_MISC.CV0_PREF_MISS",
        .encoding =
            {
                .code = 0x39ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Miscellaneous events in the Cbo. CV0 Prefetch Miss",
        .full_desc = "Miscellaneous events in the Cbo. CV0 Prefetch Miss",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_MISC.CV0_PREF_VIC",
        .encoding =
            {
                .code = 0x39ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Miscellaneous events in the Cbo. CV0 Prefetch Victim",
        .full_desc = "Miscellaneous events in the Cbo. CV0 Prefetch Victim",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_MISC.RFO_HIT_S",
        .encoding =
            {
                .code = 0x39ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Miscellaneous events in the Cbo. RFO HitS",
        .full_desc = "Miscellaneous events in the Cbo. RFO HitS",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_MISC.RSPI_WAS_FSE",
        .encoding =
            {
                .code = 0x39ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Miscellaneous events in the Cbo. Silent Snoop Eviction",
        .full_desc = "Miscellaneous events in the Cbo. Silent Snoop Eviction",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_MISC.WC_ALIASING",
        .encoding =
            {
                .code = 0x39ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Miscellaneous events in the Cbo. Write Combining Aliasing",
        .full_desc =
            "Miscellaneous events in the Cbo. Write Combining Aliasing",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_HORZ.AD",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type.",
        .full_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_HORZ.AK",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type - Acknowledgements to core",
        .full_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type - Acknowledgements to core",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_HORZ.BL",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type - Data Responses to core.",
        .full_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type - Data Responses to core.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_HORZ.IV",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type - Snoops of processor's cache.",
        .full_desc =
            "Number of incoming messages from the Horizontal ring that were bounced, by ring type - Snoops of processor's cache.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_VERT.AD",
        .encoding =
            {
                .code = 0xA0ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type.",
        .full_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_VERT.AK",
        .encoding =
            {
                .code = 0xA0ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type - Acknowledgements to core",
        .full_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type - Acknowledgements to core",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_VERT.BL",
        .encoding =
            {
                .code = 0xA0ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type - Data Responses to core.",
        .full_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type - Data Responses to core.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_BOUNCES_VERT.IV",
        .encoding =
            {
                .code = 0xA0ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type - Snoops of processor's cache.",
        .full_desc =
            "Number of incoming messages from the Vertical ring that were bounced, by ring type - Snoops of processor's cache.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_HORZ.AD",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Horizontal ring sink starvation count - AD ring",
        .full_desc = "Horizontal ring sink starvation count - AD ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_HORZ.AK",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Horizontal ring sink starvation count - AK ring",
        .full_desc = "Horizontal ring sink starvation count - AK ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_HORZ.BL",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Horizontal ring sink starvation count - BL ring",
        .full_desc = "Horizontal ring sink starvation count - BL ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_HORZ.IV",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Horizontal ring sink starvation count - IV ring",
        .full_desc = "Horizontal ring sink starvation count - IV ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_VERT.AD",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Vertical ring sink starvation count - AD ring",
        .full_desc = "Vertical ring sink starvation count - AD ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_VERT.AK",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Vertical ring sink starvation count - AK ring",
        .full_desc = "Vertical ring sink starvation count - AK ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_VERT.BL",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Vertical ring sink starvation count - BL ring",
        .full_desc = "Vertical ring sink starvation count - BL ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SINK_STARVED_VERT.IV",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Vertical ring sink starvation count - IV ring",
        .full_desc = "Vertical ring sink starvation count - IV ring",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_RING_SRC_THRTL",
        .encoding =
            {
                .code = 0xA4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts cycles in throttle mode.",
        .full_desc = "Counts cycles in throttle mode.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_SF_LOOKUP.ANY",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x11ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_SF_LOOKUP.DATA_READ",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x3ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Read transactions",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Read transactions",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_SF_LOOKUP.REMOTE_SNOOP",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x9ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_SF_LOOKUP.WRITE",
        .encoding =
            {
                .code = 0x34ULL,
                .umask = 0x5ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cacheable and UC.",
        .full_desc =
            "Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cacheable and UC.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BUSY_STARVED.AD_BNC",
        .encoding =
            {
                .code = 0xB4ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BUSY_STARVED.AD_CRD",
        .encoding =
            {
                .code = 0xB4ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BUSY_STARVED.BL_BNC",
        .encoding =
            {
                .code = 0xB4ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BUSY_STARVED.BL_CRD",
        .encoding =
            {
                .code = 0xB4ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BYPASS.AD_BNC",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
        .full_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BYPASS.AD_CRD",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
        .full_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BYPASS.AK_BNC",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
        .full_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BYPASS.BL_BNC",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
        .full_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BYPASS.BL_CRD",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
        .full_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_BYPASS.IV_BNC",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
        .full_desc =
            "Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_CRD_STARVED.AD_BNC",
        .encoding =
            {
                .code = 0xB3ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_CRD_STARVED.AD_CRD",
        .encoding =
            {
                .code = 0xB3ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_CRD_STARVED.AK_BNC",
        .encoding =
            {
                .code = 0xB3ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_CRD_STARVED.BL_BNC",
        .encoding =
            {
                .code = 0xB3ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_CRD_STARVED.BL_CRD",
        .encoding =
            {
                .code = 0xB3ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_CRD_STARVED.IFV",
        .encoding =
            {
                .code = 0xB3ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_CRD_STARVED.IV_BNC",
        .encoding =
            {
                .code = 0xB3ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
        .full_desc =
            "Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_INSERTS.AD_BNC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_INSERTS.AD_CRD",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_INSERTS.AK_BNC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_INSERTS.BL_BNC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_INSERTS.BL_CRD",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_INSERTS.IV_BNC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_OCCUPANCY.AD_BNC",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_OCCUPANCY.AD_CRD",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_OCCUPANCY.AK_BNC",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_OCCUPANCY.BL_BNC",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_OCCUPANCY.BL_CRD",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TG_INGRESS_OCCUPANCY.IV_BNC",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
        .full_desc =
            "Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_INSERTS.EVICT",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x32ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -SF/LLC Evictions",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -SF/LLC Evictions",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_INSERTS.HIT",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x1FULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -Hit (Not a Miss)",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -Hit (Not a Miss)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_INSERTS.IPQ",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x38ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IPQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IPQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_INSERTS.IRQ",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x31ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -IRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_INSERTS.MISS",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x2FULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -Miss",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -Miss",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_INSERTS.PRQ",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x34ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -PRQ",
        .full_desc =
            "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent -PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.EVICT",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x32ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -SF/LLC Evictions",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -SF/LLC Evictions",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.HIT",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x1FULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Hit (Not a Miss)",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Hit (Not a Miss)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.IPQ",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x38ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.IPQ_HIT",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x18ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ hit",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ hit",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.IPQ_MISS",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x28ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ miss",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ miss",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.IRQ",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x31ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.IRQ_HIT",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x11ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ hit",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ hit",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.IRQ_MISS",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x21ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ miss",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ miss",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.MISS",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x2FULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Miss",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Miss",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.PRQ",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x34ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.PRQ_HIT",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x14ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ hit",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ hit",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_TOR_OCCUPANCY.PRQ_MISS",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x24ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ miss",
        .full_desc =
            "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ miss",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_U_CLOCKTICKS",
        .encoding =
            {
                .code = 0x0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uncore Clocks",
        .full_desc = "Uncore Clocks",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AD_IN_USE.DN_EVEN",
        .encoding =
            {
                .code = 0xA6ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Even",
        .full_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AD_IN_USE.DN_ODD",
        .encoding =
            {
                .code = 0xA6ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Odd",
        .full_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AD_IN_USE.UP_EVEN",
        .encoding =
            {
                .code = 0xA6ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Even",
        .full_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AD_IN_USE.UP_ODD",
        .encoding =
            {
                .code = 0xA6ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Odd",
        .full_desc =
            "Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AK_IN_USE.DN_EVEN",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Even",
        .full_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AK_IN_USE.DN_ODD",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Odd",
        .full_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AK_IN_USE.UP_EVEN",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Even",
        .full_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_AK_IN_USE.UP_ODD",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Odd",
        .full_desc =
            "Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_BL_IN_USE.DN_EVEN",
        .encoding =
            {
                .code = 0xAAULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Even",
        .full_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_BL_IN_USE.DN_ODD",
        .encoding =
            {
                .code = 0xAAULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Odd",
        .full_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_BL_IN_USE.UP_EVEN",
        .encoding =
            {
                .code = 0xAAULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Even",
        .full_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Even",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_BL_IN_USE.UP_ODD",
        .encoding =
            {
                .code = 0xAAULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Odd",
        .full_desc =
            "Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Odd",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_IV_IN_USE.DN",
        .encoding =
            {
                .code = 0xACULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Down",
        .full_desc =
            "Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Down",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_H_VERT_RING_IV_IN_USE.UP",
        .encoding =
            {
                .code = 0xACULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Up",
        .full_desc =
            "Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Up",
    },
    {
        .pmu_type = PmuType::uncore_edc_uclk,
        .id = "UNC_E_EDC_ACCESS.HIT_CLEAN",
        .encoding =
            {
                .code = 0x2ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.",
        .full_desc =
            "Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.",
    },
    {
        .pmu_type = PmuType::uncore_edc_uclk,
        .id = "UNC_E_EDC_ACCESS.HIT_DIRTY",
        .encoding =
            {
                .code = 0x2ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode.",
        .full_desc =
            "Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode.",
    },
    {
        .pmu_type = PmuType::uncore_edc_uclk,
        .id = "UNC_E_EDC_ACCESS.MISS_CLEAN",
        .encoding =
            {
                .code = 0x2ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.",
        .full_desc =
            "Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.",
    },
    {
        .pmu_type = PmuType::uncore_edc_uclk,
        .id = "UNC_E_EDC_ACCESS.MISS_DIRTY",
        .encoding =
            {
                .code = 0x2ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode.",
        .full_desc =
            "Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode.",
    },
    {
        .pmu_type = PmuType::uncore_edc_uclk,
        .id = "UNC_E_EDC_ACCESS.MISS_INVALID",
        .encoding =
            {
                .code = 0x2ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of EDC Hits or Misses. Miss I",
        .full_desc = "Number of EDC Hits or Misses. Miss I",
    },
    {
        .pmu_type = PmuType::uncore_edc_uclk,
        .id = "UNC_E_U_CLOCKTICKS",
        .encoding =
            {
                .code = 0x0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "UCLK count",
        .full_desc = "UCLK count",
    },
    {
        .pmu_type = PmuType::uncore_edc_eclk,
        .id = "UNC_E_E_CLOCKTICKS",
        .encoding =
            {
                .code = 0x0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ECLK count",
        .full_desc = "ECLK count",
    },
    {
        .pmu_type = PmuType::uncore_edc_eclk,
        .id = "UNC_E_RPQ_INSERTS",
        .encoding =
            {
                .code = 0x1ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of read requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all read requests as well as streaming stores that hit or miss in the MCDRAM cache.",
        .full_desc =
            "Counts the number of read requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all read requests as well as streaming stores that hit or miss in the MCDRAM cache.",
    },
    {
        .pmu_type = PmuType::uncore_edc_eclk,
        .id = "UNC_E_WPQ_INSERTS",
        .encoding =
            {
                .code = 0x2ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of write requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all streaming stores, writebacks and, read requests that miss in MCDRAM cache.",
        .full_desc =
            "Counts the number of write requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all streaming stores, writebacks and, read requests that miss in MCDRAM cache.",
    },
    {
        .pmu_type = PmuType::uncore_imc_uclk,
        .id = "UNC_M_U_CLOCKTICKS",
        .encoding =
            {
                .code = 0x0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "UCLK count",
        .full_desc = "UCLK count",
    },
    {
        .pmu_type = PmuType::uncore_imc_dclk,
        .id = "UNC_M_CAS_COUNT.ALL",
        .encoding =
            {
                .code = 0x3ULL,
                .umask = 0x3ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CAS All",
        .full_desc = "CAS All",
    },
    {
        .pmu_type = PmuType::uncore_imc_dclk,
        .id = "UNC_M_D_CLOCKTICKS",
        .encoding =
            {
                .code = 0x0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "DCLK count",
        .full_desc = "DCLK count",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_FULL.AD_0",
        .encoding =
            {
                .code = 0x25ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_0",
        .full_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_FULL.AD_1",
        .encoding =
            {
                .code = 0x25ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_1",
        .full_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_FULL.AK_0",
        .encoding =
            {
                .code = 0x25ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_0",
        .full_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_FULL.AK_1",
        .encoding =
            {
                .code = 0x25ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_1",
        .full_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_FULL.BL_0",
        .encoding =
            {
                .code = 0x25ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_0",
        .full_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_FULL.BL_1",
        .encoding =
            {
                .code = 0x25ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_1",
        .full_desc =
            "Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_NE.AD_0",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_0",
        .full_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_NE.AD_1",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_1",
        .full_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_NE.AK_0",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_0",
        .full_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_NE.AK_1",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_1",
        .full_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_NE.BL_0",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_0",
        .full_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_CYCLES_NE.BL_1",
        .encoding =
            {
                .code = 0x23ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_1",
        .full_desc =
            "Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.AD_0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_0",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.AD_1",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x10ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_1",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.AK_0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_0",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.AK_1",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x20ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_1",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.AK_CRD_0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_0",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.AK_CRD_1",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_1",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.BL_0",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_0",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_0",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_EGRESS_INSERTS.BL_1",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x40ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_1",
        .full_desc =
            "Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_1",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_INGRESS_CYCLES_NE.ALL",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x80ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.ALL",
        .full_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.ALL",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_INGRESS_CYCLES_NE.CBO_IDI",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_IDI",
        .full_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_IDI",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_INGRESS_CYCLES_NE.CBO_NCB",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCB",
        .full_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCB",
    },
    {
        .pmu_type = PmuType::uncore_m2pcie,
        .id = "UNC_M2P_INGRESS_CYCLES_NE.CBO_NCS",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCS",
        .full_desc =
            "Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCS",
    },
}};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

} // namespace

void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addStaticEventDefs(kAllowlistedEvents);
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addStaticEventDefs(kFullOnlyEvents);
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace knightslanding_uncore
} // namespace facebook::hbt::perf_event::generated
