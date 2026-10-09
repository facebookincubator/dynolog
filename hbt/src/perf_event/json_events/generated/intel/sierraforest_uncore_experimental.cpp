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
namespace sierraforest_uncore_experimental {
namespace {

/*
  Events from sierraforest_uncore_experimental.json (405 experimental events).

  Supported SKUs:
      - Arch: x86, Model: SRF id: 175
*/
constexpr std::array<StaticEventDef, 0> kAllowlistedEvents{};

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::
    array<StaticEventDef, 350>
        kFullOnlyEvents{
            {
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
                        "Counts transactions that looked into the multi-socket cacheline Directory state, and therefore did not send a snoop because the Directory indicated it was not needed.",
                    .full_desc =
                        "Counts transactions that looked into the multi-socket cacheline Directory state, and therefore did not send a snoop because the Directory indicated it was not needed.",
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
                        "Counts  transactions that looked into the multi-socket cacheline Directory state, and sent one or more snoops, because the Directory indicated it was needed.",
                    .full_desc =
                        "Counts  transactions that looked into the multi-socket cacheline Directory state, and sent one or more snoops, because the Directory indicated it was needed.",
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
                        "Counts only multi-socket cacheline Directory state updates memory writes issued from the HA pipe. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.",
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
                        "Counts only multi-socket cacheline Directory state updates due to memory writes issued from the TOR pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.",
                    .full_desc =
                        "Counts only multi-socket cacheline Directory state updates due to memory writes issued from the TOR pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.",
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
                        "Counts when a normal (Non-Isochronous) full line write is issued from the CHA to the any of the memory controller channels.",
                    .full_desc =
                        "Counts when a normal (Non-Isochronous) full line write is issued from the CHA to the any of the memory controller channels.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_IMC_WRITES_COUNT.FULL_PRIORITY",
                    .encoding =
                        {
                            .code = 0x5BULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CHA to iMC Full Line Writes Issued : ISOCH Full Line : Counts the total number of full line writes issued from the HA into the memory controller.",
                    .full_desc =
                        "CHA to iMC Full Line Writes Issued : ISOCH Full Line",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_IMC_WRITES_COUNT.PARTIAL",
                    .encoding =
                        {
                            .code = 0x5BULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CHA to iMC Full Line Writes Issued : Partial Non-ISOCH : Counts the total number of full line writes issued from the HA into the memory controller.",
                    .full_desc =
                        "CHA to iMC Full Line Writes Issued : Partial Non-ISOCH",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_IMC_WRITES_COUNT.PARTIAL_PRIORITY",
                    .encoding =
                        {
                            .code = 0x5BULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CHA to iMC Full Line Writes Issued : ISOCH Partial : Counts the total number of full line writes issued from the HA into the memory controller.",
                    .full_desc =
                        "CHA to iMC Full Line Writes Issued : ISOCH Partial",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.ALL_REMOTE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x17E0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: All Requests to Remotely Homed Memory",
                    .full_desc =
                        "Cache Lookups : All transactions from Remote Agents",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.CODE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1BD0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups: CRd Requests",
                    .full_desc = "Cache Lookups : CRd Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.DATA_RD",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1BC1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Read Requests and Read Prefetches",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.DATA_READ_ALL",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1FC1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Read Requests, Read Prefetches, and Snoops",
                    .full_desc = "Cache Lookups : Data Reads",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.DATA_READ_LOCAL",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x841ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Read Requests to Locally Homed Memory",
                    .full_desc =
                        "Cache Lookups : Demand Data Reads, Core and LLC prefetches",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.DATA_READ_MISS",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x1FC1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Read Requests, Read Prefetches, and Snoops which miss the Cache",
                    .full_desc = "Cache Lookups : Data Read Misses",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCALLY_HOMED_ADDRESS",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0xBDFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: All Requests to Locally Homed Memory",
                    .full_desc = "Cache Lookups : Transactions homed locally",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_CODE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x19D0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Code Read Requests and Code Read Prefetches to Locally Homed Memory",
                    .full_desc = "Cache Lookups : CRd Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_DATA_RD",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x19C1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Read Requests and Read Prefetches to Locally Homed Memory",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_DMND_CODE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1850ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Code Read Requests to Locally Homed Memory",
                    .full_desc = "Cache Lookups : CRd Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_DMND_DATA_RD",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1841ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Read Requests to Locally Homed Memory",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_DMND_RFO",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1848ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: RFO Requests to Locally Homed Memory",
                    .full_desc = "Cache Lookups : RFO Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_LLC_PF",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x189DULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: LLC Prefetch Requests to Locally Homed Memory",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_PF",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x199DULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: All Prefetches to Locally Homed Memory",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_PF_CODE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1910ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Code Prefetches to Locally Homed Memory",
                    .full_desc = "Cache Lookups : CRd Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_PF_DATA_RD",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1981ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Read Prefetches to Locally Homed Memory",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_PF_RFO",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1908ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: RFO Prefetches to Locally Homed Memory",
                    .full_desc = "Cache Lookups : RFO Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.LOCAL_RFO",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x19C8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: RFO Requests and RFO Prefetches to Locally Homed Memory",
                    .full_desc = "Cache Lookups : RFO Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.REMOTELY_HOMED_ADDRESS",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x15DFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: All Requests to Remotely Homed Memory",
                    .full_desc =
                        "Cache Lookups : Transactions homed remotely : Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing. : Transaction whose address resides in a remote MC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.REMOTE_CODE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1A10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Code Read/Prefetch Requests from a Remote Socket",
                    .full_desc = "Cache Lookups : CRd Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.REMOTE_DATA_RD",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1A01ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Data Read/Prefetch Requests from a Remote Socket",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.REMOTE_RFO",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1A08ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: RFO Requests/Prefetches from a Remote Socket",
                    .full_desc = "Cache Lookups : RFO Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.REMOTE_SNP",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1C19ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Snoop Requests from a Remote Socket",
                    .full_desc =
                        "Counts the number of times the LLC was accessed",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.RFO",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x1BC8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups: All RFO and RFO Prefetches",
                    .full_desc =
                        "Cache Lookups : All RFOs - Demand and Prefetches",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.RFO_LOCAL",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x9C8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: RFO Requests and RFO Prefetches to Locally Homed Memory",
                    .full_desc =
                        "Cache Lookups : Locally HOMed RFOs - Demand and Prefetches",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.WRITE_LOCAL",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x842ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Writes to Locally Homed Memory (includes writebacks from L1/L2)",
                    .full_desc = "Cache Lookups : Writes",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_LOOKUP.WRITE_REMOTE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x17C2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cache Lookups: Writes to Remotely Homed Memory (includes writebacks from L1/L2)",
                    .full_desc = "Cache Lookups : Remote Writes",
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
                    .brief_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : All Lines Victimized",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.IA",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : IA traffic : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : IA traffic",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.IO",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : IO traffic : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : IO traffic",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.LOCAL_ALL",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0xFULL,
                            .umask_ext = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Local - All Lines",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.LOCAL_E",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Local - Lines in E State",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.LOCAL_F",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Local - Lines in F State",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.LOCAL_M",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Local - Lines in M State",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.LOCAL_S",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Local - Lines in S State",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.REMOTE_ALL",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0xFULL,
                            .umask_ext = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Remote - All Lines",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.REMOTE_E",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Remote - Lines in E State",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.REMOTE_M",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Remote - Lines in M State",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_LLC_VICTIMS.REMOTE_S",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Remote - Lines in S State",
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
                    .brief_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Lines in E state",
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
                    .brief_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Lines in M state",
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
                    .brief_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                    .full_desc = "Lines Victimized : Lines in S State",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_OSB.LOCAL_INVITOE",
                    .encoding =
                        {
                            .code = 0x55ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "OSB Snoop Broadcast : Local InvItoE : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                    .full_desc = "OSB Snoop Broadcast : Local InvItoE",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_OSB.LOCAL_READ",
                    .encoding =
                        {
                            .code = 0x55ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "OSB Snoop Broadcast : Local Rd : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                    .full_desc = "OSB Snoop Broadcast : Local Rd",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_OSB.OFF_PWRHEURISTIC",
                    .encoding =
                        {
                            .code = 0x55ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "OSB Snoop Broadcast : Off : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                    .full_desc = "OSB Snoop Broadcast : Off",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_OSB.REMOTE_READ",
                    .encoding =
                        {
                            .code = 0x55ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "OSB Snoop Broadcast : Remote Rd : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                    .full_desc = "OSB Snoop Broadcast : Remote Rd",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.ALLOC_EXCLUSIVE",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.ALLOC_EXCLUSIVE",
                    .full_desc = "UNC_CHA_REMOTE_SF.ALLOC_EXCLUSIVE",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.ALLOC_SHARED",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.ALLOC_SHARED",
                    .full_desc = "UNC_CHA_REMOTE_SF.ALLOC_SHARED",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.DEALLOC_EVCTCLN",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.DEALLOC_EVCTCLN",
                    .full_desc = "UNC_CHA_REMOTE_SF.DEALLOC_EVCTCLN",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.DIRBACKED_ONLY",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask_ext = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.DIRBACKED_ONLY",
                    .full_desc = "UNC_CHA_REMOTE_SF.DIRBACKED_ONLY",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.HIT_EXCLUSIVE",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.HIT_EXCLUSIVE",
                    .full_desc = "UNC_CHA_REMOTE_SF.HIT_EXCLUSIVE",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.HIT_SHARED",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.HIT_SHARED",
                    .full_desc = "UNC_CHA_REMOTE_SF.HIT_SHARED",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.INCLUSIVE_ONLY",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask_ext = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.INCLUSIVE_ONLY",
                    .full_desc = "UNC_CHA_REMOTE_SF.INCLUSIVE_ONLY",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.UPDATE_EXCLUSIVE",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.UPDATE_EXCLUSIVE",
                    .full_desc = "UNC_CHA_REMOTE_SF.UPDATE_EXCLUSIVE",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.UPDATE_SHARED",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.UPDATE_SHARED",
                    .full_desc = "UNC_CHA_REMOTE_SF.UPDATE_SHARED",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.VICTIM_EXCLUSIVE",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask_ext = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.VICTIM_EXCLUSIVE",
                    .full_desc = "UNC_CHA_REMOTE_SF.VICTIM_EXCLUSIVE",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_REMOTE_SF.VICTIM_SHARED",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask_ext = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_CHA_REMOTE_SF.VICTIM_SHARED",
                    .full_desc = "UNC_CHA_REMOTE_SF.VICTIM_SHARED",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.ALL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All TOR Inserts",
                    .full_desc = "TOR Inserts : All",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_CLFLUSH",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8C7FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CLFlush transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "CLFlush transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_FSRDCUR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8EFFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "FsRdCur transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "FsRdCur transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_FSRDCURPTL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C9EFFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "FsRdCurPtl transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "FsRdCurPtl transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_ITOM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC47FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "ItoM transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "ItoM transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_ITOMWR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC4FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "ItoMWr transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "ItoMWr transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_MEMPUSHWR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC6FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "MemPushWr transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "MemPushWr transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_WCIL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C86FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCiL transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "WCiL transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_WCILF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C867FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WcilF transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "WcilF transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_HIT_WIL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C87FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WiL transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "WiL transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_CLFLUSH",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8C7FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CLFlush transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "CLFlush transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_FSRDCUR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8EFFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "FsRdCur transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "FsRdCur transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_FSRDCURPTL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C9EFFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "FsRdCurPtl transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "FsRdCurPtl transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_ITOM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC47FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "ItoM transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "ItoM transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_ITOMWR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC4FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "ItoMWr transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "ItoMWr transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_MEMPUSHWR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC6FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "MemPushWr transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "MemPushWr transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_WCIL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C86FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCiL transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "WCiL transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_WCILF",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C867FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WcilF transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "WcilF transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.CXL_MISS_WIL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C87FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WiL transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "WiL transactions from a CXL device which miss the L3.",
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
                    .brief_desc =
                        "All locally initiated requests from IA Cores",
                    .full_desc = "TOR Inserts : All requests from iA Cores",
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
                        "All locally initiated requests from IA Cores which hit the cache",
                    .full_desc =
                        "TOR Inserts : All requests from iA Cores that Hit the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCILF_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8668AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCILF requests from local IA cores to locally homed PMM addresses which miss the cache",
                    .full_desc =
                        "TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed locally",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCIL_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86E8AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCIL requests from local IA cores to locally homed PMM addresses which miss the cache",
                    .full_desc =
                        "TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed locally",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCILF_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8670AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCILF requests from local IA cores to remotely homed PMM addresses which miss the cache",
                    .full_desc =
                        "TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCIL_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86F0AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCIL requests from local IA cores to remotely homed PMM addresses which miss the cache",
                    .full_desc =
                        "TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8678AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCILF requests from local IA cores to PMM homed addresses which miss the cache",
                    .full_desc =
                        "TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL_PMM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86F8AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WCIL requests from a local IA core to PMM homed addresses that miss the cache",
                    .full_desc =
                        "TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC",
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
                    .brief_desc = "All TOR inserts from local IO devices",
                    .full_desc = "TOR Inserts : All requests from IO Devices",
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
                        "All TOR inserts from local IO devices which hit the cache",
                    .full_desc =
                        "TOR Inserts : All requests from IO Devices that hit the LLC",
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
                        "All TOR inserts from local IO devices which miss the cache",
                    .full_desc =
                        "TOR Inserts : All requests from IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.LOC_ALL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x5ULL,
                            .umask_ext = 0xC000FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All locally initiated requests",
                    .full_desc = "TOR Inserts : All from Local iA and IO",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.LOC_IA",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC000FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All from Local iA",
                    .full_desc = "TOR Inserts : All from Local iA",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.LOC_IO",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC000FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All from Local IO",
                    .full_desc = "TOR Inserts : All from Local IO",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.REM_ALL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0xC8ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "All remote requests (e.g. snoops, writebacks) that came from remote sockets",
                    .full_desc = "TOR Inserts : All Remote Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_INSERTS.REM_SNPS",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "All snoops to this LLC that came from remote sockets",
                    .full_desc = "TOR Inserts : All Snoops from Remote",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Occupancy for all TOR entries",
                    .full_desc = "TOR Occupancy : All",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_CLFLUSH",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8C7FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for CLFlush transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for CLFlush transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_FSRDCUR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8EFFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for FsRdCur transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for FsRdCur transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_FSRDCURPTL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C9EFFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for FsRdCurPtl transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for FsRdCurPtl transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_ITOM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC47FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoM transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for ItoM transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_ITOMWR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC4FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoMWr transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for ItoMWr transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_MEMPUSHWR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC6FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for MemPushWr transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for MemPushWr transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_WCIL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C86FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCiL transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for WCiL transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_WCILF",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C867FDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WcilF transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for WcilF transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_WIL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C87FFDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WiL transactions from a CXL device which hit in the L3.",
                    .full_desc =
                        "TOR Occupancy for WiL transactions from a CXL device which hit in the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_CLFLUSH",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8C7FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for CLFlush transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for CLFlush transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_FSRDCUR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C8EFFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for FsRdCur transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for FsRdCur transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_FSRDCURPTL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C9EFFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for FsRdCurPtl transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for FsRdCurPtl transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_ITOM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC47FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoM transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for ItoM transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_ITOMWR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC4FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoMWr transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for ItoMWr transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_MEMPUSHWR",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78CC6FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for MemPushWr transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for MemPushWr transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_WCIL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C86FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCiL transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for WCiL transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_WCILF",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C867FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WcilF transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for WcilF transactions from a CXL device which miss the L3.",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_WIL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x78C87FFEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WiL transactions from a CXL device which miss the L3.",
                    .full_desc =
                        "TOR Occupancy for WiL transactions from a CXL device which miss the L3.",
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
                    .brief_desc =
                        "TOR Occupancy for All locally initiated requests from IA Cores",
                    .full_desc = "TOR Occupancy : All requests from iA Cores",
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
                    .brief_desc =
                        "TOR Occupancy for Data read opt from local IA that miss the cache",
                    .full_desc = "TOR Occupancy : DRd_Opts issued by iA Cores",
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
                        "TOR Occupancy for Data read opt prefetch from local IA that miss the cache",
                    .full_desc =
                        "TOR Occupancy : DRd_Opt_Prefs issued by iA Cores",
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
                        "TOR Occupancy for All locally initiated requests from IA Cores which hit the cache",
                    .full_desc =
                        "TOR Occupancy : All requests from iA Cores that Hit the LLC",
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
                        "TOR Occupancy for All locally initiated requests from IA Cores which miss the cache",
                    .full_desc =
                        "TOR Occupancy : All requests from iA Cores that Missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCILF_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8668AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCILF requests from local IA cores to locally homed PMM addresses which miss the cache",
                    .full_desc =
                        "TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed locally",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCIL_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86E8AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCIL requests from local IA cores to locally homed PMM addresses which miss the cache",
                    .full_desc =
                        "TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed locally",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCILF_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8670AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCILF requests from local IA cores to remotely homed PMM addresses which miss the cache",
                    .full_desc =
                        "TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCIL_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86F0AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCIL requests from local IA cores to remotely homed PMM addresses which miss the cache",
                    .full_desc = "TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC8678AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCILF requests from local IA cores to PMM homed addresses which miss the cache",
                    .full_desc =
                        "TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL_PMM",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC86F8AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for WCIL requests from a local IA core to PMM homed addresses that miss the cache",
                    .full_desc =
                        "TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC",
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
                        "TOR Occupancy for All TOR inserts from local IO devices",
                    .full_desc = "TOR Occupancy : All requests from IO Devices",
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
                        "TOR Occupancy for All TOR inserts from local IO devices which hit the cache",
                    .full_desc =
                        "TOR Occupancy : All requests from IO Devices that hit the LLC",
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
                        "TOR Occupancy for All TOR inserts from local IO devices which miss the cache",
                    .full_desc =
                        "TOR Occupancy : All requests from IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOMCACHENEAR_LOCAL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCD42FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoMCacheNear transactions from an IO device on the local socket that miss the cache",
                    .full_desc =
                        "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOMCACHENEAR_REMOTE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCD437EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoMCacheNear transactions from an IO device on a remote socket that miss the cache",
                    .full_desc =
                        "TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM_LOCAL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCC42FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoM transactions from an IO device on the local socket that miss the cache",
                    .full_desc =
                        "TOR Occupancy : ItoMs issued by IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM_REMOTE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xCC437EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for ItoM transactions from an IO device on a remote socket that miss the cache",
                    .full_desc =
                        "TOR Occupancy : ItoMs issued by IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_PCIRDCUR_LOCAL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC8F2FEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for PCIRDCUR transactions from an IO device on the local socket that miss the cache",
                    .full_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.IO_MISS_PCIRDCUR_REMOTE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC8F37EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for PCIRDCUR transactions from an IO device on a remote socket that miss the cache",
                    .full_desc =
                        "TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.LOC_ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x5ULL,
                            .umask_ext = 0xC000FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for All locally initiated requests",
                    .full_desc = "TOR Occupancy : All from Local iA and IO",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.LOC_IA",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0xC000FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy for All from Local iA",
                    .full_desc = "TOR Occupancy : All from Local iA",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.LOC_IO",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0xC000FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy for All from Local IO",
                    .full_desc = "TOR Occupancy : All from Local IO",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.REM_ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0xC8ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for All remote requests (e.g. snoops, writebacks) that came from remote sockets",
                    .full_desc = "TOR Occupancy : All Remote Requests",
                },
                {
                    .pmu_type = PmuType::uncore_cha,
                    .id = "UNC_CHA_TOR_OCCUPANCY.REM_SNPS",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0xC001FFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy for All snoops to this LLC that came from remote sockets",
                    .full_desc = "TOR Occupancy : All Snoops from Remote",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ACT_COUNT.RD",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0xF1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Activate Count : Read transaction on Page Empty or Page Miss : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                    .full_desc =
                        "DRAM Activate Count : Read transaction on Page Empty or Page Miss",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ACT_COUNT.UFILL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0xF4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Activate Count : Underfill Read transaction on Page Empty or Page Miss : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                    .full_desc =
                        "DRAM Activate Count : Underfill Read transaction on Page Empty or Page Miss",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ACT_COUNT.WR",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0xF2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Activate Count : Write transaction on Page Empty or Page Miss : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                    .full_desc =
                        "DRAM Activate Count : Write transaction on Page Empty or Page Miss",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT_SCH0.WR_NONPRE",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xD0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CAS count for SubChannel 0 regular writes",
                    .full_desc = "CAS count for SubChannel 0 regular writes",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT_SCH0.WR_PRE",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xE0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CAS count for SubChannel 0 auto-precharge writes",
                    .full_desc =
                        "CAS count for SubChannel 0 auto-precharge writes",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT_SCH1.WR_NONPRE",
                    .encoding =
                        {
                            .code = 0x6ULL,
                            .umask = 0xD0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CAS count for SubChannel 1 regular writes",
                    .full_desc = "CAS count for SubChannel 1 regular writes",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT_SCH1.WR_PRE",
                    .encoding =
                        {
                            .code = 0x6ULL,
                            .umask = 0xE0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "CAS count for SubChannel 1 auto-precharge writes",
                    .full_desc =
                        "CAS count for SubChannel 1 auto-precharge writes",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_HCLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number of DRAM HCLK clock cycles while the event is enabled",
                    .full_desc = "DRAM Clockticks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH0_RANK0",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH0_RANK1",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH0_RANK2",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH0_RANK3",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH1_RANK0",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH1_RANK1",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH1_RANK2",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWERDOWN_CYCLES.SCH1_RANK3",
                    .encoding =
                        {
                            .code = 0x47ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CHANNEL_PPD_CYCLES",
                    .encoding =
                        {
                            .code = 0x88ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "# of cycles a given rank is in Power Down Mode and all pages are closed",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.RD",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0xF1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                    .full_desc = "DRAM Precharge commands.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.UFILL",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0xF4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                    .full_desc = "DRAM Precharge commands.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.WR",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0xF2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.",
                    .full_desc = "DRAM Precharge commands.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RDB_INSERTS.SCH0",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read buffer inserts on subchannel 0",
                    .full_desc = "Read buffer inserts on subchannel 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RDB_INSERTS.SCH1",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read buffer inserts on subchannel 1",
                    .full_desc = "Read buffer inserts on subchannel 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RPQ_INSERTS.PCH0",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x50ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.",
                    .full_desc = "Read Pending Queue Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RPQ_INSERTS.PCH1",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0xA0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.",
                    .full_desc = "Read Pending Queue Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_SELF_REFRESH.ENTER_SUCCESS",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "subevent0 - # of cycles all ranks were in SR subevent1 - # of times all ranks went into SR subevent2 -# of times  ps_sr_active asserted (SRE) subevent3 - # of times ps_sr_active deasserted (SRX) subevent4 - # of times PS-&>Refresh ps_sr_req asserted (SRE) subevent5 - # of times PS-&>Refresh ps_sr_req deasserted (SRX) subevent6 - # of cycles PSCtrlr FSM was in FATAL",
                    .full_desc = "UNC_M_SELF_REFRESH.ENTER_SUCCESS",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_SELF_REFRESH.ENTER_SUCCESS_CYCLES",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "# of cycles all ranks were in SR",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_INSERTS.PCH0",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x50ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Allocations",
                    .full_desc = "Write Pending Queue Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_INSERTS.PCH1",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0xA0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Allocations",
                    .full_desc = "Write Pending Queue Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART0",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70010ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART1",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70020ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART2",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70040ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART3",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70080ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART4",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70100ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART5",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70200ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART6",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70400ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART7",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70800ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                    .full_desc =
                        "PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0xFFULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART0",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x70010ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART1",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70020ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART2",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70040ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART3",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70080ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART4",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x10ULL,
                            .umask_ext = 0x70100ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART5",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x70200ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART6",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x40ULL,
                            .umask_ext = 0x70400ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART7",
                    .encoding =
                        {
                            .code = 0xD5ULL,
                            .umask = 0x80ULL,
                            .umask_ext = 0x70800ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Count of allocations in the completion buffer",
                    .full_desc =
                        "Count of allocations in the completion buffer",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
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
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                    .full_desc =
                        "Data requested by the CPU : Core reporting completion of Card read from Core DRAM",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested by the CPU : Core writing to Cards MMIO space",
                    .full_desc =
                        "Data requested by the CPU : Core writing to Cards MMIO space",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART0",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70010ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART1",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70020ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART2",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70040ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART3",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70080ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART4",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70100ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART5",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70200ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART6",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70400ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART7",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70800ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.ALL_PARTS",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts once for every 4 bytes written from this card to a peer device's IO space.",
                    .full_desc =
                        "Counts once for every 4 bytes written from this card to a peer device's IO space.",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART0",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70010ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART1",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70020ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART2",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70040ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART3",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70080ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART4",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70100ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART5",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70200ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART6",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70400ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART7",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70800ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Data requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.1G_HITS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOTLB Hits to a 1G Page",
                    .full_desc = "IOTLB Hits to a 1G Page",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.2M_HITS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOTLB Hits to a 2M Page",
                    .full_desc = "IOTLB Hits to a 2M Page",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.4K_HITS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOTLB Hits to a 4K Page",
                    .full_desc = "IOTLB Hits to a 4K Page",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.ALL_LOOKUPS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOTLB lookups all",
                    .full_desc = "IOTLB lookups all",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.CTXT_CACHE_HITS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Context cache hits",
                    .full_desc = "Context cache hits",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.CTXT_CACHE_LOOKUPS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Context cache lookups",
                    .full_desc = "Context cache lookups",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.FIRST_LOOKUPS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOTLB lookups first",
                    .full_desc = "IOTLB lookups first",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU0.MISSES",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOTLB Fills (same as IOTLB miss)",
                    .full_desc = "IOTLB Fills (same as IOTLB miss)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.NUM_MEM_ACCESSES",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0xC0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "IOMMU memory access (both low and high priority)",
                    .full_desc =
                        "IOMMU memory access (both low and high priority)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.NUM_MEM_ACCESSES_HIGH",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOMMU high priority memory access",
                    .full_desc = "IOMMU high priority memory access",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.NUM_MEM_ACCESSES_LOW",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOMMU low priority memory access",
                    .full_desc = "IOMMU low priority memory access",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.SLPWC_1G_HITS",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Second Level Page Walk Cache Hit to a 1G page",
                    .full_desc =
                        "Second Level Page Walk Cache Hit to a 1G page",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.SLPWC_256T_HITS",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Second Level Page Walk Cache Hit to a 256T page",
                    .full_desc =
                        "Second Level Page Walk Cache Hit to a 256T page",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.SLPWC_2M_HITS",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Second Level Page Walk Cache Hit to a 2M page",
                    .full_desc =
                        "Second Level Page Walk Cache Hit to a 2M page",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.SLPWC_512G_HITS",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Second Level Page Walk Cache Hit to a 512G page",
                    .full_desc =
                        "Second Level Page Walk Cache Hit to a 512G page",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.SLPWC_CACHE_FILLS",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Second Level Page Walk Cache fill",
                    .full_desc = "Second Level Page Walk Cache fill",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU1.SLPWC_CACHE_LOOKUPS",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Second Level Page Walk Cache lookup",
                    .full_desc = "Second Level Page Walk Cache lookup",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU3.CYC_PWT_FULL",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles PWT full",
                    .full_desc = "Cycles PWT full",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU3.INT_CACHE_HITS",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Interrupt Entry cache hit",
                    .full_desc = "Interrupt Entry cache hit",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU3.INT_CACHE_LOOKUPS",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Interrupt Entry cache lookup",
                    .full_desc = "Interrupt Entry cache lookup",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU3.NUM_INVAL_CTXT_CACHE",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Context Cache invalidation events",
                    .full_desc = "Context Cache invalidation events",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU3.NUM_INVAL_INT_CACHE",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Interrupt Entry Cache invalidation events",
                    .full_desc = "Interrupt Entry Cache invalidation events",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU3.NUM_INVAL_IOTLB",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOTLB invalidation events",
                    .full_desc = "IOTLB invalidation events",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_IOMMU3.NUM_INVAL_PASID_CACHE",
                    .encoding =
                        {
                            .code = 0x43ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PASID Cache invalidation events",
                    .full_desc = "PASID Cache invalidation events",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_OUSTANDING_REQ_FROM_CPU.TO_IO",
                    .encoding =
                        {
                            .code = 0xC5ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Occupancy of outbound request queue : To device : Counts number of outbound requests/completions IIO is currently processing",
                    .full_desc =
                        "Occupancy of outbound request queue : To device : Counts number of outbound requests/completions IIO is currently processing",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.DATA",
                    .encoding =
                        {
                            .code = 0x88ULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x700F0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Passing data to be written",
                    .full_desc = "Passing data to be written",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.FINAL_RD_WR",
                    .encoding =
                        {
                            .code = 0x88ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x700F0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Issuing final read or write of line",
                    .full_desc = "Issuing final read or write of line",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.IOMMU_HIT",
                    .encoding =
                        {
                            .code = 0x88ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x700F0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Processing response from IOMMU",
                    .full_desc = "Processing response from IOMMU",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.IOMMU_REQ",
                    .encoding =
                        {
                            .code = 0x88ULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x700F0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Issuing to IOMMU",
                    .full_desc = "Issuing to IOMMU",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.REQ_OWN",
                    .encoding =
                        {
                            .code = 0x88ULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x700F0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Request Ownership",
                    .full_desc = "Request Ownership",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.WR",
                    .encoding =
                        {
                            .code = 0x88ULL,
                            .umask = 0x10ULL,
                            .umask_ext = 0x700F0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Writing line",
                    .full_desc = "Writing line",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.ABORT",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x80ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.CONFINED_P2P",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x40ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.LOC_P2P",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x20ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.MCAST",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.MEM",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.MSGB",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x1ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.REM_P2P",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x10ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.UBOX",
                    .encoding =
                        {
                            .code = 0x8EULL,
                            .umask = 0x4ULL,
                            .umask_ext = 0x70FF0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "-",
                    .full_desc = "-",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_PWT_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x42ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All 9 bits of Page Walk Tracker Occupancy",
                    .full_desc = "All 9 bits of Page Walk Tracker Occupancy",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART0",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70010ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART1",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70020ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART2",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70040ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART3",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70080ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART4",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70100ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART5",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70200ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART6",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70400ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART7",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x70800ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card reading from another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART0",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70010ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART1",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70020ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART2",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70040ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART3",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70080ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART4",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70100ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc = "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART5",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70200ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART6",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70400ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                },
                {
                    .pmu_type = PmuType::uncore_iio,
                    .id = "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART7",
                    .encoding =
                        {
                            .code = 0x84ULL,
                            .umask = 0x2ULL,
                            .umask_ext = 0x70800ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
                    .full_desc =
                        "Number Transactions requested of the CPU : Card writing to another Card (same or different stack)",
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
                    .brief_desc = "Total Write Cache Occupancy : Mem",
                    .full_desc = "Total Write Cache Occupancy : Mem",
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
                    .id = "UNC_I_MISC0.FAST_REJ",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Counts Timeouts - Set 0 : Fastpath Rejects",
                    .full_desc = "Counts Timeouts - Set 0 : Fastpath Rejects",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.FAST_REQ",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Counts Timeouts - Set 0 : Fastpath Requests",
                    .full_desc = "Counts Timeouts - Set 0 : Fastpath Requests",
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
                    .brief_desc =
                        "Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed",
                    .full_desc =
                        "Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.ALL_HIT_ES",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x74ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Hit E/S responses",
                    .full_desc = "Snoop Hit E/S responses",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.ALL_HIT_I",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x72ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Hit I responses",
                    .full_desc = "Snoop Hit I responses",
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
                    .brief_desc = "Snoop Hit M responses",
                    .full_desc = "Snoop Hit M responses",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.ALL_MISS",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x71ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop miss responses",
                    .full_desc = "Snoop miss responses",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_MAX_LIMIT_THERMAL_CYCLES",
                    .encoding =
                        {
                            .code = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Thermal Strongest Upper Limit Cycles",
                    .full_desc =
                        "Thermal Strongest Upper Limit Cycles : Number of cycles any frequency is reduced due to a thermal limit.  Count only if throttling is occurring.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_MAX_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Power Strongest Upper Limit Cycles",
                    .full_desc =
                        "Power Strongest Upper Limit Cycles : Counts the number of cycles when power is the upper limit on frequency.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_TRANS_CYCLES",
                    .encoding =
                        {
                            .code = 0x74ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles spent changing Frequency",
                    .full_desc =
                        "Cycles spent changing Frequency : Counts the number of cycles when the system is changing frequency.  This can not be filtered by thread ID.  One can also use it with the occupancy counter that monitors number of threads in C0 to estimate the performance impact that frequency transitions had on the system.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PKG_RESIDENCY_C2E_CYCLES",
                    .encoding =
                        {
                            .code = 0x2BULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Package C State Residency - C2E",
                    .full_desc =
                        "Package C State Residency - C2E : Counts the number of cycles when the package was in C2E.  This event can be used in conjunction with edge detect to count C2E entrances (or exits using invert).  Residency events do not include transition times.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PKG_RESIDENCY_C6_CYCLES",
                    .encoding =
                        {
                            .code = 0x2DULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Package C State Residency - C6",
                    .full_desc =
                        "Package C State Residency - C6 : Counts the number of cycles when the package was in C6.  This event can be used in conjunction with edge detect to count C6 entrances (or exits using invert).  Residency events do not include transition times.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_POWER_STATE_OCCUPANCY_CORES_C3",
                    .encoding =
                        {
                            .code = 0x36ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of cores in C3",
                    .full_desc =
                        "Number of cores in C3 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PROCHOT_EXTERNAL_CYCLES",
                    .encoding =
                        {
                            .code = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "External Prochot",
                    .full_desc =
                        "External Prochot : Counts the number of cycles that we are in external PROCHOT mode.  This mode is triggered when a sensor off the die determines that something off-die (like DRAM) is too hot and must throttle to avoid damaging the chip.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PROCHOT_INTERNAL_CYCLES",
                    .encoding =
                        {
                            .code = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Internal Prochot",
                    .full_desc =
                        "Internal Prochot : Counts the number of cycles that we are in Internal PROCHOT mode.  This mode is triggered when a sensor on the die determines that we are too hot and must throttle to avoid damaging the chip.",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_L1_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0x21ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles in L1 : Number of UPI qfclk cycles spent in L1 power mode.  L1 is a mode that totally shuts down a UPI link.  Use edge detect to count the number of instances when the UPI link entered L1.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another. Because L1 totally shuts down the link, it takes a good amount of time to exit this mode.",
                    .full_desc = "Cycles in L1",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.NCB",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Non-Coherent Bypass",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Non-Coherent Bypass",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.NCB_OPC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xEULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Non-Coherent Bypass, Match Opcode",
                    .full_desc = "Matches on Receive path of a UPI Port : Non-Coherent Bypass, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.NCS",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Non-Coherent Standard",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Non-Coherent Standard",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.NCS_OPC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xFULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Non-Coherent Standard, Match Opcode",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Non-Coherent Standard, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.REQ_OPC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Request, Match Opcode",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Request, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.RSPCNFLT",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xAAULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Response - Conflict",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Response - Conflict",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.RSPI",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x2AULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Response - Invalid",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Response - Invalid",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_DATA",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Response - Data",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Response - Data",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_DATA_OPC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xCULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Response - Data, Match Opcode",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Response - Data, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_NODATA",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Response - No Data",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Response - No Data",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_NODATA_OPC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xAULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Response - No Data, Match Opcode",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Response - No Data, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.SNP",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Snoop",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Snoop",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.SNP_OPC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x9ULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Snoop, Match Opcode",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Snoop, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_BASIC_HDR_MATCH.WB_OPC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0xDULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Receive path of a UPI Port : Writeback, Match Opcode",
                    .full_desc =
                        "Matches on Receive path of a UPI Port : Writeback, Match Opcode",
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
                        "Valid Flits Received : Null FLITs received from any slot",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.DATA",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : Data : Shows legal flit time (hides impact of L0p and L0c). : Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..",
                    .full_desc = "Valid Flits Received : Data",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.IDLE",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x47ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : Idle : Shows legal flit time (hides impact of L0p and L0c).",
                    .full_desc = "Valid Flits Received : Idle",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.LLCRD",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : LLCRD Not Empty : Shows legal flit time (hides impact of L0p and L0c). : Enables counting of LLCRD (with non-zero payload). This only applies to slot 2 since LLCRD is only allowed in slot 2",
                    .full_desc = "Valid Flits Received : LLCRD Not Empty",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.LLCTRL",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : LLCTRL : Shows legal flit time (hides impact of L0p and L0c). : Equivalent to an idle packet.  Enables counting of slot 0 LLCTRL messages.",
                    .full_desc = "Valid Flits Received : LLCTRL",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.NULL",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : Slot NULL or LLCRD Empty : Shows legal flit time (hides impact of L0p and L0c). : LLCRD with all zeros is treated as NULL. Slot 1 is not treated as NULL if slot 0 is a dual slot. This can apply to slot 0,1, or 2.",
                    .full_desc =
                        "Valid Flits Received : Slot NULL or LLCRD Empty",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.PROTHDR",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : Protocol Header : Shows legal flit time (hides impact of L0p and L0c). : Enables count of protocol headers in slot 0,1,2 (depending on slot uMask bits)",
                    .full_desc = "Valid Flits Received : Protocol Header",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.SLOT0",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : Slot 0 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 0 - Other mask bits determine types of headers to count.",
                    .full_desc = "Valid Flits Received : Slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.SLOT1",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : Slot 1 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 1 - Other mask bits determine types of headers to count.",
                    .full_desc = "Valid Flits Received : Slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_FLITS.SLOT2",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Received : Slot 2 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 2 - Other mask bits determine types of headers to count.",
                    .full_desc = "Valid Flits Received : Slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_INSERTS.SLOT0",
                    .encoding =
                        {
                            .code = 0x30ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RxQ Flit Buffer Allocations : Slot 0 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.",
                    .full_desc = "RxQ Flit Buffer Allocations : Slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_INSERTS.SLOT1",
                    .encoding =
                        {
                            .code = 0x30ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Flit Buffer Allocations : Slot 1 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.",
                    .full_desc = "RxQ Flit Buffer Allocations : Slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_INSERTS.SLOT2",
                    .encoding =
                        {
                            .code = 0x30ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RxQ Flit Buffer Allocations : Slot 2 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.",
                    .full_desc = "RxQ Flit Buffer Allocations : Slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_OCCUPANCY.SLOT0",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - All Packets : Slot 0",
                    .full_desc = "RxQ Occupancy - All Packets : Slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_OCCUPANCY.SLOT1",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - All Packets : Slot 1",
                    .full_desc = "RxQ Occupancy - All Packets : Slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_RxL_OCCUPANCY.SLOT2",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - All Packets : Slot 2",
                    .full_desc = "RxQ Occupancy - All Packets : Slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL0P_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0x27ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in L0p",
                    .full_desc = "Cycles in L0p",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL0P_POWER_CYCLES_LL_ENTER",
                    .encoding =
                        {
                            .code = 0x28ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_UPI_TxL0P_POWER_CYCLES_LL_ENTER",
                    .full_desc = "UNC_UPI_TxL0P_POWER_CYCLES_LL_ENTER",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL0P_POWER_CYCLES_M3_EXIT",
                    .encoding =
                        {
                            .code = 0x29ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_UPI_TxL0P_POWER_CYCLES_M3_EXIT",
                    .full_desc = "UNC_UPI_TxL0P_POWER_CYCLES_M3_EXIT",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.NCB",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Bypass",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Bypass",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.NCB_OPC",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xEULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Bypass, Match Opcode",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Bypass, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.NCS",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Standard",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Standard",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.NCS_OPC",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xFULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Standard, Match Opcode",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Non-Coherent Standard, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.REQ",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Request",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Request",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.REQ_OPC",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x8ULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Request, Match Opcode",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Request, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.RSPCNFLT",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xAAULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Response - Conflict",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Response - Conflict",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.RSPI",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x2AULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Response - Invalid",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Response - Invalid",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_DATA",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Response - Data",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Response - Data",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_DATA_OPC",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xCULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Response - Data, Match Opcode",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Response - Data, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_NODATA",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Response - No Data",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Response - No Data",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_NODATA_OPC",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xAULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Response - No Data, Match Opcode",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Response - No Data, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.SNP",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Snoop",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Snoop",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.SNP_OPC",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x9ULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Snoop, Match Opcode",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Snoop, Match Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.WB",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Writeback",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Writeback",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_BASIC_HDR_MATCH.WB_OPC",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0xDULL,
                            .umask_ext = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Matches on Transmit path of a UPI Port : Writeback, Match Opcode",
                    .full_desc =
                        "Matches on Transmit path of a UPI Port : Writeback, Match Opcode",
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
                    .brief_desc =
                        "Valid Flits Sent : Data : Shows legal flit time (hides impact of L0p and L0c). : Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..",
                    .full_desc = "Valid Flits Sent : Data",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_FLITS.LLCRD",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Sent : LLCRD Not Empty : Shows legal flit time (hides impact of L0p and L0c). : Enables counting of LLCRD (with non-zero payload). This only applies to slot 2 since LLCRD is only allowed in slot 2",
                    .full_desc = "Valid Flits Sent : LLCRD Not Empty",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_FLITS.LLCTRL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Sent : LLCTRL : Shows legal flit time (hides impact of L0p and L0c). : Equivalent to an idle packet.  Enables counting of slot 0 LLCTRL messages.",
                    .full_desc = "Valid Flits Sent : LLCTRL",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_FLITS.NULL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Sent : Slot NULL or LLCRD Empty : Shows legal flit time (hides impact of L0p and L0c). : LLCRD with all zeros is treated as NULL. Slot 1 is not treated as NULL if slot 0 is a dual slot. This can apply to slot 0,1, or 2.",
                    .full_desc = "Valid Flits Sent : Slot NULL or LLCRD Empty",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_FLITS.PROTHDR",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Sent : Protocol Header : Shows legal flit time (hides impact of L0p and L0c). : Enables count of protocol headers in slot 0,1,2 (depending on slot uMask bits)",
                    .full_desc = "Valid Flits Sent : Protocol Header",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_FLITS.SLOT0",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Sent : Slot 0 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 0 - Other mask bits determine types of headers to count.",
                    .full_desc = "Valid Flits Sent : Slot 0",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_FLITS.SLOT1",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Sent : Slot 1 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 1 - Other mask bits determine types of headers to count.",
                    .full_desc = "Valid Flits Sent : Slot 1",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_FLITS.SLOT2",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Valid Flits Sent : Slot 2 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 2 - Other mask bits determine types of headers to count.",
                    .full_desc = "Valid Flits Sent : Slot 2",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_INSERTS",
                    .encoding =
                        {
                            .code = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tx Flit Buffer Allocations : Number of allocations into the UPI Tx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.",
                    .full_desc = "Tx Flit Buffer Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_upi,
                    .id = "UNC_UPI_TxL_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x42ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tx Flit Buffer Occupancy : Accumulates the number of flits in the TxQ.  Generally, when data is transmitted across UPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link. This can be used with the cycles not empty event to track average occupancy, or the allocations event to track average lifetime in the TxQ.",
                    .full_desc = "Tx Flit Buffer Occupancy",
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

} // namespace sierraforest_uncore_experimental
} // namespace facebook::hbt::perf_event::generated
