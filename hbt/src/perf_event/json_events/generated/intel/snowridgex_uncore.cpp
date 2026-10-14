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
namespace snowridgex_uncore {
namespace {

/*
  Events from snowridgex_uncore.json (207 events).

  Supported SKUs:
      - Arch: x86, Model: SNR id: 134
*/
constexpr std::array<StaticEventDef, 5> kAllowlistedEvents{{
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_CLOCKTICKS",
        .encoding =
            {
                .code = 0x0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Clockticks of the uncore caching and home agent (CHA)",
        .full_desc = "Clockticks of the uncore caching and home agent (CHA)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x1ULL,
                .umask_ext = 0xC827FEULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "TOR Inserts : DRd_Opt issued by iA Cores that missed the LLC",
        .full_desc =
            "TOR Inserts : DRd_Opt issued by iA Cores that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x1ULL,
                .umask_ext = 0xC827FEULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "TOR Occupancy : DRd_Opt issued by iA Cores that missed the LLC",
        .full_desc =
            "TOR Occupancy : DRd_Opt issued by iA Cores that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT.RD",
        .encoding =
            {
                .code = 0x4ULL,
                .umask = 0xFULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "All DRAM read CAS commands issued (including underfills)",
        .full_desc =
            "Counts the total number of DRAM Read CAS commands, w/ and w/o auto-pre, issued on this channel.  This includes underfills.",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT.WR",
        .encoding =
            {
                .code = 0x4ULL,
                .umask = 0x30ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All DRAM write CAS commands issued",
        .full_desc =
            "Counts the total number of DRAM Write CAS commands issued, w/ and w/o auto-pre, on this channel.",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::
    array<StaticEventDef, 202>
        kFullOnlyEvents{
            {
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_CMS_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CMS Clockticks",
                    .full_desc = "CMS Clockticks",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_IMC_READS_COUNT.NORMAL",
                    .encoding =
                        {
                            .code = 0x59ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Normal priority reads issued to the memory controller from the CHA",
                    .full_desc =
                        "Counts when a normal (Non-Isochronous) read is issued to any of the memory controller channels from the CHA.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_IMC_WRITES_COUNT.FULL",
                    .encoding =
                        {
                            .code = 0x5BULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CHA to iMC Full Line Writes Issued : Full Line Non-ISOCH",
                    .full_desc =
                        "Counts when a normal (Non-Isochronous) full line write is issued from the CHA to any of the memory controller channels.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.DATA_READ",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1BC1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache and Snoop Filter Lookups; Data Read Request",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.ALL",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Lines Victimized : All Lines Victimized",
                    .full_desc =
                        "Lines Victimized : All Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REQUESTS.READS",
                    .encoding =
                        {
                            .code = 0x50ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Local read requests that miss the SF/LLC and remote read requests sent to the CHA's home agent",
                    .full_desc =
                        "Counts read requests made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write) .",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REQUESTS.WRITES",
                    .encoding =
                        {
                            .code = 0x50ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Local write requests that miss the SF/LLC and remote write requests sent to the CHA's home agent",
                    .full_desc =
                        "Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_SF_EVICTION.E_STATE",
                    .encoding =
                        {
                            .code = 0x3DULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Snoop filter capacity evictions for E-state entries.",
                    .full_desc =
                        "Counts snoop filter capacity evictions for entries tracking exclusive lines in the cores? cache.? Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry.? Does not count clean evictions such as when a core?s cache replaces a tracked cacheline with a new cacheline.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_SF_EVICTION.M_STATE",
                    .encoding =
                        {
                            .code = 0x3DULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Snoop filter capacity evictions for M-state entries.",
                    .full_desc =
                        "Counts snoop filter capacity evictions for entries tracking modified lines in the cores? cache.? Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry.? Does not count clean evictions such as when a core?s cache replaces a tracked cacheline with a new cacheline.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_SF_EVICTION.S_STATE",
                    .encoding =
                        {
                            .code = 0x3DULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Snoop filter capacity evictions for S-state entries.",
                    .full_desc =
                        "Counts snoop filter capacity evictions for entries tracking shared lines in the cores? cache.? Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry.? Does not count clean evictions such as when a core?s cache replaces a tracked cacheline with a new cacheline.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : All requests from iA Cores",
                    .full_desc =
                        "TOR Inserts : All requests from iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_CLFLUSH",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8C7FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : CLFlushes issued by iA Cores",
                    .full_desc =
                        "TOR Inserts : CLFlushes issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_CRD",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC80FFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : CRDs issued by iA Cores",
                    .full_desc =
                        "TOR Inserts : CRDs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_DRD_OPT",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC827FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : DRd_Opts issued by iA Cores",
                    .full_desc =
                        "TOR Inserts : DRd_Opts issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_DRD_OPT_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8A7FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRd_Opt_Prefs issued by iA Cores",
                    .full_desc =
                        "TOR Inserts : DRd_Opt_Prefs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC001FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : All requests from iA Cores that Hit the LLC",
                    .full_desc =
                        "TOR Inserts : All requests from iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_CRD",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC80FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : CRds issued by iA Cores that Hit the LLC",
                    .full_desc =
                        "TOR Inserts : CRds issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_CRD_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC88FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : CRd_Prefs issued by iA Cores that hit the LLC",
                    .full_desc =
                        "TOR Inserts : CRd_Prefs issued by iA Cores that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_OPT",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC827FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRd_Opts issued by iA Cores that hit the LLC",
                    .full_desc =
                        "TOR Inserts : DRd_Opts issued by iA Cores that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_OPT_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8A7FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRd_Opt_Prefs issued by iA Cores that hit the LLC",
                    .full_desc =
                        "TOR Inserts : DRd_Opt_Prefs issued by iA Cores that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_RFO",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC807FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : RFOs issued by iA Cores that Hit the LLC",
                    .full_desc =
                        "TOR Inserts : RFOs issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_RFO_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC887FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : RFO_Prefs issued by iA Cores that Hit the LLC",
                    .full_desc =
                        "TOR Inserts : RFO_Prefs issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC001FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : All requests from iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Inserts : All requests from iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_CRD",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC80FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : CRds issued by iA Cores that Missed the LLC",
                    .full_desc = "TOR Inserts : CRds issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC88FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8A7FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRd_Opt_Prefs issued by iA Cores that missed the LLC",
                    .full_desc =
                        "TOR Inserts : DRd_Opt_Prefs issued by iA Cores that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_FULL_STREAMING_WR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC867FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; WCiLF misses from local IA",
                    .full_desc =
                        "TOR Inserts; Data read from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_PARTIAL_STREAMING_WR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; WCiL misses from local IA",
                    .full_desc =
                        "TOR Inserts; Data read from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC807FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : RFOs issued by iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Inserts : RFOs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC887FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_UCRDF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC877DEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : UCRdFs issued by iA Cores that Missed LLC",
                    .full_desc =
                        "TOR Inserts : UCRdFs issued by iA Cores that Missed LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : WCiLs issued by iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Inserts : WCiLs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC867FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : WCiLF issued by iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Inserts : WCiLF issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_WIL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC87FDEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : WiLs issued by iA Cores that Missed LLC",
                    .full_desc =
                        "TOR Inserts : WiLs issued by iA Cores that Missed LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_RFO",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC807FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : RFOs issued by iA Cores",
                    .full_desc =
                        "TOR Inserts : RFOs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_RFO_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC887FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : RFO_Prefs issued by iA Cores",
                    .full_desc =
                        "TOR Inserts : RFO_Prefs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : All requests from IO Devices",
                    .full_desc =
                        "TOR Inserts : All requests from IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_HIT",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC001FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : All requests from IO Devices that hit the LLC",
                    .full_desc =
                        "TOR Inserts : All requests from IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_HIT_ITOM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCC43FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : ItoMs issued by IO Devices that Hit the LLC",
                    .full_desc =
                        "TOR Inserts : ItoMs issued by IO Devices that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_HIT_ITOMCACHENEAR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCD43FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC",
                    .full_desc =
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_HIT_PCIRDCUR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC8F3FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC",
                    .full_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_ITOM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCC43FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts : ItoMs issued by IO Devices",
                    .full_desc =
                        "TOR Inserts : ItoMs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCD43FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices",
                    .full_desc =
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_MISS",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC001FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : All requests from IO Devices that missed the LLC",
                    .full_desc =
                        "TOR Inserts : All requests from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_MISS_ITOM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCC43FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : ItoMs issued by IO Devices that missed the LLC",
                    .full_desc =
                        "TOR Inserts : ItoMs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_MISS_ITOMCACHENEAR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCD43FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
                    .full_desc =
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_MISS_PCIRDCUR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC8F3FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC",
                    .full_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC8F3FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices",
                    .full_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy : All requests from iA Cores",
                    .full_desc =
                        "TOR Occupancy : All requests from iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_CRD",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC80FFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy : CRDs issued by iA Cores",
                    .full_desc =
                        "TOR Occupancy : CRDs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_DRD_OPT",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC827FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy : DRd_Opts issued by iA Cores",
                    .full_desc =
                        "TOR Occupancy : DRd_Opts issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_DRD_OPT_PREF",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8A7FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : DRd_Opt_Prefs issued by iA Cores",
                    .full_desc =
                        "TOR Occupancy : DRd_Opt_Prefs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC001FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : All requests from iA Cores that Hit the LLC",
                    .full_desc =
                        "TOR Occupancy : All requests from iA Cores that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_OPT",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC827FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : DRd_Opts issued by iA Cores that hit the LLC",
                    .full_desc =
                        "TOR Occupancy : DRd_Opts issued by iA Cores that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_OPT_PREF",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8A7FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : DRd_Opt_Prefs issued by iA Cores that hit the LLC",
                    .full_desc =
                        "TOR Occupancy : DRd_Opt_Prefs issued by iA Cores that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC001FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : All requests from iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Occupancy : All requests from iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC80FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : CRds issued by iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Occupancy : CRds issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC807FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : RFOs issued by iA Cores that Missed the LLC",
                    .full_desc =
                        "TOR Occupancy : RFOs issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_RFO",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC807FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy : RFOs issued by iA Cores",
                    .full_desc =
                        "TOR Occupancy : RFOs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : All requests from IO Devices",
                    .full_desc =
                        "TOR Occupancy : All requests from IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_HIT",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC001FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : All requests from IO Devices that hit the LLC",
                    .full_desc =
                        "TOR Occupancy : All requests from IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC001FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : All requests from IO Devices that missed the LLC",
                    .full_desc =
                        "TOR Occupancy : All requests from IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_PCIRDCUR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC8F3FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC",
                    .full_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_PCIRDCUR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC8F3FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices",
                    .full_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ACT_COUNT.ALL",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Activate Count : All Activates",
                    .full_desc =
                        "DRAM Activate Count : All Activates : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT.ALL",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x3FULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All DRAM CAS commands issued",
                    .full_desc =
                        "Counts the total number of DRAM CAS commands issued on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Clockticks",
                    .full_desc =
                        "Clockticks of the integrated memory controller (IMC)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_DRAM_REFRESH.HIGH",
                    .encoding =
                        {
                            .code = 0x45ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of DRAM Refreshes Issued",
                    .full_desc =
                        "Number of DRAM Refreshes Issued : Counts the number of refreshes issued.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_DRAM_REFRESH.OPPORTUNISTIC",
                    .encoding =
                        {
                            .code = 0x45ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of DRAM Refreshes Issued",
                    .full_desc =
                        "Number of DRAM Refreshes Issued : Counts the number of refreshes issued.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_DRAM_REFRESH.PANIC",
                    .encoding =
                        {
                            .code = 0x45ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of DRAM Refreshes Issued",
                    .full_desc =
                        "Number of DRAM Refreshes Issued : Counts the number of refreshes issued.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_HCLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Half clockticks for IMC",
                    .full_desc = "Half clockticks for IMC",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.ALL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x1CULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Precharge commands.",
                    .full_desc =
                        "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.PGT",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands. : Precharge due to page table",
                    .full_desc =
                        "DRAM Precharge commands. : Precharge due to page table : Counts the number of DRAM Precharge commands sent on this channel. : Precharges from Page Table",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.RD",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands. : Precharge due to read",
                    .full_desc = "DRAM Precharge commands. : Precharge due to read : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from read bank scheduler",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.WR",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands. : Precharge due to write",
                    .full_desc =
                        "DRAM Precharge commands. : Precharge due to write : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from write bank scheduler",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RPQ_INSERTS.PCH0",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read Pending Queue Allocations",
                    .full_desc =
                        "Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RPQ_INSERTS.PCH1",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read Pending Queue Allocations",
                    .full_desc =
                        "Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RPQ_OCCUPANCY_PCH0",
                    .encoding =
                        {
                            .code = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read Pending Queue Occupancy",
                    .full_desc =
                        "Read Pending Queue Occupancy : Accumulates the occupancies of the Read Pending Queue each cycle.  This can then be used to calculate both the average occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC. They deallocate after the CAS command has been issued to memory.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RPQ_OCCUPANCY_PCH1",
                    .encoding =
                        {
                            .code = 0x81ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read Pending Queue Occupancy",
                    .full_desc =
                        "Read Pending Queue Occupancy : Accumulates the occupancies of the Read Pending Queue each cycle.  This can then be used to calculate both the average occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC. They deallocate after the CAS command has been issued to memory.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_INSERTS.PCH0",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Allocations",
                    .full_desc =
                        "Write Pending Queue Allocations : Counts the number of allocations into the Write Pending Queue.  This can then be used to calculate the average queuing latency (in conjunction with the WPQ occupancy count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_INSERTS.PCH1",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Allocations",
                    .full_desc =
                        "Write Pending Queue Allocations : Counts the number of allocations into the Write Pending Queue.  This can then be used to calculate the average queuing latency (in conjunction with the WPQ occupancy count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_OCCUPANCY_PCH0",
                    .encoding =
                        {
                            .code = 0x82ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Occupancy",
                    .full_desc =
                        "Write Pending Queue Occupancy : Accumulates the occupancies of the Write Pending Queue each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the not posted filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The posted filter, on the other hand, provides information about how much queueing is actually happening in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_OCCUPANCY_PCH1",
                    .encoding =
                        {
                            .code = 0x83ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Occupancy",
                    .full_desc =
                        "Write Pending Queue Occupancy : Accumulates the occupancies of the Write Pending Queue each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the not posted filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The posted filter, on the other hand, provides information about how much queueing is actually happening in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Clockticks of the integrated IO (IIO) traffic controller",
                    .full_desc =
                        "Clockticks of the integrated IO (IIO) traffic controller",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_CLOCKTICKS_FREERUN",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Free running counter that increments for IIO clocktick",
                    .full_desc =
                        "Free running counter that increments for integrated IO (IIO) traffic controller clockticks",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 0-7",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 0-7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART0",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 0",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART1",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 1",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART2",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 2",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART3",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 3",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART4",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 4",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART5",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 5",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART6",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 6",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART7",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Inserts of completions with data: Part 7",
                    .full_desc =
                        "PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0xFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 0-7",
                    .full_desc = "PCIe Completion Buffer Occupancy : Part 0-7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART0",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 0",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART1",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 1",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART2",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 2",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART3",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 3",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 3 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART4",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 4",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 4 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART5",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 5",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 5 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART6",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 6",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 6 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART7",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIe Completion Buffer Occupancy of completions with data : Part 7",
                    .full_desc =
                        "PCIe Completion Buffer Occupancy : Part 7 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART0",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART1",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART2",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc = "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART3",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART4",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART5",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART6",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART7",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART0",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART1",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART2",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART3",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART4",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART5",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART6",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART7",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART0",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART1",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART2",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART3",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART4",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART5",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART6",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART7",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART0",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART1",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART2",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART3",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART4",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART5",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART6",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART7",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART0",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART1",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART2",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART3",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART4",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART5",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART6",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART7",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Four byte data request of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU.COMMIT.ALL",
                    .encoding =
                        {
                            .code = 0x85ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number requests PCIe makes of the main die : All",
                    .full_desc =
                        "Number requests PCIe makes of the main die : All : Counts full PCIe requests before they're broken into a series of cache-line size requests as measured by DATA_REQ_OF_CPU and TXN_REQ_OF_CPU.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART0",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART1",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART2",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART3",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART4",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART5",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART6",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART7",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART0",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART1",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART2",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART3",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART4",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART5",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART6",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART7",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART0",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART1",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART2",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART3",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART4",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART5",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART6",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART7",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request",
                    .full_desc =
                        "Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART0",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART1",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART2",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART3",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART4",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART5",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART6",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART7",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART0",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART1",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART2",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART3",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART4",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART5",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART6",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART7",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_CACHE_TOTAL_OCCUPANCY.MEM",
                    .encoding =
                        {
                            .code = 0xFULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Total IRP occupancy of inbound read and write requests to coherent memory.",
                    .full_desc =
                        "Total IRP occupancy of inbound read and write requests to coherent memory.  This is effectively the sum of read occupancy and write occupancy.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Clockticks of the IO coherency tracker (IRP)",
                    .full_desc = "Clockticks of the IO coherency tracker (IRP)",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.PCITOM",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIITOM request issued by the IRP unit to the mesh with the intention of writing a full cacheline.",
                    .full_desc =
                        "PCIITOM request issued by the IRP unit to the mesh with the intention of writing a full cacheline to coherent memory, without a RFO.  PCIITOM is a speculative Invalidate to Modified command that requests ownership of the cacheline and does not move data from the mesh to IRP cache.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.WBMTOI",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops : WbMtoI",
                    .full_desc =
                        "Coherent Ops : WbMtoI : Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_FAF_FULL",
                    .encoding =
                        {
                            .code = 0x17ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "FAF RF full",
                    .full_desc = "FAF RF full",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_FAF_INSERTS",
                    .encoding =
                        {
                            .code = 0x18ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Inbound read requests received by the IRP and inserted into the FAF queue.",
                    .full_desc =
                        "Inbound read requests to coherent memory, received by the IRP and inserted into the Fire and Forget queue (FAF), a queue used for processing inbound reads in the IRP.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_FAF_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x19ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Occupancy of the IRP FAF queue.",
                    .full_desc =
                        "Occupancy of the IRP Fire and Forget (FAF) queue, a queue used for processing inbound reads in the IRP.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_FAF_TRANSACTIONS",
                    .encoding =
                        {
                            .code = 0x16ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "FAF allocation -- sent to ADQ",
                    .full_desc = "FAF allocation -- sent to ADQ",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_IRP_ALL.INBOUND_INSERTS",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = ": All Inserts Inbound (p2p + faf + cset)",
                    .full_desc = ": All Inserts Inbound (p2p + faf + cset)",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.LOST_FWD",
                    .encoding =
                        {
                            .code = 0x1FULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 1 : Lost Forward",
                    .full_desc =
                        "Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.ALL_HIT_M",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x78ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Responses to snoops of any type that hit M line in the IIO cache",
                    .full_desc =
                        "Responses to snoops of any type (code, data, invalidate) that hit M line in the IIO cache",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.WR_PREF",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Inbound write (fast path) requests received by the IRP.",
                    .full_desc =
                        "Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Clockticks of the mesh to memory (M2M)",
                    .full_desc = "Clockticks of the mesh to memory (M2M)",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_CMS_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CMS Clockticks",
                    .full_desc = "CMS Clockticks",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Clockticks of the power control unit (PCU)",
                    .full_desc = "Clockticks of the power control unit (PCU)",
                },
                {
                    .pmu_type = PmuType::uncore_ubox,
                    .id = "UNC_U_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Clockticks in the UBOX using a dedicated 48-bit Fixed Counter",
                    .full_desc =
                        "Clockticks in the UBOX using a dedicated 48-bit Fixed Counter",
                },
                {
                    .pmu_type = PmuType::uncore_m2pcie,
                    .id = "UNC_M2P_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Clockticks of the mesh to PCI (M2P)",
                    .full_desc = "Clockticks of the mesh to PCI (M2P)",
                },
                {
                    .pmu_type = PmuType::uncore_m2pcie,
                    .id = "UNC_M2P_CMS_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CMS Clockticks",
                    .full_desc = "CMS Clockticks",
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

} // namespace snowridgex_uncore
} // namespace facebook::hbt::perf_event::generated
