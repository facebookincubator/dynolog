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
namespace sierraforest_uncore {
namespace {

/*
  Events from sierraforest_uncore.json (327 events).

  Supported SKUs:
      - Arch: x86, Model: SRF id: 175
*/
constexpr std::array<StaticEventDef, 11> kAllowlistedEvents{{
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_CLOCKTICKS",
        .encoding =
            {
                .code = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of CHA clock cycles while the event is enabled",
        .full_desc = "Clockticks of the uncore caching and home agent (CHA)",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_REQUESTS.READS_LOCAL",
        .encoding =
            {
                .code = 0x50ULL,
                .umask = 0x1ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts read requests coming from a unit on this socket made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).",
        .full_desc =
            "Counts read requests coming from a unit on this socket made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_REQUESTS.READS_REMOTE",
        .encoding =
            {
                .code = 0x50ULL,
                .umask = 0x2ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).",
        .full_desc =
            "Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_REQUESTS.WRITES_LOCAL",
        .encoding =
            {
                .code = 0x50ULL,
                .umask = 0x4ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts  write requests coming from a unit on this socket made into this CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.",
        .full_desc =
            "Counts  write requests coming from a unit on this socket made into this CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_REQUESTS.WRITES_REMOTE",
        .encoding =
            {
                .code = 0x50ULL,
                .umask = 0x8ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).",
        .full_desc =
            "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).",
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
        .brief_desc = "Data read opt from local IA that miss the cache",
        .full_desc =
            "TOR Inserts : DRd_Opt issued by iA Cores that missed the LLC",
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
            "TOR Occupancy for Data read opt from local IA that miss the cache",
        .full_desc =
            "TOR Occupancy : DRd_Opt issued by iA Cores that missed the LLC",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT_SCH0.RD",
        .encoding =
            {
                .code = 0x5ULL,
                .umask = 0xCFULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CAS count for SubChannel 0, all reads",
        .full_desc = "CAS count for SubChannel 0, all reads",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT_SCH0.WR",
        .encoding =
            {
                .code = 0x5ULL,
                .umask = 0xF0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CAS count for SubChannel 0, all writes",
        .full_desc = "CAS count for SubChannel 0, all writes",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT_SCH1.RD",
        .encoding =
            {
                .code = 0x6ULL,
                .umask = 0xCFULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CAS count for SubChannel 1, all reads",
        .full_desc = "CAS count for SubChannel 1, all reads",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT_SCH1.WR",
        .encoding =
            {
                .code = 0x6ULL,
                .umask = 0xF0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "CAS count for SubChannel 1, all writes",
        .full_desc = "CAS count for SubChannel 1, all writes",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 286>
    kFullOnlyEvents{
        {
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_DISTRESS_ASSERTED.DPT_ANY",
                .encoding =
                    {
                        .code = 0x59ULL,
                        .umask = 0x3ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR or IRQ (immediate cause for triggering).",
                .full_desc =
                    "Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR or IRQ (immediate cause for triggering).",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_DISTRESS_ASSERTED.DPT_IRQ",
                .encoding =
                    {
                        .code = 0x59ULL,
                        .umask = 0x1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in IRQ (immediate cause for triggering).",
                .full_desc =
                    "Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in IRQ (immediate cause for triggering).",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_DISTRESS_ASSERTED.DPT_TOR",
                .encoding =
                    {
                        .code = 0x59ULL,
                        .umask = 0x2ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR (immediate cause for triggering).",
                .full_desc =
                    "Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR (immediate cause for triggering).",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_MISC.RFO_HIT_S",
                .encoding =
                    {
                        .code = 0x39ULL,
                        .umask = 0x8ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts when a RFO (the Read for Ownership issued before a  write) request hit a cacheline in the S (Shared) state.",
                .full_desc = "Cbo Misc : RFO HitS",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_OSB.RFO_HITS_SNP_BCAST",
                .encoding =
                    {
                        .code = 0x55ULL,
                        .umask = 0x10ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OSB Snoop Broadcast : RFO HitS Snoop Broadcast : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                .full_desc = "OSB Snoop Broadcast : RFO HitS Snoop Broadcast",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_REMOTE_SF.MISS",
                .encoding =
                    {
                        .code = 0x69ULL,
                        .umask = 0x4ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "UNC_CHA_REMOTE_SF.MISS",
                .full_desc = "UNC_CHA_REMOTE_SF.MISS",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_REQUESTS.INVITOE",
                .encoding =
                    {
                        .code = 0x50ULL,
                        .umask = 0x30ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.",
                .full_desc = "HA Read and Write Requests : InvalItoE",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_REQUESTS.INVITOE_LOCAL",
                .encoding =
                    {
                        .code = 0x50ULL,
                        .umask = 0x10ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.",
                .full_desc =
                    "Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_REQUESTS.INVITOE_REMOTE",
                .encoding =
                    {
                        .code = 0x50ULL,
                        .umask = 0x20ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of requests coming from a remote socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.",
                .full_desc =
                    "Counts the total number of requests coming from a remote socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.",
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
                    "Counts read requests made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write) .",
                .full_desc = "HA Read and Write Requests : Reads",
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
                    "Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.",
                .full_desc = "HA Read and Write Requests : Writes",
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
                .brief_desc = "CLFlush events that are initiated from the Core",
                .full_desc = "TOR Inserts : CLFlushes issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_CLFLUSHOPT",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8D7FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "CLFlushOpt events that are initiated from the Core",
                .full_desc = "TOR Inserts : CLFlushOpts issued by iA Cores",
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
                .brief_desc = "Code read from local IA",
                .full_desc = "TOR Inserts : CRDs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_CRD_PREF",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88FFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Code read prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts; Code read prefetch from local IA that misses in the snoop filter",
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
                .brief_desc = "Data read opt from local IA",
                .full_desc = "TOR Inserts : DRd_Opts issued by iA Cores",
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
                .brief_desc = "Data read opt prefetch from local IA",
                .full_desc = "TOR Inserts : DRd_Opt_Prefs issued by iA Cores",
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
                .brief_desc = "Code read from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : CRds issued by iA Cores that Hit the LLC",
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
                    "Code read prefetch from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : CRd_Prefs issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_HIT_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C00181ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.",
                .full_desc =
                    "All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.",
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
                .brief_desc = "Data read opt from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : DRd_Opts issued by iA Cores that hit the LLC",
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
                    "Data read opt prefetch from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : DRd_Opt_Prefs issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_HIT_ITOM",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC47FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "ItoM requests from local IA cores that hit the cache",
                .full_desc =
                    "TOR Inserts : ItoMs issued by iA Cores that Hit LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFCODE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCCFFDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch code read from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : LLCPrefCode issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFDATA",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCD7FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch data read from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : LLCPrefData issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFRFO",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCC7FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch read for ownership from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC",
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
                    "Read for ownership from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : RFOs issued by iA Cores that Hit the LLC",
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
                    "Read for ownership prefetch from local IA that hit the cache",
                .full_desc =
                    "TOR Inserts : RFO_Prefs issued by iA Cores that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_ITOM",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC47FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "ItoM events that are initiated from the Core",
                .full_desc = "TOR Inserts : ItoMs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_ITOMCACHENEAR",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCD47FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "ItoMCacheNear requests from local IA cores",
                .full_desc = "TOR Inserts : ItoMCacheNears issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_LLCPREFCODE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCCFFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch code read from local IA.",
                .full_desc = "TOR Inserts : LLCPrefCode issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_LLCPREFDATA",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCD7FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch data read from local IA.",
                .full_desc = "TOR Inserts : LLCPrefData issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_LLCPREFRFO",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCC7FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch read for ownership from local IA that miss the cache",
                .full_desc = "TOR Inserts : LLCPrefRFO issued by iA Cores",
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
                    "All locally initiated requests from IA Cores which miss the cache",
                .full_desc =
                    "TOR Inserts : All requests from iA Cores that Missed the LLC",
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
                .brief_desc = "Code read from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : CRds issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC80EFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "CRDs from local IA cores to locally homed memory",
                .full_desc =
                    "TOR Inserts : CRd issued by iA Cores that Missed the LLC - HOMed locally",
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
                    "Code read prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88EFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "CRD Prefetches from local IA cores to locally homed memory",
                .full_desc =
                    "TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88F7EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "CRD Prefetches from local IA cores to remotely homed memory",
                .full_desc =
                    "TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC80F7EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "CRDs from local IA cores to remotely homed memory",
                .full_desc =
                    "TOR Inserts : CRd issued by iA Cores that Missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C00182ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.",
                .full_desc =
                    "All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C81782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "DRds and equivalent opcodes issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.",
                .full_desc =
                    "DRds issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC826FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd_Opt, and which target local memory",
                .full_desc =
                    "TOR Inserts : DRd_Opt issued by iA Cores that Missed the LLC - HOMed locally",
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
                    "Data read opt prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : DRd_Opt_Prefs issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8A6FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF_OPT, and target local memory",
                .full_desc =
                    "TOR Inserts : Data read opt prefetch from local iA that missed the LLC targeting local memory",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8A77EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF_OPT, and target remote memory",
                .full_desc =
                    "TOR Inserts : Data read opt prefetch from local iA that missed the LLC targeting remote memory",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8277EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd_Opt, and target remote memory",
                .full_desc =
                    "TOR Inserts : Data read opt from local iA that missed the LLC targeting remote memory",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C89782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_ITOM",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC47FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "ItoM requests from local IA cores that miss the cache",
                .full_desc =
                    "TOR Inserts : ItoMs issued by iA Cores that Missed LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFCODE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCCFFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch code read from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : LLCPrefCode issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFDATA",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCD7FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch data read from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : LLCPrefData issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFDATA_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10CCD782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFRFO",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCC7FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Last level cache prefetch read for ownership from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFRFO_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C88782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCILF_DDR",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86686ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WCILF requests from local IA cores to locally homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCIL_DDR",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86E86ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WCIL requests from local IA cores to locally homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCILF_DDR",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86706ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WCILF requests from local IA cores to remotely homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCIL_DDR",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86F06ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WCIL requests from local IA cores to remotely homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely",
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
                    "Read for ownership from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : RFOs issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C80782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC806FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read for ownership from local IA that miss the LLC targeting local memory",
                .full_desc =
                    "TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed locally",
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
                    "Read for ownership prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_CXL_ACC",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10CCC782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC886FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read for ownership prefetch from local IA that miss the LLC targeting local memory",
                .full_desc =
                    "TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8877EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read for ownership prefetch from local IA that miss the LLC targeting remote memory",
                .full_desc =
                    "TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8077EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read for ownership from local IA that miss the LLC targeting remote memory",
                .full_desc =
                    "TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed remotely",
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
                    "UCRDF requests from local IA cores that miss the cache",
                .full_desc =
                    "TOR Inserts : UCRdFs issued by iA Cores that Missed LLC",
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
                    "WCIL requests from a local IA core that miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLs issued by iA Cores that Missed the LLC",
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
                    "WCILF requests from local IA core that miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLF issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF_DDR",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86786ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WCILF requests from local IA cores to DDR homed addresses which miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL_DDR",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86F86ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WCIL requests from local IA cores to DDR homed addresses which miss the cache",
                .full_desc =
                    "TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC",
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
                    "WIL requests from local IA cores that miss the cache",
                .full_desc =
                    "TOR Inserts : WiLs issued by iA Cores that Missed LLC",
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
                .brief_desc = "Read for ownership from local IA",
                .full_desc = "TOR Inserts : RFOs issued by iA Cores",
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
                .brief_desc = "Read for ownership prefetch from local IA",
                .full_desc = "TOR Inserts : RFO_Prefs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_SPECITOM",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC57FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "SpecItoM events that are initiated from the Core",
                .full_desc = "TOR Inserts : SpecItoMs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_WBEFTOE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC3FFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WbEFtoEs issued by iA Cores.  (Non Modified Write Backs)",
                .full_desc =
                    "TOR Inserts : ItoMs issued by IO Devices that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_WBEFTOI",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC37FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WbEFtoIs issued by iA Cores .  (Non Modified Write Backs)",
                .full_desc =
                    "TOR Inserts : ItoMs issued by IO Devices that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_WBMTOE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC2FFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WbMtoEs issued by iA Cores .  (Modified Write Backs)",
                .full_desc =
                    "TOR Inserts : ItoMs issued by IO Devices that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_WBMTOI",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC27FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "WbMtoI requests from local IA cores",
                .full_desc = "TOR Inserts : WbMtoIs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_WBSTOI",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC67FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "WbStoIs issued by iA Cores .  (Non Modified Write Backs)",
                .full_desc =
                    "TOR Inserts : ItoMs issued by IO Devices that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_WCIL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86FFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "WCIL requests from a local IA core",
                .full_desc = "TOR Inserts : WCiLs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IA_WCILF",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC867FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "WCILF requests from local IA core",
                .full_desc = "TOR Inserts : WCiLF issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_CLFLUSH",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC8C3FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CLFlush requests from IO devices",
                .full_desc = "TOR Inserts : CLFlushes issued by IO Devices",
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
                .brief_desc = "ItoMs from local IO devices which hit the cache",
                .full_desc =
                    "TOR Inserts : ItoMs issued by IO Devices that Hit the LLC",
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
                    "ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC",
                .full_desc =
                    "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC",
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
                    "PCIRDCURs issued by IO devices which hit the LLC",
                .full_desc =
                    "TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_HIT_RFO",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC803FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "RFOs from local IO devices which hit the cache",
                .full_desc =
                    "TOR Inserts : RFOs issued by IO Devices that hit the LLC",
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
                .brief_desc = "All TOR ItoM inserts from local IO devices",
                .full_desc = "TOR Inserts : ItoMs issued by IO Devices",
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
                    "ItoMCacheNears, indicating a partial write request, from IO Devices",
                .full_desc =
                    "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCD42FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "ItoMCacheNear (partial write) transactions from an IO device that addresses memory on the local socket",
                .full_desc =
                    "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that address memory on the local socket",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCD437FULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "ItoMCacheNear (partial write) transactions from an IO device that addresses memory on a remote socket",
                .full_desc =
                    "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that address memory on a remote socket",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_ITOM_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCC42FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "ItoM (write) transactions from an IO device that addresses memory on the local socket",
                .full_desc =
                    "TOR Inserts : ItoM, indicating a write request, from IO Devices that address memory on the local socket",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_ITOM_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCC437FULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "ItoM (write) transactions from an IO device that addresses memory on a remote socket",
                .full_desc =
                    "TOR Inserts : ItoM, indicating a write request, from IO Devices that address memory on a remote socket",
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
                    "All TOR ItoM inserts from local IO devices which miss the cache",
                .full_desc =
                    "TOR Inserts : ItoMs issued by IO Devices that missed the LLC",
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
                    "ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
                .full_desc =
                    "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
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
                    "PCIRDCURs issued by IO devices which miss the LLC",
                .full_desc =
                    "TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_MISS_RFO",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC803FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "All TOR RFO inserts from local IO devices which miss the cache",
                .full_desc =
                    "TOR Inserts : RFOs issued by IO Devices that missed the LLC",
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
                .brief_desc = "PCIRDCURs issued by IO devices",
                .full_desc = "TOR Inserts : PCIRdCurs issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR_LOCAL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC8F2FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "PCIRDCUR (read) transactions from an IO device that addresses memory on the local socket",
                .full_desc =
                    "TOR Inserts : PCIRdCurs issued by IO Devices that addresses memory on the local socket",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR_REMOTE",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC8F37FULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "PCIRDCUR (read) transactions from an IO device that addresses memory on a remote socket",
                .full_desc =
                    "TOR Inserts : PCIRdCurs issued by IO Devices that addresses memory on a remote socket",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_RFO",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC803FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "RFOs from local IO devices",
                .full_desc = "TOR Inserts : RFOs issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.IO_WBMTOI",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCC23FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "WBMtoI requests from IO devices",
                .full_desc = "TOR Inserts : WbMtoIs issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_INSERTS.LLC_OR_SF_EVICTIONS",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x2ULL,
                        .umask_ext = 0xC001FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "TOR Inserts for SF or LLC Evictions",
                .full_desc =
                    "TOR allocation occurred as a result of SF/LLC evictions (came from the ISMQ)",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_CLFLUSH",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8C7FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for CLFlush events that are initiated from the Core",
                .full_desc = "TOR Occupancy : CLFlushes issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_CLFLUSHOPT",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8D7FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for CLFlushOpt events that are initiated from the Core",
                .full_desc = "TOR Occupancy : CLFlushOpts issued by iA Cores",
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
                .brief_desc =
                    "TOR Occupancy for Code read from local IA that miss the cache",
                .full_desc = "TOR Occupancy : CRDs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_CRD_PREF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88FFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Code read prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy; Code read prefetch from local IA that misses in the snoop filter",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC80FFDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Code read from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : CRds issued by iA Cores that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD_PREF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88FFDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Code read prefetch from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : CRd_Prefs issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C00181ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.",
                .full_desc =
                    "TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.",
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
                    "TOR Occupancy for Data read opt from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : DRd_Opts issued by iA Cores that hit the LLC",
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
                    "TOR Occupancy for Data read opt prefetch from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : DRd_Opt_Prefs issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_ITOM",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC47FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoM requests from local IA cores that hit the cache",
                .full_desc =
                    "TOR Occupancy : ItoMs issued by iA Cores that Hit LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFCODE",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCCFFDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch code read from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : LLCPrefCode issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFDATA",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCD7FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch data read from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : LLCPrefData issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFRFO",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCC7FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch read for ownership from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : LLCPrefRFO issued by iA Cores that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC807FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : RFOs issued by iA Cores that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO_PREF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC887FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership prefetch from local IA that hit the cache",
                .full_desc =
                    "TOR Occupancy : RFO_Prefs issued by iA Cores that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_ITOM",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC47FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoM events that are initiated from the Core",
                .full_desc = "TOR Occupancy : ItoMs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_ITOMCACHENEAR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCD47FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoMCacheNear requests from local IA cores",
                .full_desc =
                    "TOR Occupancy : ItoMCacheNears issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFCODE",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCCFFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch code read from local IA.",
                .full_desc = "TOR Occupancy : LLCPrefCode issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFDATA",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCD7FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch data read from local IA.",
                .full_desc = "TOR Occupancy : LLCPrefData issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFRFO",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCC7FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch read for ownership from local IA that miss the cache",
                .full_desc = "TOR Occupancy : LLCPrefRFO issued by iA Cores",
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
                    "TOR Occupancy for Code read from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : CRds issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_LOCAL",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC80EFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for CRDs from local IA cores to locally homed memory",
                .full_desc =
                    "TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88FFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Code read prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF_LOCAL",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88EFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for CRD Prefetches from local IA cores to locally homed memory",
                .full_desc =
                    "TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF_REMOTE",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC88F7EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for CRD Prefetches from local IA cores to remotely homed memory",
                .full_desc =
                    "TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_REMOTE",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC80F7EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for CRDs from local IA cores to remotely homed memory",
                .full_desc =
                    "TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C00182ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.",
                .full_desc =
                    "TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C81782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for DRds and equivalent opcodes issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.",
                .full_desc =
                    "TOR Occupancy for DRds and equivalent opcodes issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT_PREF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8A7FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Data read opt prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : DRd_Opt_Prefs issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C89782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "TOR Occupancy for L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_ITOM",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC47FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoM requests from local IA cores that miss the cache",
                .full_desc =
                    "TOR Occupancy : ItoMs issued by iA Cores that Missed LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFCODE",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCCFFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch code read from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : LLCPrefCode issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFDATA",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCD7FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch data read from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : LLCPrefData issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFDATA_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10CCD782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "TOR Occupancy for LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFRFO",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCCC7FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Last level cache prefetch read for ownership from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : LLCPrefRFO issued by iA Cores that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFRFO_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C88782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "TOR Occupancy for L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCILF_DDR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86686ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCILF requests from local IA cores to locally homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCIL_DDR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86E86ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCIL requests from local IA cores to locally homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCILF_DDR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86706ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCILF requests from local IA cores to remotely homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCIL_DDR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86F06ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCIL requests from local IA cores to remotely homed DDR addresses that miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely",
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
                    "TOR Occupancy for Read for ownership from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : RFOs issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10C80782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "TOR Occupancy for RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_LOCAL",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC806FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : RFOs issued by iA Cores that Missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC887FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : RFO_Prefs issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_CXL_ACC",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x10CCC782ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
                .full_desc =
                    "TOR Occupancy for LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_LOCAL",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC886FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed locally",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_REMOTE",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8877EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership prefetch from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_REMOTE",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC8077EULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership from local IA that miss the cache",
                .full_desc =
                    "TOR Occupancy : RFOs issued by iA Cores that Missed the LLC - HOMed remotely",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_UCRDF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC877DEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for UCRDF requests from local IA cores that miss the cache",
                .full_desc =
                    "TOR Occupancy : UCRdFs issued by iA Cores that Missed LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86FFEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCIL requests from a local IA core that miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLs issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC867FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCILF requests from local IA core that miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLF issued by iA Cores that Missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF_DDR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86786ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCILF requests from local IA cores to DDR homed addresses which miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL_DDR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86F86ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCIL requests from local IA cores to DDR homed addresses which miss the cache",
                .full_desc =
                    "TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WIL",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC87FDEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WIL requests from local IA cores that miss the cache",
                .full_desc =
                    "TOR Occupancy : WiLs issued by iA Cores that Missed LLC",
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
                .brief_desc =
                    "TOR Occupancy for Read for ownership from local IA that miss the cache",
                .full_desc = "TOR Occupancy : RFOs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_RFO_PREF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC887FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for Read for ownership prefetch from local IA that miss the cache",
                .full_desc = "TOR Occupancy : RFO_Prefs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_SPECITOM",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC57FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for SpecItoM events that are initiated from the Core",
                .full_desc = "TOR Occupancy : SpecItoMs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_WBMTOI",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xCC27FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WbMtoI requests from local IA cores",
                .full_desc = "TOR Occupancy : WbMtoIs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_WCIL",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC86FFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCIL requests from a local IA core",
                .full_desc = "TOR Occupancy : WCiLs issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IA_WCILF",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0xC867FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WCILF requests from local IA core",
                .full_desc = "TOR Occupancy : WCiLF issued by iA Cores",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_CLFLUSH",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC8C3FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for CLFlush requests from IO devices",
                .full_desc = "TOR Occupancy : CLFlushes issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_HIT_ITOM",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCC43FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoMs from local IO devices which hit the cache",
                .full_desc =
                    "TOR Occupancy : ItoMs issued by IO Devices that Hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_HIT_ITOMCACHENEAR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCD43FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC",
                .full_desc =
                    "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_HIT_PCIRDCUR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC8F3FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for PCIRDCURs issued by IO devices which hit the LLC",
                .full_desc =
                    "TOR Occupancy : PCIRdCurs issued by IO Devices that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_HIT_RFO",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC803FDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for RFOs from local IO devices which hit the cache",
                .full_desc =
                    "TOR Occupancy : RFOs issued by IO Devices that hit the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_ITOM",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCC43FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for All TOR ItoM inserts from local IO devices",
                .full_desc = "TOR Occupancy : ItoMs issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_ITOMCACHENEAR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCD43FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoMCacheNears, indicating a partial write request, from IO Devices",
                .full_desc =
                    "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCC43FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for All TOR ItoM inserts from local IO devices which miss the cache",
                .full_desc =
                    "TOR Occupancy : ItoMs issued by IO Devices that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOMCACHENEAR",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCD43FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
                .full_desc =
                    "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
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
                    "TOR Occupancy for PCIRDCURs issued by IO devices which miss the LLC",
                .full_desc =
                    "TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_RFO",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC803FEULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for All TOR RFO inserts from local IO devices which miss the cache",
                .full_desc =
                    "TOR Occupancy : RFOs issued by IO Devices that missed the LLC",
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
                    "TOR Occupancy for PCIRDCURs issued by IO devices",
                .full_desc = "TOR Occupancy : PCIRdCurs issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_RFO",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xC803FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "TOR Occupancy for RFOs from local IO devices",
                .full_desc = "TOR Occupancy : RFOs issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_cha,
                .id = "UNC_CHA_TOR_OCCUPANCY.IO_WBMTOI",
                .encoding =
                    {
                        .code = 0x36ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0xCC23FFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TOR Occupancy for WBMtoI requests from IO devices",
                .full_desc = "TOR Occupancy : WbMtoIs issued by IO Devices",
            },
            {
                .pmu_type = PmuType::uncore_chacms,
                .id = "UNC_CHACMS_CLOCKTICKS",
                .encoding =
                    {
                        .code = 0x1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Clockticks for CMS units attached to CHA",
                .full_desc = "UNC_CHACMS_CLOCKTICKS",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_ACT_COUNT.ALL",
                .encoding =
                    {
                        .code = 0x2ULL,
                        .umask = 0xF7ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "DRAM Activate Count : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                .full_desc = "DRAM Activate Count",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_CAS_COUNT_SCH0.ALL",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CAS count for SubChannel 0, all CAS operations",
                .full_desc = "CAS count for SubChannel 0, all CAS operations",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_CAS_COUNT_SCH0.RD_REG",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xC1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CAS count for SubChannel 0 regular reads",
                .full_desc = "CAS count for SubChannel 0 regular reads",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_CAS_COUNT_SCH0.RD_UNDERFILL",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xC4ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CAS count for SubChannel 0 underfill reads",
                .full_desc = "CAS count for SubChannel 0 underfill reads",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_CAS_COUNT_SCH1.ALL",
                .encoding =
                    {
                        .code = 0x6ULL,
                        .umask = 0xFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CAS count for SubChannel 1, all CAS operations",
                .full_desc = "CAS count for SubChannel 1, all CAS operations",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_CAS_COUNT_SCH1.RD_REG",
                .encoding =
                    {
                        .code = 0x6ULL,
                        .umask = 0xC1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CAS count for SubChannel 1 regular reads",
                .full_desc = "CAS count for SubChannel 1 regular reads",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_CAS_COUNT_SCH1.RD_UNDERFILL",
                .encoding =
                    {
                        .code = 0x6ULL,
                        .umask = 0xC4ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CAS count for SubChannel 1 underfill reads",
                .full_desc = "CAS count for SubChannel 1 underfill reads",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_CLOCKTICKS",
                .encoding =
                    {
                        .code = 0x1ULL,
                        .umask = 0x1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of DRAM DCLK clock cycles while the event is enabled.  DCLK is 1/4 of DRAM data rate.",
                .full_desc = "DRAM Clockticks",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_PRE_COUNT.ALL",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0xFFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                .full_desc = "DRAM Precharge commands.",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_PRE_COUNT.PGT",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0xF8ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "DRAM Precharge commands. : Precharge due to (?) : Counts the number of DRAM Precharge commands sent on this channel.",
                .full_desc = "DRAM Precharge commands.",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RDB_OCCUPANCY_SCH0",
                .encoding =
                    {
                        .code = 0x1AULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Read buffer occupancy on subchannel 0",
                .full_desc = "Read buffer occupancy on subchannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RDB_OCCUPANCY_SCH1",
                .encoding =
                    {
                        .code = 0x1BULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Read buffer occupancy on subchannel 1",
                .full_desc = "Read buffer occupancy on subchannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_INSERTS.SCH0_PCH0",
                .encoding =
                    {
                        .code = 0x10ULL,
                        .umask = 0x10ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read Pending Queue inserts for subchannel 0, pseudochannel 0",
                .full_desc =
                    "Read Pending Queue inserts for subchannel 0, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_INSERTS.SCH0_PCH1",
                .encoding =
                    {
                        .code = 0x10ULL,
                        .umask = 0x20ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read Pending Queue inserts for subchannel 0, pseudochannel 1",
                .full_desc =
                    "Read Pending Queue inserts for subchannel 0, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_INSERTS.SCH1_PCH0",
                .encoding =
                    {
                        .code = 0x10ULL,
                        .umask = 0x40ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read Pending Queue inserts for subchannel 1, pseudochannel 0",
                .full_desc =
                    "Read Pending Queue inserts for subchannel 1, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_INSERTS.SCH1_PCH1",
                .encoding =
                    {
                        .code = 0x10ULL,
                        .umask = 0x80ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read Pending Queue inserts for subchannel 1, pseudochannel 1",
                .full_desc =
                    "Read Pending Queue inserts for subchannel 1, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_OCCUPANCY_SCH0_PCH0",
                .encoding =
                    {
                        .code = 0x80ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read pending queue occupancy for subchannel 0, pseudochannel 0",
                .full_desc =
                    "Read pending queue occupancy for subchannel 0, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_OCCUPANCY_SCH0_PCH1",
                .encoding =
                    {
                        .code = 0x81ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read pending queue occupancy for subchannel 0, pseudochannel 1",
                .full_desc =
                    "Read pending queue occupancy for subchannel 0, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_OCCUPANCY_SCH1_PCH0",
                .encoding =
                    {
                        .code = 0x82ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read pending queue occupancy for subchannel 1, pseudochannel 0",
                .full_desc =
                    "Read pending queue occupancy for subchannel 1, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_RPQ_OCCUPANCY_SCH1_PCH1",
                .encoding =
                    {
                        .code = 0x83ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Read pending queue occupancy for subchannel 1, pseudochannel 1",
                .full_desc =
                    "Read pending queue occupancy for subchannel 1, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_INSERTS.SCH0_PCH0",
                .encoding =
                    {
                        .code = 0x22ULL,
                        .umask = 0x10ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write Pending Queue inserts for subchannel 0, pseudochannel 0",
                .full_desc =
                    "Write Pending Queue inserts for subchannel 0, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_INSERTS.SCH0_PCH1",
                .encoding =
                    {
                        .code = 0x22ULL,
                        .umask = 0x20ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write Pending Queue inserts for subchannel 0, pseudochannel 1",
                .full_desc =
                    "Write Pending Queue inserts for subchannel 0, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_INSERTS.SCH1_PCH0",
                .encoding =
                    {
                        .code = 0x22ULL,
                        .umask = 0x40ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write Pending Queue inserts for subchannel 1, pseudochannel 0",
                .full_desc =
                    "Write Pending Queue inserts for subchannel 1, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_INSERTS.SCH1_PCH1",
                .encoding =
                    {
                        .code = 0x22ULL,
                        .umask = 0x80ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write Pending Queue inserts for subchannel 1, pseudochannel 1",
                .full_desc =
                    "Write Pending Queue inserts for subchannel 1, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_OCCUPANCY_SCH0_PCH0",
                .encoding =
                    {
                        .code = 0x84ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write pending queue occupancy for subchannel 0, pseudochannel 0",
                .full_desc =
                    "Write pending queue occupancy for subchannel 0, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_OCCUPANCY_SCH0_PCH1",
                .encoding =
                    {
                        .code = 0x85ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write pending queue occupancy for subchannel 0, pseudochannel 1",
                .full_desc =
                    "Write pending queue occupancy for subchannel 0, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_OCCUPANCY_SCH1_PCH0",
                .encoding =
                    {
                        .code = 0x86ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write pending queue occupancy for subchannel 1, pseudochannel 0",
                .full_desc =
                    "Write pending queue occupancy for subchannel 1, pseudochannel 0",
            },
            {
                .pmu_type = PmuType::uncore_imc,
                .id = "UNC_M_WPQ_OCCUPANCY_SCH1_PCH1",
                .encoding =
                    {
                        .code = 0x87ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Write pending queue occupancy for subchannel 1, pseudochannel 1",
                .full_desc =
                    "Write pending queue occupancy for subchannel 1, pseudochannel 1",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_CLOCKTICKS",
                .encoding =
                    {
                        .code = 0x1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "IIO Clockticks",
                .full_desc = "IIO Clockticks",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART0",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70010ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART1",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70020ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART2",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70040ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART3",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70080ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART4",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70100ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART5",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70200ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART6",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70400ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART7",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70800ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Data requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.ALL_PARTS",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x8ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Another card (different IIO stack) reading from this card.",
                .full_desc =
                    "Data requested by the CPU : Another card (different IIO stack) reading from this card.",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.ALL_PARTS",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x2ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Data requested by the CPU : Another card (different IIO stack) writing to this card.",
                .full_desc =
                    "Data requested by the CPU : Another card (different IIO stack) writing to this card.",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.ALL_PARTS",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts once for every 4 bytes read from this card to memory.  This event does include reads to IO.",
                .full_desc =
                    "Counts once for every 4 bytes read from this card to memory.  This event does include reads to IO.",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART0",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70010ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART1",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70020ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART2",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70040ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART3",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70080ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART4",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70100ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART5",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70200ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART6",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70400ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART7",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70800ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.ALL_PARTS",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts once for every 4 bytes written from this card to memory.  This event does include writes to IO.",
                .full_desc =
                    "Counts once for every 4 bytes written from this card to memory.  This event does include writes to IO.",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART0",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70010ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART1",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70020ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART2",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70040ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART3",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70080ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART4",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70100ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART5",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70200ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART6",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70400ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART7",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70800ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
                .full_desc =
                    "Four byte data request of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.ALL_PARTS",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART0",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70010ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART1",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70020ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART2",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70040ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART3",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70080ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART4",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70100ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART5",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70200ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART6",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70400ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART7",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70800ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.ALL_PARTS",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART0",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70010ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART1",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70020ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART2",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70040ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART3",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70080ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART4",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70100ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART5",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70200ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART6",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70400ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART7",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70800ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                .full_desc =
                    "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.ALL_PARTS",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x8ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Another card (different IIO stack) reading from this card.",
                .full_desc =
                    "Number Transactions requested by the CPU : Another card (different IIO stack) reading from this card.",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.ALL_PARTS",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x2ULL,
                        .umask_ext = 0x70FF0ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested by the CPU : Another card (different IIO stack) writing to this card.",
                .full_desc =
                    "Number Transactions requested by the CPU : Another card (different IIO stack) writing to this card.",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART0",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70010ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART1",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70020ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART2",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70040ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART3",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70080ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART4",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70100ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART5",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70200ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART6",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70400ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART7",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x4ULL,
                        .umask_ext = 0x70800ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card reading from DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART0",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70010ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART1",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70020ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART2",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70040ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART3",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70080ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART4",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70100ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART5",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70200ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART6",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70400ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_iio,
                .id = "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART7",
                .encoding =
                    {
                        .code = 0x84ULL,
                        .umask = 0x1ULL,
                        .umask_ext = 0x70800ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
                .full_desc =
                    "Number Transactions requested of the CPU : Card writing to DRAM",
            },
            {
                .pmu_type = PmuType::uncore_irp,
                .id = "UNC_I_CLOCKTICKS",
                .encoding =
                    {
                        .code = 0x1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "IRP Clockticks",
                .full_desc = "IRP Clockticks",
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
                    "Inbound read requests received by the IRP and inserted into the FAF queue",
                .full_desc =
                    "Inbound read requests received by the IRP and inserted into the FAF queue",
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
                    "Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.",
                .full_desc =
                    "Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.",
            },
            {
                .pmu_type = PmuType::uncore_pcu,
                .id = "UNC_P_CLOCKTICKS",
                .encoding =
                    {
                        .code = 0x1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "PCU Clockticks",
                .full_desc =
                    "PCU Clockticks:  The PCU runs off a fixed 1 GHz clock.  This event counts the number of pclk cycles measured while the counter was enabled.  The pclk, like the Memory Controller's dclk, counts at a constant rate making it a good measure of actual wall time.",
            },
            {
                .pmu_type = PmuType::uncore_pcu,
                .id = "UNC_P_POWER_STATE_OCCUPANCY_CORES_C0",
                .encoding =
                    {
                        .code = 0x35ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Number of cores in C0",
                .full_desc =
                    "Number of cores in C0 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.",
            },
            {
                .pmu_type = PmuType::uncore_pcu,
                .id = "UNC_P_POWER_STATE_OCCUPANCY_CORES_C6",
                .encoding =
                    {
                        .code = 0x37ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Number of cores in C6",
                .full_desc =
                    "Number of cores in C6 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_CLOCKTICKS",
                .encoding =
                    {
                        .code = 0x1ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of UPI LL clock cycles while the event is enabled",
                .full_desc = "Number of kfclks",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.REQ",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x8ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Matches on Receive path of a UPI Port : Request",
                .full_desc = "Matches on Receive path of a UPI Port : Request",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.WB",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xDULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Matches on Receive path of a UPI Port : Writeback",
                .full_desc =
                    "Matches on Receive path of a UPI Port : Writeback",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_RxL_FLITS.ALL_DATA",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0xFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Valid Flits Received : All Data : Shows legal flit time (hides impact of L0p and L0c).",
                .full_desc = "Valid Flits Received : All Data",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_RxL_FLITS.NON_DATA",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x97ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Valid Flits Received : All Non Data : Shows legal flit time (hides impact of L0p and L0c).",
                .full_desc = "Valid Flits Received : All Non Data",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_TxL_FLITS.ALL_DATA",
                .encoding =
                    {
                        .code = 0x2ULL,
                        .umask = 0xFULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Valid Flits Sent : All Data : Counts number of data flits across this UPI link.",
                .full_desc = "Valid Flits Sent : All Data",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_TxL_FLITS.ALL_NULL",
                .encoding =
                    {
                        .code = 0x2ULL,
                        .umask = 0x27ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "All Null Flits",
                .full_desc = "Valid Flits Sent : Idle",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_TxL_FLITS.IDLE",
                .encoding =
                    {
                        .code = 0x2ULL,
                        .umask = 0x47ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Valid Flits Sent : Idle : Shows legal flit time (hides impact of L0p and L0c).",
                .full_desc = "Valid Flits Sent",
            },
            {
                .pmu_type = PmuType::uncore_upi,
                .id = "UNC_UPI_TxL_FLITS.NON_DATA",
                .encoding =
                    {
                        .code = 0x2ULL,
                        .umask = 0x97ULL,
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Valid Flits Sent : All Non Data : Shows legal flit time (hides impact of L0p and L0c).",
                .full_desc =
                    "Valid Flits Sent : Null FLITs transmitted to any slot",
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

} // namespace sierraforest_uncore
} // namespace facebook::hbt::perf_event::generated
