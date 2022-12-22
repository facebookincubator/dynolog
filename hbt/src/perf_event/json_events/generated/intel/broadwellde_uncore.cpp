// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace broadwellde_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from broadwellde_uncore.json (900 events).

    Supported SKUs:
        - Arch: x86, Model: BDW-DE id: 86
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_BOUNCE_CONTROL",
      EventDef::Encoding{.code = 0xA, .umask = 0x0, .msr_values = {0}},
      R"(Bounce Control)",
      R"(Bounce Control)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_CLOCKTICKS",
      EventDef::Encoding{.code = 0x0, .umask = 0x0, .msr_values = {0}},
      R"(Uncore Clocks)",
      R"(Uncore Clocks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_COUNTER0_OCCUPANCY",
      EventDef::Encoding{.code = 0x1F, .umask = 0x0, .msr_values = {0}},
      R"(Counter 0 Occupancy)",
      R"(Since occupancy counts can only be captured in the Cbo's 0 counter, this event allows a user to capture occupancy related information by filtering the Cb0 occupancy count captured in Counter 0.   The filtering available is found in the control register - threshold, invert and edge detect.   E.g. setting threshold to 1 can effectively monitor how many cycles the monitored queue has an entry.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_FAST_ASSERTED",
      EventDef::Encoding{.code = 0x9, .umask = 0x0, .msr_values = {0}},
      R"(FaST wire asserted)",
      R"(Counts the number of cycles either the local distress or incoming distress signals are asserted.  Incoming distress includes both up and dn.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_LOOKUP.DATA_READ",
      EventDef::Encoding{.code = 0x34, .umask = 0x3, .msr_values = {0}},
      R"(Cache Lookups; Data Read Request)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_LOOKUP.WRITE",
      EventDef::Encoding{.code = 0x34, .umask = 0x5, .msr_values = {0}},
      R"(Cache Lookups; Write Requests)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cachable and UC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_LOOKUP.REMOTE_SNOOP",
      EventDef::Encoding{.code = 0x34, .umask = 0x9, .msr_values = {0}},
      R"(Cache Lookups; External Snoop Request)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Filters for only snoop requests coming from the remote socket(s) through the IPQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_LOOKUP.ANY",
      EventDef::Encoding{.code = 0x34, .umask = 0x11, .msr_values = {0}},
      R"(Cache Lookups; Any Request)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_LOOKUP.NID",
      EventDef::Encoding{.code = 0x34, .umask = 0x41, .msr_values = {0}},
      R"(Cache Lookups; Lookups that Match NID)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Qualify one of the other subevents by the Target NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.   In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_LOOKUP.READ",
      EventDef::Encoding{.code = 0x34, .umask = 0x21, .msr_values = {0}},
      R"(Cache Lookups; Any Read Request)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CBoGlCtrl[22:18] bits correspond to [FMESI] state.; Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_VICTIMS.M_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x1, .msr_values = {0}},
      R"(Lines Victimized; Lines in M state)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_VICTIMS.E_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x2, .msr_values = {0}},
      R"(Lines Victimized; Lines in E state)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_VICTIMS.I_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x4, .msr_values = {0}},
      R"(Lines Victimized; Lines in S State)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_VICTIMS.F_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x8, .msr_values = {0}},
      R"(Lines Victimized)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_VICTIMS.NID",
      EventDef::Encoding{.code = 0x37, .umask = 0x40, .msr_values = {0}},
      R"(Lines Victimized; Victimized Lines that Match NID)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.; Qualify one of the other subevents by the Target NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.   In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_LLC_VICTIMS.MISS",
      EventDef::Encoding{.code = 0x37, .umask = 0x10, .msr_values = {0}},
      R"(Lines Victimized)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_MISC.RSPI_WAS_FSE",
      EventDef::Encoding{.code = 0x39, .umask = 0x1, .msr_values = {0}},
      R"(Cbo Misc; Silent Snoop Eviction)",
      R"(Miscellaneous events in the Cbo.; Counts the number of times when a Snoop hit in FSE states and triggered a silent eviction.  This is useful because this information is lost in the PRE encodings.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_MISC.WC_ALIASING",
      EventDef::Encoding{.code = 0x39, .umask = 0x2, .msr_values = {0}},
      R"(Cbo Misc; Write Combining Aliasing)",
      R"(Miscellaneous events in the Cbo.; Counts the number of times that a USWC write (WCIL(F)) transaction hit in the LLC in M state, triggering a WBMtoI followed by the USWC write.  This occurs when there is WC aliasing.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_MISC.STARTED",
      EventDef::Encoding{.code = 0x39, .umask = 0x4, .msr_values = {0}},
      R"(Cbo Misc)",
      R"(Miscellaneous events in the Cbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_MISC.RFO_HIT_S",
      EventDef::Encoding{.code = 0x39, .umask = 0x8, .msr_values = {0}},
      R"(Cbo Misc; RFO HitS)",
      R"(Miscellaneous events in the Cbo.; Number of times that an RFO hit in S state.  This is useful for determining if it might be good for a workload to use RspIWB instead of RspSWB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_MISC.CVZERO_PREFETCH_VICTIM",
      EventDef::Encoding{.code = 0x39, .umask = 0x10, .msr_values = {0}},
      R"(Cbo Misc; Clean Victim with raw CV=0)",
      R"(Miscellaneous events in the Cbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_MISC.CVZERO_PREFETCH_MISS",
      EventDef::Encoding{.code = 0x39, .umask = 0x20, .msr_values = {0}},
      R"(Cbo Misc; DRd hitting non-M with raw CV=0)",
      R"(Miscellaneous events in the Cbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_QLRU.AGE0",
      EventDef::Encoding{.code = 0x3C, .umask = 0x1, .msr_values = {0}},
      R"(LRU Queue; LRU Age 0)",
      R"(How often age was set to 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_QLRU.AGE1",
      EventDef::Encoding{.code = 0x3C, .umask = 0x2, .msr_values = {0}},
      R"(LRU Queue; LRU Age 1)",
      R"(How often age was set to 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_QLRU.AGE2",
      EventDef::Encoding{.code = 0x3C, .umask = 0x4, .msr_values = {0}},
      R"(LRU Queue; LRU Age 2)",
      R"(How often age was set to 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_QLRU.AGE3",
      EventDef::Encoding{.code = 0x3C, .umask = 0x8, .msr_values = {0}},
      R"(LRU Queue; LRU Age 3)",
      R"(How often age was set to 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_QLRU.LRU_DECREMENT",
      EventDef::Encoding{.code = 0x3C, .umask = 0x10, .msr_values = {0}},
      R"(LRU Queue; LRU Bits Decremented)",
      R"(How often all LRU bits were decremented by 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_QLRU.VICTIM_NON_ZERO",
      EventDef::Encoding{.code = 0x3C, .umask = 0x20, .msr_values = {0}},
      R"(LRU Queue; Non-0 Aged Victim)",
      R"(How often we picked a victim that had a non-zero age)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AD_USED.UP_EVEN",
      EventDef::Encoding{.code = 0x1B, .umask = 0x1, .msr_values = {0}},
      R"(AD Ring In Use; Up and Even)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AD_USED.UP_ODD",
      EventDef::Encoding{.code = 0x1B, .umask = 0x2, .msr_values = {0}},
      R"(AD Ring In Use; Up and Odd)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AD_USED.DOWN_EVEN",
      EventDef::Encoding{.code = 0x1B, .umask = 0x4, .msr_values = {0}},
      R"(AD Ring In Use; Down and Even)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AD_USED.DOWN_ODD",
      EventDef::Encoding{.code = 0x1B, .umask = 0x8, .msr_values = {0}},
      R"(AD Ring In Use; Down and Odd)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AD_USED.CW",
      EventDef::Encoding{.code = 0x1B, .umask = 0x3, .msr_values = {0}},
      R"(AD Ring In Use; Up)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AD_USED.CCW",
      EventDef::Encoding{.code = 0x1B, .umask = 0xC, .msr_values = {0}},
      R"(AD Ring In Use; Down)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AD_USED.ALL",
      EventDef::Encoding{.code = 0x1B, .umask = 0xF, .msr_values = {0}},
      R"(AD Ring In Use; All)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AK_USED.UP_EVEN",
      EventDef::Encoding{.code = 0x1C, .umask = 0x1, .msr_values = {0}},
      R"(AK Ring In Use; Up and Even)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AK_USED.UP_ODD",
      EventDef::Encoding{.code = 0x1C, .umask = 0x2, .msr_values = {0}},
      R"(AK Ring In Use; Up and Odd)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AK_USED.DOWN_EVEN",
      EventDef::Encoding{.code = 0x1C, .umask = 0x4, .msr_values = {0}},
      R"(AK Ring In Use; Down and Even)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AK_USED.DOWN_ODD",
      EventDef::Encoding{.code = 0x1C, .umask = 0x8, .msr_values = {0}},
      R"(AK Ring In Use; Down and Odd)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AK_USED.CW",
      EventDef::Encoding{.code = 0x1C, .umask = 0x3, .msr_values = {0}},
      R"(AK Ring In Use; Up)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AK_USED.CCW",
      EventDef::Encoding{.code = 0x1C, .umask = 0xC, .msr_values = {0}},
      R"(AK Ring In Use; Down)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_AK_USED.ALL",
      EventDef::Encoding{.code = 0x1C, .umask = 0xF, .msr_values = {0}},
      R"(AK Ring In Use; All)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BL_USED.UP_EVEN",
      EventDef::Encoding{.code = 0x1D, .umask = 0x1, .msr_values = {0}},
      R"(BL Ring in Use; Up and Even)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BL_USED.UP_ODD",
      EventDef::Encoding{.code = 0x1D, .umask = 0x2, .msr_values = {0}},
      R"(BL Ring in Use; Up and Odd)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Up and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BL_USED.DOWN_EVEN",
      EventDef::Encoding{.code = 0x1D, .umask = 0x4, .msr_values = {0}},
      R"(BL Ring in Use; Down and Even)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BL_USED.DOWN_ODD",
      EventDef::Encoding{.code = 0x1D, .umask = 0x8, .msr_values = {0}},
      R"(BL Ring in Use; Down and Odd)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.; Filters for the Down and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BL_USED.CW",
      EventDef::Encoding{.code = 0x1D, .umask = 0x3, .msr_values = {0}},
      R"(BL Ring in Use; Up)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BL_USED.CCW",
      EventDef::Encoding{.code = 0x1D, .umask = 0xC, .msr_values = {0}},
      R"(BL Ring in Use; Down)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BL_USED.ALL",
      EventDef::Encoding{.code = 0x1D, .umask = 0xF, .msr_values = {0}},
      R"(BL Ring in Use; Down)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.We really have two rings in BDX -- a clockwise ring and a counter-clockwise ring.  On the left side of the ring, the UP direction is on the clockwise ring and DN is on the counter-clockwise ring.  On the right side of the ring, this is reversed.  The first half of the CBos are on the left side of the ring, and the 2nd half are on the right side of the ring.  In other words (for example), in a 4c part, Cbo 0 UP AD is NOT the same ring as CBo 2 UP AD because they are on opposite sides of the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BOUNCES.AD",
      EventDef::Encoding{.code = 0x5, .umask = 0x1, .msr_values = {0}},
      R"(Number of LLC responses that bounced on the Ring.; AD)",
      R"(Number of LLC responses that bounced on the Ring.; AD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BOUNCES.AK",
      EventDef::Encoding{.code = 0x5, .umask = 0x2, .msr_values = {0}},
      R"(Number of LLC responses that bounced on the Ring.; AK)",
      R"(Number of LLC responses that bounced on the Ring.; AK)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BOUNCES.BL",
      EventDef::Encoding{.code = 0x5, .umask = 0x4, .msr_values = {0}},
      R"(Number of LLC responses that bounced on the Ring.; BL)",
      R"(Number of LLC responses that bounced on the Ring.; BL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_BOUNCES.IV",
      EventDef::Encoding{.code = 0x5, .umask = 0x10, .msr_values = {0}},
      R"(Number of LLC responses that bounced on the Ring.; Snoops of processor's cache.)",
      R"(Number of LLC responses that bounced on the Ring.; Snoops of processor's cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_IV_USED.ANY",
      EventDef::Encoding{.code = 0x1E, .umask = 0xF, .msr_values = {0}},
      R"(BL Ring in Use; Any)",
      R"(Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in BDX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_IV_USED.UP",
      EventDef::Encoding{.code = 0x1E, .umask = 0x3, .msr_values = {0}},
      R"(BL Ring in Use; Any)",
      R"(Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in BDX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_IV_USED.DOWN",
      EventDef::Encoding{.code = 0x1E, .umask = 0xCC, .msr_values = {0}},
      R"(BL Ring in Use; Down)",
      R"(Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in BDX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters for Down polarity)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_IV_USED.DN",
      EventDef::Encoding{.code = 0x1E, .umask = 0xC, .msr_values = {0}},
      R"(BL Ring in Use; Any)",
      R"(Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.  There is only 1 IV ring in BDX  Therefore, if one wants to monitor the Even ring, they should select both UP_EVEN and DN_EVEN.  To monitor the Odd ring, they should select both UP_ODD and DN_ODD.; Filters any polarity)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_SINK_STARVED.AD",
      EventDef::Encoding{.code = 0x6, .umask = 0x1, .msr_values = {0}},
      R"(AD)",
      R"(AD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_SINK_STARVED.AK",
      EventDef::Encoding{.code = 0x6, .umask = 0x2, .msr_values = {0}},
      R"(AK)",
      R"(AK)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_SINK_STARVED.IV",
      EventDef::Encoding{.code = 0x6, .umask = 0x8, .msr_values = {0}},
      R"(IV)",
      R"(IV)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_SINK_STARVED.BL",
      EventDef::Encoding{.code = 0x6, .umask = 0x4, .msr_values = {0}},
      R"(BL)",
      R"(BL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RING_SRC_THRTL",
      EventDef::Encoding{.code = 0x7, .umask = 0x0, .msr_values = {0}},
      R"(Number of cycles the Cbo is actively throttling traffic onto the Ring in order to limit bounce traffic.)",
      R"(Number of cycles the Cbo is actively throttling traffic onto the Ring in order to limit bounce traffic.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_EXT_STARVED.IRQ",
      EventDef::Encoding{.code = 0x12, .umask = 0x1, .msr_values = {0}},
      R"(Ingress Arbiter Blocking Cycles; IPQ)",
      R"(Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.; IRQ is externally starved and therefore we are blocking the IPQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_EXT_STARVED.IPQ",
      EventDef::Encoding{.code = 0x12, .umask = 0x2, .msr_values = {0}},
      R"(Ingress Arbiter Blocking Cycles; IRQ)",
      R"(Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.; IPQ is externally startved and therefore we are blocking the IRQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_EXT_STARVED.PRQ",
      EventDef::Encoding{.code = 0x12, .umask = 0x4, .msr_values = {0}},
      R"(Ingress Arbiter Blocking Cycles; PRQ)",
      R"(Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_EXT_STARVED.ISMQ_BIDS",
      EventDef::Encoding{.code = 0x12, .umask = 0x8, .msr_values = {0}},
      R"(Ingress Arbiter Blocking Cycles; ISMQ_BID)",
      R"(Counts cycles in external starvation.  This occurs when one of the ingress queues is being starved by the other queues.; Number of times that the ISMQ Bid.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INSERTS.IRQ",
      EventDef::Encoding{.code = 0x13, .umask = 0x1, .msr_values = {0}},
      R"(Ingress Allocations; IRQ)",
      R"(Counts number of allocations per cycle into the specified Ingress queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INSERTS.IRQ_REJ",
      EventDef::Encoding{.code = 0x13, .umask = 0x2, .msr_values = {0}},
      R"(Ingress Allocations; IRQ Rejected)",
      R"(Counts number of allocations per cycle into the specified Ingress queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INSERTS.IPQ",
      EventDef::Encoding{.code = 0x13, .umask = 0x4, .msr_values = {0}},
      R"(Ingress Allocations; IPQ)",
      R"(Counts number of allocations per cycle into the specified Ingress queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INSERTS.PRQ",
      EventDef::Encoding{.code = 0x13, .umask = 0x10, .msr_values = {0}},
      R"(Ingress Allocations; PRQ)",
      R"(Counts number of allocations per cycle into the specified Ingress queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INSERTS.PRQ_REJ",
      EventDef::Encoding{.code = 0x13, .umask = 0x20, .msr_values = {0}},
      R"(Ingress Allocations; PRQ)",
      R"(Counts number of allocations per cycle into the specified Ingress queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INT_STARVED.IRQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x1, .msr_values = {0}},
      R"(Ingress Internal Starvation Cycles; IRQ)",
      R"(Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.; Cycles with the IRQ in Internal Starvation.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INT_STARVED.IPQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x4, .msr_values = {0}},
      R"(Ingress Internal Starvation Cycles; IPQ)",
      R"(Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.; Cycles with the IPQ in Internal Starvation.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INT_STARVED.ISMQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x8, .msr_values = {0}},
      R"(Ingress Internal Starvation Cycles; ISMQ)",
      R"(Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.; Cycles with the ISMQ in Internal Starvation.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_INT_STARVED.PRQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x10, .msr_values = {0}},
      R"(Ingress Internal Starvation Cycles; PRQ)",
      R"(Counts cycles in internal starvation.  This occurs when one (or more) of the entries in the ingress queue are being starved out by other entries in that queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IPQ_RETRY.ANY",
      EventDef::Encoding{.code = 0x31, .umask = 0x1, .msr_values = {0}},
      R"(Probe Queue Retries; Any Reject)",
      R"(Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request form the IPQ was retried because of a TOR reject.  TOR rejects from the IPQ can be caused by the Egress being full or Address Conflicts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IPQ_RETRY.FULL",
      EventDef::Encoding{.code = 0x31, .umask = 0x2, .msr_values = {0}},
      R"(Probe Queue Retries; No Egress Credits)",
      R"(Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request form the IPQ was retried because of a TOR reject from the Egress being full.  IPQ requests make use of the AD Egress for regular responses, the BL egress to forward data, and the AK egress to return credits.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IPQ_RETRY.ADDR_CONFLICT",
      EventDef::Encoding{.code = 0x31, .umask = 0x4, .msr_values = {0}},
      R"(Probe Queue Retries; Address Conflict)",
      R"(Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request form the IPQ was retried because of a TOR reject from an address conflicts.  Address conflicts out of the IPQ should be rare.  They will generally only occur if two different sockets are sending requests to the same address at the same time.  This is a true conflict case, unlike the IPQ Address Conflict which is commonly caused by prefetching characteristics.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IPQ_RETRY.QPI_CREDITS",
      EventDef::Encoding{.code = 0x31, .umask = 0x10, .msr_values = {0}},
      R"(Probe Queue Retries; No QPI Credits)",
      R"(Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IPQ_RETRY2.AD_SBO",
      EventDef::Encoding{.code = 0x28, .umask = 0x1, .msr_values = {0}},
      R"(Probe Queue Retries; No AD Sbo Credits)",
      R"(Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request from the IPQ was retried because of it lacked credits to send an AD packet to the Sbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IPQ_RETRY2.TARGET",
      EventDef::Encoding{.code = 0x28, .umask = 0x40, .msr_values = {0}},
      R"(Probe Queue Retries; Target Node Filter)",
      R"(Number of times a snoop (probe) request had to retry.  Filters exist to cover some of the common cases retries.; Counts the number of times that a request from the IPQ was retried filtered by the Target NodeID as specified in the Cbox's Filter register.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY.ANY",
      EventDef::Encoding{.code = 0x32, .umask = 0x1, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; Any Reject)",
      R"(Counts the number of IRQ retries that occur.  Requests from the IRQ are retried if they are rejected from the TOR pipeline for a variety of reasons.  Some of the most common reasons include if the Egress is full, there are no RTIDs, or there is a Physical Address match to another outstanding request.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY.FULL",
      EventDef::Encoding{.code = 0x32, .umask = 0x2, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; No Egress Credits)",
      R"(Counts the number of times that a request from the IRQ was retried because it failed to acquire an entry in the Egress.  The egress is the buffer that queues up for allocating onto the ring.  IRQ requests can make use of all four rings and all four Egresses.  If any of the queues that a given request needs to make use of are full, the request will be retried.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY.ADDR_CONFLICT",
      EventDef::Encoding{.code = 0x32, .umask = 0x4, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; Address Conflict)",
      R"(Counts the number of times that a request from the IRQ was retried because of an address match in the TOR.  In order to maintain coherency, requests to the same address are not allowed to pass each other up in the Cbo.  Therefore, if there is an outstanding request to a given address, one cannot issue another request to that address until it is complete.  This comes up most commonly with prefetches.  Outstanding prefetches occasionally will not complete their memory fetch and a demand request to the same address will then sit in the IRQ and get retried until the prefetch fills the data into the LLC.  Therefore, it will not be uncommon to see this case in high bandwidth streaming workloads when the LLC Prefetcher in the core is enabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY.RTID",
      EventDef::Encoding{.code = 0x32, .umask = 0x8, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; No RTIDs)",
      R"(Counts the number of times that requests from the IRQ were retried because there were no RTIDs available.  RTIDs are required after a request misses the LLC and needs to send snoops and/or requests to memory.  If there are no RTIDs available, requests will queue up in the IRQ and retry until one becomes available.  Note that there are multiple RTID pools for the different sockets.  There may be cases where the local RTIDs are all used, but requests destined for remote memory can still acquire an RTID because there are remote RTIDs available.  This event does not provide any filtering for this case.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY.QPI_CREDITS",
      EventDef::Encoding{.code = 0x32, .umask = 0x10, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; No QPI Credits)",
      R"(Number of requests rejects because of lack of QPI Ingress credits.  These credits are required in order to send transactions to the QPI agent.  Please see the QPI_IGR_CREDITS events for more information.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY.IIO_CREDITS",
      EventDef::Encoding{.code = 0x32, .umask = 0x20, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; No IIO Credits)",
      R"(Number of times a request attempted to acquire the NCS/NCB credit for sending messages on BL to the IIO.  There is a single credit in each CBo that is shared between the NCS and NCB message classes for sending transactions on the BL ring (such as read data) to the IIO.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY.NID",
      EventDef::Encoding{.code = 0x32, .umask = 0x40, .msr_values = {0}},
      R"(Ingress Request Queue Rejects)",
      R"(Qualify one of the other subevents by a given RTID destination NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER1.nid.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY2.AD_SBO",
      EventDef::Encoding{.code = 0x29, .umask = 0x1, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; No AD Sbo Credits)",
      R"(Counts the number of times that a request from the IPQ was retried because of it lacked credits to send an AD packet to the Sbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY2.BL_SBO",
      EventDef::Encoding{.code = 0x29, .umask = 0x2, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; No BL Sbo Credits)",
      R"(Counts the number of times that a request from the IPQ was retried because of it lacked credits to send an BL packet to the Sbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_IRQ_RETRY2.TARGET",
      EventDef::Encoding{.code = 0x29, .umask = 0x40, .msr_values = {0}},
      R"(Ingress Request Queue Rejects; Target Node Filter)",
      R"(Counts the number of times that a request from the IPQ was retried filtered by the Target NodeID as specified in the Cbox's Filter register.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY.ANY",
      EventDef::Encoding{.code = 0x33, .umask = 0x1, .msr_values = {0}},
      R"(ISMQ Retries; Any Reject)",
      R"(Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Counts the total number of times that a request from the ISMQ retried because of a TOR reject.  ISMQ requests generally will not need to retry (or at least ISMQ retries are less common than IRQ retries).  ISMQ requests will retry if they are not able to acquire a needed Egress credit to get onto the ring, or for cache evictions that need to acquire an RTID.  Most ISMQ requests already have an RTID, so eviction retries will be less common here.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY.FULL",
      EventDef::Encoding{.code = 0x33, .umask = 0x2, .msr_values = {0}},
      R"(ISMQ Retries; No Egress Credits)",
      R"(Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Counts the number of times that a request from the ISMQ retried because of a TOR reject caused by a lack of Egress credits. The egress is the buffer that queues up for allocating onto the ring.  If any of the Egress queues that a given request needs to make use of are full, the request will be retried.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY.RTID",
      EventDef::Encoding{.code = 0x33, .umask = 0x8, .msr_values = {0}},
      R"(ISMQ Retries; No RTIDs)",
      R"(Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Counts the number of times that a request from the ISMQ retried because of a TOR reject caused by no RTIDs.  M-state cache evictions are serviced through the ISMQ, and must acquire an RTID in order to write back to memory.  If no RTIDs are available, they will be retried.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY.QPI_CREDITS",
      EventDef::Encoding{.code = 0x33, .umask = 0x10, .msr_values = {0}},
      R"(ISMQ Retries; No QPI Credits)",
      R"(Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY.IIO_CREDITS",
      EventDef::Encoding{.code = 0x33, .umask = 0x20, .msr_values = {0}},
      R"(ISMQ Retries; No IIO Credits)",
      R"(Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Number of times a request attempted to acquire the NCS/NCB credit for sending messages on BL to the IIO.  There is a single credit in each CBo that is shared between the NCS and NCB message classes for sending transactions on the BL ring (such as read data) to the IIO.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY.WB_CREDITS",
      EventDef::Encoding{.code = 0x33, .umask = 0x80, .msr_values = {0}},
      R"(ISMQ Retries)",
      R"(Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Qualify one of the other subevents by a given RTID destination NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER1.nid.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY.NID",
      EventDef::Encoding{.code = 0x33, .umask = 0x40, .msr_values = {0}},
      R"(ISMQ Retries)",
      R"(Number of times a transaction flowing through the ISMQ had to retry.  Transaction pass through the ISMQ as responses for requests that already exist in the Cbo.  Some examples include: when data is returned or when snoop responses come back from the cores.; Qualify one of the other subevents by a given RTID destination NID.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER1.nid.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY2.AD_SBO",
      EventDef::Encoding{.code = 0x2A, .umask = 0x1, .msr_values = {0}},
      R"(ISMQ Request Queue Rejects; No AD Sbo Credits)",
      R"(Counts the number of times that a request from the ISMQ was retried because of it lacked credits to send an AD packet to the Sbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY2.BL_SBO",
      EventDef::Encoding{.code = 0x2A, .umask = 0x2, .msr_values = {0}},
      R"(ISMQ Request Queue Rejects; No BL Sbo Credits)",
      R"(Counts the number of times that a request from the ISMQ was retried because of it lacked credits to send an BL packet to the Sbo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_ISMQ_RETRY2.TARGET",
      EventDef::Encoding{.code = 0x2A, .umask = 0x40, .msr_values = {0}},
      R"(ISMQ Request Queue Rejects; Target Node Filter)",
      R"(Counts the number of times that a request from the ISMQ was retried filtered by the Target NodeID as specified in the Cbox's Filter register.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_OCCUPANCY.IRQ",
      EventDef::Encoding{.code = 0x11, .umask = 0x1, .msr_values = {0}},
      R"(Ingress Occupancy; IRQ)",
      R"(Counts number of entries in the specified Ingress queue in each cycle.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_OCCUPANCY.IRQ_REJ",
      EventDef::Encoding{.code = 0x11, .umask = 0x2, .msr_values = {0}},
      R"(Ingress Occupancy; IRQ Rejected)",
      R"(Counts number of entries in the specified Ingress queue in each cycle.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_OCCUPANCY.IPQ",
      EventDef::Encoding{.code = 0x11, .umask = 0x4, .msr_values = {0}},
      R"(Ingress Occupancy; IPQ)",
      R"(Counts number of entries in the specified Ingress queue in each cycle.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_RxR_OCCUPANCY.PRQ_REJ",
      EventDef::Encoding{.code = 0x11, .umask = 0x20, .msr_values = {0}},
      R"(Ingress Occupancy; PRQ Rejects)",
      R"(Counts number of entries in the specified Ingress queue in each cycle.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_SBO_CREDITS_ACQUIRED.AD",
      EventDef::Encoding{.code = 0x3D, .umask = 0x1, .msr_values = {0}},
      R"(SBo Credits Acquired; For AD Ring)",
      R"(Number of Sbo credits acquired in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_SBO_CREDITS_ACQUIRED.BL",
      EventDef::Encoding{.code = 0x3D, .umask = 0x2, .msr_values = {0}},
      R"(SBo Credits Acquired; For BL Ring)",
      R"(Number of Sbo credits acquired in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_SBO_CREDIT_OCCUPANCY.AD",
      EventDef::Encoding{.code = 0x3E, .umask = 0x1, .msr_values = {0}},
      R"(SBo Credits Occupancy; For AD Ring)",
      R"(Number of Sbo credits in use in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_SBO_CREDIT_OCCUPANCY.BL",
      EventDef::Encoding{.code = 0x3E, .umask = 0x2, .msr_values = {0}},
      R"(SBo Credits Occupancy; For BL Ring)",
      R"(Number of Sbo credits in use in a given cycle, per ring.  Each Cbo is assigned an Sbo it can communicate with.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x1, .msr_values = {0}},
      R"(TOR Inserts; Opcode Match)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Transactions inserted into the TOR that match an opcode (matched by Cn_MSR_PMON_BOX_FILTER.opc))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.EVICTION",
      EventDef::Encoding{.code = 0x35, .umask = 0x4, .msr_values = {0}},
      R"(TOR Inserts; Evictions)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Eviction transactions inserted into the TOR.  Evictions can be quick, such as when the line is in the F, S, or E states and no core valid bits are set.  They can also be longer if either CV bits are set (so the cores need to be snooped) and/or if there is a HitM (in which case it is necessary to write the request out to memory).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0x8, .msr_values = {0}},
      R"(TOR Inserts; All)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions inserted into the TOR.    This includes requests that reside in the TOR for a short time, such as LLC Hits that do not need to snoop cores or requests that get rejected and have to be retried through one of the ingress queues.  The TOR is more commonly a bottleneck in skews with smaller core counts, where the ratio of RTIDs to TOR entries is larger.  Note that there are reserved TOR entries for various request types, so it is possible that a given request type be blocked with an occupancy that is less than 20.  Also note that generally requests will not be able to arbitrate into the TOR pipeline if there are no available TOR slots.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.WB",
      EventDef::Encoding{.code = 0x35, .umask = 0x10, .msr_values = {0}},
      R"(TOR Inserts; Writebacks)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Write transactions inserted into the TOR.   This does not include RFO, but actual operations that contain data being sent from the core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.MISS_OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x3, .msr_values = {0}},
      R"(TOR Inserts; Miss Opcode Match)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that match an opcode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.NID_OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x41, .msr_values = {0}},
      R"(TOR Inserts; NID and Opcode Matched)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Transactions inserted into the TOR that match a NID and an opcode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.NID_EVICTION",
      EventDef::Encoding{.code = 0x35, .umask = 0x44, .msr_values = {0}},
      R"(TOR Inserts; NID Matched Evictions)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; NID matched eviction transactions inserted into the TOR.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.NID_ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0x48, .msr_values = {0}},
      R"(TOR Inserts; NID Matched)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All NID matched (matches an RTID destination) transactions inserted into the TOR.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.  In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.NID_WB",
      EventDef::Encoding{.code = 0x35, .umask = 0x50, .msr_values = {0}},
      R"(TOR Inserts; NID Matched Writebacks)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; NID matched write transactions inserted into the TOR.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.NID_MISS_OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x43, .msr_values = {0}},
      R"(TOR Inserts; NID and Opcode Matched Miss)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that match a NID and an opcode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.NID_MISS_ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0x4A, .msr_values = {0}},
      R"(TOR Inserts; NID Matched Miss All)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All NID matched miss requests that were inserted into the TOR.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.MISS_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x2A, .msr_values = {0}},
      R"(TOR Inserts; Misses to Local Memory)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that are satisifed by locally HOMed memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.MISS_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x8A, .msr_values = {0}},
      R"(TOR Inserts; Misses to Remote Memory)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions inserted into the TOR that are satisifed by remote caches or remote memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x28, .msr_values = {0}},
      R"(TOR Inserts; Local Memory)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions inserted into the TOR that are satisifed by locally HOMed memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x88, .msr_values = {0}},
      R"(TOR Inserts; Remote Memory)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions inserted into the TOR that are satisifed by remote caches or remote memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.MISS_LOCAL_OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x23, .msr_values = {0}},
      R"(TOR Inserts; Misses to Local Memory - Opcode Matched)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions, satisifed by an opcode, inserted into the TOR that are satisifed by locally HOMed memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.MISS_REMOTE_OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x83, .msr_values = {0}},
      R"(TOR Inserts; Misses to Remote Memory - Opcode Matched)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; Miss transactions, satisifed by an opcode,  inserted into the TOR that are satisifed by remote caches or remote memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.LOCAL_OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0}},
      R"(TOR Inserts; Local Memory - Opcode Matched)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions, satisifed by an opcode,  inserted into the TOR that are satisifed by locally HOMed memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_INSERTS.REMOTE_OPCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x81, .msr_values = {0}},
      R"(TOR Inserts; Remote Memory - Opcode Matched)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent.  There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc  to DRD (0x182).; All transactions, satisifed by an opcode,  inserted into the TOR that are satisifed by remote caches or remote memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x1, .msr_values = {0}},
      R"(TOR Occupancy; Opcode Match)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); TOR entries that match an opcode (matched by Cn_MSR_PMON_BOX_FILTER.opc).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.EVICTION",
      EventDef::Encoding{.code = 0x36, .umask = 0x4, .msr_values = {0}},
      R"(TOR Occupancy; Evictions)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding eviction transactions in the TOR.  Evictions can be quick, such as when the line is in the F, S, or E states and no core valid bits are set.  They can also be longer if either CV bits are set (so the cores need to be snooped) and/or if there is a HitM (in which case it is necessary to write the request out to memory).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0x8, .msr_values = {0}},
      R"(TOR Occupancy; Any)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); All valid TOR entries.  This includes requests that reside in the TOR for a short time, such as LLC Hits that do not need to snoop cores or requests that get rejected and have to be retried through one of the ingress queues.  The TOR is more commonly a bottleneck in skews with smaller core counts, where the ratio of RTIDs to TOR entries is larger.  Note that there are reserved TOR entries for various request types, so it is possible that a given request type be blocked with an occupancy that is less than 20.  Also note that generally requests will not be able to arbitrate into the TOR pipeline if there are no available TOR slots.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.MISS_OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x3, .msr_values = {0}},
      R"(TOR Occupancy; Miss Opcode Match)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); TOR entries for miss transactions that match an opcode. This generally means that the request was sent to memory or MMIO.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.MISS_ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0xA, .msr_values = {0}},
      R"(TOR Occupancy; Miss All)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding miss requests in the TOR.  'Miss' means the allocation requires an RTID.  This generally means that the request was sent to memory or MMIO.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.NID_OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x41, .msr_values = {0}},
      R"(TOR Occupancy; NID and Opcode Matched)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); TOR entries that match a NID and an opcode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.NID_EVICTION",
      EventDef::Encoding{.code = 0x36, .umask = 0x44, .msr_values = {0}},
      R"(TOR Occupancy; NID Matched Evictions)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding NID matched eviction transactions in the TOR .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.NID_ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0x48, .msr_values = {0}},
      R"(TOR Occupancy; NID Matched)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of NID matched outstanding requests in the TOR.  The NID is programmed in Cn_MSR_PMON_BOX_FILTER.nid.In conjunction with STATE = I, it is possible to monitor misses to specific NIDs in the system.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.NID_MISS_OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x43, .msr_values = {0}},
      R"(TOR Occupancy; NID and Opcode Matched Miss)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss requests in the TOR that match a NID and an opcode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.NID_MISS_ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0x4A, .msr_values = {0}},
      R"(TOR Occupancy; NID Matched)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss requests in the TOR that match a NID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.MISS_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x2A, .msr_values = {0}},
      R"(TOR Occupancy)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.MISS_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x8A, .msr_values = {0}},
      R"(TOR Occupancy)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x28, .msr_values = {0}},
      R"(TOR Occupancy)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x88, .msr_values = {0}},
      R"(TOR Occupancy)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.MISS_LOCAL_OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x23, .msr_values = {0}},
      R"(TOR Occupancy; Misses to Local Memory - Opcode Matched)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss transactions, satisifed by an opcode, in the TOR that are satisifed by locally HOMed memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.MISS_REMOTE_OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x83, .msr_values = {0}},
      R"(TOR Occupancy; Misses to Remote Memory - Opcode Matched)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding Miss transactions, satisifed by an opcode, in the TOR that are satisifed by remote caches or remote memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.LOCAL_OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0}},
      R"(TOR Occupancy; Local Memory - Opcode Matched)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding  transactions, satisifed by an opcode,  in the TOR that are satisifed by locally HOMed memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.REMOTE_OPCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x81, .msr_values = {0}},
      R"(TOR Occupancy; Remote Memory - Opcode Matched)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Number of outstanding  transactions, satisifed by an opcode,  in the TOR that are satisifed by remote caches or remote memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.WB",
      EventDef::Encoding{.code = 0x36, .umask = 0x10, .msr_values = {0}},
      R"(TOR Occupancy; Writebacks)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); Write transactions in the TOR.   This does not include RFO, but actual operations that contain data being sent from the core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TOR_OCCUPANCY.NID_WB",
      EventDef::Encoding{.code = 0x36, .umask = 0x50, .msr_values = {0}},
      R"(TOR Occupancy; NID Matched Writebacks)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   There are a number of subevent 'filters' but only a subset of the subevent combinations are valid.  Subevents that require an opcode or NID match require the Cn_MSR_PMON_BOX_FILTER.{opc, nid} field to be set.  If, for example, one wanted to count DRD Local Misses, one should select MISS_OPC_MATCH and set Cn_MSR_PMON_BOX_FILTER.opc to DRD (0x182); NID matched write transactions int the TOR.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_ADS_USED.AD",
      EventDef::Encoding{.code = 0x4, .umask = 0x1, .msr_values = {0}},
      R"(Onto AD Ring)",
      R"(Onto AD Ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_ADS_USED.AK",
      EventDef::Encoding{.code = 0x4, .umask = 0x2, .msr_values = {0}},
      R"(Onto AK Ring)",
      R"(Onto AK Ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_ADS_USED.BL",
      EventDef::Encoding{.code = 0x4, .umask = 0x4, .msr_values = {0}},
      R"(Onto BL Ring)",
      R"(Onto BL Ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_INSERTS.AD_CACHE",
      EventDef::Encoding{.code = 0x2, .umask = 0x1, .msr_values = {0}},
      R"(Egress Allocations; AD - Cachebo)",
      R"(Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the AD ring.  Some example include outbound requests, snoop requests, and snoop responses.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_INSERTS.AK_CACHE",
      EventDef::Encoding{.code = 0x2, .umask = 0x2, .msr_values = {0}},
      R"(Egress Allocations; AK - Cachebo)",
      R"(Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the AK ring.  This is commonly used for credit returns and GO responses.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_INSERTS.BL_CACHE",
      EventDef::Encoding{.code = 0x2, .umask = 0x4, .msr_values = {0}},
      R"(Egress Allocations; BL - Cacheno)",
      R"(Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the BL ring.  This is commonly used to send data from the cache to various destinations.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_INSERTS.IV_CACHE",
      EventDef::Encoding{.code = 0x2, .umask = 0x8, .msr_values = {0}},
      R"(Egress Allocations; IV - Cachebo)",
      R"(Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Cachebo destined for the IV ring.  This is commonly used for snoops to the cores.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_INSERTS.AD_CORE",
      EventDef::Encoding{.code = 0x2, .umask = 0x10, .msr_values = {0}},
      R"(Egress Allocations; AD - Corebo)",
      R"(Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Corebo destined for the AD ring.  This is commonly used for outbound requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_INSERTS.AK_CORE",
      EventDef::Encoding{.code = 0x2, .umask = 0x20, .msr_values = {0}},
      R"(Egress Allocations; AK - Corebo)",
      R"(Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Corebo destined for the AK ring.  This is commonly used for snoop responses coming from the core and destined for a Cachebo.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_INSERTS.BL_CORE",
      EventDef::Encoding{.code = 0x2, .umask = 0x40, .msr_values = {0}},
      R"(Egress Allocations; BL - Corebo)",
      R"(Number of allocations into the Cbo Egress.  The Egress is used to queue up requests destined for the ring.; Ring transactions from the Corebo destined for the BL ring.  This is commonly used for transferring writeback data to the cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_STARVED.AK_BOTH",
      EventDef::Encoding{.code = 0x3, .umask = 0x2, .msr_values = {0}},
      R"(Injection Starvation; Onto AK Ring)",
      R"(Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that both AK egresses spent in starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_STARVED.BL_BOTH",
      EventDef::Encoding{.code = 0x3, .umask = 0x4, .msr_values = {0}},
      R"(Injection Starvation; Onto BL Ring)",
      R"(Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that both BL egresses spent in starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_STARVED.IV",
      EventDef::Encoding{.code = 0x3, .umask = 0x8, .msr_values = {0}},
      R"(Injection Starvation; Onto IV Ring)",
      R"(Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that the cachebo IV egress spent in starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_C_TxR_STARVED.AD_CORE",
      EventDef::Encoding{.code = 0x3, .umask = 0x10, .msr_values = {0}},
      R"(Injection Starvation; Onto AD Ring (to core))",
      R"(Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.; cycles that the core AD egress spent in starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_ADDR_OPC_MATCH.FILT",
      EventDef::Encoding{.code = 0x20, .umask = 0x3, .msr_values = {0}},
      R"(QPI Address/Opcode Match; Address & Opcode Match)",
      R"(QPI Address/Opcode Match; Address & Opcode Match)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_ADDR_OPC_MATCH.ADDR",
      EventDef::Encoding{.code = 0x20, .umask = 0x1, .msr_values = {0}},
      R"(QPI Address/Opcode Match; Address)",
      R"(QPI Address/Opcode Match; Address)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_ADDR_OPC_MATCH.OPC",
      EventDef::Encoding{.code = 0x20, .umask = 0x2, .msr_values = {0}},
      R"(QPI Address/Opcode Match; Opcode)",
      R"(QPI Address/Opcode Match; Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_ADDR_OPC_MATCH.AD",
      EventDef::Encoding{.code = 0x20, .umask = 0x4, .msr_values = {0}},
      R"(QPI Address/Opcode Match; AD Opcodes)",
      R"(QPI Address/Opcode Match; AD Opcodes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_ADDR_OPC_MATCH.BL",
      EventDef::Encoding{.code = 0x20, .umask = 0x8, .msr_values = {0}},
      R"(QPI Address/Opcode Match; BL Opcodes)",
      R"(QPI Address/Opcode Match; BL Opcodes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_ADDR_OPC_MATCH.AK",
      EventDef::Encoding{.code = 0x20, .umask = 0x10, .msr_values = {0}},
      R"(QPI Address/Opcode Match; AK Opcodes)",
      R"(QPI Address/Opcode Match; AK Opcodes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_BT_CYCLES_NE",
      EventDef::Encoding{.code = 0x42, .umask = 0x0, .msr_values = {0}},
      R"(BT Cycles Not Empty)",
      R"(Cycles the Backup Tracker (BT) is not empty. The BT is the actual HOM tracker in IVT.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_BT_TO_HT_NOT_ISSUED.INCOMING_SNP_HAZARD",
      EventDef::Encoding{.code = 0x51, .umask = 0x2, .msr_values = {0}},
      R"(BT to HT Not Issued; Incoming Snoop Hazard)",
      R"(Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming snoop hazard)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_BT_TO_HT_NOT_ISSUED.INCOMING_BL_HAZARD",
      EventDef::Encoding{.code = 0x51, .umask = 0x4, .msr_values = {0}},
      R"(BT to HT Not Issued; Incoming Data Hazard)",
      R"(Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming BL data hazard)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_BT_TO_HT_NOT_ISSUED.RSPACKCFLT_HAZARD",
      EventDef::Encoding{.code = 0x51, .umask = 0x8, .msr_values = {0}},
      R"(BT to HT Not Issued; Incoming Data Hazard)",
      R"(Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming BL data hazard)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_BT_TO_HT_NOT_ISSUED.WBMDATA_HAZARD",
      EventDef::Encoding{.code = 0x51, .umask = 0x10, .msr_values = {0}},
      R"(BT to HT Not Issued; Incoming Data Hazard)",
      R"(Counts the number of cycles when the HA does not issue transaction from BT to HT.; Cycles unable to issue from BT due to incoming BL data hazard)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_BYPASS_IMC.TAKEN",
      EventDef::Encoding{.code = 0x14, .umask = 0x1, .msr_values = {0}},
      R"(HA to iMC Bypass; Taken)",
      R"(Counts the number of times when the HA was able to bypass was attempted.  This is a latency optimization for situations when there is light loadings on the memory subsystem.  This can be filted by when the bypass was taken and when it was not.; Filter for transactions that succeeded in taking the bypass.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_BYPASS_IMC.NOT_TAKEN",
      EventDef::Encoding{.code = 0x14, .umask = 0x2, .msr_values = {0}},
      R"(HA to iMC Bypass; Not Taken)",
      R"(Counts the number of times when the HA was able to bypass was attempted.  This is a latency optimization for situations when there is light loadings on the memory subsystem.  This can be filted by when the bypass was taken and when it was not.; Filter for transactions that could not take the bypass.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_CLOCKTICKS",
      EventDef::Encoding{.code = 0x0, .umask = 0x0, .msr_values = {0}},
      R"(uclks)",
      R"(Counts the number of uclks in the HA.  This will be slightly different than the count in the Ubox because of enable/freeze delays.  The HA is on the other side of the die from the fixed Ubox uclk counter, so the drift could be somewhat larger than in units that are closer like the QPI Agent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECT2CORE_COUNT",
      EventDef::Encoding{.code = 0x11, .umask = 0x0, .msr_values = {0}},
      R"(Direct2Core Messages Sent)",
      R"(Number of Direct2Core messages sent)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECT2CORE_CYCLES_DISABLED",
      EventDef::Encoding{.code = 0x12, .umask = 0x0, .msr_values = {0}},
      R"(Cycles when Direct2Core was Disabled)",
      R"(Number of cycles in which Direct2Core was disabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECT2CORE_TXN_OVERRIDE",
      EventDef::Encoding{.code = 0x13, .umask = 0x0, .msr_values = {0}},
      R"(Number of Reads that had Direct2Core Overridden)",
      R"(Number of Reads where Direct2Core overridden)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECTORY_LAT_OPT",
      EventDef::Encoding{.code = 0x41, .umask = 0x0, .msr_values = {0}},
      R"(Directory Lat Opt Return)",
      R"(Directory Latency Optimization Data Return Path Taken. When directory mode is enabled and the directory retuned for a read is Dir=I, then data can be returned using a faster path if certain conditions are met (credits, free pipeline, etc).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECTORY_LOOKUP.SNP",
      EventDef::Encoding{.code = 0xC, .umask = 0x1, .msr_values = {0}},
      R"(Directory Lookups; Snoop Needed)",
      R"(Counts the number of transactions that looked up the directory.  Can be filtered by requests that had to snoop and those that did not have to.; Filters for transactions that had to send one or more snoops because the directory bit was set.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECTORY_LOOKUP.NO_SNP",
      EventDef::Encoding{.code = 0xC, .umask = 0x2, .msr_values = {0}},
      R"(Directory Lookups; Snoop Not Needed)",
      R"(Counts the number of transactions that looked up the directory.  Can be filtered by requests that had to snoop and those that did not have to.; Filters for transactions that did not have to send any snoops because the directory bit was clear.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECTORY_UPDATE.SET",
      EventDef::Encoding{.code = 0xD, .umask = 0x1, .msr_values = {0}},
      R"(Directory Updates; Directory Set)",
      R"(Counts the number of directory updates that were required.  These result in writes to the memory controller.  This can be filtered by directory sets and directory clears.; Filter for directory sets.  This occurs when a remote read transaction requests memory, bringing it to a remote cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECTORY_UPDATE.CLEAR",
      EventDef::Encoding{.code = 0xD, .umask = 0x2, .msr_values = {0}},
      R"(Directory Updates; Directory Clear)",
      R"(Counts the number of directory updates that were required.  These result in writes to the memory controller.  This can be filtered by directory sets and directory clears.; Filter for directory clears.  This occurs when snoops were sent and all returned with RspI.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_DIRECTORY_UPDATE.ANY",
      EventDef::Encoding{.code = 0xD, .umask = 0x3, .msr_values = {0}},
      R"(Directory Updates; Any Directory Update)",
      R"(Counts the number of directory updates that were required.  These result in writes to the memory controller.  This can be filtered by directory sets and directory clears.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.READ_OR_INVITOE",
      EventDef::Encoding{.code = 0x71, .umask = 0x1, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE)",
      R"(Counts Number of Hits in HitMe Cache; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.WBMTOI",
      EventDef::Encoding{.code = 0x71, .umask = 0x2, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is WbMtoI)",
      R"(Counts Number of Hits in HitMe Cache; op is WbMtoI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.ACKCNFLTWBI",
      EventDef::Encoding{.code = 0x71, .umask = 0x4, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is AckCnfltWbI)",
      R"(Counts Number of Hits in HitMe Cache; op is AckCnfltWbI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.WBMTOE_OR_S",
      EventDef::Encoding{.code = 0x71, .umask = 0x8, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is WbMtoE or WbMtoS)",
      R"(Counts Number of Hits in HitMe Cache; op is WbMtoE or WbMtoS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.RSPFWDI_REMOTE",
      EventDef::Encoding{.code = 0x71, .umask = 0x10, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a remote request)",
      R"(Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a remote request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.RSPFWDI_LOCAL",
      EventDef::Encoding{.code = 0x71, .umask = 0x20, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a local request)",
      R"(Counts Number of Hits in HitMe Cache; op is RspIFwd or RspIFwdWb for a local request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.RSPFWDS",
      EventDef::Encoding{.code = 0x71, .umask = 0x40, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is RsSFwd or RspSFwdWb)",
      R"(Counts Number of Hits in HitMe Cache; op is RsSFwd or RspSFwdWb)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.RSP",
      EventDef::Encoding{.code = 0x71, .umask = 0x80, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI)",
      R"(Counts Number of Hits in HitMe Cache; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.ALLOCS",
      EventDef::Encoding{.code = 0x71, .umask = 0x70, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; Allocations)",
      R"(Counts Number of Hits in HitMe Cache; Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.EVICTS",
      EventDef::Encoding{.code = 0x71, .umask = 0x42, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; Allocations)",
      R"(Counts Number of Hits in HitMe Cache; Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.INVALS",
      EventDef::Encoding{.code = 0x71, .umask = 0x26, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; Invalidations)",
      R"(Counts Number of Hits in HitMe Cache; Invalidations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.ALL",
      EventDef::Encoding{.code = 0x71, .umask = 0xFF, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; All Requests)",
      R"(Counts Number of Hits in HitMe Cache; All Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT.HOM",
      EventDef::Encoding{.code = 0x71, .umask = 0xF, .msr_values = {0}},
      R"(Counts Number of Hits in HitMe Cache; HOM Requests)",
      R"(Counts Number of Hits in HitMe Cache; HOM Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.READ_OR_INVITOE",
      EventDef::Encoding{.code = 0x72, .umask = 0x1, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.WBMTOI",
      EventDef::Encoding{.code = 0x72, .umask = 0x2, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoI)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.ACKCNFLTWBI",
      EventDef::Encoding{.code = 0x72, .umask = 0x4, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is AckCnfltWbI)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is AckCnfltWbI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.WBMTOE_OR_S",
      EventDef::Encoding{.code = 0x72, .umask = 0x8, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoE or WbMtoS)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is WbMtoE or WbMtoS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.RSPFWDI_REMOTE",
      EventDef::Encoding{.code = 0x72, .umask = 0x10, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a remote request)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a remote request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.RSPFWDI_LOCAL",
      EventDef::Encoding{.code = 0x72, .umask = 0x20, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a local request)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RspIFwd or RspIFwdWb for a local request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.RSPFWDS",
      EventDef::Encoding{.code = 0x72, .umask = 0x40, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RsSFwd or RspSFwdWb)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RsSFwd or RspSFwdWb)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.RSP",
      EventDef::Encoding{.code = 0x72, .umask = 0x80, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.ALL",
      EventDef::Encoding{.code = 0x72, .umask = 0xFF, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; All Requests)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; All Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_HIT_PV_BITS_SET.HOM",
      EventDef::Encoding{.code = 0x72, .umask = 0xF, .msr_values = {0}},
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; HOM Requests)",
      R"(Accumulates Number of PV bits set on HitMe Cache Hits; HOM Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.READ_OR_INVITOE",
      EventDef::Encoding{.code = 0x70, .umask = 0x1, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE)",
      R"(Counts Number of times HitMe Cache is accessed; op is RdCode, RdData, RdDataMigratory, RdInvOwn, RdCur or InvItoE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.WBMTOI",
      EventDef::Encoding{.code = 0x70, .umask = 0x2, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is WbMtoI)",
      R"(Counts Number of times HitMe Cache is accessed; op is WbMtoI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.ACKCNFLTWBI",
      EventDef::Encoding{.code = 0x70, .umask = 0x4, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is AckCnfltWbI)",
      R"(Counts Number of times HitMe Cache is accessed; op is AckCnfltWbI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.WBMTOE_OR_S",
      EventDef::Encoding{.code = 0x70, .umask = 0x8, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is WbMtoE or WbMtoS)",
      R"(Counts Number of times HitMe Cache is accessed; op is WbMtoE or WbMtoS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.RSPFWDI_REMOTE",
      EventDef::Encoding{.code = 0x70, .umask = 0x10, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a remote request)",
      R"(Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a remote request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.RSPFWDI_LOCAL",
      EventDef::Encoding{.code = 0x70, .umask = 0x20, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a local request)",
      R"(Counts Number of times HitMe Cache is accessed; op is RspIFwd or RspIFwdWb for a local request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.RSPFWDS",
      EventDef::Encoding{.code = 0x70, .umask = 0x40, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is RsSFwd or RspSFwdWb)",
      R"(Counts Number of times HitMe Cache is accessed; op is RsSFwd or RspSFwdWb)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.RSP",
      EventDef::Encoding{.code = 0x70, .umask = 0x80, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI)",
      R"(Counts Number of times HitMe Cache is accessed; op is RspI, RspIWb, RspS, RspSWb, RspCnflt or RspCnfltWbI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.ALLOCS",
      EventDef::Encoding{.code = 0x70, .umask = 0x70, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; Allocations)",
      R"(Counts Number of times HitMe Cache is accessed; Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.INVALS",
      EventDef::Encoding{.code = 0x70, .umask = 0x26, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; Invalidations)",
      R"(Counts Number of times HitMe Cache is accessed; Invalidations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.ALL",
      EventDef::Encoding{.code = 0x70, .umask = 0xFF, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; All Requests)",
      R"(Counts Number of times HitMe Cache is accessed; All Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_HITME_LOOKUP.HOM",
      EventDef::Encoding{.code = 0x70, .umask = 0xF, .msr_values = {0}},
      R"(Counts Number of times HitMe Cache is accessed; HOM Requests)",
      R"(Counts Number of times HitMe Cache is accessed; HOM Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IGR_NO_CREDIT_CYCLES.AD_QPI0",
      EventDef::Encoding{.code = 0x22, .umask = 0x1, .msr_values = {0}},
      R"(Cycles without QPI Ingress Credits; AD to QPI Link 0)",
      R"(Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IGR_NO_CREDIT_CYCLES.AD_QPI1",
      EventDef::Encoding{.code = 0x22, .umask = 0x2, .msr_values = {0}},
      R"(Cycles without QPI Ingress Credits; AD to QPI Link 1)",
      R"(Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IGR_NO_CREDIT_CYCLES.BL_QPI0",
      EventDef::Encoding{.code = 0x22, .umask = 0x4, .msr_values = {0}},
      R"(Cycles without QPI Ingress Credits; BL to QPI Link 0)",
      R"(Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IGR_NO_CREDIT_CYCLES.BL_QPI1",
      EventDef::Encoding{.code = 0x22, .umask = 0x8, .msr_values = {0}},
      R"(Cycles without QPI Ingress Credits; BL to QPI Link 1)",
      R"(Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IGR_NO_CREDIT_CYCLES.AD_QPI2",
      EventDef::Encoding{.code = 0x22, .umask = 0x10, .msr_values = {0}},
      R"(Cycles without QPI Ingress Credits; BL to QPI Link 0)",
      R"(Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IGR_NO_CREDIT_CYCLES.BL_QPI2",
      EventDef::Encoding{.code = 0x22, .umask = 0x20, .msr_values = {0}},
      R"(Cycles without QPI Ingress Credits; BL to QPI Link 1)",
      R"(Counts the number of cycles when the HA does not have credits to send messages to the QPI Agent.  This can be filtered by the different credit pools and the different links.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IMC_READS.NORMAL",
      EventDef::Encoding{.code = 0x17, .umask = 0x1, .msr_values = {0}},
      R"(HA to iMC Normal Priority Reads Issued; Normal Priority)",
      R"(Count of the number of reads issued to any of the memory controller channels.  This can be filtered by the priority of the reads.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IMC_RETRY",
      EventDef::Encoding{.code = 0x1E, .umask = 0x0, .msr_values = {0}},
      R"(Retry Events)",
      R"(Retry Events)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IMC_WRITES.FULL",
      EventDef::Encoding{.code = 0x1A, .umask = 0x1, .msr_values = {0}},
      R"(HA to iMC Full Line Writes Issued; Full Line Non-ISOCH)",
      R"(Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IMC_WRITES.PARTIAL",
      EventDef::Encoding{.code = 0x1A, .umask = 0x2, .msr_values = {0}},
      R"(HA to iMC Full Line Writes Issued; Partial Non-ISOCH)",
      R"(Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IMC_WRITES.FULL_ISOCH",
      EventDef::Encoding{.code = 0x1A, .umask = 0x4, .msr_values = {0}},
      R"(HA to iMC Full Line Writes Issued; ISOCH Full Line)",
      R"(Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IMC_WRITES.PARTIAL_ISOCH",
      EventDef::Encoding{.code = 0x1A, .umask = 0x8, .msr_values = {0}},
      R"(HA to iMC Full Line Writes Issued; ISOCH Partial)",
      R"(Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IMC_WRITES.ALL",
      EventDef::Encoding{.code = 0x1A, .umask = 0xF, .msr_values = {0}},
      R"(HA to iMC Full Line Writes Issued; All Writes)",
      R"(Counts the total number of full line writes issued from the HA into the memory controller.  This counts for all four channels.  It can be filtered by full/partial and ISOCH/non-ISOCH.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_BACKPRESSURE.SAT",
      EventDef::Encoding{.code = 0x61, .umask = 0x1, .msr_values = {0}},
      R"(IOT Backpressure)",
      R"(IOT Backpressure)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_BACKPRESSURE.HUB",
      EventDef::Encoding{.code = 0x61, .umask = 0x2, .msr_values = {0}},
      R"(IOT Backpressure)",
      R"(IOT Backpressure)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_CTS_EAST_LO.CTS0",
      EventDef::Encoding{.code = 0x64, .umask = 0x1, .msr_values = {0}},
      R"(IOT Common Trigger Sequencer - Lo)",
      R"(Debug Mask/Match Tie-Ins)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_CTS_EAST_LO.CTS1",
      EventDef::Encoding{.code = 0x64, .umask = 0x2, .msr_values = {0}},
      R"(IOT Common Trigger Sequencer - Lo)",
      R"(Debug Mask/Match Tie-Ins)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_CTS_HI.CTS2",
      EventDef::Encoding{.code = 0x65, .umask = 0x1, .msr_values = {0}},
      R"(IOT Common Trigger Sequencer - Hi)",
      R"(Debug Mask/Match Tie-Ins)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_CTS_HI.CTS3",
      EventDef::Encoding{.code = 0x65, .umask = 0x2, .msr_values = {0}},
      R"(IOT Common Trigger Sequencer - Hi)",
      R"(Debug Mask/Match Tie-Ins)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_CTS_WEST_LO.CTS0",
      EventDef::Encoding{.code = 0x62, .umask = 0x1, .msr_values = {0}},
      R"(IOT Common Trigger Sequencer - Lo)",
      R"(Debug Mask/Match Tie-Ins)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_IOT_CTS_WEST_LO.CTS1",
      EventDef::Encoding{.code = 0x62, .umask = 0x2, .msr_values = {0}},
      R"(IOT Common Trigger Sequencer - Lo)",
      R"(Debug Mask/Match Tie-Ins)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB.READS_LOCAL",
      EventDef::Encoding{.code = 0x53, .umask = 0x2, .msr_values = {0}},
      R"(OSB Snoop Broadcast; Local Reads)",
      R"(Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x53, .umask = 0x4, .msr_values = {0}},
      R"(OSB Snoop Broadcast; Local InvItoE)",
      R"(Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB.REMOTE",
      EventDef::Encoding{.code = 0x53, .umask = 0x8, .msr_values = {0}},
      R"(OSB Snoop Broadcast; Remote)",
      R"(Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB.CANCELLED",
      EventDef::Encoding{.code = 0x53, .umask = 0x10, .msr_values = {0}},
      R"(OSB Snoop Broadcast; Cancelled)",
      R"(Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.; OSB Snoop broadcast cancelled due to D2C or Other. OSB cancel is counted when OSB local read is not allowed even when the transaction in local InItoE. It also counts D2C OSB cancel, but also includes the cases were D2C was not set in the first place for the transaction coming from the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB.READS_LOCAL_USEFUL",
      EventDef::Encoding{.code = 0x53, .umask = 0x20, .msr_values = {0}},
      R"(OSB Snoop Broadcast; Reads Local -  Useful)",
      R"(Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB.REMOTE_USEFUL",
      EventDef::Encoding{.code = 0x53, .umask = 0x40, .msr_values = {0}},
      R"(OSB Snoop Broadcast; Remote - Useful)",
      R"(Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB_EDR.ALL",
      EventDef::Encoding{.code = 0x54, .umask = 0x1, .msr_values = {0}},
      R"(OSB Early Data Return; All)",
      R"(Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB_EDR.READS_LOCAL_I",
      EventDef::Encoding{.code = 0x54, .umask = 0x2, .msr_values = {0}},
      R"(OSB Early Data Return; Reads to Local  I)",
      R"(Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB_EDR.READS_REMOTE_I",
      EventDef::Encoding{.code = 0x54, .umask = 0x4, .msr_values = {0}},
      R"(OSB Early Data Return; Reads to Remote I)",
      R"(Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB_EDR.READS_LOCAL_S",
      EventDef::Encoding{.code = 0x54, .umask = 0x8, .msr_values = {0}},
      R"(OSB Early Data Return; Reads to Local S)",
      R"(Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_OSB_EDR.READS_REMOTE_S",
      EventDef::Encoding{.code = 0x54, .umask = 0x10, .msr_values = {0}},
      R"(OSB Early Data Return; Reads to Remote S)",
      R"(Counts the number of transactions that broadcast snoop due to OSB, but found clean data in memory and was able to do early data return)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.READS",
      EventDef::Encoding{.code = 0x1, .umask = 0x3, .msr_values = {0}},
      R"(Read and Write Requests; Reads)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; Incoming ead requests.  This is a good proxy for LLC Read Misses (including RFOs).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.WRITES",
      EventDef::Encoding{.code = 0x1, .umask = 0xC, .msr_values = {0}},
      R"(Read and Write Requests; Writes)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; Incoming write requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.READS_LOCAL",
      EventDef::Encoding{.code = 0x1, .umask = 0x1, .msr_values = {0}},
      R"(Read and Write Requests; Local Reads)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only read requests coming from the local socket.  This is a good proxy for LLC Read Misses (including RFOs) from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.READS_REMOTE",
      EventDef::Encoding{.code = 0x1, .umask = 0x2, .msr_values = {0}},
      R"(Read and Write Requests; Remote Reads)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only read requests coming from the remote socket.  This is a good proxy for LLC Read Misses (including RFOs) from the remote socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.WRITES_LOCAL",
      EventDef::Encoding{.code = 0x1, .umask = 0x4, .msr_values = {0}},
      R"(Read and Write Requests; Local Writes)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only writes coming from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.WRITES_REMOTE",
      EventDef::Encoding{.code = 0x1, .umask = 0x8, .msr_values = {0}},
      R"(Read and Write Requests; Remote Writes)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only writes coming from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x1, .umask = 0x10, .msr_values = {0}},
      R"(Read and Write Requests; Local InvItoEs)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only InvItoEs coming from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_REQUESTS.INVITOE_REMOTE",
      EventDef::Encoding{.code = 0x1, .umask = 0x20, .msr_values = {0}},
      R"(Read and Write Requests; Remote InvItoEs)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).; This filter includes only InvItoEs coming from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AD_USED.CW_EVEN",
      EventDef::Encoding{.code = 0x3E, .umask = 0x1, .msr_values = {0}},
      R"(HA AD Ring in Use; Clockwise and Even)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AD_USED.CW_ODD",
      EventDef::Encoding{.code = 0x3E, .umask = 0x2, .msr_values = {0}},
      R"(HA AD Ring in Use; Clockwise and Odd)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AD_USED.CCW_EVEN",
      EventDef::Encoding{.code = 0x3E, .umask = 0x4, .msr_values = {0}},
      R"(HA AD Ring in Use; Counterclockwise and Even)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AD_USED.CCW_ODD",
      EventDef::Encoding{.code = 0x3E, .umask = 0x8, .msr_values = {0}},
      R"(HA AD Ring in Use; Counterclockwise and Odd)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AD_USED.CW",
      EventDef::Encoding{.code = 0x3E, .umask = 0x3, .msr_values = {0}},
      R"(HA AD Ring in Use; Clockwise)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AD_USED.CCW",
      EventDef::Encoding{.code = 0x3E, .umask = 0xC, .msr_values = {0}},
      R"(HA AD Ring in Use; Counterclockwise)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AK_USED.CW_EVEN",
      EventDef::Encoding{.code = 0x3F, .umask = 0x1, .msr_values = {0}},
      R"(HA AK Ring in Use; Clockwise and Even)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AK_USED.CW_ODD",
      EventDef::Encoding{.code = 0x3F, .umask = 0x2, .msr_values = {0}},
      R"(HA AK Ring in Use; Clockwise and Odd)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AK_USED.CCW_EVEN",
      EventDef::Encoding{.code = 0x3F, .umask = 0x4, .msr_values = {0}},
      R"(HA AK Ring in Use; Counterclockwise and Even)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AK_USED.CCW_ODD",
      EventDef::Encoding{.code = 0x3F, .umask = 0x8, .msr_values = {0}},
      R"(HA AK Ring in Use; Counterclockwise and Odd)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AK_USED.CW",
      EventDef::Encoding{.code = 0x3F, .umask = 0x3, .msr_values = {0}},
      R"(HA AK Ring in Use; Clockwise)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AK_USED.CCW",
      EventDef::Encoding{.code = 0x3F, .umask = 0xC, .msr_values = {0}},
      R"(HA AK Ring in Use; Counterclockwise)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_AK_USED.ALL",
      EventDef::Encoding{.code = 0x3F, .umask = 0xF, .msr_values = {0}},
      R"(HA AK Ring in Use; All)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_BL_USED.CW_EVEN",
      EventDef::Encoding{.code = 0x40, .umask = 0x1, .msr_values = {0}},
      R"(HA BL Ring in Use; Clockwise and Even)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_BL_USED.CW_ODD",
      EventDef::Encoding{.code = 0x40, .umask = 0x2, .msr_values = {0}},
      R"(HA BL Ring in Use; Clockwise and Odd)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_BL_USED.CCW_EVEN",
      EventDef::Encoding{.code = 0x40, .umask = 0x4, .msr_values = {0}},
      R"(HA BL Ring in Use; Counterclockwise and Even)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_BL_USED.CCW_ODD",
      EventDef::Encoding{.code = 0x40, .umask = 0x8, .msr_values = {0}},
      R"(HA BL Ring in Use; Counterclockwise and Odd)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_BL_USED.CW",
      EventDef::Encoding{.code = 0x40, .umask = 0x3, .msr_values = {0}},
      R"(HA BL Ring in Use; Clockwise)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_BL_USED.CCW",
      EventDef::Encoding{.code = 0x40, .umask = 0xC, .msr_values = {0}},
      R"(HA BL Ring in Use; Counterclockwise)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RING_BL_USED.ALL",
      EventDef::Encoding{.code = 0x40, .umask = 0xF, .msr_values = {0}},
      R"(HA BL Ring in Use; All)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN0",
      EventDef::Encoding{.code = 0x15, .umask = 0x1, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Regular; Channel 0)",
      R"(Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN1",
      EventDef::Encoding{.code = 0x15, .umask = 0x2, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Regular; Channel 1)",
      R"(Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN2",
      EventDef::Encoding{.code = 0x15, .umask = 0x4, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Regular; Channel 2)",
      R"(Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_REG_CREDITS.CHN3",
      EventDef::Encoding{.code = 0x15, .umask = 0x8, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Regular; Channel 3)",
      R"(Counts the number of cycles when there are no regular credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN0",
      EventDef::Encoding{.code = 0x16, .umask = 0x1, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Special; Channel 0)",
      R"(Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN1",
      EventDef::Encoding{.code = 0x16, .umask = 0x2, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Special; Channel 1)",
      R"(Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN2",
      EventDef::Encoding{.code = 0x16, .umask = 0x4, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Special; Channel 2)",
      R"(Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_RPQ_CYCLES_NO_SPEC_CREDITS.CHN3",
      EventDef::Encoding{.code = 0x16, .umask = 0x8, .msr_values = {0}},
      R"(iMC RPQ Credits Empty - Special; Channel 3)",
      R"(Counts the number of cycles when there are no special credits available for posting reads from the HA into the iMC.  In order to send reads into the memory controller, the HA must first acquire a credit for the iMC's RPQ (read pending queue).  This queue is broken into regular credits/buffers that are used by general reads, and special requests such as ISOCH reads.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO0_CREDITS_ACQUIRED.AD",
      EventDef::Encoding{.code = 0x68, .umask = 0x1, .msr_values = {0}},
      R"(SBo0 Credits Acquired; For AD Ring)",
      R"(Number of Sbo 0 credits acquired in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO0_CREDITS_ACQUIRED.BL",
      EventDef::Encoding{.code = 0x68, .umask = 0x2, .msr_values = {0}},
      R"(SBo0 Credits Acquired; For BL Ring)",
      R"(Number of Sbo 0 credits acquired in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO0_CREDIT_OCCUPANCY.AD",
      EventDef::Encoding{.code = 0x6A, .umask = 0x1, .msr_values = {0}},
      R"(SBo0 Credits Occupancy; For AD Ring)",
      R"(Number of Sbo 0 credits in use in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO0_CREDIT_OCCUPANCY.BL",
      EventDef::Encoding{.code = 0x6A, .umask = 0x2, .msr_values = {0}},
      R"(SBo0 Credits Occupancy; For BL Ring)",
      R"(Number of Sbo 0 credits in use in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO1_CREDITS_ACQUIRED.AD",
      EventDef::Encoding{.code = 0x69, .umask = 0x1, .msr_values = {0}},
      R"(SBo1 Credits Acquired; For AD Ring)",
      R"(Number of Sbo 1 credits acquired in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO1_CREDITS_ACQUIRED.BL",
      EventDef::Encoding{.code = 0x69, .umask = 0x2, .msr_values = {0}},
      R"(SBo1 Credits Acquired; For BL Ring)",
      R"(Number of Sbo 1 credits acquired in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO1_CREDIT_OCCUPANCY.AD",
      EventDef::Encoding{.code = 0x6B, .umask = 0x1, .msr_values = {0}},
      R"(SBo1 Credits Occupancy; For AD Ring)",
      R"(Number of Sbo 1 credits in use in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SBO1_CREDIT_OCCUPANCY.BL",
      EventDef::Encoding{.code = 0x6B, .umask = 0x2, .msr_values = {0}},
      R"(SBo1 Credits Occupancy; For BL Ring)",
      R"(Number of Sbo 1 credits in use in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOPS_RSP_AFTER_DATA.LOCAL",
      EventDef::Encoding{.code = 0xA, .umask = 0x1, .msr_values = {0}},
      R"(Data beat the Snoop Responses; Local Requests)",
      R"(Counts the number of reads when the snoop was on the critical path to the data return.; This filter includes only requests coming from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOPS_RSP_AFTER_DATA.REMOTE",
      EventDef::Encoding{.code = 0xA, .umask = 0x2, .msr_values = {0}},
      R"(Data beat the Snoop Responses; Remote Requests)",
      R"(Counts the number of reads when the snoop was on the critical path to the data return.; This filter includes only requests coming from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_CYCLES_NE.LOCAL",
      EventDef::Encoding{.code = 0x8, .umask = 0x1, .msr_values = {0}},
      R"(Cycles with Snoops Outstanding; Local Requests)",
      R"(Counts cycles when one or more snoops are outstanding.; This filter includes only requests coming from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_CYCLES_NE.REMOTE",
      EventDef::Encoding{.code = 0x8, .umask = 0x2, .msr_values = {0}},
      R"(Cycles with Snoops Outstanding; Remote Requests)",
      R"(Counts cycles when one or more snoops are outstanding.; This filter includes only requests coming from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_CYCLES_NE.ALL",
      EventDef::Encoding{.code = 0x8, .umask = 0x3, .msr_values = {0}},
      R"(Cycles with Snoops Outstanding; All Requests)",
      R"(Counts cycles when one or more snoops are outstanding.; Tracked for snoops from both local and remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_OCCUPANCY.LOCAL",
      EventDef::Encoding{.code = 0x9, .umask = 0x1, .msr_values = {0}},
      R"(Tracker Snoops Outstanding Accumulator; Local Requests)",
      R"(Accumulates the occupancy of either the local HA tracker pool that have snoops pending in every cycle.    This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if an HT (HomeTracker) entry is available and this occupancy is decremented when all the snoop responses have returned.; This filter includes only requests coming from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_OCCUPANCY.REMOTE",
      EventDef::Encoding{.code = 0x9, .umask = 0x2, .msr_values = {0}},
      R"(Tracker Snoops Outstanding Accumulator; Remote Requests)",
      R"(Accumulates the occupancy of either the local HA tracker pool that have snoops pending in every cycle.    This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if an HT (HomeTracker) entry is available and this occupancy is decremented when all the snoop responses have returned.; This filter includes only requests coming from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_RESP.RSPI",
      EventDef::Encoding{.code = 0x21, .umask = 0x1, .msr_values = {0}},
      R"(Snoop Responses Received; RspI)",
      R"(Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoops responses of RspI.  RspI is returned when the remote cache does not have the data, or when the remote cache silently evicts data (such as when an RFO hits non-modified data).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_RESP.RSPS",
      EventDef::Encoding{.code = 0x21, .umask = 0x2, .msr_values = {0}},
      R"(Snoop Responses Received; RspS)",
      R"(Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoop responses of RspS.  RspS is returned when a remote cache has data but is not forwarding it.  It is a way to let the requesting socket know that it cannot allocate the data in E state.  No data is sent with S RspS.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_RESP.RSPIFWD",
      EventDef::Encoding{.code = 0x21, .umask = 0x4, .msr_values = {0}},
      R"(Snoop Responses Received; RspIFwd)",
      R"(Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoop responses of RspIFwd.  This is returned when a remote caching agent forwards data and the requesting agent is able to acquire the data in E or M states.  This is commonly returned with RFO transactions.  It can be either a HitM or a HitFE.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_RESP.RSPSFWD",
      EventDef::Encoding{.code = 0x21, .umask = 0x8, .msr_values = {0}},
      R"(Snoop Responses Received; RspSFwd)",
      R"(Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for a snoop response of RspSFwd.  This is returned when a remote caching agent forwards data but holds on to its currentl copy.  This is common for data and code reads that hit in a remote socket in E or F state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_RESP.RSP_WB",
      EventDef::Encoding{.code = 0x21, .umask = 0x10, .msr_values = {0}},
      R"(Snoop Responses Received; Rsp*WB)",
      R"(Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for a snoop response of RspIWB or RspSWB.  This is returned when a non-RFO request hits in M state.  Data and Code Reads can return either RspIWB or RspSWB depending on how the system has been configured.  InvItoE transactions will also return RspIWB because they must acquire ownership.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_RESP.RSP_FWD_WB",
      EventDef::Encoding{.code = 0x21, .umask = 0x20, .msr_values = {0}},
      R"(Snoop Responses Received; Rsp*Fwd*WB)",
      R"(Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for a snoop response of Rsp*Fwd*WB.  This snoop response is only used in 4s systems.  It is used when a snoop HITM's in a remote caching agent and it directly forwards data to a requestor, and simultaneously returns data to the home to be written back to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNOOP_RESP.RSPCNFLCT",
      EventDef::Encoding{.code = 0x21, .umask = 0x40, .msr_values = {0}},
      R"(Snoop Responses Received; RSPCNFLCT*)",
      R"(Counts the total number of RspI snoop responses received.  Whenever a snoops are issued, one or more snoop responses will be returned depending on the topology of the system.   In systems larger than 2s, when multiple snoops are returned this will count all the snoops that are received.  For example, if 3 snoops were issued and returned RspI, RspS, and RspSFwd; then each of these sub-events would increment by 1.; Filters for snoops responses of RspConflict.  This is returned when a snoop finds an existing outstanding transaction in a remote caching agent when it CAMs that caching agent.  This triggers conflict resolution hardware.  This covers both RspCnflct and RspCnflctWbI.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.RSPI",
      EventDef::Encoding{.code = 0x60, .umask = 0x1, .msr_values = {0}},
      R"(Snoop Responses Received Local; RspI)",
      R"(Number of snoop responses received for a Local  request; Filters for snoops responses of RspI.  RspI is returned when the remote cache does not have the data, or when the remote cache silently evicts data (such as when an RFO hits non-modified data).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.RSPS",
      EventDef::Encoding{.code = 0x60, .umask = 0x2, .msr_values = {0}},
      R"(Snoop Responses Received Local; RspS)",
      R"(Number of snoop responses received for a Local  request; Filters for snoop responses of RspS.  RspS is returned when a remote cache has data but is not forwarding it.  It is a way to let the requesting socket know that it cannot allocate the data in E state.  No data is sent with S RspS.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.RSPIFWD",
      EventDef::Encoding{.code = 0x60, .umask = 0x4, .msr_values = {0}},
      R"(Snoop Responses Received Local; RspIFwd)",
      R"(Number of snoop responses received for a Local  request; Filters for snoop responses of RspIFwd.  This is returned when a remote caching agent forwards data and the requesting agent is able to acquire the data in E or M states.  This is commonly returned with RFO transactions.  It can be either a HitM or a HitFE.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.RSPSFWD",
      EventDef::Encoding{.code = 0x60, .umask = 0x8, .msr_values = {0}},
      R"(Snoop Responses Received Local; RspSFwd)",
      R"(Number of snoop responses received for a Local  request; Filters for a snoop response of RspSFwd.  This is returned when a remote caching agent forwards data but holds on to its currentl copy.  This is common for data and code reads that hit in a remote socket in E or F state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.RSPxWB",
      EventDef::Encoding{.code = 0x60, .umask = 0x10, .msr_values = {0}},
      R"(Snoop Responses Received Local; Rsp*WB)",
      R"(Number of snoop responses received for a Local  request; Filters for a snoop response of RspIWB or RspSWB.  This is returned when a non-RFO request hits in M state.  Data and Code Reads can return either RspIWB or RspSWB depending on how the system has been configured.  InvItoE transactions will also return RspIWB because they must acquire ownership.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.RSPxFWDxWB",
      EventDef::Encoding{.code = 0x60, .umask = 0x20, .msr_values = {0}},
      R"(Snoop Responses Received Local; Rsp*FWD*WB)",
      R"(Number of snoop responses received for a Local  request; Filters for a snoop response of Rsp*Fwd*WB.  This snoop response is only used in 4s systems.  It is used when a snoop HITM's in a remote caching agent and it directly forwards data to a requestor, and simultaneously returns data to the home to be written back to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.RSPCNFLCT",
      EventDef::Encoding{.code = 0x60, .umask = 0x40, .msr_values = {0}},
      R"(Snoop Responses Received Local; RspCnflct)",
      R"(Number of snoop responses received for a Local  request; Filters for snoops responses of RspConflict.  This is returned when a snoop finds an existing outstanding transaction in a remote caching agent when it CAMs that caching agent.  This triggers conflict resolution hardware.  This covers both RspCnflct and RspCnflctWbI.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_SNP_RESP_RECV_LOCAL.OTHER",
      EventDef::Encoding{.code = 0x60, .umask = 0x80, .msr_values = {0}},
      R"(Snoop Responses Received Local; Other)",
      R"(Number of snoop responses received for a Local  request; Filters for all other snoop responses.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_STALL_NO_SBO_CREDIT.SBO0_AD",
      EventDef::Encoding{.code = 0x6C, .umask = 0x1, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo0, AD Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_STALL_NO_SBO_CREDIT.SBO1_AD",
      EventDef::Encoding{.code = 0x6C, .umask = 0x2, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo1, AD Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_STALL_NO_SBO_CREDIT.SBO0_BL",
      EventDef::Encoding{.code = 0x6C, .umask = 0x4, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo0, BL Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_STALL_NO_SBO_CREDIT.SBO1_BL",
      EventDef::Encoding{.code = 0x6C, .umask = 0x8, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo1, BL Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION0",
      EventDef::Encoding{.code = 0x1B, .umask = 0x1, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 0)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION1",
      EventDef::Encoding{.code = 0x1B, .umask = 0x2, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 1)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION2",
      EventDef::Encoding{.code = 0x1B, .umask = 0x4, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 2)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION3",
      EventDef::Encoding{.code = 0x1B, .umask = 0x8, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 3)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION4",
      EventDef::Encoding{.code = 0x1B, .umask = 0x10, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 4)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION5",
      EventDef::Encoding{.code = 0x1B, .umask = 0x20, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 5)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION6",
      EventDef::Encoding{.code = 0x1B, .umask = 0x40, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 6)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G0.REGION7",
      EventDef::Encoding{.code = 0x1B, .umask = 0x80, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 0; TAD Region 7)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 0 to 7.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G1.REGION8",
      EventDef::Encoding{.code = 0x1C, .umask = 0x1, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 1; TAD Region 8)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G1.REGION9",
      EventDef::Encoding{.code = 0x1C, .umask = 0x2, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 1; TAD Region 9)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G1.REGION10",
      EventDef::Encoding{.code = 0x1C, .umask = 0x4, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 1; TAD Region 10)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TAD_REQUESTS_G1.REGION11",
      EventDef::Encoding{.code = 0x1C, .umask = 0x8, .msr_values = {0}},
      R"(HA Requests to a TAD Region - Group 1; TAD Region 11)",
      R"(Counts the number of HA requests to a given TAD region.  There are up to 11 TAD (target address decode) regions in each home agent.  All requests destined for the memory controller must first be decoded to determine which TAD region they are in.  This event is filtered based on the TAD region ID, and covers regions 8 to 10.  This event is useful for understanding how applications are using the memory that is spread across the different memory regions.  It is particularly useful for Monroe systems that use the TAD to enable individual channels to enter self-refresh to save power.; Filters request made to TAD Region 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_CYCLES_FULL.GP",
      EventDef::Encoding{.code = 0x2, .umask = 0x1, .msr_values = {0}},
      R"(Tracker Cycles Full; Cycles GP Completely Used)",
      R"(Counts the number of cycles when the local HA tracker pool is completely used.  This can be used with edge detect to identify the number of situations when the pool became fully utilized.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, the system could be starved for RTIDs but not fill up the HA trackers.  HA trackers are allocated as soon as a request enters the HA and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; Counts the number of cycles when the general purpose (GP) HA tracker pool (HT) is completely used.  It will not return valid count when BT is disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_CYCLES_FULL.ALL",
      EventDef::Encoding{.code = 0x2, .umask = 0x2, .msr_values = {0}},
      R"(Tracker Cycles Full; Cycles Completely Used)",
      R"(Counts the number of cycles when the local HA tracker pool is completely used.  This can be used with edge detect to identify the number of situations when the pool became fully utilized.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, the system could be starved for RTIDs but not fill up the HA trackers.  HA trackers are allocated as soon as a request enters the HA and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; Counts the number of cycles when the HA tracker pool (HT) is completely used including reserved HT entries.  It will not return valid count when BT is disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_CYCLES_NE.LOCAL",
      EventDef::Encoding{.code = 0x3, .umask = 0x1, .msr_values = {0}},
      R"(Tracker Cycles Not Empty; Local Requests)",
      R"(Counts the number of cycles when the local HA tracker pool is not empty.  This can be used with edge detect to identify the number of situations when the pool became empty.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, this buffer could be completely empty, but there may still be credits in use by the CBos.  This stat can be used in conjunction with the occupancy accumulation stat in order to calculate average queue occpancy.  HA trackers are allocated as soon as a request enters the HA if an HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; This filter includes only requests coming from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_CYCLES_NE.REMOTE",
      EventDef::Encoding{.code = 0x3, .umask = 0x2, .msr_values = {0}},
      R"(Tracker Cycles Not Empty; Remote Requests)",
      R"(Counts the number of cycles when the local HA tracker pool is not empty.  This can be used with edge detect to identify the number of situations when the pool became empty.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, this buffer could be completely empty, but there may still be credits in use by the CBos.  This stat can be used in conjunction with the occupancy accumulation stat in order to calculate average queue occpancy.  HA trackers are allocated as soon as a request enters the HA if an HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; This filter includes only requests coming from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_CYCLES_NE.ALL",
      EventDef::Encoding{.code = 0x3, .umask = 0x3, .msr_values = {0}},
      R"(Tracker Cycles Not Empty; All Requests)",
      R"(Counts the number of cycles when the local HA tracker pool is not empty.  This can be used with edge detect to identify the number of situations when the pool became empty.  This should not be confused with RTID credit usage -- which must be tracked inside each cbo individually -- but represents the actual tracker buffer structure.  In other words, this buffer could be completely empty, but there may still be credits in use by the CBos.  This stat can be used in conjunction with the occupancy accumulation stat in order to calculate average queue occpancy.  HA trackers are allocated as soon as a request enters the HA if an HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.; Requests coming from both local and remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_OCCUPANCY.READS_LOCAL",
      EventDef::Encoding{.code = 0x4, .umask = 0x4, .msr_values = {0}},
      R"(Tracker Occupancy Accumultor; Local Read Requests)",
      R"(Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_OCCUPANCY.READS_REMOTE",
      EventDef::Encoding{.code = 0x4, .umask = 0x8, .msr_values = {0}},
      R"(Tracker Occupancy Accumultor; Remote Read Requests)",
      R"(Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_OCCUPANCY.WRITES_LOCAL",
      EventDef::Encoding{.code = 0x4, .umask = 0x10, .msr_values = {0}},
      R"(Tracker Occupancy Accumultor; Local Write Requests)",
      R"(Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_OCCUPANCY.WRITES_REMOTE",
      EventDef::Encoding{.code = 0x4, .umask = 0x20, .msr_values = {0}},
      R"(Tracker Occupancy Accumultor; Remote Write Requests)",
      R"(Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_OCCUPANCY.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x4, .umask = 0x40, .msr_values = {0}},
      R"(Tracker Occupancy Accumultor; Local InvItoE Requests)",
      R"(Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_OCCUPANCY.INVITOE_REMOTE",
      EventDef::Encoding{.code = 0x4, .umask = 0x80, .msr_values = {0}},
      R"(Tracker Occupancy Accumultor; Remote InvItoE Requests)",
      R"(Accumulates the occupancy of the local HA tracker pool in every cycle.  This can be used in conjection with the not empty stat to calculate average queue occupancy or the allocations stat in order to calculate average queue latency.  HA trackers are allocated as soon as a request enters the HA if a HT (Home Tracker) entry is available and is released after the snoop response and data return (or post in the case of a write) and the response is returned on the ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_PENDING_OCCUPANCY.LOCAL",
      EventDef::Encoding{.code = 0x5, .umask = 0x1, .msr_values = {0}},
      R"(Data Pending Occupancy Accumultor; Local Requests)",
      R"(Accumulates the number of transactions that have data from the memory controller until they get scheduled to the Egress.  This can be used to calculate the queuing latency for two things.  (1) If the system is waiting for snoops, this will increase.  (2) If the system can't schedule to the Egress because of either (a) Egress Credits or (b) QPI BL IGR credits for remote requests.; This filter includes only requests coming from the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TRACKER_PENDING_OCCUPANCY.REMOTE",
      EventDef::Encoding{.code = 0x5, .umask = 0x2, .msr_values = {0}},
      R"(Data Pending Occupancy Accumultor; Remote Requests)",
      R"(Accumulates the number of transactions that have data from the memory controller until they get scheduled to the Egress.  This can be used to calculate the queuing latency for two things.  (1) If the system is waiting for snoops, this will increase.  (2) If the system can't schedule to the Egress because of either (a) Egress Credits or (b) QPI BL IGR credits for remote requests.; This filter includes only requests coming from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD.HOM",
      EventDef::Encoding{.code = 0xF, .umask = 0x4, .msr_values = {0}},
      R"(Outbound NDR Ring Transactions; Non-data Responses)",
      R"(Counts the number of outbound transactions on the AD ring.  This can be filtered by the NDR and SNP message classes.  See the filter descriptions for more details.; Filter for outbound NDR transactions sent on the AD ring.  NDR stands for non-data response and is generally used for completions that do not include data.  AD NDR is used for transactions to remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_CYCLES_FULL.SCHED0",
      EventDef::Encoding{.code = 0x2A, .umask = 0x1, .msr_values = {0}},
      R"(AD Egress Full; Scheduler 0)",
      R"(AD Egress Full; Filter for cycles full  from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_CYCLES_FULL.SCHED1",
      EventDef::Encoding{.code = 0x2A, .umask = 0x2, .msr_values = {0}},
      R"(AD Egress Full; Scheduler 1)",
      R"(AD Egress Full; Filter for cycles full  from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_CYCLES_FULL.ALL",
      EventDef::Encoding{.code = 0x2A, .umask = 0x3, .msr_values = {0}},
      R"(AD Egress Full; All)",
      R"(AD Egress Full; Cycles full from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_CYCLES_NE.SCHED0",
      EventDef::Encoding{.code = 0x29, .umask = 0x1, .msr_values = {0}},
      R"(AD Egress Not Empty; Scheduler 0)",
      R"(AD Egress Not Empty; Filter for cycles not empty  from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_CYCLES_NE.SCHED1",
      EventDef::Encoding{.code = 0x29, .umask = 0x2, .msr_values = {0}},
      R"(AD Egress Not Empty; Scheduler 1)",
      R"(AD Egress Not Empty; Filter for cycles not empty from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_CYCLES_NE.ALL",
      EventDef::Encoding{.code = 0x29, .umask = 0x3, .msr_values = {0}},
      R"(AD Egress Not Empty; All)",
      R"(AD Egress Not Empty; Cycles full from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_INSERTS.SCHED0",
      EventDef::Encoding{.code = 0x27, .umask = 0x1, .msr_values = {0}},
      R"(AD Egress Allocations; Scheduler 0)",
      R"(AD Egress Allocations; Filter for allocations from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_INSERTS.SCHED1",
      EventDef::Encoding{.code = 0x27, .umask = 0x2, .msr_values = {0}},
      R"(AD Egress Allocations; Scheduler 1)",
      R"(AD Egress Allocations; Filter for allocations from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AD_INSERTS.ALL",
      EventDef::Encoding{.code = 0x27, .umask = 0x3, .msr_values = {0}},
      R"(AD Egress Allocations; All)",
      R"(AD Egress Allocations; Allocations from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_CYCLES_FULL.SCHED0",
      EventDef::Encoding{.code = 0x32, .umask = 0x1, .msr_values = {0}},
      R"(AK Egress Full; Scheduler 0)",
      R"(AK Egress Full; Filter for cycles full  from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_CYCLES_FULL.SCHED1",
      EventDef::Encoding{.code = 0x32, .umask = 0x2, .msr_values = {0}},
      R"(AK Egress Full; Scheduler 1)",
      R"(AK Egress Full; Filter for cycles full  from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_CYCLES_FULL.ALL",
      EventDef::Encoding{.code = 0x32, .umask = 0x3, .msr_values = {0}},
      R"(AK Egress Full; All)",
      R"(AK Egress Full; Cycles full from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_CYCLES_NE.SCHED0",
      EventDef::Encoding{.code = 0x31, .umask = 0x1, .msr_values = {0}},
      R"(AK Egress Not Empty; Scheduler 0)",
      R"(AK Egress Not Empty; Filter for cycles not empty  from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_CYCLES_NE.SCHED1",
      EventDef::Encoding{.code = 0x31, .umask = 0x2, .msr_values = {0}},
      R"(AK Egress Not Empty; Scheduler 1)",
      R"(AK Egress Not Empty; Filter for cycles not empty from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_CYCLES_NE.ALL",
      EventDef::Encoding{.code = 0x31, .umask = 0x3, .msr_values = {0}},
      R"(AK Egress Not Empty; All)",
      R"(AK Egress Not Empty; Cycles full from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_INSERTS.SCHED0",
      EventDef::Encoding{.code = 0x2F, .umask = 0x1, .msr_values = {0}},
      R"(AK Egress Allocations; Scheduler 0)",
      R"(AK Egress Allocations; Filter for allocations from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_INSERTS.SCHED1",
      EventDef::Encoding{.code = 0x2F, .umask = 0x2, .msr_values = {0}},
      R"(AK Egress Allocations; Scheduler 1)",
      R"(AK Egress Allocations; Filter for allocations from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_AK_INSERTS.ALL",
      EventDef::Encoding{.code = 0x2F, .umask = 0x3, .msr_values = {0}},
      R"(AK Egress Allocations; All)",
      R"(AK Egress Allocations; Allocations from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL.DRS_CACHE",
      EventDef::Encoding{.code = 0x10, .umask = 0x1, .msr_values = {0}},
      R"(Outbound DRS Ring Transactions to Cache; Data to Cache)",
      R"(Counts the number of DRS messages sent out on the BL ring.   This can be filtered by the destination.; Filter for data being sent to the cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL.DRS_CORE",
      EventDef::Encoding{.code = 0x10, .umask = 0x2, .msr_values = {0}},
      R"(Outbound DRS Ring Transactions to Cache; Data to Core)",
      R"(Counts the number of DRS messages sent out on the BL ring.   This can be filtered by the destination.; Filter for data being sent directly to the requesting core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL.DRS_QPI",
      EventDef::Encoding{.code = 0x10, .umask = 0x4, .msr_values = {0}},
      R"(Outbound DRS Ring Transactions to Cache; Data to QPI)",
      R"(Counts the number of DRS messages sent out on the BL ring.   This can be filtered by the destination.; Filter for data being sent to a remote socket over QPI.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_CYCLES_FULL.SCHED0",
      EventDef::Encoding{.code = 0x36, .umask = 0x1, .msr_values = {0}},
      R"(BL Egress Full; Scheduler 0)",
      R"(BL Egress Full; Filter for cycles full  from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_CYCLES_FULL.SCHED1",
      EventDef::Encoding{.code = 0x36, .umask = 0x2, .msr_values = {0}},
      R"(BL Egress Full; Scheduler 1)",
      R"(BL Egress Full; Filter for cycles full  from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_CYCLES_FULL.ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0x3, .msr_values = {0}},
      R"(BL Egress Full; All)",
      R"(BL Egress Full; Cycles full from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_CYCLES_NE.SCHED0",
      EventDef::Encoding{.code = 0x35, .umask = 0x1, .msr_values = {0}},
      R"(BL Egress Not Empty; Scheduler 0)",
      R"(BL Egress Not Empty; Filter for cycles not empty  from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_CYCLES_NE.SCHED1",
      EventDef::Encoding{.code = 0x35, .umask = 0x2, .msr_values = {0}},
      R"(BL Egress Not Empty; Scheduler 1)",
      R"(BL Egress Not Empty; Filter for cycles not empty from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_CYCLES_NE.ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0x3, .msr_values = {0}},
      R"(BL Egress Not Empty; All)",
      R"(BL Egress Not Empty; Cycles full from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_INSERTS.SCHED0",
      EventDef::Encoding{.code = 0x33, .umask = 0x1, .msr_values = {0}},
      R"(BL Egress Allocations; Scheduler 0)",
      R"(BL Egress Allocations; Filter for allocations from scheduler bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_INSERTS.SCHED1",
      EventDef::Encoding{.code = 0x33, .umask = 0x2, .msr_values = {0}},
      R"(BL Egress Allocations; Scheduler 1)",
      R"(BL Egress Allocations; Filter for allocations from scheduler bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_BL_INSERTS.ALL",
      EventDef::Encoding{.code = 0x33, .umask = 0x3, .msr_values = {0}},
      R"(BL Egress Allocations; All)",
      R"(BL Egress Allocations; Allocations from both schedulers)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_STARVED.AK",
      EventDef::Encoding{.code = 0x6D, .umask = 0x1, .msr_values = {0}},
      R"(Injection Starvation; For AK Ring)",
      R"(Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_TxR_STARVED.BL",
      EventDef::Encoding{.code = 0x6D, .umask = 0x2, .msr_values = {0}},
      R"(Injection Starvation; For BL Ring)",
      R"(Counts injection starvation.  This starvation is triggered when the Egress cannot send a transaction onto the ring for a long period of time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN0",
      EventDef::Encoding{.code = 0x18, .umask = 0x1, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Regular; Channel 0)",
      R"(Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN1",
      EventDef::Encoding{.code = 0x18, .umask = 0x2, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Regular; Channel 1)",
      R"(Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN2",
      EventDef::Encoding{.code = 0x18, .umask = 0x4, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Regular; Channel 2)",
      R"(Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_REG_CREDITS.CHN3",
      EventDef::Encoding{.code = 0x18, .umask = 0x8, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Regular; Channel 3)",
      R"(Counts the number of cycles when there are no regular credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the regular credits  Common high banwidth workloads should be able to make use of all of the regular buffers, but it will be difficult (and uncommon) to make use of both the regular and special buffers at the same time.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN0",
      EventDef::Encoding{.code = 0x19, .umask = 0x1, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Special; Channel 0)",
      R"(Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 0 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN1",
      EventDef::Encoding{.code = 0x19, .umask = 0x2, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Special; Channel 1)",
      R"(Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 1 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN2",
      EventDef::Encoding{.code = 0x19, .umask = 0x4, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Special; Channel 2)",
      R"(Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 2 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ha,
      "UNC_H_WPQ_CYCLES_NO_SPEC_CREDITS.CHN3",
      EventDef::Encoding{.code = 0x19, .umask = 0x8, .msr_values = {0}},
      R"(HA iMC CHN0 WPQ Credits Empty - Special; Channel 3)",
      R"(Counts the number of cycles when there are no special credits available for posting writes from the HA into the iMC.  In order to send writes into the memory controller, the HA must first acquire a credit for the iMC's WPQ (write pending queue).  This queue is broken into regular credits/buffers that are used by general writes, and special requests such as ISOCH writes.  This count only tracks the special credits.  This statistic is generally not interesting for general IA workloads, but may be of interest for understanding the characteristics of systems using ISOCH.  One can filter based on the memory controller channel.  One or more channels can be tracked at a given time.; Filter for memory controller channel 3 only.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.RD",
      EventDef::Encoding{.code = 0x1, .umask = 0x1, .msr_values = {0}},
      R"(DRAM Activate Count; Activate due to Read)",
      R"(Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.WR",
      EventDef::Encoding{.code = 0x1, .umask = 0x2, .msr_values = {0}},
      R"(DRAM Activate Count; Activate due to Write)",
      R"(Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.BYP",
      EventDef::Encoding{.code = 0x1, .umask = 0x8, .msr_values = {0}},
      R"(DRAM Activate Count; Activate due to Write)",
      R"(Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_BYP_CMDS.ACT",
      EventDef::Encoding{.code = 0xA1, .umask = 0x1, .msr_values = {0}},
      R"(ACT command issued by 2 cycle bypass)",
      R"(ACT command issued by 2 cycle bypass)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_BYP_CMDS.CAS",
      EventDef::Encoding{.code = 0xA1, .umask = 0x2, .msr_values = {0}},
      R"(CAS command issued by 2 cycle bypass)",
      R"(CAS command issued by 2 cycle bypass)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_BYP_CMDS.PRE",
      EventDef::Encoding{.code = 0xA1, .umask = 0x4, .msr_values = {0}},
      R"(PRE command issued by 2 cycle bypass)",
      R"(PRE command issued by 2 cycle bypass)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_REG",
      EventDef::Encoding{.code = 0x4, .umask = 0x1, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; All DRAM RD_CAS (w/ and w/out auto-pre))",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number or DRAM Read CAS commands issued on this channel.  This includes both regular RD CAS commands as well as those with implicit Precharge.  AutoPre is only used in systems that are using closed page policy.  We do not filter based on major mode, as RD_CAS is not issued during WMM (with the exception of underfills).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_UNDERFILL",
      EventDef::Encoding{.code = 0x4, .umask = 0x2, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; Underfill Read Issued)",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the number of underfill reads that are issued by the memory controller.  This will generally be about the same as the number of partial writes, but may be slightly less because of partials hitting in the WPQ.  While it is possible for underfills to be issed in both WMM and RMM, this event counts both.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD",
      EventDef::Encoding{.code = 0x4, .umask = 0x3, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; All DRAM Reads (RD_CAS + Underfills))",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM Read CAS commands issued on this channel (including underfills).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR_WMM",
      EventDef::Encoding{.code = 0x4, .umask = 0x4, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; DRAM WR_CAS (w/ and w/out auto-pre) in Write Major Mode)",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number or DRAM Write CAS commands issued on this channel while in Write-Major-Mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR_RMM",
      EventDef::Encoding{.code = 0x4, .umask = 0x8, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; DRAM WR_CAS (w/ and w/out auto-pre) in Read Major Mode)",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number of Opportunistic DRAM Write CAS commands issued on this channel while in Read-Major-Mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x4, .umask = 0xC, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; All DRAM WR_CAS (both Modes))",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM Write CAS commands issued on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.ALL",
      EventDef::Encoding{.code = 0x4, .umask = 0xF, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; All DRAM WR_CAS (w/ and w/out auto-pre))",
      R"(DRAM RD_CAS and WR_CAS Commands; Counts the total number of DRAM CAS commands issued on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_WMM",
      EventDef::Encoding{.code = 0x4, .umask = 0x10, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; Read CAS issued in WMM)",
      R"(DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_RMM",
      EventDef::Encoding{.code = 0x4, .umask = 0x20, .msr_values = {0}},
      R"(DRAM RD_CAS and WR_CAS Commands.; Read CAS issued in RMM)",
      R"(DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_DCLOCKTICKS",
      EventDef::Encoding{.code = 0x0, .umask = 0x0, .msr_values = {0}},
      R"(DRAM Clockticks)",
      R"(DRAM Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_DRAM_PRE_ALL",
      EventDef::Encoding{.code = 0x6, .umask = 0x0, .msr_values = {0}},
      R"(DRAM Precharge All Commands)",
      R"(Counts the number of times that the precharge all command was sent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_DRAM_REFRESH.PANIC",
      EventDef::Encoding{.code = 0x5, .umask = 0x2, .msr_values = {0}},
      R"(Number of DRAM Refreshes Issued)",
      R"(Counts the number of refreshes issued.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_DRAM_REFRESH.HIGH",
      EventDef::Encoding{.code = 0x5, .umask = 0x4, .msr_values = {0}},
      R"(Number of DRAM Refreshes Issued)",
      R"(Counts the number of refreshes issued.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ECC_CORRECTABLE_ERRORS",
      EventDef::Encoding{.code = 0x9, .umask = 0x0, .msr_values = {0}},
      R"(ECC Correctable Errors)",
      R"(Counts the number of ECC errors detected and corrected by the iMC on this channel.  This counter is only useful with ECC DRAM devices.  This count will increment one time for each correction regardless of the number of bits corrected.  The iMC can correct up to 4 bit errors in independent channel mode and 8 bit erros in lockstep mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_MAJOR_MODES.READ",
      EventDef::Encoding{.code = 0x7, .umask = 0x1, .msr_values = {0}},
      R"(Cycles in a Major Mode; Read Major Mode)",
      R"(Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; Read Major Mode is the default mode for the iMC, as reads are generally more critical to forward progress than writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_MAJOR_MODES.WRITE",
      EventDef::Encoding{.code = 0x7, .umask = 0x2, .msr_values = {0}},
      R"(Cycles in a Major Mode; Write Major Mode)",
      R"(Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; This mode is triggered when the WPQ hits high occupancy and causes writes to be higher priority than reads.  This can cause blips in the available read bandwidth in the system and temporarily increase read latencies in order to achieve better bus utilizations and higher bandwidth.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_MAJOR_MODES.PARTIAL",
      EventDef::Encoding{.code = 0x7, .umask = 0x4, .msr_values = {0}},
      R"(Cycles in a Major Mode; Partial Major Mode)",
      R"(Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; This major mode is used to drain starved underfill reads.  Regular reads and writes are blocked and only underfill reads will be processed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_MAJOR_MODES.ISOCH",
      EventDef::Encoding{.code = 0x7, .umask = 0x8, .msr_values = {0}},
      R"(Cycles in a Major Mode; Isoch Major Mode)",
      R"(Counts the total number of cycles spent in a major mode (selected by a filter) on the given channel.   Major modea are channel-wide, and not a per-rank (or dimm or bank) mode.; We group these two modes together so that we can use four counters to track each of the major modes at one time.  These major modes are used whenever there is an ISOCH txn in the memory controller.  In these mode, only ISOCH transactions are processed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CHANNEL_DLLOFF",
      EventDef::Encoding{.code = 0x84, .umask = 0x0, .msr_values = {0}},
      R"(Channel DLLOFF Cycles)",
      R"(Number of cycles when all the ranks in the channel are in CKE Slow (DLLOFF) mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CHANNEL_PPD",
      EventDef::Encoding{.code = 0x85, .umask = 0x0, .msr_values = {0}},
      R"(Channel PPD Cycles)",
      R"(Number of cycles when all the ranks in the channel are in PPD mode.  If IBT=off is enabled, then this can be used to count those cycles.  If it is not enabled, then this can count the number of cycles when that could have been taken advantage of.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK0",
      EventDef::Encoding{.code = 0x83, .umask = 0x1, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK1",
      EventDef::Encoding{.code = 0x83, .umask = 0x2, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK2",
      EventDef::Encoding{.code = 0x83, .umask = 0x4, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK3",
      EventDef::Encoding{.code = 0x83, .umask = 0x8, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK4",
      EventDef::Encoding{.code = 0x83, .umask = 0x10, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK5",
      EventDef::Encoding{.code = 0x83, .umask = 0x20, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK6",
      EventDef::Encoding{.code = 0x83, .umask = 0x40, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.RANK7",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0}},
      R"(CKE_ON_CYCLES by Rank; DIMM ID)",
      R"(Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CRITICAL_THROTTLE_CYCLES",
      EventDef::Encoding{.code = 0x86, .umask = 0x0, .msr_values = {0}},
      R"(Critical Throttle Cycles)",
      R"(Counts the number of cycles when the iMC is in critical thermal throttling.  When this happens, all traffic is blocked.  This should be rare unless something bad is going on in the platform.  There is no filtering by rank for this event.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_PCU_THROTTLING",
      EventDef::Encoding{.code = 0x42, .umask = 0x0, .msr_values = {0}},
      R"(UNC_M_POWER_PCU_THROTTLING (Description is auto-generated))",
      R"(UNC_M_POWER_PCU_THROTTLING (Description is auto-generated))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_SELF_REFRESH",
      EventDef::Encoding{.code = 0x43, .umask = 0x0, .msr_values = {0}},
      R"(Clock-Enabled Self-Refresh)",
      R"(Counts the number of cycles when the iMC is in self-refresh and the iMC still has a clock.  This happens in some package C-states.  For example, the PCU may ask the iMC to enter self-refresh even though some of the cores are still processing.  One use of this is for Monroe technology.  Self-refresh is required during package C3 and C6, but there is no clock in the iMC at this time, so it is not possible to count these cases.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK0",
      EventDef::Encoding{.code = 0x41, .umask = 0x1, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.; Thermal throttling is performed per DIMM.  We support 3 DIMMs per channel.  This ID allows us to filter by ID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK1",
      EventDef::Encoding{.code = 0x41, .umask = 0x2, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK2",
      EventDef::Encoding{.code = 0x41, .umask = 0x4, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK3",
      EventDef::Encoding{.code = 0x41, .umask = 0x8, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK4",
      EventDef::Encoding{.code = 0x41, .umask = 0x10, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK5",
      EventDef::Encoding{.code = 0x41, .umask = 0x20, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK6",
      EventDef::Encoding{.code = 0x41, .umask = 0x40, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_THROTTLE_CYCLES.RANK7",
      EventDef::Encoding{.code = 0x41, .umask = 0x80, .msr_values = {0}},
      R"(Throttle Cycles for Rank 0; DIMM ID)",
      R"(Counts the number of cycles while the iMC is being throttled by either thermal constraints or by the PCU throttling.  It is not possible to distinguish between the two.  This can be filtered by rank.  If multiple ranks are selected and are being throttled at the same time, the counter will only increment by 1.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PREEMPTION.RD_PREEMPT_RD",
      EventDef::Encoding{.code = 0x8, .umask = 0x1, .msr_values = {0}},
      R"(Read Preemption Count; Read over Read Preemption)",
      R"(Counts the number of times a read in the iMC preempts another read or write.  Generally reads to an open page are issued ahead of requests to closed pages.  This improves the page hit rate of the system.  However, high priority requests can cause pages of active requests to be closed in order to get them out.  This will reduce the latency of the high-priority request at the expense of lower bandwidth and increased overall average latency.; Filter for when a read preempts another read.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PREEMPTION.RD_PREEMPT_WR",
      EventDef::Encoding{.code = 0x8, .umask = 0x2, .msr_values = {0}},
      R"(Read Preemption Count; Read over Write Preemption)",
      R"(Counts the number of times a read in the iMC preempts another read or write.  Generally reads to an open page are issued ahead of requests to closed pages.  This improves the page hit rate of the system.  However, high priority requests can cause pages of active requests to be closed in order to get them out.  This will reduce the latency of the high-priority request at the expense of lower bandwidth and increased overall average latency.; Filter for when a read preempts a write.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PAGE_MISS",
      EventDef::Encoding{.code = 0x2, .umask = 0x1, .msr_values = {0}},
      R"(DRAM Precharge commands.; Precharges due to page miss)",
      R"(Counts the number of DRAM Precharge commands sent on this channel.; Counts the number of DRAM Precharge commands sent on this channel as a result of page misses.  This does not include explicit precharge commands sent with CAS commands in Auto-Precharge mode.  This does not include PRE commands sent as a result of the page close counter expiration.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PAGE_CLOSE",
      EventDef::Encoding{.code = 0x2, .umask = 0x2, .msr_values = {0}},
      R"(DRAM Precharge commands.; Precharge due to timer expiration)",
      R"(Counts the number of DRAM Precharge commands sent on this channel.; Counts the number of DRAM Precharge commands sent on this channel as a result of the page close counter expiring.  This does not include implicit precharge commands sent in auto-precharge mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.RD",
      EventDef::Encoding{.code = 0x2, .umask = 0x4, .msr_values = {0}},
      R"(DRAM Precharge commands.; Precharge due to read)",
      R"(Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.WR",
      EventDef::Encoding{.code = 0x2, .umask = 0x8, .msr_values = {0}},
      R"(DRAM Precharge commands.; Precharge due to write)",
      R"(Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.BYP",
      EventDef::Encoding{.code = 0x2, .umask = 0x10, .msr_values = {0}},
      R"(DRAM Precharge commands.; Precharge due to bypass)",
      R"(Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_PRIO.LOW",
      EventDef::Encoding{.code = 0xA0, .umask = 0x1, .msr_values = {0}},
      R"(Read CAS issued with LOW priority)",
      R"(Read CAS issued with LOW priority)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_PRIO.MED",
      EventDef::Encoding{.code = 0xA0, .umask = 0x2, .msr_values = {0}},
      R"(Read CAS issued with MEDIUM priority)",
      R"(Read CAS issued with MEDIUM priority)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_PRIO.HIGH",
      EventDef::Encoding{.code = 0xA0, .umask = 0x4, .msr_values = {0}},
      R"(Read CAS issued with HIGH priority)",
      R"(Read CAS issued with HIGH priority)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_PRIO.PANIC",
      EventDef::Encoding{.code = 0xA0, .umask = 0x8, .msr_values = {0}},
      R"(Read CAS issued with PANIC NON ISOCH priority (starved))",
      R"(Read CAS issued with PANIC NON ISOCH priority (starved))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK1",
      EventDef::Encoding{.code = 0xB0, .umask = 0x1, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 1)",
      R"(RD_CAS Access to Rank 0; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK2",
      EventDef::Encoding{.code = 0xB0, .umask = 0x2, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 2)",
      R"(RD_CAS Access to Rank 0; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK4",
      EventDef::Encoding{.code = 0xB0, .umask = 0x4, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 4)",
      R"(RD_CAS Access to Rank 0; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK8",
      EventDef::Encoding{.code = 0xB0, .umask = 0x8, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 8)",
      R"(RD_CAS Access to Rank 0; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.ALLBANKS",
      EventDef::Encoding{.code = 0xB0, .umask = 0x10, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; All Banks)",
      R"(RD_CAS Access to Rank 0; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK0",
      EventDef::Encoding{.code = 0xB0, .umask = 0x0, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 0)",
      R"(RD_CAS Access to Rank 0; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK3",
      EventDef::Encoding{.code = 0xB0, .umask = 0x3, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 3)",
      R"(RD_CAS Access to Rank 0; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK5",
      EventDef::Encoding{.code = 0xB0, .umask = 0x5, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 5)",
      R"(RD_CAS Access to Rank 0; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK6",
      EventDef::Encoding{.code = 0xB0, .umask = 0x6, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 6)",
      R"(RD_CAS Access to Rank 0; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK7",
      EventDef::Encoding{.code = 0xB0, .umask = 0x7, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 7)",
      R"(RD_CAS Access to Rank 0; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK9",
      EventDef::Encoding{.code = 0xB0, .umask = 0x9, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 9)",
      R"(RD_CAS Access to Rank 0; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK10",
      EventDef::Encoding{.code = 0xB0, .umask = 0xA, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 10)",
      R"(RD_CAS Access to Rank 0; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK11",
      EventDef::Encoding{.code = 0xB0, .umask = 0xB, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 11)",
      R"(RD_CAS Access to Rank 0; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK12",
      EventDef::Encoding{.code = 0xB0, .umask = 0xC, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 12)",
      R"(RD_CAS Access to Rank 0; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK13",
      EventDef::Encoding{.code = 0xB0, .umask = 0xD, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 13)",
      R"(RD_CAS Access to Rank 0; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK14",
      EventDef::Encoding{.code = 0xB0, .umask = 0xE, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 14)",
      R"(RD_CAS Access to Rank 0; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANK15",
      EventDef::Encoding{.code = 0xB0, .umask = 0xF, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank 15)",
      R"(RD_CAS Access to Rank 0; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANKG0",
      EventDef::Encoding{.code = 0xB0, .umask = 0x11, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank Group 0 (Banks 0-3))",
      R"(RD_CAS Access to Rank 0; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANKG1",
      EventDef::Encoding{.code = 0xB0, .umask = 0x12, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank Group 1 (Banks 4-7))",
      R"(RD_CAS Access to Rank 0; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANKG2",
      EventDef::Encoding{.code = 0xB0, .umask = 0x13, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank Group 2 (Banks 8-11))",
      R"(RD_CAS Access to Rank 0; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK0.BANKG3",
      EventDef::Encoding{.code = 0xB0, .umask = 0x14, .msr_values = {0}},
      R"(RD_CAS Access to Rank 0; Bank Group 3 (Banks 12-15))",
      R"(RD_CAS Access to Rank 0; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK1",
      EventDef::Encoding{.code = 0xB1, .umask = 0x1, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 1)",
      R"(RD_CAS Access to Rank 1; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK2",
      EventDef::Encoding{.code = 0xB1, .umask = 0x2, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 2)",
      R"(RD_CAS Access to Rank 1; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK4",
      EventDef::Encoding{.code = 0xB1, .umask = 0x4, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 4)",
      R"(RD_CAS Access to Rank 1; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK8",
      EventDef::Encoding{.code = 0xB1, .umask = 0x8, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 8)",
      R"(RD_CAS Access to Rank 1; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.ALLBANKS",
      EventDef::Encoding{.code = 0xB1, .umask = 0x10, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; All Banks)",
      R"(RD_CAS Access to Rank 1; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK0",
      EventDef::Encoding{.code = 0xB1, .umask = 0x0, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 0)",
      R"(RD_CAS Access to Rank 1; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK3",
      EventDef::Encoding{.code = 0xB1, .umask = 0x3, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 3)",
      R"(RD_CAS Access to Rank 1; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK5",
      EventDef::Encoding{.code = 0xB1, .umask = 0x5, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 5)",
      R"(RD_CAS Access to Rank 1; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK6",
      EventDef::Encoding{.code = 0xB1, .umask = 0x6, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 6)",
      R"(RD_CAS Access to Rank 1; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK7",
      EventDef::Encoding{.code = 0xB1, .umask = 0x7, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 7)",
      R"(RD_CAS Access to Rank 1; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK9",
      EventDef::Encoding{.code = 0xB1, .umask = 0x9, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 9)",
      R"(RD_CAS Access to Rank 1; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK10",
      EventDef::Encoding{.code = 0xB1, .umask = 0xA, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 10)",
      R"(RD_CAS Access to Rank 1; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK11",
      EventDef::Encoding{.code = 0xB1, .umask = 0xB, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 11)",
      R"(RD_CAS Access to Rank 1; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK12",
      EventDef::Encoding{.code = 0xB1, .umask = 0xC, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 12)",
      R"(RD_CAS Access to Rank 1; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK13",
      EventDef::Encoding{.code = 0xB1, .umask = 0xD, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 13)",
      R"(RD_CAS Access to Rank 1; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK14",
      EventDef::Encoding{.code = 0xB1, .umask = 0xE, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 14)",
      R"(RD_CAS Access to Rank 1; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANK15",
      EventDef::Encoding{.code = 0xB1, .umask = 0xF, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank 15)",
      R"(RD_CAS Access to Rank 1; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANKG0",
      EventDef::Encoding{.code = 0xB1, .umask = 0x11, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank Group 0 (Banks 0-3))",
      R"(RD_CAS Access to Rank 1; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANKG1",
      EventDef::Encoding{.code = 0xB1, .umask = 0x12, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank Group 1 (Banks 4-7))",
      R"(RD_CAS Access to Rank 1; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANKG2",
      EventDef::Encoding{.code = 0xB1, .umask = 0x13, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank Group 2 (Banks 8-11))",
      R"(RD_CAS Access to Rank 1; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK1.BANKG3",
      EventDef::Encoding{.code = 0xB1, .umask = 0x14, .msr_values = {0}},
      R"(RD_CAS Access to Rank 1; Bank Group 3 (Banks 12-15))",
      R"(RD_CAS Access to Rank 1; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK2.BANK0",
      EventDef::Encoding{.code = 0xB2, .umask = 0x0, .msr_values = {0}},
      R"(RD_CAS Access to Rank 2; Bank 0)",
      R"(RD_CAS Access to Rank 2; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK1",
      EventDef::Encoding{.code = 0xB4, .umask = 0x1, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 1)",
      R"(RD_CAS Access to Rank 4; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK2",
      EventDef::Encoding{.code = 0xB4, .umask = 0x2, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 2)",
      R"(RD_CAS Access to Rank 4; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK4",
      EventDef::Encoding{.code = 0xB4, .umask = 0x4, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 4)",
      R"(RD_CAS Access to Rank 4; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK8",
      EventDef::Encoding{.code = 0xB4, .umask = 0x8, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 8)",
      R"(RD_CAS Access to Rank 4; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.ALLBANKS",
      EventDef::Encoding{.code = 0xB4, .umask = 0x10, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; All Banks)",
      R"(RD_CAS Access to Rank 4; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK0",
      EventDef::Encoding{.code = 0xB4, .umask = 0x0, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 0)",
      R"(RD_CAS Access to Rank 4; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK3",
      EventDef::Encoding{.code = 0xB4, .umask = 0x3, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 3)",
      R"(RD_CAS Access to Rank 4; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK5",
      EventDef::Encoding{.code = 0xB4, .umask = 0x5, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 5)",
      R"(RD_CAS Access to Rank 4; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK6",
      EventDef::Encoding{.code = 0xB4, .umask = 0x6, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 6)",
      R"(RD_CAS Access to Rank 4; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK7",
      EventDef::Encoding{.code = 0xB4, .umask = 0x7, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 7)",
      R"(RD_CAS Access to Rank 4; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK9",
      EventDef::Encoding{.code = 0xB4, .umask = 0x9, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 9)",
      R"(RD_CAS Access to Rank 4; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK10",
      EventDef::Encoding{.code = 0xB4, .umask = 0xA, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 10)",
      R"(RD_CAS Access to Rank 4; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK11",
      EventDef::Encoding{.code = 0xB4, .umask = 0xB, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 11)",
      R"(RD_CAS Access to Rank 4; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK12",
      EventDef::Encoding{.code = 0xB4, .umask = 0xC, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 12)",
      R"(RD_CAS Access to Rank 4; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK13",
      EventDef::Encoding{.code = 0xB4, .umask = 0xD, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 13)",
      R"(RD_CAS Access to Rank 4; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK14",
      EventDef::Encoding{.code = 0xB4, .umask = 0xE, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 14)",
      R"(RD_CAS Access to Rank 4; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANK15",
      EventDef::Encoding{.code = 0xB4, .umask = 0xF, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank 15)",
      R"(RD_CAS Access to Rank 4; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANKG0",
      EventDef::Encoding{.code = 0xB4, .umask = 0x11, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank Group 0 (Banks 0-3))",
      R"(RD_CAS Access to Rank 4; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANKG1",
      EventDef::Encoding{.code = 0xB4, .umask = 0x12, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank Group 1 (Banks 4-7))",
      R"(RD_CAS Access to Rank 4; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANKG2",
      EventDef::Encoding{.code = 0xB4, .umask = 0x13, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank Group 2 (Banks 8-11))",
      R"(RD_CAS Access to Rank 4; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK4.BANKG3",
      EventDef::Encoding{.code = 0xB4, .umask = 0x14, .msr_values = {0}},
      R"(RD_CAS Access to Rank 4; Bank Group 3 (Banks 12-15))",
      R"(RD_CAS Access to Rank 4; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK1",
      EventDef::Encoding{.code = 0xB5, .umask = 0x1, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 1)",
      R"(RD_CAS Access to Rank 5; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK2",
      EventDef::Encoding{.code = 0xB5, .umask = 0x2, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 2)",
      R"(RD_CAS Access to Rank 5; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK4",
      EventDef::Encoding{.code = 0xB5, .umask = 0x4, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 4)",
      R"(RD_CAS Access to Rank 5; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK8",
      EventDef::Encoding{.code = 0xB5, .umask = 0x8, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 8)",
      R"(RD_CAS Access to Rank 5; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.ALLBANKS",
      EventDef::Encoding{.code = 0xB5, .umask = 0x10, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; All Banks)",
      R"(RD_CAS Access to Rank 5; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK0",
      EventDef::Encoding{.code = 0xB5, .umask = 0x0, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 0)",
      R"(RD_CAS Access to Rank 5; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK3",
      EventDef::Encoding{.code = 0xB5, .umask = 0x3, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 3)",
      R"(RD_CAS Access to Rank 5; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK5",
      EventDef::Encoding{.code = 0xB5, .umask = 0x5, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 5)",
      R"(RD_CAS Access to Rank 5; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK6",
      EventDef::Encoding{.code = 0xB5, .umask = 0x6, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 6)",
      R"(RD_CAS Access to Rank 5; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK7",
      EventDef::Encoding{.code = 0xB5, .umask = 0x7, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 7)",
      R"(RD_CAS Access to Rank 5; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK9",
      EventDef::Encoding{.code = 0xB5, .umask = 0x9, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 9)",
      R"(RD_CAS Access to Rank 5; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK10",
      EventDef::Encoding{.code = 0xB5, .umask = 0xA, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 10)",
      R"(RD_CAS Access to Rank 5; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK11",
      EventDef::Encoding{.code = 0xB5, .umask = 0xB, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 11)",
      R"(RD_CAS Access to Rank 5; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK12",
      EventDef::Encoding{.code = 0xB5, .umask = 0xC, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 12)",
      R"(RD_CAS Access to Rank 5; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK13",
      EventDef::Encoding{.code = 0xB5, .umask = 0xD, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 13)",
      R"(RD_CAS Access to Rank 5; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK14",
      EventDef::Encoding{.code = 0xB5, .umask = 0xE, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 14)",
      R"(RD_CAS Access to Rank 5; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANK15",
      EventDef::Encoding{.code = 0xB5, .umask = 0xF, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank 15)",
      R"(RD_CAS Access to Rank 5; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANKG0",
      EventDef::Encoding{.code = 0xB5, .umask = 0x11, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank Group 0 (Banks 0-3))",
      R"(RD_CAS Access to Rank 5; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANKG1",
      EventDef::Encoding{.code = 0xB5, .umask = 0x12, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank Group 1 (Banks 4-7))",
      R"(RD_CAS Access to Rank 5; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANKG2",
      EventDef::Encoding{.code = 0xB5, .umask = 0x13, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank Group 2 (Banks 8-11))",
      R"(RD_CAS Access to Rank 5; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK5.BANKG3",
      EventDef::Encoding{.code = 0xB5, .umask = 0x14, .msr_values = {0}},
      R"(RD_CAS Access to Rank 5; Bank Group 3 (Banks 12-15))",
      R"(RD_CAS Access to Rank 5; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK1",
      EventDef::Encoding{.code = 0xB6, .umask = 0x1, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 1)",
      R"(RD_CAS Access to Rank 6; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK2",
      EventDef::Encoding{.code = 0xB6, .umask = 0x2, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 2)",
      R"(RD_CAS Access to Rank 6; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK4",
      EventDef::Encoding{.code = 0xB6, .umask = 0x4, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 4)",
      R"(RD_CAS Access to Rank 6; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK8",
      EventDef::Encoding{.code = 0xB6, .umask = 0x8, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 8)",
      R"(RD_CAS Access to Rank 6; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.ALLBANKS",
      EventDef::Encoding{.code = 0xB6, .umask = 0x10, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; All Banks)",
      R"(RD_CAS Access to Rank 6; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK0",
      EventDef::Encoding{.code = 0xB6, .umask = 0x0, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 0)",
      R"(RD_CAS Access to Rank 6; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK3",
      EventDef::Encoding{.code = 0xB6, .umask = 0x3, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 3)",
      R"(RD_CAS Access to Rank 6; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK5",
      EventDef::Encoding{.code = 0xB6, .umask = 0x5, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 5)",
      R"(RD_CAS Access to Rank 6; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK6",
      EventDef::Encoding{.code = 0xB6, .umask = 0x6, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 6)",
      R"(RD_CAS Access to Rank 6; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK7",
      EventDef::Encoding{.code = 0xB6, .umask = 0x7, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 7)",
      R"(RD_CAS Access to Rank 6; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK9",
      EventDef::Encoding{.code = 0xB6, .umask = 0x9, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 9)",
      R"(RD_CAS Access to Rank 6; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK10",
      EventDef::Encoding{.code = 0xB6, .umask = 0xA, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 10)",
      R"(RD_CAS Access to Rank 6; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK11",
      EventDef::Encoding{.code = 0xB6, .umask = 0xB, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 11)",
      R"(RD_CAS Access to Rank 6; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK12",
      EventDef::Encoding{.code = 0xB6, .umask = 0xC, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 12)",
      R"(RD_CAS Access to Rank 6; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK13",
      EventDef::Encoding{.code = 0xB6, .umask = 0xD, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 13)",
      R"(RD_CAS Access to Rank 6; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK14",
      EventDef::Encoding{.code = 0xB6, .umask = 0xE, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 14)",
      R"(RD_CAS Access to Rank 6; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANK15",
      EventDef::Encoding{.code = 0xB6, .umask = 0xF, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank 15)",
      R"(RD_CAS Access to Rank 6; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANKG0",
      EventDef::Encoding{.code = 0xB6, .umask = 0x11, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank Group 0 (Banks 0-3))",
      R"(RD_CAS Access to Rank 6; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANKG1",
      EventDef::Encoding{.code = 0xB6, .umask = 0x12, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank Group 1 (Banks 4-7))",
      R"(RD_CAS Access to Rank 6; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANKG2",
      EventDef::Encoding{.code = 0xB6, .umask = 0x13, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank Group 2 (Banks 8-11))",
      R"(RD_CAS Access to Rank 6; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK6.BANKG3",
      EventDef::Encoding{.code = 0xB6, .umask = 0x14, .msr_values = {0}},
      R"(RD_CAS Access to Rank 6; Bank Group 3 (Banks 12-15))",
      R"(RD_CAS Access to Rank 6; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK1",
      EventDef::Encoding{.code = 0xB7, .umask = 0x1, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 1)",
      R"(RD_CAS Access to Rank 7; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK2",
      EventDef::Encoding{.code = 0xB7, .umask = 0x2, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 2)",
      R"(RD_CAS Access to Rank 7; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK4",
      EventDef::Encoding{.code = 0xB7, .umask = 0x4, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 4)",
      R"(RD_CAS Access to Rank 7; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK8",
      EventDef::Encoding{.code = 0xB7, .umask = 0x8, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 8)",
      R"(RD_CAS Access to Rank 7; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.ALLBANKS",
      EventDef::Encoding{.code = 0xB7, .umask = 0x10, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; All Banks)",
      R"(RD_CAS Access to Rank 7; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK0",
      EventDef::Encoding{.code = 0xB7, .umask = 0x0, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 0)",
      R"(RD_CAS Access to Rank 7; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK3",
      EventDef::Encoding{.code = 0xB7, .umask = 0x3, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 3)",
      R"(RD_CAS Access to Rank 7; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK5",
      EventDef::Encoding{.code = 0xB7, .umask = 0x5, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 5)",
      R"(RD_CAS Access to Rank 7; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK6",
      EventDef::Encoding{.code = 0xB7, .umask = 0x6, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 6)",
      R"(RD_CAS Access to Rank 7; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK7",
      EventDef::Encoding{.code = 0xB7, .umask = 0x7, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 7)",
      R"(RD_CAS Access to Rank 7; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK9",
      EventDef::Encoding{.code = 0xB7, .umask = 0x9, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 9)",
      R"(RD_CAS Access to Rank 7; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK10",
      EventDef::Encoding{.code = 0xB7, .umask = 0xA, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 10)",
      R"(RD_CAS Access to Rank 7; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK11",
      EventDef::Encoding{.code = 0xB7, .umask = 0xB, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 11)",
      R"(RD_CAS Access to Rank 7; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK12",
      EventDef::Encoding{.code = 0xB7, .umask = 0xC, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 12)",
      R"(RD_CAS Access to Rank 7; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK13",
      EventDef::Encoding{.code = 0xB7, .umask = 0xD, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 13)",
      R"(RD_CAS Access to Rank 7; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK14",
      EventDef::Encoding{.code = 0xB7, .umask = 0xE, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 14)",
      R"(RD_CAS Access to Rank 7; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANK15",
      EventDef::Encoding{.code = 0xB7, .umask = 0xF, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank 15)",
      R"(RD_CAS Access to Rank 7; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANKG0",
      EventDef::Encoding{.code = 0xB7, .umask = 0x11, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank Group 0 (Banks 0-3))",
      R"(RD_CAS Access to Rank 7; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANKG1",
      EventDef::Encoding{.code = 0xB7, .umask = 0x12, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank Group 1 (Banks 4-7))",
      R"(RD_CAS Access to Rank 7; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANKG2",
      EventDef::Encoding{.code = 0xB7, .umask = 0x13, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank Group 2 (Banks 8-11))",
      R"(RD_CAS Access to Rank 7; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RD_CAS_RANK7.BANKG3",
      EventDef::Encoding{.code = 0xB7, .umask = 0x14, .msr_values = {0}},
      R"(RD_CAS Access to Rank 7; Bank Group 3 (Banks 12-15))",
      R"(RD_CAS Access to Rank 7; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_CYCLES_NE",
      EventDef::Encoding{.code = 0x11, .umask = 0x0, .msr_values = {0}},
      R"(Read Pending Queue Not Empty)",
      R"(Counts the number of cycles that the Read Pending Queue is not empty.  This can then be used to calculate the average occupancy (in conjunction with the Read Pending Queue Occupancy count).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This filter is to be used in conjunction with the occupancy filter so that one can correctly track the average occupancies for schedulable entries and scheduled requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS",
      EventDef::Encoding{.code = 0x10, .umask = 0x0, .msr_values = {0}},
      R"(Read Pending Queue Allocations)",
      R"(Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_VMSE_MXB_WR_OCCUPANCY",
      EventDef::Encoding{.code = 0x91, .umask = 0x0, .msr_values = {0}},
      R"(VMSE MXB write buffer occupancy)",
      R"(VMSE MXB write buffer occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_VMSE_WR_PUSH.WMM",
      EventDef::Encoding{.code = 0x90, .umask = 0x1, .msr_values = {0}},
      R"(VMSE WR PUSH issued; VMSE write PUSH issued in WMM)",
      R"(VMSE WR PUSH issued; VMSE write PUSH issued in WMM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_VMSE_WR_PUSH.RMM",
      EventDef::Encoding{.code = 0x90, .umask = 0x2, .msr_values = {0}},
      R"(VMSE WR PUSH issued; VMSE write PUSH issued in RMM)",
      R"(VMSE WR PUSH issued; VMSE write PUSH issued in RMM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WMM_TO_RMM.LOW_THRESH",
      EventDef::Encoding{.code = 0xC0, .umask = 0x1, .msr_values = {0}},
      R"(Transition from WMM to RMM because of low threshold; Transition from WMM to RMM because of starve counter)",
      R"(Transition from WMM to RMM because of low threshold; Transition from WMM to RMM because of starve counter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WMM_TO_RMM.STARVE",
      EventDef::Encoding{.code = 0xC0, .umask = 0x2, .msr_values = {0}},
      R"(Transition from WMM to RMM because of low threshold)",
      R"(Transition from WMM to RMM because of low threshold)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WMM_TO_RMM.VMSE_RETRY",
      EventDef::Encoding{.code = 0xC0, .umask = 0x4, .msr_values = {0}},
      R"(Transition from WMM to RMM because of low threshold)",
      R"(Transition from WMM to RMM because of low threshold)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_CYCLES_FULL",
      EventDef::Encoding{.code = 0x22, .umask = 0x0, .msr_values = {0}},
      R"(Write Pending Queue Full Cycles)",
      R"(Counts the number of cycles when the Write Pending Queue is full.  When the WPQ is full, the HA will not be able to issue any additional read requests into the iMC.  This count should be similar count in the HA which tracks the number of cycles that the HA has no WPQ credits, just somewhat smaller to account for the credit return overhead.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_CYCLES_NE",
      EventDef::Encoding{.code = 0x21, .umask = 0x0, .msr_values = {0}},
      R"(Write Pending Queue Not Empty)",
      R"(Counts the number of cycles that the Write Pending Queue is not empty.  This can then be used to calculate the average queue occupancy (in conjunction with the WPQ Occupancy Accumulation count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_READ_HIT",
      EventDef::Encoding{.code = 0x23, .umask = 0x0, .msr_values = {0}},
      R"(Write Pending Queue CAM Match)",
      R"(Counts the number of times a request hits in the WPQ (write-pending queue).  The iMC allows writes and reads to pass up other writes to different addresses.  Before a read or a write is issued, it will first CAM the WPQ to see if there is a write pending to that address.  When reads hit, they are able to directly pull their data from the WPQ instead of going to memory.  Writes that hit will overwrite the existing data.  Partial writes that hit will not need to do underfill reads and will simply update their relevant sections.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_WRITE_HIT",
      EventDef::Encoding{.code = 0x24, .umask = 0x0, .msr_values = {0}},
      R"(Write Pending Queue CAM Match)",
      R"(Counts the number of times a request hits in the WPQ (write-pending queue).  The iMC allows writes and reads to pass up other writes to different addresses.  Before a read or a write is issued, it will first CAM the WPQ to see if there is a write pending to that address.  When reads hit, they are able to directly pull their data from the WPQ instead of going to memory.  Writes that hit will overwrite the existing data.  Partial writes that hit will not need to do underfill reads and will simply update their relevant sections.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WRONG_MM",
      EventDef::Encoding{.code = 0xC1, .umask = 0x0, .msr_values = {0}},
      R"(Not getting the requested Major Mode)",
      R"(Not getting the requested Major Mode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK1",
      EventDef::Encoding{.code = 0xB8, .umask = 0x1, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 1)",
      R"(WR_CAS Access to Rank 0; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK2",
      EventDef::Encoding{.code = 0xB8, .umask = 0x2, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 2)",
      R"(WR_CAS Access to Rank 0; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK4",
      EventDef::Encoding{.code = 0xB8, .umask = 0x4, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 4)",
      R"(WR_CAS Access to Rank 0; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK8",
      EventDef::Encoding{.code = 0xB8, .umask = 0x8, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 8)",
      R"(WR_CAS Access to Rank 0; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.ALLBANKS",
      EventDef::Encoding{.code = 0xB8, .umask = 0x10, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; All Banks)",
      R"(WR_CAS Access to Rank 0; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK0",
      EventDef::Encoding{.code = 0xB8, .umask = 0x0, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 0)",
      R"(WR_CAS Access to Rank 0; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK3",
      EventDef::Encoding{.code = 0xB8, .umask = 0x3, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 3)",
      R"(WR_CAS Access to Rank 0; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK5",
      EventDef::Encoding{.code = 0xB8, .umask = 0x5, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 5)",
      R"(WR_CAS Access to Rank 0; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK6",
      EventDef::Encoding{.code = 0xB8, .umask = 0x6, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 6)",
      R"(WR_CAS Access to Rank 0; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK7",
      EventDef::Encoding{.code = 0xB8, .umask = 0x7, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 7)",
      R"(WR_CAS Access to Rank 0; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK9",
      EventDef::Encoding{.code = 0xB8, .umask = 0x9, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 9)",
      R"(WR_CAS Access to Rank 0; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK10",
      EventDef::Encoding{.code = 0xB8, .umask = 0xA, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 10)",
      R"(WR_CAS Access to Rank 0; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK11",
      EventDef::Encoding{.code = 0xB8, .umask = 0xB, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 11)",
      R"(WR_CAS Access to Rank 0; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK12",
      EventDef::Encoding{.code = 0xB8, .umask = 0xC, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 12)",
      R"(WR_CAS Access to Rank 0; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK13",
      EventDef::Encoding{.code = 0xB8, .umask = 0xD, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 13)",
      R"(WR_CAS Access to Rank 0; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK14",
      EventDef::Encoding{.code = 0xB8, .umask = 0xE, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 14)",
      R"(WR_CAS Access to Rank 0; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANK15",
      EventDef::Encoding{.code = 0xB8, .umask = 0xF, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank 15)",
      R"(WR_CAS Access to Rank 0; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANKG0",
      EventDef::Encoding{.code = 0xB8, .umask = 0x11, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank Group 0 (Banks 0-3))",
      R"(WR_CAS Access to Rank 0; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANKG1",
      EventDef::Encoding{.code = 0xB8, .umask = 0x12, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank Group 1 (Banks 4-7))",
      R"(WR_CAS Access to Rank 0; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANKG2",
      EventDef::Encoding{.code = 0xB8, .umask = 0x13, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank Group 2 (Banks 8-11))",
      R"(WR_CAS Access to Rank 0; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK0.BANKG3",
      EventDef::Encoding{.code = 0xB8, .umask = 0x14, .msr_values = {0}},
      R"(WR_CAS Access to Rank 0; Bank Group 3 (Banks 12-15))",
      R"(WR_CAS Access to Rank 0; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK1",
      EventDef::Encoding{.code = 0xB9, .umask = 0x1, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 1)",
      R"(WR_CAS Access to Rank 1; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK2",
      EventDef::Encoding{.code = 0xB9, .umask = 0x2, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 2)",
      R"(WR_CAS Access to Rank 1; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK4",
      EventDef::Encoding{.code = 0xB9, .umask = 0x4, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 4)",
      R"(WR_CAS Access to Rank 1; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK8",
      EventDef::Encoding{.code = 0xB9, .umask = 0x8, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 8)",
      R"(WR_CAS Access to Rank 1; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.ALLBANKS",
      EventDef::Encoding{.code = 0xB9, .umask = 0x10, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; All Banks)",
      R"(WR_CAS Access to Rank 1; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK0",
      EventDef::Encoding{.code = 0xB9, .umask = 0x0, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 0)",
      R"(WR_CAS Access to Rank 1; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK3",
      EventDef::Encoding{.code = 0xB9, .umask = 0x3, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 3)",
      R"(WR_CAS Access to Rank 1; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK5",
      EventDef::Encoding{.code = 0xB9, .umask = 0x5, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 5)",
      R"(WR_CAS Access to Rank 1; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK6",
      EventDef::Encoding{.code = 0xB9, .umask = 0x6, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 6)",
      R"(WR_CAS Access to Rank 1; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK7",
      EventDef::Encoding{.code = 0xB9, .umask = 0x7, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 7)",
      R"(WR_CAS Access to Rank 1; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK9",
      EventDef::Encoding{.code = 0xB9, .umask = 0x9, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 9)",
      R"(WR_CAS Access to Rank 1; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK10",
      EventDef::Encoding{.code = 0xB9, .umask = 0xA, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 10)",
      R"(WR_CAS Access to Rank 1; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK11",
      EventDef::Encoding{.code = 0xB9, .umask = 0xB, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 11)",
      R"(WR_CAS Access to Rank 1; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK12",
      EventDef::Encoding{.code = 0xB9, .umask = 0xC, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 12)",
      R"(WR_CAS Access to Rank 1; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK13",
      EventDef::Encoding{.code = 0xB9, .umask = 0xD, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 13)",
      R"(WR_CAS Access to Rank 1; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK14",
      EventDef::Encoding{.code = 0xB9, .umask = 0xE, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 14)",
      R"(WR_CAS Access to Rank 1; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANK15",
      EventDef::Encoding{.code = 0xB9, .umask = 0xF, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank 15)",
      R"(WR_CAS Access to Rank 1; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANKG0",
      EventDef::Encoding{.code = 0xB9, .umask = 0x11, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank Group 0 (Banks 0-3))",
      R"(WR_CAS Access to Rank 1; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANKG1",
      EventDef::Encoding{.code = 0xB9, .umask = 0x12, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank Group 1 (Banks 4-7))",
      R"(WR_CAS Access to Rank 1; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANKG2",
      EventDef::Encoding{.code = 0xB9, .umask = 0x13, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank Group 2 (Banks 8-11))",
      R"(WR_CAS Access to Rank 1; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK1.BANKG3",
      EventDef::Encoding{.code = 0xB9, .umask = 0x14, .msr_values = {0}},
      R"(WR_CAS Access to Rank 1; Bank Group 3 (Banks 12-15))",
      R"(WR_CAS Access to Rank 1; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK1",
      EventDef::Encoding{.code = 0xBC, .umask = 0x1, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 1)",
      R"(WR_CAS Access to Rank 4; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK2",
      EventDef::Encoding{.code = 0xBC, .umask = 0x2, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 2)",
      R"(WR_CAS Access to Rank 4; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK4",
      EventDef::Encoding{.code = 0xBC, .umask = 0x4, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 4)",
      R"(WR_CAS Access to Rank 4; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK8",
      EventDef::Encoding{.code = 0xBC, .umask = 0x8, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 8)",
      R"(WR_CAS Access to Rank 4; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.ALLBANKS",
      EventDef::Encoding{.code = 0xBC, .umask = 0x10, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; All Banks)",
      R"(WR_CAS Access to Rank 4; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK0",
      EventDef::Encoding{.code = 0xBC, .umask = 0x0, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 0)",
      R"(WR_CAS Access to Rank 4; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK3",
      EventDef::Encoding{.code = 0xBC, .umask = 0x3, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 3)",
      R"(WR_CAS Access to Rank 4; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK5",
      EventDef::Encoding{.code = 0xBC, .umask = 0x5, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 5)",
      R"(WR_CAS Access to Rank 4; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK6",
      EventDef::Encoding{.code = 0xBC, .umask = 0x6, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 6)",
      R"(WR_CAS Access to Rank 4; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK7",
      EventDef::Encoding{.code = 0xBC, .umask = 0x7, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 7)",
      R"(WR_CAS Access to Rank 4; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK9",
      EventDef::Encoding{.code = 0xBC, .umask = 0x9, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 9)",
      R"(WR_CAS Access to Rank 4; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK10",
      EventDef::Encoding{.code = 0xBC, .umask = 0xA, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 10)",
      R"(WR_CAS Access to Rank 4; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK11",
      EventDef::Encoding{.code = 0xBC, .umask = 0xB, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 11)",
      R"(WR_CAS Access to Rank 4; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK12",
      EventDef::Encoding{.code = 0xBC, .umask = 0xC, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 12)",
      R"(WR_CAS Access to Rank 4; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK13",
      EventDef::Encoding{.code = 0xBC, .umask = 0xD, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 13)",
      R"(WR_CAS Access to Rank 4; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK14",
      EventDef::Encoding{.code = 0xBC, .umask = 0xE, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 14)",
      R"(WR_CAS Access to Rank 4; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANK15",
      EventDef::Encoding{.code = 0xBC, .umask = 0xF, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank 15)",
      R"(WR_CAS Access to Rank 4; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANKG0",
      EventDef::Encoding{.code = 0xBC, .umask = 0x11, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank Group 0 (Banks 0-3))",
      R"(WR_CAS Access to Rank 4; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANKG1",
      EventDef::Encoding{.code = 0xBC, .umask = 0x12, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank Group 1 (Banks 4-7))",
      R"(WR_CAS Access to Rank 4; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANKG2",
      EventDef::Encoding{.code = 0xBC, .umask = 0x13, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank Group 2 (Banks 8-11))",
      R"(WR_CAS Access to Rank 4; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK4.BANKG3",
      EventDef::Encoding{.code = 0xBC, .umask = 0x14, .msr_values = {0}},
      R"(WR_CAS Access to Rank 4; Bank Group 3 (Banks 12-15))",
      R"(WR_CAS Access to Rank 4; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK1",
      EventDef::Encoding{.code = 0xBD, .umask = 0x1, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 1)",
      R"(WR_CAS Access to Rank 5; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK2",
      EventDef::Encoding{.code = 0xBD, .umask = 0x2, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 2)",
      R"(WR_CAS Access to Rank 5; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK4",
      EventDef::Encoding{.code = 0xBD, .umask = 0x4, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 4)",
      R"(WR_CAS Access to Rank 5; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK8",
      EventDef::Encoding{.code = 0xBD, .umask = 0x8, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 8)",
      R"(WR_CAS Access to Rank 5; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.ALLBANKS",
      EventDef::Encoding{.code = 0xBD, .umask = 0x10, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; All Banks)",
      R"(WR_CAS Access to Rank 5; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK0",
      EventDef::Encoding{.code = 0xBD, .umask = 0x0, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 0)",
      R"(WR_CAS Access to Rank 5; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK3",
      EventDef::Encoding{.code = 0xBD, .umask = 0x3, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 3)",
      R"(WR_CAS Access to Rank 5; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK5",
      EventDef::Encoding{.code = 0xBD, .umask = 0x5, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 5)",
      R"(WR_CAS Access to Rank 5; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK6",
      EventDef::Encoding{.code = 0xBD, .umask = 0x6, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 6)",
      R"(WR_CAS Access to Rank 5; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK7",
      EventDef::Encoding{.code = 0xBD, .umask = 0x7, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 7)",
      R"(WR_CAS Access to Rank 5; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK9",
      EventDef::Encoding{.code = 0xBD, .umask = 0x9, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 9)",
      R"(WR_CAS Access to Rank 5; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK10",
      EventDef::Encoding{.code = 0xBD, .umask = 0xA, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 10)",
      R"(WR_CAS Access to Rank 5; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK11",
      EventDef::Encoding{.code = 0xBD, .umask = 0xB, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 11)",
      R"(WR_CAS Access to Rank 5; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK12",
      EventDef::Encoding{.code = 0xBD, .umask = 0xC, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 12)",
      R"(WR_CAS Access to Rank 5; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK13",
      EventDef::Encoding{.code = 0xBD, .umask = 0xD, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 13)",
      R"(WR_CAS Access to Rank 5; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK14",
      EventDef::Encoding{.code = 0xBD, .umask = 0xE, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 14)",
      R"(WR_CAS Access to Rank 5; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANK15",
      EventDef::Encoding{.code = 0xBD, .umask = 0xF, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank 15)",
      R"(WR_CAS Access to Rank 5; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANKG0",
      EventDef::Encoding{.code = 0xBD, .umask = 0x11, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank Group 0 (Banks 0-3))",
      R"(WR_CAS Access to Rank 5; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANKG1",
      EventDef::Encoding{.code = 0xBD, .umask = 0x12, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank Group 1 (Banks 4-7))",
      R"(WR_CAS Access to Rank 5; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANKG2",
      EventDef::Encoding{.code = 0xBD, .umask = 0x13, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank Group 2 (Banks 8-11))",
      R"(WR_CAS Access to Rank 5; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK5.BANKG3",
      EventDef::Encoding{.code = 0xBD, .umask = 0x14, .msr_values = {0}},
      R"(WR_CAS Access to Rank 5; Bank Group 3 (Banks 12-15))",
      R"(WR_CAS Access to Rank 5; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK1",
      EventDef::Encoding{.code = 0xBE, .umask = 0x1, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 1)",
      R"(WR_CAS Access to Rank 6; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK2",
      EventDef::Encoding{.code = 0xBE, .umask = 0x2, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 2)",
      R"(WR_CAS Access to Rank 6; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK4",
      EventDef::Encoding{.code = 0xBE, .umask = 0x4, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 4)",
      R"(WR_CAS Access to Rank 6; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK8",
      EventDef::Encoding{.code = 0xBE, .umask = 0x8, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 8)",
      R"(WR_CAS Access to Rank 6; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.ALLBANKS",
      EventDef::Encoding{.code = 0xBE, .umask = 0x10, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; All Banks)",
      R"(WR_CAS Access to Rank 6; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK0",
      EventDef::Encoding{.code = 0xBE, .umask = 0x0, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 0)",
      R"(WR_CAS Access to Rank 6; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK3",
      EventDef::Encoding{.code = 0xBE, .umask = 0x3, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 3)",
      R"(WR_CAS Access to Rank 6; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK5",
      EventDef::Encoding{.code = 0xBE, .umask = 0x5, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 5)",
      R"(WR_CAS Access to Rank 6; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK6",
      EventDef::Encoding{.code = 0xBE, .umask = 0x6, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 6)",
      R"(WR_CAS Access to Rank 6; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK7",
      EventDef::Encoding{.code = 0xBE, .umask = 0x7, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 7)",
      R"(WR_CAS Access to Rank 6; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK9",
      EventDef::Encoding{.code = 0xBE, .umask = 0x9, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 9)",
      R"(WR_CAS Access to Rank 6; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK10",
      EventDef::Encoding{.code = 0xBE, .umask = 0xA, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 10)",
      R"(WR_CAS Access to Rank 6; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK11",
      EventDef::Encoding{.code = 0xBE, .umask = 0xB, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 11)",
      R"(WR_CAS Access to Rank 6; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK12",
      EventDef::Encoding{.code = 0xBE, .umask = 0xC, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 12)",
      R"(WR_CAS Access to Rank 6; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK13",
      EventDef::Encoding{.code = 0xBE, .umask = 0xD, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 13)",
      R"(WR_CAS Access to Rank 6; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK14",
      EventDef::Encoding{.code = 0xBE, .umask = 0xE, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 14)",
      R"(WR_CAS Access to Rank 6; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANK15",
      EventDef::Encoding{.code = 0xBE, .umask = 0xF, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank 15)",
      R"(WR_CAS Access to Rank 6; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANKG0",
      EventDef::Encoding{.code = 0xBE, .umask = 0x11, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank Group 0 (Banks 0-3))",
      R"(WR_CAS Access to Rank 6; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANKG1",
      EventDef::Encoding{.code = 0xBE, .umask = 0x12, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank Group 1 (Banks 4-7))",
      R"(WR_CAS Access to Rank 6; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANKG2",
      EventDef::Encoding{.code = 0xBE, .umask = 0x13, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank Group 2 (Banks 8-11))",
      R"(WR_CAS Access to Rank 6; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK6.BANKG3",
      EventDef::Encoding{.code = 0xBE, .umask = 0x14, .msr_values = {0}},
      R"(WR_CAS Access to Rank 6; Bank Group 3 (Banks 12-15))",
      R"(WR_CAS Access to Rank 6; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK1",
      EventDef::Encoding{.code = 0xBF, .umask = 0x1, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 1)",
      R"(WR_CAS Access to Rank 7; Bank 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK2",
      EventDef::Encoding{.code = 0xBF, .umask = 0x2, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 2)",
      R"(WR_CAS Access to Rank 7; Bank 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK4",
      EventDef::Encoding{.code = 0xBF, .umask = 0x4, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 4)",
      R"(WR_CAS Access to Rank 7; Bank 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK8",
      EventDef::Encoding{.code = 0xBF, .umask = 0x8, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 8)",
      R"(WR_CAS Access to Rank 7; Bank 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.ALLBANKS",
      EventDef::Encoding{.code = 0xBF, .umask = 0x10, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; All Banks)",
      R"(WR_CAS Access to Rank 7; All Banks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK0",
      EventDef::Encoding{.code = 0xBF, .umask = 0x0, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 0)",
      R"(WR_CAS Access to Rank 7; Bank 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK3",
      EventDef::Encoding{.code = 0xBF, .umask = 0x3, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 3)",
      R"(WR_CAS Access to Rank 7; Bank 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK5",
      EventDef::Encoding{.code = 0xBF, .umask = 0x5, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 5)",
      R"(WR_CAS Access to Rank 7; Bank 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK6",
      EventDef::Encoding{.code = 0xBF, .umask = 0x6, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 6)",
      R"(WR_CAS Access to Rank 7; Bank 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK7",
      EventDef::Encoding{.code = 0xBF, .umask = 0x7, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 7)",
      R"(WR_CAS Access to Rank 7; Bank 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK9",
      EventDef::Encoding{.code = 0xBF, .umask = 0x9, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 9)",
      R"(WR_CAS Access to Rank 7; Bank 9)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK10",
      EventDef::Encoding{.code = 0xBF, .umask = 0xA, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 10)",
      R"(WR_CAS Access to Rank 7; Bank 10)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK11",
      EventDef::Encoding{.code = 0xBF, .umask = 0xB, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 11)",
      R"(WR_CAS Access to Rank 7; Bank 11)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK12",
      EventDef::Encoding{.code = 0xBF, .umask = 0xC, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 12)",
      R"(WR_CAS Access to Rank 7; Bank 12)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK13",
      EventDef::Encoding{.code = 0xBF, .umask = 0xD, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 13)",
      R"(WR_CAS Access to Rank 7; Bank 13)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK14",
      EventDef::Encoding{.code = 0xBF, .umask = 0xE, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 14)",
      R"(WR_CAS Access to Rank 7; Bank 14)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANK15",
      EventDef::Encoding{.code = 0xBF, .umask = 0xF, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank 15)",
      R"(WR_CAS Access to Rank 7; Bank 15)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANKG0",
      EventDef::Encoding{.code = 0xBF, .umask = 0x11, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank Group 0 (Banks 0-3))",
      R"(WR_CAS Access to Rank 7; Bank Group 0 (Banks 0-3))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANKG1",
      EventDef::Encoding{.code = 0xBF, .umask = 0x12, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank Group 1 (Banks 4-7))",
      R"(WR_CAS Access to Rank 7; Bank Group 1 (Banks 4-7))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANKG2",
      EventDef::Encoding{.code = 0xBF, .umask = 0x13, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank Group 2 (Banks 8-11))",
      R"(WR_CAS Access to Rank 7; Bank Group 2 (Banks 8-11))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WR_CAS_RANK7.BANKG3",
      EventDef::Encoding{.code = 0xBF, .umask = 0x14, .msr_values = {0}},
      R"(WR_CAS Access to Rank 7; Bank Group 3 (Banks 12-15))",
      R"(WR_CAS Access to Rank 7; Bank Group 3 (Banks 12-15))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CACHE_TOTAL_OCCUPANCY.ANY",
      EventDef::Encoding{.code = 0x12, .umask = 0x1, .msr_values = {0}},
      R"(Total Write Cache Occupancy; Any Source)",
      R"(Accumulates the number of reads and writes that are outstanding in the uncore in each cycle.  This is effectively the sum of the READ_OCCUPANCY and WRITE_OCCUPANCY events.; Tracks all requests from any source port.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CACHE_TOTAL_OCCUPANCY.SOURCE",
      EventDef::Encoding{.code = 0x12, .umask = 0x2, .msr_values = {0}},
      R"(Total Write Cache Occupancy; Select Source)",
      R"(Accumulates the number of reads and writes that are outstanding in the uncore in each cycle.  This is effectively the sum of the READ_OCCUPANCY and WRITE_OCCUPANCY events.; Tracks only those requests that come from the port specified in the IRP_PmonFilter.OrderingQ register.  This register allows one to select one specific queue.  It is not possible to monitor multiple queues at a time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CLOCKTICKS",
      EventDef::Encoding{.code = 0x0, .umask = 0x0, .msr_values = {0}},
      R"(Clocks in the IRP)",
      R"(Number of clocks in the IRP.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.PCIRDCUR",
      EventDef::Encoding{.code = 0x13, .umask = 0x1, .msr_values = {0}},
      R"(Coherent Ops; PCIRdCur)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.CRD",
      EventDef::Encoding{.code = 0x13, .umask = 0x2, .msr_values = {0}},
      R"(Coherent Ops; CRd)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.DRD",
      EventDef::Encoding{.code = 0x13, .umask = 0x4, .msr_values = {0}},
      R"(Coherent Ops; DRd)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.RFO",
      EventDef::Encoding{.code = 0x13, .umask = 0x8, .msr_values = {0}},
      R"(Coherent Ops; RFO)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.PCITOM",
      EventDef::Encoding{.code = 0x13, .umask = 0x10, .msr_values = {0}},
      R"(Coherent Ops; PCIItoM)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.PCIDCAHINT",
      EventDef::Encoding{.code = 0x13, .umask = 0x20, .msr_values = {0}},
      R"(Coherent Ops; PCIDCAHin5t)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.WBMTOI",
      EventDef::Encoding{.code = 0x13, .umask = 0x40, .msr_values = {0}},
      R"(Coherent Ops; WbMtoI)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.CLFLUSH",
      EventDef::Encoding{.code = 0x13, .umask = 0x80, .msr_values = {0}},
      R"(Coherent Ops; CLFlush)",
      R"(Counts the number of coherency related operations servied by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.FAST_REQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x1, .msr_values = {0}},
      R"(Misc Events - Set 0; Fastpath Requests)",
      R"(Misc Events - Set 0; Fastpath Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.FAST_REJ",
      EventDef::Encoding{.code = 0x14, .umask = 0x2, .msr_values = {0}},
      R"(Misc Events - Set 0; Fastpath Rejects)",
      R"(Misc Events - Set 0; Fastpath Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.2ND_RD_INSERT",
      EventDef::Encoding{.code = 0x14, .umask = 0x4, .msr_values = {0}},
      R"(Misc Events - Set 0; Cache Inserts of Read Transactions as Secondary)",
      R"(Misc Events - Set 0; Cache Inserts of Read Transactions as Secondary)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.2ND_WR_INSERT",
      EventDef::Encoding{.code = 0x14, .umask = 0x8, .msr_values = {0}},
      R"(Misc Events - Set 0; Cache Inserts of Write Transactions as Secondary)",
      R"(Misc Events - Set 0; Cache Inserts of Write Transactions as Secondary)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.2ND_ATOMIC_INSERT",
      EventDef::Encoding{.code = 0x14, .umask = 0x10, .msr_values = {0}},
      R"(Misc Events - Set 0; Cache Inserts of Atomic Transactions as Secondary)",
      R"(Misc Events - Set 0; Cache Inserts of Atomic Transactions as Secondary)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.FAST_XFER",
      EventDef::Encoding{.code = 0x14, .umask = 0x20, .msr_values = {0}},
      R"(Misc Events - Set 0; Fastpath Transfers From Primary to Secondary)",
      R"(Misc Events - Set 0; Fastpath Transfers From Primary to Secondary)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.PF_ACK_HINT",
      EventDef::Encoding{.code = 0x14, .umask = 0x40, .msr_values = {0}},
      R"(Misc Events - Set 0; Prefetch Ack Hints From Primary to Secondary)",
      R"(Misc Events - Set 0; Prefetch Ack Hints From Primary to Secondary)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.PF_TIMEOUT",
      EventDef::Encoding{.code = 0x14, .umask = 0x80, .msr_values = {0}},
      R"(Misc Events - Set 0; Prefetch TimeOut)",
      R"(Indicates the fetch for a previous prefetch wasn't accepted by the prefetch.   This happens in the case of a prefetch TimeOut)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.SLOW_I",
      EventDef::Encoding{.code = 0x15, .umask = 0x1, .msr_values = {0}},
      R"(Misc Events - Set 1; Slow Transfer of I Line)",
      R"(Snoop took cacheline ownership before write from data was committed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.SLOW_S",
      EventDef::Encoding{.code = 0x15, .umask = 0x2, .msr_values = {0}},
      R"(Misc Events - Set 1; Slow Transfer of S Line)",
      R"(Secondary received a transfer that did not have sufficient MESI state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.SLOW_E",
      EventDef::Encoding{.code = 0x15, .umask = 0x4, .msr_values = {0}},
      R"(Misc Events - Set 1; Slow Transfer of E Line)",
      R"(Secondary received a transfer that did have sufficient MESI state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.SLOW_M",
      EventDef::Encoding{.code = 0x15, .umask = 0x8, .msr_values = {0}},
      R"(Misc Events - Set 1; Slow Transfer of M Line)",
      R"(Snoop took cacheline ownership before write from data was committed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.LOST_FWD",
      EventDef::Encoding{.code = 0x15, .umask = 0x10, .msr_values = {0}},
      R"(Misc Events - Set 1)",
      R"(Misc Events - Set 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.SEC_RCVD_INVLD",
      EventDef::Encoding{.code = 0x15, .umask = 0x20, .msr_values = {0}},
      R"(Misc Events - Set 1; Received Invalid)",
      R"(Secondary received a transfer that did not have sufficient MESI state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.SEC_RCVD_VLD",
      EventDef::Encoding{.code = 0x15, .umask = 0x40, .msr_values = {0}},
      R"(Misc Events - Set 1; Received Valid)",
      R"(Secondary received a transfer that did have sufficient MESI state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.DATA_THROTTLE",
      EventDef::Encoding{.code = 0x15, .umask = 0x80, .msr_values = {0}},
      R"(Misc Events - Set 1; Data Throttled)",
      R"(IRP throttled switch data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_AK_INSERTS",
      EventDef::Encoding{.code = 0xA, .umask = 0x0, .msr_values = {0}},
      R"(AK Ingress Occupancy)",
      R"(Counts the number of allocations into the AK Ingress.  This queue is where the IRP receives responses from R2PCIe (the ring).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_DRS_CYCLES_FULL",
      EventDef::Encoding{.code = 0x4, .umask = 0x0, .msr_values = {0}},
      R"(UNC_I_RxR_BL_DRS_CYCLES_FULL (Description is auto-generated))",
      R"(Counts the number of cycles when the BL Ingress is full.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_DRS_INSERTS",
      EventDef::Encoding{.code = 0x1, .umask = 0x0, .msr_values = {0}},
      R"(BL Ingress Occupancy - DRS)",
      R"(Counts the number of allocations into the BL Ingress.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_DRS_OCCUPANCY",
      EventDef::Encoding{.code = 0x7, .umask = 0x0, .msr_values = {0}},
      R"(UNC_I_RxR_BL_DRS_OCCUPANCY (Description is auto-generated))",
      R"(Accumulates the occupancy of the BL Ingress in each cycles.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_NCB_CYCLES_FULL",
      EventDef::Encoding{.code = 0x5, .umask = 0x0, .msr_values = {0}},
      R"(UNC_I_RxR_BL_NCB_CYCLES_FULL (Description is auto-generated))",
      R"(Counts the number of cycles when the BL Ingress is full.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_NCB_INSERTS",
      EventDef::Encoding{.code = 0x2, .umask = 0x0, .msr_values = {0}},
      R"(BL Ingress Occupancy - NCB)",
      R"(Counts the number of allocations into the BL Ingress.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_NCB_OCCUPANCY",
      EventDef::Encoding{.code = 0x8, .umask = 0x0, .msr_values = {0}},
      R"(UNC_I_RxR_BL_NCB_OCCUPANCY (Description is auto-generated))",
      R"(Accumulates the occupancy of the BL Ingress in each cycles.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_NCS_CYCLES_FULL",
      EventDef::Encoding{.code = 0x6, .umask = 0x0, .msr_values = {0}},
      R"(UNC_I_RxR_BL_NCS_CYCLES_FULL (Description is auto-generated))",
      R"(Counts the number of cycles when the BL Ingress is full.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_NCS_INSERTS",
      EventDef::Encoding{.code = 0x3, .umask = 0x0, .msr_values = {0}},
      R"(BL Ingress Occupancy - NCS)",
      R"(Counts the number of allocations into the BL Ingress.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_RxR_BL_NCS_OCCUPANCY",
      EventDef::Encoding{.code = 0x9, .umask = 0x0, .msr_values = {0}},
      R"(UNC_I_RxR_BL_NCS_OCCUPANCY (Description is auto-generated))",
      R"(Accumulates the occupancy of the BL Ingress in each cycles.  This queue is where the IRP receives data from R2PCIe (the ring).  It is used for data returns from read requets as well as outbound MMIO writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.MISS",
      EventDef::Encoding{.code = 0x17, .umask = 0x1, .msr_values = {0}},
      R"(Snoop Responses; Miss)",
      R"(Snoop Responses; Miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.HIT_I",
      EventDef::Encoding{.code = 0x17, .umask = 0x2, .msr_values = {0}},
      R"(Snoop Responses; Hit I)",
      R"(Snoop Responses; Hit I)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.HIT_ES",
      EventDef::Encoding{.code = 0x17, .umask = 0x4, .msr_values = {0}},
      R"(Snoop Responses; Hit E or S)",
      R"(Snoop Responses; Hit E or S)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.HIT_M",
      EventDef::Encoding{.code = 0x17, .umask = 0x8, .msr_values = {0}},
      R"(Snoop Responses; Hit M)",
      R"(Snoop Responses; Hit M)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.SNPCODE",
      EventDef::Encoding{.code = 0x17, .umask = 0x10, .msr_values = {0}},
      R"(Snoop Responses; SnpCode)",
      R"(Snoop Responses; SnpCode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.SNPDATA",
      EventDef::Encoding{.code = 0x17, .umask = 0x20, .msr_values = {0}},
      R"(Snoop Responses; SnpData)",
      R"(Snoop Responses; SnpData)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.SNPINV",
      EventDef::Encoding{.code = 0x17, .umask = 0x40, .msr_values = {0}},
      R"(Snoop Responses; SnpInv)",
      R"(Snoop Responses; SnpInv)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.READS",
      EventDef::Encoding{.code = 0x16, .umask = 0x1, .msr_values = {0}},
      R"(Inbound Transaction Count; Reads)",
      R"(Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks only read requests (not including read prefetches).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.WRITES",
      EventDef::Encoding{.code = 0x16, .umask = 0x2, .msr_values = {0}},
      R"(Inbound Transaction Count; Writes)",
      R"(Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks only write requests.  Each write request should have a prefetch, so there is no need to explicitly track these requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.RD_PREF",
      EventDef::Encoding{.code = 0x16, .umask = 0x4, .msr_values = {0}},
      R"(Inbound Transaction Count; Read Prefetches)",
      R"(Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of read prefetches.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.WR_PREF",
      EventDef::Encoding{.code = 0x16, .umask = 0x8, .msr_values = {0}},
      R"(Inbound Transaction Count; Write Prefetches)",
      R"(Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of write prefetches.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.ATOMIC",
      EventDef::Encoding{.code = 0x16, .umask = 0x10, .msr_values = {0}},
      R"(Inbound Transaction Count; Atomic)",
      R"(Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of atomic transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.OTHER",
      EventDef::Encoding{.code = 0x16, .umask = 0x20, .msr_values = {0}},
      R"(Inbound Transaction Count; Other)",
      R"(Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks the number of 'other' kinds of transactions.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.ORDERINGQ",
      EventDef::Encoding{.code = 0x16, .umask = 0x40, .msr_values = {0}},
      R"(Inbound Transaction Count; Select Source)",
      R"(Counts the number of Inbound transactions from the IRP to the Uncore.  This can be filtered based on request type in addition to the source queue.  Note the special filtering equation.  We do OR-reduction on the request type.  If the SOURCE bit is set, then we also do AND qualification based on the source portID.; Tracks only those requests that come from the port specified in the IRP_PmonFilter.OrderingQ register.  This register allows one to select one specific queue.  It is not possible to monitor multiple queues at a time.  If this bit is not set, then requests from all sources will be counted.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TxR_AD_STALL_CREDIT_CYCLES",
      EventDef::Encoding{.code = 0x18, .umask = 0x0, .msr_values = {0}},
      R"(No AD Egress Credit Stalls)",
      R"(Counts the number times when it is not possible to issue a request to the R2PCIe because there are no AD Egress Credits available.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TxR_BL_STALL_CREDIT_CYCLES",
      EventDef::Encoding{.code = 0x19, .umask = 0x0, .msr_values = {0}},
      R"(No BL Egress Credit Stalls)",
      R"(Counts the number times when it is not possible to issue data to the R2PCIe because there are no BL Egress Credits available.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TxR_DATA_INSERTS_NCB",
      EventDef::Encoding{.code = 0xE, .umask = 0x0, .msr_values = {0}},
      R"(Outbound Read Requests)",
      R"(Counts the number of requests issued to the switch (towards the devices).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TxR_DATA_INSERTS_NCS",
      EventDef::Encoding{.code = 0xF, .umask = 0x0, .msr_values = {0}},
      R"(Outbound Read Requests)",
      R"(Counts the number of requests issued to the switch (towards the devices).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TxR_REQUEST_OCCUPANCY",
      EventDef::Encoding{.code = 0xD, .umask = 0x0, .msr_values = {0}},
      R"(Outbound Request Queue Occupancy)",
      R"(Accumultes the number of outstanding outbound requests from the IRP to the switch (towards the devices).  This can be used in conjuection with the allocations event in order to calculate average latency of outbound requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x0, .umask = 0x0, .msr_values = {0}},
      R"(pclk Cycles)",
      R"(The PCU runs off a fixed 1 GHz clock.  This event counts the number of pclk cycles measured while the counter was enabled.  The pclk, like the Memory Controller's dclk, counts at a constant rate making it a good measure of actual wall time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE0_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x60, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE10_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x6A, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE11_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x6B, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE12_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x6C, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE13_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x6D, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE14_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x6E, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE15_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x6F, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE16_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x70, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE17_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x71, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE1_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x61, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE2_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x62, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE3_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x63, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE4_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x64, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE5_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x65, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE6_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x66, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE7_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x67, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE8_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x68, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CORE9_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x69, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions.  There is one event per core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE0",
      EventDef::Encoding{.code = 0x30, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE1",
      EventDef::Encoding{.code = 0x31, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE10",
      EventDef::Encoding{.code = 0x3A, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE11",
      EventDef::Encoding{.code = 0x3B, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE12",
      EventDef::Encoding{.code = 0x3C, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE13",
      EventDef::Encoding{.code = 0x3D, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE14",
      EventDef::Encoding{.code = 0x3E, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE15",
      EventDef::Encoding{.code = 0x3F, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE16",
      EventDef::Encoding{.code = 0x40, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE17",
      EventDef::Encoding{.code = 0x41, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE2",
      EventDef::Encoding{.code = 0x32, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE3",
      EventDef::Encoding{.code = 0x33, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE4",
      EventDef::Encoding{.code = 0x34, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE5",
      EventDef::Encoding{.code = 0x35, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE6",
      EventDef::Encoding{.code = 0x36, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE7",
      EventDef::Encoding{.code = 0x37, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE8",
      EventDef::Encoding{.code = 0x38, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_DEMOTIONS_CORE9",
      EventDef::Encoding{.code = 0x39, .umask = 0x0, .msr_values = {0}},
      R"(Core C State Demotions)",
      R"(Counts the number of times when a configurable cores had a C-state demotion)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MAX_LIMIT_THERMAL_CYCLES",
      EventDef::Encoding{.code = 0x4, .umask = 0x0, .msr_values = {0}},
      R"(Thermal Strongest Upper Limit Cycles)",
      R"(Counts the number of cycles when thermal conditions are the upper limit on frequency.  This is related to the THERMAL_THROTTLE CYCLES_ABOVE_TEMP event, which always counts cycles when we are above the thermal temperature.  This event (STRONGEST_UPPER_LIMIT) is sampled at the output of the algorithm that determines the actual frequency, while THERMAL_THROTTLE looks at the input.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MAX_OS_CYCLES",
      EventDef::Encoding{.code = 0x6, .umask = 0x0, .msr_values = {0}},
      R"(OS Strongest Upper Limit Cycles)",
      R"(Counts the number of cycles when the OS is the upper limit on frequency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MAX_POWER_CYCLES",
      EventDef::Encoding{.code = 0x5, .umask = 0x0, .msr_values = {0}},
      R"(Power Strongest Upper Limit Cycles)",
      R"(Counts the number of cycles when power is the upper limit on frequency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MIN_IO_P_CYCLES",
      EventDef::Encoding{.code = 0x73, .umask = 0x0, .msr_values = {0}},
      R"(IO P Limit Strongest Lower Limit Cycles)",
      R"(Counts the number of cycles when IO P Limit is preventing us from dropping the frequency lower.  This algorithm monitors the needs to the IO subsystem on both local and remote sockets and will maintain a frequency high enough to maintain good IO BW.  This is necessary for when all the IA cores on a socket are idle but a user still would like to maintain high IO Bandwidth.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_TRANS_CYCLES",
      EventDef::Encoding{.code = 0x74, .umask = 0x0, .msr_values = {0}},
      R"(Cycles spent changing Frequency)",
      R"(Counts the number of cycles when the system is changing frequency.  This can not be filtered by thread ID.  One can also use it with the occupancy counter that monitors number of threads in C0 to estimate the performance impact that frequency transitions had on the system.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_MEMORY_PHASE_SHEDDING_CYCLES",
      EventDef::Encoding{.code = 0x2F, .umask = 0x0, .msr_values = {0}},
      R"(Memory Phase Shedding Cycles)",
      R"(Counts the number of cycles that the PCU has triggered memory phase shedding.  This is a mode that can be run in the iMC physicals that saves power at the expense of additional latency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C0_CYCLES",
      EventDef::Encoding{.code = 0x2A, .umask = 0x0, .msr_values = {0}},
      R"(Package C State Residency - C0)",
      R"(Counts the number of cycles when the package was in C0.  This event can be used in conjunction with edge detect to count C0 entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C1E_CYCLES",
      EventDef::Encoding{.code = 0x4E, .umask = 0x0, .msr_values = {0}},
      R"(Package C State Residency - C1E)",
      R"(Counts the number of cycles when the package was in C1E.  This event can be used in conjunction with edge detect to count C1E entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C2E_CYCLES",
      EventDef::Encoding{.code = 0x2B, .umask = 0x0, .msr_values = {0}},
      R"(Package C State Residency - C2E)",
      R"(Counts the number of cycles when the package was in C2E.  This event can be used in conjunction with edge detect to count C2E entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C3_CYCLES",
      EventDef::Encoding{.code = 0x2C, .umask = 0x0, .msr_values = {0}},
      R"(Package C State Residency - C3)",
      R"(Counts the number of cycles when the package was in C3.  This event can be used in conjunction with edge detect to count C3 entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C6_CYCLES",
      EventDef::Encoding{.code = 0x2D, .umask = 0x0, .msr_values = {0}},
      R"(Package C State Residency - C6)",
      R"(Counts the number of cycles when the package was in C6.  This event can be used in conjunction with edge detect to count C6 entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C7_CYCLES",
      EventDef::Encoding{.code = 0x2E, .umask = 0x0, .msr_values = {0}},
      R"(Package C7 State Residency)",
      R"(Counts the number of cycles when the package was in C7.  This event can be used in conjunction with edge detect to count C7 entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY.CORES_C0",
      EventDef::Encoding{.code = 0x80, .umask = 0x40, .msr_values = {0}},
      R"(Number of cores in C-State; C0 and C1)",
      R"(This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with threshholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY.CORES_C3",
      EventDef::Encoding{.code = 0x80, .umask = 0x80, .msr_values = {0}},
      R"(Number of cores in C-State; C3)",
      R"(This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with threshholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY.CORES_C6",
      EventDef::Encoding{.code = 0x80, .umask = 0xC0, .msr_values = {0}},
      R"(Number of cores in C-State; C6 and C7)",
      R"(This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with threshholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PROCHOT_EXTERNAL_CYCLES",
      EventDef::Encoding{.code = 0xA, .umask = 0x0, .msr_values = {0}},
      R"(External Prochot)",
      R"(Counts the number of cycles that we are in external PROCHOT mode.  This mode is triggered when a sensor off the die determines that something off-die (like DRAM) is too hot and must throttle to avoid damaging the chip.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PROCHOT_INTERNAL_CYCLES",
      EventDef::Encoding{.code = 0x9, .umask = 0x0, .msr_values = {0}},
      R"(Internal Prochot)",
      R"(Counts the number of cycles that we are in Interal PROCHOT mode.  This mode is triggered when a sensor on the die determines that we are too hot and must throttle to avoid damaging the chip.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_TOTAL_TRANSITION_CYCLES",
      EventDef::Encoding{.code = 0x72, .umask = 0x0, .msr_values = {0}},
      R"(Total Core C State Transition Cycles)",
      R"(Number of cycles spent performing core C state transitions across all cores.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_UFS_TRANSITIONS_RING_GV",
      EventDef::Encoding{.code = 0x79, .umask = 0x0, .msr_values = {0}},
      R"(UNC_P_UFS_TRANSITIONS_RING_GV (Description is auto-generated))",
      R"(Ring GV with same final and initial frequency)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_VR_HOT_CYCLES",
      EventDef::Encoding{.code = 0x42, .umask = 0x0, .msr_values = {0}},
      R"(VR Hot)",
      R"(VR Hot)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_CLOCKTICKS",
      EventDef::Encoding{.code = 0x1, .umask = 0x0, .msr_values = {0}},
      R"(Number of uclks in domain)",
      R"(Counts the number of uclks in the R2PCIe uclk domain.  This could be slightly different than the count in the Ubox because of enable/freeze delays.  However, because the R2PCIe is close to the Ubox, they generally should not diverge by more than a handful of cycles.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDIT.PRQ_QPI0",
      EventDef::Encoding{.code = 0x2D, .umask = 0x1, .msr_values = {0}},
      R"(UNC_R2_IIO_CREDIT.PRQ_QPI0 (Description is auto-generated))",
      R"(UNC_R2_IIO_CREDIT.PRQ_QPI0 (Description is auto-generated))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDIT.PRQ_QPI1",
      EventDef::Encoding{.code = 0x2D, .umask = 0x2, .msr_values = {0}},
      R"(UNC_R2_IIO_CREDIT.PRQ_QPI1 (Description is auto-generated))",
      R"(UNC_R2_IIO_CREDIT.PRQ_QPI1 (Description is auto-generated))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDIT.ISOCH_QPI0",
      EventDef::Encoding{.code = 0x2D, .umask = 0x4, .msr_values = {0}},
      R"(UNC_R2_IIO_CREDIT.ISOCH_QPI0 (Description is auto-generated))",
      R"(UNC_R2_IIO_CREDIT.ISOCH_QPI0 (Description is auto-generated))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDIT.ISOCH_QPI1",
      EventDef::Encoding{.code = 0x2D, .umask = 0x8, .msr_values = {0}},
      R"(UNC_R2_IIO_CREDIT.ISOCH_QPI1 (Description is auto-generated))",
      R"(UNC_R2_IIO_CREDIT.ISOCH_QPI1 (Description is auto-generated))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDITS_ACQUIRED.DRS",
      EventDef::Encoding{.code = 0x33, .umask = 0x8, .msr_values = {0}},
      R"(R2PCIe IIO Credit Acquired; DRS)",
      R"(Counts the number of credits that are acquired in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the DRS message class.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDITS_ACQUIRED.NCB",
      EventDef::Encoding{.code = 0x33, .umask = 0x10, .msr_values = {0}},
      R"(R2PCIe IIO Credit Acquired; NCB)",
      R"(Counts the number of credits that are acquired in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCB message class.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDITS_ACQUIRED.NCS",
      EventDef::Encoding{.code = 0x33, .umask = 0x20, .msr_values = {0}},
      R"(R2PCIe IIO Credit Acquired; NCS)",
      R"(Counts the number of credits that are acquired in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCS message class.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDITS_USED.DRS",
      EventDef::Encoding{.code = 0x32, .umask = 0x8, .msr_values = {0}},
      R"(R2PCIe IIO Credits in Use; DRS)",
      R"(Counts the number of cycles when one or more credits in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the DRS message class.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDITS_USED.NCB",
      EventDef::Encoding{.code = 0x32, .umask = 0x10, .msr_values = {0}},
      R"(R2PCIe IIO Credits in Use; NCB)",
      R"(Counts the number of cycles when one or more credits in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCB message class.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_IIO_CREDITS_USED.NCS",
      EventDef::Encoding{.code = 0x32, .umask = 0x20, .msr_values = {0}},
      R"(R2PCIe IIO Credits in Use; NCS)",
      R"(Counts the number of cycles when one or more credits in the R2PCIe agent for sending transactions into the IIO on either NCB or NCS are in use.  Transactions from the BL ring going into the IIO Agent must first acquire a credit.  These credits are for either the NCB or NCS message classes.  NCB, or non-coherent bypass messages are used to transmit data without coherency (and are common).  NCS is used for reads to PCIe (and should be used sparingly).; Credits to the IIO for the NCS message class.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AD_USED.CW_EVEN",
      EventDef::Encoding{.code = 0x7, .umask = 0x1, .msr_values = {0}},
      R"(R2 AD Ring in Use; Clockwise and Even)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AD_USED.CW_ODD",
      EventDef::Encoding{.code = 0x7, .umask = 0x2, .msr_values = {0}},
      R"(R2 AD Ring in Use; Clockwise and Odd)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AD_USED.CCW_EVEN",
      EventDef::Encoding{.code = 0x7, .umask = 0x4, .msr_values = {0}},
      R"(R2 AD Ring in Use; Counterclockwise and Even)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AD_USED.CCW_ODD",
      EventDef::Encoding{.code = 0x7, .umask = 0x8, .msr_values = {0}},
      R"(R2 AD Ring in Use; Counterclockwise and Odd)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AD_USED.CW",
      EventDef::Encoding{.code = 0x7, .umask = 0x3, .msr_values = {0}},
      R"(R2 AD Ring in Use; Clockwise)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AD_USED.CCW",
      EventDef::Encoding{.code = 0x7, .umask = 0xC, .msr_values = {0}},
      R"(R2 AD Ring in Use; Counterclockwise)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AD_USED.ALL",
      EventDef::Encoding{.code = 0x7, .umask = 0xF, .msr_values = {0}},
      R"(R2 AD Ring in Use; All)",
      R"(Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_BOUNCES.UP",
      EventDef::Encoding{.code = 0x12, .umask = 0x1, .msr_values = {0}},
      R"(AK Ingress Bounced; Up)",
      R"(Counts the number of times when a request destined for the AK ingress bounced.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_BOUNCES.DN",
      EventDef::Encoding{.code = 0x12, .umask = 0x2, .msr_values = {0}},
      R"(AK Ingress Bounced; Dn)",
      R"(Counts the number of times when a request destined for the AK ingress bounced.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_USED.CW_EVEN",
      EventDef::Encoding{.code = 0x8, .umask = 0x1, .msr_values = {0}},
      R"(R2 AK Ring in Use; Clockwise and Even)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_USED.CW_ODD",
      EventDef::Encoding{.code = 0x8, .umask = 0x2, .msr_values = {0}},
      R"(R2 AK Ring in Use; Clockwise and Odd)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_USED.CCW_EVEN",
      EventDef::Encoding{.code = 0x8, .umask = 0x4, .msr_values = {0}},
      R"(R2 AK Ring in Use; Counterclockwise and Even)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_USED.CCW_ODD",
      EventDef::Encoding{.code = 0x8, .umask = 0x8, .msr_values = {0}},
      R"(R2 AK Ring in Use; Counterclockwise and Odd)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_USED.CW",
      EventDef::Encoding{.code = 0x8, .umask = 0x3, .msr_values = {0}},
      R"(R2 AK Ring in Use; Clockwise)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_USED.CCW",
      EventDef::Encoding{.code = 0x8, .umask = 0xC, .msr_values = {0}},
      R"(R2 AK Ring in Use; Counterclockwise)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_AK_USED.ALL",
      EventDef::Encoding{.code = 0x8, .umask = 0xF, .msr_values = {0}},
      R"(R2 AK Ring in Use; All)",
      R"(Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_BL_USED.CW_EVEN",
      EventDef::Encoding{.code = 0x9, .umask = 0x1, .msr_values = {0}},
      R"(R2 BL Ring in Use; Clockwise and Even)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_BL_USED.CW_ODD",
      EventDef::Encoding{.code = 0x9, .umask = 0x2, .msr_values = {0}},
      R"(R2 BL Ring in Use; Clockwise and Odd)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Clockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_BL_USED.CCW_EVEN",
      EventDef::Encoding{.code = 0x9, .umask = 0x4, .msr_values = {0}},
      R"(R2 BL Ring in Use; Counterclockwise and Even)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Even ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_BL_USED.CCW_ODD",
      EventDef::Encoding{.code = 0x9, .umask = 0x8, .msr_values = {0}},
      R"(R2 BL Ring in Use; Counterclockwise and Odd)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.; Filters for the Counterclockwise and Odd ring polarity.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_BL_USED.CW",
      EventDef::Encoding{.code = 0x9, .umask = 0x3, .msr_values = {0}},
      R"(R2 BL Ring in Use; Clockwise)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_BL_USED.CCW",
      EventDef::Encoding{.code = 0x9, .umask = 0xC, .msr_values = {0}},
      R"(R2 BL Ring in Use; Counterclockwise)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_BL_USED.ALL",
      EventDef::Encoding{.code = 0x9, .umask = 0xF, .msr_values = {0}},
      R"(R2 BL Ring in Use; All)",
      R"(Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk, but does not include when packets are being sent from the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_IV_USED.CW",
      EventDef::Encoding{.code = 0xA, .umask = 0x3, .msr_values = {0}},
      R"(R2 IV Ring in Use; Clockwise)",
      R"(Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_IV_USED.CCW",
      EventDef::Encoding{.code = 0xA, .umask = 0xC, .msr_values = {0}},
      R"(R2 IV Ring in Use; Counterclockwise)",
      R"(Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RING_IV_USED.ANY",
      EventDef::Encoding{.code = 0xA, .umask = 0xF, .msr_values = {0}},
      R"(R2 IV Ring in Use; Any)",
      R"(Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent, but does not include when packets are being sunk into the ring stop.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RxR_CYCLES_NE.NCB",
      EventDef::Encoding{.code = 0x10, .umask = 0x10, .msr_values = {0}},
      R"(Ingress Cycles Not Empty; NCB)",
      R"(Counts the number of cycles when the R2PCIe Ingress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCB Ingress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RxR_CYCLES_NE.NCS",
      EventDef::Encoding{.code = 0x10, .umask = 0x20, .msr_values = {0}},
      R"(Ingress Cycles Not Empty; NCS)",
      R"(Counts the number of cycles when the R2PCIe Ingress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCS Ingress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RxR_INSERTS.NCB",
      EventDef::Encoding{.code = 0x11, .umask = 0x10, .msr_values = {0}},
      R"(Ingress Allocations; NCB)",
      R"(Counts the number of allocations into the R2PCIe Ingress.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCB Ingress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RxR_INSERTS.NCS",
      EventDef::Encoding{.code = 0x11, .umask = 0x20, .msr_values = {0}},
      R"(Ingress Allocations; NCS)",
      R"(Counts the number of allocations into the R2PCIe Ingress.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.; NCS Ingress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_RxR_OCCUPANCY.DRS",
      EventDef::Encoding{.code = 0x13, .umask = 0x8, .msr_values = {0}},
      R"(Ingress Occupancy Accumulator; DRS)",
      R"(Accumulates the occupancy of a given R2PCIe Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the R2PCIe Ingress Not Empty event to calculate average occupancy or the R2PCIe Ingress Allocations event in order to calculate average queuing latency.; DRS Ingress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_SBO0_CREDITS_ACQUIRED.AD",
      EventDef::Encoding{.code = 0x28, .umask = 0x1, .msr_values = {0}},
      R"(SBo0 Credits Acquired; For AD Ring)",
      R"(Number of Sbo 0 credits acquired in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_SBO0_CREDITS_ACQUIRED.BL",
      EventDef::Encoding{.code = 0x28, .umask = 0x2, .msr_values = {0}},
      R"(SBo0 Credits Acquired; For BL Ring)",
      R"(Number of Sbo 0 credits acquired in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_SBO0_CREDIT_OCCUPANCY.AD",
      EventDef::Encoding{.code = 0x2A, .umask = 0x1, .msr_values = {0}},
      R"(SBo0 Credits Occupancy; For AD Ring)",
      R"(Number of Sbo 0 credits in use in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_SBO0_CREDIT_OCCUPANCY.BL",
      EventDef::Encoding{.code = 0x2A, .umask = 0x2, .msr_values = {0}},
      R"(SBo0 Credits Occupancy; For BL Ring)",
      R"(Number of Sbo 0 credits in use in a given cycle, per ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_STALL_NO_SBO_CREDIT.SBO0_AD",
      EventDef::Encoding{.code = 0x2C, .umask = 0x1, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo0, AD Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_STALL_NO_SBO_CREDIT.SBO1_AD",
      EventDef::Encoding{.code = 0x2C, .umask = 0x2, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo1, AD Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_STALL_NO_SBO_CREDIT.SBO0_BL",
      EventDef::Encoding{.code = 0x2C, .umask = 0x4, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo0, BL Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_STALL_NO_SBO_CREDIT.SBO1_BL",
      EventDef::Encoding{.code = 0x2C, .umask = 0x8, .msr_values = {0}},
      R"(Stall on No Sbo Credits; For SBo1, BL Ring)",
      R"(Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo, per Ring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_CYCLES_FULL.AD",
      EventDef::Encoding{.code = 0x25, .umask = 0x1, .msr_values = {0}},
      R"(Egress Cycles Full; AD)",
      R"(Counts the number of cycles when the R2PCIe Egress buffer is full.; AD Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_CYCLES_FULL.AK",
      EventDef::Encoding{.code = 0x25, .umask = 0x2, .msr_values = {0}},
      R"(Egress Cycles Full; AK)",
      R"(Counts the number of cycles when the R2PCIe Egress buffer is full.; AK Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_CYCLES_FULL.BL",
      EventDef::Encoding{.code = 0x25, .umask = 0x4, .msr_values = {0}},
      R"(Egress Cycles Full; BL)",
      R"(Counts the number of cycles when the R2PCIe Egress buffer is full.; BL Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_CYCLES_NE.AD",
      EventDef::Encoding{.code = 0x23, .umask = 0x1, .msr_values = {0}},
      R"(Egress Cycles Not Empty; AD)",
      R"(Counts the number of cycles when the R2PCIe Egress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Egress Occupancy Accumulator event in order to calculate average queue occupancy.  Only a single Egress queue can be tracked at any given time.  It is not possible to filter based on direction or polarity.; AD Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_CYCLES_NE.AK",
      EventDef::Encoding{.code = 0x23, .umask = 0x2, .msr_values = {0}},
      R"(Egress Cycles Not Empty; AK)",
      R"(Counts the number of cycles when the R2PCIe Egress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Egress Occupancy Accumulator event in order to calculate average queue occupancy.  Only a single Egress queue can be tracked at any given time.  It is not possible to filter based on direction or polarity.; AK Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_CYCLES_NE.BL",
      EventDef::Encoding{.code = 0x23, .umask = 0x4, .msr_values = {0}},
      R"(Egress Cycles Not Empty; BL)",
      R"(Counts the number of cycles when the R2PCIe Egress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Egress Occupancy Accumulator event in order to calculate average queue occupancy.  Only a single Egress queue can be tracked at any given time.  It is not possible to filter based on direction or polarity.; BL Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_NACK_CW.DN_AD",
      EventDef::Encoding{.code = 0x26, .umask = 0x1, .msr_values = {0}},
      R"(Egress CCW NACK; AD CCW)",
      R"(AD CounterClockwise Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_NACK_CW.DN_BL",
      EventDef::Encoding{.code = 0x26, .umask = 0x2, .msr_values = {0}},
      R"(Egress CCW NACK; BL CCW)",
      R"(BL CounterClockwise Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_NACK_CW.DN_AK",
      EventDef::Encoding{.code = 0x26, .umask = 0x4, .msr_values = {0}},
      R"(Egress CCW NACK; AK CCW)",
      R"(AK CounterClockwise Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_NACK_CW.UP_AD",
      EventDef::Encoding{.code = 0x26, .umask = 0x8, .msr_values = {0}},
      R"(Egress CCW NACK; AK CCW)",
      R"(BL CounterClockwise Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_NACK_CW.UP_BL",
      EventDef::Encoding{.code = 0x26, .umask = 0x10, .msr_values = {0}},
      R"(Egress CCW NACK; BL CCW)",
      R"(AD CounterClockwise Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_r2pcie,
      "UNC_R2_TxR_NACK_CW.UP_AK",
      EventDef::Encoding{.code = 0x26, .umask = 0x20, .msr_values = {0}},
      R"(Egress CCW NACK; BL CW)",
      R"(AD Clockwise Egress Queue)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_EVENT_MSG.DOORBELL_RCVD",
      EventDef::Encoding{.code = 0x42, .umask = 0x8, .msr_values = {0}},
      R"(VLW Received)",
      R"(Virtual Logical Wire (legacy) message were received from Uncore.   Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_FILTER_MATCH.ENABLE",
      EventDef::Encoding{.code = 0x41, .umask = 0x1, .msr_values = {0}},
      R"(Filter Match)",
      R"(Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_FILTER_MATCH.DISABLE",
      EventDef::Encoding{.code = 0x41, .umask = 0x2, .msr_values = {0}},
      R"(Filter Match)",
      R"(Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_FILTER_MATCH.U2C_ENABLE",
      EventDef::Encoding{.code = 0x41, .umask = 0x4, .msr_values = {0}},
      R"(Filter Match)",
      R"(Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_FILTER_MATCH.U2C_DISABLE",
      EventDef::Encoding{.code = 0x41, .umask = 0x8, .msr_values = {0}},
      R"(Filter Match)",
      R"(Filter match per thread (w/ or w/o Filter Enable).  Specify the thread to filter on using NCUPMONCTRLGLCTR.ThreadID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_PHOLD_CYCLES.ASSERT_TO_ACK",
      EventDef::Encoding{.code = 0x45, .umask = 0x1, .msr_values = {0}},
      R"(Cycles PHOLD Assert to Ack; Assert to ACK)",
      R"(PHOLD cycles.  Filter from source CoreID.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_RACU_REQUESTS",
      EventDef::Encoding{.code = 0x46, .umask = 0x0, .msr_values = {0}},
      R"(RACU Request)",
      R"(Number outstanding register requests within message channel tracker)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.MONITOR_T0",
      EventDef::Encoding{.code = 0x43, .umask = 0x1, .msr_values = {0}},
      R"(Monitor Sent to T0; Monitor T0)",
      R"(Events coming from Uncore can be sent to one or all cores; Filter by core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.MONITOR_T1",
      EventDef::Encoding{.code = 0x43, .umask = 0x2, .msr_values = {0}},
      R"(Monitor Sent to T0; Monitor T1)",
      R"(Events coming from Uncore can be sent to one or all cores; Filter by core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.LIVELOCK",
      EventDef::Encoding{.code = 0x43, .umask = 0x4, .msr_values = {0}},
      R"(Monitor Sent to T0; Livelock)",
      R"(Events coming from Uncore can be sent to one or all cores; Filter by core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.LTERROR",
      EventDef::Encoding{.code = 0x43, .umask = 0x8, .msr_values = {0}},
      R"(Monitor Sent to T0; LTError)",
      R"(Events coming from Uncore can be sent to one or all cores; Filter by core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.CMC",
      EventDef::Encoding{.code = 0x43, .umask = 0x10, .msr_values = {0}},
      R"(Monitor Sent to T0; Correctable Machine Check)",
      R"(Events coming from Uncore can be sent to one or all cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.UMC",
      EventDef::Encoding{.code = 0x43, .umask = 0x20, .msr_values = {0}},
      R"(Monitor Sent to T0; Uncorrectable Machine Check)",
      R"(Events coming from Uncore can be sent to one or all cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.TRAP",
      EventDef::Encoding{.code = 0x43, .umask = 0x40, .msr_values = {0}},
      R"(Monitor Sent to T0; Trap)",
      R"(Events coming from Uncore can be sent to one or all cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_U2C_EVENTS.OTHER",
      EventDef::Encoding{.code = 0x43, .umask = 0x80, .msr_values = {0}},
      R"(Monitor Sent to T0; Other)",
      R"(Events coming from Uncore can be sent to one or all cores; PREQ, PSMI, P2U, Thermal, PCUSMI, PMI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace broadwellde_uncore
} // namespace facebook::hbt::perf_event::generated
