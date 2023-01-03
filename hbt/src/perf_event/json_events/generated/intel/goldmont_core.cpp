// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace goldmont_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from goldmont_core.json (169 events).

    Supported SKUs:
        - Arch: x86, Model: GLM id: 92
        - Arch: x86, Model: GLM id: 95
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Instructions retired (Fixed event))",
      R"(Counts the number of instructions that retire execution. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. The counter continues counting during hardware interrupts, traps, and inside interrupt handlers.  This event uses fixed counter 0.  You cannot collect a PEBs record for this event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Core cycles when core is not halted  (Fixed event))",
      R"(Counts the number of core cycles while the core is not in a halt state.  The core enters the halt state when it is running the HLT instruction. In mobile systems the core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time.  This event uses fixed counter 1.  You cannot collect a PEBs record for this event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Reference cycles when core is not halted  (Fixed event))",
      R"(Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction.  In mobile systems the core frequency may change from time.  This event is not affected by core frequency changes but counts as if the core is running at the maximum frequency all the time.  This event uses fixed counter 2.  You cannot collect a PEBs record for this event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.DATA_UNKNOWN",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Loads blocked due to store data not ready (Precise event capable))",
      R"(Counts a load blocked from using a store forward, but did not occur because the store data was not available at the right time.  The forward might occur subsequently when the data is available.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.STORE_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Loads blocked due to store forward restriction (Precise event capable))",
      R"(Counts a load blocked from using a store forward because of an address/size mismatch, only one of the loads blocked from each store will be counted.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.4K_ALIAS",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Loads blocked because address has 4k partial address false dependence (Precise event capable))",
      R"(Counts loads that block because their address modulo 4K matches a pending store.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.UTLB_MISS",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Loads blocked because address in not in the UTLB (Precise event capable))",
      R"(Counts loads blocked because they are unable to find their physical address in the micro TLB (UTLB).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.ALL_BLOCK",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Loads blocked (Precise event capable))",
      R"(Counts anytime a load that retires is blocked for any reason.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.D_SIDE_CYCLES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Duration of D-side page-walks in cycles)",
      R"(Counts every core cycle when a Data-side (walks due to a data operation) page walk is in progress.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.I_SIDE_CYCLES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Duration of I-side pagewalks in cycles)",
      R"(Counts every core cycle when a Instruction-side (walks due to an instruction fetch) page walk is in progress.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.CYCLES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Duration of page-walks in cycles)",
      R"(Counts every core cycle a page-walk is in progress due to either a data memory operation or an instruction fetch.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Uops issued to the back end per cycle)",
      R"(Counts uops issued by the front end and allocated into the back end of the machine.  This event counts uops that retire as well as uops that were speculatively executed but didn't retire. The sort of speculative uops that might be counted includes, but is not limited to those uops issued in the shadow of a miss-predicted branch, those uops that are inserted during an assist (such as for a denormal floating point result), and (previously allocated) uops that might be canceled during a machine clear.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.LOAD_PAGE_SPLIT",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops that split a page (Precise event capable))",
      R"(Counts when a memory load of a uop spans a page boundary (a split) is retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.STORE_PAGE_SPLIT",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Store uops that split a page (Precise event capable))",
      R"(Counts when a memory store of a uop spans a page boundary (a split) is retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.MISS",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
      R"(L2 cache request misses)",
      R"(Counts memory requests originating from the core that miss in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x4F, .cmask = 0, .msr_values = {0x00}},
      R"(L2 cache requests)",
      R"(Counts memory requests originating from the core that reference a cache line in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REJECT_XQ.ALL",
      EventDef::Encoding{
          .code = 0x30, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Requests rejected by the XQ)",
      R"(Counts the number of demand and prefetch transactions that the L2 XQ rejects due to a full or near full condition which likely indicates back pressure from the intra-die interconnect (IDI) fabric. The XQ may reject transactions from the L2Q (non-cacheable requests), L2 misses and L2 write-back victims.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_REJECT_L2Q.ALL",
      EventDef::Encoding{
          .code = 0x31, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Requests rejected by the L2Q)",
      R"(Counts the number of demand and L1 prefetcher requests rejected by the L2Q due to a full or nearly full condition which likely indicates back pressure from L2Q. It also counts requests that would have gone directly to the XQ, but are rejected due to a full or nearly full condition, indicating back pressure from the IDI link. The L2Q may also reject transactions from a core to ensure fairness between cores, or to delay a core's dirty eviction when the address conflicts with incoming external snoops.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE_P",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Core cycles when core is not halted)",
      R"(Core cycles when core is not halted.  This event uses a (_P)rogrammable general purpose performance counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Reference cycles when core is not halted)",
      R"(Reference cycles when core is not halted.  This event uses a programmable general purpose performance counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DL1.DIRTY_EVICTION",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(L1 Cache evictions for dirty data)",
      R"(Counts when a modified (dirty) cache line is evicted from the data L1 cache and needs to be written back to memory.  No count will occur if the evicted line is clean, and hence does not require a writeback.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.HIT",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(References per ICache line that are available in the ICache (hit). This event counts differently than Intel processors based on Silvermont microarchitecture)",
      R"(Counts requests to the Instruction Cache (ICache) for one or more bytes in an ICache Line and that cache line is in the ICache (hit).  The event strives to count on a cache line basis, so that multiple accesses which hit in a single cache line count as one ICACHE.HIT.  Specifically, the event counts when straight line code crosses the cache line boundary, or when a branch target is to a new line, and that cache line is in the ICache. This event counts differently than Intel processors based on Silvermont microarchitecture.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(References per ICache line that are not available in the ICache (miss). This event counts differently than Intel processors based on Silvermont microarchitecture)",
      R"(Counts requests to the Instruction Cache (ICache)  for one or more bytes in an ICache Line and that cache line is not in the ICache (miss).  The event strives to count on a cache line basis, so that multiple accesses which miss in a single cache line count as one ICACHE.MISS.  Specifically, the event counts when straight line code crosses the cache line boundary, or when a branch target is to a new line, and that cache line is not in the ICache. This event counts differently than Intel processors based on Silvermont microarchitecture.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.ACCESSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(References per ICache line. This event counts differently than Intel processors based on Silvermont microarchitecture)",
      R"(Counts requests to the Instruction Cache (ICache) for one or more bytes in an ICache Line.  The event strives to count on a cache line basis, so that multiple fetches to a single cache line count as one ICACHE.ACCESS.  Specifically, the event counts when accesses from straight line code crosses the cache line boundary, or when a branch target is to a new line.
