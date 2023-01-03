// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace broadwellx_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from broadwellx_core.json (372 events).

    Supported SKUs:
        - Arch: x86, Model: BDX id: 79
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired from execution.)",
      R"(This event counts the number of instructions retired from execution. For instructions that consist of multiple micro-ops, this event counts the retirement of the last micro-op of the instruction. Counting continues during hardware interrupts, traps, and inside interrupt handlers. 
Notes: INST_RETIRED.ANY is counted by a designated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. INST_RETIRED.ANY_P is counted by a programmable counter and it is an architectural performance event. 
Counting: Faulting executions of GETSEC/VM entry/VM Exit/MWait will not count as retired instructions.)",
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
      R"(This event counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events.)",
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
      R"(This event counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. This event has a constant ratio with the CPU_CLK_UNHALTED.REF_XCLK event. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. 
Note: On all current platforms this event stops counting during 'throttling (TM)' states duty off periods the processor is 'halted'.  This event is clocked by base clock (100 Mhz) on Sandy Bridge. The counter update is done at a lower clock rate then the core clock the overflow status bit for this counter may appear 'sticky'.  After the counter has overflowed and software clears the overflow status bit and resets the counter to less than MAX. The reset value to the counter is not clocked immediately so the overflow status bit will flip 'high (1)' and generate another PMI (if enabled) after which the reset value gets clocked into the counter. Therefore, software will get the interrupt, read the overflow status bit '1 for bit 34 while the counter value is less than MAX. Software should ignore this case.)",
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
      R"(Cases when loads get true Block-on-Store blocking code preventing store forwarding)",
      R"(This event counts how many times the load operation got the true Block-on-Store blocking code preventing store forwarding. This includes cases when:
 - preceding store conflicts with the load (incomplete overlap);
 - store forwarding is impossible due to u-arch limitations;
 - preceding lock RMW operations are not forwarded;
 - store has the no-forward bit set (uncacheable/page-split/masked stores);
 - all-blocking stores are used (mostly, fences and port I/O);
and others.
The most common case is a load blocked due to its address range overlapping with a preceding smaller uncompleted store. Note: This event does not take into account cases of out-of-SW-control (for example, SbTailHit), unknown physical STA, and cases of blocking loads on store due to being non-WB memory type or a lock. These cases are covered by other events.
See the table of not supported store forwards in the Optimization Guide.)",
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
      R"(This event counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.)",
      R"(This event counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.)",
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
      R"(This event counts speculative cache-line split load uops dispatched to the L1 cache.)",
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
      R"(This event counts speculative cache line split store-address (STA) uops dispatched to the L1 cache.)",
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
      R"(False dependencies in MOB due to partial compare)",
      R"(This event counts false dependencies in MOB when the partial comparison upon loose net check and dependency was resolved by the Enhanced Loose net mechanism. This may not result in high performance penalties. Loose net checks can fail when loads and stores are 4k aliased.)",
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
      R"(This event counts load misses in all DTLB levels that cause page walks of any page size (4K/2M/4M/1G).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes (4K).)",
      R"(This event counts load misses in all DTLB levels that cause a completed page walk (4K page size). The page walk can end with or without a fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes (2M/4M).)",
      R"(This event counts load misses in all DTLB levels that cause a completed page walk (2M and 4M page sizes). The page walk can end with or without a fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Load miss in all TLB levels causes a page walk that completes. (1G))",
      R"(This event counts load misses in all DTLB levels that cause a completed page walk (1G  page size). The page walk can end with or without a fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes of any page size.)",
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes of any page size.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks)",
      R"(This event counts the number of cycles while PMH is busy with the page walk.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT_4K",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Load misses that miss the  DTLB and hit the STLB (4K).)",
      R"(Load misses that miss the  DTLB and hit the STLB (4K).)",
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
      R"(Load misses that miss the  DTLB and hit the STLB (2M).)",
      R"(Load misses that miss the  DTLB and hit the STLB (2M).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x60, .cmask = 0, .msr_values = {0}},
      R"(Load operations that miss the first DTLB level but hit the second and do not cause page walks.)",
      R"(Load operations that miss the first DTLB level but hit the second and do not cause page walks.)",
      2000003,
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
      R"(Cycles checkpoints in Resource Allocation Table (RAT) are recovering from JEClear or machine clear.)",
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
          .umask = 0x03,
          .any = true,
          .cmask = 1,
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
      "INT_MISC.RAT_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the thread)",
      R"(This event counts the number of cycles during which Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the current thread. This also includes the cycles during which the Allocator is serving another thread.)",
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
      R"(This event counts the number of Uops issued by the Resource Allocation Table (RAT) to the reservation station (RS).)",
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
      R"(This event counts cycles during which the Resource Allocation Table (RAT) does not issue any Uops to the reservation station (RS) for the current thread.)",
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
      R"(Number of flags-merge uops being allocated. Such uops considered perf sensitive
 added by GSR u-arch.)",
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
      "UOPS_ISSUED.SINGLE_MUL",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of Multiply packed/scalar single precision uops allocated.)",
      R"(Number of Multiply packed/scalar single precision uops allocated.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.FPU_DIV_ACTIVE",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when divider is busy executing divide operations)",
      R"(This event counts the number of the divide operations executed. Uses edge-detect and a cmask value of 1 on ARITH.FPU_DIV_ACTIVE to get the number of the divide operations executed.)",
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
      R"(This event counts the number of demand Data Read requests that miss L2 cache. Only not rejected loads are counted.)",
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
      R"(RFO requests that miss L2 cache.)",
      R"(RFO requests that miss L2 cache.)",
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
      R"(L2 cache misses when fetching instructions.)",
      R"(L2 cache misses when fetching instructions.)",
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
      R"(Demand requests that miss L2 cache.)",
      R"(Demand requests that miss L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.L2_PF_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(L2 prefetch requests that miss L2 cache)",
      R"(This event counts the number of requests from the L2 hardware prefetchers that miss L2 cache.)",
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
      R"(All requests that miss L2 cache.)",
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
      R"(Counts the number of demand Data Read requests, initiated by load instructions, that hit L2 cache.)",
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
      R"(RFO requests that hit L2 cache.)",
      R"(RFO requests that hit L2 cache.)",
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
      R"(L2 cache hits when fetching instructions, code reads.)",
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
      R"(This event counts the number of requests from the L2 hardware prefetchers that hit L2 cache. L3 prefetch new types.)",
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
      R"(This event counts the number of demand Data Read requests (including requests from L1D hardware prefetchers). These loads may hit or miss L2 cache. Only non rejected loads are counted.)",
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
      R"(This event counts the total number of RFO (read for ownership) requests to L2 cache. L2 RFO requests include both L1D demand RFO misses as well as L1D RFO prefetches.)",
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
      R"(This event counts the total number of L2 code requests.)",
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
      R"(Demand requests to L2 cache.)",
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
      R"(Requests from L2 hardware prefetchers)",
      R"(This event counts the total number of requests from the L2 hardware prefetchers.)",
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
      R"(All L2 requests.)",
      R"(All L2 requests.)",
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
      R"(This event counts the number of WB requests that hit L2 cache.)",
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
      R"(This event counts core-originated cacheable demand requests that miss the last level cache (LLC). Demand requests include loads, RFOs, and hardware prefetches from L1D, and instruction fetches from IFU.)",
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
      R"(This event counts core-originated cacheable demand requests that refer to the last level cache (LLC). Demand requests include loads, RFOs, and hardware prefetches from L1D, and instruction fetches from IFU.)",
      100003,
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
      "CPU_CLK_THREAD_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate))",
      R"(This is a fixed-frequency event programmed to general counters. It counts when the core is unhalted at 100 Mhz.)",
      100003,
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
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
      100003,
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
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate).)",
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
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
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
      "L1D_PEND_MISS.PENDING",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L1D miss oustandings duration in cycles)",
      R"(This event counts duration of L1D miss outstanding, that is each cycle number of Fill Buffers (FB) outstanding required by Demand Reads. FB either is held by demand loads, or it is held by non-demand loads and gets hit at least once by demand. The valid outstanding interval is defined until the FB deallocation by one of the following ways: from FB allocation, if FB is allocated by demand; from the demand Hit FB, if it is allocated by hardware or software prefetch.
