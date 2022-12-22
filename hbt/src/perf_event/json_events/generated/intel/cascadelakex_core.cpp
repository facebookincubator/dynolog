// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace cascadelakex_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from cascadelakex_core.json (2331 events).

    Supported SKUs:
        - Arch: x86, Model: CLX id: 85 Steps: ['5', '6', '7', '8', '9', 'A',
    'B', 'C', 'D', 'E', 'F']
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired from execution.)",
      R"(Counts the number of instructions retired from execution. For instructions that consist of multiple micro-ops, Counts the retirement of the last micro-op of the instruction. Counting continues during hardware interrupts, traps, and inside interrupt handlers. Notes: INST_RETIRED.ANY is counted by a designated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. INST_RETIRED.ANY_P is counted by a programmable counter and it is an architectural performance event. Counting: Faulting executions of GETSEC/VM entry/VM Exit/MWait will not count as retired instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Core cycles when the thread is not in halt state)",
      R"(Counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events.)",
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
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when the core is not in halt state.)",
      R"(Counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. This event has a constant ratio with the CPU_CLK_UNHALTED.REF_XCLK event. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. Note: On all current platforms this event stops counting during 'throttling (TM)' states duty off periods the processor is 'halted'.  The counter update is done at a lower clock rate then the core clock the overflow status bit for this counter may appear 'sticky'.  After the counter has overflowed and software clears the overflow status bit and resets the counter to less than MAX. The reset value to the counter is not clocked immediately so the overflow status bit will flip 'high (1)' and generate another PMI (if enabled) after which the reset value gets clocked into the counter. Therefore, software will get the interrupt, read the overflow status bit '1 for bit 34 while the counter value is less than MAX. Software should ignore this case.)",
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
      R"(Loads blocked due to overlapping with a preceding store that cannot be forwarded.)",
      R"(Counts the number of times where store forwarding was prevented for a load operation. The most common case is a load blocked due to the address of memory access (partially) overlapping with a preceding uncompleted store. Note: See the table of not supported store forwards in the Optimization Guide.)",
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
      "LD_BLOCKS_PARTIAL.ADDRESS_ALIAS",
      EventDef::Encoding{
          .code = 0x07, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(False dependencies in MOB due to partial compare on address.)",
      R"(Counts false dependencies in MOB when the partial comparison upon loose net check and dependency was resolved by the Enhanced Loose net mechanism. This may not result in high performance penalties. Loose net checks can fail when loads and stores are 4k aliased.)",
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
      R"(Counts demand data loads that caused a page walk of any page size (4K/2M/4M/1G). This implies it missed in all TLB levels, but the walk need not have completed.)",
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
      R"(Page walk completed due to a demand data load to a 4K page)",
      R"(Counts completed page walks  (4K sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Page walk completed due to a demand data load to a 2M/4M page)",
      R"(Counts completed page walks  (2M/4M sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Page walk completed due to a demand data load to a 1G page)",
      R"(Counts completed page walks  (1G sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Load miss in all TLB levels causes a page walk that completes. (All page sizes))",
      R"(Counts completed page walks  (all page sizes) caused by demand data loads. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts 1 per cycle for each PMH that is busy with a page walk for a load. EPT page walk duration are excluded in Skylake.)",
      R"(Counts 1 per cycle for each PMH that is busy with a page walk for a load. EPT page walk duration are excluded in Skylake microarchitecture.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_ACTIVE",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles when at least one PMH is busy with a page walk for a load. EPT page walk duration are excluded in Skylake.)",
      R"(Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a load.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Loads that miss the DTLB and hit the STLB.)",
      R"(Counts loads that miss the DTLB (Data TLB) and hit the STLB (Second level TLB).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Core cycles the allocator was stalled due to recovery from earlier clear event for this thread (e.g. misprediction or memory nuke))",
      R"(Core cycles the Resource allocator was stalled due to recovery from an earlier branch misprediction or machine clear event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_CYCLES_ANY",
      EventDef::Encoding{
          .code = 0x0D,
          .umask = 0x01,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke).)",
      R"(Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.CLEAR_RESTEER_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Cycles the issue-stage is waiting for front-end to fetch from resteered path following branch misprediction or machine clear events.)",
      R"(Cycles the issue-stage is waiting for front-end to fetch from resteered path following branch misprediction or machine clear events.)",
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
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for the thread)",
      R"(Counts cycles during which the Resource Allocation Table (RAT) does not issue any Uops to the reservation station (RS) for the current thread.)",
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
      R"(Counts the number of uops that the Resource Allocation Table (RAT) issues to the Reservation Station (RS).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.VECTOR_WIDTH_MISMATCH",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Uops inserted at issue-stage in order to preserve upper bits of vector registers.)",
      R"(Counts the number of Blend Uops issued by the Resource Allocation Table (RAT) to the reservation station (RS) in order to preserve upper bits of vector registers. Starting with the Skylake microarchitecture, these Blend uops are needed since every Intel SSE instruction executed in Dirty Upper State needs to preserve bits 128-255 of the destination register. For more information, refer to Mixing Intel AVX and Intel SSE Code section of the Optimization Guide.)",
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
      R"(Number of slow LEA uops being allocated. A uop is generally considered SlowLea if it has 3 sources (e.g. 2 sources + immediate) regardless if as a result of LEA instruction or not.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.DIVIDER_ACTIVE",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles when divide unit is busy executing divide or square root operations. Accounts for integer and floating-point operations.)",
      R"(Cycles when divide unit is busy executing divide or square root operations. Accounts for integer and floating-point operations.)",
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
      R"(Counts the number of demand Data Read requests that miss L2 cache. Only not rejected loads are counted.)",
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
      R"(Counts the RFO (Read-for-Ownership) requests that miss L2 cache.)",
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
      R"(Counts L2 cache misses when fetching instructions.)",
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
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PF_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x38, .cmask = 0, .msr_values = {0}},
      R"(Requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that miss L2 cache)",
      R"(Counts requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that miss L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x3F, .cmask = 0, .msr_values = {0}},
      R"(All requests that miss L2 cache)",
      R"(All requests that miss L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xc2, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that hit L2 cache)",
      R"(Counts the RFO (Read-for-Ownership) requests that hit L2 cache.)",
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
      R"(Counts L2 cache hits when fetching instructions, code reads.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PF_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xd8, .cmask = 0, .msr_values = {0}},
      R"(Requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that hit L2 cache)",
      R"(Counts requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that hit L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xE1, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests)",
      R"(Counts the number of demand Data Read requests (including requests from L1D hardware prefetchers). These loads may hit or miss L2 cache. Only non rejected loads are counted.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_RFO",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xE2, .cmask = 0, .msr_values = {0}},
      R"(RFO requests to L2 cache)",
      R"(Counts the total number of RFO (read for ownership) requests to L2 cache. L2 RFO requests include both L1D demand RFO misses as well as L1D RFO prefetches.)",
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
      R"(Counts the total number of L2 code requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_PF",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xF8, .cmask = 0, .msr_values = {0}},
      R"(Requests from the L1/L2/L3 hardware prefetchers or Load software prefetches)",
      R"(Counts the total number of requests from the L2 hardware prefetchers.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.REFERENCES",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xFF, .cmask = 0, .msr_values = {0}},
      R"(All L2 requests)",
      R"(All L2 requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_POWER.LVL0_TURBO_LICENSE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x07, .cmask = 0, .msr_values = {0}},
      R"(Core cycles where the core was running in a manner where Turbo may be clipped to the Non-AVX turbo schedule.)",
      R"(Core cycles where the core was running with power-delivery for baseline license level 0.  This includes non-AVX codes, SSE, AVX 128-bit, and low-current AVX 256-bit codes.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_POWER.LVL1_TURBO_LICENSE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x18, .cmask = 0, .msr_values = {0}},
      R"(Core cycles where the core was running in a manner where Turbo may be clipped to the AVX2 turbo schedule.)",
      R"(Core cycles where the core was running with power-delivery for license level 1.  This includes high current AVX 256-bit instructions as well as low current AVX 512-bit instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_POWER.LVL2_TURBO_LICENSE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Core cycles where the core was running in a manner where Turbo may be clipped to the AVX512 turbo schedule.)",
      R"(Core cycles where the core was running with power-delivery for license level 2 (introduced in Skylake Server michroarchtecture).  This includes high current AVX 512-bit instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_POWER.THROTTLE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Core cycles the core was throttled due to a pending power level request.)",
      R"(Core cycles the out-of-order engine was throttled due to a pending power level request.)",
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
      R"(Counts core-originated cacheable requests that miss the L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L1 and L2. It does not include all misses to the L3.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(SKL057)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x4F, .cmask = 0, .msr_values = {0}},
      R"(Core-originated cacheable demand requests that refer to L3)",
      R"(Counts core-originated cacheable requests to the  L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L1 and L2.  It does not include all accesses to the L3.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(SKL057)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.NTA",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of PREFETCHNTA instructions executed.)",
      R"(Number of PREFETCHNTA instructions executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.T0",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of PREFETCHT0 instructions executed.)",
      R"(Number of PREFETCHT0 instructions executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.T1_T2",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of PREFETCHT1 or PREFETCHT2 instructions executed.)",
      R"(Number of PREFETCHT1 or PREFETCHT2 instructions executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.PREFETCHW",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of PREFETCHW instructions executed.)",
      R"(Number of PREFETCHW instructions executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_P",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Thread cycles when thread is not in halt state)",
      R"(This is an architectural event that counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling. For this reason, this event may have a changing ratio with regards to wall clock time.)",
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
      "CPU_CLK_UNHALTED.RING0_TRANS",
      EventDef::Encoding{
          .code = 0x3C,
          .umask = 0x00,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Counts when there is a transition from ring 1, 2 or 3 to ring 0.)",
      R"(Counts when the Current Privilege Level (CPL) transitions from ring 1, 2 or 3 to ring 0 (Kernel).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Core crystal clock cycles when the thread is unhalted.)",
      R"(Core crystal clock cycles when the thread is unhalted.)",
      25003,
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
      R"(Core crystal clock cycles when at least one thread on the physical core is unhalted.)",
      R"(Core crystal clock cycles when at least one thread on the physical core is unhalted.)",
      25003,
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
          .msr_values = {0}},
      R"(Core crystal clock cycles when at least one thread on the physical core is unhalted.)",
      R"(Core crystal clock cycles when at least one thread on the physical core is unhalted.)",
      25003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Core crystal clock cycles when the thread is unhalted.)",
      R"(Core crystal clock cycles when the thread is unhalted.)",
      25003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.ONE_THREAD_ACTIVE",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Core crystal clock cycles when this thread is unhalted and the other thread is halted.)",
      R"(Core crystal clock cycles when this thread is unhalted and the other thread is halted.)",
      25003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.ONE_THREAD_ACTIVE",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Core crystal clock cycles when this thread is unhalted and the other thread is halted.)",
      R"(Core crystal clock cycles when this thread is unhalted and the other thread is halted.)",
      25003,
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
      R"(Counts duration of L1D miss outstanding in cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.PENDING",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L1D miss outstandings duration in cycles)",
      R"(Counts duration of L1D miss outstanding, that is each cycle number of Fill Buffers (FB) outstanding required by Demand Reads. FB either is held by demand loads, or it is held by non-demand loads and gets hit at least once by demand. The valid outstanding interval is defined until the FB deallocation by one of the following ways: from FB allocation, if FB is allocated by demand from the demand Hit FB, if it is allocated by hardware or software prefetch.Note: In the L1D, a Demand Read contains cacheable or noncacheable demand loads, including ones causing cache-line splits and reads due to page walks resulted from any request type.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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
          .code = 0x48, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times a request needed a FB entry but there was no entry available for it. That is the FB unavailability was dominant reason for blocking the request. A request includes cacheable/uncacheable demands that is load, store or SW prefetch.)",
      R"(Number of times a request needed a FB (Fill Buffer) entry but there was no entry available for it. A request includes cacheable/uncacheable demands that are load, store or SW prefetch instructions.)",
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
      R"(Counts demand data stores that caused a page walk of any page size (4K/2M/4M/1G). This implies it missed in all TLB levels, but the walk need not have completed.)",
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
      R"(Page walk completed due to a demand data store to a 4K page)",
      R"(Counts completed page walks  (4K sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Page walk completed due to a demand data store to a 2M/4M page)",
      R"(Counts completed page walks  (2M/4M sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Page walk completed due to a demand data store to a 1G page)",
      R"(Counts completed page walks  (1G sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all TLB levels causes a page walk that completes. (All page sizes))",
      R"(Counts completed page walks  (all page sizes) caused by demand data stores. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts 1 per cycle for each PMH that is busy with a page walk for a store. EPT page walk duration are excluded in Skylake.)",
      R"(Counts 1 per cycle for each PMH that is busy with a page walk for a store. EPT page walk duration are excluded in Skylake microarchitecture.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_ACTIVE",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles when at least one PMH is busy with a page walk for a store. EPT page walk duration are excluded in Skylake.)",
      R"(Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a store.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Stores that miss the DTLB and hit the STLB.)",
      R"(Stores that miss the DTLB (Data TLB) and hit the STLB (2nd Level TLB).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE.SW_PF",
      EventDef::Encoding{
          .code = 0x4C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand load dispatches that hit L1D fill buffer (FB) allocated for software prefetch.)",
      R"(Counts all not software-prefetch load dispatches that hit the fill buffer (FB) allocated for the software prefetch. It can also be incremented by some lock instructions. So it should only be used with profiling so that the locks can be excluded by ASM (Assembly File) inspection of the nearby instructions.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x4f, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts 1 per cycle for each PMH that is busy with a EPT (Extended Page Table) walk for any request type.)",
      R"(Counts cycles for each PMH (Page Miss Handler) that is busy with an EPT (Extended Page Table) walk for any request type.)",
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
      R"(Counts L1D data line replacements including opportunistic replacements, and replacements that require stall-for-replace or block-for-replace.)",
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
      R"(Number of times a transactional abort was signaled due to a data conflict on a transactionally accessed address)",
      R"(Number of times a TSX line had a cache conflict.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_CAPACITY",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times a transactional abort was signaled due to a data capacity limitation for transactional reads or writes.)",
      R"(Number of times a transactional abort was signaled due to a data capacity limitation for transactional reads or writes.)",
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
      R"(Number of times a HLE transactional region aborted due to a non XRELEASE prefixed instruction writing to an elided lock in the elision buffer)",
      R"(Number of times a TSX Abort was triggered due to a non-release/commit store to lock.)",
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
      R"(Number of times a TSX Abort was triggered due to commit but Lock Buffer not empty.)",
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
      R"(Number of times an HLE transactional execution aborted due to XRELEASE lock not satisfying the address and value requirements in the elision buffer)",
      R"(Number of times a TSX Abort was triggered due to release/commit but data and address mismatch.)",
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
      R"(Number of times a TSX Abort was triggered due to attempting an unsupported alignment from Lock Buffer.)",
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
      R"(Number of times we could not allocate Lock Buffer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_DECODED.DECODERS",
      EventDef::Encoding{
          .code = 0x55, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instruction decoders utilized in a cycle)",
      R"(Number of decoders utilized in a cycle when the MITE (legacy decode pipeline) fetches instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PARTIAL_RAT_STALLS.SCOREBOARD",
      EventDef::Encoding{
          .code = 0x59, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles where the pipeline is stalled due to serializing operations.)",
      R"(This event counts cycles during which the microcode scoreboard stalls happen.)",
      2000003,
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
      R"(Counts the number of times a class of instructions (e.g., vzeroupper) that may cause a transactional abort was executed inside a transactional region)",
      R"(Unfriendly TSX abort triggered by a vzeroupper instruction.)",
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
      R"(Counts the number of times an instruction execution caused the transactional nest count supported to be exceeded)",
      R"(Unfriendly TSX abort triggered by a nest count that is too deep.)",
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
      R"(RTM region detected inside HLE.)",
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
      R"(Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region)",
      R"(Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region.)",
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
      R"(Counts end of periods where the Reservation Station (RS) was empty. Could be useful to precisely locate front-end Latency Bound issues.)",
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
      R"(Counts cycles during which the reservation station (RS) is empty for the thread.; Note: In ST-mode, not active thread should drive 0. This is usually caused by severely costly branch mispredictions, or allocator/FE issues.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore)",
      R"(Counts cycles when offcore outstanding Demand Data Read transactions are present in the super queue (SQ). A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation).)",
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
      R"(Counts the number of offcore outstanding Demand Data Read transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor. See the corresponding Umask under OFFCORE_REQUESTS.Note: A prefetch promoted to Demand is counted from the promotion point.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding Code Reads transactions in the SuperQueue (SQ), queue to uncore, every cycle.)",
      R"(Counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x02, .cmask = 1, .msr_values = {0}},
      R"(Cycles with offcore outstanding Code Reads transactions in the SuperQueue (SQ), queue to uncore.)",
      R"(Counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle)",
      R"(Counts the number of offcore outstanding RFO (store) transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 1, .msr_values = {0}},
      R"(Cycles with offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore.)",
      R"(Counts the number of offcore outstanding demand rfo Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore.)",
      R"(Counts cycles when offcore outstanding cacheable Core Data Read transactions are present in the super queue. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore)",
      R"(Counts the number of offcore outstanding cacheable Core Data Read transactions in the super queue every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.L3_MISS_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts number of Offcore outstanding Demand Data Read requests that miss L3 cache in the superQ every cycle.)",
      R"(Counts number of Offcore outstanding Demand Data Read requests that miss L3 cache in the superQ every cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.L3_MISS_DEMAND_DATA_RD_GE_6",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x10, .cmask = 6, .msr_values = {0x00}},
      R"(Cycles with at least 6 Demand Data Read requests that miss L3 cache in the superQ.)",
      R"(Cycles with at least 6 Demand Data Read requests that miss L3 cache in the superQ.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_L3_MISS_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x10, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles with at least 1 Demand Data Read requests who miss L3 cache in the superQ.)",
      R"(Cycles with at least 1 Demand Data Read requests who miss L3 cache in the superQ.)",
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
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from MITE path)",
      R"(Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may 'bypass' the IDQ.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path)",
      R"(Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may 'bypass' the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from Decode Stream Buffer (DSB) path)",
      R"(Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may 'bypass' the IDQ.)",
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
      R"(Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may 'bypass' the IDQ.)",
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
      R"(Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Counts cycles during which uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may 'bypass' the IDQ.)",
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
      R"(Counts the number of cycles uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Count includes uops that may 'bypass' the IDQ.)",
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
      R"(Counts the number of cycles 4 uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Count includes uops that may 'bypass' the IDQ.)",
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
      R"(Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Counts the number of uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may 'bypass' the IDQ.)",
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
      R"(Counts the number of cycles uops were delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. Counting includes uops that may 'bypass' the IDQ. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
      R"(Counts the number of cycles 4 uops were delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. Counting includes uops that may 'bypass' the IDQ. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may 'bypass' the IDQ. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.)",
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
      R"(Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Counts the total number of uops delivered by the Microcode Sequencer (MS). Any instruction over 4 uops will be delivered by the MS. Some instructions such as transcendentals may additionally generate uops from the MS.)",
      2000003,
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
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer)",
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_16B.IFDATA_STALL",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles where a code fetch is stalled due to L1 instruction cache miss.)",
      R"(Cycles where a code line fetch is stalled due to an L1 instruction cache miss. The legacy decode pipeline works at a 16 Byte granularity.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_64B.IFTAG_HIT",
      EventDef::Encoding{
          .code = 0x83, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instruction fetch tag lookups that hit in the instruction cache (L1I). Counts at 64-byte cache-line granularity.)",
      R"(Instruction fetch tag lookups that hit in the instruction cache (L1I). Counts at 64-byte cache-line granularity.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_64B.IFTAG_MISS",
      EventDef::Encoding{
          .code = 0x83, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Instruction fetch tag lookups that miss in the instruction cache (L1I). Counts at 64-byte cache-line granularity.)",
      R"(Instruction fetch tag lookups that miss in the instruction cache (L1I). Counts at 64-byte cache-line granularity.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_64B.IFTAG_STALL",
      EventDef::Encoding{
          .code = 0x83, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles where a code fetch is stalled due to L1 instruction cache tag miss.)",
      R"(Cycles where a code fetch is stalled due to L1 instruction cache tag miss.)",
      200003,
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
      R"(Counts page walks of any page size (4K/2M/4M/1G) caused by a code fetch. This implies it missed in the ITLB and further levels of TLB, but the walk need not have completed.)",
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
      R"(Counts completed page walks (4K page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Counts completed page walks (2M/4M page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Code miss in all TLB levels causes a page walk that completes. (1G))",
      R"(Counts completed page walks (1G page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Code miss in all TLB levels causes a page walk that completes. (All page sizes))",
      R"(Counts completed page walks (all page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts 1 per cycle for each PMH that is busy with a page walk for an instruction fetch request. EPT page walk duration are excluded in Skylake.)",
      R"(Counts 1 per cycle for each PMH (Page Miss Handler) that is busy with a page walk for an instruction fetch request. EPT page walk duration are excluded in Skylake michroarchitecture.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_ACTIVE",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles when at least one PMH is busy with a page walk for code (instruction fetch) request. EPT page walk duration are excluded in Skylake.)",
      R"(Cycles when at least one PMH is busy with a page walk for code (instruction fetch) request. EPT page walk duration are excluded in Skylake microarchitecture.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Instruction fetch requests that miss the ITLB and hit the STLB.)",
      R"(Instruction fetch requests that miss the ITLB and hit the STLB.)",
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
      R"(Counts cycles that the Instruction Length decoder (ILD) stalls occurred due to dynamically changing prefix length of the decoded instruction (by operand size prefix instruction 0x66, address size prefix instruction 0x67 or REX.W for Intel64). Count is proportional to the number of prefixes in a 16B-line. This may result in a three-cycle penalty for each LCP (Length changing prefix) in a 16-byte chunk.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_3_UOP_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles with less than 3 uops delivered by the front end.)",
      R"(Cycles with less than 3 uops delivered by the front-end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_2_UOP_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 2, .msr_values = {0}},
      R"(Cycles with less than 2 uops delivered by the front end.)",
      R"(Cycles with less than 2 uops delivered by the front-end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_1_UOP_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 3, .msr_values = {0}},
      R"(Cycles per thread when 3 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled)",
      R"(Counts, on the per-thread basis, cycles when less than 1 uop is delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core >= 3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 4, .msr_values = {0}},
      R"(Cycles per thread when 4 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled)",
      R"(Counts, on the per-thread basis, cycles when no uops are delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core =4.)",
      2000003,
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
      R"(Counts the number of uops not delivered to Resource Allocation Table (RAT) per thread adding 4  x when Resource Allocation Table (RAT) is not stalled and Instruction Decode Queue (IDQ) delivers x uops to Resource Allocation Table (RAT) (where x belongs to {0,1,2,3}). Counting does not cover cases when: a. IDQ-Resource Allocation Table (RAT) pipe serves the other thread. b. Resource Allocation Table (RAT) is stalled for the thread (including uop drops and clear BE conditions).  c. Instruction Decode Queue (IDQ) delivers four uops.)",
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
      R"(Cycles per thread when uops are executed in port 0)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 0.)",
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
      R"(Cycles per thread when uops are executed in port 1)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 1.)",
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
      R"(Cycles per thread when uops are executed in port 2)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 2.)",
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
      R"(Cycles per thread when uops are executed in port 3)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 3.)",
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
      R"(Cycles per thread when uops are executed in port 4)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 4.)",
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
      R"(Cycles per thread when uops are executed in port 5)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 5.)",
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
      R"(Cycles per thread when uops are executed in port 6)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 6.)",
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
      R"(Cycles per thread when uops are executed in port 7)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 7.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.ANY",
      EventDef::Encoding{
          .code = 0xa2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Resource-related stall cycles)",
      R"(Counts resource-related stall cycles.)",
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
      R"(Counts allocation stall cycles caused by the store buffer (SB) being full. This counts cycles that the pipeline back-end blocked uop delivery from the front-end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L2_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles while L2 cache miss demand load is outstanding.)",
      R"(Cycles while L2 cache miss demand load is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L3_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x02, .cmask = 2, .msr_values = {0x00}},
      R"(Cycles while L3 cache miss demand load is outstanding.)",
      R"(Cycles while L3 cache miss demand load is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_TOTAL",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x04, .cmask = 4, .msr_values = {0}},
      R"(Total execution stalls.)",
      R"(Total execution stalls.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x05, .cmask = 5, .msr_values = {0}},
      R"(Execution stalls while L2 cache miss demand load is outstanding.)",
      R"(Execution stalls while L2 cache miss demand load is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L3_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x06, .cmask = 6, .msr_values = {0x00}},
      R"(Execution stalls while L3 cache miss demand load is outstanding.)",
      R"(Execution stalls while L3 cache miss demand load is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L1D_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x08, .cmask = 8, .msr_values = {0}},
      R"(Cycles while L1 cache miss demand load is outstanding.)",
      R"(Cycles while L1 cache miss demand load is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L1D_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x0C, .cmask = 12, .msr_values = {0}},
      R"(Execution stalls while L1 cache miss demand load is outstanding.)",
      R"(Execution stalls while L1 cache miss demand load is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_MEM_ANY",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x10, .cmask = 16, .msr_values = {0}},
      R"(Cycles while memory subsystem has an outstanding load.)",
      R"(Cycles while memory subsystem has an outstanding load.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_MEM_ANY",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x14, .cmask = 20, .msr_values = {0}},
      R"(Execution stalls while memory subsystem has an outstanding load.)",
      R"(Execution stalls while memory subsystem has an outstanding load.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EXE_ACTIVITY.EXE_BOUND_0_PORTS",
      EventDef::Encoding{
          .code = 0xA6, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles where no uops were executed, the Reservation Station was not empty, the Store Buffer was full and there was no outstanding load.)",
      R"(Counts cycles during which no uops were executed on all ports and Reservation Station (RS) was not empty.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EXE_ACTIVITY.1_PORTS_UTIL",
      EventDef::Encoding{
          .code = 0xA6, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cycles total of 1 uop is executed on all ports and Reservation Station was not empty.)",
      R"(Counts cycles during which a total of 1 uop was executed on all ports and Reservation Station (RS) was not empty.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EXE_ACTIVITY.2_PORTS_UTIL",
      EventDef::Encoding{
          .code = 0xA6, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles total of 2 uops are executed on all ports and Reservation Station was not empty.)",
      R"(Counts cycles during which a total of 2 uops were executed on all ports and Reservation Station (RS) was not empty.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EXE_ACTIVITY.3_PORTS_UTIL",
      EventDef::Encoding{
          .code = 0xA6, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles total of 3 uops are executed on all ports and Reservation Station was not empty.)",
      R"(Cycles total of 3 uops are executed on all ports and Reservation Station (RS) was not empty.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EXE_ACTIVITY.4_PORTS_UTIL",
      EventDef::Encoding{
          .code = 0xA6, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles total of 4 uops are executed on all ports and Reservation Station was not empty.)",
      R"(Cycles total of 4 uops are executed on all ports and Reservation Station (RS) was not empty.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EXE_ACTIVITY.BOUND_ON_STORES",
      EventDef::Encoding{
          .code = 0xA6, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Cycles where the Store Buffer was full and no outstanding load.)",
      R"(Cycles where the Store Buffer was full and no outstanding load.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.UOPS",
      EventDef::Encoding{
          .code = 0xA8, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of Uops delivered by the LSD.)",
      R"(Number of uops delivered to the back-end by the LSD(Loop Stream Detector).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.CYCLES_4_UOPS",
      EventDef::Encoding{
          .code = 0xA8, .umask = 0x01, .cmask = 4, .msr_values = {0x00}},
      R"(Cycles 4 Uops delivered by the LSD, but didn't come from the decoder.)",
      R"(Counts the cycles when 4 uops are delivered by the LSD (Loop-stream detector).)",
      2000003,
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
      R"(Counts the cycles when at least one uop is delivered by the LSD (Loop-stream detector).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB2MITE_SWITCHES.COUNT",
      EventDef::Encoding{
          .code = 0xAB, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Decode Stream Buffer (DSB)-to-MITE switches)",
      R"(This event counts the number of the Decode Stream Buffer (DSB)-to-MITE switches including all misses because of missing Decode Stream Buffer (DSB) cache and u-arch forced misses.
