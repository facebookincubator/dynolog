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
namespace haswellx_uncore {
namespace {

/*
  Events from haswellx_uncore.json (1278 events).

  Supported SKUs:
      - Arch: x86, Model: HSX id: 63
*/
constexpr std::array<StaticEventDef, 2> kAllowlistedEvents{{
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
            "DRAM RD_CAS and WR_CAS Commands.; All DRAM Reads (RD_CAS + Underfills)",
        .full_desc =
            "DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM Read CAS commands issued on this channel (including underfills).",
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
        .brief_desc =
            "DRAM RD_CAS and WR_CAS Commands.; All DRAM WR_CAS (both Modes)",
        .full_desc =
            "DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM Write CAS commands issued on this channel.",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::
    array<StaticEventDef, 512>
        kFullOnlyEvents0{
            {
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_BOUNCE_CONTROL",
                    .encoding =
                        {
                            .code = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Bounce Control",
                    .full_desc = "Bounce Control",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Uncore Clocks",
                    .full_desc = "Uncore Clocks",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_COUNTER0_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x1FULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Counter 0 Occupancy",
                    .full_desc =
                        "Since occupancy counts can only be captured in the Cbo's 0 counter, this event allows a user to capture occupancy related information by filtering the Cb0 occupancy count captured in Counter 0.   The filtering available is found in the control register - threshold, invert and edge detect.   E.g. setting threshold to 1 can effectively monitor how many cycles the monitored queue has an entry.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_FAST_ASSERTED",
                    .encoding =
                        {
                            .code = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "FaST wire asserted",
                    .full_desc =
                        "Counts the number of cycles either the local distress or incoming distress signals are asserted.  Incoming distress includes both up and dn.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_LOOKUP.ANY",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups; Any Request",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_LOOKUP.DATA_READ",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups; Data Read Request",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_LOOKUP.NID",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x41ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups; Lookups that Match NID",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Qualify one of the other subevents by the Target NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.   In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_LOOKUP.READ",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x21ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups; Any Read Request",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Read transactions",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_LOOKUP.REMOTE_SNOOP",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups; External Snoop Request",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Filters for only snoop requests coming from the remote socket(s) through the IPQ.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_LOOKUP.WRITE",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cache Lookups; Write Requests",
                    .full_desc =
                        "Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cacheable and UC.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_VICTIMS.E_STATE",
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
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_VICTIMS.F_STATE",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Lines Victimized",
                    .full_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_VICTIMS.I_STATE",
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
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_VICTIMS.MISS",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Lines Victimized",
                    .full_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_VICTIMS.M_STATE",
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
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_VICTIMS.NID",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Lines Victimized; Victimized Lines that Match NID",
                    .full_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.; Qualify one of the other subevents by the Target NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.   In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_LLC_VICTIMS.S_STATE",
                    .encoding =
                        {
                            .code = 0x37ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Lines in S State",
                    .full_desc =
                        "Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_MISC.CVZERO_PREFETCH_MISS",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cbo Misc; DRd hitting non-M with raw CV=0",
                    .full_desc = "Miscellaneous events in the Cbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_MISC.CVZERO_PREFETCH_VICTIM",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cbo Misc; Clean Victim with raw CV=0",
                    .full_desc = "Miscellaneous events in the Cbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_MISC.RFO_HIT_S",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cbo Misc; RFO HitS",
                    .full_desc =
                        "Miscellaneous events in the Cbo.; Number of times that an RFO hit in S state.  This is useful for determining if it might be good for a workload to use RspIWB instead of RspSWB.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_MISC.RSPI_WAS_FSE",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cbo Misc; Silent Snoop Eviction",
                    .full_desc = "Miscellaneous events in the Cbo.; Counts the number of times when a Snoop hit in FSE states and triggered a silent eviction.  This is useful because this information is lost in the PRE encodings.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_MISC.STARTED",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cbo Misc",
                    .full_desc = "Miscellaneous events in the Cbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_MISC.WC_ALIASING",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cbo Misc; Write Combining Aliasing",
                    .full_desc =
                        "Miscellaneous events in the Cbo.; Counts the number of times that a USWC write (WCIL(F)) transaction hit in the LLC in M state, triggering a WBMtoI followed by the USWC write.  This occurs when there is WC aliasing.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_QLRU.AGE0",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "LRU Queue; LRU Age 0",
                    .full_desc = "How often age was set to 0",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_QLRU.AGE1",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "LRU Queue; LRU Age 1",
                    .full_desc = "How often age was set to 1",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_QLRU.AGE2",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "LRU Queue; LRU Age 2",
                    .full_desc = "How often age was set to 2",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_QLRU.AGE3",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "LRU Queue; LRU Age 3",
                    .full_desc = "How often age was set to 3",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_QLRU.LRU_DECREMENT",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "LRU Queue; LRU Bits Decremented",
                    .full_desc = "How often all LRU bits were decremented by 1",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_QLRU.VICTIM_NON_ZERO",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "LRU Queue; Non-0 Aged Victim",
                    .full_desc =
                        "How often we picked a victim that had a non-zero age",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AD_USED.ALL",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Ring In Use; All",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AD_USED.DOWN",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Ring In Use; Down",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AD_USED.DOWN_EVEN",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Ring In Use; Down and Even",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AD_USED.DOWN_ODD",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Ring In Use; Down and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AD_USED.UP",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Ring In Use; Up",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AD_USED.UP_EVEN",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Ring In Use; Up and Even",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AD_USED.UP_ODD",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Ring In Use; Up and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AK_USED.ALL",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ring In Use; All",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AK_USED.DOWN",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ring In Use; Down",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AK_USED.DOWN_EVEN",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ring In Use; Down and Even",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AK_USED.DOWN_ODD",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ring In Use; Down and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AK_USED.UP",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ring In Use; Up",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AK_USED.UP_EVEN",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ring In Use; Up and Even",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_AK_USED.UP_ODD",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ring In Use; Up and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BL_USED.ALL",
                    .encoding =
                        {
                            .code = 0x1DULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Down",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BL_USED.DOWN",
                    .encoding =
                        {
                            .code = 0x1DULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Down",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BL_USED.DOWN_EVEN",
                    .encoding =
                        {
                            .code = 0x1DULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Down and Even",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BL_USED.DOWN_ODD",
                    .encoding =
                        {
                            .code = 0x1DULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Down and Odd",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BL_USED.UP",
                    .encoding =
                        {
                            .code = 0x1DULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Up",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BL_USED.UP_EVEN",
                    .encoding =
                        {
                            .code = 0x1DULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Up and Even",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BL_USED.UP_ODD",
                    .encoding =
                        {
                            .code = 0x1DULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Up and Odd",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BOUNCES.AD",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number of LLC responses that bounced on the Ring.; AD",
                    .full_desc =
                        "Number of LLC responses that bounced on the Ring.; AD",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BOUNCES.AK",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number of LLC responses that bounced on the Ring.; AK",
                    .full_desc =
                        "Number of LLC responses that bounced on the Ring.; AK",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BOUNCES.BL",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number of LLC responses that bounced on the Ring.; BL",
                    .full_desc =
                        "Number of LLC responses that bounced on the Ring.; BL",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_BOUNCES.IV",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number of LLC responses that bounced on the Ring.; Snoops of processor's cache.",
                    .full_desc =
                        "Number of LLC responses that bounced on the Ring.; Snoops of processor's cache.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_IV_USED.ANY",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Any",
                    .full_desc =
                        "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in HSX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_IV_USED.DN",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Any",
                    .full_desc =
                        "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in HSX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_IV_USED.DOWN",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0xCCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Down",
                    .full_desc =
                        "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in HSX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters for Down polarity",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_IV_USED.UP",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ring in Use; Any",
                    .full_desc =
                        "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in HSX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_SINK_STARVED.AD",
                    .encoding =
                        {
                            .code = 0x6ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_C_RING_SINK_STARVED.AD",
                    .full_desc = "UNC_C_RING_SINK_STARVED.AD",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_SINK_STARVED.AK",
                    .encoding =
                        {
                            .code = 0x6ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_C_RING_SINK_STARVED.AK",
                    .full_desc = "UNC_C_RING_SINK_STARVED.AK",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_SINK_STARVED.BL",
                    .encoding =
                        {
                            .code = 0x6ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_C_RING_SINK_STARVED.BL",
                    .full_desc = "UNC_C_RING_SINK_STARVED.BL",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_SINK_STARVED.IV",
                    .encoding =
                        {
                            .code = 0x6ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_C_RING_SINK_STARVED.IV",
                    .full_desc = "UNC_C_RING_SINK_STARVED.IV",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RING_SRC_THRTL",
                    .encoding =
                        {
                            .code = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number of cycles the Cbo is actively throttling traffic onto the Ring in order to limit bounce traffic.",
                    .full_desc =
                        "Number of cycles the Cbo is actively throttling traffic onto the Ring in order to limit bounce traffic.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_EXT_STARVED.IPQ",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Arbiter Blocking Cycles; IRQ",
                    .full_desc =
                        "Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.; IPQ is externally starved and therefore we are blocking the IRQ.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_EXT_STARVED.IRQ",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Arbiter Blocking Cycles; IPQ",
                    .full_desc =
                        "Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.; IRQ is externally starved and therefore we are blocking the IPQ.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_EXT_STARVED.ISMQ_BIDS",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Arbiter Blocking Cycles; ISMQ_BID",
                    .full_desc =
                        "Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.; Number of times that the ISMQ Bid.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_EXT_STARVED.PRQ",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Arbiter Blocking Cycles; PRQ",
                    .full_desc =
                        "Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INSERTS.IPQ",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Allocations; IPQ",
                    .full_desc =
                        "Counts number of allocations per cycle into the specified Ingress queue.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INSERTS.IRQ",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Allocations; IRQ",
                    .full_desc =
                        "Counts number of allocations per cycle into the specified Ingress queue.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INSERTS.IRQ_REJ",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Allocations; IRQ Rejected",
                    .full_desc =
                        "Counts number of allocations per cycle into the specified Ingress queue.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INSERTS.PRQ",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Allocations; PRQ",
                    .full_desc =
                        "Counts number of allocations per cycle into the specified Ingress queue.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INSERTS.PRQ_REJ",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Allocations; PRQ",
                    .full_desc =
                        "Counts number of allocations per cycle into the specified Ingress queue.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INT_STARVED.IPQ",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Internal Starvation Cycles; IPQ",
                    .full_desc =
                        "Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.; Cycles with the IPQ in Internal Starvation.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INT_STARVED.IRQ",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Internal Starvation Cycles; IRQ",
                    .full_desc =
                        "Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.; Cycles with the IRQ in Internal Starvation.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INT_STARVED.ISMQ",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Internal Starvation Cycles; ISMQ",
                    .full_desc =
                        "Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.; Cycles with the ISMQ in Internal Starvation.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_INT_STARVED.PRQ",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Internal Starvation Cycles; PRQ",
                    .full_desc =
                        "Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IPQ_RETRY.ADDR_CONFLICT",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Probe Queue Retries; Address Conflict",
                    .full_desc =
                        "Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request form the IPQ was retried because of a TOR reject from an address conflicts.  Address conflicts out of the IPQ should be rare.  They will generally only occur if two different sockets are sending requests to the same address at the same time.  This is a true conflict case, unlike the IPQ Address Conflict which is commonly caused by prefetching characteristics.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IPQ_RETRY.ANY",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Probe Queue Retries; Any Reject",
                    .full_desc =
                        "Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request form the IPQ was retried because of a TOR reject.  TOR rejects from the IPQ can be caused by the Egress being full or Address Conflicts.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IPQ_RETRY.FULL",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Probe Queue Retries; No Egress Credits",
                    .full_desc =
                        "Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request form the IPQ was retried because of a TOR reject from the Egress being full.  IPQ requests make use of the AD Egress for regular responses, the BL egress to forward data, and the AK egress to return credits.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IPQ_RETRY.QPI_CREDITS",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Probe Queue Retries; No QPI Credits",
                    .full_desc =
                        "Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IPQ_RETRY2.AD_SBO",
                    .encoding =
                        {
                            .code = 0x28ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Probe Queue Retries; No AD Sbo Credits",
                    .full_desc =
                        "Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request from the IPQ was retried because of it lacked credits to send an AD packet to the Sbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IPQ_RETRY2.TARGET",
                    .encoding =
                        {
                            .code = 0x28ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Probe Queue Retries; Target Node Filter",
                    .full_desc =
                        "Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request from the IPQ was retried filtered by the Target NodeID as specified in the Cbox's Filter register.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY.ADDR_CONFLICT",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Ingress Request Queue Rejects; Address Conflict",
                    .full_desc =
                        "Counts the number of times that a request from the IRQ was retried because of an address match in the TOR.  In order to maintain coherency, requests to the same address are not allowed to pass each other up in the Cbo.  Therefore, if there is an outstanding request to a given address, one cannot issue another request to that address until it is complete.  This comes up most commonly with prefetches.  Outstanding prefetches occasionally will not complete their memory fetch and a demand request to the same address will then sit in the IRQ and get retried until the prefetch fills the data into the LLC.  Therefore, it will not be uncommon to see this case in high bandwidth streaming workloads when the LLC Prefetcher in the core is enabled.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY.ANY",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Request Queue Rejects; Any Reject",
                    .full_desc =
                        "Counts the number of IRQ retries that occur.  Requests from the IRQ are retried if they are rejected from the TOR pipeline for a variety of reasons.  Some of the most common reasons include if the Egress is full, there are no RTIDs, or there is a Physical Address match to another outstanding request.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY.FULL",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Ingress Request Queue Rejects; No Egress Credits",
                    .full_desc =
                        "Counts the number of times that a request from the IRQ was retried because it failed to acquire an entry in the Egress.  The egress is the buffer that queues up for allocating onto the ring.  IRQ requests can make use of all four rings and all four Egresses.  If any of the queues that a given request needs to make use of are full, the request will be retried.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY.IIO_CREDITS",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Ingress Request Queue Rejects; No IIO Credits",
                    .full_desc =
                        "Number of times a request attempted to acquire the NCS/NCB credit for sending messages on BL to the IIO.  There is a single credit in each CBo that is shared between the NCS and NCB message classes for sending transactions on the BL ring (such as read data) to the IIO.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY.NID",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Request Queue Rejects",
                    .full_desc =
                        "Qualify one of the other subevents by a given RTID destination NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER1.nid.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY.QPI_CREDITS",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Ingress Request Queue Rejects; No QPI Credits",
                    .full_desc =
                        "Number of requests rejects because of lack of QPI Ingress credits.  These credits are required in order to send transactions to the QPI agent.  Please see the QPI_IGR_CREDITS events for more information.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY.RTID",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Request Queue Rejects; No RTIDs",
                    .full_desc =
                        "Counts the number of times that requests from the IRQ were retried because there were no RTIDs available.  RTIDs are required after a request misses the LLC and needs to send snoops and/or requests to memory.  If there are no RTIDs available, requests will queue up in the IRQ and retry until one becomes available.  Note that there are multiple RTID pools for the different sockets.  There may be cases where the local RTIDs are all used, but requests destined for remote memory can still acquire an RTID because there are remote RTIDs available.  This event does not provide any filtering for this case.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY2.AD_SBO",
                    .encoding =
                        {
                            .code = 0x29ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Ingress Request Queue Rejects; No AD Sbo Credits",
                    .full_desc =
                        "Counts the number of times that a request from the IPQ was retried because of it lacked credits to send an AD packet to the Sbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY2.BL_SBO",
                    .encoding =
                        {
                            .code = 0x29ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Ingress Request Queue Rejects; No BL Sbo Credits",
                    .full_desc =
                        "Counts the number of times that a request from the IPQ was retried because of it lacked credits to send an BL packet to the Sbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_IRQ_RETRY2.TARGET",
                    .encoding =
                        {
                            .code = 0x29ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Ingress Request Queue Rejects; Target Node Filter",
                    .full_desc =
                        "Counts the number of times that a request from the IPQ was retried filtered by the Target NodeID as specified in the Cbox's Filter register.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY.ANY",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ISMQ Retries; Any Reject",
                    .full_desc =
                        "Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Counts the total number of times that a request from the ISMQ retried because of a TOR reject.  ISMQ requests generally will not need to retry (or at least ISMQ retries are less common than IRQ retries).  ISMQ requests will retry if they are not able to acquire a needed Egress credit to get onto the ring, or for cache evictions that need to acquire an RTID.  Most ISMQ requests already have an RTID, so eviction retries will be less common here.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY.FULL",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ISMQ Retries; No Egress Credits",
                    .full_desc =
                        "Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Counts the number of times that a request from the ISMQ retried because of a TOR reject caused by a lack of Egress credits. The egress is the buffer that queues up for allocating onto the ring.  If any of the Egress queues that a given request needs to make use of are full, the request will be retried.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY.IIO_CREDITS",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ISMQ Retries; No IIO Credits",
                    .full_desc =
                        "Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Number of times a request attempted to acquire the NCS/NCB credit for sending messages on BL to the IIO.  There is a single credit in each CBo that is shared between the NCS and NCB message classes for sending transactions on the BL ring (such as read data) to the IIO.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY.NID",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ISMQ Retries",
                    .full_desc =
                        "Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Qualify one of the other subevents by a given RTID destination NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER1.nid.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY.QPI_CREDITS",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ISMQ Retries; No QPI Credits",
                    .full_desc = "Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY.RTID",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ISMQ Retries; No RTIDs",
                    .full_desc =
                        "Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Counts the number of times that a request from the ISMQ retried because of a TOR reject caused by no RTIDs.  M-state cache evictions are serviced through the ISMQ, and must acquire an RTID in order to write back to memory.  If no RTIDs are available, they will be retried.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY.WB_CREDITS",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ISMQ Retries",
                    .full_desc =
                        "Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Qualify one of the other subevents by a given RTID destination NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER1.nid.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY2.AD_SBO",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "ISMQ Request Queue Rejects; No AD Sbo Credits",
                    .full_desc =
                        "Counts the number of times that a request from the ISMQ was retried because of it lacked credits to send an AD packet to the Sbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY2.BL_SBO",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "ISMQ Request Queue Rejects; No BL Sbo Credits",
                    .full_desc =
                        "Counts the number of times that a request from the ISMQ was retried because of it lacked credits to send an BL packet to the Sbo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_ISMQ_RETRY2.TARGET",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "ISMQ Request Queue Rejects; Target Node Filter",
                    .full_desc =
                        "Counts the number of times that a request from the ISMQ was retried filtered by the Target NodeID as specified in the Cbox's Filter register.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_OCCUPANCY.IPQ",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Occupancy; IPQ",
                    .full_desc =
                        "Counts number of entries in the specified Ingress queue in each cycle.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_OCCUPANCY.IRQ",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Occupancy; IRQ",
                    .full_desc =
                        "Counts number of entries in the specified Ingress queue in each cycle.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_OCCUPANCY.IRQ_REJ",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Occupancy; IRQ Rejected",
                    .full_desc =
                        "Counts number of entries in the specified Ingress queue in each cycle.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_RxR_OCCUPANCY.PRQ_REJ",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Occupancy; PRQ Rejects",
                    .full_desc =
                        "Counts number of entries in the specified Ingress queue in each cycle.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_SBO_CREDITS_ACQUIRED.AD",
                    .encoding =
                        {
                            .code = 0x3DULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo Credits Acquired; For AD Ring",
                    .full_desc =
                        "Number of Sbo credits acquired in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_SBO_CREDITS_ACQUIRED.BL",
                    .encoding =
                        {
                            .code = 0x3DULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo Credits Acquired; For BL Ring",
                    .full_desc =
                        "Number of Sbo credits acquired in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_SBO_CREDIT_OCCUPANCY.AD",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo Credits Occupancy; For AD Ring",
                    .full_desc =
                        "Number of Sbo credits in use in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_SBO_CREDIT_OCCUPANCY.BL",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo Credits Occupancy; For BL Ring",
                    .full_desc =
                        "Number of Sbo credits in use in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.ALL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; All",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions inserted into the TOR.    This includes requests that reside in the TOR for a short time, such as LLC Hits that do not need to snoop cores or requests that get rejected and have to be retried through one of the ingress queues.  The TOR is more commonly a bottleneck in skews with smaller core counts, where the ratio of RTIDs to TOR entries is larger.  Note that there are reserved TOR entries for various request types, so it is possible that a given request type be blocked with an occupancy that is less than 20.  Also note that generally requests will not be able to arbitrate into the TOR pipeline if there are no available TOR slots.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.EVICTION",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Evictions",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Eviction transactions inserted into the TOR.  Evictions can be quick, such as when the line is in the F, S, or E states and no core valid bits are set.  They can also be longer if either CV bits are set (so the cores need to be snooped) and/or if there is a HitM (in which case it is necessary to write the request out to memory).",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.LOCAL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x28ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Local Memory",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions inserted into the TOR that are satisfied by locally HOMed memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.LOCAL_OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x21ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Local Memory - Opcode Matched",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions, satisfied by an opcode,  inserted into the TOR that are satisfied by locally HOMed memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x2AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Misses to Local Memory",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that are satisfied by locally HOMed memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.MISS_LOCAL_OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x23ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts; Misses to Local Memory - Opcode Matched",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions, satisfied by an opcode, inserted into the TOR that are satisfied by locally HOMed memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.MISS_OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Miss Opcode Match",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that match an opcode.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.MISS_REMOTE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x8AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Misses to Remote Memory",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that are satisfied by remote caches or remote memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.MISS_REMOTE_OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x83ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Inserts; Misses to Remote Memory - Opcode Matched",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions, satisfied by an opcode,  inserted into the TOR that are satisfied by remote caches or remote memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.NID_ALL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x48ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; NID Matched",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All NID matched (matches an RTID destination) transactions inserted into the TOR.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.  In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.NID_EVICTION",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x44ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; NID Matched Evictions",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; NID matched eviction transactions inserted into the TOR.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.NID_MISS_ALL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; NID Matched Miss All",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All NID matched miss requests that were inserted into the TOR.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.NID_MISS_OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x43ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; NID and Opcode Matched Miss",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that match a NID and an opcode.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.NID_OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x41ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; NID and Opcode Matched",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Transactions inserted into the TOR that match a NID and an opcode.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.NID_WB",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x50ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; NID Matched Writebacks",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; NID matched write transactions inserted into the TOR.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Opcode Match",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Transactions inserted into the TOR that match an opcode (matched by Cn_MSR_PMON_BOX_FILTER.opc)",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.REMOTE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x88ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Remote Memory",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions inserted into the TOR that are satisfied by remote caches or remote memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.REMOTE_OPCODE",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x81ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Remote Memory - Opcode Matched",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions, satisfied by an opcode,  inserted into the TOR that are satisfied by remote caches or remote memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_INSERTS.WB",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Inserts; Writebacks",
                    .full_desc =
                        "Counts the number of entries successfully inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Write transactions inserted into the TOR.   This does not include RFO, but actual operations that contain data being sent from the core.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; Any",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); All valid TOR entries.  This includes requests that reside in the TOR for a short time, such as LLC Hits that do not need to snoop cores or requests that get rejected and have to be retried through one of the ingress queues.  The TOR is more commonly a bottleneck in skews with smaller core counts, where the ratio of RTIDs to TOR entries is larger.  Note that there are reserved TOR entries for various request types, so it is possible that a given request type be blocked with an occupancy that is less than 20.  Also note that generally requests will not be able to arbitrate into the TOR pipeline if there are no available TOR slots.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.EVICTION",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; Evictions",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding eviction transactions in the TOR.  Evictions can be quick, such as when the line is in the F, S, or E states and no core valid bits are set.  They can also be longer if either CV bits are set (so the cores need to be snooped) and/or if there is a HitM (in which case it is necessary to write the request out to memory).",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.LOCAL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x28ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182)",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.LOCAL_OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x21ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy; Local Memory - Opcode Matched",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding  transactions, satisfied by an opcode,  in the TOR that are satisfied by locally HOMed memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.MISS_ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; Miss All",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding miss requests in the TOR.  'Miss' means the allocation requires an RTID.  This generally means that the request was sent to memory or MMIO.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x2AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182)",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.MISS_LOCAL_OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x23ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy; Misses to Local Memory - Opcode Matched",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss transactions, satisfied by an opcode, in the TOR that are satisfied by locally HOMed memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.MISS_OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; Miss Opcode Match",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); TOR entries for miss transactions that match an opcode. This generally means that the request was sent to memory or MMIO.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.MISS_REMOTE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x8AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182)",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.MISS_REMOTE_OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x83ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy; Misses to Remote Memory - Opcode Matched",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss transactions, satisfied by an opcode, in the TOR that are satisfied by remote caches or remote memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.NID_ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x48ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; NID Matched",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of NID matched outstanding requests in the TOR.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.NID_EVICTION",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x44ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; NID Matched Evictions",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding NID matched eviction transactions in the TOR .",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.NID_MISS_ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x4AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; NID Matched",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss requests in the TOR that match a NID.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.NID_MISS_OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x43ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; NID and Opcode Matched Miss",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss requests in the TOR that match a NID and an opcode.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.NID_OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x41ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; NID and Opcode Matched",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); TOR entries that match a NID and an opcode.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.NID_WB",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x50ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; NID Matched Writebacks",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); NID matched write transactions int the TOR.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; Opcode Match",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); TOR entries that match an opcode (matched by Cn_MSR_PMON_BOX_FILTER.opc).",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.REMOTE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x88ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182)",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.REMOTE_OPCODE",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x81ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "TOR Occupancy; Remote Memory - Opcode Matched",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding  transactions, satisfied by an opcode,  in the TOR that are satisfied by remote caches or remote memory.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TOR_OCCUPANCY.WB",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "TOR Occupancy; Writebacks",
                    .full_desc =
                        "For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Write transactions in the TOR.   This does not include RFO, but actual operations that contain data being sent from the core.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_ADS_USED.AD",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Onto AD Ring",
                    .full_desc = "Onto AD Ring",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_ADS_USED.AK",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Onto AK Ring",
                    .full_desc = "Onto AK Ring",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_ADS_USED.BL",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Onto BL Ring",
                    .full_desc = "Onto BL Ring",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_INSERTS.AD_CACHE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Allocations; AD - Cachebo",
                    .full_desc =
                        "Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the AD ring.  Some example include outbound requests, snoop requests, and snoop responses.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_INSERTS.AD_CORE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Allocations; AD - Corebo",
                    .full_desc =
                        "Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Corebo destined for the AD ring.  This is commonly used for outbound requests.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_INSERTS.AK_CACHE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Allocations; AK - Cachebo",
                    .full_desc =
                        "Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the AK ring.  This is commonly used for credit returns and GO responses.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_INSERTS.AK_CORE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Allocations; AK - Corebo",
                    .full_desc = "Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Corebo destined for the AK ring.  This is commonly used for snoop responses coming from the core and destined for a Cachebo.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_INSERTS.BL_CACHE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Allocations; BL - Cacheno",
                    .full_desc =
                        "Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the BL ring.  This is commonly used to send data from the cache to various destinations.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_INSERTS.BL_CORE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Allocations; BL - Corebo",
                    .full_desc =
                        "Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Corebo destined for the BL ring.  This is commonly used for transferring writeback data to the cache.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_INSERTS.IV_CACHE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Allocations; IV - Cachebo",
                    .full_desc =
                        "Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the IV ring.  This is commonly used for snoops to the cores.",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_STARVED.AD_CORE",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Injection Starvation; Onto AD Ring (to core)",
                    .full_desc =
                        "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that the core AD egress spent in starvation",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_STARVED.AK_BOTH",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Injection Starvation; Onto AK Ring",
                    .full_desc =
                        "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that both AK egresses spent in starvation",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_STARVED.BL_BOTH",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Injection Starvation; Onto BL Ring",
                    .full_desc =
                        "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that both BL egresses spent in starvation",
                },
                {
                    .pmu_type = PmuType::uncore_cbox,
                    .id = "UNC_C_TxR_STARVED.IV",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Injection Starvation; Onto IV Ring",
                    .full_desc =
                        "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that the cachebo IV egress spent in starvation",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_ADDR_OPC_MATCH.AD",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "QPI Address/Opcode Match; AD Opcodes",
                    .full_desc = "QPI Address/Opcode Match; AD Opcodes",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_ADDR_OPC_MATCH.ADDR",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "QPI Address/Opcode Match; Address",
                    .full_desc = "QPI Address/Opcode Match; Address",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_ADDR_OPC_MATCH.AK",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "QPI Address/Opcode Match; AK Opcodes",
                    .full_desc = "QPI Address/Opcode Match; AK Opcodes",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_ADDR_OPC_MATCH.BL",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "QPI Address/Opcode Match; BL Opcodes",
                    .full_desc = "QPI Address/Opcode Match; BL Opcodes",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_ADDR_OPC_MATCH.FILT",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "QPI Address/Opcode Match; Address & Opcode Match",
                    .full_desc =
                        "QPI Address/Opcode Match; Address & Opcode Match",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_ADDR_OPC_MATCH.OPC",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "QPI Address/Opcode Match; Opcode",
                    .full_desc = "QPI Address/Opcode Match; Opcode",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_BT_CYCLES_NE",
                    .encoding =
                        {
                            .code = 0x42ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BT Cycles Not Empty",
                    .full_desc =
                        "Cycles the Backup Tracker (BT) is not empty. The BT is the actual HOM tracker in IVT.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_BT_TO_HT_NOT_ISSUED.INCOMING_BL_HAZARD",
                    .encoding =
                        {
                            .code = 0x51ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BT to HT Not Issued; Incoming Data Hazard",
                    .full_desc =
                        "Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming BL data hazard",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_BT_TO_HT_NOT_ISSUED.INCOMING_SNP_HAZARD",
                    .encoding =
                        {
                            .code = 0x51ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BT to HT Not Issued; Incoming Snoop Hazard",
                    .full_desc =
                        "Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming snoop hazard",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_BT_TO_HT_NOT_ISSUED.RSPACKCFLT_HAZARD",
                    .encoding =
                        {
                            .code = 0x51ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BT to HT Not Issued; Incoming Data Hazard",
                    .full_desc =
                        "Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming BL data hazard",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_BT_TO_HT_NOT_ISSUED.WBMDATA_HAZARD",
                    .encoding =
                        {
                            .code = 0x51ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BT to HT Not Issued; Incoming Data Hazard",
                    .full_desc =
                        "Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming BL data hazard",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_BYPASS_IMC.NOT_TAKEN",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA to iMC Bypass; Not Taken",
                    .full_desc =
                        "Counts the number of times when the HA was able to bypass was attempted.  This is a latency optimization for situations when there is light loadings on the memory subsystem.  This can be filtered by when the bypass was taken and when it was not.; Filter for transactions that could not take the bypass.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_BYPASS_IMC.TAKEN",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA to iMC Bypass; Taken",
                    .full_desc =
                        "Counts the number of times when the HA was able to bypass was attempted.  This is a latency optimization for situations when there is light loadings on the memory subsystem.  This can be filtered by when the bypass was taken and when it was not.; Filter for transactions that succeeded in taking the bypass.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "uclks",
                    .full_desc =
                        "Counts the number of uclks in the HA.  This will be slightly different than the count in the Ubox because of enable/freeze delays.  The HA is on the other side of the die from the fixed Ubox uclk counter, so the drift could be somewhat larger than in units that are closer like the QPI Agent.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECT2CORE_COUNT",
                    .encoding =
                        {
                            .code = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Direct2Core Messages Sent",
                    .full_desc = "Number of Direct2Core messages sent",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECT2CORE_CYCLES_DISABLED",
                    .encoding =
                        {
                            .code = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles when Direct2Core was Disabled",
                    .full_desc =
                        "Number of cycles in which Direct2Core was disabled",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECT2CORE_TXN_OVERRIDE",
                    .encoding =
                        {
                            .code = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Number of Reads that had Direct2Core Overridden",
                    .full_desc = "Number of Reads where Direct2Core overridden",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECTORY_LAT_OPT",
                    .encoding =
                        {
                            .code = 0x41ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Directory Lat Opt Return",
                    .full_desc =
                        "Directory Latency Optimization Data Return Path Taken. When directory mode is enabled and the directory returned for a read is Dir=I, then data can be returned using a faster path if certain conditions are met (credits, free pipeline, etc).",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECTORY_LOOKUP.NO_SNP",
                    .encoding =
                        {
                            .code = 0xCULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Directory Lookups; Snoop Not Needed",
                    .full_desc =
                        "Counts the number of transactions that looked up the directory.  Can be filtered by requests that had to snoop and those that did not have to.; Filters for transactions that did not have to send any snoops because the directory bit was clear.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECTORY_LOOKUP.SNP",
                    .encoding =
                        {
                            .code = 0xCULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Directory Lookups; Snoop Needed",
                    .full_desc =
                        "Counts the number of transactions that looked up the directory.  Can be filtered by requests that had to snoop and those that did not have to.; Filters for transactions that had to send one or more snoops because the directory bit was set.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECTORY_UPDATE.ANY",
                    .encoding =
                        {
                            .code = 0xDULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Directory Updates; Any Directory Update",
                    .full_desc =
                        "Counts the number of directory updates that were required.  These result in writes to the memory controller.  This can be filtered by directory sets and directory clears.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECTORY_UPDATE.CLEAR",
                    .encoding =
                        {
                            .code = 0xDULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Directory Updates; Directory Clear",
                    .full_desc =
                        "Counts the number of directory updates that were required.  These result in writes to the memory controller.  This can be filtered by directory sets and directory clears.; Filter for directory clears.  This occurs when snoops were sent and all returned with RspI.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_DIRECTORY_UPDATE.SET",
                    .encoding =
                        {
                            .code = 0xDULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Directory Updates; Directory Set",
                    .full_desc =
                        "Counts the number of directory updates that were required.  These result in writes to the memory controller.  This can be filtered by directory sets and directory clears.; Filter for directory sets.  This occurs when a remote read transaction requests memory, bringing it to a remote cache.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.ACKCNFLTWBI",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is AckCnfltWbI",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is AckCnfltWbI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.ALL",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0xFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; All Requests",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; All Requests",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.ALLOCS",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x70ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; Allocations",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.EVICTS",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x42ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; Allocations",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.HOM",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; HOM Requests",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; HOM Requests",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.INVALS",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x26ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; Invalidations",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; Invalidations",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.READ_OR_INVITOE",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.RSP",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.RSPFWDI_LOCAL",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a local request",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a local request",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.RSPFWDI_REMOTE",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a remote request",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a remote request",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.RSPFWDS",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is RsSFwd or RspSFwdWb",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is RsSFwd or RspSFwdWb",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.WBMTOE_OR_S",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is WbMtoE or WbMtoS",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is WbMtoE or WbMtoS",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT.WBMTOI",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of Hits in HitMe Cache; op is WbMtoI",
                    .full_desc =
                        "Counts Number of Hits in HitMe Cache; op is WbMtoI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.ACKCNFLTWBI",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is AckCnfltWbI",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is AckCnfltWbI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.ALL",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0xFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; All Requests",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; All Requests",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.HOM",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; HOM Requests",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; HOM Requests",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.READ_OR_INVITOE",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.RSP",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.RSPFWDI_LOCAL",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a local request",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a local request",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.RSPFWDI_REMOTE",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a remote request",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a remote request",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.RSPFWDS",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RsSFwd or RspSFwdWb",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is RsSFwd or RspSFwdWb",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.WBMTOE_OR_S",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoE or WbMtoS",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoE or WbMtoS",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_HIT_PV_BITS_SET.WBMTOI",
                    .encoding =
                        {
                            .code = 0x72ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoI",
                    .full_desc =
                        "Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.ACKCNFLTWBI",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is AckCnfltWbI",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is AckCnfltWbI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.ALL",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0xFFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; All Requests",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; All Requests",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.ALLOCS",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x70ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; Allocations",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; Allocations",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.HOM",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; HOM Requests",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; HOM Requests",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.INVALS",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x26ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; Invalidations",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; Invalidations",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.READ_OR_INVITOE",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.RSP",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.RSPFWDI_LOCAL",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a local request",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a local request",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.RSPFWDI_REMOTE",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a remote request",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a remote request",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.RSPFWDS",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RsSFwd or RspSFwdWb",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is RsSFwd or RspSFwdWb",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.WBMTOE_OR_S",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is WbMtoE or WbMtoS",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is WbMtoE or WbMtoS",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_HITME_LOOKUP.WBMTOI",
                    .encoding =
                        {
                            .code = 0x70ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts Number of times HitMe Cache is accessed; op is WbMtoI",
                    .full_desc =
                        "Counts Number of times HitMe Cache is accessed; op is WbMtoI",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IGR_NO_CREDIT_CYCLES.AD_QPI0",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles without QPI Ingress Credits; AD to QPI Link 0",
                    .full_desc =
                        "Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IGR_NO_CREDIT_CYCLES.AD_QPI1",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles without QPI Ingress Credits; AD to QPI Link 1",
                    .full_desc =
                        "Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IGR_NO_CREDIT_CYCLES.AD_QPI2",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles without QPI Ingress Credits; BL to QPI Link 0",
                    .full_desc =
                        "Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IGR_NO_CREDIT_CYCLES.BL_QPI0",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles without QPI Ingress Credits; BL to QPI Link 0",
                    .full_desc =
                        "Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IGR_NO_CREDIT_CYCLES.BL_QPI1",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles without QPI Ingress Credits; BL to QPI Link 1",
                    .full_desc =
                        "Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IGR_NO_CREDIT_CYCLES.BL_QPI2",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles without QPI Ingress Credits; BL to QPI Link 1",
                    .full_desc =
                        "Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IMC_READS.NORMAL",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA to iMC Normal Priority Reads Issued; Normal Priority",
                    .full_desc =
                        "Count of the number of reads issued to any of the memory controller channels.  This can be filtered by the priority of the reads.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IMC_RETRY",
                    .encoding =
                        {
                            .code = 0x1EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Retry Events",
                    .full_desc = "Retry Events",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IMC_WRITES.ALL",
                    .encoding =
                        {
                            .code = 0x1AULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA to iMC Full Line Writes Issued; All Writes",
                    .full_desc =
                        "Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IMC_WRITES.FULL",
                    .encoding =
                        {
                            .code = 0x1AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA to iMC Full Line Writes Issued; Full Line Non-ISOCH",
                    .full_desc =
                        "Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IMC_WRITES.FULL_ISOCH",
                    .encoding =
                        {
                            .code = 0x1AULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA to iMC Full Line Writes Issued; ISOCH Full Line",
                    .full_desc =
                        "Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IMC_WRITES.PARTIAL",
                    .encoding =
                        {
                            .code = 0x1AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA to iMC Full Line Writes Issued; Partial Non-ISOCH",
                    .full_desc =
                        "Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IMC_WRITES.PARTIAL_ISOCH",
                    .encoding =
                        {
                            .code = 0x1AULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA to iMC Full Line Writes Issued; ISOCH Partial",
                    .full_desc =
                        "Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_BACKPRESSURE.HUB",
                    .encoding =
                        {
                            .code = 0x61ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Backpressure",
                    .full_desc = "IOT Backpressure",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_BACKPRESSURE.SAT",
                    .encoding =
                        {
                            .code = 0x61ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Backpressure",
                    .full_desc = "IOT Backpressure",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_CTS_EAST_LO.CTS0",
                    .encoding =
                        {
                            .code = 0x64ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Common Trigger Sequencer - Lo",
                    .full_desc = "Debug Mask/Match Tie-Ins",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_CTS_EAST_LO.CTS1",
                    .encoding =
                        {
                            .code = 0x64ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Common Trigger Sequencer - Lo",
                    .full_desc = "Debug Mask/Match Tie-Ins",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_CTS_HI.CTS2",
                    .encoding =
                        {
                            .code = 0x65ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Common Trigger Sequencer - Hi",
                    .full_desc = "Debug Mask/Match Tie-Ins",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_CTS_HI.CTS3",
                    .encoding =
                        {
                            .code = 0x65ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Common Trigger Sequencer - Hi",
                    .full_desc = "Debug Mask/Match Tie-Ins",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_CTS_WEST_LO.CTS0",
                    .encoding =
                        {
                            .code = 0x62ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Common Trigger Sequencer - Lo",
                    .full_desc = "Debug Mask/Match Tie-Ins",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_IOT_CTS_WEST_LO.CTS1",
                    .encoding =
                        {
                            .code = 0x62ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IOT Common Trigger Sequencer - Lo",
                    .full_desc = "Debug Mask/Match Tie-Ins",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB.CANCELLED",
                    .encoding =
                        {
                            .code = 0x53ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Snoop Broadcast; Cancelled",
                    .full_desc =
                        "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.; OSB Snoop broadcast cancelled due to D2C or Other. OSB cancel is counted when OSB local read is not allowed even when the transaction in local InItoE. It also counts D2C OSB cancel, but also includes the cases were D2C was not set in the first place for the transaction coming from the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB.INVITOE_LOCAL",
                    .encoding =
                        {
                            .code = 0x53ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Snoop Broadcast; Local InvItoE",
                    .full_desc =
                        "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB.READS_LOCAL",
                    .encoding =
                        {
                            .code = 0x53ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Snoop Broadcast; Local Reads",
                    .full_desc =
                        "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB.READS_LOCAL_USEFUL",
                    .encoding =
                        {
                            .code = 0x53ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Snoop Broadcast; Reads Local -  Useful",
                    .full_desc =
                        "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB.REMOTE",
                    .encoding =
                        {
                            .code = 0x53ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Snoop Broadcast; Remote",
                    .full_desc =
                        "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB.REMOTE_USEFUL",
                    .encoding =
                        {
                            .code = 0x53ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Snoop Broadcast; Remote - Useful",
                    .full_desc =
                        "Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB_EDR.ALL",
                    .encoding =
                        {
                            .code = 0x54ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Early Data Return; All",
                    .full_desc =
                        "Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB_EDR.READS_LOCAL_I",
                    .encoding =
                        {
                            .code = 0x54ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Early Data Return; Reads to Local  I",
                    .full_desc =
                        "Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB_EDR.READS_LOCAL_S",
                    .encoding =
                        {
                            .code = 0x54ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Early Data Return; Reads to Local S",
                    .full_desc =
                        "Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB_EDR.READS_REMOTE_I",
                    .encoding =
                        {
                            .code = 0x54ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Early Data Return; Reads to Remote I",
                    .full_desc =
                        "Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_OSB_EDR.READS_REMOTE_S",
                    .encoding =
                        {
                            .code = 0x54ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OSB Early Data Return; Reads to Remote S",
                    .full_desc =
                        "Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.INVITOE_LOCAL",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Local InvItoEs",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only InvItoEs coming from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.INVITOE_REMOTE",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Remote InvItoEs",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only InvItoEs coming from remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.READS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Reads",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; Incoming ead requests.  This is a good proxy for LLC Read Misses (including RFOs).",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.READS_LOCAL",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Local Reads",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only read requests coming from the local socket.  This is a good proxy for LLC Read Misses (including RFOs) from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.READS_REMOTE",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Remote Reads",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only read requests coming from the remote socket.  This is a good proxy for LLC Read Misses (including RFOs) from the remote socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.WRITES",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Writes",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; Incoming write requests.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.WRITES_LOCAL",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Local Writes",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only writes coming from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_REQUESTS.WRITES_REMOTE",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read and Write Requests; Remote Writes",
                    .full_desc =
                        "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only writes coming from remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AD_USED.CCW",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AD Ring in Use; Counterclockwise",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AD_USED.CCW_EVEN",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA AD Ring in Use; Counterclockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AD_USED.CCW_ODD",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AD Ring in Use; Counterclockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AD_USED.CW",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AD Ring in Use; Clockwise",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AD_USED.CW_EVEN",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AD Ring in Use; Clockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AD_USED.CW_ODD",
                    .encoding =
                        {
                            .code = 0x3EULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AD Ring in Use; Clockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AK_USED.CCW",
                    .encoding =
                        {
                            .code = 0x3FULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AK Ring in Use; Counterclockwise",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AK_USED.CCW_EVEN",
                    .encoding =
                        {
                            .code = 0x3FULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA AK Ring in Use; Counterclockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AK_USED.CCW_ODD",
                    .encoding =
                        {
                            .code = 0x3FULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AK Ring in Use; Counterclockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AK_USED.CW",
                    .encoding =
                        {
                            .code = 0x3FULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AK Ring in Use; Clockwise",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AK_USED.CW_EVEN",
                    .encoding =
                        {
                            .code = 0x3FULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AK Ring in Use; Clockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_AK_USED.CW_ODD",
                    .encoding =
                        {
                            .code = 0x3FULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA AK Ring in Use; Clockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_BL_USED.CCW",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA BL Ring in Use; Counterclockwise",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_BL_USED.CCW_EVEN",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA BL Ring in Use; Counterclockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_BL_USED.CCW_ODD",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA BL Ring in Use; Counterclockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_BL_USED.CW",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA BL Ring in Use; Clockwise",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_BL_USED.CW_EVEN",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA BL Ring in Use; Clockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RING_BL_USED.CW_ODD",
                    .encoding =
                        {
                            .code = 0x40ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "HA BL Ring in Use; Clockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN0",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Regular; Channel 0",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN1",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Regular; Channel 1",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN2",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Regular; Channel 2",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN3",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Regular; Channel 3",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN0",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Special; Channel 0",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN1",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Special; Channel 1",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN2",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Special; Channel 2",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN3",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "iMC RPQ Credits Empty - Special; Channel 3",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO0_CREDITS_ACQUIRED.AD",
                    .encoding =
                        {
                            .code = 0x68ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Acquired; For AD Ring",
                    .full_desc =
                        "Number of Sbo 0 credits acquired in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO0_CREDITS_ACQUIRED.BL",
                    .encoding =
                        {
                            .code = 0x68ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Acquired; For BL Ring",
                    .full_desc =
                        "Number of Sbo 0 credits acquired in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO0_CREDIT_OCCUPANCY.AD",
                    .encoding =
                        {
                            .code = 0x6AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Occupancy; For AD Ring",
                    .full_desc =
                        "Number of Sbo 0 credits in use in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO0_CREDIT_OCCUPANCY.BL",
                    .encoding =
                        {
                            .code = 0x6AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Occupancy; For BL Ring",
                    .full_desc =
                        "Number of Sbo 0 credits in use in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO1_CREDITS_ACQUIRED.AD",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo1 Credits Acquired; For AD Ring",
                    .full_desc =
                        "Number of Sbo 1 credits acquired in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO1_CREDITS_ACQUIRED.BL",
                    .encoding =
                        {
                            .code = 0x69ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo1 Credits Acquired; For BL Ring",
                    .full_desc =
                        "Number of Sbo 1 credits acquired in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO1_CREDIT_OCCUPANCY.AD",
                    .encoding =
                        {
                            .code = 0x6BULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo1 Credits Occupancy; For AD Ring",
                    .full_desc =
                        "Number of Sbo 1 credits in use in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SBO1_CREDIT_OCCUPANCY.BL",
                    .encoding =
                        {
                            .code = 0x6BULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo1 Credits Occupancy; For BL Ring",
                    .full_desc =
                        "Number of Sbo 1 credits in use in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOPS_RSP_AFTER_DATA.LOCAL",
                    .encoding =
                        {
                            .code = 0xAULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data beat the Snoop Responses; Local Requests",
                    .full_desc =
                        "Counts the number of reads when the snoop was on the critical path to the data return.; This filter includes only requests coming from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOPS_RSP_AFTER_DATA.REMOTE",
                    .encoding =
                        {
                            .code = 0xAULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data beat the Snoop Responses; Remote Requests",
                    .full_desc =
                        "Counts the number of reads when the snoop was on the critical path to the data return.; This filter includes only requests coming from remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_CYCLES_NE.ALL",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles with Snoops Outstanding; All Requests",
                    .full_desc =
                        "Counts cycles when one or more snoops are outstanding.; Tracked for snoops from both local and remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_CYCLES_NE.LOCAL",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles with Snoops Outstanding; Local Requests",
                    .full_desc =
                        "Counts cycles when one or more snoops are outstanding.; This filter includes only requests coming from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_CYCLES_NE.REMOTE",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles with Snoops Outstanding; Remote Requests",
                    .full_desc =
                        "Counts cycles when one or more snoops are outstanding.; This filter includes only requests coming from remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_OCCUPANCY.LOCAL",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Snoops Outstanding Accumulator; Local Requests",
                    .full_desc = "Accumulates the occupancy of either the local HA tracker pool that have snoops pending in every cycle.    This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if an HT (HomeTracker) entry is available and this occupancy is decremented when all the snoop responses have returned.; This filter includes only requests coming from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_OCCUPANCY.REMOTE",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Snoops Outstanding Accumulator; Remote Requests",
                    .full_desc =
                        "Accumulates the occupancy of either the local HA tracker pool that have snoops pending in every cycle.    This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if an HT (HomeTracker) entry is available and this occupancy is decremented when all the snoop responses have returned.; This filter includes only requests coming from remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_RESP.RSPCNFLCT",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received; RSPCNFLCT*",
                    .full_desc =
                        "Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoops responses of RspConflict.  This is returned when a snoop finds an existing outstanding transaction in a remote caching agent when it CAMs that caching agent.  This triggers conflict resolution hardware.  This covers both RspCnflct and RspCnflctWbI.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_RESP.RSPI",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received; RspI",
                    .full_desc =
                        "Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoops responses of RspI.  RspI is returned when the remote cache does not have the data, or when the remote cache silently evicts data (such as when an RFO hits non-modified data).",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_RESP.RSPIFWD",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received; RspIFwd",
                    .full_desc =
                        "Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoop responses of RspIFwd.  This is returned when a remote caching agent forwards data and the requesting agent is able to acquire the data in E or M states.  This is commonly returned with RFO transactions.  It can be either a HitM or a HitFE.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_RESP.RSPS",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received; RspS",
                    .full_desc =
                        "Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoop responses of RspS.  RspS is returned when a remote cache has data but is not forwarding it.  It is a way to let the requesting socket know that it cannot allocate the data in E state.  No data is sent with S RspS.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_RESP.RSPSFWD",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received; RspSFwd",
                    .full_desc =
                        "Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for a snoop response of RspSFwd.  This is returned when a remote caching agent forwards data but holds on to its currently copy.  This is common for data and code reads that hit in a remote socket in E or F state.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_RESP.RSP_FWD_WB",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received; Rsp*Fwd*WB",
                    .full_desc =
                        "Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for a snoop response of Rsp*Fwd*WB.  This snoop response is only used in 4s systems.  It is used when a snoop HITM's in a remote caching agent and it directly forwards data to a requestor, and simultaneously returns data to the home to be written back to memory.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNOOP_RESP.RSP_WB",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received; Rsp*WB",
                    .full_desc =
                        "Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for a snoop response of RspIWB or RspSWB.  This is returned when a non-RFO request hits in M state.  Data and Code Reads can return either RspIWB or RspSWB depending on how the system has been configured.  InvItoE transactions will also return RspIWB because they must acquire ownership.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.OTHER",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; Other",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for all other snoop responses.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.RSPCNFLCT",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; RspCnflct",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for snoops responses of RspConflict.  This is returned when a snoop finds an existing outstanding transaction in a remote caching agent when it CAMs that caching agent.  This triggers conflict resolution hardware.  This covers both RspCnflct and RspCnflctWbI.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.RSPI",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; RspI",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for snoops responses of RspI.  RspI is returned when the remote cache does not have the data, or when the remote cache silently evicts data (such as when an RFO hits non-modified data).",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.RSPIFWD",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; RspIFwd",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for snoop responses of RspIFwd.  This is returned when a remote caching agent forwards data and the requesting agent is able to acquire the data in E or M states.  This is commonly returned with RFO transactions.  It can be either a HitM or a HitFE.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.RSPS",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; RspS",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for snoop responses of RspS.  RspS is returned when a remote cache has data but is not forwarding it.  It is a way to let the requesting socket know that it cannot allocate the data in E state.  No data is sent with S RspS.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.RSPSFWD",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; RspSFwd",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for a snoop response of RspSFwd.  This is returned when a remote caching agent forwards data but holds on to its currently copy.  This is common for data and code reads that hit in a remote socket in E or F state.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.RSPxFWDxWB",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; Rsp*FWD*WB",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for a snoop response of Rsp*Fwd*WB.  This snoop response is only used in 4s systems.  It is used when a snoop HITM's in a remote caching agent and it directly forwards data to a requestor, and simultaneously returns data to the home to be written back to memory.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_SNP_RESP_RECV_LOCAL.RSPxWB",
                    .encoding =
                        {
                            .code = 0x60ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses Received Local; Rsp*WB",
                    .full_desc =
                        "Number of snoop responses received for a Local  request; Filters for a snoop response of RspIWB or RspSWB.  This is returned when a non-RFO request hits in M state.  Data and Code Reads can return either RspIWB or RspSWB depending on how the system has been configured.  InvItoE transactions will also return RspIWB because they must acquire ownership.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_STALL_NO_SBO_CREDIT.SBO0_AD",
                    .encoding =
                        {
                            .code = 0x6CULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo0, AD Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_STALL_NO_SBO_CREDIT.SBO0_BL",
                    .encoding =
                        {
                            .code = 0x6CULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo0, BL Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_STALL_NO_SBO_CREDIT.SBO1_AD",
                    .encoding =
                        {
                            .code = 0x6CULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo1, AD Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_STALL_NO_SBO_CREDIT.SBO1_BL",
                    .encoding =
                        {
                            .code = 0x6CULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo1, BL Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION0",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 0",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION1",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 1",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION2",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 2",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 2",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION3",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 3",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 3",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION4",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 4",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 4",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION5",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 5",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 5",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION6",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 6",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 6",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G0.REGION7",
                    .encoding =
                        {
                            .code = 0x1BULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 0; TAD Region 7",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 7",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G1.REGION10",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 1; TAD Region 10",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 10",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G1.REGION11",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 1; TAD Region 11",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 11",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G1.REGION8",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 1; TAD Region 8",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 8",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TAD_REQUESTS_G1.REGION9",
                    .encoding =
                        {
                            .code = 0x1CULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA Requests to a TAD Region - Group 1; TAD Region 9",
                    .full_desc =
                        "Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 9",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_CYCLES_FULL.ALL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tracker Cycles Full; Cycles Completely Used",
                    .full_desc =
                        "Counts the number of cycles when the local HA tracker pool is completely used.  This can be used with edge detect to identify the number of situations when the pool became fully utilized.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, the system could be starved for RTIDs but not fill up the HA trackers.  HA trackers are allocated as soon as a request enters the HA and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; Counts the number of cycles when the HA tracker pool (HT) is completely used including reserved HT entries.  It will not return valid count when BT is disabled.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_CYCLES_FULL.GP",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Cycles Full; Cycles GP Completely Used",
                    .full_desc = "Counts the number of cycles when the local HA tracker pool is completely used.  This can be used with edge detect to identify the number of situations when the pool became fully utilized.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, the system could be starved for RTIDs but not fill up the HA trackers.  HA trackers are allocated as soon as a request enters the HA and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; Counts the number of cycles when the general purpose (GP) HA tracker pool (HT) is completely used.  It will not return valid count when BT is disabled.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_CYCLES_NE.ALL",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tracker Cycles Not Empty; All Requests",
                    .full_desc =
                        "Counts the number of cycles when the local HA tracker pool is not empty.  This can be used with edge detect to identify the number of situations when the pool became empty.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, this buffer could be completely empty, but there may still be credits in use by the CBos.  This stat can be used in conjunction with the occupancy accumulation stat in order to calculate average queue occupancy.  HA trackers are allocated as soon as a request enters the HA if an HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; Requests coming from both local and remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_CYCLES_NE.LOCAL",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tracker Cycles Not Empty; Local Requests",
                    .full_desc =
                        "Counts the number of cycles when the local HA tracker pool is not empty.  This can be used with edge detect to identify the number of situations when the pool became empty.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, this buffer could be completely empty, but there may still be credits in use by the CBos.  This stat can be used in conjunction with the occupancy accumulation stat in order to calculate average queue occupancy.  HA trackers are allocated as soon as a request enters the HA if an HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; This filter includes only requests coming from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_CYCLES_NE.REMOTE",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tracker Cycles Not Empty; Remote Requests",
                    .full_desc =
                        "Counts the number of cycles when the local HA tracker pool is not empty.  This can be used with edge detect to identify the number of situations when the pool became empty.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, this buffer could be completely empty, but there may still be credits in use by the CBos.  This stat can be used in conjunction with the occupancy accumulation stat in order to calculate average queue occupancy.  HA trackers are allocated as soon as a request enters the HA if an HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; This filter includes only requests coming from remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_OCCUPANCY.INVITOE_LOCAL",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Occupancy Accumulator; Local InvItoE Requests",
                    .full_desc =
                        "Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_OCCUPANCY.INVITOE_REMOTE",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Occupancy Accumulator; Remote InvItoE Requests",
                    .full_desc =
                        "Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_OCCUPANCY.READS_LOCAL",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Occupancy Accumulator; Local Read Requests",
                    .full_desc =
                        "Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_OCCUPANCY.READS_REMOTE",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Occupancy Accumulator; Remote Read Requests",
                    .full_desc =
                        "Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_OCCUPANCY.WRITES_LOCAL",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Occupancy Accumulator; Local Write Requests",
                    .full_desc =
                        "Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_OCCUPANCY.WRITES_REMOTE",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Tracker Occupancy Accumulator; Remote Write Requests",
                    .full_desc =
                        "Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_PENDING_OCCUPANCY.LOCAL",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data Pending Occupancy Accumulator; Local Requests",
                    .full_desc =
                        "Accumulates the number of transactions that have data from the memory controller until they get scheduled to the Egress.  This can be used to calculate the queuing latency for two things.  (1) If the system is waiting for snoops, this will increase.  (2) If the system can't schedule to the Egress because of either (a) Egress Credits or (b) QPI BL IGR credits for remote requests.; This filter includes only requests coming from the local socket.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TRACKER_PENDING_OCCUPANCY.REMOTE",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Data Pending Occupancy Accumulator; Remote Requests",
                    .full_desc =
                        "Accumulates the number of transactions that have data from the memory controller until they get scheduled to the Egress.  This can be used to calculate the queuing latency for two things.  (1) If the system is waiting for snoops, this will increase.  (2) If the system can't schedule to the Egress because of either (a) Egress Credits or (b) QPI BL IGR credits for remote requests.; This filter includes only requests coming from remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD.HOM",
                    .encoding =
                        {
                            .code = 0xFULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Outbound NDR Ring Transactions; Non-data Responses",
                    .full_desc =
                        "Counts the number of outbound transactions on the AD ring.  This can be filtered by the NDR and SNP message classes.  See the filter descriptions for more details.; Filter for outbound NDR transactions sent on the AD ring.  NDR stands for non-data response and is generally used for completions that do not include data.  AD NDR is used for transactions to remote sockets.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_CYCLES_FULL.ALL",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Full; All",
                    .full_desc =
                        "AD Egress Full; Cycles full from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_CYCLES_FULL.SCHED0",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Full; Scheduler 0",
                    .full_desc =
                        "AD Egress Full; Filter for cycles full  from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_CYCLES_FULL.SCHED1",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Full; Scheduler 1",
                    .full_desc =
                        "AD Egress Full; Filter for cycles full  from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_CYCLES_NE.ALL",
                    .encoding =
                        {
                            .code = 0x29ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Not Empty; All",
                    .full_desc =
                        "AD Egress Not Empty; Cycles full from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_CYCLES_NE.SCHED0",
                    .encoding =
                        {
                            .code = 0x29ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Not Empty; Scheduler 0",
                    .full_desc =
                        "AD Egress Not Empty; Filter for cycles not empty  from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_CYCLES_NE.SCHED1",
                    .encoding =
                        {
                            .code = 0x29ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Not Empty; Scheduler 1",
                    .full_desc =
                        "AD Egress Not Empty; Filter for cycles not empty from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_INSERTS.ALL",
                    .encoding =
                        {
                            .code = 0x27ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Allocations; All",
                    .full_desc =
                        "AD Egress Allocations; Allocations from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_INSERTS.SCHED0",
                    .encoding =
                        {
                            .code = 0x27ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Allocations; Scheduler 0",
                    .full_desc =
                        "AD Egress Allocations; Filter for allocations from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AD_INSERTS.SCHED1",
                    .encoding =
                        {
                            .code = 0x27ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AD Egress Allocations; Scheduler 1",
                    .full_desc =
                        "AD Egress Allocations; Filter for allocations from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_CYCLES_FULL.ALL",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Full; All",
                    .full_desc =
                        "AK Egress Full; Cycles full from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_CYCLES_FULL.SCHED0",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Full; Scheduler 0",
                    .full_desc =
                        "AK Egress Full; Filter for cycles full  from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_CYCLES_FULL.SCHED1",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Full; Scheduler 1",
                    .full_desc =
                        "AK Egress Full; Filter for cycles full  from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_CYCLES_NE.ALL",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Not Empty; All",
                    .full_desc =
                        "AK Egress Not Empty; Cycles full from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_CYCLES_NE.SCHED0",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Not Empty; Scheduler 0",
                    .full_desc =
                        "AK Egress Not Empty; Filter for cycles not empty  from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_CYCLES_NE.SCHED1",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Not Empty; Scheduler 1",
                    .full_desc =
                        "AK Egress Not Empty; Filter for cycles not empty from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_INSERTS.ALL",
                    .encoding =
                        {
                            .code = 0x2FULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Allocations; All",
                    .full_desc =
                        "AK Egress Allocations; Allocations from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_INSERTS.SCHED0",
                    .encoding =
                        {
                            .code = 0x2FULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Allocations; Scheduler 0",
                    .full_desc =
                        "AK Egress Allocations; Filter for allocations from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_AK_INSERTS.SCHED1",
                    .encoding =
                        {
                            .code = 0x2FULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Egress Allocations; Scheduler 1",
                    .full_desc =
                        "AK Egress Allocations; Filter for allocations from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL.DRS_CACHE",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Outbound DRS Ring Transactions to Cache; Data to Cache",
                    .full_desc =
                        "Counts the number of DRS messages sent out on the BL ring.   This can be filtered by the destination.; Filter for data being sent to the cache.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL.DRS_CORE",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Outbound DRS Ring Transactions to Cache; Data to Core",
                    .full_desc =
                        "Counts the number of DRS messages sent out on the BL ring.   This can be filtered by the destination.; Filter for data being sent directly to the requesting core.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL.DRS_QPI",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Outbound DRS Ring Transactions to Cache; Data to QPI",
                    .full_desc =
                        "Counts the number of DRS messages sent out on the BL ring.   This can be filtered by the destination.; Filter for data being sent to a remote socket over QPI.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_CYCLES_FULL.ALL",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Full; All",
                    .full_desc =
                        "BL Egress Full; Cycles full from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_CYCLES_FULL.SCHED0",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Full; Scheduler 0",
                    .full_desc =
                        "BL Egress Full; Filter for cycles full  from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_CYCLES_FULL.SCHED1",
                    .encoding =
                        {
                            .code = 0x36ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Full; Scheduler 1",
                    .full_desc =
                        "BL Egress Full; Filter for cycles full  from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_CYCLES_NE.ALL",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Not Empty; All",
                    .full_desc =
                        "BL Egress Not Empty; Cycles full from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_CYCLES_NE.SCHED0",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Not Empty; Scheduler 0",
                    .full_desc =
                        "BL Egress Not Empty; Filter for cycles not empty  from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_CYCLES_NE.SCHED1",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Not Empty; Scheduler 1",
                    .full_desc =
                        "BL Egress Not Empty; Filter for cycles not empty from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_INSERTS.ALL",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Allocations; All",
                    .full_desc =
                        "BL Egress Allocations; Allocations from both schedulers",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_INSERTS.SCHED0",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Allocations; Scheduler 0",
                    .full_desc =
                        "BL Egress Allocations; Filter for allocations from scheduler bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_BL_INSERTS.SCHED1",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Egress Allocations; Scheduler 1",
                    .full_desc =
                        "BL Egress Allocations; Filter for allocations from scheduler bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_STARVED.AK",
                    .encoding =
                        {
                            .code = 0x6DULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Injection Starvation; For AK Ring",
                    .full_desc =
                        "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_TxR_STARVED.BL",
                    .encoding =
                        {
                            .code = 0x6DULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Injection Starvation; For BL Ring",
                    .full_desc =
                        "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN0",
                    .encoding =
                        {
                            .code = 0x18ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Regular; Channel 0",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN1",
                    .encoding =
                        {
                            .code = 0x18ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Regular; Channel 1",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN2",
                    .encoding =
                        {
                            .code = 0x18ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Regular; Channel 2",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN3",
                    .encoding =
                        {
                            .code = 0x18ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Regular; Channel 3",
                    .full_desc =
                        "Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high bandwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN0",
                    .encoding =
                        {
                            .code = 0x19ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Special; Channel 0",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN1",
                    .encoding =
                        {
                            .code = 0x19ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Special; Channel 1",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN2",
                    .encoding =
                        {
                            .code = 0x19ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Special; Channel 2",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.",
                },
                {
                    .pmu_type = PmuType::uncore_ha,
                    .id = "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN3",
                    .encoding =
                        {
                            .code = 0x19ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "HA iMC CHN0 WPQ Credits Empty - Special; Channel 3",
                    .full_desc =
                        "Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ACT_COUNT.BYP",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Activate Count; Activate due to Write",
                    .full_desc =
                        "Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ACT_COUNT.RD",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Activate Count; Activate due to Read",
                    .full_desc =
                        "Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
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
                    .brief_desc = "DRAM Activate Count; Activate due to Write",
                    .full_desc =
                        "Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_BYP_CMDS.ACT",
                    .encoding =
                        {
                            .code = 0xA1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ACT command issued by 2 cycle bypass",
                    .full_desc = "ACT command issued by 2 cycle bypass",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_BYP_CMDS.CAS",
                    .encoding =
                        {
                            .code = 0xA1ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CAS command issued by 2 cycle bypass",
                    .full_desc = "CAS command issued by 2 cycle bypass",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_BYP_CMDS.PRE",
                    .encoding =
                        {
                            .code = 0xA1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "PRE command issued by 2 cycle bypass",
                    .full_desc = "PRE command issued by 2 cycle bypass",
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
                    .brief_desc =
                        "DRAM RD_CAS and WR_CAS Commands.; All DRAM WR_CAS (w/ and w/out auto-pre)",
                    .full_desc =
                        "DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM CAS commands issued on this channel.",
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
                        "DRAM RD_CAS and WR_CAS Commands.; All DRAM RD_CAS (w/ and w/out auto-pre)",
                    .full_desc =
                        "DRAM RD_CAS and WR_CAS Commands; Counts the total number or DRAM Read CAS commands issued on this channel.  This includes both regular RD CAS commands as well as those with implicit Precharge.  AutoPre is only used in systems that are using closed page policy.  We do not filter based on major mode, as RD_CAS is not issued during WMM (with the exception of underfills).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT.RD_RMM",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM RD_CAS and WR_CAS Commands.; Read CAS issued in RMM",
                    .full_desc = "DRAM RD_CAS and WR_CAS Commands",
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
                    .brief_desc =
                        "DRAM RD_CAS and WR_CAS Commands.; Underfill Read Issued",
                    .full_desc =
                        "DRAM RD_CAS and WR_CAS Commands; Counts the number of underfill reads that are issued by the memory controller.  This will generally be about the same as the number of partial writes, but may be slightly less because of partials hitting in the WPQ.  While it is possible for underfills to be issed in both WMM and RMM, this event counts both.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT.RD_WMM",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM RD_CAS and WR_CAS Commands.; Read CAS issued in WMM",
                    .full_desc = "DRAM RD_CAS and WR_CAS Commands",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_CAS_COUNT.WR_RMM",
                    .encoding =
                        {
                            .code = 0x4ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM RD_CAS and WR_CAS Commands.; DRAM WR_CAS (w/ and w/out auto-pre) in Read Major Mode",
                    .full_desc =
                        "DRAM RD_CAS and WR_CAS Commands; Counts the total number of Opportunistic DRAM Write CAS commands issued on this channel while in Read-Major-Mode.",
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
                        "DRAM RD_CAS and WR_CAS Commands.; DRAM WR_CAS (w/ and w/out auto-pre) in Write Major Mode",
                    .full_desc =
                        "DRAM RD_CAS and WR_CAS Commands; Counts the total number or DRAM Write CAS commands issued on this channel while in Write-Major-Mode.",
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
                    .full_desc = "DRAM Clockticks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_DCLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Clockticks",
                    .full_desc = "DRAM Clockticks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_DRAM_PRE_ALL",
                    .encoding =
                        {
                            .code = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "DRAM Precharge All Commands",
                    .full_desc =
                        "Counts the number of times that the precharge all command was sent.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_DRAM_REFRESH.HIGH",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of DRAM Refreshes Issued",
                    .full_desc = "Counts the number of refreshes issued.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_DRAM_REFRESH.PANIC",
                    .encoding =
                        {
                            .code = 0x5ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of DRAM Refreshes Issued",
                    .full_desc = "Counts the number of refreshes issued.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_ECC_CORRECTABLE_ERRORS",
                    .encoding =
                        {
                            .code = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "ECC Correctable Errors",
                    .full_desc =
                        "Counts the number of ECC errors detected and corrected by the iMC on this channel.  This counter is only useful with ECC DRAM devices.  This count will increment one time for each correction regardless of the number of bits corrected.  The iMC can correct up to 4 bit errors in independent channel mode and 8 bit errors in lockstep mode.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_MAJOR_MODES.ISOCH",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in a Major Mode; Isoch Major Mode",
                    .full_desc =
                        "Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; We group these two modes together so that we can use four counters to track each of the major modes at one time.  These major modes are used whenever there is an ISOCH txn in the memory controller.  In these mode, only ISOCH transactions are processed.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_MAJOR_MODES.PARTIAL",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in a Major Mode; Partial Major Mode",
                    .full_desc =
                        "Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; This major mode is used to drain starved underfill reads.  Regular reads and writes are blocked and only underfill reads will be processed.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_MAJOR_MODES.READ",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in a Major Mode; Read Major Mode",
                    .full_desc =
                        "Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; Read Major Mode is the default mode for the iMC, as reads are generally more critical to forward progress than writes.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_MAJOR_MODES.WRITE",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in a Major Mode; Write Major Mode",
                    .full_desc =
                        "Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; This mode is triggered when the WPQ hits high occupancy and causes writes to be higher priority than reads.  This can cause blips in the available read bandwidth in the system and temporarily increase read latencies in order to achieve better bus utilizations and higher bandwidth.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CHANNEL_DLLOFF",
                    .encoding =
                        {
                            .code = 0x84ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Channel DLLOFF Cycles",
                    .full_desc =
                        "Number of cycles when all the ranks in the channel are in CKE Slow (DLLOFF) mode.",
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
                        "Number of cycles when all the ranks in the channel are in PPD mode.  If IBT=off is enabled, then this can be used to count those cycles.  If it is not enabled, then this can count the number of cycles when that could have been taken advantage of.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK0",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK1",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK2",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK3",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK4",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK5",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK6",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CKE_CYCLES.RANK7",
                    .encoding =
                        {
                            .code = 0x83ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CKE_ON_CYCLES by Rank; DIMM ID",
                    .full_desc =
                        "Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_CRITICAL_THROTTLE_CYCLES",
                    .encoding =
                        {
                            .code = 0x86ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Critical Throttle Cycles",
                    .full_desc =
                        "Counts the number of cycles when the iMC is in critical thermal throttling.  When this happens, all traffic is blocked.  This should be rare unless something bad is going on in the platform.  There is no filtering by rank for this event.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_PCU_THROTTLING",
                    .encoding =
                        {
                            .code = 0x42ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_M_POWER_PCU_THROTTLING",
                    .full_desc = "UNC_M_POWER_PCU_THROTTLING",
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
                        "Counts the number of cycles when the iMC is in self-refresh and the iMC still has a clock.  This happens in some package C-states.  For example, the PCU may ask the iMC to enter self-refresh even though some of the cores are still processing.  One use of this is for Monroe technology.  Self-refresh is required during package C3 and C6, but there is no clock in the iMC at this time, so it is not possible to count these cases.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK0",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.; Thermal throttling is performed per DIMM.  We support 3 DIMMs per channel.  This ID allows us to filter by ID.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK1",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK2",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK3",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK4",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK5",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK6",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_POWER_THROTTLE_CYCLES.RANK7",
                    .encoding =
                        {
                            .code = 0x41ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Throttle Cycles for Rank 0; DIMM ID",
                    .full_desc =
                        "Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PREEMPTION.RD_PREEMPT_RD",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read Preemption Count; Read over Read Preemption",
                    .full_desc =
                        "Counts the number of times a read in the iMC preempts another read or write.  Generally reads to an open page are issued ahead of requests to closed pages.  This improves the page hit rate of the system.  However, high priority requests can cause pages of active requests to be closed in order to get them out.  This will reduce the latency of the high-priority request at the expense of lower bandwidth and increased overall average latency.; Filter for when a read preempts another read.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PREEMPTION.RD_PREEMPT_WR",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read Preemption Count; Read over Write Preemption",
                    .full_desc =
                        "Counts the number of times a read in the iMC preempts another read or write.  Generally reads to an open page are issued ahead of requests to closed pages.  This improves the page hit rate of the system.  However, high priority requests can cause pages of active requests to be closed in order to get them out.  This will reduce the latency of the high-priority request at the expense of lower bandwidth and increased overall average latency.; Filter for when a read preempts a write.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.BYP",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands.; Precharge due to bypass",
                    .full_desc =
                        "Counts the number of DRAM Precharge commands sent on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_PRE_COUNT.PAGE_CLOSE",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "DRAM Precharge commands.; Precharge due to timer expiration",
                    .full_desc =
                        "Counts the number of DRAM Precharge commands sent on this channel.; Counts the number of DRAM Precharge commands sent on this channel as a result of the page close counter expiring.  This does not include implicit precharge commands sent in auto-precharge mode.",
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
                    .brief_desc =
                        "DRAM Precharge commands.; Precharges due to page miss",
                    .full_desc =
                        "Counts the number of DRAM Precharge commands sent on this channel.; Counts the number of DRAM Precharge commands sent on this channel as a result of page misses.  This does not include explicit precharge commands sent with CAS commands in Auto-Precharge mode.  This does not include PRE commands sent as a result of the page close counter expiration.",
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
                        "DRAM Precharge commands.; Precharge due to read",
                    .full_desc =
                        "Counts the number of DRAM Precharge commands sent on this channel.",
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
                        "DRAM Precharge commands.; Precharge due to write",
                    .full_desc =
                        "Counts the number of DRAM Precharge commands sent on this channel.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_PRIO.HIGH",
                    .encoding =
                        {
                            .code = 0xA0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read CAS issued with HIGH priority",
                    .full_desc = "Read CAS issued with HIGH priority",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_PRIO.LOW",
                    .encoding =
                        {
                            .code = 0xA0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read CAS issued with LOW priority",
                    .full_desc = "Read CAS issued with LOW priority",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_PRIO.MED",
                    .encoding =
                        {
                            .code = 0xA0ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read CAS issued with MEDIUM priority",
                    .full_desc = "Read CAS issued with MEDIUM priority",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_PRIO.PANIC",
                    .encoding =
                        {
                            .code = 0xA0ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Read CAS issued with PANIC NON ISOCH priority (starved)",
                    .full_desc =
                        "Read CAS issued with PANIC NON ISOCH priority (starved)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; All Banks",
                    .full_desc = "RD_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK0",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 0",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK1",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 1",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK10",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 10",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK11",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 11",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK12",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 12",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK13",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 13",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK14",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 14",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK15",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 15",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK2",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 2",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK3",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 3",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK4",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 4",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK5",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 5",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK6",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 6",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK7",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 7",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK8",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 8",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANK9",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 0; Bank 9",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANKG0",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 0; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANKG1",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 0; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANKG2",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 0; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK0.BANKG3",
                    .encoding =
                        {
                            .code = 0xB0ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 0; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; All Banks",
                    .full_desc = "RD_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK0",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 0",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK1",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 1",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK10",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 10",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK11",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 11",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK12",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 12",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK13",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 13",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK14",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 14",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK15",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 15",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK2",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 2",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK3",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 3",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK4",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 4",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK5",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 5",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK6",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 6",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK7",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 7",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK8",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 8",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANK9",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 1; Bank 9",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANKG0",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 1; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANKG1",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 1; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANKG2",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 1; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK1.BANKG3",
                    .encoding =
                        {
                            .code = 0xB1ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 1; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK2.BANK0",
                    .encoding =
                        {
                            .code = 0xB2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 2; Bank 0",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; All Banks",
                    .full_desc = "RD_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK0",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 0",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK1",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 1",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK10",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 10",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK11",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 11",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK12",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 12",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK13",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 13",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK14",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 14",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK15",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 15",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK2",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 2",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK3",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 3",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK4",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 4",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK5",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 5",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK6",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 6",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK7",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 7",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK8",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 8",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANK9",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 4; Bank 9",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANKG0",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 4; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANKG1",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 4; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANKG2",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 4; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK4.BANKG3",
                    .encoding =
                        {
                            .code = 0xB4ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 4; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; All Banks",
                    .full_desc = "RD_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK0",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 0",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK1",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 1",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK10",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 10",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK11",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 11",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK12",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 12",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 12",
                },
            }};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents0));

constexpr std::
    array<StaticEventDef, 512>
        kFullOnlyEvents1{
            {
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK13",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 13",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK14",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 14",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK15",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 15",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK2",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 2",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK3",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 3",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK4",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 4",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK5",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 5",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK6",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 6",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK7",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 7",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK8",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 8",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANK9",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 5; Bank 9",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANKG0",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 5; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANKG1",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 5; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANKG2",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 5; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK5.BANKG3",
                    .encoding =
                        {
                            .code = 0xB5ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 5; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; All Banks",
                    .full_desc = "RD_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK0",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 0",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK1",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 1",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK10",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 10",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK11",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 11",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK12",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 12",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK13",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 13",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK14",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 14",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK15",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 15",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK2",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 2",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK3",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 3",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK4",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 4",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK5",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 5",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK6",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 6",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK7",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 7",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK8",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 8",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANK9",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 6; Bank 9",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANKG0",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 6; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANKG1",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 6; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANKG2",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 6; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK6.BANKG3",
                    .encoding =
                        {
                            .code = 0xB6ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 6; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; All Banks",
                    .full_desc = "RD_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK0",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 0",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK1",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 1",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK10",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 10",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK11",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 11",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK12",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 12",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK13",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 13",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK14",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 14",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK15",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 15",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK2",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 2",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK3",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 3",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK4",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 4",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK5",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 5",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK6",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 6",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK7",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 7",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK8",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 8",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANK9",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RD_CAS Access to Rank 7; Bank 9",
                    .full_desc = "RD_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANKG0",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 7; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANKG1",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 7; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANKG2",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 7; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RD_CAS_RANK7.BANKG3",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "RD_CAS Access to Rank 7; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "RD_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_RPQ_CYCLES_NE",
                    .encoding =
                        {
                            .code = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Read Pending Queue Not Empty",
                    .full_desc =
                        "Counts the number of cycles that the Read Pending Queue is not empty.  This can then be used to calculate the average occupancy (in conjunction with the Read Pending Queue Occupancy count).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This filter is to be used in conjunction with the occupancy filter so that one can correctly track the average occupancies for schedulable entries and scheduled requests.",
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
                        "Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_VMSE_MXB_WR_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x91ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VMSE MXB write buffer occupancy",
                    .full_desc = "VMSE MXB write buffer occupancy",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_VMSE_WR_PUSH.RMM",
                    .encoding =
                        {
                            .code = 0x90ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "VMSE WR PUSH issued; VMSE write PUSH issued in RMM",
                    .full_desc =
                        "VMSE WR PUSH issued; VMSE write PUSH issued in RMM",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_VMSE_WR_PUSH.WMM",
                    .encoding =
                        {
                            .code = 0x90ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "VMSE WR PUSH issued; VMSE write PUSH issued in WMM",
                    .full_desc =
                        "VMSE WR PUSH issued; VMSE write PUSH issued in WMM",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WMM_TO_RMM.LOW_THRESH",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Transition from WMM to RMM because of low threshold; Transition from WMM to RMM because of starve counter",
                    .full_desc =
                        "Transition from WMM to RMM because of low threshold; Transition from WMM to RMM because of starve counter",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WMM_TO_RMM.STARVE",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Transition from WMM to RMM because of low threshold",
                    .full_desc =
                        "Transition from WMM to RMM because of low threshold",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WMM_TO_RMM.VMSE_RETRY",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Transition from WMM to RMM because of low threshold",
                    .full_desc =
                        "Transition from WMM to RMM because of low threshold",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_CYCLES_FULL",
                    .encoding =
                        {
                            .code = 0x22ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Full Cycles",
                    .full_desc =
                        "Counts the number of cycles when the Write Pending Queue is full.  When the WPQ is full, the HA will not be able to issue any additional read requests into the iMC.  This count should be similar count in the HA which tracks the number of cycles that the HA has no WPQ credits, just somewhat smaller to account for the credit return overhead.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_CYCLES_NE",
                    .encoding =
                        {
                            .code = 0x21ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue Not Empty",
                    .full_desc =
                        "Counts the number of cycles that the Write Pending Queue is not empty.  This can then be used to calculate the average queue occupancy (in conjunction with the WPQ Occupancy Accumulation count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_READ_HIT",
                    .encoding =
                        {
                            .code = 0x23ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue CAM Match",
                    .full_desc =
                        "Counts the number of times a request hits in the WPQ (write-pending queue).  The iMC allows writes and reads to pass up other writes to different addresses.  Before a read or a write is issued, it will first CAM the WPQ to see if there is a write pending to that address.  When reads hit, they are able to directly pull their data from the WPQ instead of going to memory.  Writes that hit will overwrite the existing data.  Partial writes that hit will not need to do underfill reads and will simply update their relevant sections.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WPQ_WRITE_HIT",
                    .encoding =
                        {
                            .code = 0x24ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Write Pending Queue CAM Match",
                    .full_desc =
                        "Counts the number of times a request hits in the WPQ (write-pending queue).  The iMC allows writes and reads to pass up other writes to different addresses.  Before a read or a write is issued, it will first CAM the WPQ to see if there is a write pending to that address.  When reads hit, they are able to directly pull their data from the WPQ instead of going to memory.  Writes that hit will overwrite the existing data.  Partial writes that hit will not need to do underfill reads and will simply update their relevant sections.",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WRONG_MM",
                    .encoding =
                        {
                            .code = 0xC1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Not getting the requested Major Mode",
                    .full_desc = "Not getting the requested Major Mode",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; All Banks",
                    .full_desc = "WR_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK0",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 0",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK1",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 1",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK10",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 10",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK11",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 11",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK12",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 12",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK13",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 13",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK14",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 14",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK15",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 15",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK2",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 2",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK3",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 3",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK4",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 4",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK5",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 5",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK6",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 6",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK7",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 7",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK8",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 8",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANK9",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 0; Bank 9",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANKG0",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 0; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANKG1",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 0; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANKG2",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 0; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK0.BANKG3",
                    .encoding =
                        {
                            .code = 0xB8ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 0; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; All Banks",
                    .full_desc = "WR_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK0",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 0",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK1",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 1",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK10",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 10",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK11",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 11",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK12",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 12",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK13",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 13",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK14",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 14",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK15",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 15",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK2",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 2",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK3",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 3",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK4",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 4",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK5",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 5",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK6",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 6",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK7",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 7",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK8",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 8",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANK9",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 1; Bank 9",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANKG0",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 1; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANKG1",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 1; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANKG2",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 1; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK1.BANKG3",
                    .encoding =
                        {
                            .code = 0xB9ULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 1; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; All Banks",
                    .full_desc = "WR_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK0",
                    .encoding =
                        {
                            .code = 0xBCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 0",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK1",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 1",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK10",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 10",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK11",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 11",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK12",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 12",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK13",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 13",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK14",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 14",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK15",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 15",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK2",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 2",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK3",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 3",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK4",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 4",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK5",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 5",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK6",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 6",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK7",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 7",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK8",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 8",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANK9",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 4; Bank 9",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANKG0",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 4; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANKG1",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 4; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANKG2",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 4; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK4.BANKG3",
                    .encoding =
                        {
                            .code = 0xBCULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 4; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; All Banks",
                    .full_desc = "WR_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK0",
                    .encoding =
                        {
                            .code = 0xBDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 0",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK1",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 1",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK10",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 10",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK11",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 11",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK12",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 12",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK13",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 13",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK14",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 14",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK15",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 15",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK2",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 2",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK3",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 3",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK4",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 4",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK5",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 5",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK6",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 6",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK7",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 7",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK8",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 8",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANK9",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 5; Bank 9",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANKG0",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 5; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANKG1",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 5; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANKG2",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 5; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK5.BANKG3",
                    .encoding =
                        {
                            .code = 0xBDULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 5; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; All Banks",
                    .full_desc = "WR_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK0",
                    .encoding =
                        {
                            .code = 0xBEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 0",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK1",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 1",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK10",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 10",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK11",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 11",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK12",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 12",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK13",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 13",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK14",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 14",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK15",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 15",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK2",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 2",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK3",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 3",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK4",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 4",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK5",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 5",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK6",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 6",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK7",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 7",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK8",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 8",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANK9",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 6; Bank 9",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANKG0",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 6; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANKG1",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 6; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANKG2",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 6; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK6.BANKG3",
                    .encoding =
                        {
                            .code = 0xBEULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 6; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.ALLBANKS",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; All Banks",
                    .full_desc = "WR_CAS Access to Rank 0 : All Banks",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK0",
                    .encoding =
                        {
                            .code = 0xBFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 0",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 0",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK1",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 1",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 1",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK10",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 10",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 10",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK11",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 11",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 11",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK12",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 12",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 12",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK13",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 13",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 13",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK14",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 14",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 14",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK15",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 15",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 15",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK2",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 2",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 2",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK3",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 3",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 3",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK4",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 4",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 4",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK5",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 5",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 5",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK6",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 6",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 6",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK7",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 7",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 7",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK8",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 8",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 8",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANK9",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "WR_CAS Access to Rank 7; Bank 9",
                    .full_desc = "WR_CAS Access to Rank 0 : Bank 9",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANKG0",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x11ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 7; Bank Group 0 (Banks 0-3)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 0 (Banks 0-3)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANKG1",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 7; Bank Group 1 (Banks 4-7)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 1 (Banks 4-7)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANKG2",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x13ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 7; Bank Group 2 (Banks 8-11)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 2 (Banks 8-11)",
                },
                {
                    .pmu_type = PmuType::uncore_imc,
                    .id = "UNC_M_WR_CAS_RANK7.BANKG3",
                    .encoding =
                        {
                            .code = 0xBFULL,
                            .umask = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "WR_CAS Access to Rank 7; Bank Group 3 (Banks 12-15)",
                    .full_desc =
                        "WR_CAS Access to Rank 0 : Bank Group 3 (Banks 12-15)",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_CACHE_TOTAL_OCCUPANCY.ANY",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Total Write Cache Occupancy; Any Source",
                    .full_desc =
                        "Accumulates the number of reads and writes that are outstanding in the uncore in each cycle.  This is effectively the sum of the READ_OCCUPANCY and WRITE_OCCUPANCY events.; Tracks all requests from any source port.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_CACHE_TOTAL_OCCUPANCY.SOURCE",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Total Write Cache Occupancy; Select Source",
                    .full_desc =
                        "Accumulates the number of reads and writes that are outstanding in the uncore in each cycle.  This is effectively the sum of the READ_OCCUPANCY and WRITE_OCCUPANCY events.; Tracks only those requests that come from the port specified in the IRP_PmonFilter.OrderingQ register.  This register allows one to select one specific queue.  It is not possible to monitor multiple queues at a time.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Clocks in the IRP",
                    .full_desc = "Number of clocks in the IRP.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.CLFLUSH",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; CLFlush",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.CRD",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; CRd",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.DRD",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; DRd",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.PCIDCAHINT",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; PCIDCAHin5t",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.PCIRDCUR",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; PCIRdCur",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.PCITOM",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; PCIItoM",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.RFO",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; RFO",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_COHERENT_OPS.WBMTOI",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Coherent Ops; WbMtoI",
                    .full_desc =
                        "Counts the number of coherency related operations serviced by the IRP",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.2ND_ATOMIC_INSERT",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 0; Cache Inserts of Atomic Transactions as Secondary",
                    .full_desc =
                        "Counts Timeouts - Set 0 : Cache Inserts of Atomic Transactions as Secondary",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.2ND_RD_INSERT",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 0; Cache Inserts of Read Transactions as Secondary",
                    .full_desc =
                        "Counts Timeouts - Set 0 : Cache Inserts of Read Transactions as Secondary",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.2ND_WR_INSERT",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 0; Cache Inserts of Write Transactions as Secondary",
                    .full_desc =
                        "Counts Timeouts - Set 0 : Cache Inserts of Write Transactions as Secondary",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.FAST_REJ",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 0; Fastpath Rejects",
                    .full_desc = "Counts Timeouts - Set 0 : Fastpath Rejects",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.FAST_REQ",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 0; Fastpath Requests",
                    .full_desc = "Counts Timeouts - Set 0 : Fastpath Requests",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.FAST_XFER",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 0; Fastpath Transfers From Primary to Secondary",
                    .full_desc =
                        "Counts Timeouts - Set 0 : Fastpath Transfers From Primary to Secondary",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.PF_ACK_HINT",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 0; Prefetch Ack Hints From Primary to Secondary",
                    .full_desc =
                        "Counts Timeouts - Set 0 : Prefetch Ack Hints From Primary to Secondary",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC0.PF_TIMEOUT",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 0; Prefetch TimeOut",
                    .full_desc =
                        "Indicates the fetch for a previous prefetch wasn't accepted by the prefetch.   This happens in the case of a prefetch TimeOut",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.DATA_THROTTLE",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 1; Data Throttled",
                    .full_desc = "IRP throttled switch data",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.LOST_FWD",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 1",
                    .full_desc =
                        "Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.SEC_RCVD_INVLD",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 1; Received Invalid",
                    .full_desc =
                        "Secondary received a transfer that did not have sufficient MESI state",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.SEC_RCVD_VLD",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Misc Events - Set 1; Received Valid",
                    .full_desc =
                        "Secondary received a transfer that did have sufficient MESI state",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.SLOW_E",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 1; Slow Transfer of E Line",
                    .full_desc =
                        "Secondary received a transfer that did have sufficient MESI state",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.SLOW_I",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 1; Slow Transfer of I Line",
                    .full_desc =
                        "Snoop took cacheline ownership before write from data was committed.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.SLOW_M",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 1; Slow Transfer of M Line",
                    .full_desc =
                        "Snoop took cacheline ownership before write from data was committed.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_MISC1.SLOW_S",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Misc Events - Set 1; Slow Transfer of S Line",
                    .full_desc =
                        "Secondary received a transfer that did not have sufficient MESI state",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_AK_INSERTS",
                    .encoding =
                        {
                            .code = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ingress Occupancy",
                    .full_desc =
                        "Counts the number of allocations into the AK Ingress.  This queue is where the IRP receives responses from R2PCIe (the ring).",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_DRS_CYCLES_FULL",
                    .encoding =
                        {
                            .code = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_I_RxR_BL_DRS_CYCLES_FULL",
                    .full_desc =
                        "Counts the number of cycles when the BL Ingress is full.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_DRS_INSERTS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ingress Occupancy - DRS",
                    .full_desc =
                        "Counts the number of allocations into the BL Ingress.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_DRS_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_I_RxR_BL_DRS_OCCUPANCY",
                    .full_desc =
                        "Accumulates the occupancy of the BL Ingress in each cycles.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_NCB_CYCLES_FULL",
                    .encoding =
                        {
                            .code = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_I_RxR_BL_NCB_CYCLES_FULL",
                    .full_desc =
                        "Counts the number of cycles when the BL Ingress is full.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_NCB_INSERTS",
                    .encoding =
                        {
                            .code = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ingress Occupancy - NCB",
                    .full_desc =
                        "Counts the number of allocations into the BL Ingress.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_NCB_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_I_RxR_BL_NCB_OCCUPANCY",
                    .full_desc =
                        "Accumulates the occupancy of the BL Ingress in each cycles.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_NCS_CYCLES_FULL",
                    .encoding =
                        {
                            .code = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_I_RxR_BL_NCS_CYCLES_FULL",
                    .full_desc =
                        "Counts the number of cycles when the BL Ingress is full.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_NCS_INSERTS",
                    .encoding =
                        {
                            .code = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "BL Ingress Occupancy - NCS",
                    .full_desc =
                        "Counts the number of allocations into the BL Ingress.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_RxR_BL_NCS_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_I_RxR_BL_NCS_OCCUPANCY",
                    .full_desc =
                        "Accumulates the occupancy of the BL Ingress in each cycles.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requests as well as outbound MMIO writes.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.HIT_ES",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses; Hit E or S",
                    .full_desc = "Snoop Responses : Hit E or S",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.HIT_I",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses; Hit I",
                    .full_desc = "Snoop Responses : Hit I",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.HIT_M",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses; Hit M",
                    .full_desc = "Snoop Responses : Hit M",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.MISS",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses; Miss",
                    .full_desc = "Snoop Responses : Miss",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.SNPCODE",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses; SnpCode",
                    .full_desc = "Snoop Responses : SnpCode",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.SNPDATA",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses; SnpData",
                    .full_desc = "Snoop Responses : SnpData",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_SNOOP_RESP.SNPINV",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Snoop Responses; SnpInv",
                    .full_desc = "Snoop Responses : SnpInv",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.ATOMIC",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Inbound Transaction Count; Atomic",
                    .full_desc =
                        "Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of atomic transactions",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.ORDERINGQ",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Inbound Transaction Count; Select Source",
                    .full_desc =
                        "Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks only those requests that come from the port specified in the IRP_PmonFilter.OrderingQ register.  This register allows one to select one specific queue.  It is not possible to monitor multiple queues at a time.  If this bit is not set, then requests from all sources will be counted.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.OTHER",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Inbound Transaction Count; Other",
                    .full_desc =
                        "Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of 'other' kinds of transactions.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.RD_PREF",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Inbound Transaction Count; Read Prefetches",
                    .full_desc =
                        "Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of read prefetches.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.READS",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Inbound Transaction Count; Reads",
                    .full_desc =
                        "Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks only read requests (not including read prefetches).",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.WRITES",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Inbound Transaction Count; Writes",
                    .full_desc =
                        "Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks only write requests.  Each write request should have a prefetch, so there is no need to explicitly track these requests.  For writes that are tickled and have to retry, the counter will be incremented for each retry.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TRANSACTIONS.WR_PREF",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Inbound Transaction Count; Write Prefetches",
                    .full_desc =
                        "Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of write prefetches.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TxR_AD_STALL_CREDIT_CYCLES",
                    .encoding =
                        {
                            .code = 0x18ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "No AD Egress Credit Stalls",
                    .full_desc =
                        "Counts the number times when it is not possible to issue a request to the R2PCIe because there are no AD Egress Credits available.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TxR_BL_STALL_CREDIT_CYCLES",
                    .encoding =
                        {
                            .code = 0x19ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "No BL Egress Credit Stalls",
                    .full_desc =
                        "Counts the number times when it is not possible to issue data to the R2PCIe because there are no BL Egress Credits available.",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TxR_DATA_INSERTS_NCB",
                    .encoding =
                        {
                            .code = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Outbound Read Requests",
                    .full_desc =
                        "Counts the number of requests issued to the switch (towards the devices).",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TxR_DATA_INSERTS_NCS",
                    .encoding =
                        {
                            .code = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Outbound Read Requests",
                    .full_desc =
                        "Counts the number of requests issued to the switch (towards the devices).",
                },
                {
                    .pmu_type = PmuType::uncore_irp,
                    .id = "UNC_I_TxR_REQUEST_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Outbound Request Queue Occupancy",
                    .full_desc =
                        "Accumulates the number of outstanding outbound requests from the IRP to the switch (towards the devices).  This can be used in conjunction with the allocations event in order to calculate average latency of outbound requests.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "pclk Cycles",
                    .full_desc =
                        "The PCU runs off a fixed 800 MHz clock.  This event counts the number of pclk cycles measured while the counter was enabled.  The pclk, like the Memory Controller's dclk, counts at a constant rate making it a good measure of actual wall time.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE0_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x60ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE10_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x6AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE11_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x6BULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE12_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x6CULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE13_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x6DULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE14_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x6EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE15_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x6FULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE16_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x70ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE17_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x71ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE1_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x61ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE2_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x62ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE3_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x63ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE4_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x64ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE5_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x65ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE6_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x66ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE7_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x67ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE8_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x68ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_CORE9_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x69ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions.  There is one event per core.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE0",
                    .encoding =
                        {
                            .code = 0x30ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE1",
                    .encoding =
                        {
                            .code = 0x31ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE10",
                    .encoding =
                        {
                            .code = 0x3AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE11",
                    .encoding =
                        {
                            .code = 0x3BULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE12",
                    .encoding =
                        {
                            .code = 0x3CULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE13",
                    .encoding =
                        {
                            .code = 0x3DULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE14",
                    .encoding =
                        {
                            .code = 0x3EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE15",
                    .encoding =
                        {
                            .code = 0x3FULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE16",
                    .encoding =
                        {
                            .code = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE17",
                    .encoding =
                        {
                            .code = 0x41ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE2",
                    .encoding =
                        {
                            .code = 0x32ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE3",
                    .encoding =
                        {
                            .code = 0x33ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE4",
                    .encoding =
                        {
                            .code = 0x34ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE5",
                    .encoding =
                        {
                            .code = 0x35ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE6",
                    .encoding =
                        {
                            .code = 0x36ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE7",
                    .encoding =
                        {
                            .code = 0x37ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE8",
                    .encoding =
                        {
                            .code = 0x38ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_DEMOTIONS_CORE9",
                    .encoding =
                        {
                            .code = 0x39ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Core C State Demotions",
                    .full_desc =
                        "Counts the number of times when a configurable cores had a C-state demotion",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_BAND0_CYCLES",
                    .encoding =
                        {
                            .code = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Frequency Residency",
                    .full_desc =
                        "Counts the number of cycles that the uncore was running at a frequency greater than or equal to the frequency that is configured in the filter.  One can use all four counters with this event, so it is possible to track up to 4 configurable bands.  One can use edge detect in conjunction with this event to track the number of times that we transitioned into a frequency greater than or equal to the configurable frequency. One can also use inversion to track cycles when we were less than the configured frequency.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_BAND1_CYCLES",
                    .encoding =
                        {
                            .code = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Frequency Residency",
                    .full_desc =
                        "Counts the number of cycles that the uncore was running at a frequency greater than or equal to the frequency that is configured in the filter.  One can use all four counters with this event, so it is possible to track up to 4 configurable bands.  One can use edge detect in conjunction with this event to track the number of times that we transitioned into a frequency greater than or equal to the configurable frequency. One can also use inversion to track cycles when we were less than the configured frequency.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_BAND2_CYCLES",
                    .encoding =
                        {
                            .code = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Frequency Residency",
                    .full_desc =
                        "Counts the number of cycles that the uncore was running at a frequency greater than or equal to the frequency that is configured in the filter.  One can use all four counters with this event, so it is possible to track up to 4 configurable bands.  One can use edge detect in conjunction with this event to track the number of times that we transitioned into a frequency greater than or equal to the configurable frequency. One can also use inversion to track cycles when we were less than the configured frequency.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_BAND3_CYCLES",
                    .encoding =
                        {
                            .code = 0xEULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Frequency Residency",
                    .full_desc =
                        "Counts the number of cycles that the uncore was running at a frequency greater than or equal to the frequency that is configured in the filter.  One can use all four counters with this event, so it is possible to track up to 4 configurable bands.  One can use edge detect in conjunction with this event to track the number of times that we transitioned into a frequency greater than or equal to the configurable frequency. One can also use inversion to track cycles when we were less than the configured frequency.",
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
                        "Counts the number of cycles when thermal conditions are the upper limit on frequency.  This is related to the THERMAL_THROTTLE CYCLES_ABOVE_TEMP event, which always counts cycles when we are above the thermal temperature.  This event (STRONGEST_UPPER_LIMIT) is sampled at the output of the algorithm that determines the actual frequency, while THERMAL_THROTTLE looks at the input.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_MAX_OS_CYCLES",
                    .encoding =
                        {
                            .code = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "OS Strongest Upper Limit Cycles",
                    .full_desc =
                        "Counts the number of cycles when the OS is the upper limit on frequency.",
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
                        "Counts the number of cycles when power is the upper limit on frequency.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_FREQ_MIN_IO_P_CYCLES",
                    .encoding =
                        {
                            .code = 0x73ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "IO P Limit Strongest Lower Limit Cycles",
                    .full_desc =
                        "Counts the number of cycles when IO P Limit is preventing us from dropping the frequency lower.  This algorithm monitors the needs to the IO subsystem on both local and remote sockets and will maintain a frequency high enough to maintain good IO BW.  This is necessary for when all the IA cores on a socket are idle but a user still would like to maintain high IO Bandwidth.",
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
                        "Counts the number of cycles when the system is changing frequency.  This can not be filtered by thread ID.  One can also use it with the occupancy counter that monitors number of threads in C0 to estimate the performance impact that frequency transitions had on the system.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_MEMORY_PHASE_SHEDDING_CYCLES",
                    .encoding =
                        {
                            .code = 0x2FULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Memory Phase Shedding Cycles",
                    .full_desc =
                        "Counts the number of cycles that the PCU has triggered memory phase shedding.  This is a mode that can be run in the iMC physicals that saves power at the expense of additional latency.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PKG_RESIDENCY_C0_CYCLES",
                    .encoding =
                        {
                            .code = 0x2AULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Package C State Residency - C0",
                    .full_desc =
                        "Counts the number of cycles when the package was in C0.  This event can be used in conjunction with edge detect to count C0 entrances (or exits using invert).  Residency events do not include transition times.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PKG_RESIDENCY_C1E_CYCLES",
                    .encoding =
                        {
                            .code = 0x4EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Package C State Residency - C1E",
                    .full_desc =
                        "Counts the number of cycles when the package was in C1E.  This event can be used in conjunction with edge detect to count C1E entrances (or exits using invert).  Residency events do not include transition times.",
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
                        "Counts the number of cycles when the package was in C2E.  This event can be used in conjunction with edge detect to count C2E entrances (or exits using invert).  Residency events do not include transition times.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PKG_RESIDENCY_C3_CYCLES",
                    .encoding =
                        {
                            .code = 0x2CULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Package C State Residency - C3",
                    .full_desc =
                        "Counts the number of cycles when the package was in C3.  This event can be used in conjunction with edge detect to count C3 entrances (or exits using invert).  Residency events do not include transition times.",
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
                        "Counts the number of cycles when the package was in C6.  This event can be used in conjunction with edge detect to count C6 entrances (or exits using invert).  Residency events do not include transition times.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_PKG_RESIDENCY_C7_CYCLES",
                    .encoding =
                        {
                            .code = 0x2EULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Package C7 State Residency",
                    .full_desc =
                        "Counts the number of cycles when the package was in C7.  This event can be used in conjunction with edge detect to count C7 entrances (or exits using invert).  Residency events do not include transition times.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_POWER_STATE_OCCUPANCY.CORES_C0",
                    .encoding =
                        {
                            .code = 0x80ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of cores in C-State; C0 and C1",
                    .full_desc =
                        "This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_POWER_STATE_OCCUPANCY.CORES_C3",
                    .encoding =
                        {
                            .code = 0x80ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of cores in C-State; C3",
                    .full_desc =
                        "This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_POWER_STATE_OCCUPANCY.CORES_C6",
                    .encoding =
                        {
                            .code = 0x80ULL,
                            .umask = 0xC0ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of cores in C-State; C6 and C7",
                    .full_desc =
                        "This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.",
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
                        "Counts the number of cycles that we are in external PROCHOT mode.  This mode is triggered when a sensor off the die determines that something off-die (like DRAM) is too hot and must throttle to avoid damaging the chip.",
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
                        "Counts the number of cycles that we are in Internal PROCHOT mode.  This mode is triggered when a sensor on the die determines that we are too hot and must throttle to avoid damaging the chip.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_TOTAL_TRANSITION_CYCLES",
                    .encoding =
                        {
                            .code = 0x72ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Total Core C State Transition Cycles",
                    .full_desc =
                        "Number of cycles spent performing core C state transitions across all cores.",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_UFS_TRANSITIONS_NO_CHANGE",
                    .encoding =
                        {
                            .code = 0x79ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_P_UFS_TRANSITIONS_NO_CHANGE",
                    .full_desc =
                        "Ring GV with same final and initial frequency",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_UFS_TRANSITIONS_RING_GV",
                    .encoding =
                        {
                            .code = 0x79ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_P_UFS_TRANSITIONS_RING_GV",
                    .full_desc =
                        "Ring GV with same final and initial frequency",
                },
                {
                    .pmu_type = PmuType::uncore_pcu,
                    .id = "UNC_P_VR_HOT_CYCLES",
                    .encoding =
                        {
                            .code = 0x42ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VR Hot",
                    .full_desc =
                        "VR Hot : Number of cycles that a CPU SVID VR is hot.  Does not cover DRAM VRs",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x14ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of qfclks",
                    .full_desc =
                        "Counts the number of clocks in the QPI LL.  This clock runs at 1/4th the GT/s speed of the QPI link.  For example, a 4GT/s link will have qfclk or 1GHz.  HSX does not support dynamic link speeds, so this frequency is fixed.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_CTO_COUNT",
                    .encoding =
                        {
                            .code = 0x38ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Count of CTO Events",
                    .full_desc =
                        "Counts the number of CTO (cluster trigger outs) events that were asserted across the two slots.  If both slots trigger in a given cycle, the event will increment by 2.  You can use edge detect to count the number of cases when both events triggered.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.FAILURE_CREDITS",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Direct 2 Core Spawning; Spawn Failure - Egress Credits",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn failed because there were not enough Egress credits.  Had there been enough credits, the spawn would have worked as the RBT bit was set and the RBT tag matched.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.FAILURE_CREDITS_MISS",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Direct 2 Core Spawning; Spawn Failure - Egress and RBT Miss",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn failed because the RBT tag did not match and there weren't enough Egress credits.   The valid bit was set.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.FAILURE_CREDITS_RBT",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Direct 2 Core Spawning; Spawn Failure - Egress and RBT Invalid",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn failed because there were not enough Egress credits AND the RBT bit was not set, but the RBT tag matched.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.FAILURE_CREDITS_RBT_MISS",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Direct 2 Core Spawning; Spawn Failure - Egress and RBT Miss, Invalid",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn failed because the RBT tag did not match, the valid bit was not set and there weren't enough Egress credits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.FAILURE_MISS",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Direct 2 Core Spawning; Spawn Failure - RBT Miss",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn failed because the RBT tag did not match although the valid bit was set and there were enough Egress credits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.FAILURE_RBT_HIT",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Direct 2 Core Spawning; Spawn Failure - RBT Invalid",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn failed because the route-back table (RBT) specified that the transaction should not trigger a direct2core transaction.  This is common for IO transactions.  There were enough Egress credits and the RBT tag matched but the valid bit was not set.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.FAILURE_RBT_MISS",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Direct 2 Core Spawning; Spawn Failure - RBT Miss and Invalid",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn failed because the RBT tag did not match and the valid bit was not set although there were enough Egress credits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_DIRECT2CORE.SUCCESS_RBT_HIT",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Direct 2 Core Spawning; Spawn Success",
                    .full_desc =
                        "Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.; The spawn was successful.  There were sufficient credits, the RBT valid bit was set and there was an RBT tag match.  The message was marked to spawn direct2core.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_L1_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0x12ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in L1",
                    .full_desc =
                        "Number of QPI qfclk cycles spent in L1 power mode.  L1 is a mode that totally shuts down a QPI link.  Use edge detect to count the number of instances when the QPI link entered L1.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another. Because L1 totally shuts down the link, it takes a good amount of time to exit this mode.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL0P_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in L0p",
                    .full_desc =
                        "Number of QPI qfclk cycles spent in L0p power mode.  L0p is a mode where we disable 1/2 of the QPI lanes, decreasing our bandwidth in order to save power.  It increases snoop and data transfer latencies and decreases overall bandwidth.  This mode can be very useful in NUMA optimized workloads that largely only utilize QPI for snoops and their responses.  Use edge detect to count the number of instances when the QPI link entered L0p.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL0_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in L0",
                    .full_desc =
                        "Number of QPI qfclk cycles spent in L0 power mode in the Link Layer.  L0 is the default mode which provides the highest performance with the most power.  Use edge detect to count the number of instances that the link entered L0.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another.  The phy layer  sometimes leaves L0 for training, which will not be captured by this event.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_BYPASSED",
                    .encoding =
                        {
                            .code = 0x9ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Bypassed",
                    .full_desc =
                        "Counts the number of times that an incoming flit was able to bypass the flit buffer and pass directly across the BGF and into the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of flits transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CRC_ERRORS.LINK_INIT",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CRC Errors Detected; LinkInit",
                    .full_desc =
                        "Number of CRC errors detected in the QPI Agent.  Each QPI flit incorporates 8 bits of CRC for error detection.  This counts the number of flits where the CRC was able to detect an error.  After an error has been detected, the QPI agent will send a request to the transmitting socket to resend the flit (as well as any flits that came after it).; CRC errors detected during link initialization.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CRC_ERRORS.NORMAL_OP",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "CRC Errors Detected; Normal Operations",
                    .full_desc =
                        "Number of CRC errors detected in the QPI Agent.  Each QPI flit incorporates 8 bits of CRC for error detection.  This counts the number of flits where the CRC was able to detect an error.  After an error has been detected, the QPI agent will send a request to the transmitting socket to resend the flit (as well as any flits that came after it).; CRC errors detected during normal operation.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN0.DRS",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN0 Credit Consumed; DRS",
                    .full_desc =
                        "Counts the number of times that an RxQ VN0 credit was consumed (i.e. message uses a VN0 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN0 credit for the DRS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN0.HOM",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN0 Credit Consumed; HOM",
                    .full_desc =
                        "Counts the number of times that an RxQ VN0 credit was consumed (i.e. message uses a VN0 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN0 credit for the HOM message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN0.NCB",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN0 Credit Consumed; NCB",
                    .full_desc =
                        "Counts the number of times that an RxQ VN0 credit was consumed (i.e. message uses a VN0 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN0 credit for the NCB message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN0.NCS",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN0 Credit Consumed; NCS",
                    .full_desc =
                        "Counts the number of times that an RxQ VN0 credit was consumed (i.e. message uses a VN0 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN0 credit for the NCS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN0.NDR",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN0 Credit Consumed; NDR",
                    .full_desc =
                        "Counts the number of times that an RxQ VN0 credit was consumed (i.e. message uses a VN0 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN0 credit for the NDR message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN0.SNP",
                    .encoding =
                        {
                            .code = 0x1EULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN0 Credit Consumed; SNP",
                    .full_desc =
                        "Counts the number of times that an RxQ VN0 credit was consumed (i.e. message uses a VN0 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN0 credit for the SNP message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN1.DRS",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN1 Credit Consumed; DRS",
                    .full_desc =
                        "Counts the number of times that an RxQ VN1 credit was consumed (i.e. message uses a VN1 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN1 credit for the DRS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN1.HOM",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN1 Credit Consumed; HOM",
                    .full_desc =
                        "Counts the number of times that an RxQ VN1 credit was consumed (i.e. message uses a VN1 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN1 credit for the HOM message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN1.NCB",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN1 Credit Consumed; NCB",
                    .full_desc =
                        "Counts the number of times that an RxQ VN1 credit was consumed (i.e. message uses a VN1 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN1 credit for the NCB message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN1.NCS",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN1 Credit Consumed; NCS",
                    .full_desc =
                        "Counts the number of times that an RxQ VN1 credit was consumed (i.e. message uses a VN1 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN1 credit for the NCS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN1.NDR",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN1 Credit Consumed; NDR",
                    .full_desc =
                        "Counts the number of times that an RxQ VN1 credit was consumed (i.e. message uses a VN1 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN1 credit for the NDR message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VN1.SNP",
                    .encoding =
                        {
                            .code = 0x39ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VN1 Credit Consumed; SNP",
                    .full_desc =
                        "Counts the number of times that an RxQ VN1 credit was consumed (i.e. message uses a VN1 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.; VN1 credit for the SNP message class.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CREDITS_CONSUMED_VNA",
                    .encoding =
                        {
                            .code = 0x1DULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VNA Credit Consumed",
                    .full_desc =
                        "Counts the number of times that an RxQ VNA credit was consumed (i.e. message uses a VNA credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE",
                    .encoding =
                        {
                            .code = 0xAULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_DRS.VN0",
                    .encoding =
                        {
                            .code = 0xFULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - DRS; for VN0",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors DRS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_DRS.VN1",
                    .encoding =
                        {
                            .code = 0xFULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - DRS; for VN1",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors DRS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_HOM.VN0",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - HOM; for VN0",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors HOM flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_HOM.VN1",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - HOM; for VN1",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors HOM flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_NCB.VN0",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - NCB; for VN0",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors NCB flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_NCB.VN1",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - NCB; for VN1",
                    .full_desc = "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors NCB flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_NCS.VN0",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - NCS; for VN0",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors NCS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_NCS.VN1",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - NCS; for VN1",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors NCS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_NDR.VN0",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - NDR; for VN0",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors NDR flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_NDR.VN1",
                    .encoding =
                        {
                            .code = 0x14ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - NDR; for VN1",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors NDR flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_SNP.VN0",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - SNP; for VN0",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors SNP flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_CYCLES_NE_SNP.VN1",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Cycles Not Empty - SNP; for VN1",
                    .full_desc =
                        "Counts the number of cycles that the QPI RxQ was not empty.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy Accumulator event to calculate the average occupancy.  This monitors SNP flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G0.IDLE",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 0; Idle and Null Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  It includes filters for Idle, protocol, and Data Flits.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time (for L0) or 4B instead of 8B for L0p.; Number of flits received over QPI that do not hold protocol payload.  When QPI is not in a power saving state, it continuously transmits flits across the link.  When there are no protocol flits to send, it will send IDLE and NULL flits  across.  These flits sometimes do carry a payload, such as credit returns, but are generally not considered part of the QPI bandwidth.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G1.DRS",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x18ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 1; DRS Flits (both Header and Data)",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of flits received over QPI on the DRS (Data Response) channel.  DRS flits are used to transmit data with coherency.  This does not count data flits received over the NCB channel which transmits non-coherent data.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G1.DRS_DATA",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Received - Group 1; DRS Data Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of data flits received over QPI on the DRS (Data Response) channel.  DRS flits are used to transmit data with coherency.  This does not count data flits received over the NCB channel which transmits non-coherent data.  This includes only the data flits (not the header).",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G1.DRS_NONDATA",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Received - Group 1; DRS Header Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of protocol flits received over QPI on the DRS (Data Response) channel.  DRS flits are used to transmit data with coherency.  This does not count data flits received over the NCB channel which transmits non-coherent data.  This includes only the header flits (not the data).  This includes extended headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G1.HOM",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Received - Group 1; HOM Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of flits received over QPI on the home channel.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G1.HOM_NONREQ",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 1; HOM Non-Request Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of non-request flits received over QPI on the home channel.  These are most commonly snoop responses, and this event can be used as a proxy for that.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G1.HOM_REQ",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Received - Group 1; HOM Request Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of data request received over QPI on the home channel.  This basically counts the number of remote memory requests received over QPI.  In conjunction with the local read count in the Home Agent, one can calculate the number of LLC Misses.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G1.SNP",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Received - Group 1; SNP Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of snoop request flits received over QPI.  These requests are contained in the snoop channel.  This does not include snoop responses, which are received on the home channel.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G2.NCB",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 2; Non-Coherent Rx Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of Non-Coherent Bypass flits.  These packets are generally used to transmit non-coherent data across QPI.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G2.NCB_DATA",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 2; Non-Coherent data Rx Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of Non-Coherent Bypass data flits.  These flits are generally used to transmit non-coherent data across QPI.  This does not include a count of the DRS (coherent) data flits.  This only counts the data flits, not the NCB headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G2.NCB_NONDATA",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 2; Non-Coherent non-data Rx Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of Non-Coherent Bypass non-data flits.  These packets are generally used to transmit non-coherent data across QPI, and the flits counted here are for headers and other non-data flits.  This includes extended headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G2.NCS",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 2; Non-Coherent standard Rx Flits",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of NCS (non-coherent standard) flits received over QPI.    This includes extended headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G2.NDR_AD",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 2; Non-Data Response Rx Flits - AD",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of flits received over the NDR (Non-Data Response) channel.  This channel is used to send a variety of protocol flits including grants and completions.  This is only for NDR packets to the local socket which use the AK ring.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_FLITS_G2.NDR_AK",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Received - Group 2; Non-Data Response Rx Flits - AK",
                    .full_desc =
                        "Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of flits received over the NDR (Non-Data Response) channel.  This channel is used to send a variety of protocol flits including grants and completions.  This is only for NDR packets destined for Route-thru to a remote socket.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS",
                    .encoding =
                        {
                            .code = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_DRS.VN0",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - DRS; for VN0",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only DRS flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_DRS.VN1",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - DRS; for VN1",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only DRS flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_HOM.VN0",
                    .encoding =
                        {
                            .code = 0xCULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - HOM; for VN0",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only HOM flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_HOM.VN1",
                    .encoding =
                        {
                            .code = 0xCULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - HOM; for VN1",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only HOM flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_NCB.VN0",
                    .encoding =
                        {
                            .code = 0xAULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - NCB; for VN0",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only NCB flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_NCB.VN1",
                    .encoding =
                        {
                            .code = 0xAULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - NCB; for VN1",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only NCB flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_NCS.VN0",
                    .encoding =
                        {
                            .code = 0xBULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - NCS; for VN0",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only NCS flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_NCS.VN1",
                    .encoding =
                        {
                            .code = 0xBULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - NCS; for VN1",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only NCS flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_NDR.VN0",
                    .encoding =
                        {
                            .code = 0xEULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - NDR; for VN0",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only NDR flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_NDR.VN1",
                    .encoding =
                        {
                            .code = 0xEULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - NDR; for VN1",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only NDR flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_SNP.VN0",
                    .encoding =
                        {
                            .code = 0xDULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - SNP; for VN0",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only SNP flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_INSERTS_SNP.VN1",
                    .encoding =
                        {
                            .code = 0xDULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Rx Flit Buffer Allocations - SNP; for VN1",
                    .full_desc =
                        "Number of allocations into the QPI Rx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.  This monitors only SNP flits.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0xBULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - All Packets",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_DRS.VN0",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - DRS; for VN0",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors DRS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_DRS.VN1",
                    .encoding =
                        {
                            .code = 0x15ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - DRS; for VN1",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors DRS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_HOM.VN0",
                    .encoding =
                        {
                            .code = 0x18ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - HOM; for VN0",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors HOM flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_HOM.VN1",
                    .encoding =
                        {
                            .code = 0x18ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - HOM; for VN1",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors HOM flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_NCB.VN0",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - NCB; for VN0",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors NCB flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_NCB.VN1",
                    .encoding =
                        {
                            .code = 0x16ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - NCB; for VN1",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors NCB flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_NCS.VN0",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - NCS; for VN0",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors NCS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_NCS.VN1",
                    .encoding =
                        {
                            .code = 0x17ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - NCS; for VN1",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors NCS flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_NDR.VN0",
                    .encoding =
                        {
                            .code = 0x1AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - NDR; for VN0",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors NDR flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_NDR.VN1",
                    .encoding =
                        {
                            .code = 0x1AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - NDR; for VN1",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors NDR flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_SNP.VN0",
                    .encoding =
                        {
                            .code = 0x19ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - SNP; for VN0",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors SNP flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_OCCUPANCY_SNP.VN1",
                    .encoding =
                        {
                            .code = 0x19ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "RxQ Occupancy - SNP; for VN1",
                    .full_desc =
                        "Accumulates the number of elements in the QPI RxQ in each cycle.  Generally, when data is transmitted across QPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.  This monitors SNP flits only.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.BGF_DRS",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN0; BGF Stall - HOM",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled a packet from the HOM message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.BGF_HOM",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN0; BGF Stall - DRS",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled a packet from the DRS message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.BGF_NCB",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN0; BGF Stall - SNP",
                    .full_desc = "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled a packet from the SNP message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.BGF_NCS",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN0; BGF Stall - NDR",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled a packet from the NDR message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.BGF_NDR",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN0; BGF Stall - NCS",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled a packet from the NCS message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.BGF_SNP",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN0; BGF Stall - NCB",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled a packet from the NCB message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.EGRESS_CREDITS",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x40ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN0; Egress Credits",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled a packet because there were insufficient BGF credits.  For details on a message class granularity, use the Egress Credit Occupancy events.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN0.GV",
                    .encoding =
                        {
                            .code = 0x35ULL,
                            .umask = 0x80ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stalls Sending to R3QPI on VN0; GV",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 0; Stalled because a GV transition (frequency transition) was taking place.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN1.BGF_DRS",
                    .encoding =
                        {
                            .code = 0x3AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN1; BGF Stall - HOM",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 1.; Stalled a packet from the HOM message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN1.BGF_HOM",
                    .encoding =
                        {
                            .code = 0x3AULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN1; BGF Stall - DRS",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 1.; Stalled a packet from the DRS message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN1.BGF_NCB",
                    .encoding =
                        {
                            .code = 0x3AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN1; BGF Stall - SNP",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 1.; Stalled a packet from the SNP message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN1.BGF_NCS",
                    .encoding =
                        {
                            .code = 0x3AULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN1; BGF Stall - NDR",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 1.; Stalled a packet from the NDR message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN1.BGF_NDR",
                    .encoding =
                        {
                            .code = 0x3AULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN1; BGF Stall - NCS",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 1.; Stalled a packet from the NCS message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_RxL_STALLS_VN1.BGF_SNP",
                    .encoding =
                        {
                            .code = 0x3AULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Stalls Sending to R3QPI on VN1; BGF Stall - NCB",
                    .full_desc =
                        "Number of stalls trying to send to R3QPI on Virtual Network 1.; Stalled a packet from the NCB message class because there were not enough BGF credits.  In bypass mode, we will stall on the packet boundary, while in RxQ mode we will stall on the flit boundary.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL0P_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0xDULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in L0p",
                    .full_desc =
                        "Number of QPI qfclk cycles spent in L0p power mode.  L0p is a mode where we disable 1/2 of the QPI lanes, decreasing our bandwidth in order to save power.  It increases snoop and data transfer latencies and decreases overall bandwidth.  This mode can be very useful in NUMA optimized workloads that largely only utilize QPI for snoops and their responses.  Use edge detect to count the number of instances when the QPI link entered L0p.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL0_POWER_CYCLES",
                    .encoding =
                        {
                            .code = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Cycles in L0",
                    .full_desc =
                        "Number of QPI qfclk cycles spent in L0 power mode in the Link Layer.  L0 is the default mode which provides the highest performance with the most power.  Use edge detect to count the number of instances that the link entered L0.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another.  The phy layer  sometimes leaves L0 for training, which will not be captured by this event.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_BYPASSED",
                    .encoding =
                        {
                            .code = 0x5ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tx Flit Buffer Bypassed",
                    .full_desc =
                        "Counts the number of times that an incoming flit was able to bypass the Tx flit buffer and pass directly out the QPI Link. Generally, when data is transmitted across QPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_CRC_NO_CREDITS.ALMOST_FULL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles Stalled with no LLR Credits; LLR is almost full",
                    .full_desc =
                        "Number of cycles when the Tx side ran out of Link Layer Retry credits, causing the Tx to stall.; When LLR is almost full, we block some but not all packets.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_CRC_NO_CREDITS.FULL",
                    .encoding =
                        {
                            .code = 0x2ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Cycles Stalled with no LLR Credits; LLR is full",
                    .full_desc =
                        "Number of cycles when the Tx side ran out of Link Layer Retry credits, causing the Tx to stall.; When LLR is totally full, we are not allowed to send any packets.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_CYCLES_NE",
                    .encoding =
                        {
                            .code = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tx Flit Buffer Cycles not Empty",
                    .full_desc =
                        "Counts the number of cycles when the TxQ is not empty. Generally, when data is transmitted across QPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G0.DATA",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Transferred - Group 0; Data Tx Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  It includes filters for Idle, protocol, and Data Flits.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time (for L0) or 4B instead of 8B for L0p.; Number of data flits transmitted over QPI.  Each flit contains 64b of data.  This includes both DRS and NCB data flits (coherent and non-coherent).  This can be used to calculate the data bandwidth of the QPI link.  One can get a good picture of the QPI-link characteristics by evaluating the protocol flits, data flits, and idle/null flits.  This does not include the header flits that go in data packets.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G0.NON_DATA",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 0; Non-Data protocol Tx Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  It includes filters for Idle, protocol, and Data Flits.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time (for L0) or 4B instead of 8B for L0p.; Number of non-NULL non-data flits transmitted across QPI.  This basically tracks the protocol overhead on the QPI link.  One can get a good picture of the QPI-link characteristics by evaluating the protocol flits, data flits, and idle/null flits.  This includes the header flits for data packets.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G1.DRS",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x18ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 1; DRS Flits (both Header and Data)",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of flits transmitted over QPI on the DRS (Data Response) channel.  DRS flits are used to transmit data with coherency.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G1.DRS_DATA",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Transferred - Group 1; DRS Data Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of data flits transmitted over QPI on the DRS (Data Response) channel.  DRS flits are used to transmit data with coherency.  This does not count data flits transmitted over the NCB channel which transmits non-coherent data.  This includes only the data flits (not the header).",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G1.DRS_NONDATA",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 1; DRS Header Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of protocol flits transmitted over QPI on the DRS (Data Response) channel.  DRS flits are used to transmit data with coherency.  This does not count data flits transmitted over the NCB channel which transmits non-coherent data.  This includes only the header flits (not the data).  This includes extended headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G1.HOM",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x6ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Transferred - Group 1; HOM Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of flits transmitted over QPI on the home channel.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G1.HOM_NONREQ",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 1; HOM Non-Request Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of non-request flits transmitted over QPI on the home channel.  These are most commonly snoop responses, and this event can be used as a proxy for that.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G1.HOM_REQ",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 1; HOM Request Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of data request transmitted over QPI on the home channel.  This basically counts the number of remote memory requests transmitted over QPI.  In conjunction with the local read count in the Home Agent, one can calculate the number of LLC Misses.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G1.SNP",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Flits Transferred - Group 1; SNP Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP, HOM, and DRS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the number of snoop request flits transmitted over QPI.  These requests are contained in the snoop channel.  This does not include snoop responses, which are transmitted on the home channel.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G2.NCB",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 2; Non-Coherent Bypass Tx Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of Non-Coherent Bypass flits.  These packets are generally used to transmit non-coherent data across QPI.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G2.NCB_DATA",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 2; Non-Coherent data Tx Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of Non-Coherent Bypass data flits.  These flits are generally used to transmit non-coherent data across QPI.  This does not include a count of the DRS (coherent) data flits.  This only counts the data flits, not the NCB headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G2.NCB_NONDATA",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 2; Non-Coherent non-data Tx Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of Non-Coherent Bypass non-data flits.  These packets are generally used to transmit non-coherent data across QPI, and the flits counted here are for headers and other non-data flits.  This includes extended headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G2.NCS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 2; Non-Coherent standard Tx Flits",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Number of NCS (non-coherent standard) flits transmitted over QPI.    This includes extended headers.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G2.NDR_AD",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 2; Non-Data Response Tx Flits - AD",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of flits transmitted over the NDR (Non-Data Response) channel.  This channel is used to send a variety of protocol flits including grants and completions.  This is only for NDR packets to the local socket which use the AK ring.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_FLITS_G2.NDR_AK",
                    .encoding =
                        {
                            .code = 0x1ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Flits Transferred - Group 2; Non-Data Response Tx Flits - AK",
                    .full_desc =
                        "Counts the number of flits transmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR, NCB, and NCS message classes.  Each flit is made up of 80 bits of information (in addition to some ECC data).  In full-width (L0) mode, flits are made up of four fits, each of which contains 20 bits of data (along with some additional ECC data).   In half-width (L0p) mode, the fits are only 10 bits, and therefore it takes twice as many fits to transmit a flit.  When one talks about QPI speed (for example, 8.0 GT/s), the transfers here refer to fits.  Therefore, in L0, the system will transfer 1 flit at the rate of 1/4th the QPI speed.  One can calculate the bandwidth of the link by taking: flits*80b/time.  Note that this is not the same as data bandwidth.  For example, when we are transferring a 64B cacheline across QPI, we will break it into 9 flits -- 1 with header information and 8 with 64 bits of actual data and an additional 16 bits of other information.  To calculate data bandwidth, one should therefore do: data flits * 8B / time.; Counts the total number of flits transmitted over the NDR (Non-Data Response) channel.  This channel is used to send a variety of protocol flits including grants and completions.  This is only for NDR packets destined for Route-thru to a remote socket.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_INSERTS",
                    .encoding =
                        {
                            .code = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tx Flit Buffer Allocations",
                    .full_desc =
                        "Number of allocations into the QPI Tx Flit Buffer.  Generally, when data is transmitted across QPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxL_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x7ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Tx Flit Buffer Occupancy",
                    .full_desc =
                        "Accumulates the number of flits in the TxQ.  Generally, when data is transmitted across QPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link. This can be used with the cycles not empty event to track average occupancy, or the allocations event to track average lifetime in the TxQ.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_HOM_CREDIT_ACQUIRED.VN0",
                    .encoding =
                        {
                            .code = 0x26ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - HOM; for VN0",
                    .full_desc =
                        "Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle. Flow Control FIFO for Home messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_HOM_CREDIT_ACQUIRED.VN1",
                    .encoding =
                        {
                            .code = 0x26ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - HOM; for VN1",
                    .full_desc =
                        "Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle. Flow Control FIFO for Home messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_HOM_CREDIT_OCCUPANCY.VN0",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD HOM; for VN0",
                    .full_desc =
                        "Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle.  Flow Control FIFO for HOM messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_HOM_CREDIT_OCCUPANCY.VN1",
                    .encoding =
                        {
                            .code = 0x22ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD HOM; for VN1",
                    .full_desc =
                        "Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle.  Flow Control FIFO for HOM messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_NDR_CREDIT_ACQUIRED.VN0",
                    .encoding =
                        {
                            .code = 0x28ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD NDR; for VN0",
                    .full_desc =
                        "Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle.  Flow Control FIFO for NDR messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_NDR_CREDIT_ACQUIRED.VN1",
                    .encoding =
                        {
                            .code = 0x28ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD NDR; for VN1",
                    .full_desc =
                        "Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle.  Flow Control FIFO for NDR messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_NDR_CREDIT_OCCUPANCY.VN0",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD NDR; for VN0",
                    .full_desc =
                        "Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle. Flow Control FIFO  for NDR messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_NDR_CREDIT_OCCUPANCY.VN1",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD NDR; for VN1",
                    .full_desc =
                        "Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle. Flow Control FIFO  for NDR messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_SNP_CREDIT_ACQUIRED.VN0",
                    .encoding =
                        {
                            .code = 0x27ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - SNP; for VN0",
                    .full_desc =
                        "Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle.  Flow Control FIFO for Snoop messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_SNP_CREDIT_ACQUIRED.VN1",
                    .encoding =
                        {
                            .code = 0x27ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - SNP; for VN1",
                    .full_desc =
                        "Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle.  Flow Control FIFO for Snoop messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_SNP_CREDIT_OCCUPANCY.VN0",
                    .encoding =
                        {
                            .code = 0x23ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD SNP; for VN0",
                    .full_desc =
                        "Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle.  Flow Control FIFO for Snoop messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AD_SNP_CREDIT_OCCUPANCY.VN1",
                    .encoding =
                        {
                            .code = 0x23ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - AD SNP; for VN1",
                    .full_desc =
                        "Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle.  Flow Control FIFO for Snoop messages on AD.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AK_NDR_CREDIT_ACQUIRED",
                    .encoding =
                        {
                            .code = 0x29ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R3QPI Egress Credit Occupancy - AK NDR",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. Local NDR message class to AK Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_AK_NDR_CREDIT_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x25ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R3QPI Egress Credit Occupancy - AK NDR",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  Local NDR message class to AK Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_DRS_CREDIT_ACQUIRED.VN0",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - DRS; for VN0",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. DRS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_DRS_CREDIT_ACQUIRED.VN1",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - DRS; for VN1",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. DRS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_DRS_CREDIT_ACQUIRED.VN_SHR",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - DRS; for Shared VN",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. DRS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_DRS_CREDIT_OCCUPANCY.VN0",
                    .encoding =
                        {
                            .code = 0x1FULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - BL DRS; for VN0",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  DRS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_DRS_CREDIT_OCCUPANCY.VN1",
                    .encoding =
                        {
                            .code = 0x1FULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - BL DRS; for VN1",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  DRS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_DRS_CREDIT_OCCUPANCY.VN_SHR",
                    .encoding =
                        {
                            .code = 0x1FULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - BL DRS; for Shared VN",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  DRS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCB_CREDIT_ACQUIRED.VN0",
                    .encoding =
                        {
                            .code = 0x2BULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - NCB; for VN0",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. NCB message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCB_CREDIT_ACQUIRED.VN1",
                    .encoding =
                        {
                            .code = 0x2BULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - NCB; for VN1",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. NCB message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCB_CREDIT_OCCUPANCY.VN0",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - BL NCB; for VN0",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  NCB message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCB_CREDIT_OCCUPANCY.VN1",
                    .encoding =
                        {
                            .code = 0x20ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - BL NCB; for VN1",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  NCB message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCS_CREDIT_ACQUIRED.VN0",
                    .encoding =
                        {
                            .code = 0x2CULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - NCS; for VN0",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. NCS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCS_CREDIT_ACQUIRED.VN1",
                    .encoding =
                        {
                            .code = 0x2CULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - NCS; for VN1",
                    .full_desc =
                        "Number of credits into the R3 (for transactions across the BGF) acquired each cycle. NCS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCS_CREDIT_OCCUPANCY.VN0",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - BL NCS; for VN0",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  NCS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_TxR_BL_NCS_CREDIT_OCCUPANCY.VN1",
                    .encoding =
                        {
                            .code = 0x21ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R3QPI Egress Credit Occupancy - BL NCS; for VN1",
                    .full_desc =
                        "Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  NCS message class to BL Egress.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_VNA_CREDIT_RETURNS",
                    .encoding =
                        {
                            .code = 0x1CULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VNA Credits Returned",
                    .full_desc = "Number of VNA credits returned.",
                },
                {
                    .pmu_type = PmuType::uncore_qpi,
                    .id = "UNC_Q_VNA_CREDIT_RETURN_OCCUPANCY",
                    .encoding =
                        {
                            .code = 0x1BULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "VNA Credits Pending Return - Occupancy",
                    .full_desc =
                        "Number of VNA credits in the Rx side that are waitng to be returned back across the link.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_CLOCKTICKS",
                    .encoding =
                        {
                            .code = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Number of uclks in domain",
                    .full_desc =
                        "Counts the number of uclks in the R2PCIe uclk domain.  This could be slightly different than the count in the Ubox because of enable/freeze delays.  However, because the R2PCIe is close to the Ubox, they generally should not diverge by more than a handful of cycles.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDIT.ISOCH_QPI0",
                    .encoding =
                        {
                            .code = 0x2DULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_R2_IIO_CREDIT.ISOCH_QPI0",
                    .full_desc = "UNC_R2_IIO_CREDIT.ISOCH_QPI0",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDIT.ISOCH_QPI1",
                    .encoding =
                        {
                            .code = 0x2DULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_R2_IIO_CREDIT.ISOCH_QPI1",
                    .full_desc = "UNC_R2_IIO_CREDIT.ISOCH_QPI1",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDIT.PRQ_QPI0",
                    .encoding =
                        {
                            .code = 0x2DULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_R2_IIO_CREDIT.PRQ_QPI0",
                    .full_desc = "UNC_R2_IIO_CREDIT.PRQ_QPI0",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDIT.PRQ_QPI1",
                    .encoding =
                        {
                            .code = 0x2DULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "UNC_R2_IIO_CREDIT.PRQ_QPI1",
                    .full_desc = "UNC_R2_IIO_CREDIT.PRQ_QPI1",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDITS_ACQUIRED.DRS",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2PCIe IIO Credit Acquired; DRS",
                    .full_desc =
                        "Counts the number of credits that are acquired in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the DRS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDITS_ACQUIRED.NCB",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2PCIe IIO Credit Acquired; NCB",
                    .full_desc =
                        "Counts the number of credits that are acquired in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCB message class.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDITS_ACQUIRED.NCS",
                    .encoding =
                        {
                            .code = 0x33ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2PCIe IIO Credit Acquired; NCS",
                    .full_desc =
                        "Counts the number of credits that are acquired in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDITS_USED.DRS",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2PCIe IIO Credits in Use; DRS",
                    .full_desc =
                        "Counts the number of cycles when one or more credits in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the DRS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDITS_USED.NCB",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2PCIe IIO Credits in Use; NCB",
                    .full_desc =
                        "Counts the number of cycles when one or more credits in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCB message class.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_IIO_CREDITS_USED.NCS",
                    .encoding =
                        {
                            .code = 0x32ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2PCIe IIO Credits in Use; NCS",
                    .full_desc =
                        "Counts the number of cycles when one or more credits in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCS message class.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AD_USED.CCW",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AD Ring in Use; Counterclockwise",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AD_USED.CCW_EVEN",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R2 AD Ring in Use; Counterclockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AD_USED.CCW_ODD",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AD Ring in Use; Counterclockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AD_USED.CW",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AD Ring in Use; Clockwise",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AD_USED.CW_EVEN",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AD Ring in Use; Clockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AD_USED.CW_ODD",
                    .encoding =
                        {
                            .code = 0x7ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AD Ring in Use; Clockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_BOUNCES.DN",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ingress Bounced; Dn",
                    .full_desc =
                        "Counts the number of times when a request destined for the AK ingress bounced.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_BOUNCES.UP",
                    .encoding =
                        {
                            .code = 0x12ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "AK Ingress Bounced; Up",
                    .full_desc =
                        "Counts the number of times when a request destined for the AK ingress bounced.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_USED.CCW",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AK Ring in Use; Counterclockwise",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_USED.CCW_EVEN",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R2 AK Ring in Use; Counterclockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_USED.CCW_ODD",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AK Ring in Use; Counterclockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_USED.CW",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AK Ring in Use; Clockwise",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_USED.CW_EVEN",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AK Ring in Use; Clockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_AK_USED.CW_ODD",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 AK Ring in Use; Clockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_BL_USED.CCW",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 BL Ring in Use; Counterclockwise",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_BL_USED.CCW_EVEN",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "R2 BL Ring in Use; Counterclockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_BL_USED.CCW_ODD",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 BL Ring in Use; Counterclockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_BL_USED.CW",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 BL Ring in Use; Clockwise",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_BL_USED.CW_EVEN",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 BL Ring in Use; Clockwise and Even",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_BL_USED.CW_ODD",
                    .encoding =
                        {
                            .code = 0x9ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 BL Ring in Use; Clockwise and Odd",
                    .full_desc =
                        "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_IV_USED.ANY",
                    .encoding =
                        {
                            .code = 0xAULL,
                            .umask = 0xFULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 IV Ring in Use; Any",
                    .full_desc =
                        "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_IV_USED.CCW",
                    .encoding =
                        {
                            .code = 0xAULL,
                            .umask = 0xCULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 IV Ring in Use; Counterclockwise",
                    .full_desc =
                        "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RING_IV_USED.CW",
                    .encoding =
                        {
                            .code = 0xAULL,
                            .umask = 0x3ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "R2 IV Ring in Use; Clockwise",
                    .full_desc =
                        "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RxR_CYCLES_NE.NCB",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Cycles Not Empty; NCB",
                    .full_desc =
                        "Counts the number of cycles when the R2PCIe Ingress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCB Ingress Queue",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RxR_CYCLES_NE.NCS",
                    .encoding =
                        {
                            .code = 0x10ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Cycles Not Empty; NCS",
                    .full_desc =
                        "Counts the number of cycles when the R2PCIe Ingress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCS Ingress Queue",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RxR_INSERTS.NCB",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x10ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Allocations; NCB",
                    .full_desc =
                        "Counts the number of allocations into the R2PCIe Ingress.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCB Ingress Queue",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RxR_INSERTS.NCS",
                    .encoding =
                        {
                            .code = 0x11ULL,
                            .umask = 0x20ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Allocations; NCS",
                    .full_desc =
                        "Counts the number of allocations into the R2PCIe Ingress.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCS Ingress Queue",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_RxR_OCCUPANCY.DRS",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Ingress Occupancy Accumulator; DRS",
                    .full_desc =
                        "Accumulates the occupancy of a given R2PCIe Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the R2PCIe Ingress Not Empty event to calculate average occupancy or the R2PCIe Ingress Allocations event in order to calculate average queuing latency.; DRS Ingress Queue",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_SBO0_CREDITS_ACQUIRED.AD",
                    .encoding =
                        {
                            .code = 0x28ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Acquired; For AD Ring",
                    .full_desc =
                        "Number of Sbo 0 credits acquired in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_SBO0_CREDITS_ACQUIRED.BL",
                    .encoding =
                        {
                            .code = 0x28ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Acquired; For BL Ring",
                    .full_desc =
                        "Number of Sbo 0 credits acquired in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_SBO0_CREDIT_OCCUPANCY.AD",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Occupancy; For AD Ring",
                    .full_desc =
                        "Number of Sbo 0 credits in use in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_SBO0_CREDIT_OCCUPANCY.BL",
                    .encoding =
                        {
                            .code = 0x2AULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "SBo0 Credits Occupancy; For BL Ring",
                    .full_desc =
                        "Number of Sbo 0 credits in use in a given cycle, per ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_STALL_NO_SBO_CREDIT.SBO0_AD",
                    .encoding =
                        {
                            .code = 0x2CULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo0, AD Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_STALL_NO_SBO_CREDIT.SBO0_BL",
                    .encoding =
                        {
                            .code = 0x2CULL,
                            .umask = 0x4ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo0, BL Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_STALL_NO_SBO_CREDIT.SBO1_AD",
                    .encoding =
                        {
                            .code = 0x2CULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo1, AD Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_STALL_NO_SBO_CREDIT.SBO1_BL",
                    .encoding =
                        {
                            .code = 0x2CULL,
                            .umask = 0x8ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Stall on No Sbo Credits; For SBo1, BL Ring",
                    .full_desc =
                        "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_TxR_CYCLES_FULL.AD",
                    .encoding =
                        {
                            .code = 0x25ULL,
                            .umask = 0x1ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Cycles Full; AD",
                    .full_desc =
                        "Counts the number of cycles when the R2PCIe Egress buffer is full.; AD Egress Queue",
                },
                {
                    .pmu_type = PmuType::uncore_r2pcie,
                    .id = "UNC_R2_TxR_CYCLES_FULL.AK",
                    .encoding =
                        {
                            .code = 0x25ULL,
                            .umask = 0x2ULL,
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Egress Cycles Full; AK",
                    .full_desc =
                        "Counts the number of cycles when the R2PCIe Egress buffer is full.; AK Egress Queue",
                },
            }};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents1));

constexpr std::array<StaticEventDef, 252> kFullOnlyEvents2{
    {
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_CYCLES_FULL.BL",
            .encoding =
                {
                    .code = 0x25ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Cycles Full; BL",
            .full_desc =
                "Counts the number of cycles when the R2PCIe Egress buffer is full.; BL Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_CYCLES_NE.AD",
            .encoding =
                {
                    .code = 0x23ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Cycles Not Empty; AD",
            .full_desc =
                "Counts the number of cycles when the R2PCIe Egress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Egress Occupancy Accumulator event in order to calculate average queue occupancy.  Only a single Egress queue can be tracked at any given time.  It is not possible to filter based on direction or polarity.; AD Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_CYCLES_NE.AK",
            .encoding =
                {
                    .code = 0x23ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Cycles Not Empty; AK",
            .full_desc =
                "Counts the number of cycles when the R2PCIe Egress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Egress Occupancy Accumulator event in order to calculate average queue occupancy.  Only a single Egress queue can be tracked at any given time.  It is not possible to filter based on direction or polarity.; AK Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_CYCLES_NE.BL",
            .encoding =
                {
                    .code = 0x23ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Cycles Not Empty; BL",
            .full_desc =
                "Counts the number of cycles when the R2PCIe Egress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Egress Occupancy Accumulator event in order to calculate average queue occupancy.  Only a single Egress queue can be tracked at any given time.  It is not possible to filter based on direction or polarity.; BL Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_NACK_CW.DN_AD",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; AD CCW",
            .full_desc = "AD CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_NACK_CW.DN_AK",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; AK CCW",
            .full_desc = "AK CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_NACK_CW.DN_BL",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; BL CCW",
            .full_desc = "BL CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_NACK_CW.UP_AD",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; AK CCW",
            .full_desc = "BL CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_NACK_CW.UP_AK",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; BL CW",
            .full_desc = "AD Clockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r2pcie,
            .id = "UNC_R2_TxR_NACK_CW.UP_BL",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; BL CCW",
            .full_desc = "AD CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_CLOCKTICKS",
            .encoding =
                {
                    .code = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of uclks in domain",
            .full_desc =
                "Counts the number of uclks in the QPI uclk domain.  This could be slightly different than the count in the Ubox because of enable/freeze delays.  However, because the QPI Agent is close to the Ubox, they generally should not diverge by more than a handful of cycles.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO10",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 10",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO11",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 11",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO12",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 12",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO13",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 13",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO14_16",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 14&16",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO8",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 8",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO9",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 9",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_HI_AD_CREDITS_EMPTY.CBO_15_17",
            .encoding =
                {
                    .code = 0x1FULL,
                    .umask = 0x80ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers higher CBoxes); Cbox 15&17",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO0",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 0",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO1",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 1",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO2",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 2",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO3",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 3",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO4",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 4",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO5",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 5",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO6",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 6",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_C_LO_AD_CREDITS_EMPTY.CBO7",
            .encoding =
                {
                    .code = 0x22ULL,
                    .umask = 0x80ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CBox AD Credits Empty",
            .full_desc =
                "No credits available to send to Cbox on the AD Ring (covers lower CBoxes); Cbox 7",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_HA_R2_BL_CREDITS_EMPTY.HA0",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "HA/R2 AD Credits Empty",
            .full_desc =
                "No credits available to send to either HA or R2 on the BL Ring; HA0",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_HA_R2_BL_CREDITS_EMPTY.HA1",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "HA/R2 AD Credits Empty",
            .full_desc =
                "No credits available to send to either HA or R2 on the BL Ring; HA1",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_HA_R2_BL_CREDITS_EMPTY.R2_NCB",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "HA/R2 AD Credits Empty",
            .full_desc =
                "No credits available to send to either HA or R2 on the BL Ring; R2 NCB Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_HA_R2_BL_CREDITS_EMPTY.R2_NCS",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "HA/R2 AD Credits Empty",
            .full_desc =
                "No credits available to send to either HA or R2 on the BL Ring; R2 NCS Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_IOT_BACKPRESSURE.HUB",
            .encoding =
                {
                    .code = 0xBULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "IOT Backpressure",
            .full_desc = "IOT Backpressure",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_IOT_BACKPRESSURE.SAT",
            .encoding =
                {
                    .code = 0xBULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "IOT Backpressure",
            .full_desc = "IOT Backpressure",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_IOT_CTS_HI.CTS2",
            .encoding =
                {
                    .code = 0xDULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "IOT Common Trigger Sequencer - Hi",
            .full_desc = "Debug Mask/Match Tie-Ins",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_IOT_CTS_HI.CTS3",
            .encoding =
                {
                    .code = 0xDULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "IOT Common Trigger Sequencer - Hi",
            .full_desc = "Debug Mask/Match Tie-Ins",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_IOT_CTS_LO.CTS0",
            .encoding =
                {
                    .code = 0xCULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "IOT Common Trigger Sequencer - Lo",
            .full_desc = "Debug Mask/Match Tie-Ins",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_IOT_CTS_LO.CTS1",
            .encoding =
                {
                    .code = 0xCULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "IOT Common Trigger Sequencer - Lo",
            .full_desc = "Debug Mask/Match Tie-Ins",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_AD_CREDITS_EMPTY.VN0_HOM",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the AD Ring; VN0 HOM Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_AD_CREDITS_EMPTY.VN0_NDR",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the AD Ring; VN0 NDR Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_AD_CREDITS_EMPTY.VN0_SNP",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the AD Ring; VN0 SNP Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_AD_CREDITS_EMPTY.VN1_HOM",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the AD Ring; VN1 HOM Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_AD_CREDITS_EMPTY.VN1_NDR",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the AD Ring; VN1 NDR Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_AD_CREDITS_EMPTY.VN1_SNP",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the AD Ring; VN1 SNP Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_AD_CREDITS_EMPTY.VNA",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the AD Ring; VNA",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_BL_CREDITS_EMPTY.VN1_HOM",
            .encoding =
                {
                    .code = 0x21ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the BL Ring; VN1 HOM Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_BL_CREDITS_EMPTY.VN1_NDR",
            .encoding =
                {
                    .code = 0x21ULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the BL Ring; VN1 NDR Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_BL_CREDITS_EMPTY.VN1_SNP",
            .encoding =
                {
                    .code = 0x21ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the BL Ring; VN1 SNP Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI0_BL_CREDITS_EMPTY.VNA",
            .encoding =
                {
                    .code = 0x21ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI0 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI0 on the BL Ring; VNA",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_AD_CREDITS_EMPTY.VN1_HOM",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the AD Ring; VN1 HOM Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_AD_CREDITS_EMPTY.VN1_NDR",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the AD Ring; VN1 NDR Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_AD_CREDITS_EMPTY.VN1_SNP",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the AD Ring; VN1 SNP Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_AD_CREDITS_EMPTY.VNA",
            .encoding =
                {
                    .code = 0x2EULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 AD Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the AD Ring; VNA",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_BL_CREDITS_EMPTY.VN0_HOM",
            .encoding =
                {
                    .code = 0x2FULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the BL Ring; VN0 HOM Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_BL_CREDITS_EMPTY.VN0_NDR",
            .encoding =
                {
                    .code = 0x2FULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the BL Ring; VN0 NDR Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_BL_CREDITS_EMPTY.VN0_SNP",
            .encoding =
                {
                    .code = 0x2FULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the BL Ring; VN0 SNP Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_BL_CREDITS_EMPTY.VN1_HOM",
            .encoding =
                {
                    .code = 0x2FULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the BL Ring; VN1 HOM Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_BL_CREDITS_EMPTY.VN1_NDR",
            .encoding =
                {
                    .code = 0x2FULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the BL Ring; VN1 NDR Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_BL_CREDITS_EMPTY.VN1_SNP",
            .encoding =
                {
                    .code = 0x2FULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the BL Ring; VN1 SNP Messages",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_QPI1_BL_CREDITS_EMPTY.VNA",
            .encoding =
                {
                    .code = 0x2FULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "QPI1 BL Credits Empty",
            .full_desc =
                "No credits available to send to QPI1 on the BL Ring; VNA",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AD_USED.CCW",
            .encoding =
                {
                    .code = 0x7ULL,
                    .umask = 0xCULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AD Ring in Use; Counterclockwise",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AD_USED.CCW_EVEN",
            .encoding =
                {
                    .code = 0x7ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AD Ring in Use; Counterclockwise and Even",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AD_USED.CCW_ODD",
            .encoding =
                {
                    .code = 0x7ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AD Ring in Use; Counterclockwise and Odd",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AD_USED.CW",
            .encoding =
                {
                    .code = 0x7ULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AD Ring in Use; Clockwise",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AD_USED.CW_EVEN",
            .encoding =
                {
                    .code = 0x7ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AD Ring in Use; Clockwise and Even",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AD_USED.CW_ODD",
            .encoding =
                {
                    .code = 0x7ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AD Ring in Use; Clockwise and Odd",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AK_USED.CCW",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0xCULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AK Ring in Use; Counterclockwise",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AK_USED.CCW_EVEN",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AK Ring in Use; Counterclockwise and Even",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AK_USED.CCW_ODD",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AK Ring in Use; Counterclockwise and Odd",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AK_USED.CW",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AK Ring in Use; Clockwise",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AK_USED.CW_EVEN",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AK Ring in Use; Clockwise and Even",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_AK_USED.CW_ODD",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 AK Ring in Use; Clockwise and Odd",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_BL_USED.CCW",
            .encoding =
                {
                    .code = 0x9ULL,
                    .umask = 0xCULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 BL Ring in Use; Counterclockwise",
            .full_desc = "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_BL_USED.CCW_EVEN",
            .encoding =
                {
                    .code = 0x9ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 BL Ring in Use; Counterclockwise and Even",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_BL_USED.CCW_ODD",
            .encoding =
                {
                    .code = 0x9ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 BL Ring in Use; Counterclockwise and Odd",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_BL_USED.CW",
            .encoding =
                {
                    .code = 0x9ULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 BL Ring in Use; Clockwise",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_BL_USED.CW_EVEN",
            .encoding =
                {
                    .code = 0x9ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 BL Ring in Use; Clockwise and Even",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_BL_USED.CW_ODD",
            .encoding =
                {
                    .code = 0x9ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 BL Ring in Use; Clockwise and Odd",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_IV_USED.ANY",
            .encoding =
                {
                    .code = 0xAULL,
                    .umask = 0xFULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 IV Ring in Use; Any",
            .full_desc =
                "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_IV_USED.CW",
            .encoding =
                {
                    .code = 0xAULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "R3 IV Ring in Use; Clockwise",
            .full_desc =
                "Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RING_SINK_STARVED.AK",
            .encoding =
                {
                    .code = 0xEULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ring Stop Starved; AK",
            .full_desc =
                "Number of cycles the ringstop is in starvation (per ring)",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE.HOM",
            .encoding =
                {
                    .code = 0x10ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Cycles Not Empty; HOM",
            .full_desc =
                "Counts the number of cycles when the QPI Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; HOM Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE.NDR",
            .encoding =
                {
                    .code = 0x10ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Cycles Not Empty; NDR",
            .full_desc =
                "Counts the number of cycles when the QPI Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NDR Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE.SNP",
            .encoding =
                {
                    .code = 0x10ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Cycles Not Empty; SNP",
            .full_desc =
                "Counts the number of cycles when the QPI Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; SNP Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE_VN1.DRS",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Cycles Not Empty; DRS",
            .full_desc =
                "Counts the number of cycles when the QPI VN1  Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; DRS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE_VN1.HOM",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Cycles Not Empty; HOM",
            .full_desc =
                "Counts the number of cycles when the QPI VN1  Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; HOM Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE_VN1.NCB",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Cycles Not Empty; NCB",
            .full_desc =
                "Counts the number of cycles when the QPI VN1  Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCB Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE_VN1.NCS",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Cycles Not Empty; NCS",
            .full_desc =
                "Counts the number of cycles when the QPI VN1  Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE_VN1.NDR",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Cycles Not Empty; NDR",
            .full_desc =
                "Counts the number of cycles when the QPI VN1  Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NDR Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_CYCLES_NE_VN1.SNP",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Cycles Not Empty; SNP",
            .full_desc =
                "Counts the number of cycles when the QPI VN1  Ingress is not empty.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; SNP Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS.DRS",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; DRS",
            .full_desc =
                "Counts the number of allocations into the QPI Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; DRS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS.HOM",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; HOM",
            .full_desc =
                "Counts the number of allocations into the QPI Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; HOM Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS.NCB",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; NCB",
            .full_desc =
                "Counts the number of allocations into the QPI Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCB Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS.NCS",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; NCS",
            .full_desc =
                "Counts the number of allocations into the QPI Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS.NDR",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; NDR",
            .full_desc =
                "Counts the number of allocations into the QPI Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NDR Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS.SNP",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; SNP",
            .full_desc =
                "Counts the number of allocations into the QPI Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; SNP Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS_VN1.DRS",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Allocations; DRS",
            .full_desc =
                "Counts the number of allocations into the QPI VN1  Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; DRS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS_VN1.HOM",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Allocations; HOM",
            .full_desc =
                "Counts the number of allocations into the QPI VN1  Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; HOM Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS_VN1.NCB",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Allocations; NCB",
            .full_desc =
                "Counts the number of allocations into the QPI VN1  Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCB Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS_VN1.NCS",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Allocations; NCS",
            .full_desc =
                "Counts the number of allocations into the QPI VN1  Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS_VN1.NDR",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Allocations; NDR",
            .full_desc =
                "Counts the number of allocations into the QPI VN1  Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NDR Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_INSERTS_VN1.SNP",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Allocations; SNP",
            .full_desc =
                "Counts the number of allocations into the QPI VN1  Ingress.  This tracks one of the three rings that are used by the QPI agent.  This can be used in conjunction with the QPI VN1  Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; SNP Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_OCCUPANCY_VN1.DRS",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Occupancy Accumulator; DRS",
            .full_desc =
                "Accumulates the occupancy of a given QPI VN1  Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the QPI VN1  Ingress Not Empty event to calculate average occupancy or the QPI VN1  Ingress Allocations event in order to calculate average queuing latency.; DRS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_OCCUPANCY_VN1.HOM",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Occupancy Accumulator; HOM",
            .full_desc =
                "Accumulates the occupancy of a given QPI VN1  Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the QPI VN1  Ingress Not Empty event to calculate average occupancy or the QPI VN1  Ingress Allocations event in order to calculate average queuing latency.; HOM Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_OCCUPANCY_VN1.NCB",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Occupancy Accumulator; NCB",
            .full_desc =
                "Accumulates the occupancy of a given QPI VN1  Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the QPI VN1  Ingress Not Empty event to calculate average occupancy or the QPI VN1  Ingress Allocations event in order to calculate average queuing latency.; NCB Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_OCCUPANCY_VN1.NCS",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Occupancy Accumulator; NCS",
            .full_desc =
                "Accumulates the occupancy of a given QPI VN1  Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the QPI VN1  Ingress Not Empty event to calculate average occupancy or the QPI VN1  Ingress Allocations event in order to calculate average queuing latency.; NCS Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_OCCUPANCY_VN1.NDR",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Occupancy Accumulator; NDR",
            .full_desc =
                "Accumulates the occupancy of a given QPI VN1  Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the QPI VN1  Ingress Not Empty event to calculate average occupancy or the QPI VN1  Ingress Allocations event in order to calculate average queuing latency.; NDR Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_RxR_OCCUPANCY_VN1.SNP",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Ingress Occupancy Accumulator; SNP",
            .full_desc =
                "Accumulates the occupancy of a given QPI VN1  Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the QPI VN1  Ingress Not Empty event to calculate average occupancy or the QPI VN1  Ingress Allocations event in order to calculate average queuing latency.; SNP Ingress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO0_CREDITS_ACQUIRED.AD",
            .encoding =
                {
                    .code = 0x28ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo0 Credits Acquired; For AD Ring",
            .full_desc =
                "Number of Sbo 0 credits acquired in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO0_CREDITS_ACQUIRED.BL",
            .encoding =
                {
                    .code = 0x28ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo0 Credits Acquired; For BL Ring",
            .full_desc =
                "Number of Sbo 0 credits acquired in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO0_CREDIT_OCCUPANCY.AD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo0 Credits Occupancy; For AD Ring",
            .full_desc =
                "Number of Sbo 0 credits in use in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO0_CREDIT_OCCUPANCY.BL",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo0 Credits Occupancy; For BL Ring",
            .full_desc =
                "Number of Sbo 0 credits in use in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO1_CREDITS_ACQUIRED.AD",
            .encoding =
                {
                    .code = 0x29ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo1 Credits Acquired; For AD Ring",
            .full_desc =
                "Number of Sbo 1 credits acquired in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO1_CREDITS_ACQUIRED.BL",
            .encoding =
                {
                    .code = 0x29ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo1 Credits Acquired; For BL Ring",
            .full_desc =
                "Number of Sbo 1 credits acquired in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO1_CREDIT_OCCUPANCY.AD",
            .encoding =
                {
                    .code = 0x2BULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo1 Credits Occupancy; For AD Ring",
            .full_desc =
                "Number of Sbo 1 credits in use in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_SBO1_CREDIT_OCCUPANCY.BL",
            .encoding =
                {
                    .code = 0x2BULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "SBo1 Credits Occupancy; For BL Ring",
            .full_desc =
                "Number of Sbo 1 credits in use in a given cycle, per ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_STALL_NO_SBO_CREDIT.SBO0_AD",
            .encoding =
                {
                    .code = 0x2CULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Stall on No Sbo Credits; For SBo0, AD Ring",
            .full_desc =
                "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_STALL_NO_SBO_CREDIT.SBO0_BL",
            .encoding =
                {
                    .code = 0x2CULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Stall on No Sbo Credits; For SBo0, BL Ring",
            .full_desc =
                "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_STALL_NO_SBO_CREDIT.SBO1_AD",
            .encoding =
                {
                    .code = 0x2CULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Stall on No Sbo Credits; For SBo1, AD Ring",
            .full_desc =
                "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_STALL_NO_SBO_CREDIT.SBO1_BL",
            .encoding =
                {
                    .code = 0x2CULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Stall on No Sbo Credits; For SBo1, BL Ring",
            .full_desc =
                "Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_TxR_NACK.DN_AD",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; AD CCW",
            .full_desc = "AD CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_TxR_NACK.DN_AK",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; AK CCW",
            .full_desc = "AK CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_TxR_NACK.DN_BL",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; BL CCW",
            .full_desc = "BL CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_TxR_NACK.UP_AD",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; AK CCW",
            .full_desc = "BL CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_TxR_NACK.UP_AK",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; BL CW",
            .full_desc = "AD Clockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_TxR_NACK.UP_BL",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress CCW NACK; BL CCW",
            .full_desc = "AD CounterClockwise Egress Queue",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_REJECT.DRS",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN0 Credit Acquisition Failed on DRS; DRS Message Class",
            .full_desc =
                "Number of times a request failed to acquire a DRS VN0 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN0 credit and is delayed.  This should generally be a rare situation.; Filter for Data Response (DRS).  DRS is generally used to transmit data with coherency.  For example, remote reads and writes, or cache to cache transfers will transmit their data using DRS.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_REJECT.HOM",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN0 Credit Acquisition Failed on DRS; HOM Message Class",
            .full_desc =
                "Number of times a request failed to acquire a DRS VN0 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN0 credit and is delayed.  This should generally be a rare situation.; Filter for the Home (HOM) message class.  HOM is generally used to send requests, request responses, and snoop responses.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_REJECT.NCB",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN0 Credit Acquisition Failed on DRS; NCB Message Class",
            .full_desc =
                "Number of times a request failed to acquire a DRS VN0 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN0 credit and is delayed.  This should generally be a rare situation.; Filter for Non-Coherent Broadcast (NCB).  NCB is generally used to transmit data without coherency.  For example, non-coherent read data returns.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_REJECT.NCS",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN0 Credit Acquisition Failed on DRS; NCS Message Class",
            .full_desc =
                "Number of times a request failed to acquire a DRS VN0 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN0 credit and is delayed.  This should generally be a rare situation.; Filter for Non-Coherent Standard (NCS).  NCS is commonly used for ?",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_REJECT.NDR",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN0 Credit Acquisition Failed on DRS; NDR Message Class",
            .full_desc =
                "Number of times a request failed to acquire a DRS VN0 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN0 credit and is delayed.  This should generally be a rare situation.; NDR packets are used to transmit a variety of protocol flits including grants and completions (CMP).",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_REJECT.SNP",
            .encoding =
                {
                    .code = 0x37ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN0 Credit Acquisition Failed on DRS; SNP Message Class",
            .full_desc =
                "Number of times a request failed to acquire a DRS VN0 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN0 credit and is delayed.  This should generally be a rare situation.; Filter for Snoop (SNP) message class.  SNP is used for outgoing snoops.  Note that snoop responses flow on the HOM message class.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_USED.DRS",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN0 Credit Used; DRS Message Class",
            .full_desc =
                "Number of times a VN0 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This counts the number of times a VN0 credit was used.  Note that a single VN0 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN0 will only count a single credit even though it may use multiple buffers.; Filter for Data Response (DRS).  DRS is generally used to transmit data with coherency.  For example, remote reads and writes, or cache to cache transfers will transmit their data using DRS.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_USED.HOM",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN0 Credit Used; HOM Message Class",
            .full_desc =
                "Number of times a VN0 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This counts the number of times a VN0 credit was used.  Note that a single VN0 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN0 will only count a single credit even though it may use multiple buffers.; Filter for the Home (HOM) message class.  HOM is generally used to send requests, request responses, and snoop responses.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_USED.NCB",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN0 Credit Used; NCB Message Class",
            .full_desc =
                "Number of times a VN0 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This counts the number of times a VN0 credit was used.  Note that a single VN0 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN0 will only count a single credit even though it may use multiple buffers.; Filter for Non-Coherent Broadcast (NCB).  NCB is generally used to transmit data without coherency.  For example, non-coherent read data returns.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_USED.NCS",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN0 Credit Used; NCS Message Class",
            .full_desc =
                "Number of times a VN0 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This counts the number of times a VN0 credit was used.  Note that a single VN0 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN0 will only count a single credit even though it may use multiple buffers.; Filter for Non-Coherent Standard (NCS).  NCS is commonly used for ?",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_USED.NDR",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN0 Credit Used; NDR Message Class",
            .full_desc =
                "Number of times a VN0 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This counts the number of times a VN0 credit was used.  Note that a single VN0 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN0 will only count a single credit even though it may use multiple buffers.; NDR packets are used to transmit a variety of protocol flits including grants and completions (CMP).",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN0_CREDITS_USED.SNP",
            .encoding =
                {
                    .code = 0x36ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN0 Credit Used; SNP Message Class",
            .full_desc =
                "Number of times a VN0 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN0.  VNA is a shared pool used to achieve high performance.  The VN0 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN0 if they fail.  This counts the number of times a VN0 credit was used.  Note that a single VN0 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN0 will only count a single credit even though it may use multiple buffers.; Filter for Snoop (SNP) message class.  SNP is used for outgoing snoops.  Note that snoop responses flow on the HOM message class.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_REJECT.DRS",
            .encoding =
                {
                    .code = 0x39ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN1 Credit Acquisition Failed on DRS; DRS Message Class",
            .full_desc =
                "Number of times a request failed to acquire a VN1 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN1 credit and is delayed.  This should generally be a rare situation.; Filter for Data Response (DRS).  DRS is generally used to transmit data with coherency.  For example, remote reads and writes, or cache to cache transfers will transmit their data using DRS.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_REJECT.HOM",
            .encoding =
                {
                    .code = 0x39ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN1 Credit Acquisition Failed on DRS; HOM Message Class",
            .full_desc =
                "Number of times a request failed to acquire a VN1 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN1 credit and is delayed.  This should generally be a rare situation.; Filter for the Home (HOM) message class.  HOM is generally used to send requests, request responses, and snoop responses.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_REJECT.NCB",
            .encoding =
                {
                    .code = 0x39ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN1 Credit Acquisition Failed on DRS; NCB Message Class",
            .full_desc =
                "Number of times a request failed to acquire a VN1 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN1 credit and is delayed.  This should generally be a rare situation.; Filter for Non-Coherent Broadcast (NCB).  NCB is generally used to transmit data without coherency.  For example, non-coherent read data returns.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_REJECT.NCS",
            .encoding =
                {
                    .code = 0x39ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN1 Credit Acquisition Failed on DRS; NCS Message Class",
            .full_desc =
                "Number of times a request failed to acquire a VN1 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN1 credit and is delayed.  This should generally be a rare situation.; Filter for Non-Coherent Standard (NCS).  NCS is commonly used for ?",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_REJECT.NDR",
            .encoding =
                {
                    .code = 0x39ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN1 Credit Acquisition Failed on DRS; NDR Message Class",
            .full_desc =
                "Number of times a request failed to acquire a VN1 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN1 credit and is delayed.  This should generally be a rare situation.; NDR packets are used to transmit a variety of protocol flits including grants and completions (CMP).",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_REJECT.SNP",
            .encoding =
                {
                    .code = 0x39ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "VN1 Credit Acquisition Failed on DRS; SNP Message Class",
            .full_desc =
                "Number of times a request failed to acquire a VN1 credit.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This therefore counts the number of times when a request failed to acquire either a VNA or VN1 credit and is delayed.  This should generally be a rare situation.; Filter for Snoop (SNP) message class.  SNP is used for outgoing snoops.  Note that snoop responses flow on the HOM message class.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_USED.DRS",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Credit Used; DRS Message Class",
            .full_desc =
                "Number of times a VN1 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This counts the number of times a VN1 credit was used.  Note that a single VN1 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN1 will only count a single credit even though it may use multiple buffers.; Filter for Data Response (DRS).  DRS is generally used to transmit data with coherency.  For example, remote reads and writes, or cache to cache transfers will transmit their data using DRS.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_USED.HOM",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Credit Used; HOM Message Class",
            .full_desc =
                "Number of times a VN1 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This counts the number of times a VN1 credit was used.  Note that a single VN1 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN1 will only count a single credit even though it may use multiple buffers.; Filter for the Home (HOM) message class.  HOM is generally used to send requests, request responses, and snoop responses.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_USED.NCB",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Credit Used; NCB Message Class",
            .full_desc =
                "Number of times a VN1 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This counts the number of times a VN1 credit was used.  Note that a single VN1 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN1 will only count a single credit even though it may use multiple buffers.; Filter for Non-Coherent Broadcast (NCB).  NCB is generally used to transmit data without coherency.  For example, non-coherent read data returns.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_USED.NCS",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Credit Used; NCS Message Class",
            .full_desc =
                "Number of times a VN1 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This counts the number of times a VN1 credit was used.  Note that a single VN1 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN1 will only count a single credit even though it may use multiple buffers.; Filter for Non-Coherent Standard (NCS).  NCS is commonly used for ?",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_USED.NDR",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Credit Used; NDR Message Class",
            .full_desc =
                "Number of times a VN1 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This counts the number of times a VN1 credit was used.  Note that a single VN1 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN1 will only count a single credit even though it may use multiple buffers.; NDR packets are used to transmit a variety of protocol flits including grants and completions (CMP).",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VN1_CREDITS_USED.SNP",
            .encoding =
                {
                    .code = 0x38ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VN1 Credit Used; SNP Message Class",
            .full_desc =
                "Number of times a VN1 credit was used on the DRS message channel.  In order for a request to be transferred across QPI, it must be guaranteed to have a flit buffer on the remote socket to sink into.  There are two credit pools, VNA and VN1.  VNA is a shared pool used to achieve high performance.  The VN1 pool has reserved entries for each message class and is used to prevent deadlock.  Requests first attempt to acquire a VNA credit, and then fall back to VN1 if they fail.  This counts the number of times a VN1 credit was used.  Note that a single VN1 credit holds access to potentially multiple flit buffers.  For example, a transfer that uses VNA could use 9 flit buffers and in that case uses 9 credits.  A transfer on VN1 will only count a single credit even though it may use multiple buffers.; Filter for Snoop (SNP) message class.  SNP is used for outgoing snoops.  Note that snoop responses flow on the HOM message class.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_ACQUIRED.AD",
            .encoding =
                {
                    .code = 0x33ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA credit Acquisitions; HOM Message Class",
            .full_desc =
                "Number of QPI VNA Credit acquisitions.  This event can be used in conjunction with the VNA In-Use Accumulator to calculate the average lifetime of a credit holder.  VNA credits are used by all message classes in order to communicate across QPI.  If a packet is unable to acquire credits, it will then attempt to use credits from the VN0 pool.  Note that a single packet may require multiple flit buffers (i.e. when data is being transferred).  Therefore, this event will increment by the number of credits acquired in each cycle.  Filtering based on message class is not provided.  One can count the number of packets transferred in a given message class using an qfclk event.; Filter for the Home (HOM) message class.  HOM is generally used to send requests, request responses, and snoop responses.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_ACQUIRED.BL",
            .encoding =
                {
                    .code = 0x33ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA credit Acquisitions; HOM Message Class",
            .full_desc =
                "Number of QPI VNA Credit acquisitions.  This event can be used in conjunction with the VNA In-Use Accumulator to calculate the average lifetime of a credit holder.  VNA credits are used by all message classes in order to communicate across QPI.  If a packet is unable to acquire credits, it will then attempt to use credits from the VN0 pool.  Note that a single packet may require multiple flit buffers (i.e. when data is being transferred).  Therefore, this event will increment by the number of credits acquired in each cycle.  Filtering based on message class is not provided.  One can count the number of packets transferred in a given message class using an qfclk event.; Filter for the Home (HOM) message class.  HOM is generally used to send requests, request responses, and snoop responses.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_REJECT.DRS",
            .encoding =
                {
                    .code = 0x34ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA Credit Reject; DRS Message Class",
            .full_desc =
                "Number of attempted VNA credit acquisitions that were rejected because the VNA credit pool was full (or almost full).  It is possible to filter this event by message class.  Some packets use more than one flit buffer, and therefore must acquire multiple credits.  Therefore, one could get a reject even if the VNA credits were not fully used up.  The VNA pool is generally used to provide the bulk of the QPI bandwidth (as opposed to the VN0 pool which is used to guarantee forward progress).  VNA credits can run out if the flit buffer on the receiving side starts to queue up substantially.  This can happen if the rest of the uncore is unable to drain the requests fast enough.; Filter for Data Response (DRS).  DRS is generally used to transmit data with coherency.  For example, remote reads and writes, or cache to cache transfers will transmit their data using DRS.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_REJECT.HOM",
            .encoding =
                {
                    .code = 0x34ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA Credit Reject; HOM Message Class",
            .full_desc =
                "Number of attempted VNA credit acquisitions that were rejected because the VNA credit pool was full (or almost full).  It is possible to filter this event by message class.  Some packets use more than one flit buffer, and therefore must acquire multiple credits.  Therefore, one could get a reject even if the VNA credits were not fully used up.  The VNA pool is generally used to provide the bulk of the QPI bandwidth (as opposed to the VN0 pool which is used to guarantee forward progress).  VNA credits can run out if the flit buffer on the receiving side starts to queue up substantially.  This can happen if the rest of the uncore is unable to drain the requests fast enough.; Filter for the Home (HOM) message class.  HOM is generally used to send requests, request responses, and snoop responses.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_REJECT.NCB",
            .encoding =
                {
                    .code = 0x34ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA Credit Reject; NCB Message Class",
            .full_desc =
                "Number of attempted VNA credit acquisitions that were rejected because the VNA credit pool was full (or almost full).  It is possible to filter this event by message class.  Some packets use more than one flit buffer, and therefore must acquire multiple credits.  Therefore, one could get a reject even if the VNA credits were not fully used up.  The VNA pool is generally used to provide the bulk of the QPI bandwidth (as opposed to the VN0 pool which is used to guarantee forward progress).  VNA credits can run out if the flit buffer on the receiving side starts to queue up substantially.  This can happen if the rest of the uncore is unable to drain the requests fast enough.; Filter for Non-Coherent Broadcast (NCB).  NCB is generally used to transmit data without coherency.  For example, non-coherent read data returns.",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_REJECT.NCS",
            .encoding =
                {
                    .code = 0x34ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA Credit Reject; NCS Message Class",
            .full_desc =
                "Number of attempted VNA credit acquisitions that were rejected because the VNA credit pool was full (or almost full).  It is possible to filter this event by message class.  Some packets use more than one flit buffer, and therefore must acquire multiple credits.  Therefore, one could get a reject even if the VNA credits were not fully used up.  The VNA pool is generally used to provide the bulk of the QPI bandwidth (as opposed to the VN0 pool which is used to guarantee forward progress).  VNA credits can run out if the flit buffer on the receiving side starts to queue up substantially.  This can happen if the rest of the uncore is unable to drain the requests fast enough.; Filter for Non-Coherent Standard (NCS).",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_REJECT.NDR",
            .encoding =
                {
                    .code = 0x34ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA Credit Reject; NDR Message Class",
            .full_desc =
                "Number of attempted VNA credit acquisitions that were rejected because the VNA credit pool was full (or almost full).  It is possible to filter this event by message class.  Some packets use more than one flit buffer, and therefore must acquire multiple credits.  Therefore, one could get a reject even if the VNA credits were not fully used up.  The VNA pool is generally used to provide the bulk of the QPI bandwidth (as opposed to the VN0 pool which is used to guarantee forward progress).  VNA credits can run out if the flit buffer on the receiving side starts to queue up substantially.  This can happen if the rest of the uncore is unable to drain the requests fast enough.; NDR packets are used to transmit a variety of protocol flits including grants and completions (CMP).",
        },
        {
            .pmu_type = PmuType::uncore_r3qpi,
            .id = "UNC_R3_VNA_CREDITS_REJECT.SNP",
            .encoding =
                {
                    .code = 0x34ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VNA Credit Reject; SNP Message Class",
            .full_desc =
                "Number of attempted VNA credit acquisitions that were rejected because the VNA credit pool was full (or almost full).  It is possible to filter this event by message class.  Some packets use more than one flit buffer, and therefore must acquire multiple credits.  Therefore, one could get a reject even if the VNA credits were not fully used up.  The VNA pool is generally used to provide the bulk of the QPI bandwidth (as opposed to the VN0 pool which is used to guarantee forward progress).  VNA credits can run out if the flit buffer on the receiving side starts to queue up substantially.  This can happen if the rest of the uncore is unable to drain the requests fast enough.; Filter for Snoop (SNP) message class.  SNP is used for outgoing snoops.  Note that snoop responses flow on the HOM message class.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_BOUNCE_CONTROL",
            .encoding =
                {
                    .code = 0xAULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bounce Control",
            .full_desc = "Bounce Control",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_CLOCKTICKS",
            .encoding =
                {
                    .code = 0x0ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uncore Clocks",
            .full_desc = "Uncore Clocks",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_FAST_ASSERTED",
            .encoding =
                {
                    .code = 0x9ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FaST wire asserted",
            .full_desc =
                "Counts the number of cycles either the local or incoming distress signals are asserted.  Incoming distress includes up, dn and across.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AD_USED.DOWN",
            .encoding =
                {
                    .code = 0x1BULL,
                    .umask = 0xCULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ring In Use; Down",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AD_USED.DOWN_EVEN",
            .encoding =
                {
                    .code = 0x1BULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ring In Use; Down and Event",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Event ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AD_USED.DOWN_ODD",
            .encoding =
                {
                    .code = 0x1BULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ring In Use; Down and Odd",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AD_USED.UP",
            .encoding =
                {
                    .code = 0x1BULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ring In Use; Up",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AD_USED.UP_EVEN",
            .encoding =
                {
                    .code = 0x1BULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ring In Use; Up and Even",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AD_USED.UP_ODD",
            .encoding =
                {
                    .code = 0x1BULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AD Ring In Use; Up and Odd",
            .full_desc =
                "Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AK_USED.DOWN",
            .encoding =
                {
                    .code = 0x1CULL,
                    .umask = 0xCULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AK Ring In Use; Down",
            .full_desc = "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AK_USED.DOWN_EVEN",
            .encoding =
                {
                    .code = 0x1CULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AK Ring In Use; Down and Event",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Event ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AK_USED.DOWN_ODD",
            .encoding =
                {
                    .code = 0x1CULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AK Ring In Use; Down and Odd",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AK_USED.UP",
            .encoding =
                {
                    .code = 0x1CULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AK Ring In Use; Up",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AK_USED.UP_EVEN",
            .encoding =
                {
                    .code = 0x1CULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AK Ring In Use; Up and Even",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_AK_USED.UP_ODD",
            .encoding =
                {
                    .code = 0x1CULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "AK Ring In Use; Up and Odd",
            .full_desc =
                "Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BL_USED.DOWN",
            .encoding =
                {
                    .code = 0x1DULL,
                    .umask = 0xCULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Down",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BL_USED.DOWN_EVEN",
            .encoding =
                {
                    .code = 0x1DULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Down and Event",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Event ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BL_USED.DOWN_ODD",
            .encoding =
                {
                    .code = 0x1DULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Down and Odd",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BL_USED.UP",
            .encoding =
                {
                    .code = 0x1DULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Up",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BL_USED.UP_EVEN",
            .encoding =
                {
                    .code = 0x1DULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Up and Even",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BL_USED.UP_ODD",
            .encoding =
                {
                    .code = 0x1DULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Up and Odd",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop. We really have two rings in HSX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BOUNCES.AD_CACHE",
            .encoding =
                {
                    .code = 0x5ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of LLC responses that bounced on the Ring.",
            .full_desc = "Number of LLC responses that bounced on the Ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BOUNCES.AK_CORE",
            .encoding =
                {
                    .code = 0x5ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of LLC responses that bounced on the Ring.; Acknowledgements to core",
            .full_desc =
                "Number of LLC responses that bounced on the Ring.; Acknowledgements to core",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BOUNCES.BL_CORE",
            .encoding =
                {
                    .code = 0x5ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of LLC responses that bounced on the Ring.; Data Responses to core",
            .full_desc =
                "Number of LLC responses that bounced on the Ring.; Data Responses to core",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_BOUNCES.IV_CORE",
            .encoding =
                {
                    .code = 0x5ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of LLC responses that bounced on the Ring.; Snoops of processor's cache.",
            .full_desc =
                "Number of LLC responses that bounced on the Ring.; Snoops of processor's cache.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_IV_USED.DN",
            .encoding =
                {
                    .code = 0x1EULL,
                    .umask = 0xCULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Any",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  There is only 1 IV ring in HSX.  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_IV_USED.UP",
            .encoding =
                {
                    .code = 0x1EULL,
                    .umask = 0x3ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "BL Ring in Use; Any",
            .full_desc =
                "Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.  There is only 1 IV ring in HSX.  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_SINK_STARVED.AD_CACHE",
            .encoding =
                {
                    .code = 0x6ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_S_RING_SINK_STARVED.AD_CACHE",
            .full_desc = "UNC_S_RING_SINK_STARVED.AD_CACHE",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_SINK_STARVED.AK_CORE",
            .encoding =
                {
                    .code = 0x6ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_S_RING_SINK_STARVED.AK_CORE",
            .full_desc = "UNC_S_RING_SINK_STARVED.AK_CORE",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_SINK_STARVED.BL_CORE",
            .encoding =
                {
                    .code = 0x6ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_S_RING_SINK_STARVED.BL_CORE",
            .full_desc = "UNC_S_RING_SINK_STARVED.BL_CORE",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RING_SINK_STARVED.IV_CORE",
            .encoding =
                {
                    .code = 0x6ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_S_RING_SINK_STARVED.IV_CORE",
            .full_desc = "UNC_S_RING_SINK_STARVED.IV_CORE",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BUSY_STARVED.AD_BNC",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; AD - Bounces",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress because a message (credited/bounceable) is  being sent.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BUSY_STARVED.AD_CRD",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; AD - Credits",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress because a message (credited/bounceable) is  being sent.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BUSY_STARVED.BL_BNC",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; BL - Bounces",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress because a message (credited/bounceable) is  being sent.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BUSY_STARVED.BL_CRD",
            .encoding =
                {
                    .code = 0x15ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; BL - Credits",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress because a message (credited/bounceable) is  being sent.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BYPASS.AD_BNC",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bypass; AD - Bounces",
            .full_desc = "Bypass the Sbo Ingress.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BYPASS.AD_CRD",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bypass; AD - Credits",
            .full_desc = "Bypass the Sbo Ingress.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BYPASS.AK",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bypass; AK",
            .full_desc = "Bypass the Sbo Ingress.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BYPASS.BL_BNC",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bypass; BL - Bounces",
            .full_desc = "Bypass the Sbo Ingress.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BYPASS.BL_CRD",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bypass; BL - Credits",
            .full_desc = "Bypass the Sbo Ingress.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_BYPASS.IV",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bypass; IV",
            .full_desc = "Bypass the Sbo Ingress.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_CRD_STARVED.AD_BNC",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; AD - Bounces",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress due to lack of credit.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_CRD_STARVED.AD_CRD",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; AD - Credits",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress due to lack of credit.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_CRD_STARVED.AK",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; AK",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress due to lack of credit.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_CRD_STARVED.BL_BNC",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; BL - Bounces",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress due to lack of credit.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_CRD_STARVED.BL_CRD",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; BL - Credits",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress due to lack of credit.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_CRD_STARVED.IFV",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; IVF Credit",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress due to lack of credit.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_CRD_STARVED.IV",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; IV",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Ingress cannot send a transaction onto the ring for a long period of time.  In this case, the Ingress but unable to forward to Egress due to lack of credit.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_INSERTS.AD_BNC",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; AD - Bounces",
            .full_desc =
                "Number of allocations into the Sbo Ingress  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_INSERTS.AD_CRD",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; AD - Credits",
            .full_desc =
                "Number of allocations into the Sbo Ingress  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_INSERTS.AK",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; AK",
            .full_desc =
                "Number of allocations into the Sbo Ingress  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_INSERTS.BL_BNC",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; BL - Bounces",
            .full_desc =
                "Number of allocations into the Sbo Ingress  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_INSERTS.BL_CRD",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; BL - Credits",
            .full_desc =
                "Number of allocations into the Sbo Ingress  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_INSERTS.IV",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Allocations; IV",
            .full_desc =
                "Number of allocations into the Sbo Ingress  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_OCCUPANCY.AD_BNC",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Occupancy; AD - Bounces",
            .full_desc =
                "Occupancy event for the Ingress buffers in the Sbo.  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_OCCUPANCY.AD_CRD",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Occupancy; AD - Credits",
            .full_desc =
                "Occupancy event for the Ingress buffers in the Sbo.  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_OCCUPANCY.AK",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Occupancy; AK",
            .full_desc =
                "Occupancy event for the Ingress buffers in the Sbo.  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_OCCUPANCY.BL_BNC",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Occupancy; BL - Bounces",
            .full_desc =
                "Occupancy event for the Ingress buffers in the Sbo.  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_OCCUPANCY.BL_CRD",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Occupancy; BL - Credits",
            .full_desc =
                "Occupancy event for the Ingress buffers in the Sbo.  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_RxR_OCCUPANCY.IV",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Ingress Occupancy; IV",
            .full_desc =
                "Occupancy event for the Ingress buffers in the Sbo.  The Ingress is used to queue up requests received from the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_ADS_USED.AD",
            .encoding =
                {
                    .code = 0x4ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_S_TxR_ADS_USED.AD",
            .full_desc = "UNC_S_TxR_ADS_USED.AD",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_ADS_USED.AK",
            .encoding =
                {
                    .code = 0x4ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_S_TxR_ADS_USED.AK",
            .full_desc = "UNC_S_TxR_ADS_USED.AK",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_ADS_USED.BL",
            .encoding =
                {
                    .code = 0x4ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_S_TxR_ADS_USED.BL",
            .full_desc = "UNC_S_TxR_ADS_USED.BL",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_INSERTS.AD_BNC",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Allocations; AD - Bounces",
            .full_desc =
                "Number of allocations into the Sbo Egress.  The Egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_INSERTS.AD_CRD",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Allocations; AD - Credits",
            .full_desc =
                "Number of allocations into the Sbo Egress.  The Egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_INSERTS.AK",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Allocations; AK",
            .full_desc =
                "Number of allocations into the Sbo Egress.  The Egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_INSERTS.BL_BNC",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Allocations; BL - Bounces",
            .full_desc =
                "Number of allocations into the Sbo Egress.  The Egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_INSERTS.BL_CRD",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Allocations; BL - Credits",
            .full_desc =
                "Number of allocations into the Sbo Egress.  The Egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_INSERTS.IV",
            .encoding =
                {
                    .code = 0x2ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Allocations; IV",
            .full_desc =
                "Number of allocations into the Sbo Egress.  The Egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_OCCUPANCY.AD_BNC",
            .encoding =
                {
                    .code = 0x1ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Occupancy; AD - Bounces",
            .full_desc =
                "Occupancy event for the Egress buffers in the Sbo.  The egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_OCCUPANCY.AD_CRD",
            .encoding =
                {
                    .code = 0x1ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Occupancy; AD - Credits",
            .full_desc =
                "Occupancy event for the Egress buffers in the Sbo.  The egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_OCCUPANCY.AK",
            .encoding =
                {
                    .code = 0x1ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Occupancy; AK",
            .full_desc =
                "Occupancy event for the Egress buffers in the Sbo.  The egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_OCCUPANCY.BL_BNC",
            .encoding =
                {
                    .code = 0x1ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Occupancy; BL - Bounces",
            .full_desc =
                "Occupancy event for the Egress buffers in the Sbo.  The egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_OCCUPANCY.BL_CRD",
            .encoding =
                {
                    .code = 0x1ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Occupancy; BL - Credits",
            .full_desc =
                "Occupancy event for the Egress buffers in the Sbo.  The egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_OCCUPANCY.IV",
            .encoding =
                {
                    .code = 0x1ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Egress Occupancy; IV",
            .full_desc =
                "Occupancy event for the Egress buffers in the Sbo.  The egress is used to queue up requests destined for the ring.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_STARVED.AD",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; Onto AD Ring",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_STARVED.AK",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; Onto AK Ring",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_STARVED.BL",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; Onto BL Ring",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.",
        },
        {
            .pmu_type = PmuType::uncore_sbox,
            .id = "UNC_S_TxR_STARVED.IV",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Injection Starvation; Onto IV Ring",
            .full_desc =
                "Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_CLOCKTICKS",
            .encoding =
                {
                    .code = 0x0ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UNC_U_CLOCKTICKS",
            .full_desc = "UNC_U_CLOCKTICKS",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_EVENT_MSG.DOORBELL_RCVD",
            .encoding =
                {
                    .code = 0x42ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "VLW Received",
            .full_desc =
                "Virtual Logical Wire (legacy) message were received from Uncore.   Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_FILTER_MATCH.DISABLE",
            .encoding =
                {
                    .code = 0x41ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Filter Match",
            .full_desc =
                "Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_FILTER_MATCH.ENABLE",
            .encoding =
                {
                    .code = 0x41ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Filter Match",
            .full_desc =
                "Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_FILTER_MATCH.U2C_DISABLE",
            .encoding =
                {
                    .code = 0x41ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Filter Match",
            .full_desc =
                "Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_FILTER_MATCH.U2C_ENABLE",
            .encoding =
                {
                    .code = 0x41ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Filter Match",
            .full_desc =
                "Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_PHOLD_CYCLES.ASSERT_TO_ACK",
            .encoding =
                {
                    .code = 0x45ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles PHOLD Assert to Ack; Assert to ACK",
            .full_desc = "PHOLD cycles.  Filter from source CoreID.",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_RACU_REQUESTS",
            .encoding =
                {
                    .code = 0x46ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "RACU Request",
            .full_desc =
                "Number outstanding register requests within message channel tracker",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.CMC",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x10ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; Correctable Machine Check",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.LIVELOCK",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x4ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; Livelock",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores; Filter by core",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.LTERROR",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x8ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; LTError",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores; Filter by core",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.MONITOR_T0",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x1ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; Monitor T0",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores; Filter by core",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.MONITOR_T1",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x2ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; Monitor T1",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores; Filter by core",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.OTHER",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x80ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; Other",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores; PREQ, PSMI, P2U, Thermal, PCUSMI, PMI",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.TRAP",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x40ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; Trap",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores",
        },
        {
            .pmu_type = PmuType::uncore_ubox,
            .id = "UNC_U_U2C_EVENTS.UMC",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0x20ULL,
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Monitor Sent to T0; Uncorrectable Machine Check",
            .full_desc =
                "Events coming from Uncore can be sent to one or all cores",
        },
    }};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents2));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

} // namespace

void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addStaticEventDefs(kAllowlistedEvents);
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addStaticEventDefs(kFullOnlyEvents0);
  pmu_manager.addStaticEventDefs(kFullOnlyEvents1);
  pmu_manager.addStaticEventDefs(kFullOnlyEvents2);
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace haswellx_uncore
} // namespace facebook::hbt::perf_event::generated