Note: In the L1D, a Demand Read contains cacheable or noncacheable demand loads, including ones causing cache-line splits and reads due to page walks resulted from any request type.)",
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
      R"(This event counts duration of L1D miss outstanding in cycles.)",
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
      "DTLB_STORE_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause page walks)",
      R"(This event counts store misses in all DTLB levels that cause page walks of any page size (4K/2M/4M/1G).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Store miss in all TLB levels causes a page walk that completes. (4K))",
      R"(This event counts store misses in all DTLB levels that cause a completed page walk (4K page size). The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks (2M/4M))",
      R"(This event counts store misses in all DTLB levels that cause a completed page walk (2M and 4M page sizes). The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks (1G))",
      R"(This event counts store misses in all DTLB levels that cause a completed page walk (1G  page size). The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks.)",
      R"(Store misses in all DTLB levels that cause completed page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks)",
      R"(This event counts the number of cycles while PMH is busy with the page walk.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT_4K",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Store misses that miss the  DTLB and hit the STLB (4K).)",
      R"(Store misses that miss the  DTLB and hit the STLB (4K).)",
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
      R"(Store misses that miss the  DTLB and hit the STLB (2M).)",
      R"(Store misses that miss the  DTLB and hit the STLB (2M).)",
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
      R"(Store operations that miss the first TLB level but hit the second and do not cause page walks.)",
      R"(Store operations that miss the first TLB level but hit the second and do not cause page walks.)",
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
      R"(This event counts all not software-prefetch load dispatches that hit the fill buffer (FB) allocated for the software prefetch. It can also be incremented by some lock instructions. So it should only be used with profiling so that the locks can be excluded by asm inspection of the nearby instructions.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE.HW_PF",
      EventDef::Encoding{
          .code = 0x4C, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Not software-prefetch load dispatches that hit FB allocated for hardware prefetch)",
      R"(This event counts all not software-prefetch load dispatches that hit the fill buffer (FB) allocated for the hardware prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.WALK_CYCLES",
      EventDef::Encoding{
          .code = 0x4F, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycle count for an Extended Page table walk.)",
      R"(This event counts cycles for an extended page table walk. The Extended Page directory cache differs from standard TLB caches by the operating system that use it. Virtual machine operating systems use the extended page directory cache, while guest operating systems use the standard TLB caches.)",
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
      R"(This event counts L1D data line replacements including opportunistic replacements, and replacements that require stall-for-replace or block-for-replace.)",
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
      R"(Number of times a TSX line had a cache conflict)",
      R"(Number of times a TSX line had a cache conflict.)",
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
      R"(Number of times a TSX Abort was triggered due to an evicted line caused by a transaction overflow)",
      R"(Number of times a TSX Abort was triggered due to an evicted line caused by a transaction overflow.)",
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
      R"(Number of times a TSX Abort was triggered due to a non-release/commit store to lock)",
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
      R"(Number of times a TSX Abort was triggered due to commit but Lock Buffer not empty)",
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
      R"(Number of times a TSX Abort was triggered due to release/commit but data and address mismatch)",
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
      R"(Number of times a TSX Abort was triggered due to attempting an unsupported alignment from Lock Buffer)",
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
      R"(Number of times we could not allocate Lock Buffer)",
      R"(Number of times we could not allocate Lock Buffer.)",
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
      R"(Number of integer Move Elimination candidate uops that were eliminated.)",
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
      R"(Number of SIMD Move Elimination candidate uops that were eliminated.)",
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
      R"(Number of integer Move Elimination candidate uops that were not eliminated.)",
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
      R"(Number of SIMD Move Elimination candidate uops that were not eliminated.)",
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
      R"(This event counts the unhalted core cycles during which the thread is in the ring 0 privileged mode.)",
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
      R"(Number of intervals between processor halts while thread is in ring 0)",
      R"(This event counts when there is a transition from ring 1,2 or 3 to ring0.)",
      100007,
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
      R"(This event counts unhalted core cycles during which the thread is in rings 1, 2, or 3.)",
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
      R"(Unfriendly TSX abort triggered by  a vzeroupper instruction.)",
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
      R"(This event counts cycles during which the reservation station (RS) is empty for the thread.