Note: Invoking MITE requires two or three cycles delay.)",
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
      R"(Counts Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles. These cycles do not include uops routed through because of the switch itself, for example, when Instruction Decode Queue (IDQ) pre-allocation is unavailable, or Instruction Decode Queue (IDQ) is full. SBD-to-MITE switch true penalty cycles happen after the merge mux (MM) receives Decode Stream Buffer (DSB) Sync-indication until receiving the first MITE uop. MM is placed before Instruction Decode Queue (IDQ) to merge uops being fed from the MITE and Decode Stream Buffer (DSB) paths. Decode Stream Buffer (DSB) inserts the Sync-indication whenever a Decode Stream Buffer (DSB)-to-MITE switch occurs.Penalty: A Decode Stream Buffer (DSB) hit followed by a Decode Stream Buffer (DSB) miss can cost up to six cycles in which no uops are delivered to the IDQ. Most often, such switches from the Decode Stream Buffer (DSB) to the legacy pipeline cost 02 cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB.ITLB_FLUSH",
      EventDef::Encoding{
          .code = 0xAE, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Flushing of the Instruction TLB (ITLB) pages, includes 4k/2M/4M pages.)",
      R"(Counts the number of flushes of the big or small ITLB pages. Counting include both TLB Flush (covering all sets) and TLB Set Clear (set-specific).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests sent to uncore)",
      R"(Counts the Demand Data Read requests sent to uncore. Use it in conjunction with OFFCORE_REQUESTS_OUTSTANDING to determine average latency in the uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cacheable and noncachaeble code read requests)",
      R"(Counts both cacheable and non-cacheable code read requests.)",
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
      R"(Counts the demand RFO (read for ownership) requests including regular RFOs, locks, ItoM.)",
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
      R"(Counts the demand and prefetch data reads. All Core Data Reads include cacheable 'Demands' and L2 prefetchers (not L3 prefetchers). Counting also covers reads due to page walks resulted from any request type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.L3_MISS_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests who miss L3 cache)",
      R"(Demand Data Read requests who miss L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.ALL_REQUESTS",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Any memory transaction that reached the SQ.)",
      R"(Counts memory transactions reached the super queue including requests initiated by the core, all L3 prefetches, page walks, etc..)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_4_UOPS_EXEC",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 4, .msr_values = {0}},
      R"(Cycles where at least 4 uops were executed per-thread)",
      R"(Cycles where at least 4 uops were executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_3_UOPS_EXEC",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 3, .msr_values = {0}},
      R"(Cycles where at least 3 uops were executed per-thread)",
      R"(Cycles where at least 3 uops were executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_2_UOPS_EXEC",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 2, .msr_values = {0}},
      R"(Cycles where at least 2 uops were executed per-thread)",
      R"(Cycles where at least 2 uops were executed per-thread.)",
      2000003,
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
      R"(Cycles where at least 1 uop was executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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
      R"(Counts cycles during which no uops were dispatched from the Reservation Station (RS) per thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.THREAD",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of uops to be executed per-thread each cycle.)",
      R"(Number of uops to be executed per-thread each cycle.)",
      2000003,
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
      R"(Number of uops executed from any thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_NONE",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x02,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles with no micro-ops executed from any thread on physical core.)",
      R"(Cycles with no micro-ops executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_4",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 4, .msr_values = {0}},
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_3",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 3, .msr_values = {0}},
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_2",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 2, .msr_values = {0}},
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_1",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 1, .msr_values = {0}},
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.X87",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of x87 uops dispatched.)",
      R"(Counts the number of x87 uops executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_BUFFER.SQ_FULL",
      EventDef::Encoding{
          .code = 0xB2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore requests buffer cannot take more entries for this thread core.)",
      R"(Counts the number of cases when the offcore requests buffer cannot take more entries for the core. This can happen when the superqueue does not contain eligible entries, or when L1D writeback pending FIFO requests is full.Note: Writeback pending FIFO has six entries.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction)",
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
      100003,
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
      R"(Counts the number of DTLB flush attempts of the thread-specific entries.)",
      100007,
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
      R"(Counts the number of any STLB flush attempts (such as entire, VPID, PCID, InvPage, CR3 write, etc.).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Number of instructions retired. General Counter - architectural event)",
      R"(Counts the number of instructions (EOMs) retired. Counting covers macro-fused instructions individually (that is, increments by two).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(SKL091, SKL044)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.PREC_DIST",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Precise instruction retired event with HW to reduce effect of PEBS shadow in IP distribution)",
      R"(A version of INST_RETIRED that allows for a more unbiased distribution of samples across instructions retired. It utilizes the Precise Distribution of Instructions Retired (PDIR) feature to mitigate some bias in how retired instructions get sampled.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(SKL091, SKL044)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.TOTAL_CYCLES_PS",
      EventDef::Encoding{
          .code = 0xC0,
          .umask = 0x01,
          .inv = true,
          .cmask = 10,
          .msr_values = {0}},
      R"(Number of cycles using always true condition applied to  PEBS instructions retired event.)",
      R"(Number of cycles using an always true condition applied to  PEBS instructions retired event. (inst_ret< 16))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(SKL091, SKL044)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.NOP",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of all retired NOP instructions.)",
      R"(Number of all retired NOP instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(SKL091, SKL044)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.ANY",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x3F, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times a microcode assist is invoked by HW other than FP-assist. Examples include AD (page Access Dirty) and AVX* related assists.)",
      R"(Number of times a microcode assist is invoked by HW other than FP-assist. Examples include AD (page Access Dirty) and AVX* related assists.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.TOTAL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x02,
          .inv = true,
          .cmask = 16,
          .msr_values = {0}},
      R"(Cycles with less than 10 actually retired uops.)",
      R"(Number of cycles using always true condition (uops_ret < 16) applied to non PEBS uops retired event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x02,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles without actually retired uops.)",
      R"(This event counts cycles without actually retired uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.RETIRE_SLOTS",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retirement slots used.)",
      R"(Counts the retirement slots used.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.MACRO_FUSED",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of macro-fused uops retired. (non precise))",
      R"(Counts the number of macro-fused uops retired. (non precise))",
      2000003,
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
          .msr_values = {0}},
      R"(Number of machine clears (nukes) of any type.)",
      R"(Number of machine clears (nukes) of any type.)",
      100003,
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
      R"(Counts the number of memory ordering Machine Clears detected. Memory Ordering Machine Clears can result from one of the following:a. memory disambiguation,b. external snoop, orc. cross SMT-HW-thread snoop (stores) hitting load buffer.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(SKL089)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SMC",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Self-modifying code (SMC) detected.)",
      R"(Counts self-modifying code (SMC) detected, which causes a machine clear.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(All (macro) branch instructions retired.)",
      R"(Counts all (macro) branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Conditional branch instructions retired.)",
      R"(This event counts conditional branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect near call instructions retired.)",
      R"(This event counts both direct and indirect near call instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(All (macro) branch instructions retired.)",
      R"(This is a precise version of BR_INST_RETIRED.ALL_BRANCHES that counts all (macro) branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_RETURN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Return instructions retired.)",
      R"(This event counts return instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NOT_TAKEN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Not taken branch instructions retired.)",
      R"(This event counts not taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.COND_NTAKEN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Not taken branch instructions retired.)",
      R"(This event counts not taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Taken branch instructions retired.)",
      R"(This event counts taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Far branch instructions retired.)",
      R"(This event counts far branch instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(SKL091)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(All mispredicted macro branch instructions retired.)",
      R"(Counts all the retired branch instructions that were mispredicted by the processor. A branch misprediction occurs when the processor incorrectly predicts the destination of the branch.  When the misprediction is discovered at execution, all the instructions executed in the wrong (speculative) path must be discarded, and the processor must start fetching from the correct path.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted conditional branch instructions retired.)",
      R"(This event counts mispredicted conditional branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted direct and indirect near call instructions retired.)",
      R"(Counts both taken and not taken retired mispredicted direct and indirect near calls, including both register and memory indirect.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted macro branch instructions retired.)",
      R"(This is a precise version of BR_MISP_RETIRED.ALL_BRANCHES that counts all mispredicted macro branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.RET",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(This event counts the number of mispredicted ret instructions retired. Non PEBS)",
      R"(This is a non-precise version (that is, does not use PEBS) of the event that counts mispredicted return instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of near branch instructions retired that were mispredicted and taken.)",
      R"(Number of near branch instructions retired that were mispredicted and taken.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_4",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x400406}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_2_BUBBLES_GE_2",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x200206}},
      R"(Retired instructions that are fetched after an interval where the front-end had at least 2 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end had at least 2 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_2",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x400206}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 2 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 2 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.STLB_MISS",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x15}},
      R"(Retired Instructions who experienced STLB (2nd level TLB) true miss.)",
      R"(Counts retired Instructions that experienced STLB (2nd level TLB) true miss. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.ITLB_MISS",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x14}},
      R"(Retired Instructions who experienced iTLB true miss.)",
      R"(Counts retired Instructions that experienced iTLB (Instruction TLB) true miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x13}},
      R"(Retired Instructions who experienced Instruction L2 Cache true miss.)",
      R"(Retired Instructions who experienced Instruction L2 Cache true miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.L1I_MISS",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x12}},
      R"(Retired Instructions who experienced Instruction L1 Cache true miss.)",
      R"(Retired Instructions who experienced Instruction L1 Cache true miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.DSB_MISS",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x11}},
      R"(Retired Instructions who experienced a critical DSB miss.)",
      R"(Number of retired Instructions that experienced a critical DSB (Decode stream buffer i.e. the decoded instruction-cache) miss. Critical means stalls were exposed to the back-end as a result of the DSB miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_2_BUBBLES_GE_3",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x300206}},
      R"(Retired instructions that are fetched after an interval where the front-end had at least 3 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end had at least 3 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_2_BUBBLES_GE_1",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x100206}},
      R"(Retired instructions that are fetched after an interval where the front-end had at least 1 bubble-slot for a period of 2 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after the front-end had at least 1 bubble-slot for a period of 2 cycles. A bubble-slot is an empty issue-pipeline slot while there was no RAT stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_512",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x420006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_256",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x410006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_128",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x408006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_64",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x404006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_32",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x402006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 32 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after a front-end stall of at least 32 cycles. During this period the front-end delivered no uops.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_16",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x401006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 16 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after a front-end stall of at least 16 cycles. During this period the front-end delivered no uops.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_8",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x400806}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 8 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after a front-end stall of at least 8 cycles. During this period the front-end delivered no uops.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_1",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x400106}},
      R"(Retired instructions after front-end starvation of at least 1 cycle)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of at least 1 cycle which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.ANY_DSB_MISS",
      EventDef::Encoding{
          .code = 0xC6, .umask = 0x01, .cmask = 0, .msr_values = {0x1}},
      R"(Retired Instructions who experienced DSB miss.)",
      R"(Counts retired Instructions that experienced DSB (Decode stream buffer i.e. the decoded instruction-cache) miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SCALAR_DOUBLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts once for most SIMD scalar computational double precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.)",
      R"(Counts once for most SIMD scalar computational double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SIMD scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SCALAR_SINGLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts once for most SIMD scalar computational single precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.)",
      R"(Counts once for most SIMD scalar computational single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SIMD scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.128B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts once for most SIMD 128-bit packed computational double precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.)",
      R"(Counts once for most SIMD 128-bit packed computational double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.128B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Counts once for most SIMD 128-bit packed computational single precision floating-point instruction retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.)",
      R"(Counts once for most SIMD 128-bit packed computational single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.256B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts once for most SIMD 256-bit packed double computational precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.)",
      R"(Counts once for most SIMD 256-bit packed double computational precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.256B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Counts once for most SIMD 256-bit packed single computational precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.)",
      R"(Counts once for most SIMD 256-bit packed single computational precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.512B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.  The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.512B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.START",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution started.)",
      R"(Number of times we entered an HLE region. Does not count nested transactions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.COMMIT",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution successfully committed)",
      R"(Number of times HLE commit succeeded.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to any reasons (multiple categories may count as one). )",
      R"(Number of times HLE abort was triggered.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MEM",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      R"(Number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_TIMER",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to hardware timer expiration.)",
      R"(Number of times an HLE execution aborted due to hardware timer expiration.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_UNFRIENDLY",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to HLE-unfriendly instructions and certain unfriendly events (such as AD assists etc.).)",
      R"(Number of times an HLE execution aborted due to HLE-unfriendly instructions and certain unfriendly events (such as AD assists etc.).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MEMTYPE",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to incompatible memory type)",
      R"(Number of times an HLE execution aborted due to incompatible memory type.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_EVENTS",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to unfriendly events (such as interrupts).)",
      R"(Number of times an HLE execution aborted due to unfriendly events (such as interrupts).)",
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
      R"(Number of times we entered an RTM region. Does not count nested transactions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.COMMIT",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution successfully committed)",
      R"(Number of times RTM commit succeeded.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to any reasons (multiple categories may count as one). )",
      R"(Number of times RTM abort was triggered.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MEM",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts))",
      R"(Number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_TIMER",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to uncommon conditions.)",
      R"(Number of times an RTM execution aborted due to uncommon conditions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_UNFRIENDLY",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to HLE-unfriendly instructions)",
      R"(Number of times an RTM execution aborted due to HLE-unfriendly instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MEMTYPE",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to incompatible memory type)",
      R"(Number of times an RTM execution aborted due to incompatible memory type.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_EVENTS",
      EventDef::Encoding{
          .code = 0xC9, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt))",
      R"(Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt).)",
      2000003,
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
      R"(Counts cycles with any input and output SSE or x87 FP assist. If an input and output assist are detected on the same cycle the event increments by 1.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_INTERRUPTS.RECEIVED",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of hardware interrupts received by the processor.)",
      R"(Counts the number of hardware interruptions received by the processor.)",
      203,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ROB_MISC_EVENTS.LBR_INSERTS",
      EventDef::Encoding{
          .code = 0xCC, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Increments whenever there is an update to the LBR array.)",
      R"(Increments when an entry is added to the Last Branch Record (LBR) array (or removed from the array in case of RETURNs in call stack mode). The event requires LBR enable via IA32_DEBUGCTL MSR and branch type selection via MSR_LBR_SELECT.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ROB_MISC_EVENTS.PAUSE_INST",
      EventDef::Encoding{
          .code = 0xCC, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of retired PAUSE instructions (that do not end up with a VMExit to the VMM; TSX aborted Instructions may be counted). This event is not supported on first SKL and KBL products.)",
      R"(Number of retired PAUSE instructions (that do not end up with a VMExit to the VMM; TSX aborted Instructions may be counted). This event is not supported on first SKL and KBL products.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_512",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x200}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 512 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 512 cycles.  Reported latency may be longer than just the memory latency.)",
      101,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_256",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x100}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 256 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 256 cycles.  Reported latency may be longer than just the memory latency.)",
      503,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_128",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x80}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 128 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 128 cycles.  Reported latency may be longer than just the memory latency.)",
      1009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_64",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x40}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 64 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 64 cycles.  Reported latency may be longer than just the memory latency.)",
      2003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_32",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x20}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 32 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 32 cycles.  Reported latency may be longer than just the memory latency.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_16",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x10}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 16 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 16 cycles.  Reported latency may be longer than just the memory latency.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_8",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x8}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 8 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 8 cycles.  Reported latency may be longer than just the memory latency.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_4",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x4}},
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 4 cycles.)",
      R"(Counts randomly selected loads when the latency from first dispatch to completion is greater than 4 cycles.  Reported latency may be longer than just the memory latency.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED2.128BIT_PACKED_BF16",
      EventDef::Encoding{
          .code = 0xCF, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Intel AVX-512 computational 512-bit packed BFloat16 instructions retired.)",
      R"(Counts once for each Intel AVX-512 computational 512-bit packed BFloat16 floating-point instruction retired. Applies to the ZMM based VDPBF16PS instruction.  Each count represents 64 computation operations. This event is only supported on products formerly named Cooper Lake and is not supported on products formerly named Cascade Lake.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED2.256BIT_PACKED_BF16",
      EventDef::Encoding{
          .code = 0xCF, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Intel AVX-512 computational 128-bit packed BFloat16 instructions retired.)",
      R"(Counts once for each Intel AVX-512 computational 128-bit packed BFloat16 floating-point instruction retired. Applies to the XMM based VDPBF16PS instruction. Each count represents 16 computation operations. This event is only supported on products formerly named Cooper Lake and is not supported on products formerly named Cascade Lake.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED2.512BIT_PACKED_BF16",
      EventDef::Encoding{
          .code = 0xCF, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Intel AVX-512 computational 256-bit packed BFloat16 instructions retired.)",
      R"(Counts once for each Intel AVX-512 computational 256-bit packed BFloat16 floating-point instruction retired. Applies to the YMM based VDPBF16PS instruction.  Each count represents 32 computation operations. This event is only supported on products formerly named Cooper Lake and is not supported on products formerly named Cascade Lake.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.STLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x11, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions that miss the STLB.)",
      R"(Number of retired load instructions that (start a) miss in the 2nd-level TLB (STLB).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.STLB_MISS_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x12, .cmask = 0, .msr_values = {0}},
      R"(Retired store instructions that miss the STLB.)",
      R"(Number of retired store instructions that (start a) miss in the 2nd-level TLB (STLB).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions with locked access.)",
      R"(Retired load instructions with locked access.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions that split across a cacheline boundary.)",
      R"(Counts retired load instructions that split across a cacheline boundary.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x42, .cmask = 0, .msr_values = {0}},
      R"(Retired store instructions that split across a cacheline boundary.)",
      R"(Counts retired store instructions that split across a cacheline boundary.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(All retired load instructions.)",
      R"(All retired load instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(All retired store instructions.)",
      R"(All retired store instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x83, .cmask = 0, .msr_values = {0}},
      R"(All retired memory instructions.)",
      R"(Counts all retired memory instructions - loads and stores.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions with L1 cache hits as data sources)",
      R"(Counts retired load instructions with at least one uop that hit in the L1 data cache. This event includes all SW prefetches and lock instructions regardless of the data source.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions with L2 cache hits as data sources)",
      R"(Retired load instructions with L2 cache hits as data sources.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L3_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions with L3 cache hits as data sources)",
      R"(Counts retired load instructions with at least one uop that hit in the L3 cache. )",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions missed L1 cache as data sources)",
      R"(Counts retired load instructions with at least one uop that missed in the L1 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions missed L2 cache as data sources)",
      R"(Retired load instructions missed L2 cache as data sources.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L3_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions missed L3 cache as data sources)",
      R"(Counts retired load instructions with at least one uop that missed in the L3 cache. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.FB_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions which data sources were load missed L1 but hit FB due to preceding miss to the same cache line with data not ready)",
      R"(Counts retired load instructions with at least one uop was load missed in L1 but hit FB (Fill Buffers) due to preceding miss to the same cache line with data not ready. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.LOCAL_PMM",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions with local Intel\xae Optane\u2122 DC persistent memory as the data source where the data request missed all caches. Precise event.)",
      R"(Counts retired load instructions with local Intel\xae Optane\u2122 DC persistent memory as the data source and the data request missed L3 (AppDirect or Memory Mode) and DRAM cache(Memory Mode). Precise event)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .ellc = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_MISS",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.)",
      R"(Retired load instructions which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_HIT",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions which data sources were L3 and cross-core snoop hits in on-pkg core cache)",
      R"(Retired load instructions which data sources were L3 and cross-core snoop hits in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_HITM",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions which data sources were HitM responses from shared L3)",
      R"(Retired load instructions which data sources were HitM responses from shared L3.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_NONE",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions which data sources were hits in L3 without snoops required)",
      R"(Retired load instructions which data sources were hits in L3 without snoops required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_MISS_RETIRED.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions which data sources missed L3 but serviced from local dram)",
      R"(Retired load instructions which data sources missed L3 but serviced from local DRAM.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_MISS_RETIRED.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions which data sources missed L3 but serviced from remote dram)",
      R"(Retired load instructions which data sources missed L3 but serviced from remote dram)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_MISS_RETIRED.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions whose data sources was remote HITM)",
      R"(Retired load instructions whose data sources was remote HITM.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_MISS_RETIRED.REMOTE_FWD",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions whose data sources was forwarded from a remote cache)",
      R"(Retired load instructions whose data sources was forwarded from a remote cache.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_MISS_RETIRED.REMOTE_PMM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Retired load instructions with remote Intel\xae Optane\u2122 DC persistent memory as the data source where the data request missed all caches. Precise event.)",
      R"(Counts retired load instructions with remote Intel\xae Optane\u2122 DC persistent memory as the data source and the data request missed L3 (AppDirect or Memory Mode) and DRAM cache(Memory Mode). Precise event)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .ellc = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_MISC_RETIRED.UC",
      EventDef::Encoding{
          .code = 0xD4, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired instructions with at least 1 uncacheable load or lock.)",
      R"(Retired instructions with at least 1 uncacheable load or lock.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ANY",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      R"(Counts the number of times the front-end is resteered when it finds a branch instruction in a fetch line. This occurs for the first time a branch instruction is fetched or when the branch is not tracked by the BPU (Branch Prediction Unit) anymore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_SNOOP_RESPONSE.RSP_IHITI",
      EventDef::Encoding{
          .code = 0xEF, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(CORE_SNOOP_RESPONSE.RSP_IHITI)",
      R"(CORE_SNOOP_RESPONSE.RSP_IHITI)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_SNOOP_RESPONSE.RSP_IHITFSE",
      EventDef::Encoding{
          .code = 0xEF, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(CORE_SNOOP_RESPONSE.RSP_IHITFSE)",
      R"(CORE_SNOOP_RESPONSE.RSP_IHITFSE)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_SNOOP_RESPONSE.RSP_SHITFSE",
      EventDef::Encoding{
          .code = 0xEF, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(CORE_SNOOP_RESPONSE.RSP_SHITFSE)",
      R"(CORE_SNOOP_RESPONSE.RSP_SHITFSE)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_SNOOP_RESPONSE.RSP_SFWDM",
      EventDef::Encoding{
          .code = 0xEF, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(CORE_SNOOP_RESPONSE.RSP_SFWDM)",
      R"(CORE_SNOOP_RESPONSE.RSP_SFWDM)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_SNOOP_RESPONSE.RSP_IFWDM",
      EventDef::Encoding{
          .code = 0xEF, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(CORE_SNOOP_RESPONSE.RSP_IFWDM)",
      R"(CORE_SNOOP_RESPONSE.RSP_IFWDM)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_SNOOP_RESPONSE.RSP_IFWDFE",
      EventDef::Encoding{
          .code = 0xEF, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(CORE_SNOOP_RESPONSE.RSP_IFWDFE)",
      R"(CORE_SNOOP_RESPONSE.RSP_IFWDFE)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_SNOOP_RESPONSE.RSP_SFWDFE",
      EventDef::Encoding{
          .code = 0xEF, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(CORE_SNOOP_RESPONSE.RSP_SFWDFE)",
      R"(CORE_SNOOP_RESPONSE.RSP_SFWDFE)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L2_WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(L2 writebacks that access L2 cache)",
      R"(Counts L2 writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.ALL",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x1F, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines filling L2)",
      R"(Counts the number of L2 cache lines filling the L2. Counting does not cover rejects.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.SILENT",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of lines that are silently dropped by L2 cache when triggered by an L2 cache fill. These lines are typically in Shared state. A non-threaded event.)",
      R"(Counts the number of lines that are silently dropped by L2 cache when triggered by an L2 cache fill. These lines are typically in Shared state. A non-threaded event.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.NON_SILENT",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of lines that are evicted by L2 cache when triggered by an L2 cache fill. Those lines can be either in modified state or clean state. Modified lines may either be written back to L3 or directly written to memory and not allocated in L3.  Clean lines may either be allocated in L3 or dropped)",
      R"(Counts the number of lines that are evicted by L2 cache when triggered by an L2 cache fill. Those lines can be either in modified state or clean state. Modified lines may either be written back to L3 or directly written to memory and not allocated in L3.  Clean lines may either be allocated in L3 or dropped.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.USELESS_HWPF",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of lines that have been hardware prefetched but not used and now evicted by L2 cache)",
      R"(Counts the number of lines that have been hardware prefetched but not used and now evicted by L2 cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SQ_MISC.SPLIT_LOCK",
      EventDef::Encoding{
          .code = 0xF4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of cache line split locks sent to uncore.)",
      R"(Counts the number of cache line split locks sent to the uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDI_MISC.WB_UPGRADE",
      EventDef::Encoding{
          .code = 0xFE, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts number of cache lines that are allocated and written back to L3 with the intention that they are more likely to be reused shortly)",
      R"(Counts number of cache lines that are allocated and written back to L3 with the intention that they are more likely to be reused shortly.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDI_MISC.WB_DOWNGRADE",
      EventDef::Encoding{
          .code = 0xFE, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts number of cache lines that are dropped and not written back to L3 as they are deemed to be less likely to be reused shortly)",
      R"(Counts number of cache lines that are dropped and not written back to L3 as they are deemed to be less likely to be reused shortly.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_NONE)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.DEMAND_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.DEMAND_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_MISS)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.DEMAND_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.DEMAND_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.ANY_SNOOP OCR.DEMAND_DATA_RD.L3_HIT.ANY_SNOOP)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_HIT.ANY_SNOOP OCR.DEMAND_DATA_RD.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000001}},
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts demand data reads  OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.SNOOP_NONE)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.DEMAND_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.DEMAND_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.SNOOP_MISS)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.DEMAND_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.DEMAND_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.DEMAND_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.ANY_SNOOP OCR.DEMAND_DATA_RD.L3_MISS.ANY_SNOOP)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.ANY_SNOOP OCR.DEMAND_DATA_RD.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.SNOOP_NONE)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.DEMAND_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.DEMAND_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.SNOOP_MISS)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.HITM_OTHER_CORE OCR.DEMAND_RFO.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.HITM_OTHER_CORE OCR.DEMAND_RFO.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.ANY_SNOOP OCR.DEMAND_RFO.L3_HIT.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_HIT.ANY_SNOOP OCR.DEMAND_RFO.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000002}},
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs)  OCR.DEMAND_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.SNOOP_NONE)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.DEMAND_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.DEMAND_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.SNOOP_MISS)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.DEMAND_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.HITM_OTHER_CORE OCR.DEMAND_RFO.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.HITM_OTHER_CORE OCR.DEMAND_RFO.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.ANY_SNOOP OCR.DEMAND_RFO.L3_MISS.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.ANY_SNOOP OCR.DEMAND_RFO.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.ANY_SNOOP)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.ANY_SNOOP)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.ANY_SNOOP)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.ANY_SNOOP)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_NONE)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.NO_SNOOP_NEEDED OCR.DEMAND_CODE_RD.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.NO_SNOOP_NEEDED OCR.DEMAND_CODE_RD.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_MISS)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.HITM_OTHER_CORE OCR.DEMAND_CODE_RD.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.HITM_OTHER_CORE OCR.DEMAND_CODE_RD.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.ANY_SNOOP OCR.DEMAND_CODE_RD.L3_HIT.ANY_SNOOP)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_HIT.ANY_SNOOP OCR.DEMAND_CODE_RD.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000004}},
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts all demand code reads  OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.SNOOP_NONE)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.NO_SNOOP_NEEDED OCR.DEMAND_CODE_RD.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.NO_SNOOP_NEEDED OCR.DEMAND_CODE_RD.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.SNOOP_MISS)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.DEMAND_CODE_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.HITM_OTHER_CORE OCR.DEMAND_CODE_RD.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.HITM_OTHER_CORE OCR.DEMAND_CODE_RD.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.ANY_SNOOP OCR.DEMAND_CODE_RD.L3_MISS.ANY_SNOOP)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.ANY_SNOOP OCR.DEMAND_CODE_RD.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.SNOOP_NONE)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L2_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L2_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.SNOOP_MISS)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.PF_L2_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.PF_L2_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.ANY_SNOOP OCR.PF_L2_DATA_RD.L3_HIT.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_HIT.ANY_SNOOP OCR.PF_L2_DATA_RD.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000010}},
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads  OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.SNOOP_NONE)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L2_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L2_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.SNOOP_MISS)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L2_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.PF_L2_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.PF_L2_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.ANY_SNOOP OCR.PF_L2_DATA_RD.L3_MISS.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.ANY_SNOOP OCR.PF_L2_DATA_RD.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L2_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L2_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.SNOOP_MISS)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.HITM_OTHER_CORE OCR.PF_L2_RFO.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.HITM_OTHER_CORE OCR.PF_L2_RFO.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.ANY_SNOOP OCR.PF_L2_RFO.L3_HIT.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_HIT.ANY_SNOOP OCR.PF_L2_RFO.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs  OCR.PF_L2_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L2_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L2_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.SNOOP_MISS)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L2_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.HITM_OTHER_CORE OCR.PF_L2_RFO.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.HITM_OTHER_CORE OCR.PF_L2_RFO.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.ANY_SNOOP OCR.PF_L2_RFO.L3_MISS.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.ANY_SNOOP OCR.PF_L2_RFO.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L3_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L3_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.SNOOP_MISS)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.PF_L3_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.PF_L3_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.ANY_SNOOP OCR.PF_L3_DATA_RD.L3_HIT.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_HIT.ANY_SNOOP OCR.PF_L3_DATA_RD.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads  OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L3_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L3_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.SNOOP_MISS)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L3_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.PF_L3_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.PF_L3_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.ANY_SNOOP OCR.PF_L3_DATA_RD.L3_MISS.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.ANY_SNOOP OCR.PF_L3_DATA_RD.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L3_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L3_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.SNOOP_MISS)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.HITM_OTHER_CORE OCR.PF_L3_RFO.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.HITM_OTHER_CORE OCR.PF_L3_RFO.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.ANY_SNOOP OCR.PF_L3_RFO.L3_HIT.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_HIT.ANY_SNOOP OCR.PF_L3_RFO.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs  OCR.PF_L3_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L3_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L3_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.SNOOP_MISS)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L3_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.HITM_OTHER_CORE OCR.PF_L3_RFO.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.HITM_OTHER_CORE OCR.PF_L3_RFO.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.ANY_SNOOP OCR.PF_L3_RFO.L3_MISS.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.ANY_SNOOP OCR.PF_L3_RFO.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.SNOOP_NONE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L1D_AND_SW.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.NO_SNOOP_NEEDED OCR.PF_L1D_AND_SW.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.SNOOP_MISS)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_FWD OCR.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.HITM_OTHER_CORE OCR.PF_L1D_AND_SW.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.HITM_OTHER_CORE OCR.PF_L1D_AND_SW.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.ANY_SNOOP OCR.PF_L1D_AND_SW.L3_HIT.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_HIT.ANY_SNOOP OCR.PF_L1D_AND_SW.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests  OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.SNOOP_NONE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L1D_AND_SW.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.NO_SNOOP_NEEDED OCR.PF_L1D_AND_SW.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.SNOOP_MISS)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_FWD OCR.PF_L1D_AND_SW.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.HITM_OTHER_CORE OCR.PF_L1D_AND_SW.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.HITM_OTHER_CORE OCR.PF_L1D_AND_SW.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.ANY_SNOOP OCR.PF_L1D_AND_SW.L3_MISS.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.ANY_SNOOP OCR.PF_L1D_AND_SW.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80028000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100028000}},
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200028000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400028000}},
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800028000}},
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000028000}},
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80028000}},
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.ANY_SNOOP)",
      R"(Counts any other requests  OCR.OTHER.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80048000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100048000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200048000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400048000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800048000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000048000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.HITM_OTHER_CORE)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80048000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.ANY_SNOOP)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80088000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100088000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200088000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400088000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800088000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000088000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.HITM_OTHER_CORE)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80088000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.ANY_SNOOP)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80108000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100108000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200108000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400108000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800108000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000108000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.HITM_OTHER_CORE)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80108000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.ANY_SNOOP)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80208000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100208000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200208000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400208000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800208000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000208000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.HITM_OTHER_CORE)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80208000}},
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.ANY_SNOOP)",
      R"(Counts any other requests  OCR.OTHER.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C8000}},
      R"(Counts any other requests OCR.OTHER.L3_HIT.SNOOP_NONE)",
      R"(Counts any other requests OCR.OTHER.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C8000}},
      R"(Counts any other requests OCR.OTHER.L3_HIT.NO_SNOOP_NEEDED OCR.OTHER.L3_HIT.NO_SNOOP_NEEDED)",
      R"(Counts any other requests OCR.OTHER.L3_HIT.NO_SNOOP_NEEDED OCR.OTHER.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C8000}},
      R"(Counts any other requests OCR.OTHER.L3_HIT.SNOOP_MISS)",
      R"(Counts any other requests OCR.OTHER.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C8000}},
      R"(Counts any other requests OCR.OTHER.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.OTHER.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests OCR.OTHER.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.OTHER.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C8000}},
      R"(Counts any other requests OCR.OTHER.L3_HIT.HIT_OTHER_CORE_FWD OCR.OTHER.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests OCR.OTHER.L3_HIT.HIT_OTHER_CORE_FWD OCR.OTHER.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C8000}},
      R"(Counts any other requests OCR.OTHER.L3_HIT.HITM_OTHER_CORE OCR.OTHER.L3_HIT.HITM_OTHER_CORE)",
      R"(Counts any other requests OCR.OTHER.L3_HIT.HITM_OTHER_CORE OCR.OTHER.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C8000}},
      R"(Counts any other requests OCR.OTHER.L3_HIT.ANY_SNOOP OCR.OTHER.L3_HIT.ANY_SNOOP)",
      R"(Counts any other requests OCR.OTHER.L3_HIT.ANY_SNOOP OCR.OTHER.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84008000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204008000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90008000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210008000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90008000}},
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(Counts any other requests  OCR.OTHER.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.SNOOP_NONE)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.NO_SNOOP_NEEDED OCR.OTHER.L3_MISS.NO_SNOOP_NEEDED)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.NO_SNOOP_NEEDED OCR.OTHER.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.SNOOP_MISS)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.OTHER.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.OTHER.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.HIT_OTHER_CORE_FWD OCR.OTHER.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.HIT_OTHER_CORE_FWD OCR.OTHER.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.HITM_OTHER_CORE OCR.OTHER.L3_MISS.HITM_OTHER_CORE)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.HITM_OTHER_CORE OCR.OTHER.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.ANY_SNOOP OCR.OTHER.L3_MISS.ANY_SNOOP)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.ANY_SNOOP OCR.OTHER.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020490}},
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020490}},
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020490}},
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020490}},
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020490}},
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020490}},
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020490}},
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_PF_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_M.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_E.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_S.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT_F.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_NONE OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_NONE OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_MISS OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_MISS OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_NONE OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_NONE OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_MISS OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_MISS)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_MISS OCR.ALL_PF_DATA_RD.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020120}},
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020120}},
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020120}},
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020120}},
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020120}},
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020120}},
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_PF_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_PF_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020120}},
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_PF_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_PF_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_M.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_M.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_M.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_HIT_M.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_M.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_M.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_HIT_M.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_E.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_E.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_E.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_HIT_E.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_E.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_E.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_HIT_E.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_S.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_S.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_S.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_HIT_S.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_S.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_S.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_HIT_S.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_F.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_F.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_F.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_HIT_F.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200120}},
      R"(OCR.ALL_PF_RFO.L3_HIT_F.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_F.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_HIT_F.ANY_SNOOP  OCR.ALL_PF_RFO.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.SNOOP_NONE OCR.ALL_PF_RFO.L3_HIT.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_HIT.SNOOP_NONE OCR.ALL_PF_RFO.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.SNOOP_MISS OCR.ALL_PF_RFO.L3_HIT.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_HIT.SNOOP_MISS OCR.ALL_PF_RFO.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.ANY_SNOOP OCR.ALL_PF_RFO.L3_HIT.ANY_SNOOP OCR.ALL_PF_RFO.L3_HIT.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_HIT.ANY_SNOOP OCR.ALL_PF_RFO.L3_HIT.ANY_SNOOP OCR.ALL_PF_RFO.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_PF_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.SNOOP_NONE OCR.ALL_PF_RFO.L3_MISS.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.L3_MISS.SNOOP_NONE OCR.ALL_PF_RFO.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_PF_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_PF_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.SNOOP_MISS OCR.ALL_PF_RFO.L3_MISS.SNOOP_MISS)",
      R"(OCR.ALL_PF_RFO.L3_MISS.SNOOP_MISS OCR.ALL_PF_RFO.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_PF_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_MISS.HITM_OTHER_CORE)",
      R"(OCR.ALL_PF_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_PF_RFO.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020491}},
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020491}},
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020491}},
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020491}},
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020491}},
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020491}},
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_DATA_RD.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020491}},
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_DATA_RD.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_M.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_M.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_M.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_HIT_M.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_M.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_HIT_M.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_E.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_E.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_E.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_HIT_E.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_E.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_HIT_E.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_S.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_S.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_S.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_HIT_S.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_S.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_HIT_S.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_F.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_F.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_F.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_HIT_F.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200491}},
      R"(OCR.ALL_DATA_RD.L3_HIT_F.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_HIT_F.ANY_SNOOP  OCR.ALL_DATA_RD.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.SNOOP_NONE OCR.ALL_DATA_RD.L3_HIT.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_HIT.SNOOP_NONE OCR.ALL_DATA_RD.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.SNOOP_MISS OCR.ALL_DATA_RD.L3_HIT.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_HIT.SNOOP_MISS OCR.ALL_DATA_RD.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_DATA_RD.L3_HIT.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_DATA_RD.L3_HIT.ANY_SNOOP OCR.ALL_DATA_RD.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_DATA_RD.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.SNOOP_NONE OCR.ALL_DATA_RD.L3_MISS.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.L3_MISS.SNOOP_NONE OCR.ALL_DATA_RD.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_DATA_RD.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.SNOOP_MISS OCR.ALL_DATA_RD.L3_MISS.SNOOP_MISS)",
      R"(OCR.ALL_DATA_RD.L3_MISS.SNOOP_MISS OCR.ALL_DATA_RD.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_DATA_RD.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      R"(OCR.ALL_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_MISS.HITM_OTHER_CORE OCR.ALL_DATA_RD.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_DATA_RD.L3_MISS.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_DATA_RD.L3_MISS.ANY_SNOOP OCR.ALL_DATA_RD.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80020122}},
      R"(OCR.ALL_RFO.SUPPLIER_NONE.SNOOP_NONE)",
      R"(OCR.ALL_RFO.SUPPLIER_NONE.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100020122}},
      R"(OCR.ALL_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_RFO.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200020122}},
      R"(OCR.ALL_RFO.SUPPLIER_NONE.SNOOP_MISS)",
      R"(OCR.ALL_RFO.SUPPLIER_NONE.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400020122}},
      R"(OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800020122}},
      R"(OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000020122}},
      R"(OCR.ALL_RFO.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_RFO.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80020122}},
      R"(OCR.ALL_RFO.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      R"(OCR.ALL_RFO.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_RFO.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80040122}},
      R"(OCR.ALL_RFO.L3_HIT_M.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_HIT_M.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100040122}},
      R"(OCR.ALL_RFO.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200040122}},
      R"(OCR.ALL_RFO.L3_HIT_M.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_HIT_M.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400040122}},
      R"(OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800040122}},
      R"(OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000040122}},
      R"(OCR.ALL_RFO.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80040122}},
      R"(OCR.ALL_RFO.L3_HIT_M.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_M.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_HIT_M.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80080122}},
      R"(OCR.ALL_RFO.L3_HIT_E.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_HIT_E.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100080122}},
      R"(OCR.ALL_RFO.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200080122}},
      R"(OCR.ALL_RFO.L3_HIT_E.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_HIT_E.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400080122}},
      R"(OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800080122}},
      R"(OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080122}},
      R"(OCR.ALL_RFO.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80080122}},
      R"(OCR.ALL_RFO.L3_HIT_E.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_E.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_HIT_E.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80100122}},
      R"(OCR.ALL_RFO.L3_HIT_S.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_HIT_S.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100100122}},
      R"(OCR.ALL_RFO.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200100122}},
      R"(OCR.ALL_RFO.L3_HIT_S.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_HIT_S.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400100122}},
      R"(OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800100122}},
      R"(OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000100122}},
      R"(OCR.ALL_RFO.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80100122}},
      R"(OCR.ALL_RFO.L3_HIT_S.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_S.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_HIT_S.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80200122}},
      R"(OCR.ALL_RFO.L3_HIT_F.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_HIT_F.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100200122}},
      R"(OCR.ALL_RFO.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x200200122}},
      R"(OCR.ALL_RFO.L3_HIT_F.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_HIT_F.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x400200122}},
      R"(OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800200122}},
      R"(OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000200122}},
      R"(OCR.ALL_RFO.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_RFO.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80200122}},
      R"(OCR.ALL_RFO.L3_HIT_F.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_F.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_HIT_F.ANY_SNOOP  OCR.ALL_RFO.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C0122}},
      R"(OCR.ALL_RFO.L3_HIT.SNOOP_NONE OCR.ALL_RFO.L3_HIT.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_HIT.SNOOP_NONE OCR.ALL_RFO.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0122}},
      R"(OCR.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0122}},
      R"(OCR.ALL_RFO.L3_HIT.SNOOP_MISS OCR.ALL_RFO.L3_HIT.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_HIT.SNOOP_MISS OCR.ALL_RFO.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0122}},
      R"(OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0122}},
      R"(OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0122}},
      R"(OCR.ALL_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_RFO.L3_HIT.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_RFO.L3_HIT.HITM_OTHER_CORE OCR.ALL_RFO.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0122}},
      R"(OCR.ALL_RFO.L3_HIT.ANY_SNOOP OCR.ALL_RFO.L3_HIT.ANY_SNOOP OCR.ALL_RFO.L3_HIT.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_HIT.ANY_SNOOP OCR.ALL_RFO.L3_HIT.ANY_SNOOP OCR.ALL_RFO.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x84000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x104000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x204000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x404000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F84000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x90000122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x110000122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x210000122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x410000122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x810000122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010000122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F90000122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_RFO.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC000122}},
      R"(OCR.ALL_RFO.L3_MISS.SNOOP_NONE OCR.ALL_RFO.L3_MISS.SNOOP_NONE)",
      R"(OCR.ALL_RFO.L3_MISS.SNOOP_NONE OCR.ALL_RFO.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C000122}},
      R"(OCR.ALL_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_RFO.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C000122}},
      R"(OCR.ALL_RFO.L3_MISS.SNOOP_MISS OCR.ALL_RFO.L3_MISS.SNOOP_MISS)",
      R"(OCR.ALL_RFO.L3_MISS.SNOOP_MISS OCR.ALL_RFO.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C000122}},
      R"(OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C000122}},
      R"(OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_RFO.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C000122}},
      R"(OCR.ALL_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_RFO.L3_MISS.HITM_OTHER_CORE)",
      R"(OCR.ALL_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_RFO.L3_MISS.HITM_OTHER_CORE OCR.ALL_RFO.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC000122}},
      R"(OCR.ALL_RFO.L3_MISS.ANY_SNOOP OCR.ALL_RFO.L3_MISS.ANY_SNOOP OCR.ALL_RFO.L3_MISS.ANY_SNOOP)",
      R"(OCR.ALL_RFO.L3_MISS.ANY_SNOOP OCR.ALL_RFO.L3_MISS.ANY_SNOOP OCR.ALL_RFO.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.SUPPLIER_NONE.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800207F7}},
      R"(OCR.ALL_READS.SUPPLIER_NONE.SNOOP_NONE)",
      R"(OCR.ALL_READS.SUPPLIER_NONE.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.SUPPLIER_NONE.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1000207F7}},
      R"(OCR.ALL_READS.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_READS.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.SUPPLIER_NONE.NO_SNOOP_NEEDED  OCR.ALL_READS.SUPPLIER_NONE.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.SUPPLIER_NONE.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2000207F7}},
      R"(OCR.ALL_READS.SUPPLIER_NONE.SNOOP_MISS)",
      R"(OCR.ALL_READS.SUPPLIER_NONE.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4000207F7}},
      R"(OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8000207F7}},
      R"(OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_FWD  OCR.ALL_READS.SUPPLIER_NONE.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.SUPPLIER_NONE.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10000207F7}},
      R"(OCR.ALL_READS.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_READS.SUPPLIER_NONE.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.SUPPLIER_NONE.HITM_OTHER_CORE  OCR.ALL_READS.SUPPLIER_NONE.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.SUPPLIER_NONE.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F800207F7}},
      R"(OCR.ALL_READS.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_READS.SUPPLIER_NONE.ANY_SNOOP)",
      R"(OCR.ALL_READS.SUPPLIER_NONE.ANY_SNOOP  OCR.ALL_READS.SUPPLIER_NONE.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_M.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800407F7}},
      R"(OCR.ALL_READS.L3_HIT_M.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_HIT_M.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_M.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1000407F7}},
      R"(OCR.ALL_READS.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_M.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_HIT_M.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_M.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_M.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2000407F7}},
      R"(OCR.ALL_READS.L3_HIT_M.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_HIT_M.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4000407F7}},
      R"(OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8000407F7}},
      R"(OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_M.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_M.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10000407F7}},
      R"(OCR.ALL_READS.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_M.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_HIT_M.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_M.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_M.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F800407F7}},
      R"(OCR.ALL_READS.L3_HIT_M.ANY_SNOOP  OCR.ALL_READS.L3_HIT_M.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_HIT_M.ANY_SNOOP  OCR.ALL_READS.L3_HIT_M.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_E.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x800807F7}},
      R"(OCR.ALL_READS.L3_HIT_E.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_HIT_E.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_E.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1000807F7}},
      R"(OCR.ALL_READS.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_E.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_HIT_E.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_E.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_E.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2000807F7}},
      R"(OCR.ALL_READS.L3_HIT_E.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_HIT_E.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4000807F7}},
      R"(OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8000807F7}},
      R"(OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_E.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_E.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10000807F7}},
      R"(OCR.ALL_READS.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_E.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_HIT_E.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_E.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_E.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F800807F7}},
      R"(OCR.ALL_READS.L3_HIT_E.ANY_SNOOP  OCR.ALL_READS.L3_HIT_E.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_HIT_E.ANY_SNOOP  OCR.ALL_READS.L3_HIT_E.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_S.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x801007F7}},
      R"(OCR.ALL_READS.L3_HIT_S.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_HIT_S.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_S.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1001007F7}},
      R"(OCR.ALL_READS.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_S.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_HIT_S.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_S.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_S.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2001007F7}},
      R"(OCR.ALL_READS.L3_HIT_S.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_HIT_S.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4001007F7}},
      R"(OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8001007F7}},
      R"(OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_S.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_S.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10001007F7}},
      R"(OCR.ALL_READS.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_S.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_HIT_S.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_S.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_S.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F801007F7}},
      R"(OCR.ALL_READS.L3_HIT_S.ANY_SNOOP  OCR.ALL_READS.L3_HIT_S.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_HIT_S.ANY_SNOOP  OCR.ALL_READS.L3_HIT_S.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_F.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x802007F7}},
      R"(OCR.ALL_READS.L3_HIT_F.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_HIT_F.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_F.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1002007F7}},
      R"(OCR.ALL_READS.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_F.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_HIT_F.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_HIT_F.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_F.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2002007F7}},
      R"(OCR.ALL_READS.L3_HIT_F.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_HIT_F.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4002007F7}},
      R"(OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8002007F7}},
      R"(OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_HIT_F.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_F.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10002007F7}},
      R"(OCR.ALL_READS.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_F.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_HIT_F.HITM_OTHER_CORE  OCR.ALL_READS.L3_HIT_F.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT_F.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F802007F7}},
      R"(OCR.ALL_READS.L3_HIT_F.ANY_SNOOP  OCR.ALL_READS.L3_HIT_F.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_HIT_F.ANY_SNOOP  OCR.ALL_READS.L3_HIT_F.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803C07F7}},
      R"(OCR.ALL_READS.L3_HIT.SNOOP_NONE OCR.ALL_READS.L3_HIT.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_HIT.SNOOP_NONE OCR.ALL_READS.L3_HIT.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C07F7}},
      R"(OCR.ALL_READS.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_READS.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_READS.L3_HIT.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_READS.L3_HIT.NO_SNOOP_NEEDED OCR.ALL_READS.L3_HIT.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C07F7}},
      R"(OCR.ALL_READS.L3_HIT.SNOOP_MISS OCR.ALL_READS.L3_HIT.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_HIT.SNOOP_MISS OCR.ALL_READS.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C07F7}},
      R"(OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C07F7}},
      R"(OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C07F7}},
      R"(OCR.ALL_READS.L3_HIT.HITM_OTHER_CORE OCR.ALL_READS.L3_HIT.HITM_OTHER_CORE OCR.ALL_READS.L3_HIT.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_HIT.HITM_OTHER_CORE OCR.ALL_READS.L3_HIT.HITM_OTHER_CORE OCR.ALL_READS.L3_HIT.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C07F7}},
      R"(OCR.ALL_READS.L3_HIT.ANY_SNOOP OCR.ALL_READS.L3_HIT.ANY_SNOOP OCR.ALL_READS.L3_HIT.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_HIT.ANY_SNOOP OCR.ALL_READS.L3_HIT.ANY_SNOOP OCR.ALL_READS.L3_HIT.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x840007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1040007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2040007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4040007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8040007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10040007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F840007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.ANY_SNOOP  OCR.ALL_READS.L3_MISS_LOCAL_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x900007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1100007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2100007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4100007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8100007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10100007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F900007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP  OCR.ALL_READS.L3_MISS_REMOTE_HOP1_DRAM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0xBC0007F7}},
      R"(OCR.ALL_READS.L3_MISS.SNOOP_NONE OCR.ALL_READS.L3_MISS.SNOOP_NONE)",
      R"(OCR.ALL_READS.L3_MISS.SNOOP_NONE OCR.ALL_READS.L3_MISS.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x13C0007F7}},
      R"(OCR.ALL_READS.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_READS.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_READS.L3_MISS.NO_SNOOP_NEEDED)",
      R"(OCR.ALL_READS.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_READS.L3_MISS.NO_SNOOP_NEEDED OCR.ALL_READS.L3_MISS.NO_SNOOP_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x23C0007F7}},
      R"(OCR.ALL_READS.L3_MISS.SNOOP_MISS OCR.ALL_READS.L3_MISS.SNOOP_MISS)",
      R"(OCR.ALL_READS.L3_MISS.SNOOP_MISS OCR.ALL_READS.L3_MISS.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x43C0007F7}},
      R"(OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      R"(OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_NO_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83C0007F7}},
      R"(OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_FWD)",
      R"(OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_FWD OCR.ALL_READS.L3_MISS.HIT_OTHER_CORE_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103C0007F7}},
      R"(OCR.ALL_READS.L3_MISS.HITM_OTHER_CORE OCR.ALL_READS.L3_MISS.HITM_OTHER_CORE OCR.ALL_READS.L3_MISS.HITM_OTHER_CORE)",
      R"(OCR.ALL_READS.L3_MISS.HITM_OTHER_CORE OCR.ALL_READS.L3_MISS.HITM_OTHER_CORE OCR.ALL_READS.L3_MISS.HITM_OTHER_CORE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBC0007F7}},
      R"(OCR.ALL_READS.L3_MISS.ANY_SNOOP OCR.ALL_READS.L3_MISS.ANY_SNOOP OCR.ALL_READS.L3_MISS.ANY_SNOOP)",
      R"(OCR.ALL_READS.L3_MISS.ANY_SNOOP OCR.ALL_READS.L3_MISS.ANY_SNOOP OCR.ALL_READS.L3_MISS.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10001}},
      R"(Counts demand data reads have any response type.)",
      R"(Counts demand data reads have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0001}},
      R"(Counts demand data reads)",
      R"(Counts demand data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10002}},
      R"(Counts all demand data writes (RFOs) have any response type.)",
      R"(Counts all demand data writes (RFOs) have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0002}},
      R"(Counts all demand data writes (RFOs))",
      R"(Counts all demand data writes (RFOs))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10004}},
      R"(Counts all demand code reads have any response type.)",
      R"(Counts all demand code reads have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0004}},
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10010}},
      R"(Counts prefetch (that bring data to L2) data reads have any response type.)",
      R"(Counts prefetch (that bring data to L2) data reads have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0010}},
      R"(Counts prefetch (that bring data to L2) data reads)",
      R"(Counts prefetch (that bring data to L2) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10020}},
      R"(Counts all prefetch (that bring data to L2) RFOs have any response type.)",
      R"(Counts all prefetch (that bring data to L2) RFOs have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      R"(Counts all prefetch (that bring data to L2) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads have any response type.)",
      R"(Counts all prefetch (that bring data to LLC only) data reads have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      R"(Counts all prefetch (that bring data to LLC only) data reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs have any response type.)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests have any response type.)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x18000}},
      R"(Counts any other requests have any response type.)",
      R"(Counts any other requests have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B808000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts any other requests OCR.OTHER.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604008000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(Counts any other requests OCR.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C8000}},
      R"(Counts any other requests)",
      R"(Counts any other requests)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10490}},
      R"(OCR.ALL_PF_DATA_RD.ANY_RESPONSE have any response type.)",
      R"(OCR.ALL_PF_DATA_RD.ANY_RESPONSE have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0490}},
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD)",
      R"(OCR.ALL_PF_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10120}},
      R"(OCR.ALL_PF_RFO.ANY_RESPONSE have any response type.)",
      R"(OCR.ALL_PF_RFO.ANY_RESPONSE have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000120}},
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0120}},
      R"(OCR.ALL_PF_RFO.L3_HIT.SNOOP_HIT_WITH_FWD)",
      R"(OCR.ALL_PF_RFO.L3_HIT.SNOOP_HIT_WITH_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10491}},
      R"(OCR.ALL_DATA_RD.ANY_RESPONSE have any response type.)",
      R"(OCR.ALL_DATA_RD.ANY_RESPONSE have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000491}},
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0491}},
      R"(OCR.ALL_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD)",
      R"(OCR.ALL_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10122}},
      R"(OCR.ALL_RFO.ANY_RESPONSE have any response type.)",
      R"(OCR.ALL_RFO.ANY_RESPONSE have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B800122}},
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000122}},
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C0122}},
      R"(OCR.ALL_RFO.L3_HIT.SNOOP_HIT_WITH_FWD)",
      R"(OCR.ALL_RFO.L3_HIT.SNOOP_HIT_WITH_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x107F7}},
      R"(OCR.ALL_READS.ANY_RESPONSE have any response type.)",
      R"(OCR.ALL_READS.ANY_RESPONSE have any response type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63B8007F7}},
      R"(OCR.ALL_READS.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_READS.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_READS.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_READS.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x6040007F7}},
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      R"(OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD OCR.ALL_READS.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8007C07F7}},
      R"(OCR.ALL_READS.L3_HIT.SNOOP_HIT_WITH_FWD)",
      R"(OCR.ALL_READS.L3_HIT.SNOOP_HIT_WITH_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.REMOTE_HITM)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.REMOTE_HITM)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.REMOTE_HITM)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.REMOTE_HITM)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.REMOTE_HITM)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.REMOTE_HITM)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.REMOTE_HITM)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.REMOTE_HITM)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC08000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.REMOTE_HITM)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HITM OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HITM)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HITM OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.REMOTE_HITM OCR.ALL_PF_RFO.L3_MISS.REMOTE_HITM)",
      R"(OCR.ALL_PF_RFO.L3_MISS.REMOTE_HITM OCR.ALL_PF_RFO.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.REMOTE_HITM OCR.ALL_DATA_RD.L3_MISS.REMOTE_HITM)",
      R"(OCR.ALL_DATA_RD.L3_MISS.REMOTE_HITM OCR.ALL_DATA_RD.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC00122}},
      R"(OCR.ALL_RFO.L3_MISS.REMOTE_HITM OCR.ALL_RFO.L3_MISS.REMOTE_HITM)",
      R"(OCR.ALL_RFO.L3_MISS.REMOTE_HITM OCR.ALL_RFO.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x103FC007F7}},
      R"(OCR.ALL_READS.L3_MISS.REMOTE_HITM OCR.ALL_READS.L3_MISS.REMOTE_HITM)",
      R"(OCR.ALL_READS.L3_MISS.REMOTE_HITM OCR.ALL_READS.L3_MISS.REMOTE_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC08000}},
      R"(Counts any other requests OCR.OTHER.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(Counts any other requests OCR.OTHER.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00490}},
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_PF_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00120}},
      R"(OCR.ALL_PF_RFO.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_PF_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(OCR.ALL_PF_RFO.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_PF_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00491}},
      R"(OCR.ALL_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(OCR.ALL_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC00122}},
      R"(OCR.ALL_RFO.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(OCR.ALL_RFO.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_RFO.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.L3_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x83FC007F7}},
      R"(OCR.ALL_READS.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_READS.L3_MISS.REMOTE_HIT_FORWARD)",
      R"(OCR.ALL_READS.L3_MISS.REMOTE_HIT_FORWARD OCR.ALL_READS.L3_MISS.REMOTE_HIT_FORWARD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100408000}},
      R"(Counts any other requests OCR.OTHER.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(Counts any other requests OCR.OTHER.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80408000}},
      R"(Counts any other requests OCR.OTHER.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(Counts any other requests OCR.OTHER.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400490}},
      R"(OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400490}},
      R"(OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400120}},
      R"(OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400120}},
      R"(OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400491}},
      R"(OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400491}},
      R"(OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x100400122}},
      R"(OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x80400122}},
      R"(OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1004007F7}},
      R"(OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      R"(OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NONE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x804007F7}},
      R"(OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      R"(OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NONE OCR.ALL_READS.PMM_HIT_LOCAL_PMM.SNOOP_NONE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400001}},
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts demand data reads OCR.DEMAND_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400002}},
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts all demand data writes (RFOs) OCR.DEMAND_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400004}},
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts all demand code reads OCR.DEMAND_CODE_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400010}},
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts prefetch (that bring data to L2) data reads OCR.PF_L2_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400020}},
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to L2) RFOs OCR.PF_L2_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) data reads OCR.PF_L3_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs OCR.PF_L3_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400400}},
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts L1 data cache hardware prefetch requests and software prefetch requests OCR.PF_L1D_AND_SW.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80408000}},
      R"(Counts any other requests OCR.OTHER.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(Counts any other requests OCR.OTHER.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400490}},
      R"(OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_PF_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400120}},
      R"(OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_PF_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400491}},
      R"(OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_DATA_RD.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F80400122}},
      R"(OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_RFO.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_READS.PMM_HIT_LOCAL_PMM.ANY_SNOOP",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F804007F7}},
      R"(OCR.ALL_READS.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_READS.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      R"(OCR.ALL_READS.PMM_HIT_LOCAL_PMM.ANY_SNOOP OCR.ALL_READS.PMM_HIT_LOCAL_PMM.ANY_SNOOP)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace cascadelakex_core
} // namespace facebook::hbt::perf_event::generated
