// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace knightslanding_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from KnightsLanding_core.json (374 events).

    Supported SKUs:
        - Arch: x86, Model: KNL id: 87
        - Arch: x86, Model: KNM id: 133
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of branch instructions retired)",
      R"(Counts the number of branch instructions retired)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.JCC",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x7E, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of branch instructions retired that were conditional jumps.)",
      R"(Counts the number of branch instructions retired that were conditional jumps.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.TAKEN_JCC",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xFE, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of branch instructions retired that were conditional jumps and predicted taken.)",
      R"(Counts the number of branch instructions retired that were conditional jumps and predicted taken.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xF9, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of near CALL branch instructions retired.)",
      R"(Counts the number of near CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.REL_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xFD, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of near relative CALL branch instructions retired.)",
      R"(Counts the number of near relative CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.IND_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xFB, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of near indirect CALL branch instructions retired.)",
      R"(Counts the number of near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.RETURN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xF7, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of near RET branch instructions retired.)",
      R"(Counts the number of near RET branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NON_RETURN_IND",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xEB, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of branch instructions retired that were near indirect CALL or near indirect JMP.)",
      R"(Counts the number of branch instructions retired that were near indirect CALL or near indirect JMP.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0xBF, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of far branch instructions retired.)",
      R"(Counts the number of far branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted branch instructions retired)",
      R"(Counts the number of mispredicted branch instructions retired)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.JCC",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x7E, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted branch instructions retired that were conditional jumps.)",
      R"(Counts the number of mispredicted branch instructions retired that were conditional jumps.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.TAKEN_JCC",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xFE, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted branch instructions retired that were conditional jumps and predicted taken.)",
      R"(Counts the number of mispredicted branch instructions retired that were conditional jumps and predicted taken.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.IND_CALL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xFB, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted near indirect CALL branch instructions retired.)",
      R"(Counts the number of mispredicted near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.RETURN",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xF7, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted near RET branch instructions retired.)",
      R"(Counts the number of mispredicted near RET branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NON_RETURN_IND",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xEB, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted branch instructions retired that were near indirect CALL or near indirect JMP.)",
      R"(Counts the number of mispredicted branch instructions retired that were near indirect CALL or near indirect JMP.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.MS",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of micro-ops retired that are from the complex flows issued by the micro-sequencer (MS).)",
      R"(This event counts the number of micro-ops retired that were supplied from MSROM.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of micro-ops retired)",
      R"(This event counts the number of micro-ops (uops) retired. The processor decodes complex macro instructions into a sequence of simpler uops. Most instructions are composed of one or two uops. Some instructions are decoded into longer sequences such as repeat instructions, floating point transcendental instructions, and assists. )",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.SCALAR_SIMD",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of scalar SSE, AVX, AVX2, AVX-512 micro-ops retired. More specifically, it counts scalar SSE, AVX, AVX2, AVX-512 micro-ops except for loads (memory-to-register mov-type micro ops), division, sqrt.)",
      R"(This event counts the number of scalar SSE, AVX, AVX2, AVX-512 micro-ops retired (floating point, integer and store) except for loads (memory-to-register mov-type micro ops), division, sqrt.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.PACKED_SIMD",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of vector SSE, AVX, AVX2, AVX-512 micro-ops retired. More specifically, it counts packed SSE, AVX, AVX2, AVX-512 micro-ops (both floating point and integer) except for loads (memory-to-register mov-type micro-ops), packed byte and word multiplies.)",
      R"(This event counts the number of packed vector SSE, AVX, AVX2, and AVX-512 micro-ops retired (floating point, integer and store) except for loads (memory-to-register mov-type micro-ops), packed byte and word multiplies.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SMC",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times that the machine clears due to program modifying data within 1K of a recently fetched code page)",
      R"(Counts the number of times that the machine clears due to program modifying data within 1K of a recently fetched code page)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times the machine clears due to memory ordering hazards)",
      R"(Counts the number of times the machine clears due to memory ordering hazards)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.FP_ASSIST",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of floating operations retired that required microcode assists)",
      R"(This event counts the number of times that the pipeline stalled due to FP operations needing assists.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.ALL",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Counts all nukes)",
      R"(Counts all nukes)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "NO_ALLOC_CYCLES.ROB_FULL",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of core cycles when no micro-ops are allocated and the ROB is full)",
      R"(Counts the number of core cycles when no micro-ops are allocated and the ROB is full)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "NO_ALLOC_CYCLES.MISPREDICTS",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of core cycles when no micro-ops are allocated and the alloc pipe is stalled waiting for a mispredicted branch to retire.)",
      R"(This event counts the number of core cycles when no uops are allocated and the alloc pipe is stalled waiting for a mispredicted branch to retire.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "NO_ALLOC_CYCLES.RAT_STALL",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of core cycles when no micro-ops are allocated and a RATstall (caused by reservation station full) is asserted.  )",
      R"(Counts the number of core cycles when no micro-ops are allocated and a RATstall (caused by reservation station full) is asserted.  )",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "NO_ALLOC_CYCLES.NOT_DELIVERED",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x90, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of core cycles when no micro-ops are allocated, the IQ is empty, and no other condition is blocking allocation.)",
      R"(This event counts the number of core cycles when no uops are allocated, the instruction queue is empty and the alloc pipe is stalled waiting for instructions to be fetched.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "NO_ALLOC_CYCLES.ALL",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x7F, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number of core cycles when no micro-ops are allocated for any reason.)",
      R"(Counts the total number of core cycles when no micro-ops are allocated for any reason.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RS_FULL_STALL.MEC",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of core cycles when allocation pipeline is stalled and is waiting for a free MEC reservation station entry.)",
      R"(Counts the number of core cycles when allocation pipeline is stalled and is waiting for a free MEC reservation station entry.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RS_FULL_STALL.ALL",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x1F, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number of core cycles the Alloc pipeline is stalled when any one of the reservation stations is full. )",
      R"(Counts the total number of core cycles the Alloc pipeline is stalled when any one of the reservation stations is full. )",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number of instructions retired)",
      R"(Counts the total number of instructions retired)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.ALL",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles the number of core cycles when divider is busy.  Does not imply a stall waiting for the divider.  )",
      R"(This event counts cycles when the divider is busy. More specifically cycles when the divide unit is unable to accept a new divide uop because it is busy processing a previously dispatched uop. The cycles will be counted irrespective of whether or not another divide uop is waiting to enter the divide unit (from the RS). This event counts integer divides, x87 divides, divss, divsd, sqrtss, sqrtsd event and does not count vector divides.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Fixed Counter: Counts the number of instructions retired)",
      R"(This event counts the number of instructions that retire.  For instructions that consist of multiple micro-ops, this event counts exactly once, as the last micro-op of the instruction retires.  The event continues counting while instructions retire, including during interrupt service routines caused by hardware interrupts, faults or traps.)",
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
      R"(Counts the number of unhalted core clock cycles)",
      R"(Counts the number of unhalted core clock cycles)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of unhalted reference clock cycles)",
      R"(Counts the number of unhalted reference clock cycles)",
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
      R"(Fixed Counter: Counts the number of unhalted core clock cycles)",
      R"(This event counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter
)",
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
      R"(Fixed Counter: Counts the number of unhalted reference clock cycles)",
      R"(Fixed Counter: Counts the number of unhalted reference clock cycles)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REQUESTS_REJECT.ALL",
      EventDef::Encoding{
          .code = 0x30, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of MEC requests from the L2Q that reference a cache line (cacheable requests) exlcuding SW prefetches filling only to L2 cache and L1 evictions (automatically exlcudes L2HWP, UC, WC) that were rejected - Multiple repeated rejects should be counted multiple times)",
      R"(Counts the number of MEC requests from the L2Q that reference a cache line (cacheable requests) exlcuding SW prefetches filling only to L2 cache and L1 evictions (automatically exlcudes L2HWP, UC, WC) that were rejected - Multiple repeated rejects should be counted multiple times)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_REJECT_L2Q.ALL",
      EventDef::Encoding{
          .code = 0x31, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of MEC requests that were not accepted into the L2Q because of any L2  queue reject condition. There is no concept of at-ret here. It might include requests due to instructions in the speculative path.)",
      R"(Counts the number of MEC requests that were not accepted into the L2Q because of any L2  queue reject condition. There is no concept of at-ret here. It might include requests due to instructions in the speculative path.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REQUESTS.REFERENCE",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x4F, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number of L2 cache references.)",
      R"(Counts the total number of L2 cache references.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REQUESTS.MISS",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of L2 cache misses)",
      R"(Counts the number of L2 cache misses)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.ACCESSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x03, .cmask = 0, .msr_values = {0}},
      R"(Counts all instruction fetches, including uncacheable fetches.)",
      R"(Counts all instruction fetches, including uncacheable fetches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.HIT",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts all instruction fetches that hit the instruction cache.)",
      R"(Counts all instruction fetches that hit the instruction cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts all instruction fetches that miss the instruction cache or produce memory requests. An instruction fetch miss is counted only once and not once for every cycle it is outstanding.)",
      R"(Counts all instruction fetches that miss the instruction cache or produce memory requests. An instruction fetch miss is counted only once and not once for every cycle it is outstanding.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FETCH_STALL.ICACHE_FILL_PENDING_CYCLES",
      EventDef::Encoding{
          .code = 0x86, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of core cycles the fetch stalls because of an icache miss. This is a cummulative count of core cycles the fetch stalled for all icache misses. )",
      R"(This event counts the number of core cycles the fetch stalls because of an icache miss. This is a cumulative count of cycles the NIP stalled for all icache misses. )",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ALL",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times the front end resteers for any branch as a result of another branch handling mechanism in the front end.)",
      R"(Counts the number of times the front end resteers for any branch as a result of another branch handling mechanism in the front end.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.RETURN",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times the front end resteers for RET branches as a result of another branch handling mechanism in the front end.)",
      R"(Counts the number of times the front end resteers for RET branches as a result of another branch handling mechanism in the front end.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.COND",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times the front end resteers for conditional branches as a result of another branch handling mechanism in the front end.)",
      R"(Counts the number of times the front end resteers for conditional branches as a result of another branch handling mechanism in the front end.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MS_DECODED.MS_ENTRY",
      EventDef::Encoding{
          .code = 0xE7, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of times the MSROM starts a flow of uops.)",
      R"(Counts the number of times the MSROM starts a flow of uops.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.LD_BLOCK_ST_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of occurences a retired load gets blocked because its address partially overlaps with a store )",
      R"(Counts the number of occurences a retired load gets blocked because its address partially overlaps with a store )",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.LD_BLOCK_STD_NOTREADY",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of occurences a retired load gets blocked because its address overlaps with a store whose data is not ready)",
      R"(Counts the number of occurences a retired load gets blocked because its address overlaps with a store whose data is not ready)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.ST_SPLITS",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of occurences a retired store that is a cache line split. Each split should be counted only once.)",
      R"(This event counts the number of retired store that experienced a cache line boundary split(Precise Event). Note that each spilt should be counted only once.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.LD_SPLITS",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of occurences a retired load that is a cache line split. Each split should be counted only once.)",
      R"(Counts the number of occurences a retired load that is a cache line split. Each split should be counted only once.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.LOCK",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts all the retired locked loads. It does not include stores because we would double count if we count stores)",
      R"(Counts all the retired locked loads. It does not include stores because we would double count if we count stores)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.STA_FULL",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Counts the store micro-ops retired that were pushed in the rehad queue because the store address buffer is full)",
      R"(Counts the store micro-ops retired that were pushed in the rehad queue because the store address buffer is full)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.ANY_LD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Counts any retired load that was pushed into the recycle queue for any reason.)",
      R"(Counts any retired load that was pushed into the recycle queue for any reason.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RECYCLEQ.ANY_ST",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Counts any retired store that was pushed into the recycle queue for any reason.)",
      R"(Counts any retired store that was pushed into the recycle queue for any reason.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.L1_MISS_LOADS",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of load micro-ops retired that miss in L1 D cache)",
      R"(This event counts the number of load micro-ops retired that miss in L1 Data cache. Note that prefetch misses will not be counted. )",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.L2_HIT_LOADS",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of load micro-ops retired that hit in the L2)",
      R"(Counts the number of load micro-ops retired that hit in the L2)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.L2_MISS_LOADS",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of load micro-ops retired that miss in the L2)",
      R"(Counts the number of load micro-ops retired that miss in the L2)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.DTLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of load micro-ops retired that cause a DTLB miss)",
      R"(Counts the number of load micro-ops retired that cause a DTLB miss)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.UTLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of load micro-ops retired that caused micro TLB miss)",
      R"(Counts the number of load micro-ops retired that caused micro TLB miss)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.HITM",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Counts the loads retired that get the data from the other core in the same tile in M state)",
      R"(Counts the loads retired that get the data from the other core in the same tile in M state)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Counts all the load micro-ops retired)",
      R"(This event counts the number of load micro-ops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Counts all the store micro-ops retired)",
      R"(This event counts the number of store micro-ops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.D_SIDE_WALKS",
      EventDef::Encoding{
          .code = 0x05,
          .umask = 0x01,
          .edge = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Counts the total D-side page walks that are completed or started. The page walks started in the speculative path will also be counted)",
      R"(Counts the total D-side page walks that are completed or started. The page walks started in the speculative path will also be counted)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.D_SIDE_CYCLES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number of core cycles for all the D-side page walks. The cycles for page walks started in speculative path will also be included.)",
      R"(Counts the total number of core cycles for all the D-side page walks. The cycles for page walks started in speculative path will also be included.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.I_SIDE_WALKS",
      EventDef::Encoding{
          .code = 0x05,
          .umask = 0x02,
          .edge = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Counts the total I-side page walks that are completed.)",
      R"(Counts the total I-side page walks that are completed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.I_SIDE_CYCLES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number of core cycles for all the I-side page walks. The cycles for page walks started in speculative path will also be included.)",
      R"(This event counts every cycle when an I-side (walks due to an instruction fetch) page walk is in progress. )",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.WALKS",
      EventDef::Encoding{
          .code = 0x05,
          .umask = 0x03,
          .edge = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Counts the total page walks that are completed (I-side and D-side))",
      R"(Counts the total page walks that are completed (I-side and D-side))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.CYCLES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x03, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number of core cycles for all the page walks. The cycles for page walks started in speculative path will also be included.)",
      R"(This event counts every cycle when a data (D) page walk or instruction (I) page walk is in progress.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the matrix events specified by MSR_OFFCORE_RESPx)",
      R"(Counts the matrix events specified by MSR_OFFCORE_RESPx)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.CALL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xF9, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted near CALL branch instructions retired.)",
      R"(Counts the number of mispredicted near CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.REL_CALL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xFD, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted near relative CALL branch instructions retired.)",
      R"(Counts the number of mispredicted near relative CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0xBF, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of mispredicted far branch instructions retired.)",
      R"(Counts the number of mispredicted far branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000070}},
      R"(Counts any Prefetch requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts any Prefetch requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400070}},
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400070}},
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080070}},
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080070}},
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400070}},
      R"(Counts any Prefetch requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts any Prefetch requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200070}},
      R"(Counts any Prefetch requests that accounts for data responses from MCDRAM Local.)",
      R"(Counts any Prefetch requests that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000070}},
      R"(Counts any Prefetch requests that accounts for data responses from DRAM Far. )",
      R"(Counts any Prefetch requests that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800070}},
      R"(Counts any Prefetch requests that accounts for data responses from DRAM Local.)",
      R"(Counts any Prefetch requests that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010070}},
      R"(Counts any Prefetch requests that accounts for any response)",
      R"(Counts any Prefetch requests that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x40000032f7}},
      R"(Counts any Read request  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts any Read request  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10004032f7}},
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x08004032f7}},
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10000832f7}},
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x08000832f7}},
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x01004032f7}},
      R"(Counts any Read request  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts any Read request  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00802032f7}},
      R"(Counts any Read request  that accounts for data responses from MCDRAM Local.)",
      R"(Counts any Read request  that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x01010032f7}},
      R"(Counts any Read request  that accounts for data responses from DRAM Far. )",
      R"(Counts any Read request  that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00808032f7}},
      R"(Counts any Read request  that accounts for data responses from DRAM Local.)",
      R"(Counts any Read request  that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00000132f7}},
      R"(Counts any Read request  that accounts for any response)",
      R"(Counts any Read request  that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000044}},
      R"(Counts Demand code reads and prefetch code read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts Demand code reads and prefetch code read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Local.)",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Far. )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Local.)",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for any response)",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000022}},
      R"(Counts Demand cacheable data write requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts Demand cacheable data write requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400022}},
      R"(Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200022}},
      R"(Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Local.)",
      R"(Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000022}},
      R"(Counts Demand cacheable data write requests  that accounts for data responses from DRAM Far. )",
      R"(Counts Demand cacheable data write requests  that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800022}},
      R"(Counts Demand cacheable data write requests  that accounts for data responses from DRAM Local.)",
      R"(Counts Demand cacheable data write requests  that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010022}},
      R"(Counts Demand cacheable data write requests  that accounts for any response)",
      R"(Counts Demand cacheable data write requests  that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000003091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000403091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800403091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000083091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800083091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100403091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080203091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Local.)",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101003091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Far. )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080803091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Local.)",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000013091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for any response)",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000008000}},
      R"(Counts any request that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts any request that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000408000}},
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800408000}},
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000088000}},
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800088000}},
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100408000}},
      R"(Counts any request that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts any request that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080208000}},
      R"(Counts any request that accounts for data responses from MCDRAM Local.)",
      R"(Counts any request that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101008000}},
      R"(Counts any request that accounts for data responses from DRAM Far. )",
      R"(Counts any request that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080808000}},
      R"(Counts any request that accounts for data responses from DRAM Local.)",
      R"(Counts any request that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000018000}},
      R"(Counts any request that accounts for any response)",
      R"(Counts any request that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.STREAMING_STORES.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000014800}},
      R"(Counts all streaming stores (WC and should be programmed on PMC1) that accounts for any response)",
      R"(Counts all streaming stores (WC and should be programmed on PMC1) that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000014000}},
      R"(Counts Partial streaming stores (WC and should be programmed on PMC1) that accounts for any response)",
      R"(Counts Partial streaming stores (WC and should be programmed on PMC1) that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000002000}},
      R"(Counts L1 data HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts L1 data HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000402000}},
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800402000}},
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000082000}},
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800082000}},
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100402000}},
      R"(Counts L1 data HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts L1 data HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080202000}},
      R"(Counts L1 data HW prefetches that accounts for data responses from MCDRAM Local.)",
      R"(Counts L1 data HW prefetches that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101002000}},
      R"(Counts L1 data HW prefetches that accounts for data responses from DRAM Far. )",
      R"(Counts L1 data HW prefetches that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080802000}},
      R"(Counts L1 data HW prefetches that accounts for data responses from DRAM Local.)",
      R"(Counts L1 data HW prefetches that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000012000}},
      R"(Counts L1 data HW prefetches that accounts for any response)",
      R"(Counts L1 data HW prefetches that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000001000}},
      R"(Counts Software Prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts Software Prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000401000}},
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800401000}},
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000081000}},
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800081000}},
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100401000}},
      R"(Counts Software Prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Software Prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080201000}},
      R"(Counts Software Prefetches that accounts for data responses from MCDRAM Local.)",
      R"(Counts Software Prefetches that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101001000}},
      R"(Counts Software Prefetches that accounts for data responses from DRAM Far. )",
      R"(Counts Software Prefetches that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080801000}},
      R"(Counts Software Prefetches that accounts for data responses from DRAM Local.)",
      R"(Counts Software Prefetches that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000011000}},
      R"(Counts Software Prefetches that accounts for any response)",
      R"(Counts Software Prefetches that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.FULL_STREAMING_STORES.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010800}},
      R"(Counts Full streaming stores (WC and should be programmed on PMC1) that accounts for any response)",
      R"(Counts Full streaming stores (WC and should be programmed on PMC1) that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000400}},
      R"(Counts Bus locks and split lock requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts Bus locks and split lock requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400400}},
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400400}},
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080400}},
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080400}},
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400400}},
      R"(Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200400}},
      R"(Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Local.)",
      R"(Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000400}},
      R"(Counts Bus locks and split lock requests that accounts for data responses from DRAM Far. )",
      R"(Counts Bus locks and split lock requests that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800400}},
      R"(Counts Bus locks and split lock requests that accounts for data responses from DRAM Local.)",
      R"(Counts Bus locks and split lock requests that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010400}},
      R"(Counts Bus locks and split lock requests that accounts for any response)",
      R"(Counts Bus locks and split lock requests that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Local.)",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Far. )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Local.)",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for any response)",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Local.)",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Far. )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Local.)",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for any response)",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.NON_DRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2000020080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from any NON_DRAM system address. This includes MMIO transactions)",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from any NON_DRAM system address. This includes MMIO transactions)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Local.)",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Far. )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Local.)",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for any response)",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000040}},
      R"(Counts L2 code HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts L2 code HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400040}},
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400040}},
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080040}},
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080040}},
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400040}},
      R"(Counts L2 code HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts L2 code HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200040}},
      R"(Counts L2 code HW prefetches that accounts for data responses from MCDRAM Local.)",
      R"(Counts L2 code HW prefetches that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000040}},
      R"(Counts L2 code HW prefetches that accounts for data responses from DRAM Far. )",
      R"(Counts L2 code HW prefetches that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800040}},
      R"(Counts L2 code HW prefetches that accounts for data responses from DRAM Local.)",
      R"(Counts L2 code HW prefetches that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010040}},
      R"(Counts L2 code HW prefetches that accounts for any response)",
      R"(Counts L2 code HW prefetches that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.NON_DRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2000020020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from any NON_DRAM system address. This includes MMIO transactions)",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from any NON_DRAM system address. This includes MMIO transactions)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Local.)",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Far. )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Local.)",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000020020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that provides no supplier details)",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that provides no supplier details)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for any response)",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000004}},
      R"(Counts demand code reads and prefetch code reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts demand code reads and prefetch code reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400004}},
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200004}},
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Local.)",
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000004}},
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Far. )",
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800004}},
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Local.)",
      R"(Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010004}},
      R"(Counts demand code reads and prefetch code reads that accounts for any response)",
      R"(Counts demand code reads and prefetch code reads that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000002}},
      R"(Counts Demand cacheable data writes that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts Demand cacheable data writes that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400002}},
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400002}},
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080002}},
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080002}},
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400002}},
      R"(Counts Demand cacheable data writes that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts Demand cacheable data writes that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200002}},
      R"(Counts Demand cacheable data writes that accounts for data responses from MCDRAM Local.)",
      R"(Counts Demand cacheable data writes that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000002}},
      R"(Counts Demand cacheable data writes that accounts for data responses from DRAM Far. )",
      R"(Counts Demand cacheable data writes that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800002}},
      R"(Counts Demand cacheable data writes that accounts for data responses from DRAM Local.)",
      R"(Counts Demand cacheable data writes that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010002}},
      R"(Counts Demand cacheable data writes that accounts for any response)",
      R"(Counts Demand cacheable data writes that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x4000000001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      R"(Counts demand cacheable data and L1 prefetch data reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The oustanding response should be programmed only on PMC0. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_FAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000400001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_FAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800400001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_NEAR_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000080001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_NEAR_TILE_E_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0800080001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.MCDRAM_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0100400001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.MCDRAM_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080200001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Local.)",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.DDR_FAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0101000001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Far. )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Far. )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.DDR_NEAR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0080800001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Local.)",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Local.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0000010001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for any response)",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for any response)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from MCDRAM (local and far))",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600002}},
      R"(Counts Demand cacheable data writes that accounts for responses from MCDRAM (local and far))",
      R"(Counts Demand cacheable data writes that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses from MCDRAM (local and far))",
      R"(Counts demand code reads and prefetch code reads that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from MCDRAM (local and far))",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from MCDRAM (local and far))",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from MCDRAM (local and far))",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from MCDRAM (local and far))",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600400}},
      R"(Counts Bus locks and split lock requests that accounts for responses from MCDRAM (local and far))",
      R"(Counts Bus locks and split lock requests that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180601000}},
      R"(Counts Software Prefetches that accounts for responses from MCDRAM (local and far))",
      R"(Counts Software Prefetches that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180608000}},
      R"(Counts any request that accounts for responses from MCDRAM (local and far))",
      R"(Counts any request that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180603091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from MCDRAM (local and far))",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses from MCDRAM (local and far))",
      R"(Counts Demand cacheable data write requests  that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from MCDRAM (local and far))",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x01806032f7}},
      R"(Counts any Read request  that accounts for responses from MCDRAM (local and far))",
      R"(Counts any Read request  that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.MCDRAM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0180600070}},
      R"(Counts any Prefetch requests that accounts for responses from MCDRAM (local and far))",
      R"(Counts any Prefetch requests that accounts for responses from MCDRAM (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from DDR (local and far))",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800002}},
      R"(Counts Demand cacheable data writes that accounts for responses from DDR (local and far))",
      R"(Counts Demand cacheable data writes that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses from DDR (local and far))",
      R"(Counts demand code reads and prefetch code reads that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from DDR (local and far))",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800040}},
      R"(Counts L2 code HW prefetches that accounts for responses from DDR (local and far))",
      R"(Counts L2 code HW prefetches that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from DDR (local and far))",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from DDR (local and far))",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800400}},
      R"(Counts Bus locks and split lock requests that accounts for responses from DDR (local and far))",
      R"(Counts Bus locks and split lock requests that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181801000}},
      R"(Counts Software Prefetches that accounts for responses from DDR (local and far))",
      R"(Counts Software Prefetches that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181802000}},
      R"(Counts L1 data HW prefetches that accounts for responses from DDR (local and far))",
      R"(Counts L1 data HW prefetches that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181808000}},
      R"(Counts any request that accounts for responses from DDR (local and far))",
      R"(Counts any request that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181803091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from DDR (local and far))",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses from DDR (local and far))",
      R"(Counts Demand cacheable data write requests  that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0181800044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from DDR (local and far))",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.DDR",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x01818032f7}},
      R"(Counts any Read request  that accounts for responses from DDR (local and far))",
      R"(Counts any Read request  that accounts for responses from DDR (local and far))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000002}},
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000400}},
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002001000}},
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002002000}},
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002008000}},
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002003091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00020032f7}},
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_THIS_TILE_M",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0002000070}},
      R"(Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in M state )",
      R"(Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in M state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000002}},
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000040}},
      R"(Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000400}},
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004001000}},
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004002000}},
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004008000}},
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004003091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00040032f7}},
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_THIS_TILE_E",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0004000070}},
      R"(Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in E state )",
      R"(Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in E state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000002}},
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000400}},
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008001000}},
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008002000}},
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008008000}},
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008003091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0008000044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_S",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00080032f7}},
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in S state )",
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in S state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000001}},
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000002}},
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000004}},
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000040}},
      R"(Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000400}},
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010001000}},
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010002000}},
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010008000}},
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts any request that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010003091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000022}},
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x00100032f7}},
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts any Read request  that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_THIS_TILE_F",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x0010000070}},
      R"(Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in F state )",
      R"(Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in F state )",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180002}},
      R"(Counts Demand cacheable data writes that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Demand cacheable data writes that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180004}},
      R"(Counts demand code reads and prefetch code reads that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts demand code reads and prefetch code reads that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180020}},
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180040}},
      R"(Counts L2 code HW prefetches that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts L2 code HW prefetches that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180200}},
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts UC code reads (valid only for Outstanding response type)  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180400}},
      R"(Counts Bus locks and split lock requests that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Bus locks and split lock requests that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800181000}},
      R"(Counts Software Prefetches that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Software Prefetches that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800182000}},
      R"(Counts L1 data HW prefetches that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts L1 data HW prefetches that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800188000}},
      R"(Counts any request that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts any request that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800183091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180022}},
      R"(Counts Demand cacheable data write requests  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Demand cacheable data write requests  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x18001832f7}},
      R"(Counts any Read request  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts any Read request  that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_NEAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800180070}},
      R"(Counts any Prefetch requests that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      R"(Counts any Prefetch requests that accounts for reponses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400002}},
      R"(Counts Demand cacheable data writes that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Demand cacheable data writes that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400004}},
      R"(Counts demand code reads and prefetch code reads that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts demand code reads and prefetch code reads that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400040}},
      R"(Counts L2 code HW prefetches that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts L2 code HW prefetches that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400080}},
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400100}},
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400400}},
      R"(Counts Bus locks and split lock requests that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Bus locks and split lock requests that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800401000}},
      R"(Counts Software Prefetches that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Software Prefetches that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800402000}},
      R"(Counts L1 data HW prefetches that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts L1 data HW prefetches that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800408000}},
      R"(Counts any request that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts any request that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800403091}},
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Demand cacheable data and L1 prefetch data read requests  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400022}},
      R"(Counts Demand cacheable data write requests  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Demand cacheable data write requests  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400044}},
      R"(Counts Demand code reads and prefetch code read requests  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts Demand code reads and prefetch code read requests  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_READ.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x18004032f7}},
      R"(Counts any Read request  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts any Read request  that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_FAR_TILE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1800400070}},
      R"(Counts any Prefetch requests that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      R"(Counts any Prefetch requests that accounts for reponses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace knightslanding_core
} // namespace facebook::hbt::perf_event::generated