Note: In ST-mode, not active thread should drive 0. This is usually caused by severely costly branch mispredictions, or allocator/FE issues.)",
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
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding Demand Data Read transactions in uncore queue.)",
      R"(This event counts the number of offcore outstanding Demand Data Read transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor. See the corresponding Umask under OFFCORE_REQUESTS.
Note: A prefetch promoted to Demand is counted from the promotion point.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM76)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore)",
      R"(This event counts cycles when offcore outstanding Demand Data Read transactions are present in the super queue (SQ). A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM76)"));

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
      R"(BDM76)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle)",
      R"(This event counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The Offcore outstanding state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM76)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding RFO store transactions in SuperQueue (SQ), queue to uncore)",
      R"(This event counts the number of offcore outstanding RFO (store) transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM76)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 1, .msr_values = {0}},
      R"(Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle)",
      R"(This event counts the number of offcore outstanding demand rfo Reads transactions in the super queue every cycle. The Offcore outstanding state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM76)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore)",
      R"(This event counts the number of offcore outstanding cacheable Core Data Read transactions in the super queue every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM76)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore)",
      R"(This event counts cycles when offcore outstanding cacheable Core Data Read transactions are present in the super queue. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM76)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOCK_CYCLES.SPLIT_LOCK_UC_LOCK_DURATION",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when L1 and L2 are locked due to UC or split lock)",
      R"(This event counts cycles in which the L1 and L2 are locked due to a UC lock or split lock. A lock is asserted in case of locked memory access, due to noncacheable memory, locked operation that spans two cache lines, or a page walk from the noncacheable page table. L1D and L2 locks have a very high performance penalty and it is highly recommended to avoid such access.)",
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
      R"(This event counts the number of cycles when the L1D is locked. It is a superset of the 0x1 mask (BUS_LOCK_CLOCKS.BUS_LOCK_DURATION).)",
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
      R"(This counts the number of cycles that the instruction decoder queue is empty and can indicate that the application may be bound in the front end.  It does not determine whether there are uops being delivered to the Alloc stage since uops can be delivered by bypass skipping the Instruction Decode Queue (IDQ) when it is empty.)",
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
      R"(This event counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
      R"(This event counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ.)",
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
      R"(This event counts the number of uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.)",
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
      R"(This event counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.)",
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
      R"(Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(This event counts the number of uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ.)",
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
      R"(This event counts cycles during which uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ.)",
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
      R"(Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequenser (MS) is busy)",
      R"(This event counts the number of deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ.)",
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
      R"(This event counts the number of cycles 4  uops were  delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.)",
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
      R"(This event counts the number of cycles  uops were  delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.)",
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
      R"(This event counts the number of uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while the Microcode Sequenser (MS) is busy. Counting includes uops that may bypass the IDQ.)",
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
      R"(This event counts the number of cycles 4  uops were  delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
      R"(This event counts the number of cycles  uops were delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
      R"(This event counts the total number of uops delivered to Instruction Decode Queue (IDQ) while the Microcode Sequenser (MS) is busy. Counting includes uops that may bypass the IDQ. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.)",
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
      R"(This event counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequenser (MS) is busy. Counting includes uops that may bypass the IDQ. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.)",
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
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_ALL_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x3C, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path)",
      R"(This event counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
      R"(Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches)",
      R"(This event counts the number of both cacheable and noncacheable Instruction Cache, Streaming Buffer and Victim Cache Reads including UC fetches.)",
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
      R"(This event counts the number of instruction cache, streaming buffer and victim cache misses. Counting includes UC accesses.)",
      200003,
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
      R"(This event counts cycles during which the demand fetch waits for data (wfdM104H) from L2 or iSB (opportunistic hit).)",
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
      R"(This event counts store misses in all DTLB levels that cause page walks of any page size (4K/2M/4M/1G).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Code miss in all TLB levels causes a page walk that completes. (4K))",
      R"(This event counts store misses in all DTLB levels that cause a completed page walk (4K page size). The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Code miss in all TLB levels causes a page walk that completes. (2M/4M))",
      R"(This event counts store misses in all DTLB levels that cause a completed page walk (2M and 4M page sizes). The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Store miss in all TLB levels causes a page walk that completes. (1G))",
      R"(This event counts store misses in all DTLB levels that cause a completed page walk (1G  page size). The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x0e, .cmask = 0, .msr_values = {0}},
      R"(Misses in all ITLB levels that cause completed page walks.)",
      R"(Misses in all ITLB levels that cause completed page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks)",
      R"(This event counts the number of cycles while PMH is busy with the page walk.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT_4K",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Core misses that miss the  DTLB and hit the STLB (4K).)",
      R"(Core misses that miss the  DTLB and hit the STLB (4K).)",
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
      R"(Code misses that miss the  DTLB and hit the STLB (2M).)",
      R"(Code misses that miss the  DTLB and hit the STLB (2M).)",
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
      R"(Operations that miss the first ITLB level but hit the second and do not cause any page walks.)",
      R"(Operations that miss the first ITLB level but hit the second and do not cause any page walks.)",
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
      R"(This event counts stalls occured due to changing prefix length (66, 67 or REX.W when they change the length of the decoded instruction). Occurrences counting is proportional to the number of prefixes in a 16B-line. This may result in the following penalties: three-cycle penalty for each LCP in a 16-byte chunk.)",
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
      R"(Not taken macro-conditional branches)",
      R"(This event counts not taken macro-conditional branch instructions.)",
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
      R"(Taken speculative and retired macro-conditional branches)",
      R"(This event counts taken speculative and retired macro-conditional branch instructions.)",
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
      R"(Taken speculative and retired macro-conditional branch instructions excluding calls and indirects)",
      R"(This event counts taken speculative and retired macro-conditional branch instructions excluding calls and indirect branches.)",
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
      R"(Taken speculative and retired indirect branches excluding calls and returns)",
      R"(This event counts taken speculative and retired indirect branches excluding calls and return branches.)",
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
      R"(Taken speculative and retired indirect branches with return mnemonic)",
      R"(This event counts taken speculative and retired indirect branches that have a return mnemonic.)",
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
      R"(Taken speculative and retired direct near calls)",
      R"(This event counts taken speculative and retired direct near calls.)",
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
      R"(Taken speculative and retired indirect calls)",
      R"(This event counts taken speculative and retired indirect calls including both register and memory indirect.)",
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
      R"(Speculative and retired macro-conditional branches)",
      R"(This event counts both taken and not taken speculative and retired macro-conditional branch instructions.)",
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
      R"(Speculative and retired macro-unconditional branches excluding calls and indirects)",
      R"(This event counts both taken and not taken speculative and retired macro-unconditional branch instructions, excluding calls and indirects.)",
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
      R"(Speculative and retired indirect branches excluding calls and returns)",
      R"(This event counts both taken and not taken speculative and retired indirect branches excluding calls and return branches.)",
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
      R"(This event counts both taken and not taken speculative and retired indirect branches that have a return mnemonic.)",
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
      R"(Speculative and retired direct near calls)",
      R"(This event counts both taken and not taken speculative and retired direct near calls.)",
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
      R"(This event counts both taken and not taken speculative and retired branch instructions.)",
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
      R"(Not taken speculative and retired mispredicted macro conditional branches)",
      R"(This event counts not taken speculative and retired mispredicted macro conditional branch instructions.)",
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
      R"(Taken speculative and retired mispredicted macro conditional branches)",
      R"(This event counts taken speculative and retired mispredicted macro conditional branch instructions.)",
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
      R"(Taken speculative and retired mispredicted indirect branches excluding calls and returns)",
      R"(This event counts taken speculative and retired mispredicted indirect branches excluding calls and returns.)",
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
      R"(Taken speculative and retired mispredicted indirect branches with return mnemonic)",
      R"(This event counts taken speculative and retired mispredicted indirect branches that have a return mnemonic.)",
      200003,
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
      "BR_MISP_EXEC.ALL_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xC1, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired mispredicted macro conditional branches)",
      R"(This event counts both taken and not taken speculative and retired mispredicted macro conditional branch instructions.)",
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
      R"(Mispredicted indirect branches excluding calls and returns)",
      R"(This event counts both taken and not taken mispredicted indirect branches excluding calls and returns.)",
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
      R"(This event counts both taken and not taken speculative and retired mispredicted branch instructions.)",
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
      R"(This event counts the number of uops not delivered to Resource Allocation Table (RAT) per thread adding 4  x when Resource Allocation Table (RAT) is not stalled and Instruction Decode Queue (IDQ) delivers x uops to Resource Allocation Table (RAT) (where x belongs to {0,1,2,3}). Counting does not cover cases when:
 a. IDQ-Resource Allocation Table (RAT) pipe serves the other thread;
 b. Resource Allocation Table (RAT) is stalled for the thread (including uop drops and clear BE conditions); 
 c. Instruction Decode Queue (IDQ) delivers four uops.)",
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
      R"(This event counts, on the per-thread basis, cycles when no uops are delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core =4.)",
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
      R"(This event counts, on the per-thread basis, cycles when less than 1 uop is  delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core >=3.)",
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
      R"(Cycles with less than 2 uops delivered by the front end.)",
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
      R"(Cycles with less than 3 uops delivered by the front end.)",
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
      "UOP_DISPATCHES_CANCELLED.SIMD_PRF",
      EventDef::Encoding{
          .code = 0xA0, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Micro-op dispatches cancelled due to insufficient SIMD physical register file read ports)",
      R"(This event counts the number of micro-operations cancelled after they were dispatched from the scheduler to the execution units when the total number of physical register read ports across all dispatch ports exceeds the read bandwidth of the physical register file.  The SIMD_PRF subevent applies to the following instructions: VDPPS, DPPS, VPCMPESTRI, PCMPESTRI, VPCMPESTRM, PCMPESTRM, VFMADD*, VFMADDSUB*, VFMSUB*, VMSUBADD*, VFNMADD*, VFNMSUB*.  See the Broadwell Optimization Guide for more information.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 0.)",
      2000003,
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
      R"(Cycles per core when uops are exectuted in port 0.)",
      R"(Cycles per core when uops are exectuted in port 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED_PORT.PORT_0",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 0)",
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 0.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 1.)",
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
      R"(Cycles per core when uops are exectuted in port 1.)",
      R"(Cycles per core when uops are exectuted in port 1.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 1.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 2.)",
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
      "UOPS_EXECUTED_PORT.PORT_2",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 2)",
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 2.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 3.)",
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
      "UOPS_EXECUTED_PORT.PORT_3",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 3)",
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 3.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 4.)",
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
      R"(Cycles per core when uops are exectuted in port 4.)",
      R"(Cycles per core when uops are exectuted in port 4.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 4.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 5.)",
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
      R"(Cycles per core when uops are exectuted in port 5.)",
      R"(Cycles per core when uops are exectuted in port 5.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 5.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 6.)",
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
      R"(Cycles per core when uops are exectuted in port 6.)",
      R"(Cycles per core when uops are exectuted in port 6.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 6.)",
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
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 7.)",
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
      "UOPS_EXECUTED_PORT.PORT_7",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are executed in port 7)",
      R"(This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 7.)",
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
      R"(This event counts resource-related stall cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.RS",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles stalled due to no eligible RS entry available.)",
      R"(This event counts stall cycles caused by absence of eligible entries in the reservation station (RS). This may result from RS overflow, or from RS deallocation because of the RS array Write Port allocation scheme (each RS entry has two write ports instead of four. As a result, empty entries could not be used, although RS is not really full). This counts cycles that the pipeline backend blocked uop delivery from the front end.)",
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
      R"(This event counts stall cycles caused by the store buffer (SB) overflow (excluding draining from synch). This counts cycles that the pipeline backend blocked uop delivery from the front end.)",
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
      R"(This event counts ROB full stall cycles. This counts cycles that the pipeline backend blocked uop delivery from the front end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L2_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles while L2 cache miss demand load is outstanding.)",
      R"(Counts number of cycles the CPU has at least one pending  demand* load request missing the L2 cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L2_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x01, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles while L2 cache miss demand load is outstanding.)",
      R"(Cycles while L2 cache miss demand load is outstanding.)",
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
      R"(Cycles while memory subsystem has an outstanding load.)",
      R"(Counts number of cycles the CPU has at least one pending  demand load request (that is cycles with non-completed load waiting for its data from memory subsystem).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_MEM_ANY",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x02, .cmask = 2, .msr_values = {0x00}},
      R"(Cycles while memory subsystem has an outstanding load.)",
      R"(Cycles while memory subsystem has an outstanding load.)",
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
      R"(Counts number of cycles nothing is executed on any execution port.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_TOTAL",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x04, .cmask = 4, .msr_values = {0x00}},
      R"(Total execution stalls.)",
      R"(Total execution stalls.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x05, .cmask = 5, .msr_values = {0}},
      R"(Execution stalls while L2 cache miss demand load is outstanding.)",
      R"(Counts number of cycles nothing is executed on any execution port, while there was at least one pending demand* load request missing the L2 cache.(as a footprint) * includes also L1 HW prefetch requests that may or may not be required by demands.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x05, .cmask = 5, .msr_values = {0x00}},
      R"(Execution stalls while L2 cache miss demand load is outstanding.)",
      R"(Execution stalls while L2 cache miss demand load is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_LDM_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x06, .cmask = 6, .msr_values = {0}},
      R"(Execution stalls while memory subsystem has an outstanding load.)",
      R"(Counts number of cycles nothing is executed on any execution port, while there was at least one pending demand load request.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_MEM_ANY",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x06, .cmask = 6, .msr_values = {0x00}},
      R"(Execution stalls while memory subsystem has an outstanding load.)",
      R"(Execution stalls while memory subsystem has an outstanding load.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L1D_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x08, .cmask = 8, .msr_values = {0}},
      R"(Cycles while L1 cache miss demand load is outstanding.)",
      R"(Counts number of cycles the CPU has at least one pending  demand load request missing the L1 data cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L1D_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x08, .cmask = 8, .msr_values = {0x00}},
      R"(Cycles while L1 cache miss demand load is outstanding.)",
      R"(Cycles while L1 cache miss demand load is outstanding.)",
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
      R"(Execution stalls while L1 cache miss demand load is outstanding.)",
      R"(Counts number of cycles nothing is executed on any execution port, while there was at least one pending demand load request missing the L1 data cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L1D_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x0C, .cmask = 12, .msr_values = {0x00}},
      R"(Execution stalls while L1 cache miss demand load is outstanding.)",
      R"(Execution stalls while L1 cache miss demand load is outstanding.)",
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
      R"(Number of Uops delivered by the LSD.)",
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
      R"(Cycles 4 Uops delivered by the LSD, but didn't come from the decoder.)",
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
      R"(Cycles Uops delivered by the LSD, but didn't come from the decoder.)",
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
      R"(This event counts Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles. These cycles do not include uops routed through because of the switch itself, for example, when Instruction Decode Queue (IDQ) pre-allocation is unavailable, or Instruction Decode Queue (IDQ) is full. SBD-to-MITE switch true penalty cycles happen after the merge mux (MM) receives Decode Stream Buffer (DSB) Sync-indication until receiving the first MITE uop. 