This event counts differently than Intel processors based on Silvermont microarchitecture.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB.MISS",
      EventDef::Encoding{
          .code = 0x81, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(ITLB misses)",
      R"(Counts the number of times the machine was unable to find a translation in the Instruction Translation Lookaside Buffer (ITLB) for a linear address of an instruction fetch.  It counts when new translation are filled into the ITLB.  The event is speculative in nature, but will not count translations (page walks) that are begun and not finished, or translations that are finished but not filled into the ITLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FETCH_STALL.ALL",
      EventDef::Encoding{
          .code = 0x86, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles code-fetch stalled due to any reason.)",
      R"(Counts cycles that fetch is stalled due to any reason. That is, the decoder queue is able to accept bytes, but the fetch unit is unable to provide bytes.  This will include cycles due to an ITLB miss, ICache miss and other events. )",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FETCH_STALL.ITLB_FILL_PENDING_CYCLES",
      EventDef::Encoding{
          .code = 0x86, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles code-fetch stalled due to an outstanding ITLB miss.)",
      R"(Counts cycles that fetch is stalled due to an outstanding ITLB miss. That is, the decoder queue is able to accept bytes, but the fetch unit is unable to provide bytes due to an ITLB miss.  Note: this event is not the same as page walk cycles to retrieve an instruction translation.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FETCH_STALL.ICACHE_FILL_PENDING_CYCLES",
      EventDef::Encoding{
          .code = 0x86, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles code-fetch stalled due to an outstanding ICache miss.)",
      R"(Counts cycles that fetch is stalled due to an outstanding ICache miss. That is, the decoder queue is able to accept bytes, but the fetch unit is unable to provide bytes due to an ICache miss.  Note: this event is not the same as the total number of cycles spent retrieving instruction cache lines from the memory hierarchy.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_NOT_DELIVERED.ANY",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Uops requested but not-delivered to the back-end per cycle)",
      R"(This event used to measure front-end inefficiencies. I.e. when front-end of the machine is not delivering uops to the back-end and the back-end has is not stalled. This event can be used to identify if the machine is truly front-end bound.  When this event occurs, it is an indication that the front-end of the machine is operating at less than its theoretical peak performance. Background: We can think of the processor pipeline as being divided into 2 broader parts: Front-end and Back-end. Front-end is responsible for fetching the instruction, decoding into uops in machine understandable format and putting them into a uop queue to be consumed by back end. The back-end then takes these uops, allocates the required resources.  When all resources are ready, uops are executed. If the back-end is not ready to accept uops from the front-end, then we do not want to count these as front-end bottlenecks.  However, whenever we have bottlenecks in the back-end, we will have allocation unit stalls and eventually forcing the front-end to wait until the back-end is ready to receive more uops. This event counts only when back-end is requesting more uops and front-end is not able to provide them. When 3 uops are requested and no uops are delivered, the event counts 3. When 3 are requested, and only 1 is delivered, the event counts 2. When only 2 are delivered, the event counts 1. Alternatively stated, the event will not count if 3 uops are delivered, or if the back end is stalled and not requesting any uops at all.  Counts indicate missed opportunities for the front-end to deliver a uop to the back end. Some examples of conditions that cause front-end efficiencies are: ICache misses, ITLB misses, and decoder restrictions that limit the front-end bandwidth. Known Issues: Some uops require multiple allocation slots.  These uops will not be charged as a front end 'not delivered' opportunity, and will be regarded as a back end problem. For example, the INC instruction has one uop that requires 2 issue slots.  A stream of INC instructions will not count as UOPS_NOT_DELIVERED, even though only one instruction can be issued per clock.  The low uop issue rate for a stream of INC instructions is considered to be a back end issue.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      R"(Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Instructions retired (Precise event capable))",
      R"(Counts the number of instructions that retire execution. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. The event continues counting during hardware interrupts, traps, and inside interrupt handlers.  This is an architectural performance event.  This event uses a (_P)rogrammable general purpose performance counter. *This event is Precise Event capable:  The EventingRIP field in the PEBS record is precise to the address of the instruction which caused the event.  Note: Because PEBS records can be collected only on IA32_PMC0, only one event can use the PEBS facility at a time.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Uops retired (Precise event capable))",
      R"(Counts uops which retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.MS",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(MS uops retired (Precise event capable))",
      R"(Counts uops retired that are from the complex flows issued by the micro-sequencer (MS).  Counts both the uops from a micro-coded instruction, and the uops that might be generated from a micro-coded assist.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.FPDIV",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Floating point divide uops retired. (Precise Event Capable))",
      R"(Counts the number of floating point divide uops retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.IDIV",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Integer divide uops retired. (Precise Event Capable))",
      R"(Counts the number of integer divide uops retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.ALL",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(All machine clears)",
      R"(Counts machine clears for any reason.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SMC",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Self-Modifying Code detected)",
      R"(Counts the number of times that the processor detects that a program is writing to a code section and has to perform a machine clear because of that modification.  Self-modifying code (SMC) causes a severe penalty in all Intel\xae architecture processors.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Machine clears due to memory ordering issue)",
      R"(Counts machine clears due to memory ordering issues.  This occurs when a snoop request happens and the machine is uncertain if memory ordering will be preserved as another core is in the process of modifying the data.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.FP_ASSIST",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Machine clears due to FP assists)",
      R"(Counts machine clears due to floating point (FP) operations needing assists.  For instance, if the result was a floating point denormal, the hardware clears the pipeline and reissues uops to produce the correct IEEE compliant denormal result.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.DISAMBIGUATION",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Machine clears due to memory disambiguation)",
      R"(Counts machine clears due to memory disambiguation.  Memory disambiguation happens when a load which has been issued conflicts with a previous unretired store in the pipeline whose address was not known at issue time, but is later resolved to be the same as the load address.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Retired branch instructions (Precise event capable))",
      R"(Counts branch instructions retired for all branch types.  This is an architectural performance event.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.JCC",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x7E, .cmask = 0, .msr_values = {0x00}},
      R"(Retired conditional branch instructions (Precise event capable))",
      R"(Counts retired Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired, including both when the branch was taken and when it was not taken.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_TAKEN_BRANCHES",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Retired taken branch instructions (Precise event capable))",
      R"(Counts the number of taken branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xBF, .cmask = 0, .msr_values = {0x00}},
      R"(Retired far branch instructions (Precise event capable))",
      R"(Counts far branch instructions retired.  This includes far jump, far call and return, and Interrupt call and return.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NON_RETURN_IND",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xEB, .cmask = 0, .msr_values = {0x00}},
      R"(Retired instructions of near indirect Jmp or call (Precise event capable))",
      R"(Counts near indirect call or near indirect jmp branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.RETURN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xF7, .cmask = 0, .msr_values = {0x00}},
      R"(Retired near return instructions (Precise event capable))",
      R"(Counts near return branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xF9, .cmask = 0, .msr_values = {0x00}},
      R"(Retired near call instructions (Precise event capable))",
      R"(Counts near CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.IND_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xFB, .cmask = 0, .msr_values = {0x00}},
      R"(Retired near indirect call instructions (Precise event capable))",
      R"(Counts near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.REL_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xFD, .cmask = 0, .msr_values = {0x00}},
      R"(Retired near relative call instructions (Precise event capable))",
      R"(Counts near relative CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.TAKEN_JCC",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xFE, .cmask = 0, .msr_values = {0x00}},
      R"(Retired conditional branch instructions that were taken (Precise event capable))",
      R"(Counts Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired that were taken and does not count when the Jcc branch instruction were not taken.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Retired mispredicted branch instructions (Precise event capable))",
      R"(Counts mispredicted branch instructions retired including all branch types.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.JCC",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x7E, .cmask = 0, .msr_values = {0x00}},
      R"(Retired mispredicted conditional branch instructions (Precise event capable))",
      R"(Counts mispredicted retired Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired, including both when the branch was supposed to be taken and when it was not supposed to be taken (but the processor predicted the opposite condition).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NON_RETURN_IND",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xEB, .cmask = 0, .msr_values = {0x00}},
      R"(Retired mispredicted instructions of near indirect Jmp or near indirect call. (Precise event capable))",
      R"(Counts mispredicted branch instructions retired that were near indirect call or near indirect jmp, where the target address taken was not what the processor predicted.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.RETURN",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xF7, .cmask = 0, .msr_values = {0x00}},
      R"(Retired mispredicted near return instructions (Precise event capable))",
      R"(Counts mispredicted near RET branch instructions retired, where the return address taken was not what the processor predicted.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.IND_CALL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xFB, .cmask = 0, .msr_values = {0x00}},
      R"(Retired mispredicted near indirect call instructions (Precise event capable))",
      R"(Counts mispredicted near indirect CALL branch instructions retired, where the target address taken was not what the processor predicted.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.TAKEN_JCC",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xFE, .cmask = 0, .msr_values = {0x00}},
      R"(Retired mispredicted conditional branch instructions that were taken (Precise event capable))",
      R"(Counts mispredicted retired Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired that were supposed to be taken but the processor predicted that it would not be taken.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ISSUE_SLOTS_NOT_CONSUMED.ANY",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Unfilled issue slots per cycle)",
      R"(Counts the number of issue slots per core cycle that were not consumed by the backend due to either a full resource  in the backend (RESOURCE_FULL) or due to the processor recovering from some event (RECOVERY).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ISSUE_SLOTS_NOT_CONSUMED.RESOURCE_FULL",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Unfilled issue slots per cycle because of a full resource in the backend)",
      R"(Counts the number of issue slots per core cycle that were not consumed because of a full resource in the backend.  Including but not limited to resources such as the Re-order Buffer (ROB), reservation stations (RS), load/store buffers, physical registers, or any other needed machine resource that is currently unavailable.   Note that uops must be available for consumption in order for this event to fire.  If a uop is not available (Instruction Queue is empty), this event will not count.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ISSUE_SLOTS_NOT_CONSUMED.RECOVERY",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Unfilled issue slots per cycle to recover)",
      R"(Counts the number of issue slots per core cycle that were not consumed by the backend because allocation is stalled waiting for a mispredicted jump to retire or other branch-like conditions (e.g. the event is relevant during certain microcode flows).   Counts all issue slots blocked while within this window including slots where uops were not available in the Instruction Queue.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_INTERRUPTS.RECEIVED",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Hardware interrupts received)",
      R"(Counts hardware interrupts received by the processor.)",
      203,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_INTERRUPTS.MASKED",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles hardware interrupts are masked)",
      R"(Counts the number of core cycles during which interrupts are masked (disabled). Increments by 1 each core cycle that EFLAGS.IF is 0, regardless of whether interrupts are pending or not.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_INTERRUPTS.PENDING_AND_MASKED",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles pending interrupts are masked)",
      R"(Counts core cycles during which there are pending interrupts, but interrupts are masked (EFLAGS.IF = 0).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.ALL",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles a divider is busy)",
      R"(Counts core cycles if either divide unit is busy.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.IDIV",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles the integer divide unit is busy)",
      R"(Counts core cycles the integer divide unit is busy.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.FPDIV",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles the FP divide unit is busy)",
      R"(Counts core cycles the floating point divide unit is busy.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.DTLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x11, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops retired that missed the DTLB (Precise event capable))",
      R"(Counts load uops retired that caused a DTLB miss.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.DTLB_MISS_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x12, .cmask = 0, .msr_values = {0x00}},
      R"(Store uops retired that missed the DTLB (Precise event capable))",
      R"(Counts store uops retired that caused a DTLB miss.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.DTLB_MISS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x13, .cmask = 0, .msr_values = {0x00}},
      R"(Memory uops retired that missed the DTLB (Precise event capable))",
      R"(Counts uops retired that had a DTLB miss on load, store or either.  Note that when two distinct memory operations to the same page miss the DTLB, only one of them will be recorded as a DTLB miss.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x21, .cmask = 0, .msr_values = {0x00}},
      R"(Locked load uops retired (Precise event capable))",
      R"(Counts locked memory uops retired.  This includes regular locks and bus locks. (To specifically count bus locks only, see the Offcore response event.)  A locked access is one with a lock prefix, or an exchange to memory.  See the SDM for a complete description of which memory load accesses are locks.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops retired that split a cache-line (Precise event capable))",
      R"(Counts load uops retired where the data requested spans a 64 byte cache line boundary.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x42, .cmask = 0, .msr_values = {0x00}},
      R"(Stores uops retired that split a cache-line (Precise event capable))",
      R"(Counts store uops retired where the data requested spans a 64 byte cache line boundary.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x43, .cmask = 0, .msr_values = {0x00}},
      R"(Memory uops retired that split a cache-line (Precise event capable))",
      R"(Counts memory uops retired where the data requested spans a 64 byte cache line boundary.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x81, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops retired (Precise event capable))",
      R"(Counts the number of load uops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x82, .cmask = 0, .msr_values = {0x00}},
      R"(Store uops retired (Precise event capable))",
      R"(Counts the number of store uops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x83, .cmask = 0, .msr_values = {0x00}},
      R"(Memory uops retired (Precise event capable))",
      R"(Counts the number of memory uops retired that is either a loads or a store or both.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops retired that hit L1 data cache (Precise event capable))",
      R"(Counts load uops retired that hit the L1 data cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops retired that hit L2 (Precise event capable))",
      R"(Counts load uops retired that hit in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops retired that missed L1 data cache (Precise event capable))",
      R"(Counts load uops retired that miss the L1 data cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Load uops retired that missed L2 (Precise event capable))",
      R"(Counts load uops retired that miss in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.HITM",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Memory uop retired where cross core or cross module HITM occurred (Precise event capable))",
      R"(Counts load uops retired where the cache line containing the data was in the modified state of another core or modules cache (HITM).  More specifically, this means that when the load address was checked by other caching agents (typically another processor) in the system, one of those caching agents indicated that they had a dirty copy of the data.  Loads that obtain a HITM response incur greater latency than most is typical for a load.  In addition, since HITM indicates that some other processor had this data in its cache, it implies that the data was shared between processors, or potentially was a lock or semaphore value.  This event is useful for locating sharing, false sharing, and contended locks.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.WCB_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Loads retired that hit WCB (Precise event capable))",
      R"(Counts memory load uops retired where the data is retrieved from the WCB (or fill buffer), indicating that the load found its data while that data was in the process of being brought into the L1 cache.  Typically a load will receive this indication when some other load or prefetch missed the L1 cache and was in the process of retrieving the cache line containing the data, but that process had not yet finished (and written the data back to the cache). For example, consider load X and Y, both referencing the same cache line that is not in the L1 cache.  If load X misses cache first, it obtains and WCB (or fill buffer) and begins the process of requesting the data.  When load Y requests the data, it will either hit the WCB, or the L1 cache, depending on exactly what time the request to Y occurs.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.DRAM_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Loads retired that came from DRAM (Precise event capable))",
      R"(Counts memory load uops retired where the data is retrieved from DRAM.  Event is counted at retirement, so the speculative loads are ignored.  A memory load can hit (or miss) the L1 cache, hit (or miss) the L2 cache, hit DRAM, hit in the WCB or receive a HITM response.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ALL",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(BACLEARs asserted for any branch type)",
      R"(Counts the number of times a BACLEAR is signaled for any reason, including, but not limited to indirect branch/call,  Jcc (Jump on Conditional Code/Jump if Condition is Met) branch, unconditional branch/call, and returns.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.RETURN",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(BACLEARs asserted for return branch)",
      R"(Counts BACLEARS on return instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.COND",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(BACLEARs asserted for conditional branch)",
      R"(Counts BACLEARS on Jcc (Jump on Conditional Code/Jump if Condition is Met) branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MS_DECODED.MS_ENTRY",
      EventDef::Encoding{
          .code = 0xE7, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(MS decode starts)",
      R"(Counts the number of times the Microcode Sequencer (MS) starts a flow of uops from the MSROM. It does not count every time a uop is read from the MSROM.  The most common case that this counts is when a micro-coded instruction is encountered by the front end of the machine.  Other cases include when an instruction encounters a fault, trap, or microcode assist of any sort that initiates a flow of uops.  The event will count MS startups for uops that are speculative, and subsequently cleared by branch mispredict or a machine clear.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DECODE_RESTRICTION.PREDECODE_WRONG",
      EventDef::Encoding{
          .code = 0xE9, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Decode restrictions due to predicting wrong instruction length)",
      R"(Counts the number of times the prediction (from the predecode cache) for instruction length is incorrect.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x36000032b7}},
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache.)",
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10000032b7}},
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x04000032b7}},
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x02000032b7}},
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00000432b7}},
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that hit the L2 cache.)",
      R"(Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000022}},
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache.)",
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000022}},
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000022}},
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000022}},
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040022}},
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that hit the L2 cache.)",
      R"(Counts reads for ownership (RFO) requests (demand & prefetch) that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600003091}},
      R"(Counts data reads (demand & prefetch) that miss the L2 cache.)",
      R"(Counts data reads (demand & prefetch) that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000003091}},
      R"(Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400003091}},
      R"(Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200003091}},
      R"(Counts data reads (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts data reads (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000043091}},
      R"(Counts data reads (demand & prefetch) that hit the L2 cache.)",
      R"(Counts data reads (demand & prefetch) that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600003010}},
      R"(Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache.)",
      R"(Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000003010}},
      R"(Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400003010}},
      R"(Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200003010}},
      R"(Counts data reads generated by L1 or L2 prefetchers that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts data reads generated by L1 or L2 prefetchers that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000043010}},
      R"(Counts data reads generated by L1 or L2 prefetchers that hit the L2 cache.)",
      R"(Counts data reads generated by L1 or L2 prefetchers that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000008000}},
      R"(Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400008000}},
      R"(Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200008000}},
      R"(Counts requests to the uncore subsystem that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts requests to the uncore subsystem that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000048000}},
      R"(Counts requests to the uncore subsystem that hit the L2 cache.)",
      R"(Counts requests to the uncore subsystem that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000018000}},
      R"(Counts requests to the uncore subsystem that have any transaction responses from the uncore subsystem.)",
      R"(Counts requests to the uncore subsystem that have any transaction responses from the uncore subsystem. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.STREAMING_STORES.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600004800}},
      R"(Counts any data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache.)",
      R"(Counts any data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.STREAMING_STORES.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000044800}},
      R"(Counts any data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache.)",
      R"(Counts any data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600004000}},
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache.)",
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000004000}},
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400004000}},
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200004000}},
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000044000}},
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache.)",
      R"(Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600002000}},
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache.)",
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000002000}},
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400002000}},
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200002000}},
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000042000}},
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that hit the L2 cache.)",
      R"(Counts data cache line reads generated by hardware L1 data cache prefetcher that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600001000}},
      R"(Counts data cache lines requests by software prefetch instructions that miss the L2 cache.)",
      R"(Counts data cache lines requests by software prefetch instructions that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000001000}},
      R"(Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400001000}},
      R"(Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200001000}},
      R"(Counts data cache lines requests by software prefetch instructions that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts data cache lines requests by software prefetch instructions that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.SW_PREFETCH.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000041000}},
      R"(Counts data cache lines requests by software prefetch instructions that hit the L2 cache.)",
      R"(Counts data cache lines requests by software prefetch instructions that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000800}},
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache.)",
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000800}},
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000800}},
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000800}},
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040800}},
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that hit the L2 cache.)",
      R"(Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010400}},
      R"(Counts bus lock and split lock requests that have any transaction responses from the uncore subsystem.)",
      R"(Counts bus lock and split lock requests that have any transaction responses from the uncore subsystem. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000100}},
      R"(Counts the number of demand write requests (RFO) generated by a write to partial data cache line, including the writes to uncacheable (UC) and write through (WT), and write protected (WP) types of memory that miss the L2 cache.)",
      R"(Counts the number of demand write requests (RFO) generated by a write to partial data cache line, including the writes to uncacheable (UC) and write through (WT), and write protected (WP) types of memory that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000080}},
      R"(Counts demand data partial reads, including data in uncacheable (UC) or uncacheable write combining (USWC) memory types that miss the L2 cache.)",
      R"(Counts demand data partial reads, including data in uncacheable (UC) or uncacheable write combining (USWC) memory types that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000020}},
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache.)",
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000020}},
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000020}},
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000020}},
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040020}},
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that hit the L2 cache.)",
      R"(Counts reads for ownership (RFO) requests generated by L2 prefetcher that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000010}},
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache.)",
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000010}},
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000010}},
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000010}},
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040010}},
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that hit the L2 cache.)",
      R"(Counts data cacheline reads generated by hardware L2 cache prefetcher that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.COREWB.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000008}},
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache.)",
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.COREWB.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000008}},
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.COREWB.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000008}},
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.COREWB.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000008}},
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.COREWB.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040008}},
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that hit the L2 cache.)",
      R"(Counts the number of writeback transactions caused by L1 or L2 cache evictions that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000004}},
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that are outstanding, per cycle, from the time of the L2 miss to when any response is received.)",
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that are outstanding, per cycle, from the time of the L2 miss to when any response is received. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000004}},
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache.)",
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000004}},
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000004}},
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040004}},
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that hit the L2 cache.)",
      R"(Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000002}},
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that are outstanding, per cycle, from the time of the L2 miss to when any response is received.)",
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that are outstanding, per cycle, from the time of the L2 miss to when any response is received. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000002}},
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache.)",
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000002}},
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000002}},
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000002}},
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040002}},
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that hit the L2 cache.)",
      R"(Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000001}},
      R"(Counts demand cacheable data reads of full cache lines that are outstanding, per cycle, from the time of the L2 miss to when any response is received.)",
      R"(Counts demand cacheable data reads of full cache lines that are outstanding, per cycle, from the time of the L2 miss to when any response is received. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3600000001}},
      R"(Counts demand cacheable data reads of full cache lines that miss the L2 cache.)",
      R"(Counts demand cacheable data reads of full cache lines that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000001}},
      R"(Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.)",
      R"(Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0400000001}},
      R"(Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.)",
      R"(Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0200000001}},
      R"(Counts demand cacheable data reads of full cache lines that true miss for the L2 cache with a snoop miss in the other processor module. )",
      R"(Counts demand cacheable data reads of full cache lines that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000040001}},
      R"(Counts demand cacheable data reads of full cache lines that hit the L2 cache.)",
      R"(Counts demand cacheable data reads of full cache lines that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));
}

} // namespace goldmont_core
} // namespace facebook::hbt::perf_event::generated
