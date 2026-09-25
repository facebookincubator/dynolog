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
namespace sapphirerapids_uncore {
namespace {

/*
  Events from sapphirerapids_uncore.json (287 events).

  Supported SKUs:
      - Arch: x86, Model: SPR id: 143
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
        .brief_desc = "CHA Clockticks",
        .full_desc = "Number of CHA clock cycles while the event is enabled",
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
        .brief_desc = "Read requests from a unit on this socket",
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
        .brief_desc = "Read requests from a remote socket",
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
        .brief_desc = "Write Requests from a unit on this socket",
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
        .brief_desc = "Read and Write Requests; Writes Remote",
        .full_desc =
            "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x1ULL,
                .umask_ext = 0xC816FEULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "TOR Inserts for DRd misses from local IA targeting local memory",
        .full_desc =
            "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target local memory",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE",
        .encoding =
            {
                .code = 0x35ULL,
                .umask = 0x1ULL,
                .umask_ext = 0xC8177EULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "TOR Inserts for DRd misses from local IA targeting remote memory",
        .full_desc =
            "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and target remote memory",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x1ULL,
                .umask_ext = 0xC816FEULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "TOR Occupancy for DRd misses from local IA targeting local memory",
        .full_desc =
            "Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target local memory",
    },
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE",
        .encoding =
            {
                .code = 0x36ULL,
                .umask = 0x1ULL,
                .umask_ext = 0xC8177EULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "TOR Occupancy for DRd misses from local IA targeting remote memory",
        .full_desc =
            "Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target remote memory",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT.RD",
        .encoding =
            {
                .code = 0x5ULL,
                .umask = 0xCFULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "All DRAM read CAS commands issued (including underfills)",
        .full_desc =
            "DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM Read CAS commands issued on this channel.  This includes underfills.",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT.WR",
        .encoding =
            {
                .code = 0x5ULL,
                .umask = 0xF0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All DRAM write CAS commands issued",
        .full_desc =
            "DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM Write CAS commands issued on this channel.",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::
    array<StaticEventDef, 267>
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
                    .id = "UNC_CHA_DIR_UPDATE.HA",
                    .encoding =
                        {
                            .code = 0x54ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Multi-socket cacheline Directory state updates; Directory Updated memory write from the HA pipe",
                    .full_desc =
                        "Counts only multi-socket cacheline Directory state updates memory writes issued from the HA pipe. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_DIR_UPDATE.TOR",
                    .encoding =
                        {
                            .code = 0x54ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Multi-socket cacheline Directory state updates; Directory Updated memory write from TOR pipe",
                    .full_desc =
                        "Counts only multi-socket cacheline Directory state updates due to memory writes issued from the TOR pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.",
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
                        "CHA to iMC Full Line Writes Issued; Full Line Non-ISOCH",
                    .full_desc =
                        "Counts when a normal (Non-Isochronous) full line write is issued from the CHA to the any of the memory controller channels.",
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
                        "Local requests for exclusive ownership of a cache line  without receiving data",
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
                        "Remote requests for exclusive ownership of a cache line  without receiving data",
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
                    .brief_desc = "Read requests made into the CHA",
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
                    .brief_desc = "Write requests made into the CHA",
                    .full_desc =
                        "Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.",
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
                    .brief_desc = "TOR Inserts; All from Local IA",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; All locally initiated requests from IA Cores",
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
                    .brief_desc = "TOR Inserts;CLFlush from Local IA",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; CLFlush events that are initiated from the Core",
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
                    .brief_desc = "TOR Inserts; CRd from local IA",
                    .full_desc =
                        "TOR Inserts; Code read from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_DRD",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC817FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; DRd from local IA",
                    .full_desc =
                        "TOR Inserts; Data read from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_DRD_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC897FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; DRd Pref from local IA",
                    .full_desc =
                        "TOR Inserts; Data read prefetch from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts; Hits from Local IA",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.",
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
                    .brief_desc = "TOR Inserts; CRd hits from local IA",
                    .full_desc =
                        "TOR Inserts; Code read from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Inserts; CRd Pref hits from local IA",
                    .full_desc =
                        "TOR Inserts; Code read prefetch from local IA that hits in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_DRD",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC817FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; DRd hits from local IA",
                    .full_desc =
                        "TOR Inserts; Data read from local IA that hits in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC897FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; DRd Pref hits from local IA",
                    .full_desc =
                        "TOR Inserts; Data read prefetch from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Inserts; LLCPrefRFO hits from local IA",
                    .full_desc =
                        "TOR Inserts; Last level cache prefetch read for ownership from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Inserts; RFO hits from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Inserts; RFO Pref hits from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership prefetch from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Inserts; LLCPrefData from local IA",
                    .full_desc =
                        "TOR Inserts; Last level cache prefetch data read from local IA.",
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
                    .brief_desc = "TOR Inserts; LLCPrefRFO from local IA",
                    .full_desc =
                        "TOR Inserts; Last level cache prefetch read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts; misses from Local IA",
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
                    .brief_desc = "TOR Inserts for CRd misses from local IA",
                    .full_desc =
                        "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode CRd",
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
                    .brief_desc = "TOR Inserts; CRd Pref misses from local IA",
                    .full_desc =
                        "TOR Inserts; Code read prefetch from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC817FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts for DRd misses from local IA",
                    .full_desc =
                        "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_DDR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC81786ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts for DRds issued by IA Cores targeting DDR Mem that Missed the LLC",
                    .full_desc =
                        "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target DDR memory",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL_DDR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC81686ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally",
                    .full_desc = "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8168AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8178AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts for DRds issued by iA Cores targeting PMM Mem that Missed the LLC",
                    .full_desc =
                        "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target PMM memory",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC897FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts for DRd Pref misses from local IA",
                    .full_desc =
                        "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_LOCAL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC896FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts for DRd Pref misses from local IA targeting local memory",
                    .full_desc =
                        "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF, and target local memory",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_REMOTE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8977EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts for DRd Pref misses from local IA targeting remote memory",
                    .full_desc =
                        "Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF, and target remote memory",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE_DDR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC81706ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8170AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Inserts; LLCPrefData misses from local IA",
                    .full_desc =
                        "TOR Inserts; Last level cache prefetch data read from local IA that misses in the snoop filter",
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
                        "TOR Inserts; LLCPrefRFO misses from local IA",
                    .full_desc =
                        "TOR Inserts; Last level cache prefetch read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts; RFO misses from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts RFO misses from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts; RFO pref misses from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                        "TOR Inserts; RFO prefetch misses from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                        "TOR Inserts; RFO prefetch misses from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts; RFO misses from local IA",
                    .full_desc =
                        "TOR Inserts Read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts; RFO from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts; RFO pref from local IA",
                    .full_desc =
                        "TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Inserts;SpecItoM from Local IA",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; SpecItoM events that are initiated from the Core",
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
                    .brief_desc = "TOR Inserts; All from local IO",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc =
                        "TOR Inserts : CLFlushes issued by IO Devices",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts; Hits from local IO",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts; ItoM hits from local IO",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Inserts; RdCur and FsRdCur hits from local IO",
                    .full_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts; RFO hits from local IO",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts for ItoM from local IO",
                    .full_desc =
                        "Inserts into the TOR from local IO with the opcode ItoM",
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
                        "TOR Inserts for ItoMCacheNears from IO devices.",
                    .full_desc =
                        "Inserts into the TOR from local IO devices with the opcode ItoMCacheNears.  This event indicates a partial write request.",
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
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts; Misses from local IO",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Inserts : ItoM, indicating a full cacheline write request, from IO Devices that missed the LLC",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Inserts; RdCur and FsRdCur requests from local IO that miss LLC",
                    .full_desc =
                        "TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts; RFO misses from local IO",
                    .full_desc =
                        "TOR Inserts : RFOs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts for RdCur from local IO",
                    .full_desc =
                        "Inserts into the TOR from local IO with the opcode RdCur",
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
                        "PCIRDCUR (read) transactions from an IO device that addresses memory on a remote socket",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                        "PCIRDCUR (read) transactions from an IO device that addresses memory on the local socket",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts; RFO from local IO",
                    .full_desc =
                        "TOR Inserts : RFOs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Inserts : WbMtoIs issued by IO Devices",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; All from local IA",
                    .full_desc =
                        "TOR Occupancy : All requests from iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Occupancy : CLFlushes issued by iA Cores",
                    .full_desc =
                        "TOR Occupancy : CLFlushes issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; CRd from local IA",
                    .full_desc =
                        "TOR Occupancy; Code read from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_DRD",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC817FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; DRd from local IA",
                    .full_desc =
                        "TOR Occupancy; Data read from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_DRD_PREF",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC897FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; DRd Pref from local IA",
                    .full_desc =
                        "TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; Hits from local IA",
                    .full_desc =
                        "TOR Occupancy : All requests from iA Cores that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; CRd hits from local IA",
                    .full_desc =
                        "TOR Occupancy; Code read from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; CRd Pref hits from local IA",
                    .full_desc =
                        "TOR Occupancy; Code read prefetch from local IA that hits in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC817FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; DRd hits from local IA",
                    .full_desc =
                        "TOR Occupancy; Data read from local IA that hits in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_PREF",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC897FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; DRd Pref hits from local IA",
                    .full_desc =
                        "TOR Occupancy; Data read prefetch from local IA that hits in the snoop filter",
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
                        "TOR Occupancy; LLCPrefRFO hits from local IA",
                    .full_desc =
                        "TOR Occupancy; Last level cache prefetch read for ownership from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; RFO hits from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; RFO Pref hits from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership prefetch from local IA that hits in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; LLCPrefData from local IA",
                    .full_desc =
                        "TOR Occupancy; Last level cache prefetch data read from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; LLCPrefRFO from local IA",
                    .full_desc =
                        "TOR Occupancy; Last level cache prefetch read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; Misses from Local IA",
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
                    .brief_desc = "TOR Occupancy; CRd misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Code read from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC817FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy for DRd misses from local IA",
                    .full_desc =
                        "Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_DDR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC81786ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for DRds issued by iA Cores targeting DDR Mem that Missed the LLC",
                    .full_desc =
                        "Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target DDR memory",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL_DDR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC81686ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally",
                    .full_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8168AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally",
                    .full_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8178AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for DRds issued by iA Cores targeting PMM Mem that Missed the LLC",
                    .full_desc =
                        "Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target PMM memory",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC897FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy; DRd Pref misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_REMOTE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8977EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy; DRd Pref misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE_DDR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC81706ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely",
                    .full_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8170AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely",
                    .full_desc =
                        "TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Occupancy; LLCPrefData misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Last level cache prefetch data read from local IA that misses in the snoop filter",
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
                        "TOR Occupancy; LLCPrefRFO misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Last level cache prefetch read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; RFO misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; RFO misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership from local IA that misses in the snoop filter",
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
                        "TOR Occupancy; RFO prefetch misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                        "TOR Occupancy; RFO prefetch misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                        "TOR Occupancy; RFO prefetch misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; RFO misses from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; RFO from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership from local IA that misses in the snoop filter",
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
                    .brief_desc = "TOR Occupancy; RFO prefetch from local IA",
                    .full_desc =
                        "TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter",
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
                        "TOR Occupancy : SpecItoMs issued by iA Cores",
                    .full_desc =
                        "TOR Occupancy : SpecItoMs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; All from local IO",
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
                    .brief_desc = "TOR Occupancy; Hits from local IO",
                    .full_desc =
                        "TOR Occupancy : All requests from IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; ITOM hits from local IO",
                    .full_desc =
                        "TOR Occupancy : ItoMs issued by IO Devices that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC",
                    .full_desc =
                        "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Occupancy; RdCur and FsRdCur hits from local IO",
                    .full_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; ITOM from local IO",
                    .full_desc =
                        "TOR Occupancy : ItoMs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; Misses from local IO",
                    .full_desc =
                        "TOR Occupancy : All requests from IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                    .brief_desc = "TOR Occupancy; ITOM misses from local IO",
                    .full_desc =
                        "TOR Occupancy : ItoMs issued by IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
                    .full_desc =
                        "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
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
                        "TOR Occupancy; RdCur and FsRdCur misses from local IO",
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
                        "TOR Occupancy; RdCur and FsRdCur from local IO",
                    .full_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ACT_COUNT.ALL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0xFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Activate due to read, write, underfill, or bypass",
                    .full_desc =
                        "DRAM Activate Count : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT.ALL",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All DRAM CAS commands issued",
                    .full_desc =
                        "DRAM RD_CAS and WR_CAS Commands. : All DRAM Read and Write actions : DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM CAS commands issued on this channel.",
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
                    .brief_desc = "IMC Clockticks at DCLK frequency",
                    .full_desc =
                        "Number of DRAM DCLK clock cycles while the event is enabled",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_HCLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IMC Clockticks at HCLK frequency",
                    .full_desc =
                        "Number of DRAM HCLK clock cycles while the event is enabled",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PMM_RPQ_INSERTS",
                    .encoding =
                        {
                            .code = 0xE3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM Read Pending Queue inserts",
                    .full_desc =
                        "Counts number of read requests allocated in the PMM Read Pending Queue.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PMM_RPQ_OCCUPANCY.ALL_SCH0",
                    .encoding =
                        {
                            .code = 0xE0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM Read Pending Queue occupancy",
                    .full_desc =
                        "Accumulates the per cycle occupancy of the PMM Read Pending Queue.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PMM_RPQ_OCCUPANCY.ALL_SCH1",
                    .encoding =
                        {
                            .code = 0xE0ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM Read Pending Queue occupancy",
                    .full_desc =
                        "Accumulates the per cycle occupancy of the PMM Read Pending Queue.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PMM_WPQ_INSERTS",
                    .encoding =
                        {
                            .code = 0xE7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM Write Pending Queue inserts",
                    .full_desc =
                        "Counts number of  write requests allocated in the PMM Write Pending Queue.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PMM_WPQ_OCCUPANCY.ALL",
                    .encoding =
                        {
                            .code = 0xE4ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM Write Pending Queue Occupancy",
                    .full_desc =
                        "PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the Write Pending Queue to the PMM DIMM.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PMM_WPQ_OCCUPANCY.ALL_SCH0",
                    .encoding =
                        {
                            .code = 0xE4ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM Write Pending Queue Occupancy",
                    .full_desc =
                        "PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Write Pending Queue.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PMM_WPQ_OCCUPANCY.ALL_SCH1",
                    .encoding =
                        {
                            .code = 0xE4ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM Write Pending Queue Occupancy",
                    .full_desc =
                        "PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Write Pending Queue.",
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
                        "Precharge due to read, write, underfill, or PGT.",
                    .full_desc =
                        "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.PGT",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x88ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Precharge commands",
                    .full_desc =
                        "DRAM Precharge commands.  Counts the number of DRAM Precharge commands sent on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.RD",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Precharge due to read on page miss",
                    .full_desc =
                        "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.WR",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x22ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Precharge due to write on page miss",
                    .full_desc =
                        "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RDB_INSERTS.PCH0",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read Data Buffer Inserts",
                    .full_desc = "Read Data Buffer Inserts",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RDB_INSERTS.PCH1",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read Data Buffer Inserts",
                    .full_desc = "Read Data Buffer Inserts",
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
                    .id = "UNC_M_TAGCHK.HIT",
                    .encoding =
                        {
                            .code = 0xD3ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "2LM Tag check hit in near memory cache (DDR4)",
                    .full_desc =
                        "2LM Tag check hit in near memory cache (DDR4)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_TAGCHK.MISS_CLEAN",
                    .encoding =
                        {
                            .code = 0xD3ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "2LM Tag check miss, no data at this line",
                    .full_desc = "2LM Tag check miss, no data at this line",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_TAGCHK.MISS_DIRTY",
                    .encoding =
                        {
                            .code = 0xD3ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "2LM Tag check miss, existing data may be evicted to PMM",
                    .full_desc =
                        "2LM Tag check miss, existing data may be evicted to PMM",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_TAGCHK.NM_RD_HIT",
                    .encoding =
                        {
                            .code = 0xD3ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "2LM Tag check hit due to memory read",
                    .full_desc = "2LM Tag check hit due to memory read",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_TAGCHK.NM_WR_HIT",
                    .encoding =
                        {
                            .code = 0xD3ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "2LM Tag check hit due to memory write",
                    .full_desc = "2LM Tag check hit due to memory write",
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
                    .brief_desc = "IIO Clockticks",
                    .full_desc =
                        "Number of IIO clock cycles while the event is enabled",
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
                    .full_desc = "0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART0",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70010ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read request for 4 bytes made by the CPU to IIO Part0",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART1",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70020ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read request for 4 bytes made by the CPU to IIO Part1",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART2",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70040ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read request for 4 bytes made by the CPU to IIO Part2",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART3",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70080ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read request for 4 bytes made by the CPU to IIO Part3",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART4",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70100ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART5",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70200ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART6",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70400ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART7",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70800ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
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
                        "Write request of 4 bytes made to IIO Part0 by the CPU",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Write request of 4 bytes made to IIO Part1 by the CPU",
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
                        "Write request of 4 bytes made to IIO Part2 by the CPU",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Write request of 4 bytes made to IIO Part3 by the CPU",
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
                        "Data requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Data requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
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
                        "Data requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Data requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
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
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read request for 4 bytes made by IIO Part0-7 to Memory",
                    .full_desc =
                        "Read request for 4 bytes made by IIO Part0-7 to Memory",
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
                        "Read request for 4 bytes made by IIO Part0 to Memory",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Read request for 4 bytes made by IIO Part1 to Memory",
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
                        "Read request for 4 bytes made by IIO Part2 to Memory",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Read request for 4 bytes made by IIO Part3 to Memory",
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
                        "Data requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Data requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
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
                        "Data requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Data requested of the CPU : Card reading from DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Write request of 4 bytes made by IIO Part0-7 to Memory",
                    .full_desc =
                        "Write request of 4 bytes made by IIO Part0-7 to Memory",
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
                        "Write request of 4 bytes made by IIO Part0 to Memory",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Write request of 4 bytes made by IIO Part1 to Memory",
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
                        "Write request of 4 bytes made by IIO Part2 to Memory",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Write request of 4 bytes made by IIO Part3 to Memory",
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
                        "Data requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Data requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
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
                        "Data requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Data requested of the CPU : Card writing to DRAM",
                    .full_desc =
                        "Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
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
                        "Read request for up to a 64 byte transaction is made by the CPU to IIO Part0",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Read request for up to a 64 byte transaction is made by the CPU to IIO Part1",
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
                        "Read request for up to a 64 byte transaction is made by the CPU to IIO Part2",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Read request for up to a 64 byte transaction is made by the CPU to IIO Part3",
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
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
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
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
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
                        "Write request of up to a 64 byte transaction is made to IIO Part0 by the CPU",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Write request of up to a 64 byte transaction is made to IIO Part1 by the CPU",
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
                        "Write request of up to a 64 byte transaction is made to IIO Part2 by the CPU",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Write request of up to a 64 byte transaction is made to IIO Part3 by the CPU",
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
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1",
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
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3",
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
                        "Read request for up to a 64 byte transaction is made by IIO Part0 to Memory",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Read request for up to a 64 byte transaction is  made by IIO Part1 to Memory",
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
                        "Read request for up to a 64 byte transaction is made by IIO Part2 to Memory",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Read request for up to a 64 byte transaction is made by IIO Part3 to Memory",
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
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
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
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
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
                        "Write request of up to a 64 byte transaction is made by IIO Part0 to Memory",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Write request of up to a 64 byte transaction is made by IIO Part1 to Memory",
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
                        "Write request of up to a 64 byte transaction is made by IIO Part2 to Memory",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Write request of up to a 64 byte transaction is made by IIO Part3 to Memory",
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
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0",
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
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1",
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
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1",
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
                        "Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3",
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
                    .full_desc =
                        "Number of IRP clock cycles while the event is enabled",
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
                    .brief_desc = "FAF - request insert from TC.",
                    .full_desc = "FAF - request insert from TC.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_FAF_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x19ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "FAF occupancy",
                    .full_desc = "FAF occupancy",
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
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "M2M Clockticks",
                    .full_desc = "Clockticks of the mesh to memory (M2M)",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_CMS_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask_ext = 0x800000ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CMS Clockticks",
                    .full_desc = "CMS Clockticks",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_DIRECTORY_LOOKUP.ANY",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Multi-socket cacheline Directory lookups (any state found)",
                    .full_desc =
                        "Counts the number of hit data returns to egress with any directory to non persistent memory",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_DIRECTORY_LOOKUP.STATE_A",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Multi-socket cacheline Directory lookups (cacheline found in A state)",
                    .full_desc =
                        "Counts the number of hit data returns to egress with directory A to non persistent memory",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_DIRECTORY_LOOKUP.STATE_I",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Multi-socket cacheline Directory lookup (cacheline found in I state)",
                    .full_desc =
                        "Counts the number of hit data returns to egress with directory I to non persistent memory",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_DIRECTORY_LOOKUP.STATE_S",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Multi-socket cacheline Directory lookup (cacheline found in S state)",
                    .full_desc =
                        "Counts the number of hit data returns to egress with directory S to non persistent memory",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_DIRECTORY_UPDATE.ANY",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Multi-socket cacheline Directory update from/to Any state",
                    .full_desc =
                        "Multi-socket cacheline Directory update from/to Any state",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_IMC_READS.TO_PMM",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_M2M_IMC_READS.TO_PMM",
                    .full_desc = "UNC_M2M_IMC_READS.TO_PMM",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_IMC_WRITES.TO_PMM",
                    .encoding =
                        {
                            .code = 0x25ULL,
                            .umask = 0x80ULL,
                            .umask_ext = 0x18ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PMM - All Channels",
                    .full_desc = "PMM - All Channels",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_TAG_HIT.NM_RD_HIT_CLEAN",
                    .encoding =
                        {
                            .code = 0x1FULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Clean NearMem Read Hit",
                    .full_desc =
                        "Counts clean full line read hits (reads and RFOs).",
                },
                {
                    .pmu_type = PmuType::uncore_m2m,
                    .id = "UNC_M2M_TAG_HIT.NM_RD_HIT_DIRTY",
                    .encoding =
                        {
                            .code = 0x1FULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Dirty NearMem Read Hit",
                    .full_desc =
                        "Counts dirty full line read hits (reads and RFOs).",
                },
                {
                    .pmu_type = PmuType::uncore_m3upi,
                    .id = "UNC_M3UPI_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "M3UPI Clockticks",
                    .full_desc =
                        "Number of M2UPI clock cycles while the event is enabled",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PCU PCLK Clockticks",
                    .full_desc =
                        "Number of PCU PCLK Clock cycles while the event is enabled",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UPI Clockticks",
                    .full_desc =
                        "Number of UPI LL clock cycles while the event is enabled",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_L1_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0x21ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in L1",
                    .full_desc =
                        "Cycles in L1 : Number of UPI qfclk cycles spent in L1 power mode.  L1 is a mode that totally shuts down a UPI link.  Use edge detect to count the number of instances when the UPI link entered L1.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another. Because L1 totally shuts down the link, it takes a good amount of time to exit this mode.",
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
                    .brief_desc = "Valid Flits Received : All Data",
                    .full_desc =
                        "Valid Flits Received : All Data : Shows legal flit time (hides impact of L0p and L0c).",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.ALL_NULL",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x27ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Null FLITs received from any slot",
                    .full_desc = "Null FLITs received from any slot",
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
                    .brief_desc = "Valid Flits Received : All Non Data",
                    .full_desc =
                        "Valid Flits Received : All Non Data : Shows legal flit time (hides impact of L0p and L0c).",
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
                    .brief_desc = "Valid Flits Sent : All Data",
                    .full_desc =
                        "Valid Flits Sent : All Data : Counts number of data flits across this UPI link.",
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
                    .full_desc = "All Null Flits",
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
                    .brief_desc = "Valid Flits Sent : All Non Data",
                    .full_desc =
                        "Valid Flits Sent : All Non Data : Shows legal flit time (hides impact of L0p and L0c).",
                },
                {
                    .pmu_type = PmuType::uncore_m2pcie,
                    .id = "UNC_M2P_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "M2P Clockticks",
                    .full_desc =
                        "Number of M2P clock cycles while the event is enabled",
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
                {
                    .pmu_type = PmuType::uncore_mchbm,
                    .id = "UNC_MCHBM_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IMC Clockticks at DCLK frequency",
                    .full_desc = "IMC Clockticks at DCLK frequency",
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

} // namespace sapphirerapids_uncore
} // namespace facebook::hbt::perf_event::generated