MM is placed before Instruction Decode Queue (IDQ) to merge uops being fed from the MITE and Decode Stream Buffer (DSB) paths. Decode Stream Buffer (DSB) inserts the Sync-indication whenever a Decode Stream Buffer (DSB)-to-MITE switch occurs.
Penalty: A Decode Stream Buffer (DSB) hit followed by a Decode Stream Buffer (DSB) miss can cost up to six cycles in which no uops are delivered to the IDQ. Most often, such switches from the Decode Stream Buffer (DSB) to the legacy pipeline cost 02 cycles.)",
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
      R"(This event counts the number of flushes of the big or small ITLB pages. Counting include both TLB Flush (covering all sets) and TLB Set Clear (set-specific).)",
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
      R"(This event counts the Demand Data Read requests sent to uncore. Use it in conjunction with OFFCORE_REQUESTS_OUTSTANDING to determine average latency in the uncore.)",
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
      R"(This event counts both cacheable and noncachaeble code read requests.)",
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
      R"(This event counts the demand RFO (read for ownership) requests including regular RFOs, locks, ItoM.)",
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
      R"(This event counts the demand and prefetch data reads. All Core Data Reads include cacheable Demands and L2 prefetchers (not L3 prefetchers). Counting also covers reads due to page walks resulted from any request type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.ALL_REQUESTS",
      EventDef::Encoding{
          .code = 0xb0, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Any memory transaction that reached the SQ.)",
      R"(This event counts memory transactions reached the super queue including requests initiated by the core, all L3 prefetches, page walks, and so on.)",
      100003,
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
      "UOPS_EXECUTED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x01,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Counts number of cycles no uops were dispatched to be executed on this thread.)",
      R"(This event counts cycles during which no uops were dispatched from the Reservation Station (RS) per thread.)",
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
      R"(Cycles where at least 1 uop was executed per-thread.)",
      R"(Cycles where at least 1 uop was executed per-thread.)",
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
      R"(Cycles where at least 2 uops were executed per-thread.)",
      R"(Cycles where at least 2 uops were executed per-thread.)",
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
      R"(Cycles where at least 3 uops were executed per-thread.)",
      R"(Cycles where at least 3 uops were executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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
      "UOPS_EXECUTED.CORE_CYCLES_GE_1",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 1, .msr_values = {0}},
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_2",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 2, .msr_values = {0}},
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_3",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 3, .msr_values = {0}},
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_4",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x02, .cmask = 4, .msr_values = {0}},
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_NONE",
      EventDef::Encoding{
          .code = 0xb1,
          .umask = 0x02,
          .inv = true,
          .cmask = 0,
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
      "OFFCORE_REQUESTS_BUFFER.SQ_FULL",
      EventDef::Encoding{
          .code = 0xb2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore requests buffer cannot take more entries for this thread core.)",
      R"(This event counts the number of cases when the offcore requests buffer cannot take more entries for the core. This can happen when the superqueue does not contain eligible entries, or when L1D writeback pending FIFO requests is full.
Note: Writeback pending FIFO has six entries.)",
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
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_L1",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x11, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in the L1+FB.)",
      R"(Number of DTLB page walker hits in the L1+FB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69, BDM98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_L2",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x12, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in the L2.)",
      R"(Number of DTLB page walker hits in the L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69, BDM98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_L3",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x14, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in the L3 + XSNP.)",
      R"(Number of DTLB page walker hits in the L3 + XSNP.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69, BDM98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.DTLB_MEMORY",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x18, .cmask = 0, .msr_values = {0}},
      R"(Number of DTLB page walker hits in Memory.)",
      R"(Number of DTLB page walker hits in Memory.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69, BDM98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.ITLB_L1",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Number of ITLB page walker hits in the L1+FB.)",
      R"(Number of ITLB page walker hits in the L1+FB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69, BDM98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.ITLB_L2",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x22, .cmask = 0, .msr_values = {0}},
      R"(Number of ITLB page walker hits in the L2.)",
      R"(Number of ITLB page walker hits in the L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69, BDM98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKER_LOADS.ITLB_L3",
      EventDef::Encoding{
          .code = 0xBC, .umask = 0x24, .cmask = 0, .msr_values = {0}},
      R"(Number of ITLB page walker hits in the L3 + XSNP.)",
      R"(Number of ITLB page walker hits in the L3 + XSNP.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM69, BDM98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TLB_FLUSH.DTLB_THREAD",
      EventDef::Encoding{
          .code = 0xBD, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(DTLB flush attempts of the thread-specific entries)",
      R"(This event counts the number of DTLB flush attempts of the thread-specific entries.)",
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
      R"(This event counts the number of any STLB flush attempts (such as entire, VPID, PCID, InvPage, CR3 write, and so on).)",
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
      R"(Number of instructions retired. General Counter   - architectural event)",
      R"(This event counts the number of instructions (EOMs) retired. Counting covers macro-fused instructions individually (that is, increments by two).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM61)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.PREC_DIST",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Precise instruction retired event with HW to reduce effect of PEBS shadow in IP distribution)",
      R"(This is a precise version (that is, uses PEBS) of the event that counts instructions retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(BDM11, BDM55)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.X87",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(FP operations  retired. X87 FP operations that have no exceptions:)",
      R"(This event counts FP operations retired. For X87 FP operations that have no exceptions counting also includes flows that have several X87, or flows that use X87 uops in the exception handling.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.AVX_TO_SSE",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of transitions from AVX-256 to legacy SSE when penalty applicable.)",
      R"(This event counts the number of transitions from AVX-256 to legacy SSE when penalty is applicable.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.SSE_TO_AVX",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of transitions from SSE to AVX-256 when penalty applicable.)",
      R"(This event counts the number of transitions from legacy SSE to AVX-256 when penalty is applicable.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDM30)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.ANY_WB_ASSIST",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of times any microcode assist is invoked by HW upon uop writeback.)",
      R"(Number of times any microcode assist is invoked by HW upon uop writeback.)",
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
      R"(This event counts all actually retired uops. Counting increments by two for micro-fused uops, and by one for macro-fused and other uops. Maximal increment value for one cycle is eight.)",
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
      R"(This event counts cycles without actually retired uops.)",
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
      R"(Number of cycles using always true condition (uops_ret < 16) applied to non PEBS uops retired event.)",
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
      R"(This event counts the number of retirement slots used.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.CYCLES",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles there was a Nuke. Account for both thread-specific and All Thread Nukes.)",
      R"(This event counts both thread-specific (TS) and all-thread (AT) nukes.)",
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
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of machine clears due to memory order conflicts.)",
      R"(This event counts the number of memory ordering Machine Clears detected. Memory Ordering Machine Clears can result from one of the following:
