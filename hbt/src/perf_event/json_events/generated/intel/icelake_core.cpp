// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace icelake_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from icelake_core.json (326 events).

    Supported SKUs:
        - Arch: x86, Model: ICL id: 125
        - Arch: x86, Model: ICL id: 126
        - Arch: x86, Model: ICL id: 167
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_16B.IFDATA_STALL",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles where a code fetch is stalled due to L1 instruction cache miss.)",
      R"(Counts cycles where a code line fetch is stalled due to an L1 instruction cache miss. The legacy decode pipeline works at a 16 Byte granularity.)",
      500009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_64B.IFTAG_HIT",
      EventDef::Encoding{
          .code = 0x83, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Instruction fetch tag lookups that hit in the instruction cache (L1I). Counts at 64-byte cache-line granularity.)",
      R"(Counts instruction fetch tag lookups that hit in the instruction cache (L1I). Counts at 64-byte cache-line granularity. Accounts for both cacheable and uncacheable accesses.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_64B.IFTAG_MISS",
      EventDef::Encoding{
          .code = 0x83, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Instruction fetch tag lookups that miss in the instruction cache (L1I). Counts at 64-byte cache-line granularity.)",
      R"(Counts instruction fetch tag lookups that miss in the instruction cache (L1I). Counts at 64-byte cache-line granularity. Accounts for both cacheable and uncacheable accesses.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE_64B.IFTAG_STALL",
      EventDef::Encoding{
          .code = 0x83, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles where a code fetch is stalled due to L1 instruction cache tag miss.)",
      R"(Counts cycles where a code fetch is stalled due to L1 instruction cache tag miss.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ANY",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      R"(Counts the number of times the front-end is resteered when it finds a branch instruction in a fetch line. This occurs for the first time a branch instruction is fetched or when the branch is not tracked by the BPU (Branch Prediction Unit) anymore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.UOPS",
      EventDef::Encoding{
          .code = 0xa8, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of Uops delivered by the LSD.)",
      R"(Counts the number of uops delivered to the back-end by the LSD(Loop Stream Detector).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.LCP",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Stalls caused by changing prefix length of the instruction.)",
      R"(Counts cycles that the Instruction Length decoder (ILD) stalls occurred due to dynamically changing prefix length of the decoded instruction (by operand size prefix instruction 0x66, address size prefix instruction 0x67 or REX.W for Intel64). Count is proportional to the number of prefixes in a 16B-line. This may result in a three-cycle penalty for each LCP (Length changing prefix) in a 16-byte chunk.)",
      500009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_DECODED.DECODERS",
      EventDef::Encoding{
          .code = 0x55, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Instruction decoders utilized in a cycle)",
      R"(Number of decoders utilized in a cycle when the MITE (legacy decode pipeline) fetches instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path)",
      R"(Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.DSB_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path)",
      R"(Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CORE",
      EventDef::Encoding{
          .code = 0x9c, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Uops not delivered by IDQ when backend of the machine is not stalled)",
      R"(Counts the number of uops not delivered to by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB2MITE_SWITCHES.PENALTY_CYCLES",
      EventDef::Encoding{
          .code = 0xab, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(DSB-to-MITE switch true penalty cycles.)",
      R"(Decode Stream Buffer (DSB) is a Uop-cache that holds translations of previously fetched instructions that were decoded by the legacy x86 decode pipeline (MITE). This event counts fetch penalty cycles when a transition occurs from DSB to MITE.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN.BACKEND_BOUND_SLOTS",
      EventDef::Encoding{
          .code = 0xa4, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(TMA slots where no uops were being issued due to lack of back-end resources.)",
      R"(Counts the number of Top-down Microarchitecture Analysis (TMA) method's  slots where no micro-operations were being issued from front-end to back-end of the machine due to lack of back-end resources.)",
      10000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN.BR_MISPREDICT_SLOTS",
      EventDef::Encoding{
          .code = 0xa4, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(TMA slots wasted due to incorrect speculation by branch mispredictions)",
      R"(Number of TMA slots that were wasted due to incorrect speculation by branch mispredictions. This event estimates number of operations that were issued but not retired from the specualtive path as well as the out-of-order engine recovery past a branch misprediction.)",
      10000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Core cycles the allocator was stalled due to recovery from earlier clear event for this thread)",
      R"(Counts core cycles when the Resource allocator was stalled due to recovery from an earlier branch misprediction or machine clear event.)",
      500009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.UOP_DROPPING",
      EventDef::Encoding{
          .code = 0x0d, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(TMA slots where uops got dropped)",
      R"(Estimated number of Top-down Microarchitecture Analysis slots that got dropped due to non front-end reasons)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.CLEAR_RESTEER_CYCLES",
      EventDef::Encoding{
          .code = 0x0d, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts cycles after recovery from a branch misprediction or machine clear till the first uop is issued from the resteered path.)",
      R"(Cycles after recovery from a branch misprediction or machine clear till the first uop is issued from the resteered path.)",
      500009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.SCOREBOARD",
      EventDef::Encoding{
          .code = 0xa2, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts cycles where the pipeline is stalled due to serializing operations.)",
      R"(Counts cycles where the pipeline is stalled due to serializing operations.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.SB",
      EventDef::Encoding{
          .code = 0xa2, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles stalled due to no store buffers available. (not including draining form sync).)",
      R"(Counts allocation stall cycles caused by the store buffer (SB) being full. This counts cycles that the pipeline back-end blocked uop delivery from the front-end.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0x0e, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Uops that RAT issues to RS)",
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
          .code = 0x0e, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Uops inserted at issue-stage in order to preserve upper bits of vector registers.)",
      R"(Counts the number of Blend Uops issued by the Resource Allocation Table (RAT) to the reservation station (RS) in order to preserve upper bits of vector registers. Starting with the Skylake microarchitecture, these Blend uops are needed since every Intel SSE instruction executed in Dirty Upper State needs to preserve bits 128-255 of the destination register. For more information, refer to Mixing Intel AVX and Intel SSE Code section of the Optimization Guide.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_EXEC.MISC2",
      EventDef::Encoding{
          .code = 0x5d, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of times a class of instructions that may cause a transactional abort was executed inside a transactional region)",
      R"(Counts Unfriendly TSX abort triggered by a vzeroupper instruction.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_EXEC.MISC3",
      EventDef::Encoding{
          .code = 0x5d, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an instruction execution caused the transactional nest count supported to be exceeded)",
      R"(Counts Unfriendly TSX abort triggered by a nest count that is too deep.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RS_EVENTS.EMPTY_CYCLES",
      EventDef::Encoding{
          .code = 0x5e, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles when Reservation Station (RS) is empty for the thread)",
      R"(Counts cycles during which the reservation station (RS) is empty for this logical processor. This is usually caused when the front-end pipeline runs into stravation periods (e.g. branch mispredictions or i-cache misses))",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.START",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE execution started.)",
      R"(Counts the number of times we entered an HLE region. Does not count nested transactions.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.COMMIT",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE execution successfully committed)",
      R"(Counts the number of times HLE commit succeeded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE execution aborted due to any reasons (multiple categories may count as one).)",
      R"(Counts the number of times HLE abort was triggered.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_MEM",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      R"(Counts the number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_UNFRIENDLY",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE execution aborted due to HLE-unfriendly instructions and certain unfriendly events (such as AD assists etc.).)",
      R"(Counts the number of times an HLE execution aborted due to HLE-unfriendly instructions and certain unfriendly events (such as AD assists etc.).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HLE_RETIRED.ABORTED_EVENTS",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE execution aborted due to unfriendly events (such as interrupts).)",
      R"(Counts the number of times an HLE execution aborted due to unfriendly events (such as interrupts).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.START",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an RTM execution started.)",
      R"(Counts the number of times we entered an RTM region. Does not count nested transactions.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.COMMIT",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an RTM execution successfully committed)",
      R"(Counts the number of times RTM commit succeeded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an RTM execution aborted.)",
      R"(Counts the number of times RTM abort was triggered.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MEM",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts))",
      R"(Counts the number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_UNFRIENDLY",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an RTM execution aborted due to HLE-unfriendly instructions)",
      R"(Counts the number of times an RTM execution aborted due to HLE-unfriendly instructions.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_MEMTYPE",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an RTM execution aborted due to incompatible memory type)",
      R"(Counts the number of times an RTM execution aborted due to incompatible memory type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RTM_RETIRED.ABORTED_EVENTS",
      EventDef::Encoding{
          .code = 0xc9, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt))",
      R"(Counts the number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of machine clears due to memory ordering conflicts.)",
      R"(Counts the number of Machine Clears detected dye to memory ordering. Memory Ordering Machine Clears may apply when a memory read may not conform to the memory ordering rules of the x86 architecture)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SMC",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Self-modifying code (SMC) detected.)",
      R"(Counts self-modifying code (SMC) detected, which causes a machine clear.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.COND",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x11, .cmask = 0, .msr_values = {0x00}},
      R"(Conditional branch instructions retired.)",
      R"(Counts conditional branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Direct and indirect near call instructions retired.)",
      R"(Counts both direct and indirect near call instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(All branch instructions retired.)",
      R"(Counts all branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_RETURN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Return instructions retired.)",
      R"(Counts return instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.COND_NTAKEN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Not taken branch instructions retired.)",
      R"(Counts not taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Taken branch instructions retired.)",
      R"(Counts taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Far branch instructions retired.)",
      R"(Counts far branch instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.INDIRECT",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Indirect near branch instructions retired (excluding returns))",
      R"(Counts near indirect branch instructions retired excluding returns. TSX abort is an indirect branch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.COND",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x11, .cmask = 0, .msr_values = {0x00}},
      R"(Mispredicted conditional branch instructions retired.)",
      R"(Counts mispredicted conditional branch instructions retired.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(All mispredicted branch instructions retired.)",
      R"(Counts all the retired branch instructions that were mispredicted by the processor. A branch misprediction occurs when the processor incorrectly predicts the destination of the branch.  When the misprediction is discovered at execution, all the instructions executed in the wrong (speculative) path must be discarded, and the processor must start fetching from the correct path.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.COND_NTAKEN",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Mispredicted non-taken conditional branch instructions retired.)",
      R"(Counts the number of conditional branch instructions retired that were mispredicted and the branch direction was not taken.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Number of near branch instructions retired that were mispredicted and taken.)",
      R"(Counts number of near branch instructions retired that were mispredicted and taken.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.INDIRECT",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(All miss-predicted indirect branch instructions retired (excluding RETs. TSX aborts is considered indirect branch).)",
      R"(Counts all miss-predicted indirect branch instructions retired (excluding RETs. TSX aborts is considered indirect branch).)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SCALAR_DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.SCALAR_SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.128B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.128B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.256B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.256B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.512B_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Counts number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ARITH_INST_RETIRED.512B_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.)",
      R"(Number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ASSISTS.FP",
      EventDef::Encoding{
          .code = 0xc1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts all microcode FP assists.)",
      R"(Counts all microcode Floating Point assists.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
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
      "MEM_LOAD_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions with L1 cache hits as data sources)",
      R"(Counts retired load instructions with at least one uop that hit in the L1 data cache. This event includes all SW prefetches and lock instructions regardless of the data source.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions with L2 cache hits as data sources)",
      R"(Counts retired load instructions with L2 cache hits as data sources.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L3_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions with L3 cache hits as data sources)",
      R"(Counts retired load instructions with at least one uop that hit in the L3 cache.)",
      100021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions missed L1 cache as data sources)",
      R"(Counts retired load instructions with at least one uop that missed in the L1 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions missed L2 cache as data sources)",
      R"(Counts retired load instructions missed L2 cache as data sources.)",
      100021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L3_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions missed L3 cache as data sources)",
      R"(Counts retired load instructions with at least one uop that missed in the L3 cache.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.FB_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Number of completed demand load requests that missed the L1, but hit the FB(fill buffer), because a preceding miss to the same cacheline initiated the line to be brought into L1, but data is not yet ready in L1.)",
      R"(Counts retired load instructions with at least one uop was load missed in L1 but hit FB (Fill Buffers) due to preceding miss to the same cache line with data not ready.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_MISS",
      EventDef::Encoding{
          .code = 0xd2, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions whose data sources were L3 hit and cross-core snoop missed in on-pkg core cache.)",
      R"(Counts the retired load instructions whose data sources were L3 hit and cross-core snoop missed in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_HIT",
      EventDef::Encoding{
          .code = 0xd2, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions whose data sources were L3 and cross-core snoop hits in on-pkg core cache)",
      R"(Counts retired load instructions whose data sources were L3 and cross-core snoop hits in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_HITM",
      EventDef::Encoding{
          .code = 0xd2, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions whose data sources were HitM responses from shared L3)",
      R"(Counts retired load instructions whose data sources were HitM responses from shared L3.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_L3_HIT_RETIRED.XSNP_NONE",
      EventDef::Encoding{
          .code = 0xd2, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions whose data sources were hits in L3 without snoops required)",
      R"(Counts retired load instructions whose data sources were hits in L3 without snoops required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.DSB_MISS",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x11}},
      R"(Retired Instructions who experienced a critical DSB miss.)",
      R"(Number of retired Instructions that experienced a critical DSB (Decode stream buffer i.e. the decoded instruction-cache) miss. Critical means stalls were exposed to the back-end as a result of the DSB miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.THREAD",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of uops to be executed per-thread each cycle.)",
      R"(Counts the number of uops to be executed per-thread each cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on the core.)",
      R"(Counts the number of uops executed from any thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.X87",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of x87 uops dispatched.)",
      R"(Counts the number of x87 uops executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EXE_ACTIVITY.1_PORTS_UTIL",
      EventDef::Encoding{
          .code = 0xa6, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xa6, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xa6, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xa6, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xA6, .umask = 0x40, .cmask = 2, .msr_values = {0x00}},
      R"(Cycles where the Store Buffer was full and no loads caused an execution stall.)",
      R"(Counts cycles where the Store Buffer was full and no loads caused an execution stall.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x85, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Code miss in all TLB levels causes a page walk that completes. (2M/4M))",
      R"(Counts completed page walks (2M/4M page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Number of page walks outstanding for an outstanding code request in the PMH each cycle.)",
      R"(Counts the number of page walks outstanding for an outstanding code (instruction fetch) request in the PMH (Page Miss Handler) each cycle.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Instruction fetch requests that miss the ITLB and hit the STLB.)",
      R"(Counts instruction fetch requests that miss the ITLB (Instruction TLB) and hit the STLB (Second-level TLB).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Page walks completed due to a demand data load to a 4K page.)",
      R"(Counts completed page walks  (4K sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Page walks completed due to a demand data load to a 2M/4M page.)",
      R"(Counts completed page walks  (2M/4M sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Number of page walks outstanding for a demand load in the PMH each cycle.)",
      R"(Counts the number of page walks outstanding for a demand load in the PMH (Page Miss Handler) each cycle.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Loads that miss the DTLB and hit the STLB.)",
      R"(Counts loads that miss the DTLB (Data TLB) and hit the STLB (Second level TLB).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Page walks completed due to a demand data store to a 4K page.)",
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
          .code = 0x49, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Page walks completed due to a demand data store to a 2M/4M page.)",
      R"(Counts completed page walks  (2M/4M sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Number of page walks outstanding for a store in the PMH each cycle.)",
      R"(Counts the number of page walks outstanding for a store in the PMH (Page Miss Handler) each cycle.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Stores that miss the DTLB and hit the STLB.)",
      R"(Counts stores that miss the DTLB (Data TLB) and hit the STLB (2nd Level TLB).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TLB_FLUSH.DTLB_THREAD",
      EventDef::Encoding{
          .code = 0xBD, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xBD, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(STLB flush attempts)",
      R"(Counts the number of any STLB flush attempts (such as entire, VPID, PCID, InvPage, CR3 write, etc.).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.REPLACEMENT",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cache lines replaced in L1 data cache.)",
      R"(Counts L1D data line replacements including opportunistic replacements, and replacements that require stall-for-replace or block-for-replace.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_CONFLICT",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times a transactional abort was signaled due to a data conflict on a transactionally accessed address)",
      R"(Counts the number of times a TSX line had a cache conflict.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_CAPACITY_WRITE",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Speculatively counts the number of TSX aborts due to a data capacity limitation for transactional writes.)",
      R"(Speculatively counts the number of Transactional Synchronization Extensions (TSX) aborts due to a data capacity limitation for transactional writes.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_STORE_TO_ELIDED_LOCK",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times a HLE transactional region aborted due to a non XRELEASE prefixed instruction writing to an elided lock in the elision buffer)",
      R"(Counts the number of times a TSX Abort was triggered due to a non-release/commit store to lock.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_ELISION_BUFFER_NOT_EMPTY",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE transactional execution aborted due to NoAllocatedElisionBuffer being non-zero.)",
      R"(Counts the number of times a TSX Abort was triggered due to commit but Lock Buffer not empty.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_ELISION_BUFFER_MISMATCH",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE transactional execution aborted due to XRELEASE lock not satisfying the address and value requirements in the elision buffer)",
      R"(Counts the number of times a TSX Abort was triggered due to release/commit but data and address mismatch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_HLE_ELISION_BUFFER_UNSUPPORTED_ALIGNMENT",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times an HLE transactional execution aborted due to an unsupported read alignment from the elision buffer.)",
      R"(Counts the number of times a TSX Abort was triggered due to attempting an unsupported alignment from Lock Buffer.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.HLE_ELISION_BUFFER_FULL",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Number of times HLE lock could not be elided due to ElisionBufferAvailable being zero.)",
      R"(Counts the number of times we could not allocate Lock Buffer.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TX_MEM.ABORT_CAPACITY_READ",
      EventDef::Encoding{
          .code = 0x54, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Speculatively counts the number of TSX aborts due to a data capacity limitation for transactional reads)",
      R"(Speculatively counts the number of Transactional Synchronization Extensions (TSX) aborts due to a data capacity limitation for transactional reads)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.PENDING",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of L1D misses that are outstanding)",
      R"(Counts number of L1D misses that are outstanding in each cycle, that is each cycle the number of Fill Buffers (FB) outstanding required by Demand Reads. FB either is held by demand loads, or it is held by non-demand loads and gets hit at least once by demand. The valid outstanding interval is defined until the FB deallocation by one of the following ways: from FB allocation, if FB is allocated by demand from the demand Hit FB, if it is allocated by hardware or software prefetch. Note: In the L1D, a Demand Read contains cacheable or noncacheable demand loads, including ones causing cache-line splits and reads due to page walks resulted from any request type.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.FB_FULL",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of cycles a demand request has waited due to L1D Fill Buffer (FB) unavailability.)",
      R"(Counts number of cycles a demand request has waited due to L1D Fill Buffer (FB) unavailability. Demand requests include cacheable/uncacheable demand load, store, lock or SW prefetch accesses.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.L2_STALL",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Number of cycles a demand request has waited due to L1D due to lack of L2 resources.)",
      R"(Counts number of cycles a demand request has waited due to L1D due to lack of L2 resources. Demand requests include cacheable/uncacheable demand load, store, lock or SW prefetch accesses.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.NTA",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of PREFETCHNTA instructions executed.)",
      R"(Counts the number of PREFETCHNTA instructions executed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.T0",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of PREFETCHT0 instructions executed.)",
      R"(Counts the number of PREFETCHT0 instructions executed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.T1_T2",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Number of PREFETCHT1 or PREFETCHT2 instructions executed.)",
      R"(Counts the number of PREFETCHT1 or PREFETCHT2 instructions executed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SW_PREFETCH_ACCESS.PREFETCHW",
      EventDef::Encoding{
          .code = 0x32, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Number of PREFETCHW instructions executed.)",
      R"(Counts the number of PREFETCHW instructions executed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.STORE_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x03, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.)",
      R"(Counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS_PARTIAL.ADDRESS_ALIAS",
      EventDef::Encoding{
          .code = 0x07, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(False dependencies due to partial compare on address.)",
      R"(Counts the number of times a load got blocked due to false dependencies due to partial compare on address.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xb0, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Demand Data Read requests sent to uncore)",
      R"(Counts the Demand Data Read requests sent to uncore. Use it in conjunction with OFFCORE_REQUESTS_OUTSTANDING to determine average latency in the uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0xb0, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xB0, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xb0, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts demand data read requests that miss the L3 cache.)",
      R"(Counts demand data read requests that miss the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.ALL_REQUESTS",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts memory transactions sent to the uncore.)",
      R"(Counts memory transactions sent to the uncore including requests initiated by the core, all L3 prefetches, reads resulting from page walks, and snoop responses.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(For every cycle, increments by the number of outstanding demand data read requests pending.)",
      R"(For every cycle, increments by the number of outstanding demand data read requests pending.   Requests are considered outstanding from the time they miss the core's L2 cache until the transaction completion message is sent to the requestor.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Store Read transactions pending for off-core. Highly correlated.)",
      R"(Counts the number of off-core outstanding read-for-ownership (RFO) store transactions every cycle. An RFO transaction is considered to be in the Off-core outstanding state between L2 cache miss and transaction completion.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(For every cycle, increments by the number of outstanding data read requests pending.)",
      R"(For every cycle, increments by the number of outstanding data read requests pending.  Data read requests include cacheable demand reads and L2 prefetches, but do not include RFOs, code reads or prefetches to the L3.  Reads due to page walks resulting from any request type will also be counted.  Requests are considered outstanding from the time they miss the core's L2 cache until the transaction completion message is sent to the requestor.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L2_WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(L2 writebacks that access L2 cache)",
      R"(Counts L2 writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.MISS",
      EventDef::Encoding{
          .code = 0x2e, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
      R"(Core-originated cacheable requests that missed L3  (Except hardware prefetches to the L3))",
      R"(Counts core-originated cacheable requests that miss the L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches to the L1 and L2.  It does not include hardware prefetches to the L3, and may not count other types of requests to the L3.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SQ_MISC.SQ_FULL",
      EventDef::Encoding{
          .code = 0xf4, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Cycles the queue waiting for offcore responses is full.)",
      R"(Counts the cycles for which the thread is active and the queue waiting for responses from the uncore cannot take any more entries.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.SILENT",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Non-modified cache lines that are silently dropped by L2 cache when triggered by an L2 cache fill.)",
      R"(Counts the number of lines that are silently dropped by L2 cache when triggered by an L2 cache fill. These lines are typically in Shared or Exclusive state. A non-threaded event.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.NON_SILENT",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Modified cache lines that are evicted by L2 cache when triggered by an L2 cache fill.)",
      R"(Counts the number of lines that are evicted by L2 cache when triggered by an L2 cache fill. Those lines are in Modified state. Modified lines are written back to L3)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.USELESS_HWPF",
      EventDef::Encoding{
          .code = 0xf2, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Cache lines that have been L2 hardware prefetched but not used by demand accesses)",
      R"(Counts the number of cache lines that have been prefetched by the L2 hardware prefetcher but not used by demand access when evicted from the L2 cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.DEMAND_DATA_RD_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x21, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x24, .umask = 0x22, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x24, .umask = 0x24, .cmask = 0, .msr_values = {0x00}},
      R"(L2 cache misses when fetching instructions)",
      R"(Counts L2 cache misses when fetching instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.SWPF_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x28, .cmask = 0, .msr_values = {0x00}},
      R"(SW prefetch requests that miss L2 cache.)",
      R"(Counts Software prefetch requests that miss the L2 cache. Accounts for PREFETCHNTA and PREFETCHT0/1/2 instructions when FB is not full.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.DEMAND_DATA_RD_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xc1, .cmask = 0, .msr_values = {0x00}},
      R"(Demand Data Read requests that hit L2 cache)",
      R"(Counts the number of demand Data Read requests initiated by load instructions that hit L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xc2, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x24, .umask = 0xc4, .cmask = 0, .msr_values = {0x00}},
      R"(L2 cache hits when fetching instructions, code reads.)",
      R"(Counts L2 cache hits when fetching instructions, code reads.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.SWPF_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xc8, .cmask = 0, .msr_values = {0x00}},
      R"(SW prefetch requests that hit L2 cache.)",
      R"(Counts Software prefetch requests that hit the L2 cache. Accounts for PREFETCHNTA and PREFETCHT0/1/2 instructions when FB is not full.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xE1, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x24, .umask = 0xE2, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x24, .umask = 0xE4, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0x24, .umask = 0xE7, .cmask = 0, .msr_values = {0x00}},
      R"(Demand requests to L2 cache)",
      R"(Counts demand requests to L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_DEMAND_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x27, .cmask = 0, .msr_values = {0x00}},
      R"(Demand requests that miss L2 cache)",
      R"(Counts demand requests that miss L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Load miss in all TLB levels causes a page walk that completes. (All page sizes))",
      R"(Counts completed page walks  (all page sizes) caused by demand data loads. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_ACTIVE",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles when at least one PMH is busy with a page walk for a demand load.)",
      R"(Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a demand load.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.ALL_RECOVERY_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x03, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles the Backend cluster is recovering after a miss-speculation or a Store Buffer or Load Buffer drain stall.)",
      R"(Counts cycles the Backend cluster is recovering after a miss-speculation or a Store Buffer or Load Buffer drain stall.)",
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
          .msr_values = {0x00}},
      R"(Cycles when RAT does not issue Uops to RS for the thread)",
      R"(Counts cycles during which the Resource Allocation Table (RAT) does not issue any Uops to the reservation station (RS) for the current thread.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.DIVIDER_ACTIVE",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x09, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles when divide unit is busy executing divide or square root operations.)",
      R"(Counts cycles when divide unit is busy executing divide or square root operations. Accounts for integer and floating-point operations.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_POWER.LVL0_TURBO_LICENSE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x07, .cmask = 0, .msr_values = {0x00}},
      R"(Core cycles where the core was running in a manner where Turbo may be clipped to the Non-AVX turbo schedule.)",
      R"(Counts Core cycles where the core was running with power-delivery for baseline license level 0.  This includes non-AVX codes, SSE, AVX 128-bit, and low-current AVX 256-bit codes.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_POWER.LVL1_TURBO_LICENSE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x18, .cmask = 0, .msr_values = {0x00}},
      R"(Core cycles where the core was running in a manner where Turbo may be clipped to the AVX2 turbo schedule.)",
      R"(Counts Core cycles where the core was running with power-delivery for license level 1.  This includes high current AVX 256-bit instructions as well as low current AVX 512-bit instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.PENDING_CYCLES",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x01, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles with L1D load Misses outstanding.)",
      R"(Counts duration of L1D miss outstanding in cycles.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.FB_FULL_PERIODS",
      EventDef::Encoding{
          .code = 0x48,
          .umask = 0x02,
          .edge = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Number of phases a demand request has waited due to L1D Fill Buffer (FB) unavailability.)",
      R"(Counts number of phases a demand request has waited due to L1D Fill Buffer (FB) unavailability. Demand requests include cacheable/uncacheable demand load, store, lock or SW prefetch accesses.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Store misses in all TLB levels causes a page walk that completes. (All page sizes))",
      R"(Counts completed page walks  (all page sizes) caused by demand data stores. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_ACTIVE",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles when at least one PMH is busy with a page walk for a store.)",
      R"(Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a store.)",
      100003,
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
          .msr_values = {0x00}},
      R"(Counts end of periods where the Reservation Station (RS) was empty.)",
      R"(Counts end of periods where the Reservation Station (RS) was empty. Could be useful to closely sample on front-end latency issues (see the FRONTEND_RETIRED event of designated precise events))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles where at least 1 outstanding Demand RFO request is pending.)",
      R"(Cycles where at least 1 outstanding Demand RFO request is pending.   RFOs are initiated by a core as part of a data store operation.  Demand RFO requests include RFOs, locks, and ItoM transactions.  Requests are considered outstanding from the time they miss the core's L2 cache until the transaction completion message is sent to the requestor.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles where at least 1 outstanding data read request is pending.)",
      R"(Cycles where at least 1 outstanding data read request is pending.  Data read requests include cacheable demand reads and L2 prefetches, but do not include RFOs, code reads or prefetches to the L3.  Reads due to page walks resulting from any request type will also be counted.  Requests are considered outstanding from the time they miss the core's L2 cache until the transaction completion message is sent to the requestor.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_L3_MISS_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x10, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles where at least one demand data read request known to have missed the L3 cache is pending.)",
      R"(Cycles where at least one demand data read request known to have missed the L3 cache is pending.  Note that this does not capture all elapsed cycles while requests are outstanding - only cycles from when the requests were known to have missed the L3 cache.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.DSB_CYCLES_OK",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x08, .cmask = 5, .msr_values = {0x00}},
      R"(Cycles DSB is delivering optimal number of Uops)",
      R"(Counts the number of cycles where optimal number of uops was delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.DSB_CYCLES_ANY",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x08, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles Decode Stream Buffer (DSB) is delivering any Uop)",
      R"(Counts the number of cycles uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_CYCLES_OK",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 5, .msr_values = {0x00}},
      R"(Cycles MITE is delivering optimal number of Uops)",
      R"(Counts the number of cycles where optimal number of uops was delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_CYCLES_ANY",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles MITE is delivering any Uop)",
      R"(Counts the number of cycles uops were delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).)",
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
          .msr_values = {0x00}},
      R"(Number of switches from DSB or MITE to the MS)",
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 0, .msr_values = {0x00}},
      R"(Uops delivered to IDQ while MS is busy)",
      R"(Counts the total number of uops delivered by the Microcode Sequencer (MS). Any instruction over 4 uops will be delivered by the MS. Some instructions such as transcendentals may additionally generate uops from the MS.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Code miss in all TLB levels causes a page walk that completes. (All page sizes))",
      R"(Counts completed page walks (all page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.)",
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
      R"(Cycles when at least one PMH is busy with a page walk for code (instruction fetch) request.)",
      R"(Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a code (instruction fetch) request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9c, .umask = 0x01, .cmask = 5, .msr_values = {0x00}},
      R"(Cycles when no uops are not delivered by the IDQ when backend of the machine is not stalled)",
      R"(Counts the number of cycles when no uops were delivered by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle.)",
      1000003,
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
          .msr_values = {0x00}},
      R"(Cycles when optimal number of uops was delivered to the back-end when the back-end is not stalled)",
      R"(Counts the number of cycles when the optimal number of uops were delivered by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.CYCLES_ACTIVE",
      EventDef::Encoding{
          .code = 0xA8, .umask = 0x01, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles Uops delivered by the LSD, but didn't come from the decoder.)",
      R"(Counts the cycles when at least one uop is delivered by the LSD (Loop-stream detector).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.CYCLES_OK",
      EventDef::Encoding{
          .code = 0xa8, .umask = 0x01, .cmask = 5, .msr_values = {0x00}},
      R"(Cycles optimal number of Uops delivered by the LSD, but did not come from the decoder.)",
      R"(Counts the cycles when optimal number of uops is delivered by the LSD (Loop-stream detector).)",
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
          .msr_values = {0x00}},
      R"(Counts number of cycles no uops were dispatched to be executed on this thread.)",
      R"(Counts cycles during which no uops were dispatched from the Reservation Station (RS) per thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_1",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      R"(Counts cycles when at least 1 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_2",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 2, .msr_values = {0x00}},
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      R"(Counts cycles when at least 2 micro-ops are executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_3",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 3, .msr_values = {0x00}},
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      R"(Counts cycles when at least 3 micro-ops are executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_4",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 4, .msr_values = {0x00}},
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      R"(Counts cycles when at least 4 micro-ops are executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ASSISTS.ANY",
      EventDef::Encoding{
          .code = 0xc1, .umask = 0x07, .cmask = 0, .msr_values = {0x00}},
      R"(Number of occurrences where a microcode assist is invoked by hardware.)",
      R"(Counts the number of occurrences where a microcode assist is invoked by hardware Examples include AD (page Access Dirty), FP and AVX related assists.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xc2,
          .umask = 0x02,
          .inv = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Cycles without actually retired uops.)",
      R"(This event counts cycles without actually retired uops.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.TOTAL_CYCLES",
      EventDef::Encoding{
          .code = 0xc2,
          .umask = 0x02,
          .inv = true,
          .cmask = 10,
          .msr_values = {0x00}},
      R"(Cycles with less than 10 actually retired uops.)",
      R"(Counts the number of cycles using always true condition (uops_ret &amp;lt; 16) applied to non PEBS uops retired event.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.L1I_MISS",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x12}},
      R"(Retired Instructions who experienced Instruction L1 Cache true miss.)",
      R"(Counts retired Instructions who experienced Instruction L1 Cache true miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x13}},
      R"(Retired Instructions who experienced Instruction L2 Cache true miss.)",
      R"(Counts retired Instructions who experienced Instruction L2 Cache true miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.ITLB_MISS",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x14}},
      R"(Retired Instructions who experienced iTLB true miss.)",
      R"(Counts retired Instructions that experienced iTLB (Instruction TLB) true miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.STLB_MISS",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x15}},
      R"(Retired Instructions who experienced STLB (2nd level TLB) true miss.)",
      R"(Counts retired Instructions that experienced STLB (2nd level TLB) true miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_2",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x500206}},
      R"(Retired instructions after front-end starvation of at least 2 cycles)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of at least 2 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_4",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x500406}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_8",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x500806}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 8 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after a front-end stall of at least 8 cycles. During this period the front-end delivered no uops.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_16",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x501006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 16 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after a front-end stall of at least 16 cycles. During this period the front-end delivered no uops.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_32",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x502006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 32 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after a front-end stall of at least 32 cycles. During this period the front-end delivered no uops.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_64",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x504006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_128",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x508006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_256",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x510006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_512",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x520006}},
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_2_BUBBLES_GE_1",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x100206}},
      R"(Retired instructions that are fetched after an interval where the front-end had at least 1 bubble-slot for a period of 2 cycles which was not interrupted by a back-end stall.)",
      R"(Counts retired instructions that are delivered to the back-end after the front-end had at least 1 bubble-slot for a period of 2 cycles. A bubble-slot is an empty issue-pipeline slot while there was no RAT stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
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
      "L2_LINES_IN.ALL",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x1F, .cmask = 0, .msr_values = {0x00}},
      R"(L2 cache lines filling L2)",
      R"(Counts the number of L2 cache lines filling the L2. Counting does not cover rejects.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_P",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Thread cycles when thread is not in halt state)",
      R"(This is an architectural event that counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling. For this reason, this event may have a changing ratio with regards to wall clock time.)",
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
      R"(Core crystal clock cycles when the thread is unhalted.)",
      R"(Counts core crystal clock cycles when the thread is unhalted.)",
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
      R"(Counts Core crystal clock cycles when current thread is unhalted and the other thread is halted.)",
      25003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xc0, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Number of instructions retired. General Counter - architectural event)",
      R"(Counts the number of instructions retired - an Architectural PerfMon event. Counting continues during hardware interrupts, traps, and inside interrupt handlers. Notes: INST_RETIRED.ANY is counted by a designated fixed counter freeing up programmable counters to count other events. INST_RETIRED.ANY_P is counted by a programmable counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of instructions retired. Fixed Counter - architectural event)",
      R"(Counts the number of instructions retired - an Architectural PerfMon event. Counting continues during hardware interrupts, traps, and inside interrupt handlers. Notes: INST_RETIRED.ANY is counted by a designated fixed counter freeing up programmable counters to count other events. INST_RETIRED.ANY_P is counted by a programmable counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Core cycles when the thread is not in halt state)",
      R"(Counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the eight programmable counters available for other events.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Reference cycles when the core is not in halt state.)",
      R"(Counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. This event has a constant ratio with the CPU_CLK_UNHALTED.REF_XCLK event. It is counted on a dedicated fixed counter, leaving the eight programmable counters available for other events. Note: On all current platforms this event stops counting during 'throttling (TM)' states duty off periods the processor is 'halted'.  The counter update is done at a lower clock rate then the core clock the overflow status bit for this counter may appear 'sticky'.  After the counter has overflowed and software clears the overflow status bit and resets the counter to less than MAX. The reset value to the counter is not clocked immediately so the overflow status bit will flip 'high (1)' and generate another PMI (if enabled) after which the reset value gets clocked into the counter. Therefore, software will get the interrupt, read the overflow status bit '1 for bit 34 while the counter value is less than MAX. Software should ignore this case.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.STLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x11, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xd0, .umask = 0x12, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xd0, .umask = 0x21, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions with locked access.)",
      R"(Counts retired load instructions with locked access.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xd0, .umask = 0x42, .cmask = 0, .msr_values = {0x00}},
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
          .code = 0xd0, .umask = 0x81, .cmask = 0, .msr_values = {0x00}},
      R"(Retired load instructions.)",
      R"(Counts all retired load instructions. This event accounts for SW prefetch instructions of PREFETCHNTA or PREFETCHT0/1/2 or PREFETCHW.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x82, .cmask = 0, .msr_values = {0x00}},
      R"(Retired store instructions.)",
      R"(Counts all retired store instructions.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L2_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x01, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles while L2 cache miss demand load is outstanding.)",
      R"(Cycles while L2 cache miss demand load is outstanding.)",
      1000003,
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
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_TOTAL",
      EventDef::Encoding{
          .code = 0xa3, .umask = 0x04, .cmask = 4, .msr_values = {0x00}},
      R"(Total execution stalls.)",
      R"(Total execution stalls.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_MISS",
      EventDef::Encoding{
          .code = 0xa3, .umask = 0x05, .cmask = 5, .msr_values = {0x00}},
      R"(Execution stalls while L2 cache miss demand load is outstanding.)",
      R"(Execution stalls while L2 cache miss demand load is outstanding.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L3_MISS",
      EventDef::Encoding{
          .code = 0xa3, .umask = 0x06, .cmask = 6, .msr_values = {0x00}},
      R"(Execution stalls while L3 cache miss demand load is outstanding.)",
      R"(Execution stalls while L3 cache miss demand load is outstanding.)",
      1000003,
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
      1000003,
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
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_MEM_ANY",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x10, .cmask = 16, .msr_values = {0x00}},
      R"(Cycles while memory subsystem has an outstanding load.)",
      R"(Cycles while memory subsystem has an outstanding load.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_MEM_ANY",
      EventDef::Encoding{
          .code = 0xa3, .umask = 0x14, .cmask = 20, .msr_values = {0x00}},
      R"(Execution stalls while memory subsystem has an outstanding load.)",
      R"(Execution stalls while memory subsystem has an outstanding load.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_POWER.LVL2_TURBO_LICENSE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Core cycles where the core was running in a manner where Turbo may be clipped to the AVX512 turbo schedule.)",
      R"(Core cycles where the core was running with power-delivery for license level 2 (introduced in Skylake Server microarchtecture).  This includes high current AVX 512-bit instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.PREC_DIST",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Precise instruction retired event with a reduced effect of PEBS shadow in IP distribution)",
      R"(A version of INST_RETIRED that allows for a more unbiased distribution of samples across instructions retired. It utilizes the Precise Distribution of Instructions Retired (PDIR) feature to mitigate some bias in how retired instructions get sampled. Use on Fixed Counter 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.COUNT",
      EventDef::Encoding{
          .code = 0xc3,
          .umask = 0x01,
          .edge = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Number of machine clears (nukes) of any type.)",
      R"(Counts the number of machine clears (nukes) of any type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.COND_TAKEN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Taken conditional branch instructions retired.)",
      R"(Counts taken conditional branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.COND_TAKEN",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(number of branch instructions retired that were mispredicted and taken.)",
      R"(Counts taken conditional mispredicted branch instructions retired.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.DISTRIBUTED",
      EventDef::Encoding{
          .code = 0xec, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Cycle counts are evenly distributed between active threads in the Core.)",
      R"(This event distributes cycle counts between active hyperthreads, i.e., those in C0.  A hyperthread becomes inactive when it executes the HLT or MWAIT instructions.  If all other hyperthreads are inactive (or disabled or do not exist), all counts are attributed to this hyperthread. To obtain the full count when the Core is active, sum the counts from each hyperthread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN.SLOTS_P",
      EventDef::Encoding{
          .code = 0xa4, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(TMA slots available for an unhalted logical processor. General counter - architectural event)",
      R"(Counts the number of available slots for an unhalted logical processor. The event increments by machine-width of the narrowest pipeline as employed by the Top-down Microarchitecture Analysis method. The count is distributed among unhalted logical processors (hyper-threads) who share the same physical core.)",
      10000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN.SLOTS",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(TMA slots available for an unhalted logical processor. Fixed counter - architectural event)",
      R"(Number of available slots for an unhalted logical processor. The event increments by machine-width of the narrowest pipeline as employed by the Top-down Microarchitecture Analysis method (TMA). The count is distributed among unhalted logical processors (hyper-threads) who share the same physical core. Software can use this event as the denominator for the top-level metrics of the TMA method. This architectural event is counted on a designated fixed counter (Fixed Counter 3).)",
      10000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.PORT_0",
      EventDef::Encoding{
          .code = 0xa1, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on port 0)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PREFETCH.SWPF",
      EventDef::Encoding{
          .code = 0x4c, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of demand load dispatches that hit L1D fill buffer (FB) allocated for software prefetch.)",
      R"(Counts all not software-prefetch load dispatches that hit the fill buffer (FB) allocated for the software prefetch. It can also be incremented by some lock instructions. So it should only be used with profiling so that the locks can be excluded by ASM (Assembly File) inspection of the nearby instructions.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_1",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x01, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles where at least 1 uop was executed per-thread)",
      R"(Cycles where at least 1 uop was executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_2",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x01, .cmask = 2, .msr_values = {0x00}},
      R"(Cycles where at least 2 uops were executed per-thread)",
      R"(Cycles where at least 2 uops were executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_3",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x01, .cmask = 3, .msr_values = {0x00}},
      R"(Cycles where at least 3 uops were executed per-thread)",
      R"(Cycles where at least 3 uops were executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CYCLES_GE_4",
      EventDef::Encoding{
          .code = 0xb1, .umask = 0x01, .cmask = 4, .msr_values = {0x00}},
      R"(Cycles where at least 4 uops were executed per-thread)",
      R"(Cycles where at least 4 uops were executed per-thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.SLOTS",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Retirement slots used.)",
      R"(Counts the retirement slots used each cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.PORT_1",
      EventDef::Encoding{
          .code = 0xa1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on port 1)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.PORT_2_3",
      EventDef::Encoding{
          .code = 0xa1, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on port 2 and 3)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to ports 2 and 3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.PORT_4_9",
      EventDef::Encoding{
          .code = 0xa1, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on port 4 and 9)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to ports 5 and 9.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISC_RETIRED.LBR_INSERTS",
      EventDef::Encoding{
          .code = 0xcc, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Increments whenever there is an update to the LBR array.)",
      R"(Increments when an entry is added to the Last Branch Record (LBR) array (or removed from the array in case of RETURNs in call stack mode). The event requires LBR to be enabled properly.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.PORT_5",
      EventDef::Encoding{
          .code = 0xa1, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on port 5)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 5.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_CYCLES_ANY",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles when uops are being delivered to IDQ while MS is busy)",
      R"(Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.PORT_6",
      EventDef::Encoding{
          .code = 0xa1, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on port 6)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 6.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.PORT_7_8",
      EventDef::Encoding{
          .code = 0xa1, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops executed on port 7 and 8)",
      R"(Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to ports 7 and 8.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_DISTRIBUTED",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Core crystal clock cycles. Cycle counts are evenly distributed between active threads in the Core.)",
      R"(This event distributes Core crystal clock cycle counts between active hyperthreads, i.e., those in C0 sleep-state. A hyperthread becomes inactive when it executes the HLT or MWAIT instructions. If one thread is active in a core, all counts are attributed to this hyperthread. To obtain the full count when the Core is active, sum the counts from each hyperthread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISC_RETIRED.PAUSE_INST",
      EventDef::Encoding{
          .code = 0xcc, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of retired PAUSE instructions. This event is not supported on first SKL and KBL products.)",
      R"(Counts number of retired PAUSE instructions. This event is not supported on first SKL and KBL products.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.INDIRECT_CALL",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Mispredicted indirect CALL instructions retired.)",
      R"(Counts retired mispredicted indirect (near taken) CALL instructions, including both register and memory indirect.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB2MITE_SWITCHES.COUNT",
      EventDef::Encoding{
          .code = 0xab,
          .umask = 0x02,
          .edge = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Decode Stream Buffer (DSB)-to-MITE transitions count.)",
      R"(Counts the number of Decode Stream Buffer (DSB a.k.a. Uop Cache)-to-MITE speculative transitions.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.LATENCY_GE_1",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x500106}},
      R"(Retired instructions after front-end starvation of at least 1 cycle)",
      R"(Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of at least 1 cycle which was not interrupted by a back-end stall.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xc0,
          .umask = 0x01,
          .inv = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Cycles without actually retired instructions.)",
      R"(This event counts cycles without actually retired instructions.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.ANY_DSB_MISS",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x01, .cmask = 0, .msr_values = {0x1}},
      R"(Retired Instructions who experienced DSB miss.)",
      R"(Counts retired Instructions that experienced DSB (Decode stream buffer i.e. the decoded instruction-cache) miss.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x83, .cmask = 0, .msr_values = {0x00}},
      R"(All retired memory instructions.)",
      R"(Counts all retired memory instructions - loads and stores.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{
          .data_la = true, .l1_hit_indication = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.NOP",
      EventDef::Encoding{
          .code = 0xc0, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Number of all retired NOP instructions.)",
      R"(Number of all retired NOP instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DECODED.DEC0",
      EventDef::Encoding{
          .code = 0x56, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Number of uops decoded out of instructions exclusively fetched by decoder 0)",
      R"(Uops exclusively fetched by decoder 0)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0001}},
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
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
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0001}},
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0001}},
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C0001}},
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was sent or not.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
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
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C0002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was sent or not.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
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
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was sent or not.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C0010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was sent or not.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop hit in another cores caches, data forwarding is required as the data is modified.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C0020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was sent or not.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0400}},
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0400}},
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C0400}},
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that hit a cacheline in the L3 where a snoop was sent or not.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C0800}},
      R"(Counts streaming stores that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts streaming stores that hit a cacheline in the L3 where a snoop was sent or not.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C8000}},
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop was not needed to satisfy the request.)",
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
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop was sent but no other cores had the data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C8000}},
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop hit in another core, data forwarding is not required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L3.L3_HIT.ANY",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FC03C2380}},
      R"(Counts hardware prefetches to the L3 only that hit a cacheline in the L3 where a snoop was sent or not.)",
      R"(Counts hardware prefetches to the L3 only that hit a cacheline in the L3 where a snoop was sent or not.)",
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
      R"(Counts demand data reads that have any type of response.)",
      R"(Counts demand data reads that have any type of response.)",
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
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.)",
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
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that have any type of response.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that have any type of response.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that have any type of response.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10400}},
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that have any type of response.)",
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10800}},
      R"(Counts streaming stores that have any type of response.)",
      R"(Counts streaming stores that have any type of response.)",
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
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that have any type of response.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_SENT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1E003C0001}},
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was sent.)",
      R"(Counts demand data reads that hit a cacheline in the L3 where a snoop was sent.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_SENT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1E003C0002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was sent.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a cacheline in the L3 where a snoop was sent.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_SENT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1E003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was sent.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that hit a cacheline in the L3 where a snoop was sent.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_SENT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1E003C0010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was sent.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that hit a cacheline in the L3 where a snoop was sent.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_SENT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1E003C0020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was sent.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that hit a cacheline in the L3 where a snoop was sent.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_HIT.SNOOP_SENT",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1E003C8000}},
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop was sent.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that hit a cacheline in the L3 where a snoop was sent.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000001}},
      R"(Counts demand data reads that DRAM supplied the request.)",
      R"(Counts demand data reads that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that DRAM supplied the request.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that DRAM supplied the request.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that DRAM supplied the request.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that DRAM supplied the request.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000400}},
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that DRAM supplied the request.)",
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000800}},
      R"(Counts streaming stores that DRAM supplied the request.)",
      R"(Counts streaming stores that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184008000}},
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that DRAM supplied the request.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC00001}},
      R"(Counts demand data reads that was not supplied by the L3 cache.)",
      R"(Counts demand data reads that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC00002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that was not supplied by the L3 cache.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC00004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that was not supplied by the L3 cache.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC00010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that was not supplied by the L3 cache.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC00020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that was not supplied by the L3 cache.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC00400}},
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that was not supplied by the L3 cache.)",
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC00800}},
      R"(Counts streaming stores that was not supplied by the L3 cache.)",
      R"(Counts streaming stores that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FFFC08000}},
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that was not supplied by the L3 cache.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that was not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000001}},
      R"(Counts demand data reads that DRAM supplied the request.)",
      R"(Counts demand data reads that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000002}},
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that DRAM supplied the request.)",
      R"(Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that DRAM supplied the request.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000010}},
      R"(Counts hardware prefetch data reads (which bring data to L2)  that DRAM supplied the request.)",
      R"(Counts hardware prefetch data reads (which bring data to L2)  that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000020}},
      R"(Counts hardware prefetch RFOs (which bring data to L2) that DRAM supplied the request.)",
      R"(Counts hardware prefetch RFOs (which bring data to L2) that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000400}},
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that DRAM supplied the request.)",
      R"(Counts L1 data cache prefetch requests and software prefetches (except PREFETCHW) that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000800}},
      R"(Counts streaming stores that DRAM supplied the request.)",
      R"(Counts streaming stores that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184008000}},
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that DRAM supplied the request.)",
      R"(Counts miscellaneous requests, such as I/O and un-cacheable accesses that DRAM supplied the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace icelake_core
} // namespace facebook::hbt::perf_event::generated
