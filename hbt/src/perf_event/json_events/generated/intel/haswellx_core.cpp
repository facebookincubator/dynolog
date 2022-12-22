// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace haswellx_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from haswellx_core.json (385 events).

    Supported SKUs:
        - Arch: x86, Model: HSX id: 63
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired from execution.)",
      R"(This event counts the number of instructions retired from execution. For instructions that consist of multiple micro-ops, this event counts the retirement of the last micro-op of the instruction. Counting continues during hardware interrupts, traps, and inside interrupt handlers. INST_RETIRED.ANY is counted by a designated fixed counter, leaving the programmable counters available for other events. Faulting executions of GETSEC/VM entry/VM Exit/MWait will not count as retired instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD140, HSD143)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Core cycles when the thread is not in halt state.)",
      R"(This event counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when the core is not in halt state.)",
      R"(This event counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.STORE_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(loads blocked by overlapping with store buffer that cannot be forwarded)",
      R"(This event counts loads that followed a store to the same address, where the data could not be forwarded inside the pipeline from the store to the load.  The most common reason why store forwarding would be blocked is when a load's address range overlaps with a preceding smaller uncompleted store. The penalty for blocked store forwarding is that the load must wait for the store to write its value to the cache before it can be issued.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.NO_SR",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use)",
      R"(The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.LOADS",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Speculative cache line split load uops dispatched to L1 cache)",
      R"(Speculative cache-line split load uops dispatched to L1D.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.STORES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Speculative cache line split STA uops dispatched to L1 cache)",
      R"(Speculative cache-line split store-address uops dispatched to L1D.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS_PARTIAL.ADDRESS_ALIAS",
      EventDef::Encoding{
          .code = 0x07, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(False dependencies in MOB due to partial compare on address.)",
      R"(Aliasing occurs when a load is issued after a store and their memory addresses are offset by 4K.  This event counts the number of loads that aliased with a preceding store, resulting in an extended address check in the pipeline which can have a performance impact.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Load misses in all DTLB levels that cause page walks)",
      R"(Misses in all TLB levels that cause a page walk of any page size.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes (4K).)",
      R"(Completed page walks due to demand load misses that caused 4K page walks in any TLB levels.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes (2M/4M).)",
      R"(Completed page walks due to demand load misses that caused 2M/4M page walks in any TLB levels.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Load miss in all TLB levels causes a page walk that completes. (1G))",
      R"(Load miss in all TLB levels causes a page walk that completes. (1G))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks)",
      R"(This event counts cycles when the  page miss handler (PMH) is servicing page walks caused by DTLB load misses.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT_4K",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Load misses that miss the  DTLB and hit the STLB (4K))",
      R"(This event counts load operations from a 4K page that miss the first DTLB level but hit the second and do not cause page walks.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT_2M",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Load misses that miss the  DTLB and hit the STLB (2M))",
      R"(This event counts load operations from a 2M page that miss the first DTLB level but hit the second and do not cause page walks.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.PDE_CACHE_MISS",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(DTLB demand load misses with low part of linear-to-physical address translation missed)",
      R"(DTLB demand load misses with low part of linear-to-physical address translation missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x03, .cmask = 1, .msr_values = {0}},
      R"(Core cycles the allocator was stalled due to recovery from earlier clear event for this thread (e.g. misprediction or memory nuke))",
      R"(This event counts the number of cycles spent waiting for a recovery after an event such as a processor nuke, JEClear, assist, hle/rtm abort etc.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Uops that Resource Allocation Table (RAT) issues to Reservation Station (RS))",
      R"(This event counts the number of uops issued by the Front-end of the pipeline to the Back-end. This event is counted at the allocation stage and will count both retired and non-retired uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.FLAGS_MERGE",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of flags-merge uops being allocated. Such uops considered perf sensitive; added by GSR u-arch.)",
      R"(Number of flags-merge uops allocated. Such uops add delay.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.SLOW_LEA",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of slow LEA uops being allocated. A uop is generally considered SlowLea if it has 3 sources (e.g. 2 sources + immediate) regardless if as a result of LEA instruction or not.)",
      R"(Number of slow LEA or similar uops allocated. Such uop has 3 sources (for example, 2 sources + immediate) regardless of whether it is a result of LEA instruction or not.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.SINGLE_MUL",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of Multiply packed/scalar single precision uops allocated)",
      R"(Number of multiply packed/scalar single precision uops allocated.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0x0E,
          .umask = 0x01,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for the thread.)",
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for the thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.CORE_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0x0E,
          .umask = 0x01,
          .any = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads.)",
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.DIVIDER_UOPS",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Any uop executed by the Divider. (This includes all divide uops, sqrt, ...))",
      R"(Any uop executed by the Divider. (This includes all divide uops, sqrt, ...))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.DEMAND_DATA_RD_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read miss L2, no rejects)",
      R"(Demand data read requests that missed L2, no rejects.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.DEMAND_DATA_RD_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xc1, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests that hit L2 cache)",
      R"(Counts the number of demand Data Read requests, initiated by load instructions, that hit L2 cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.L2_PF_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(L2 prefetch requests that miss L2 cache)",
      R"(Counts all L2 HW prefetcher requests that missed L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.L2_PF_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xd0, .cmask = 0, .msr_values = {0}},
      R"(L2 prefetch requests that hit L2 cache)",
      R"(Counts all L2 HW prefetcher requests that hit L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xe1, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests)",
      R"(Counts any demand and L1 HW prefetch data load requests to L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_RFO",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xE2, .cmask = 0, .msr_values = {0}},
      R"(RFO requests to L2 cache)",
      R"(Counts all L2 store RFO requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_CODE_RD",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xE4, .cmask = 0, .msr_values = {0}},
      R"(L2 code requests)",
      R"(Counts all L2 code requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_PF",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xF8, .cmask = 0, .msr_values = {0}},
      R"(Requests from L2 hardware prefetchers)",
      R"(Counts all L2 HW prefetcher requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DEMAND_RQSTS.WB_HIT",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x50, .cmask = 0, .msr_values = {0}},
      R"(Not rejected writebacks that hit L2 cache)",
      R"(Not rejected writebacks that hit L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.MISS",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Core-originated cacheable demand requests missed L3)",
      R"(This event counts each cache miss condition for references to the last level cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x4F, .cmask = 0, .msr_values = {0}},
      R"(Core-originated cacheable demand requests that refer to L3)",
      R"(This event counts requests originating from the core that reference a cache line in the last level cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate))",
      R"(Increments at the frequency of XCLK (100 MHz) when not halted.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.ONE_THREAD_ACTIVE",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Count XClk pulses when this thread is unhalted and the other thread is halted.)",
      R"(Count XClk pulses when this thread is unhalted and the other thread is halted.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.PENDING",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L1D miss outstanding duration in cycles)",
      R"(Increments the number of outstanding L1D misses every cycle. Set Cmask = 1 and Edge =1 to count occurrences.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.REQUEST_FB_FULL",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times a request needed a FB entry but there was no entry available for it. That is the FB unavailability was dominant reason for blocking the request. A request includes cacheable/uncacheable demands that is load, store or SW prefetch. HWP are e.)",
      R"(Number of times a request needed a FB entry but there was no entry available for it. That is the FB unavailability was dominant reason for blocking the request. A request includes cacheable/uncacheable demands that is load, store or SW prefetch. HWP are e.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.PENDING_CYCLES",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles with L1D load Misses outstanding.)",
      R"(Cycles with L1D load Misses outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause page walks)",
      R"(Miss in all TLB levels causes a page walk of any page size (4K/2M/4M/1G).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Store miss in all TLB levels causes a page walk that completes. (4K))",
      R"(Completed page walks due to store misses in one or more TLB levels of 4K page structure.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks (2M/4M))",
      R"(Completed page walks due to store misses in one or more TLB levels of 2M/4M page structure.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks. (1G))",
      R"(Store misses in all DTLB levels that cause completed page walks. (1G))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks)",
      R"(This event counts cycles when the  page miss handler (PMH) is servicing page walks caused by DTLB store misses.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT_4K",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Store misses that miss the  DTLB and hit the STLB (4K))",
      R"(This event counts store operations from a 4K page that miss the first DTLB level but hit the second and do not cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT_2M",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Store misses that miss the  DTLB and hit the STLB (2M))",
      R"(This event counts store operations from a 2M page that miss the first DTLB level but hit the second and do not cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.PDE_CACHE_MISS",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(DTLB store misses with low part of linear-to-physical address translation missed)",
      R"(DTLB store misses with low part of linear-to-physical address translation missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE.SW_PF",
      EventDef::Encoding{
          .code = 0x4c, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Not software-prefetch load dispatches that hit FB allocated for software prefetch)",
      R"(Non-SW-prefetch load dispatches that hit fill buffer allocated for S/W prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE.HW_PF",
      EventDef::Encoding{
          .code = 0x4c, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Not software-prefetch load dispatches that hit FB allocated for hardware prefetch)",
      R"(Non-SW-prefetch load dispatches that hit fill buffer allocated for H/W prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.WALK_CYCLES",
      EventDef::Encoding{
          .code = 0x4f, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycle count for an Extended Page table walk.)",
      R"(Cycle count for an Extended Page table walk.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.REPLACEMENT",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L1D data line replacements)",
      R"(This event counts when new data lines are brought into the L1 Data cache, which cause other lines to be evicted from the cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_CONFLICT",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of times a transactional abort was signaled due to a data conflict on a transactionally accessed address.)",
      R"(Number of times a transactional abort was signaled due to a data conflict on a transactionally accessed address.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_CAPACITY_WRITE",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times a transactional abort was signaled due to a data capacity limitation for transactional writes.)",
      R"(Number of times a transactional abort was signaled due to a data capacity limitation for transactional writes.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_STORE_TO_ELIDED_LOCK",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of times a HLE transactional region aborted due to a non XRELEASE prefixed instruction writing to an elided lock in the elision buffer.)",
      R"(Number of times a HLE transactional region aborted due to a non XRELEASE prefixed instruction writing to an elided lock in the elision buffer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_ELISION_BUFFER_NOT_EMPTY",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE transactional execution aborted due to NoAllocatedElisionBuffer being non-zero.)",
      R"(Number of times an HLE transactional execution aborted due to NoAllocatedElisionBuffer being non-zero.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_ELISION_BUFFER_MISMATCH",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE transactional execution aborted due to XRELEASE lock not satisfying the address and value requirements in the elision buffer.)",
      R"(Number of times an HLE transactional execution aborted due to XRELEASE lock not satisfying the address and value requirements in the elision buffer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_ELISION_BUFFER_UNSUPPORTED_ALIGNMENT",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE transactional execution aborted due to an unsupported read alignment from the elision buffer.)",
      R"(Number of times an HLE transactional execution aborted due to an unsupported read alignment from the elision buffer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.HLE_ELISION_BUFFER_FULL",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of times HLE lock could not be elided due to ElisionBufferAvailable being zero.)",
      R"(Number of times HLE lock could not be elided due to ElisionBufferAvailable being zero.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MOVE_ELIMINATION.INT_ELIMINATED",
      EventDef::Encoding{
          .code = 0x58, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of integer Move Elimination candidate uops that were eliminated.)",
      R"(Number of integer move elimination candidate uops that were eliminated.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MOVE_ELIMINATION.SIMD_ELIMINATED",
      EventDef::Encoding{
          .code = 0x58, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of SIMD Move Elimination candidate uops that were eliminated.)",
      R"(Number of SIMD move elimination candidate uops that were eliminated.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MOVE_ELIMINATION.INT_NOT_ELIMINATED",
      EventDef::Encoding{
          .code = 0x58, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of integer Move Elimination candidate uops that were not eliminated.)",
      R"(Number of integer move elimination candidate uops that were not eliminated.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MOVE_ELIMINATION.SIMD_NOT_ELIMINATED",
      EventDef::Encoding{
          .code = 0x58, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of SIMD Move Elimination candidate uops that were not eliminated.)",
      R"(Number of SIMD move elimination candidate uops that were not eliminated.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPL_CYCLES.RING0",
      EventDef::Encoding{
          .code = 0x5C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Unhalted core cycles when the thread is in ring 0)",
      R"(Unhalted core cycles when the thread is in ring 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPL_CYCLES.RING123",
      EventDef::Encoding{
          .code = 0x5C, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Unhalted core cycles when thread is in rings 1, 2, or 3)",
      R"(Unhalted core cycles when the thread is not in ring 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPL_CYCLES.RING0_TRANS",
      EventDef::Encoding{
          .code = 0x5C,
          .umask = 0x01,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Number of intervals between processor halts while thread is in ring 0.)",
      R"(Number of intervals between processor halts while thread is in ring 0.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_EXEC.MISC1",
      EventDef::Encoding{
          .code = 0x5d, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times a class of instructions that may cause a transactional abort was executed. Since this is the count of execution, it may not always cause a transactional abort.)",
      R"(Counts the number of times a class of instructions that may cause a transactional abort was executed. Since this is the count of execution, it may not always cause a transactional abort.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_EXEC.MISC2",
      EventDef::Encoding{
          .code = 0x5d, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times a class of instructions (e.g., vzeroupper) that may cause a transactional abort was executed inside a transactional region.)",
      R"(Counts the number of times a class of instructions (e.g., vzeroupper) that may cause a transactional abort was executed inside a transactional region.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_EXEC.MISC3",
      EventDef::Encoding{
          .code = 0x5d, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times an instruction execution caused the transactional nest count supported to be exceeded.)",
      R"(Counts the number of times an instruction execution caused the transactional nest count supported to be exceeded.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_EXEC.MISC4",
      EventDef::Encoding{
          .code = 0x5d, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times a XBEGIN instruction was executed inside an HLE transactional region.)",
      R"(Counts the number of times a XBEGIN instruction was executed inside an HLE transactional region.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_EXEC.MISC5",
      EventDef::Encoding{
          .code = 0x5d, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region.)",
      R"(Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RS_EVENTS.EMPTY_CYCLES",
      EventDef::Encoding{
          .code = 0x5E, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Reservation Station (RS) is empty for the thread)",
      R"(This event counts cycles when the Reservation Station ( RS ) is empty for the thread. The RS is a structure that buffers allocated micro-ops from the Front-end. If there are many cycles when the RS is empty, it may represent an underflow of instructions delivered from the Front-end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding Demand Data Read transactions in uncore queue.)",
      R"(Offcore outstanding demand data read transactions in SQ to uncore. Set Cmask=1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSD62, HSD61, HSM63, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle)",
      R"(Offcore outstanding Demand code Read transactions in SQ to uncore. Set Cmask=1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD62, HSD61, HSM63)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding RFO store transactions in SuperQueue (SQ), queue to uncore)",
      R"(Offcore outstanding RFO store transactions in SQ to uncore. Set Cmask=1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD62, HSD61, HSM63)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore)",
      R"(Offcore outstanding cacheable data read transactions in SQ to uncore. Set Cmask=1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD62, HSD61, HSM63)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore.)",
      R"(Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSD62, HSD61, HSM63, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore.)",
      R"(Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD62, HSD61, HSM63)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 1, .msr_values = {0}},
      R"(Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle.)",
      R"(Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD62, HSD61, HSM63)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOCK_CYCLES.SPLIT_LOCK_UC_LOCK_DURATION",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when L1 and L2 are locked due to UC or split lock)",
      R"(Cycles in which the L1D and L2 are locked, due to a UC lock or split lock.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOCK_CYCLES.CACHE_LOCK_DURATION",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cycles when L1D is locked)",
      R"(Cycles in which the L1D is locked.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.EMPTY",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Instruction Decode Queue (IDQ) empty cycles)",
      R"(Counts cycles the IDQ is empty.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path)",
      R"(Increment each cycle # of uops delivered to IDQ from MITE path. Set Cmask = 1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.DSB_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path)",
      R"(Increment each cycle. # of uops delivered to IDQ from DSB path. Set Cmask = 1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_DSB_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy)",
      R"(Increment each cycle # of uops delivered to IDQ when MS_busy by DSB. Set Cmask = 1 to count cycles. Add Edge=1 to count # of delivery.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_MITE_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy)",
      R"(Increment each cycle # of uops delivered to IDQ when MS_busy by MITE. Set Cmask = 1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy)",
      R"(This event counts uops delivered by the Front-end with the assistance of the microcode sequencer.  Microcode assists are used for complex instructions or scenarios that can't be handled by the standard decoder.  Using other instructions, if possible, will usually improve performance.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy)",
      R"(This event counts cycles during which the microcode sequencer assisted the Front-end in delivering uops.  Microcode assists are used for complex instructions or scenarios that can't be handled by the standard decoder.  Using other instructions, if possible, will usually improve performance.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from MITE path.)",
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from MITE path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.DSB_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x08, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from Decode Stream Buffer (DSB) path.)",
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from Decode Stream Buffer (DSB) path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_DSB_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x10, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      R"(Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_DSB_OCCUR",
      EventDef::Encoding{
          .code = 0x79,
          .umask = 0x10,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequencer (MS) is busy.)",
      R"(Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequencer (MS) is busy.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_DSB_CYCLES_4_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x18, .cmask = 4, .msr_values = {0}},
      R"(Cycles Decode Stream Buffer (DSB) is delivering 4 Uops)",
      R"(Counts cycles DSB is delivered four uops. Set Cmask = 4.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_DSB_CYCLES_ANY_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x18, .cmask = 1, .msr_values = {0}},
      R"(Cycles Decode Stream Buffer (DSB) is delivering any Uop)",
      R"(Counts cycles DSB is delivered at least one uops. Set Cmask = 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_MITE_CYCLES_4_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x24, .cmask = 4, .msr_values = {0}},
      R"(Cycles MITE is delivering 4 Uops)",
      R"(Counts cycles MITE is delivered four uops. Set Cmask = 4.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_MITE_CYCLES_ANY_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x24, .cmask = 1, .msr_values = {0}},
      R"(Cycles MITE is delivering any Uop)",
      R"(Counts cycles MITE is delivered at least one uop. Set Cmask = 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_ALL_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x3c, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path)",
      R"(Number of uops delivered to IDQ from any path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.HIT",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches.)",
      R"(Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of Instruction Cache, Streaming Buffer and Victim Cache Misses. Includes Uncacheable accesses.)",
      R"(This event counts Instruction Cache (ICACHE) misses.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.IFETCH_STALL",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles where a code fetch is stalled due to L1 instruction-cache miss.)",
      R"(Cycles where a code fetch is stalled due to L1 instruction-cache miss.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Misses at all ITLB levels that cause page walks)",
      R"(Misses in ITLB that causes a page walk of any page size.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Code miss in all TLB levels causes a page walk that completes. (4K))",
      R"(Completed page walks due to misses in ITLB 4K page entries.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Code miss in all TLB levels causes a page walk that completes. (2M/4M))",
      R"(Completed page walks due to misses in ITLB 2M/4M page entries.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Store miss in all TLB levels causes a page walk that completes. (1G))",
      R"(Store miss in all TLB levels causes a page walk that completes. (1G))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks)",
      R"(This event counts cycles when the  page miss handler (PMH) is servicing page walks caused by ITLB misses.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT_4K",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Core misses that miss the  DTLB and hit the STLB (4K))",
      R"(ITLB misses that hit STLB (4K).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT_2M",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Code misses that miss the  DTLB and hit the STLB (2M))",
      R"(ITLB misses that hit STLB (2M).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.LCP",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Stalls caused by changing prefix length of the instruction.)",
      R"(This event counts cycles where the decoder is stalled on an instruction with a length changing prefix (LCP).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.IQ_FULL",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Stall cycles because IQ is full)",
      R"(Stall cycles due to IQ is full.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.NONTAKEN_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Not taken macro-conditional branches.)",
      R"(Not taken macro-conditional branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.TAKEN_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired macro-conditional branches.)",
      R"(Taken speculative and retired macro-conditional branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.TAKEN_DIRECT_JUMP",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired macro-conditional branch instructions excluding calls and indirects.)",
      R"(Taken speculative and retired macro-conditional branch instructions excluding calls and indirects.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.TAKEN_INDIRECT_JUMP_NON_CALL_RET",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x84, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired indirect branches excluding calls and returns.)",
      R"(Taken speculative and retired indirect branches excluding calls and returns.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.TAKEN_INDIRECT_NEAR_RETURN",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x88, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired indirect branches with return mnemonic.)",
      R"(Taken speculative and retired indirect branches with return mnemonic.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.TAKEN_DIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x90, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired direct near calls.)",
      R"(Taken speculative and retired direct near calls.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.TAKEN_INDIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xA0, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired indirect calls.)",
      R"(Taken speculative and retired indirect calls.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ALL_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xC1, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired macro-conditional branches.)",
      R"(Speculative and retired macro-conditional branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ALL_DIRECT_JMP",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xC2, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired macro-unconditional branches excluding calls and indirects.)",
      R"(Speculative and retired macro-unconditional branches excluding calls and indirects.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ALL_INDIRECT_JUMP_NON_CALL_RET",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xC4, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired indirect branches excluding calls and returns.)",
      R"(Speculative and retired indirect branches excluding calls and returns.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ALL_INDIRECT_NEAR_RETURN",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xC8, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired indirect return branches.)",
      R"(Speculative and retired indirect return branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ALL_DIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xD0, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired direct near calls.)",
      R"(Speculative and retired direct near calls.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xFF, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired  branches)",
      R"(Counts all near executed branches (not necessarily retired).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.NONTAKEN_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Not taken speculative and retired mispredicted macro conditional branches.)",
      R"(Not taken speculative and retired mispredicted macro conditional branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.TAKEN_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired mispredicted macro conditional branches.)",
      R"(Taken speculative and retired mispredicted macro conditional branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.TAKEN_INDIRECT_JUMP_NON_CALL_RET",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x84, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired mispredicted indirect branches excluding calls and returns.)",
      R"(Taken speculative and retired mispredicted indirect branches excluding calls and returns.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.TAKEN_RETURN_NEAR",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x88, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired mispredicted indirect branches with return mnemonic.)",
      R"(Taken speculative and retired mispredicted indirect branches with return mnemonic.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.ALL_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xC1, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired mispredicted macro conditional branches.)",
      R"(Speculative and retired mispredicted macro conditional branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.ALL_INDIRECT_JUMP_NON_CALL_RET",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xC4, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted indirect branches excluding calls and returns.)",
      R"(Mispredicted indirect branches excluding calls and returns.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xFF, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired mispredicted macro conditional branches)",
      R"(Counts all near executed branches (not necessarily retired).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Uops not delivered to Resource Allocation Table (RAT) per thread when backend of the machine is not stalled)",
      R"(This event count the number of undelivered (unallocated) uops from the Front-end to the Resource Allocation Table (RAT) while the Back-end of the processor is not stalled. The Front-end can allocate up to 4 uops per cycle so this event can increment 0-4 times per cycle depending on the number of unallocated uops. This event is counted on a per-core basis.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 4, .msr_values = {0}},
      R"(Cycles per thread when 4 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled)",
      R"(This event counts the number cycles during which the Front-end allocated exactly zero uops to the Resource Allocation Table (RAT) while the Back-end of the processor is not stalled.  This event is counted on a per-core basis.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_1_UOP_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 3, .msr_values = {0}},
      R"(Cycles per thread when 3 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.)",
      R"(Cycles per thread when 3 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_2_UOP_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 2, .msr_values = {0}},
      R"(Cycles with less than 2 uops delivered by the front end.)",
      R"(Cycles with less than 2 uops delivered by the front end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_3_UOP_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles with less than 3 uops delivered by the front end.)",
      R"(Cycles with less than 3 uops delivered by the front end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_FE_WAS_OK",
      EventDef::Encoding{
          .code = 0x9C,
          .umask = 0x01,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Counts cycles FE delivered 4 uops or Resource Allocation Table (RAT) was stalling FE.)",
      R"(Counts cycles FE delivered 4 uops or Resource Allocation Table (RAT) was stalling FE.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_0",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 0)",
      R"(Cycles which a uop is dispatched on port 0 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_1",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 1)",
      R"(Cycles which a uop is dispatched on port 1 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_2",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 2)",
      R"(Cycles which a uop is dispatched on port 2 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_3",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 3)",
      R"(Cycles which a uop is dispatched on port 3 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_4",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 4)",
      R"(Cycles which a uop is dispatched on port 4 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_5",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 5)",
      R"(Cycles which a uop is dispatched on port 5 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_6",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 6)",
      R"(Cycles which a uop is dispatched on port 6 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_7",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 7)",
      R"(Cycles which a uop is dispatched on port 7 in this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.ANY",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Resource-related stall cycles)",
      R"(Cycles allocation is stalled due to resource related reason.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD135)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.RS",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles stalled due to no eligible RS entry available.)",
      R"(Cycles stalled due to no eligible RS entry available.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.SB",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles stalled due to no store buffers available. (not including draining form sync).)",
      R"(This event counts cycles during which no instructions were allocated because no Store Buffers (SB) were available.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.ROB",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles stalled due to re-order buffer full.)",
      R"(Cycles stalled due to re-order buffer full.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L2_PENDING",
      EventDef::Encoding{
          .code = 0xa3, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles with pending L2 cache miss loads.)",
      R"(Cycles with pending L2 miss loads. Set Cmask=2 to count cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM63, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L1D_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x08, .cmask = 8, .msr_values = {0}},
      R"(Cycles with pending L1 cache miss loads.)",
      R"(Cycles with pending L1 data cache miss loads. Set Cmask=8 to count cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_LDM_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x02, .cmask = 2, .msr_values = {0}},
      R"(Cycles with pending memory loads.)",
      R"(Cycles with pending memory loads. Set Cmask=2 to count cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_NO_EXECUTE",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x04, .cmask = 4, .msr_values = {0}},
      R"(This event increments by 1 for every cycle where there was no execute for this thread.)",
      R"(This event counts cycles during which no instructions were executed in the execution stage of the pipeline.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_PENDING",
      EventDef::Encoding{
          .code = 0xa3, .umask = 0x05, .cmask = 5, .msr_values = {0}},
      R"(Execution stalls due to L2 cache misses.)",
      R"(Number of loads missed L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSM63, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_LDM_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x06, .cmask = 6, .msr_values = {0}},
      R"(Execution stalls due to memory subsystem.)",
      R"(This event counts cycles during which no instructions were executed in the execution stage of the pipeline and there were memory instructions pending (waiting for data).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L1D_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x0C, .cmask = 12, .msr_values = {0}},
      R"(Execution stalls due to L1 data cache misses)",
      R"(Execution stalls due to L1 data cache miss loads. Set Cmask=0CH.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.UOPS",
      EventDef::Encoding{
          .code = 0xa8, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of Uops delivered by the LSD.)",
      R"(Number of uops delivered by the LSD.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB2MITE_SWITCHES.PENALTY_CYCLES",
      EventDef::Encoding{
          .code = 0xAB, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles.)",
      R"(Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB.ITLB_FLUSH",
      EventDef::Encoding{
          .code = 0xae, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Flushing of the Instruction TLB (ITLB) pages, includes 4k/2M/4M pages.)",
      R"(Counts the number of ITLB flushes, includes 4k/2M/4M pages.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xb0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests sent to uncore)",
      R"(Demand data read requests sent to uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cacheable and noncacheable code read requests)",
      R"(Demand code read requests sent to uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Demand RFO requests including regular RFOs, locks, ItoM)",
      R"(Demand RFO read requests sent to uncore, including regular RFOs, locks, ItoM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.ALL_DATA_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Demand and prefetch data reads)",
      R"(Data read requests sent to uncore (demand and prefetch).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of uops executed on the core.)",
      R"(Counts total number of uops to be executed per-core each cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x01,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Counts number of cycles no uops were dispatched to be executed on this thread.)",
      R"(Counts number of cycles no uops were dispatched to be executed on this thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD144, HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_BUFFER.SQ_FULL",
      EventDef::Encoding{
          .code = 0xb2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore requests buffer cannot take more entries for this thread core.)",
      R"(Offcore requests buffer cannot take more entries for this thread core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_L1",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x11, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in the L1+FB)",
      R"(Number of DTLB page walker loads that hit in the L1+FB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.ITLB_L1",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Number of ITLB page walker hits in the L1+FB)",
      R"(Number of ITLB page walker loads that hit in the L1+FB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_DTLB_L1",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in the L1 and FB.)",
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in the L1 and FB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_ITLB_L1",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in the L1 and FB.)",
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in the L1 and FB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_L2",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x12, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in the L2)",
      R"(Number of DTLB page walker loads that hit in the L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.ITLB_L2",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x22, .cmask = 0, .msr_values = {0}},
      R"(Number of ITLB page walker hits in the L2)",
      R"(Number of ITLB page walker loads that hit in the L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_DTLB_L2",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x42, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in the L2.)",
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in the L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_ITLB_L2",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in the L2.)",
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in the L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_L3",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x14, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in the L3 + XSNP)",
      R"(Number of DTLB page walker loads that hit in the L3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD25)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.ITLB_L3",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x24, .cmask = 0, .msr_values = {0}},
      R"(Number of ITLB page walker hits in the L3 + XSNP)",
      R"(Number of ITLB page walker loads that hit in the L3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD25)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_DTLB_L3",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x44, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in the L3.)",
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in the L3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_ITLB_L3",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x84, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in the L2.)",
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in the L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_MEMORY",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x18, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in Memory)",
      R"(Number of DTLB page walker loads from memory.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD25)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.ITLB_MEMORY",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x28, .cmask = 0, .msr_values = {0}},
      R"(Number of ITLB page walker hits in Memory)",
      R"(Number of ITLB page walker loads from memory.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD25)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_DTLB_MEMORY",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x48, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in memory.)",
      R"(Counts the number of Extended Page Table walks from the DTLB that hit in memory.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.EPT_ITLB_MEMORY",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x88, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in memory.)",
      R"(Counts the number of Extended Page Table walks from the ITLB that hit in memory.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TLB_FLUSH.DTLB_THREAD",
      EventDef::Encoding{
          .code = 0xBD, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(DTLB flush attempts of the thread-specific entries)",
      R"(DTLB flush attempts of the thread-specific entries.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TLB_FLUSH.STLB_ANY",
      EventDef::Encoding{
          .code = 0xBD, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(STLB flush attempts)",
      R"(Count number of STLB flush attempts.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Number of instructions retired. General Counter   - architectural event)",
      R"(Number of instructions at retirement.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD11, HSD140)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.X87",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(FP operations retired. X87 FP operations that have no exceptions: Counts also flows that have several X87 or flows that use X87 uops in the exception handling.)",
      R"(This is a non-precise version (that is, does not use PEBS) of the event that counts FP operations retired. For X87 FP operations that have no exceptions counting also includes flows that have several X87, or flows that use X87 uops in the exception handling.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.PREC_DIST",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Precise instruction retired event with HW to reduce effect of PEBS shadow in IP distribution)",
      R"(Precise instruction retired event with HW to reduce effect of PEBS shadow in IP distribution.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(HSD140)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.AVX_TO_SSE",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of transitions from AVX-256 to legacy SSE when penalty applicable.)",
      R"(Number of transitions from AVX-256 to legacy SSE when penalty applicable.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD56, HSM57)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.SSE_TO_AVX",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of transitions from SSE to AVX-256 when penalty applicable.)",
      R"(Number of transitions from SSE to AVX-256 when penalty applicable.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD56, HSM57)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.ANY_WB_ASSIST",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of times any microcode assist is invoked by HW upon uop writeback.)",
      R"(Number of microcode assists invoked by HW upon uop writeback.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Actually retired uops.)",
      R"(Counts the number of micro-ops retired. Use Cmask=1 and invert to count active cycles or stalled cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.RETIRE_SLOTS",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retirement slots used.)",
      R"(This event counts the number of retirement slots used each cycle.  There are potentially 4 slots that can be used each cycle - meaning, 4 uops or 4 instructions could retire each cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x01,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles without actually retired uops.)",
      R"(Cycles without actually retired uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.TOTAL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x01,
          .inv = true,
          .cmask = 16,
          .msr_values = {0}},
      R"(Cycles with less than 10 actually retired uops.)",
      R"(Cycles with less than 10 actually retired uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.CORE_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x01,
          .any = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles without actually retired uops.)",
      R"(Cycles without actually retired uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.CYCLES",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles there was a Nuke. Account for both thread-specific and All Thread Nukes.)",
      R"(Cycles there was a Nuke. Account for both thread-specific and All Thread Nukes.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of machine clears due to memory order conflicts.)",
      R"(This event counts the number of memory ordering machine clears detected. Memory ordering machine clears can result from memory address aliasing or snoops from another hardware thread or core to data inflight in the pipeline.  Machine clears can have a significant performance impact if they are happening frequently.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SMC",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Self-modifying code (SMC) detected.)",
      R"(This event is incremented when self-modifying code (SMC) is detected, which causes a machine clear.  Machine clears can have a significant performance impact if they are happening frequently.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MASKMOV",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(This event counts the number of executed Intel AVX masked load operations that refer to an illegal address range with the mask bits set to 0.)",
      R"(This event counts the number of executed Intel AVX masked load operations that refer to an illegal address range with the mask bits set to 0.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Conditional branch instructions retired.)",
      R"(Counts the number of conditional branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect near call instructions retired.)",
      R"(Direct and indirect near call instructions retired.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(All (macro) branch instructions retired.)",
      R"(Branch instructions at retirement.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_RETURN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Return instructions retired.)",
      R"(Counts the number of near return instructions retired.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NOT_TAKEN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Not taken branch instructions retired.)",
      R"(Counts the number of not taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Taken branch instructions retired.)",
      R"(Number of near taken branches retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Far branch instructions retired.)",
      R"(Number of far branches retired.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(All (macro) branch instructions retired.)",
      R"(All (macro) branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL_R3",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect macro near call instructions retired (captured in ring 3).)",
      R"(Direct and indirect macro near call instructions retired (captured in ring 3).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted conditional branch instructions retired.)",
      R"(Mispredicted conditional branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(All mispredicted macro branch instructions retired.)",
      R"(Mispredicted branch instructions at retirement.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted macro branch instructions retired.)",
      R"(This event counts all mispredicted branch instructions retired. This is a precise event.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.START",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution started.)",
      R"(Number of times an HLE execution started.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.COMMIT",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution successfully committed.)",
      R"(Number of times an HLE execution successfully committed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to any reasons (multiple categories may count as one).)",
      R"(Number of times an HLE execution aborted due to any reasons (multiple categories may count as one).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MISC1",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      R"(Number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MISC2",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to uncommon conditions.)",
      R"(Number of times an HLE execution aborted due to uncommon conditions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MISC3",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to HLE-unfriendly instructions.)",
      R"(Number of times an HLE execution aborted due to HLE-unfriendly instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MISC4",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to incompatible memory type.)",
      R"(Number of times an HLE execution aborted due to incompatible memory type.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD65)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MISC5",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to none of the previous 4 categories (e.g. interrupts))",
      R"(Number of times an HLE execution aborted due to none of the previous 4 categories (e.g. interrupts).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.START",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution started.)",
      R"(Number of times an RTM execution started.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.COMMIT",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution successfully committed.)",
      R"(Number of times an RTM execution successfully committed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to any reasons (multiple categories may count as one).)",
      R"(Number of times an RTM execution aborted due to any reasons (multiple categories may count as one).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MISC1",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts))",
      R"(Number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MISC2",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      R"(Number of times an RTM execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MISC3",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to HLE-unfriendly instructions.)",
      R"(Number of times an RTM execution aborted due to HLE-unfriendly instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MISC4",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to incompatible memory type.)",
      R"(Number of times an RTM execution aborted due to incompatible memory type.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD65)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MISC5",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt))",
      R"(Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.X87_OUTPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of X87 assists due to output value.)",
      R"(Number of X87 FP assists due to output values.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.X87_INPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of X87 assists due to input value.)",
      R"(Number of X87 FP assists due to input values.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.SIMD_OUTPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of SIMD FP assists due to Output values)",
      R"(Number of SIMD FP assists due to output values.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.SIMD_INPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of SIMD FP assists due to input values)",
      R"(Number of SIMD FP assists due to input values.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.ANY",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x1E, .cmask = 1, .msr_values = {0}},
      R"(Cycles with any input/output SSE or FP assist)",
      R"(Cycles with any input/output SSE* or FP assists.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ROB_MISC_EVENTS.LBR_INSERTS",
      EventDef::Encoding{
          .code = 0xCC, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Count cases of saving new LBR)",
      R"(Count cases of saving new LBR records by hardware.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_4",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x4}},
      R"(Randomly selected loads with latency value being above 4.)",
      R"(Randomly selected loads with latency value being above 4.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_8",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x8}},
      R"(Randomly selected loads with latency value being above 8.)",
      R"(Randomly selected loads with latency value being above 8.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_16",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x10}},
      R"(Randomly selected loads with latency value being above 16.)",
      R"(Randomly selected loads with latency value being above 16.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_32",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x20}},
      R"(Randomly selected loads with latency value being above 32.)",
      R"(Randomly selected loads with latency value being above 32.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_64",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x40}},
      R"(Randomly selected loads with latency value being above 64.)",
      R"(Randomly selected loads with latency value being above 64.)",
      2003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_128",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x80}},
      R"(Randomly selected loads with latency value being above 128.)",
      R"(Randomly selected loads with latency value being above 128.)",
      1009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_256",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x100}},
      R"(Randomly selected loads with latency value being above 256.)",
      R"(Randomly selected loads with latency value being above 256.)",
      503,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_512",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x200}},
      R"(Randomly selected loads with latency value being above 512.)",
      R"(Randomly selected loads with latency value being above 512.)",
      101,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(HSD76, HSD25, HSM26)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x11, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that miss the STLB.)",
      R"(Retired load uops that miss the STLB.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x12, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that miss the STLB.)",
      R"(Retired store uops that miss the STLB.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with locked access.)",
      R"(Retired load uops with locked access.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD76, HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that split across a cacheline boundary.)",
      R"(Retired load uops that split across a cacheline boundary.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x42, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that split across a cacheline boundary.)",
      R"(Retired store uops that split across a cacheline boundary.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops.)",
      R"(Counts all retired load uops. This event accounts for SW prefetch uops of PREFETCHNTA or PREFETCHT0/1/2 or PREFETCHW.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops.)",
      R"(Counts all retired store uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L1 cache hits as data sources.)",
      R"(Retired load uops with L1 cache hits as data sources.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L2 cache hits as data sources.)",
      R"(Retired load uops with L2 cache hits as data sources.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD76, HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L3_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were data hits in L3 without snoops required.)",
      R"(Retired load uops with L3 cache hits as data sources.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD74, HSD29, HSD25, HSM26, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops misses in L1 cache as data sources.)",
      R"(Retired load uops missed L1 cache as data sources.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Miss in mid-level (L2) cache. Excludes Unknown data-source.)",
      R"(Retired load uops missed L2. Unknown data source excluded.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L3_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Miss in last-level (L3) cache. Excludes Unknown data-source.)",
      R"(Retired load uops missed L3. Excludes unknown data source .)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD74, HSD29, HSD25, HSM26, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.HIT_LFB",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.)",
      R"(Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_MISS",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.)",
      R"(Retired load uops which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSD25, HSM26, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_HIT",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were L3 and cross-core snoop hits in on-pkg core cache.)",
      R"(Retired load uops which data sources were L3 and cross-core snoop hits in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSD25, HSM26, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_HITM",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were HitM responses from shared L3.)",
      R"(Retired load uops which data sources were HitM responses from shared L3.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSD25, HSM26, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_NONE",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were hits in L3 without snoops required.)",
      R"(Retired load uops which data sources were hits in L3 without snoops required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD74, HSD29, HSD25, HSM26, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Data from local DRAM either Snoop not needed or Snoop Miss (RspI))",
      R"(This event counts retired load uops where the data came from local DRAM. This does not include hardware prefetches.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD74, HSD29, HSD25, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uop whose Data Source was: remote DRAM either Snoop not needed or Snoop Miss (RspI))",
      R"(Retired load uop whose Data Source was: remote DRAM either Snoop not needed or Snoop Miss (RspI))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSD29, HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Retired load uop whose Data Source was: Remote cache HITM)",
      R"(Retired load uop whose Data Source was: Remote cache HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.REMOTE_FWD",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Retired load uop whose Data Source was: forwarded from remote cache)",
      R"(Retired load uop whose Data Source was: forwarded from remote cache)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(HSM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_P",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Thread cycles when thread is not in halt state)",
      R"(Counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests that access L2 cache)",
      R"(Demand data read requests that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.RFO",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that access L2 cache)",
      R"(RFO requests that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.CODE_RD",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(L2 cache accesses when fetching instructions)",
      R"(L2 cache accesses when fetching instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.ALL_PF",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(L2 or L3 HW prefetches that access L2 cache)",
      R"(Any MLC or L3 HW prefetch accessing L2, including rejects.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L1D_WB",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L1D writebacks that access L2 cache)",
      R"(L1D writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L2_FILL",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 fill requests that access L2 cache)",
      R"(L2 fill requests that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L2_WB",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(L2 writebacks that access L2 cache)",
      R"(L2 writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.ALL_REQUESTS",
      EventDef::Encoding{
          .code = 0xf0, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Transactions accessing L2 pipe)",
      R"(Transactions accessing L2 pipe.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.I",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines in I state filling L2)",
      R"(L2 cache lines in I state filling L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.S",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines in S state filling L2)",
      R"(L2 cache lines in S state filling L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.E",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines in E state filling L2)",
      R"(L2 cache lines in E state filling L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.ALL",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x07, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines filling L2)",
      R"(This event counts the number of L2 cache lines brought into the L2 cache.  Lines are filled into the L2 cache when there was an L2 miss.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DEMAND_CLEAN",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x05, .cmask = 0, .msr_values = {0}},
      R"(Clean L2 cache lines evicted by demand)",
      R"(Clean L2 cache lines evicted by demand.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DEMAND_DIRTY",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x06, .cmask = 0, .msr_values = {0}},
      R"(Dirty L2 cache lines evicted by demand)",
      R"(Dirty L2 cache lines evicted by demand.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SQ_MISC.SPLIT_LOCK",
      EventDef::Encoding{
          .code = 0xf4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Split locks in SQ)",
      R"(Split locks in SQ)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.TAKEN_INDIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xA0, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired mispredicted indirect calls.)",
      R"(Taken speculative and retired mispredicted indirect calls.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_0_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x01,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are executed in port 0.)",
      R"(Cycles per core when uops are executed in port 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_1_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x02,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are executed in port 1.)",
      R"(Cycles per core when uops are executed in port 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_2_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x04,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are dispatched to port 2.)",
      R"(Cycles per core when uops are dispatched to port 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_3_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x08,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are dispatched to port 3.)",
      R"(Cycles per core when uops are dispatched to port 3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_4_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x10,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are executed in port 4.)",
      R"(Cycles per core when uops are executed in port 4.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_5_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x20,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are executed in port 5.)",
      R"(Cycles per core when uops are executed in port 5.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_6_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x40,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are executed in port 6.)",
      R"(Cycles per core when uops are executed in port 6.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_7_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x80,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are dispatched to port 7.)",
      R"(Cycles per core when uops are dispatched to port 7.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(number of near branch instructions retired that were mispredicted and taken.)",
      R"(Number of near branch instructions retired that were taken but mispredicted.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes of any page size.)",
      R"(Completed page walks in any TLB of any page size due to demand load misses.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x60, .cmask = 0, .msr_values = {0}},
      R"(Load operations that miss the first DTLB level but hit the second and do not cause page walks)",
      R"(Number of cache load STLB hits. No page walk.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xc2, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that hit L2 cache)",
      R"(Counts the number of store RFO requests that hit the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x22, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that miss L2 cache)",
      R"(Counts the number of store RFO requests that miss the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.CODE_RD_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xc4, .cmask = 0, .msr_values = {0}},
      R"(L2 cache hits when fetching instructions, code reads.)",
      R"(Number of instruction fetches that hit the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.CODE_RD_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x24, .cmask = 0, .msr_values = {0}},
      R"(L2 cache misses when fetching instructions)",
      R"(Number of instruction fetches that missed the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_DEMAND_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x27, .cmask = 0, .msr_values = {0}},
      R"(Demand requests that miss L2 cache)",
      R"(Demand requests that miss L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_DEMAND_REFERENCES",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xe7, .cmask = 0, .msr_values = {0}},
      R"(Demand requests to L2 cache)",
      R"(Demand requests to L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x3f, .cmask = 0, .msr_values = {0}},
      R"(All requests that miss L2 cache)",
      R"(All requests that missed L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.REFERENCES",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xff, .cmask = 0, .msr_values = {0}},
      R"(All L2 requests)",
      R"(All requests to L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks)",
      R"(Completed page walks due to store miss in any TLB levels of any page size (4K/2M/4M/1G).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x60, .cmask = 0, .msr_values = {0}},
      R"(Store operations that miss the first TLB level but hit the second and do not cause page walks)",
      R"(Store operations that miss the first TLB level but hit the second and do not cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Misses in all ITLB levels that cause completed page walks)",
      R"(Completed page walks in ITLB of any page size.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x60, .cmask = 0, .msr_values = {0}},
      R"(Operations that miss the first ITLB level but hit the second and do not cause any page walks)",
      R"(ITLB misses that hit STLB. No page walk.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_1_UOP_EXEC",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles where at least 1 uop was executed per-thread)",
      R"(This events counts the cycles where at least one uop was executed. It is counted per thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD144, HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_2_UOPS_EXEC",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 2, .msr_values = {0}},
      R"(Cycles where at least 2 uops were executed per-thread)",
      R"(This events counts the cycles where at least two uop were executed. It is counted per thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD144, HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_3_UOPS_EXEC",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 3, .msr_values = {0}},
      R"(Cycles where at least 3 uops were executed per-thread)",
      R"(This events counts the cycles where at least three uop were executed. It is counted per thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD144, HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_4_UOPS_EXEC",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 4, .msr_values = {0}},
      R"(Cycles where at least 4 uops were executed per-thread.)",
      R"(Cycles where at least 4 uops were executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD144, HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ANY",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x1f, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      R"(Number of front end re-steers due to BPU misprediction.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.COUNT",
      EventDef::Encoding{
          .code = 0xC3,
          .umask = 0x01,
          .edge = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Number of machine clears (nukes) of any type.)",
      R"(Number of machine clears (nukes) of any type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.CYCLES_ACTIVE",
      EventDef::Encoding{
          .code = 0xA8, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles Uops delivered by the LSD, but didn't come from the decoder.)",
      R"(Cycles Uops delivered by the LSD, but didn't come from the decoder.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.CYCLES_4_UOPS",
      EventDef::Encoding{
          .code = 0xA8, .umask = 0x01, .cmask = 4, .msr_values = {0}},
      R"(Cycles 4 Uops delivered by the LSD, but didn't come from the decoder.)",
      R"(Cycles 4 Uops delivered by the LSD, but didn't come from the decoder.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RS_EVENTS.EMPTY_END",
      EventDef::Encoding{
          .code = 0x5E,
          .umask = 0x01,
          .edge = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Counts end of periods where the Reservation Station (RS) was empty. Could be useful to precisely locate Frontend Latency Bound issues.)",
      R"(Counts end of periods where the Reservation Station (RS) was empty. Could be useful to precisely locate Frontend Latency Bound issues.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_SWITCHES",
      EventDef::Encoding{
          .code = 0x79,
          .umask = 0x30,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_0",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 0.)",
      R"(Cycles per thread when uops are executed in port 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_1",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 1.)",
      R"(Cycles per thread when uops are executed in port 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_2",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 2.)",
      R"(Cycles per thread when uops are executed in port 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_3",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 3.)",
      R"(Cycles per thread when uops are executed in port 3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_4",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 4.)",
      R"(Cycles per thread when uops are executed in port 4.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_5",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 5.)",
      R"(Cycles per thread when uops are executed in port 5.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_6",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 6.)",
      R"(Cycles per thread when uops are executed in port 6.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_7",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 7.)",
      R"(Cycles per thread when uops are executed in port 7.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_ANY",
      EventDef::Encoding{
          .code = 0x00,
          .umask = 0x02,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Core cycles when at least one thread on the physical core is not in halt state.)",
      R"(Core cycles when at least one thread on the physical core is not in halt state.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_P_ANY",
      EventDef::Encoding{
          .code = 0x3C,
          .umask = 0x00,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Core cycles when at least one thread on the physical core is not in halt state.)",
      R"(Core cycles when at least one thread on the physical core is not in halt state.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.REF_XCLK_ANY",
      EventDef::Encoding{
          .code = 0x3C,
          .umask = 0x01,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate))",
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_CYCLES_ANY",
      EventDef::Encoding{
          .code = 0x0D,
          .umask = 0x03,
          .any = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke))",
      R"(Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_1",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_2",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 2, .msr_values = {0x00}},
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_3",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 3, .msr_values = {0x00}},
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_4",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 4, .msr_values = {0x00}},
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_NONE",
      EventDef::Encoding{
          .code = 0xb1,
          .umask = 0x02,
          .inv = true,
          .cmask = 0,
          .msr_values = {0x00}},
      R"(Cycles with no micro-ops executed from any thread on physical core.)",
      R"(Cycles with no micro-ops executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD30, HSM31)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD_GE_6",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 6, .msr_values = {0x00}},
      R"(Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.)",
      R"(Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(HSD78, HSD62, HSD61, HSM63, HSM80)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.PENDING_CYCLES_ANY",
      EventDef::Encoding{
          .code = 0x48,
          .umask = 0x01,
          .any = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Cycles with L1D load Misses outstanding from any thread on physical core.)",
      R"(Cycles with L1D load Misses outstanding from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.FB_FULL",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x02, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles a demand request was blocked due to Fill Buffers inavailability.)",
      R"(Cycles a demand request was blocked due to Fill Buffers inavailability.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "AVX_INSTS.ALL",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x07, .cmask = 0, .msr_values = {0}},
      R"(Approximate counts of AVX & AVX2 256-bit instructions, including non-arithmetic instructions, loads, and stores.  May count non-AVX instructions that employ 256-bit operations, including (but not necessarily limited to) rep string instructions that use 256-bit loads and stores for optimized performance, XSAVE* and XRSTOR*, and operations that transition the x87 FPU data registers between x87 and MMX.)",
      R"(Note that a whole rep string only counts AVX_INST.ALL once.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.IFDATA_STALL",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles where a code fetch is stalled due to L1 instruction-cache miss.)",
      R"(Cycles where a code fetch is stalled due to L1 instruction-cache miss.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate))",
      R"(Reference cycles when the thread is unhalted. (counts at 100 MHz rate))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_XCLK_ANY",
      EventDef::Encoding{
          .code = 0x3C,
          .umask = 0x01,
          .any = true,
          .cmask = 0,
          .msr_values = {0x00}},
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate))",
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.ONE_THREAD_ACTIVE",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Count XClk pulses when this thread is unhalted and the other thread is halted.)",
      R"(Count XClk pulses when this thread is unhalted and the other thread is halted.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0001}},
      R"(Counts demand data reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts demand data reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0001}},
      R"(Counts demand data reads hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts demand data reads hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00001}},
      R"(Counts demand data reads miss in the L3)",
      R"(Counts demand data reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x600400001}},
      R"(Counts demand data reads miss the L3 and the data is returned from local dram)",
      R"(Counts demand data reads miss the L3 and the data is returned from local dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0002}},
      R"(Counts all demand data writes (RFOs) hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts all demand data writes (RFOs) hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0002}},
      R"(Counts all demand data writes (RFOs) hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts all demand data writes (RFOs) hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00002}},
      R"(Counts all demand data writes (RFOs) miss in the L3)",
      R"(Counts all demand data writes (RFOs) miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x600400002}},
      R"(Counts all demand data writes (RFOs) miss the L3 and the data is returned from local dram)",
      R"(Counts all demand data writes (RFOs) miss the L3 and the data is returned from local dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00002}},
      R"(Counts all demand data writes (RFOs) miss the L3 and the modified data is transferred from remote cache)",
      R"(Counts all demand data writes (RFOs) miss the L3 and the modified data is transferred from remote cache)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0004}},
      R"(Counts all demand code reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts all demand code reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0004}},
      R"(Counts all demand code reads hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts all demand code reads hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00004}},
      R"(Counts all demand code reads miss in the L3)",
      R"(Counts all demand code reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x600400004}},
      R"(Counts all demand code reads miss the L3 and the data is returned from local dram)",
      R"(Counts all demand code reads miss the L3 and the data is returned from local dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0010}},
      R"(Counts prefetch (that bring data to L2) data reads hit in the L3)",
      R"(Counts prefetch (that bring data to L2) data reads hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00010}},
      R"(Counts prefetch (that bring data to L2) data reads miss in the L3)",
      R"(Counts prefetch (that bring data to L2) data reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs hit in the L3)",
      R"(Counts all prefetch (that bring data to L2) RFOs hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00020}},
      R"(Counts all prefetch (that bring data to L2) RFOs miss in the L3)",
      R"(Counts all prefetch (that bring data to L2) RFOs miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0040}},
      R"(Counts all prefetch (that bring data to LLC only) code reads hit in the L3)",
      R"(Counts all prefetch (that bring data to LLC only) code reads hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00040}},
      R"(Counts all prefetch (that bring data to LLC only) code reads miss in the L3)",
      R"(Counts all prefetch (that bring data to LLC only) code reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads hit in the L3)",
      R"(Counts all prefetch (that bring data to LLC only) data reads hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads miss in the L3)",
      R"(Counts all prefetch (that bring data to LLC only) data reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs hit in the L3)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs miss in the L3)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0200}},
      R"(Counts prefetch (that bring data to LLC only) code reads hit in the L3)",
      R"(Counts prefetch (that bring data to LLC only) code reads hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00200}},
      R"(Counts prefetch (that bring data to LLC only) code reads miss in the L3)",
      R"(Counts prefetch (that bring data to LLC only) code reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0091}},
      R"(Counts all demand & prefetch data reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts all demand & prefetch data reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0091}},
      R"(Counts all demand & prefetch data reads hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts all demand & prefetch data reads hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00091}},
      R"(Counts all demand & prefetch data reads miss in the L3)",
      R"(Counts all demand & prefetch data reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x600400091}},
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from local dram)",
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from local dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63F800091}},
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from remote dram)",
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from remote dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00091}},
      R"(Counts all demand & prefetch data reads miss the L3 and the modified data is transferred from remote cache)",
      R"(Counts all demand & prefetch data reads miss the L3 and the modified data is transferred from remote cache)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00091}},
      R"(Counts all demand & prefetch data reads miss the L3 and clean or shared data is transferred from remote cache)",
      R"(Counts all demand & prefetch data reads miss the L3 and clean or shared data is transferred from remote cache)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0122}},
      R"(Counts all demand & prefetch RFOs hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts all demand & prefetch RFOs hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0122}},
      R"(Counts all demand & prefetch RFOs hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts all demand & prefetch RFOs hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00122}},
      R"(Counts all demand & prefetch RFOs miss in the L3)",
      R"(Counts all demand & prefetch RFOs miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x600400122}},
      R"(Counts all demand & prefetch RFOs miss the L3 and the data is returned from local dram)",
      R"(Counts all demand & prefetch RFOs miss the L3 and the data is returned from local dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0244}},
      R"(Counts all demand & prefetch code reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts all demand & prefetch code reads hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00244}},
      R"(Counts all demand & prefetch code reads miss in the L3)",
      R"(Counts all demand & prefetch code reads miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x600400244}},
      R"(Counts all demand & prefetch code reads miss the L3 and the data is returned from local dram)",
      R"(Counts all demand & prefetch code reads miss the L3 and the data is returned from local dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C07F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts all data/code/rfo reads (demand & prefetch) hit in the L3 and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C07F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts all data/code/rfo reads (demand & prefetch) hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss in the L3)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x6004007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from local dram)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from local dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63F8007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from remote dram)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from remote dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the modified data is transferred from remote cache)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the modified data is transferred from remote cache)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and clean or shared data is transferred from remote cache)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and clean or shared data is transferred from remote cache)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_REQUESTS.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C8FFF}},
      R"(Counts all requests hit in the L3)",
      R"(Counts all requests hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_REQUESTS.LLC_MISS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC08FFF}},
      R"(Counts all requests miss in the L3)",
      R"(Counts all requests miss in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace haswellx_core
} // namespace facebook::hbt::perf_event::generated