1. memory disambiguation,
2. external snoop, or
3. cross SMT-HW-thread snoop (stores) hitting load buffer.)",
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
      R"(This event counts self-modifying code (SMC) detected, which causes a machine clear.)",
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
      R"(Maskmov false fault - counts number of time ucode passes through Maskmov flow due to instruction's mask being 0 while the flow was completed without raising a fault.)",
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
      R"(This event counts all (macro) branch instructions retired.)",
      400009,
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
      R"(This event counts conditional branch instructions retired.)",
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
      R"(This event counts both direct and indirect near call instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL_R3",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect macro near call instructions retired (captured in ring 3).)",
      R"(This event counts both direct and indirect macro near call instructions retired (captured in ring 3).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(All (macro) branch instructions retired. (Precise Event - PEBS))",
      R"(This is a precise version of BR_INST_RETIRED.ALL_BRANCHES that counts all (macro) branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(BDW98)"));

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
      std::nullopt // Errata
      ));

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
      std::nullopt // Errata
      ));

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
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Far branch instructions retired.)",
      R"(This event counts far branch instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(BDW98)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(All mispredicted macro branch instructions retired.)",
      R"(This event counts all mispredicted macro branch instructions retired.)",
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
      "BR_MISP_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted macro branch instructions retired. (Precise Event - PEBS))",
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
      R"(This event counts mispredicted return instructions retired.)",
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
      R"(number of near branch instructions retired that were mispredicted and taken.)",
      R"(Number of near branch instructions retired that were mispredicted and taken.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SCALAR_DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      R"(Number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SCALAR_SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      R"(Number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SCALAR",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Number of SSE/AVX computational scalar floating-point instructions retired; some instructions will count twice as noted below. Each count represents 1 computation operation.   Applies to SSE* and AVX* scalar double and single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      R"(Number of SSE/AVX computational scalar single precision and double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.128B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.128B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 4 calculations per element.)",
      R"(Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.256B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 4 calculations per element.)",
      R"(Number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x15, .cmask = 0, .msr_values = {0x00}},
      R"(Number of SSE/AVX computational double precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      R"(Number of SSE/AVX computational double precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      2000006,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.256B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 8 calculations per element.)",
      R"(Number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x2a, .cmask = 0, .msr_values = {0x00}},
      R"(Number of SSE/AVX computational single precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      R"(Number of SSE/AVX computational single precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      2000005,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.PACKED",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x3c, .cmask = 0, .msr_values = {0x00}},
      R"(Number of SSE/AVX computational packed floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* packed double and single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      R"(Number of SSE/AVX computational packed floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* packed double and single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.)",
      2000004,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.START",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of times we entered an HLE region; does not count nested transactions)",
      R"(Number of times we entered an HLE region
 does not count nested transactions.)",
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
      R"(Number of times HLE commit succeeded)",
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
          .code = 0xc8, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of times HLE abort was triggered)",
      R"(Number of times HLE abort was triggered.)",
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
      R"(Number of times an HLE abort was attributed to a Memory condition (See TSX_Memory event for additional details).)",
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
      R"(Number of times an HLE execution aborted due to uncommon conditions)",
      R"(Number of times the TSX watchdog signaled an HLE abort.)",
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
      R"(Number of times an HLE execution aborted due to HLE-unfriendly instructions)",
      R"(Number of times a disallowed operation caused an HLE abort.)",
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
      R"(Number of times an HLE execution aborted due to incompatible memory type)",
      R"(Number of times HLE caused a fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MISC5",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of times an HLE execution aborted due to none of the previous 4 categories (e.g. interrupts))",
      R"(Number of times HLE aborted and was not due to the abort conditions in subevents 3-6.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.START",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of times we entered an RTM region; does not count nested transactions)",
      R"(Number of times we entered an RTM region
 does not count nested transactions.)",
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
      R"(Number of times RTM commit succeeded)",
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
          .code = 0xc9, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of times RTM abort was triggered)",
      R"(Number of times RTM abort was triggered .)",
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
      R"(Number of times an RTM abort was attributed to a Memory condition (See TSX_Memory event for additional details).)",
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
      R"(Number of times the TSX watchdog signaled an RTM abort.)",
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
      R"(Number of times an RTM execution aborted due to HLE-unfriendly instructions)",
      R"(Number of times a disallowed operation caused an RTM abort.)",
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
      R"(Number of times an RTM execution aborted due to incompatible memory type)",
      R"(Number of times a RTM caused a fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MISC5",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt))",
      R"(Number of times RTM aborted and was not due to the abort conditions in subevents 3-6.)",
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
      R"(This event counts the number of x87 floating point (FP) micro-code assist (numeric overflow/underflow, inexact result) when the output value (destination register) is invalid.)",
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
      R"(This event counts x87 floating point (FP) micro-code assist (invalid operation, denormal operand, SNaN operand) when the input value (one of the source operands to an FP instruction) is invalid.)",
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
      R"(This event counts the number of SSE* floating point (FP) micro-code assist (numeric overflow/underflow) when the output value (destination register) is invalid. Counting covers only cases involving penalties that require micro-code assist intervention.)",
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
      R"(This event counts any input SSE* FP assist - invalid operation, denormal operand, dividing by zero, SNaN operand. Counting includes only cases involving penalties that required micro-code assist intervention.)",
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
      R"(This event counts cycles with any input and output SSE or x87 FP assist. If an input and output assist are detected on the same cycle the event increments by 1.)",
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
      R"(This event counts cases of saving new LBR records by hardware. This assumes proper enabling of LBRs and takes into account LBR filtering done by the LBR_SELECT register.)",
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
      R"(Randomly selected loads with latency value being above 4)",
      R"(Counts randomly selected loads with latency value being above four.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_8",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x8}},
      R"(Randomly selected loads with latency value being above 8)",
      R"(Counts randomly selected loads with latency value being above eight.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_16",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x10}},
      R"(Randomly selected loads with latency value being above 16)",
      R"(Counts randomly selected loads with latency value being above 16.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_32",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x20}},
      R"(Randomly selected loads with latency value being above 32)",
      R"(Counts randomly selected loads with latency value being above 32.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_64",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x40}},
      R"(Randomly selected loads with latency value being above 64)",
      R"(Counts randomly selected loads with latency value being above 64.)",
      2003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_128",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x80}},
      R"(Randomly selected loads with latency value being above 128)",
      R"(Counts randomly selected loads with latency value being above 128.)",
      1009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_256",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x100}},
      R"(Randomly selected loads with latency value being above 256)",
      R"(Counts randomly selected loads with latency value being above 256.)",
      503,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_512",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x200}},
      R"(Randomly selected loads with latency value being above 512)",
      R"(Counts randomly selected loads with latency value being above 512.)",
      101,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(BDM100, BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x11, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that miss the STLB.)",
      R"(This event counts load uops with true STLB miss retired to the architected path. True STLB miss is an uop triggering page walk that gets completed without blocks, and later gets retired. This page walk can end up with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x12, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that miss the STLB.)",
      R"(This event counts store uops with true STLB miss retired to the architected path. True STLB miss is an uop triggering page walk that gets completed without blocks, and later gets retired. This page walk can end up with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with locked access.)",
      R"(This event counts load uops with locked access retired to the architected path.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that split across a cacheline boundary.)",
      R"(This event counts line-split load uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x42, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that split across a cacheline boundary.)",
      R"(This event counts line-split store uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(All retired load uops.)",
      R"(This event counts load uops retired to the architected path with a filter on bits 0 and 1 applied.
