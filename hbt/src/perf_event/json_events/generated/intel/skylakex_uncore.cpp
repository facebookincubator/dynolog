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
namespace skylakex_uncore {
namespace {

/*
  Events from skylakex_uncore.json (269 events).

  Supported SKUs:
      - Arch: x86, Model: SKX id: 85 Steps: ['0', '1', '2', '3', '4']
*/
constexpr std::array<StaticEventDef, 7> kAllowlistedEvents{{
    {
        .pmu_type = PmuType::uncore_cha,
        .id = "UNC_CHA_CLOCKTICKS",
        .encoding =
            {
                .code = 0x0ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Clockticks of the uncore caching & home agent (CHA)",
        .full_desc =
            "Counts clockticks of the clock controlling the uncore caching and home agent (CHA).",
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
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT.RD",
        .encoding =
            {
                .code = 0x4ULL,
                .umask = 0x3ULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "All DRAM Read CAS Commands issued (including underfills)",
        .full_desc =
            "Counts all CAS (Column Access Select) read commands issued to DRAM on a per channel basis.  CAS commands are issued to specify the address to read or write on DRAM, and this event increments for every read.  This event includes underfill reads due to partial write requests.  This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write)  is enabled or not.",
    },
    {
        .pmu_type = PmuType::uncore_imc,
        .id = "UNC_M_CAS_COUNT.WR",
        .encoding =
            {
                .code = 0x4ULL,
                .umask = 0xCULL,
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All DRAM Write CAS commands issued",
        .full_desc =
            "Counts all CAS (Column Address Select) commands issued to DRAM per memory channel.  CAS commands are issued to specify the address to read or write on DRAM, and this event increments for every write. This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write) is enabled or not.",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 212> kFullOnlyEvents{
    {
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_CORE_SNP.CORE_GTONE",
            .encoding =
                {
                    .code = 0x33ULL,
                    .umask = 0x42ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Core Cross Snoops Issued; Multiple Core Requests",
            .full_desc =
                "Counts the number of transactions that trigger a configurable number of cross snoops.  Cores are snooped if the transaction looks up the cache and determines that it is necessary based on the operation type and what CoreValid bits are set.  For example, if 2 CV bits are set on a data read, the cores must have the data in S state so it is not necessary to snoop them.  However, if only 1 CV bit is set the core my have modified the data.  If the transaction was an RFO, it would need to invalidate the lines.  This event can be filtered based on who triggered the initial snoop(s).",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_CORE_SNP.EVICT_GTONE",
            .encoding =
                {
                    .code = 0x33ULL,
                    .umask = 0x82ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Core Cross Snoops Issued; Multiple Eviction",
            .full_desc =
                "Counts the number of transactions that trigger a configurable number of cross snoops.  Cores are snooped if the transaction looks up the cache and determines that it is necessary based on the operation type and what CoreValid bits are set.  For example, if 2 CV bits are set on a data read, the cores must have the data in S state so it is not necessary to snoop them.  However, if only 1 CV bit is set the core my have modified the data.  If the transaction was an RFO, it would need to invalidate the lines.  This event can be filtered based on who triggered the initial snoop(s).",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_DIR_LOOKUP.NO_SNP",
            .encoding =
                {
                    .code = 0x53ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multi-socket cacheline Directory state lookups; Snoop Not Needed",
            .full_desc =
                "Counts transactions that looked into the multi-socket cacheline Directory state, and therefore did not send a snoop because the Directory indicated it was not needed",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_DIR_LOOKUP.SNP",
            .encoding =
                {
                    .code = 0x53ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multi-socket cacheline Directory state lookups; Snoop Needed",
            .full_desc =
                "Counts  transactions that looked into the multi-socket cacheline Directory state, and sent one or more snoops, because the Directory indicated it was needed",
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
            .id = "UNC_CHA_FAST_ASSERTED.HORZ",
            .encoding =
                {
                    .code = 0xA5ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FaST wire asserted; Horizontal",
            .full_desc =
                "Counts the number of cycles either the local or incoming distress signals are asserted.  Incoming distress includes up, dn and across.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_HITME_HIT.EX_RDS",
            .encoding =
                {
                    .code = 0x5FULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Read request from a remote socket which hit in the HitMe Cache to a line In the E state",
            .full_desc =
                "Counts read requests from a remote socket which hit in the HitME cache (used to cache the multi-socket Directory state) to a line in the E(Exclusive) state.  This includes the following read opcodes (RdCode, RdData, RdDataMigratory, RdCur, RdInv*, Inv*)",
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
            .id = "UNC_CHA_LLC_VICTIMS.TOTAL_E",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Lines Victimized; Lines in E state",
            .full_desc =
                "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_LLC_VICTIMS.TOTAL_F",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Lines Victimized; Lines in F State",
            .full_desc =
                "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_LLC_VICTIMS.TOTAL_M",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Lines Victimized; Lines in M state",
            .full_desc =
                "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_LLC_VICTIMS.TOTAL_S",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Lines Victimized; Lines in S State",
            .full_desc =
                "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
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
            .brief_desc = "Number of times that an RFO hit in S state.",
            .full_desc =
                "Counts when a RFO (the Read for Ownership issued before a  write) request hit a cacheline in the S (Shared) state.",
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
                "Local requests for exclusive ownership of a cache line without receiving data",
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
            .brief_desc = "Read requests",
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
            .brief_desc = "Write requests",
            .full_desc =
                "Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_RxC_INSERTS.IRQ",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress (from CMS) Allocations; IRQ",
            .full_desc =
                "Counts number of allocations per cycle into the specified Ingress queue.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_RxC_IRQ1_REJECT.PA_MATCH",
            .encoding =
                {
                    .code = 0x19ULL,
                    .umask = 0x80ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Ingress (from CMS) Request Queue Rejects; PhyAddr Match",
            .full_desc =
                "Ingress (from CMS) Request Queue Rejects; PhyAddr Match",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_RxC_OCCUPANCY.IRQ",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress (from CMS) Occupancy; IRQ",
            .full_desc =
                "Counts number of entries in the specified Ingress queue in each cycle.",
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
                "Counts snoop filter capacity evictions for entries tracking exclusive lines in the cores cache. Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry. Does not count clean evictions such as when a cores cache replaces a tracked cacheline with a new cacheline.",
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
                "Counts snoop filter capacity evictions for entries tracking modified lines in the cores cache. Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry. Does not count clean evictions such as when a cores cache replaces a tracked cacheline with a new cacheline.",
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
                "Counts snoop filter capacity evictions for entries tracking shared lines in the cores cache. Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry. Does not count clean evictions such as when a cores cache replaces a tracked cacheline with a new cacheline.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_SNOOP_RESP.RSPCNFLCTS",
            .encoding =
                {
                    .code = 0x5CULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "RspCnflct* Snoop Responses Received",
            .full_desc =
                "Counts when a a transaction with the opcode type RspCnflct* Snoop Response was received. This is returned when a snoop finds an existing outstanding transaction in a remote caching agent. This triggers conflict resolution hardware. This covers both the opcode RspCnflct and RspCnflctWbI.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_SNOOP_RESP.RSPI",
            .encoding =
                {
                    .code = 0x5CULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "RspI Snoop Responses Received",
            .full_desc =
                "Counts when a transaction with the opcode type RspI Snoop Response was received which indicates the remote cache does not have the data, or when the remote cache silently evicts data (such as when an RFO: the Read for Ownership issued before a write hits non-modified data).",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_SNOOP_RESP.RSPIFWD",
            .encoding =
                {
                    .code = 0x5CULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "RspIFwd Snoop Responses Received",
            .full_desc =
                "Counts when a a transaction with the opcode type RspIFwd Snoop Response was received which indicates a remote caching agent forwarded the data and the requesting agent is able to acquire the data in E (Exclusive) or M (modified) states.  This is commonly returned with RFO (the Read for Ownership issued before a write) transactions.  The snoop could have either been to a cacheline in the M,E,F (Modified, Exclusive or Forward)  states.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_SNOOP_RESP.RSPSFWD",
            .encoding =
                {
                    .code = 0x5CULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "RspSFwd Snoop Responses Received",
            .full_desc =
                "Counts when a a transaction with the opcode type RspSFwd Snoop Response was received which indicates a remote caching agent forwarded the data but held on to its current copy.  This is common for data and code reads that hit in a remote socket in E (Exclusive) or F (Forward) state.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_SNOOP_RESP.RSP_FWD_WB",
            .encoding =
                {
                    .code = 0x5CULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Rsp*Fwd*WB Snoop Responses Received",
            .full_desc =
                "Counts when a transaction with the opcode type Rsp*Fwd*WB Snoop Response was received which indicates the data was written back to its home socket, and the cacheline was forwarded to the requestor socket.  This snoop response is only used in >= 4 socket systems.  It is used when a snoop HITM's in a remote caching agent and it directly forwards data to a requestor, and simultaneously returns data to its home socket to be written back to memory.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_SNOOP_RESP.RSP_WBWB",
            .encoding =
                {
                    .code = 0x5CULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Rsp*WB Snoop Responses Received",
            .full_desc =
                "Counts when a transaction with the opcode type Rsp*WB Snoop Response was received which indicates which indicates the data was written back to its home.  This is returned when a non-RFO request hits a cacheline in the Modified state. The Cache can either downgrade the cacheline to a S (Shared) or I (Invalid) state depending on how the system has been configured.  This response will also be sent when a cache requests E (Exclusive) ownership of a cache line without receiving data, because the cache must acquire ownership.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x31ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOR Inserts; All from Local iA",
            .full_desc =
                "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; All locally initiated requests from iA Cores",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_HIT",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOR Inserts; Hits from Local iA",
            .full_desc =
                "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_HIT_CRD",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : CRds issued by iA Cores that Hit the LLC",
            .full_desc =
                "TOR Inserts : CRds issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_HIT_DRD",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : DRds issued by iA Cores that Hit the LLC",
            .full_desc =
                "TOR Inserts : DRds issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefCRD",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefCRD",
            .full_desc = "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefCRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefDRD",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefDRD",
            .full_desc = "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefDRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefRFO",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC",
            .full_desc =
                "TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_HIT_RFO",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : RFOs issued by iA Cores that Hit the LLC",
            .full_desc =
                "TOR Inserts : RFOs issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_MISS",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x21ULL,
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
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : CRds issued by iA Cores that Missed the LLC",
            .full_desc =
                "TOR Inserts : CRds issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_MISS_DRD",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : DRds issued by iA Cores that Missed the LLC",
            .full_desc =
                "TOR Inserts : DRds issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefCRD",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefCRD",
            .full_desc = "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefCRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefDRD",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefDRD",
            .full_desc = "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefDRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefRFO",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC",
            .full_desc =
                "TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IA_MISS_RFO",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Inserts : RFOs issued by iA Cores that Missed the LLC",
            .full_desc =
                "TOR Inserts : RFOs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IO_HIT",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x14ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOR Inserts; Hits from Local IO",
            .full_desc =
                "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_INSERTS.IO_MISS",
            .encoding =
                {
                    .code = 0x35ULL,
                    .umask = 0x24ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOR Inserts; Misses from Local IO",
            .full_desc =
                "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x31ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOR Occupancy; All from Local iA",
            .full_desc =
                "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T; All locally initiated requests from iA Cores",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOR Occupancy; Hits from Local iA",
            .full_desc =
                "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : CRds issued by iA Cores that Hit the LLC",
            .full_desc =
                "TOR Occupancy : CRds issued by iA Cores that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : DRds issued by iA Cores that Hit the LLC",
            .full_desc =
                "TOR Occupancy : DRds issued by iA Cores that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefCRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefCRD",
            .full_desc = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefCRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefDRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefDRD",
            .full_desc = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefDRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefRFO",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : LLCPrefRFO issued by iA Cores that hit the LLC",
            .full_desc =
                "TOR Occupancy : LLCPrefRFO issued by iA Cores that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x11ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : RFOs issued by iA Cores that Hit the LLC",
            .full_desc =
                "TOR Occupancy : RFOs issued by iA Cores that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOR Occupancy; Misses from Local iA",
            .full_desc =
                "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : CRds issued by iA Cores that Missed the LLC",
            .full_desc = "TOR Occupancy : CRds issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : DRds issued by iA Cores that Missed the LLC",
            .full_desc =
                "TOR Occupancy : DRds issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefCRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefCRD",
            .full_desc = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefCRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefDRD",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefDRD",
            .full_desc = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefDRD",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefRFO",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : LLCPrefRFO issued by iA Cores that missed the LLC",
            .full_desc =
                "TOR Occupancy : LLCPrefRFO issued by iA Cores that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TOR Occupancy : RFOs issued by iA Cores that Missed the LLC",
            .full_desc =
                "TOR Occupancy : RFOs issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.",
        },
        {
            .pmu_type = PmuType::uncore_cha,
            .id = "UNC_CHA_UPI_CREDIT_OCCUPANCY.VN0_BL_NCS",
            .encoding =
                {
                    .code = 0x3BULL,
                    .umask = 0x80ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "UPI Ingress Credits In Use Cycles; BL NCS VN0 Credits",
            .full_desc =
                "Accumulates the number of UPI credits available in each cycle for either the AD or BL ring.  In order to send snoops, snoop responses, requests, data, etc to the UPI agent on the ring, it is necessary to first acquire a credit for the UPI ingress buffer.  This stat increments by the number of credits that are available each cycle.  This can be used in conjunction with the Credit Acquired event in order to calculate average credit lifetime.  This event supports filtering for the different types of credits that are available.  Note that you must select the link that you would like to monitor using the link select register, and you can only monitor 1 link at a time.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_ACT_COUNT.WR",
            .encoding =
                {
                    .code = 0x1ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "DRAM Page Activate commands sent due to a write request",
            .full_desc =
                "Counts DRAM Page Activate commands sent on this channel due to a write request to the iMC (Memory Controller).  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS (Column Access Select) command.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_CAS_COUNT.ALL",
            .encoding =
                {
                    .code = 0x4ULL,
                    .umask = 0xFULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "All DRAM CAS Commands issued",
            .full_desc =
                "Counts all CAS (Column Address Select) commands issued to DRAM per memory channel.  CAS commands are issued to specify the address to read or write on DRAM, so this event increments for every read and write. This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write) is enabled or not.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_CAS_COUNT.RD_REG",
            .encoding =
                {
                    .code = 0x4ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "All DRAM Read CAS Commands issued (does not include underfills)",
            .full_desc =
                "Counts CAS (Column Access Select) regular read commands issued to DRAM on a per channel basis.  CAS commands are issued to specify the address to read or write on DRAM, and this event increments for every regular read.  This event only counts regular reads and does not includes underfill reads due to partial write requests.  This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write)  is enabled or not.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_CAS_COUNT.RD_UNDERFILL",
            .encoding =
                {
                    .code = 0x4ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "DRAM Underfill Read CAS Commands issued",
            .full_desc =
                "Counts CAS (Column Access Select) underfill read commands issued to DRAM due to a partial write, on a per channel basis.  CAS commands are issued to specify the address to read or write on DRAM, and this command counts underfill reads.  Partial writes must be completed by first reading in the underfill from DRAM and then merging in the partial write data before writing the full line back to DRAM. This event will generally count about the same as the number of partial writes, but may be slightly less because of partials hitting in the WPQ (due to a previous write request).",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_CAS_COUNT.WR_WMM",
            .encoding =
                {
                    .code = 0x4ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "DRAM CAS (Column Address Strobe) Commands.; DRAM WR_CAS (w/ and w/out auto-pre) in Write Major Mode",
            .full_desc =
                "Counts the total number or DRAM Write CAS commands issued on this channel while in Write-Major-Mode.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_CLOCKTICKS",
            .encoding =
                {
                    .code = 0x0ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Clockticks of the memory controller which uses a programmable counter",
            .full_desc =
                "Counts clockticks of the fixed frequency clock of the memory controller using one of the programmable counters.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_POWER_CHANNEL_PPD",
            .encoding =
                {
                    .code = 0x85ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Channel PPD Cycles",
            .full_desc =
                "Counts cycles when all the ranks in the channel are in PPD (PreCharge Power Down) mode. If IBT (Input Buffer Terminators)=off is enabled, then this event counts the cycles in PPD mode. If IBT=off is not enabled, then this event counts the number of cycles when being in PPD mode could have been taken advantage of.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_POWER_SELF_REFRESH",
            .encoding =
                {
                    .code = 0x43ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Clock-Enabled Self-Refresh",
            .full_desc =
                "Counts the number of cycles when the iMC (memory controller) is in self-refresh and has a clock. This happens in some ACPI CPU package C-states for the sleep levels. For example, the PCU (Power Control Unit) may ask the iMC to enter self-refresh even though some of the cores are still processing. One use of this is for Intel? Dynamic Power Technology.  Self-refresh is required during package C3 and C6, but there is no clock in the iMC at this time, so it is not possible to count these cases.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_PRE_COUNT.PAGE_MISS",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Precharges due to page miss",
            .full_desc =
                "Counts the number of explicit DRAM Precharge commands sent on this channel as a result of a DRAM page miss. This does not include the implicit precharge commands sent with CAS commands in Auto-Precharge mode. This does not include Precharge commands sent as a result of a page close counter expiration.",
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
            .brief_desc = "Precharge due to read",
            .full_desc =
                "Counts the number of explicit DRAM Precharge commands issued on a per channel basis due to a read, so as to close the previous DRAM page, before opening the requested page.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_RPQ_INSERTS",
            .encoding =
                {
                    .code = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Read Pending Queue Allocations",
            .full_desc =
                "Counts the number of read requests allocated into the Read Pending Queue (RPQ).  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  The requests deallocate after the read CAS command has been issued to DRAM.  This event counts both Isochronous and non-Isochronous requests which were issued to the RPQ.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_RPQ_OCCUPANCY",
            .encoding =
                {
                    .code = 0x80ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Read Pending Queue Occupancy",
            .full_desc =
                "Counts the number of entries in the Read Pending Queue (RPQ) at each cycle.  This can then be used to calculate both the average occupancy of the queue (in conjunction with the number of cycles not empty) and the average latency in the queue (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC. They deallocate from the RPQ after the CAS command has been issued to memory.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_WPQ_INSERTS",
            .encoding =
                {
                    .code = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Write Pending Queue Allocations",
            .full_desc =
                "Counts the number of writes requests allocated into the Write Pending Queue (WPQ).  The WPQ is used to schedule writes out to the memory controller and to track the requests.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC (Memory Controller).  The write requests deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have 'posted' to the iMC.",
        },
        {
            .pmu_type = PmuType::uncore_imc,
            .id = "UNC_M_WPQ_OCCUPANCY",
            .encoding =
                {
                    .code = 0x81ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Write Pending Queue Occupancy",
            .full_desc =
                "Counts the number of entries in the Write Pending Queue (WPQ) at each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule writes out to the memory controller and to track the requests.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC (memory controller).  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have 'posted' to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the 'not posted' filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The 'posted' filter, on the other hand, provides information about how much queueing is actually happening in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_CLOCKTICKS",
            .encoding =
                {
                    .code = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Clockticks of the IIO Traffic Controller",
            .full_desc =
                "Counts clockticks of the 1GHz traffic controller clock in the IIO unit.",
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
                "PCIe Completion Buffer Inserts of completions with data: Part 0-3",
            .full_desc =
                "PCIe Completion Buffer Inserts of completions with data: Part 0-3",
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
                "PCIe Completion Buffer Inserts of completions with data: Part 0",
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
                "PCIe Completion Buffer Inserts of completions with data: Part 1",
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
                "PCIe Completion Buffer Inserts of completions with data: Part 2",
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
                "PCIe Completion Buffer Inserts of completions with data: Part 3",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS",
            .encoding =
                {
                    .code = 0xD5ULL,
                    .umask = 0xFULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "PCIe Completion Buffer occupancy of completions with data: Part 0-3",
            .full_desc =
                "PCIe Completion Buffer occupancy of completions with data: Part 0-3",
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
                "PCIe Completion Buffer occupancy of completions with data: Part 0",
            .full_desc =
                "PCIe Completion Buffer occupancy of completions with data: Part 0",
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
                "PCIe Completion Buffer occupancy of completions with data: Part 1",
            .full_desc =
                "PCIe Completion Buffer occupancy of completions with data: Part 1",
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
                "PCIe Completion Buffer occupancy of completions with data: Part 2",
            .full_desc =
                "PCIe Completion Buffer occupancy of completions with data: Part 2",
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
                "PCIe Completion Buffer occupancy of completions with data: Part 3",
            .full_desc =
                "PCIe Completion Buffer occupancy of completions with data: Part 3",
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
                "Read request for 4 bytes made by the CPU to IIO Part0",
            .full_desc =
                "Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part0. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Read request for 4 bytes made by the CPU to IIO Part1",
            .full_desc =
                "Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part1. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Read request for 4 bytes made by the CPU to IIO Part2",
            .full_desc =
                "Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part2. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Read request for 4 bytes made by the CPU to IIO Part3",
            .full_desc =
                "Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part3. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part0 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part1 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part2 by  a unit on the main die (generally a core) or by another IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part3 by  a unit on the main die (generally a core) or by another IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART0",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part0",
            .full_desc =
                "Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part0. Does not include requests made by the same IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART1",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part1",
            .full_desc =
                "Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part1. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART2",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part2",
            .full_desc =
                "Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part2. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART3",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part3",
            .full_desc =
                "Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part3. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART0",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made to IIO Part0 by a different IIO unit",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part0 by a different IIO unit. Does not include requests made by the same IIO unit.  In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART1",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made to IIO Part1 by a different IIO unit",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part1 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART2",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made to IIO Part2 by a different IIO unit",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part2 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART3",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made to IIO Part3 by a different IIO unit",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part3 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Counts every read request for 4 bytes of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Counts every read request for 4 bytes of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Counts every read request for 4 bytes of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Counts every read request for 4 bytes of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Counts every write request of 4 bytes of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART0",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by IIO Part0 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request for 4 bytes of data made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART1",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by IIO Part1 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request for 4 bytes of data made by IIO Part1 to the MMIO space of an IIO target. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART2",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by IIO Part2 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request for 4 bytes of data made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART3",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for 4 bytes made by IIO Part3 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request for 4 bytes of data made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART0",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART1",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made by IIO Part1 to the MMIO space of an IIO target. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART2",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART3",
            .encoding =
                {
                    .code = 0x83ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of 4 bytes of data made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part0. In the general case, part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part1. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part2. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part3. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part0 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part1 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part2 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part3 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART0",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part0",
            .full_desc =
                "Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part0. Does not include requests made by the same IIO unit. In the general case, part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART1",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part1",
            .full_desc =
                "Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part1. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART2",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part2",
            .full_desc =
                "Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part2. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART3",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part3",
            .full_desc =
                "Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part3. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART0",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made to IIO Part0 by a different IIO unit",
            .full_desc =
                "Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part0 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART1",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made to IIO Part1 by a different IIO unit",
            .full_desc = "Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part1 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART2",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made to IIO Part2 by a different IIO unit",
            .full_desc =
                "Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part2 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART3",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made to IIO Part3 by a different IIO unit",
            .full_desc =
                "Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part3 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Counts every read request for up to a 64 byte transaction of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
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
                "Counts every write request of up to a 64 byte transaction of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART0",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request of up to a 64 byte transaction is made by IIO Part0 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART1",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request of up to a 64 byte transaction is made by IIO Part1 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part1 to the MMIO space of an IIO target. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART2",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request of up to a 64 byte transaction is made by IIO Part2 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART3",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer read request of up to a 64 byte transaction is made by IIO Part3 to an IIO target",
            .full_desc =
                "Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART0",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made by IIO Part0 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART1",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made by IIO Part1 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part1 to the MMIO space of an IIO target.In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART2",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made by IIO Part2 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.",
        },
        {
            .pmu_type = PmuType::uncore_iio,
            .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART3",
            .encoding =
                {
                    .code = 0x84ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Peer to peer write request of up to a 64 byte transaction is made by IIO Part3 to an IIO target",
            .full_desc =
                "Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.",
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
                "Total IRP occupancy of inbound read and write requests.",
            .full_desc =
                "Total IRP occupancy of inbound read and write requests.  This is effectively the sum of read occupancy and write occupancy.",
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
            .id = "UNC_I_COHERENT_OPS.RFO",
            .encoding =
                {
                    .code = 0x10ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "RFO request issued by the IRP unit to the mesh with the intention of writing a partial cacheline.",
            .full_desc =
                "RFO request issued by the IRP unit to the mesh with the intention of writing a partial cacheline to coherent memory.  RFO is a Read For Ownership command that requests ownership of the cacheline and moves data from the mesh to IRP cache.",
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
            .id = "UNC_M2M_BYPASS_M2M_Egress.NOT_TAKEN",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Traffic in which the M2M to iMC Bypass was not taken",
            .full_desc =
                "Counts traffic in which the M2M (Mesh to Memory) to iMC (Memory Controller) bypass was not taken",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECT2CORE_NOT_TAKEN_DIRSTATE",
            .encoding =
                {
                    .code = 0x24ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when direct to core mode (which bypasses the CHA) was disabled",
            .full_desc =
                "Counts cycles when direct to core mode (which bypasses the CHA) was disabled",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECT2CORE_TAKEN",
            .encoding =
                {
                    .code = 0x23ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Messages sent direct to core (bypassing the CHA)",
            .full_desc =
                "Counts when messages were sent direct to core (bypassing the CHA)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECT2CORE_TXN_OVERRIDE",
            .encoding =
                {
                    .code = 0x25ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of reads in which direct to core transaction were overridden",
            .full_desc =
                "Counts reads in which direct to core transactions (which would have bypassed the CHA) were overridden",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECT2UPI_NOT_TAKEN_CREDITS",
            .encoding =
                {
                    .code = 0x28ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of reads in which direct to Intel(R) UPI transactions were overridden",
            .full_desc =
                "Counts reads in which direct to Intel(R) Ultra Path Interconnect (UPI) transactions (which would have bypassed the CHA) were overridden",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECT2UPI_NOT_TAKEN_DIRSTATE",
            .encoding =
                {
                    .code = 0x27ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles when direct to Intel(R) UPI was disabled",
            .full_desc =
                "Counts cycles when the ability to send messages direct to the Intel(R) Ultra Path Interconnect (bypassing the CHA) was disabled",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECT2UPI_TAKEN",
            .encoding =
                {
                    .code = 0x26ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Messages sent direct to the Intel(R) UPI",
            .full_desc =
                "Counts when messages were sent direct to the Intel(R) Ultra Path Interconnect (bypassing the CHA)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECT2UPI_TXN_OVERRIDE",
            .encoding =
                {
                    .code = 0x29ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of reads that a message sent direct2 Intel(R) UPI was overridden",
            .full_desc =
                "Counts when a read message that was sent direct to the Intel(R) Ultra Path Interconnect (bypassing the CHA) was overridden",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_LOOKUP.ANY",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multi-socket cacheline Directory lookups (any state found)",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state, and found the cacheline marked in Any State (A, I, S or unused)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_LOOKUP.STATE_A",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multi-socket cacheline Directory lookups (cacheline found in A state)",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state, and found the cacheline marked in the A (SnoopAll) state, indicating the cacheline is stored in another socket in any state, and we must snoop the other sockets to make sure we get the latest data.  The data may be stored in any state in the local socket.",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_LOOKUP.STATE_I",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multi-socket cacheline Directory lookup (cacheline found in I state)",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state , and found the cacheline marked in the I (Invalid) state indicating the cacheline is not stored in another socket, and so there is no need to snoop the other sockets for the latest data.  The data may be stored in any state in the local socket.",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_LOOKUP.STATE_S",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multi-socket cacheline Directory lookup (cacheline found in S state)",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state , and found the cacheline marked in the S (Shared) state indicating the cacheline is either stored in another socket in the S(hared) state , and so there is no need to snoop the other sockets for the latest data.  The data may be stored in any state in the local socket.",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_UPDATE.A2I",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Multi-socket cacheline Directory update from A to I",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from A (SnoopAll) to I (Invalid)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_UPDATE.A2S",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Multi-socket cacheline Directory update from A to S",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from A (SnoopAll) to S (Shared)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_UPDATE.ANY",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multi-socket cacheline Directory update from/to Any state",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory to a new state",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_UPDATE.I2A",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Multi-socket cacheline Directory update from I to A",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from I (Invalid) to A (SnoopAll)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_UPDATE.I2S",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Multi-socket cacheline Directory update from I to S",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from I (Invalid) to S (Shared)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_UPDATE.S2A",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Multi-socket cacheline Directory update from S to A",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from S (Shared) to A (SnoopAll)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_DIRECTORY_UPDATE.S2I",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Multi-socket cacheline Directory update from S to I",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from S (Shared) to I (Invalid)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_IMC_READS.ALL",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Reads to iMC issued",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) issues reads to the iMC (Memory Controller).",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_IMC_READS.NORMAL",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Reads to iMC issued at Normal Priority (Non-Isochronous)",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) issues reads to the iMC (Memory Controller).  It only counts  normal priority non-isochronous reads.",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_IMC_WRITES.ALL",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Writes to iMC issued",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) issues writes to the iMC (Memory Controller).",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_IMC_WRITES.NI",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x80ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "M2M Writes Issued to iMC; All, regardless of priority.",
            .full_desc =
                "M2M Writes Issued to iMC; All, regardless of priority.",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_IMC_WRITES.PARTIAL",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Partial Non-Isochronous writes to the iMC",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) issues partial writes to the iMC (Memory Controller).  It only counts normal priority non-isochronous writes.",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_PREFCAM_DEMAND_PROMOTIONS",
            .encoding =
                {
                    .code = 0x56ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Prefetch requests that got turn into a demand request",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) promotes a outstanding request in the prefetch queue due to a subsequent demand read request that entered the M2M with the same address.  Explanatory Side Note: The Prefetch queue is made of CAM (Content Addressable Memory)",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_PREFCAM_INSERTS",
            .encoding =
                {
                    .code = 0x57ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Inserts into the Memory Controller Prefetch Queue",
            .full_desc =
                "Counts when the M2M (Mesh to Memory) receives a prefetch request and inserts it into its outstanding prefetch queue.  Explanatory Side Note: the prefect queue is made from CAM: Content Addressable Memory",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_RxC_AD_INSERTS",
            .encoding =
                {
                    .code = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ingress (from CMS) Queue Inserts",
            .full_desc =
                "Counts when the a new entry is Received(RxC) and then added to the AD (Address Ring) Ingress Queue from the CMS (Common Mesh Stop).  This is generally used for reads, and",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_RxC_AD_OCCUPANCY",
            .encoding =
                {
                    .code = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ingress (from CMS) Occupancy",
            .full_desc = "AD Ingress (from CMS) Occupancy",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_RxC_BL_INSERTS",
            .encoding =
                {
                    .code = 0x5ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ingress (from CMS) Allocations",
            .full_desc = "BL Ingress (from CMS) Allocations",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_RxC_BL_OCCUPANCY",
            .encoding =
                {
                    .code = 0x6ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ingress (from CMS) Occupancy",
            .full_desc = "BL Ingress (from CMS) Occupancy",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_TxC_AD_INSERTS",
            .encoding =
                {
                    .code = 0x9ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Egress (to CMS) Allocations",
            .full_desc = "AD Egress (to CMS) Allocations",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_TxC_AD_OCCUPANCY",
            .encoding =
                {
                    .code = 0xAULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Egress (to CMS) Occupancy",
            .full_desc = "AD Egress (to CMS) Occupancy",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_TxC_BL_INSERTS.ALL",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Egress (to CMS) Allocations; All",
            .full_desc = "BL Egress (to CMS) Allocations; All",
        },
        {
            .pmu_type = PmuType::uncore_m2m,
            .id = "UNC_M2M_TxC_BL_OCCUPANCY.ALL",
            .encoding =
                {
                    .code = 0x16ULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Egress (to CMS) Occupancy; All",
            .full_desc = "BL Egress (to CMS) Occupancy; All",
        },
        {
            .pmu_type = PmuType::uncore_m3upi,
            .id = "UNC_M3UPI_UPI_PREFETCH_SPAWN",
            .encoding =
                {
                    .code = 0x29ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Prefetches generated by the flow control queue of the M3UPI unit.",
            .full_desc =
                "Count cases where flow control queue that sits between the Intel(R) Ultra Path Interconnect (UPI) and the mesh spawns a prefetch to the iMC (Memory Controller)",
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
                "Clocks of the Intel(R) Ultra Path Interconnect (UPI)",
            .full_desc =
                "Counts clockticks of the fixed frequency clock controlling the Intel(R) Ultra Path Interconnect (UPI).  This clock runs at1/8th the 'GT/s' speed of the UPI link.  For example, a  9.6GT/s  link will have a fixed Frequency of 1.2 Ghz.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_DIRECT_ATTEMPTS.D2C",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Data Response packets that go direct to core",
            .full_desc =
                "Counts Data Response (DRS) packets that attempted to go direct to core bypassing the CHA.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_DIRECT_ATTEMPTS.D2U",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Data Response packets that go direct to Intel(R) UPI",
            .full_desc =
                "Counts Data Response (DRS) packets that attempted to go direct to Intel(R) Ultra Path Interconnect (UPI) bypassing the CHA .",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_L1_POWER_CYCLES",
            .encoding =
                {
                    .code = 0x21ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles Intel(R) UPI is in L1 power mode (shutdown)",
            .full_desc =
                "Counts cycles when the Intel(R) Ultra Path Interconnect (UPI) is in L1 power mode.  L1 is a mode that totally shuts down the UPI link.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another, this event only coutns when both links are shutdown.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_RxL0P_POWER_CYCLES",
            .encoding =
                {
                    .code = 0x25ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles the Rx of the Intel(R) UPI is in L0p power mode",
            .full_desc =
                "Counts cycles when the receive side (Rx) of the Intel(R) Ultra Path Interconnect(UPI) is in L0p power mode. L0p is a mode where we disable 60% of the UPI lanes, decreasing our bandwidth in order to save power.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_RxL_BYPASSED.SLOT0",
            .encoding =
                {
                    .code = 0x31ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FLITs received which bypassed the Slot0 Receive Buffer",
            .full_desc =
                "Counts incoming FLITs (FLow control unITs) which bypassed the slot0 RxQ buffer (Receive Queue) and passed directly to the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of FLITs transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_RxL_BYPASSED.SLOT1",
            .encoding =
                {
                    .code = 0x31ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FLITs received which bypassed the Slot0 Receive Buffer",
            .full_desc =
                "Counts incoming FLITs (FLow control unITs) which bypassed the slot1 RxQ buffer  (Receive Queue) and passed directly across the BGF and into the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of FLITs transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_RxL_BYPASSED.SLOT2",
            .encoding =
                {
                    .code = 0x31ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FLITs received which bypassed the Slot0 Receive Buffer",
            .full_desc =
                "Counts incoming FLITs (FLow control unITs) which bypassed the slot2 RxQ buffer (Receive Queue)  and passed directly to the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of FLITs transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.",
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
            .brief_desc = "Valid data FLITs received from any slot",
            .full_desc =
                "Counts valid data FLITs  (80 bit FLow control unITs: 64bits of data) received from any of the 3 Intel(R) Ultra Path Interconnect (UPI) Receive Queue slots on this UPI unit.",
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
            .full_desc =
                "Counts null FLITs (80 bit FLow control unITs) received from any of the 3 Intel(R) Ultra Path Interconnect (UPI) Receive Queue slots on this UPI unit.",
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
                "Protocol header and credit FLITs received from any slot",
            .full_desc =
                "Counts protocol header and credit FLITs  (80 bit FLow control unITs) received from any of the 3 UPI slots on this UPI unit.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_TxL0P_POWER_CYCLES",
            .encoding =
                {
                    .code = 0x27ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles in which the Tx of the Intel(R) Ultra Path Interconnect (UPI) is in L0p power mode",
            .full_desc =
                "Counts cycles when the transmit side (Tx) of the Intel(R) Ultra Path Interconnect(UPI) is in L0p power mode. L0p is a mode where we disable 60% of the UPI lanes, decreasing our bandwidth in order to save power.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_TxL_BYPASSED",
            .encoding =
                {
                    .code = 0x41ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FLITs that bypassed the TxL Buffer",
            .full_desc =
                "Counts incoming FLITs (FLow control unITs) which bypassed the TxL(transmit) FLIT buffer and pass directly out the UPI Link. Generally, when data is transmitted across the Intel(R) Ultra Path Interconnect (UPI), it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used in L0p (Low Power) mode and (Link Layer Retry) LLR  mode, increasing latency to transfer out to the link.",
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
            .brief_desc = "Valid data FLITs transmitted via any slot",
            .full_desc =
                "Counts valid data FLITs (80 bit FLow control unITs: 64bits of data) transmitted (TxL) via any of the 3 Intel(R) Ultra Path Interconnect (UPI) slots on this UPI unit.",
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
            .brief_desc = "Null FLITs transmitted from any slot",
            .full_desc =
                "Counts null FLITs (80 bit FLow control unITs) transmitted via any of the 3 Intel(R) Ulra Path Interconnect (UPI) slots on this UPI unit.",
        },
        {
            .pmu_type = PmuType::uncore_upi,
            .id = "UNC_UPI_TxL_FLITS.DATA",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Valid Flits Sent; Data",
            .full_desc =
                "Shows legal flit time (hides impact of L0p and L0c).; Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..",
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
            .brief_desc = "Idle FLITs transmitted",
            .full_desc =
                "Counts when the Intel Ultra Path Interconnect(UPI) transmits an idle FLIT(80 bit FLow control unITs).  Every UPI cycle must be sending either data FLITs, protocol/credit FLITs or idle FLITs.",
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
                "Protocol header and credit FLITs transmitted across any slot",
            .full_desc =
                "Counts protocol header and credit FLITs (80 bit FLow control unITs) transmitted across any of the 3 UPI (Ultra Path Interconnect) slots on this UPI unit.",
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

} // namespace skylakex_uncore
} // namespace facebook::hbt::perf_event::generated