Note: This event counts AVX-256bit load/store double-pump memory uops as a single uop at retirement. This event also counts SW prefetches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(All retired store uops.)",
      R"(This event counts store uops retired to the architected path with a filter on bits 0 and 1 applied.
Note: This event counts AVX-256bit load/store double-pump memory uops as a single uop at retirement.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L1 cache hits as data sources.)",
      R"(This event counts retired load uops which data sources were hits in the nearest-level (L1) cache.
Note: Only two data-sources of L1/FB are applicable for AVX-256bit  even though the corresponding AVX load could be serviced by a deeper level in the memory hierarchy. Data source is reported for the Low-half load. This event also counts SW prefetches independent of the actual data source.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L2 cache hits as data sources.)",
      R"(This event counts retired load uops which data sources were hits in the mid-level (L2) cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM35)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L3_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were data hits in L3 without snoops required.)",
      R"(This event counts retired load uops which data sources were data hits in the last-level (L3) cache without snoops required.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM100)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops misses in L1 cache as data sources.)",
      R"(This event counts retired load uops which data sources were misses in the nearest-level (L1) cache. Counting excludes unknown and UC data source.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Miss in mid-level (L2) cache. Excludes Unknown data-source.)",
      R"(This event counts retired load uops which data sources were misses in the mid-level (L2) cache. Counting excludes unknown and UC data source.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L3_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Miss in last-level (L3) cache. Excludes Unknown data-source.)",
      R"(Miss in last-level (L3) cache. Excludes Unknown data-source.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM100, BDE70)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.HIT_LFB",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.)",
      R"(This event counts retired load uops which data sources were load uops missed L1 but hit a fill buffer due to a preceding miss to the same cache line with the data not ready.
Note: Only two data-sources of L1/FB are applicable for AVX-256bit  even though the corresponding AVX load could be serviced by a deeper level in the memory hierarchy. Data source is reported for the Low-half load.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_MISS",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.)",
      R"(This event counts retired load uops which data sources were L3 Hit and a cross-core snoop missed in the on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM100)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_HIT",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were L3 and cross-core snoop hits in on-pkg core cache.)",
      R"(This event counts retired load uops which data sources were L3 hit and a cross-core snoop hit in the on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM100)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_HITM",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were HitM responses from shared L3.)",
      R"(This event counts retired load uops which data sources were HitM responses from a core on same socket (shared L3).)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM100)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_NONE",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were hits in L3 without snoops required.)",
      R"(This event counts retired load uops which data sources were hits in the last-level (L3) cache without snoops required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDM100)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Data from local DRAM either Snoop not needed or Snoop Miss (RspI))",
      R"(Retired load uop whose Data Source was: local DRAM either Snoop not needed or Snoop Miss (RspI).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDE70, BDM100)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uop whose Data Source was: remote DRAM either Snoop not needed or Snoop Miss (RspI))",
      R"(Retired load uop whose Data Source was: remote DRAM either Snoop not needed or Snoop Miss (RspI))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDE70)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.REMOTE_HITM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Retired load uop whose Data Source was: Remote cache HITM)",
      R"(Retired load uop whose Data Source was: Remote cache HITM)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDE70)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.REMOTE_FWD",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Retired load uop whose Data Source was: forwarded from remote cache)",
      R"(Retired load uop whose Data Source was: forwarded from remote cache)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(BDE70)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ANY",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x1f, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests that access L2 cache)",
      R"(This event counts Demand Data Read requests that access L2 cache, including rejects.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.RFO",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that access L2 cache)",
      R"(This event counts Read for Ownership (RFO) requests that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.CODE_RD",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(L2 cache accesses when fetching instructions)",
      R"(This event counts the number of L2 cache accesses when fetching instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.ALL_PF",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(L2 or L3 HW prefetches that access L2 cache)",
      R"(This event counts L2 or L3 HW prefetches that access L2 cache including rejects.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L1D_WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L1D writebacks that access L2 cache)",
      R"(This event counts L1D writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L2_FILL",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 fill requests that access L2 cache)",
      R"(This event counts L2 fill requests that access L2 cache.)",
      200003,
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
      R"(This event counts L2 writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.ALL_REQUESTS",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Transactions accessing L2 pipe)",
      R"(This event counts transactions that access the L2 pipe including snoops, pagewalks, and so on.)",
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
      R"(This event counts the number of L2 cache lines in the Invalidate state filling the L2. Counting does not cover rejects.)",
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
      R"(This event counts the number of L2 cache lines in the Shared state filling the L2. Counting does not cover rejects.)",
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
      R"(This event counts the number of L2 cache lines in the Exclusive state filling the L2. Counting does not cover rejects.)",
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
      R"(This event counts the number of L2 cache lines filling the L2. Counting does not cover rejects.)",
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
      R"(Clean L2 cache lines evicted by demand.)",
      R"(Clean L2 cache lines evicted by demand.)",
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
      R"(This event counts the number of split locks in the super queue.)",
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
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x87FC007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and clean or shared data is transferred from remote cache)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and clean or shared data is transferred from remote cache)",
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
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63BC007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from remote dram)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from remote dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x6040007F7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from local dram)",
      R"(Counts all data/code/rfo reads (demand & prefetch) miss the L3 and the data is returned from local dram)",
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
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000244}},
      R"(Counts all demand & prefetch code reads miss the L3 and the data is returned from local dram)",
      R"(Counts all demand & prefetch code reads miss the L3 and the data is returned from local dram)",
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
      "OFFCORE_RESPONSE.ALL_RFO.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000122}},
      R"(Counts all demand & prefetch RFOs miss the L3 and the data is returned from local dram)",
      R"(Counts all demand & prefetch RFOs miss the L3 and the data is returned from local dram)",
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
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.REMOTE_HIT_FORWARD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x87FC00091}},
      R"(Counts all demand & prefetch data reads miss the L3 and clean or shared data is transferred from remote cache)",
      R"(Counts all demand & prefetch data reads miss the L3 and clean or shared data is transferred from remote cache)",
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
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x63BC00091}},
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from remote dram)",
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from remote dram)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x604000091}},
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from local dram)",
      R"(Counts all demand & prefetch data reads miss the L3 and the data is returned from local dram)",
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
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3F803C0002}},
      R"(Counts all demand data writes (RFOs) hit in the L3)",
      R"(Counts all demand data writes (RFOs) hit in the L3)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace broadwellx_core
} // namespace facebook::hbt::perf_event::generated
