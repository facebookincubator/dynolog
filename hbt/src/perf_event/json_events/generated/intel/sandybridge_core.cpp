// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace sandybridge_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from sandybridge_core.json (406 events).

    Supported SKUs:
        - Arch: x86, Model: SNB id: 42
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when the core is not in halt state.)",
      R"(This event counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. This event has a constant ratio with the CPU_CLK_UNHALTED.REF_XCLK event. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. )",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired from execution.)",
      R"(This event counts the number of instructions retired from execution. For instructions that consist of multiple micro-ops, this event counts the retirement of the last micro-op of the instruction. Counting continues during hardware interrupts, traps, and inside interrupt handlers. )",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Core cycles when the thread is not in halt state.)",
      R"(This event counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. )",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.DATA_UNKNOWN",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Loads delayed due to SB blocks, preceding store operations with known addresses but unknown data.)",
      R"(Loads delayed due to SB blocks, preceding store operations with known addresses but unknown data.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.STORE_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cases when loads get true Block-on-Store blocking code preventing store forwarding.)",
      R"(This event counts loads that followed a store to the same address, where the data could not be forwarded inside the pipeline from the store to the load.  The most common reason why store forwarding would be blocked is when a load's address range overlaps with a preceding smaller uncompleted store.  See the table of not supported store forwards in the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual.  The penalty for blocked store forwarding is that the load must wait for the store to complete before it can be issued.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.ALL_BLOCK",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of cases where any load ends up with a valid block-code written to the load buffer (including blocks due to Memory Order Buffer (MOB), Data Cache Unit (DCU), TLB, but load has no DCU miss).)",
      R"(Number of cases where any load ends up with a valid block-code written to the load buffer (including blocks due to Memory Order Buffer (MOB), Data Cache Unit (DCU), TLB, but load has no DCU miss).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.LOADS",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Speculative cache line split load uops dispatched to L1 cache.)",
      R"(Speculative cache line split load uops dispatched to L1 cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.STORES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Speculative cache line split STA uops dispatched to L1 cache.)",
      R"(Speculative cache line split STA uops dispatched to L1 cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS_PARTIAL.ADDRESS_ALIAS",
      EventDef::Encoding{
          .code = 0x07, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(False dependencies in MOB due to partial compare.)",
      R"(Aliasing occurs when a load is issued after a store and their memory addresses are offset by 4K.  This event counts the number of loads that aliased with a preceding store, resulting in an extended address check in the pipeline.  The enhanced address check typically has a performance penalty of 5 cycles.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS_PARTIAL.ALL_STA_BLOCK",
      EventDef::Encoding{
          .code = 0x07, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(This event counts the number of times that load operations are temporarily blocked because of older stores, with addresses that are not yet known. A load operation may incur more than one block of this type.)",
      R"(This event counts the number of times that load operations are temporarily blocked because of older stores, with addresses that are not yet known. A load operation may incur more than one block of this type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Load misses in all DTLB levels that cause page walks.)",
      R"(Load misses in all DTLB levels that cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Load misses at all DTLB levels that cause completed page walks.)",
      R"(Load misses at all DTLB levels that cause completed page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks.)",
      R"(This event counts cycles when the  page miss handler (PMH) is servicing page walks caused by DTLB load misses.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Load operations that miss the first DTLB level but hit the second and do not cause page walks.)",
      R"(This event counts load operations that miss the first DTLB level but hit the second and do not cause any page walks. The penalty in this case is approximately 7 cycles.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x03, .cmask = 1, .msr_values = {0}},
      R"(Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).)",
      R"(Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_STALLS_COUNT",
      EventDef::Encoding{
          .code = 0x0D,
          .umask = 0x03,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).)",
      R"(Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RAT_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the thread.)",
      R"(Cycles when Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Uops that Resource Allocation Table (RAT) issues to Reservation Station (RS).)",
      R"(This event counts the number of Uops issued by the front-end of the pipeilne to the back-end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.X87",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of FP Computational Uops Executed this cycle. The number of FADD, FSUB, FCOM, FMULs, integer MULs and IMULs, FDIVs, FPREMs, FSQRTS, integer DIVs, and IDIVs. This event does not distinguish an FADD used in the middle of a transcendental flow from a s.)",
      R"(Number of FP Computational Uops Executed this cycle. The number of FADD, FSUB, FCOM, FMULs, integer MULs and IMULs, FDIVs, FPREMs, FSQRTS, integer DIVs, and IDIVs. This event does not distinguish an FADD used in the middle of a transcendental flow from a s.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE* or AVX-128 FP Computational packed double-precision uops issued this cycle.)",
      R"(Number of SSE* or AVX-128 FP Computational packed double-precision uops issued this cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_SCALAR_SINGLE",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE* or AVX-128 FP Computational scalar single-precision uops issued this cycle.)",
      R"(Number of SSE* or AVX-128 FP Computational scalar single-precision uops issued this cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE* or AVX-128 FP Computational packed single-precision uops issued this cycle.)",
      R"(Number of SSE* or AVX-128 FP Computational packed single-precision uops issued this cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_SCALAR_DOUBLE",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE* or AVX-128 FP Computational scalar double-precision uops issued this cycle.)",
      R"(Number of SSE* or AVX-128 FP Computational scalar double-precision uops issued this cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_FP_256.PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0x11, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of GSSE-256 Computational FP single precision uops issued this cycle.)",
      R"(Number of GSSE-256 Computational FP single precision uops issued this cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_FP_256.PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0x11, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of AVX-256 Computational FP double precision uops issued this cycle.)",
      R"(Number of AVX-256 Computational FP double precision uops issued this cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.FPU_DIV_ACTIVE",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when divider is busy executing divide operations.)",
      R"(Cycles when divider is busy executing divide operations.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.FPU_DIV",
      EventDef::Encoding{
          .code = 0x14,
          .umask = 0x01,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Divide operations executed.)",
      R"(This event counts the number of the divide operations executed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INSTS_WRITTEN_TO_IQ.INSTS",
      EventDef::Encoding{
          .code = 0x17, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Valid instructions written to IQ per cycle.)",
      R"(Valid instructions written to IQ per cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.DEMAND_DATA_RD_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests that hit L2 cache.)",
      R"(Demand Data Read requests that hit L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x03, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests.)",
      R"(Demand Data Read requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that hit L2 cache.)",
      R"(RFO requests that hit L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that miss L2 cache.)",
      R"(RFO requests that miss L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_RFO",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x0C, .cmask = 0, .msr_values = {0}},
      R"(RFO requests to L2 cache.)",
      R"(RFO requests to L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.CODE_RD_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L2 cache hits when fetching instructions, code reads.)",
      R"(L2 cache hits when fetching instructions, code reads.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.CODE_RD_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 cache misses when fetching instructions.)",
      R"(L2 cache misses when fetching instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_CODE_RD",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(L2 code requests.)",
      R"(L2 code requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PF_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Requests from the L2 hardware prefetchers that hit L2 cache.)",
      R"(Requests from the L2 hardware prefetchers that hit L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PF_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Requests from the L2 hardware prefetchers that miss L2 cache.)",
      R"(Requests from the L2 hardware prefetchers that miss L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_PF",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xC0, .cmask = 0, .msr_values = {0}},
      R"(Requests from L2 hardware prefetchers.)",
      R"(Requests from L2 hardware prefetchers.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_STORE_LOCK_RQSTS.MISS",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(RFOs that miss cache lines.)",
      R"(RFOs that miss cache lines.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_STORE_LOCK_RQSTS.HIT_E",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(RFOs that hit cache lines in E state.)",
      R"(RFOs that hit cache lines in E state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_STORE_LOCK_RQSTS.HIT_M",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(RFOs that hit cache lines in M state.)",
      R"(RFOs that hit cache lines in M state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_STORE_LOCK_RQSTS.ALL",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x0F, .cmask = 0, .msr_values = {0}},
      R"(RFOs that access cache lines in any state.)",
      R"(RFOs that access cache lines in any state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_L1D_WB_RQSTS.MISS",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Count the number of modified Lines evicted from L1 and missed L2. (Non-rejected WBs from the DCU.).)",
      R"(Count the number of modified Lines evicted from L1 and missed L2. (Non-rejected WBs from the DCU.).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_L1D_WB_RQSTS.HIT_S",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Not rejected writebacks from L1D to L2 cache lines in S state.)",
      R"(Not rejected writebacks from L1D to L2 cache lines in S state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_L1D_WB_RQSTS.HIT_E",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Not rejected writebacks from L1D to L2 cache lines in E state.)",
      R"(Not rejected writebacks from L1D to L2 cache lines in E state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_L1D_WB_RQSTS.HIT_M",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Not rejected writebacks from L1D to L2 cache lines in M state.)",
      R"(Not rejected writebacks from L1D to L2 cache lines in M state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_L1D_WB_RQSTS.ALL",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x0F, .cmask = 0, .msr_values = {0}},
      R"(Not rejected writebacks from L1D to L2 cache lines in any state.)",
      R"(Not rejected writebacks from L1D to L2 cache lines in any state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.MISS",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Core-originated cacheable demand requests missed LLC.)",
      R"(Core-originated cacheable demand requests missed LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x4F, .cmask = 0, .msr_values = {0}},
      R"(Core-originated cacheable demand requests that refer to LLC.)",
      R"(Core-originated cacheable demand requests that refer to LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_P",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Thread cycles when thread is not in halt state.)",
      R"(Thread cycles when thread is not in halt state.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate).)",
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.REF_XCLK_ANY",
      EventDef::Encoding{
          .code = 0x3C,
          .umask = 0x01,
          .any = true,
          .cmask = 0,
          .msr_values = {0x00}},
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
      R"(Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate).)",
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_THREAD_UNHALTED.ONE_THREAD_ACTIVE",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Count XClk pulses when this thread is unhalted and the other is halted.)",
      R"(Count XClk pulses when this thread is unhalted and the other is halted.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.ONE_THREAD_ACTIVE",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Count XClk pulses when this thread is unhalted and the other thread is halted.)",
      R"(Count XClk pulses when this thread is unhalted and the other thread is halted.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.PENDING",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L1D miss outstanding duration in cycles.)",
      R"(L1D miss outstanding duration in cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PEND_MISS.FB_FULL",
      EventDef::Encoding{
          .code = 0x48, .umask = 0x02, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles a demand request was blocked due to Fill Buffers unavailability.)",
      R"(Cycles a demand request was blocked due to Fill Buffers unavailability.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause page walks.)",
      R"(Store misses in all DTLB levels that cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks.)",
      R"(Store misses in all DTLB levels that cause completed page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks.)",
      R"(Cycles when PMH is busy with page walks.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Store operations that miss the first TLB level but hit the second and do not cause page walks.)",
      R"(Store operations that miss the first TLB level but hit the second and do not cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE.SW_PF",
      EventDef::Encoding{
          .code = 0x4C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Not software-prefetch load dispatches that hit FB allocated for software prefetch.)",
      R"(Not software-prefetch load dispatches that hit FB allocated for software prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE.HW_PF",
      EventDef::Encoding{
          .code = 0x4C, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Not software-prefetch load dispatches that hit FB allocated for hardware prefetch.)",
      R"(Not software-prefetch load dispatches that hit FB allocated for hardware prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_PRE_REQ.DL1_MISS",
      EventDef::Encoding{
          .code = 0x4E, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Hardware Prefetch requests that miss the L1D cache. This accounts for both L1 streamer and IP-based (IPP) HW prefetchers. A request is being counted each time it access the cache & miss it, including if a block is applicable or if hit the Fill Buffer for .)",
      R"(Hardware Prefetch requests that miss the L1D cache. This accounts for both L1 streamer and IP-based (IPP) HW prefetchers. A request is being counted each time it access the cache & miss it, including if a block is applicable or if hit the Fill Buffer for .)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.WALK_CYCLES",
      EventDef::Encoding{
          .code = 0x4F, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Cycle count for an Extended Page table walk.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.)",
      R"(Cycle count for an Extended Page table walk.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.REPLACEMENT",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L1D data line replacements.)",
      R"(This event counts L1D data line replacements.  Replacements occur when a new line is brought into the cache, causing eviction of a line loaded earlier.  )",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.ALLOCATED_IN_M",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Allocated L1D data cache lines in M state.)",
      R"(Allocated L1D data cache lines in M state.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.EVICTION",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(L1D data cache lines in M state evicted due to replacement.)",
      R"(L1D data cache lines in M state evicted due to replacement.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.ALL_M_REPLACEMENT",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cache lines in M state evicted out of L1D due to Snoop HitM or dirty line replacement.)",
      R"(Cache lines in M state evicted out of L1D due to Snoop HitM or dirty line replacement.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PARTIAL_RAT_STALLS.FLAGS_MERGE_UOP",
      EventDef::Encoding{
          .code = 0x59, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Increments the number of flags-merge uops in flight each cycle.)",
      R"(Increments the number of flags-merge uops in flight each cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PARTIAL_RAT_STALLS.FLAGS_MERGE_UOP_CYCLES",
      EventDef::Encoding{
          .code = 0x59, .umask = 0x20, .cmask = 1, .msr_values = {0}},
      R"(Performance sensitive flags-merging uops added by Sandy Bridge u-arch.)",
      R"(This event counts the number of cycles spent executing performance-sensitive flags-merging uops. For example, shift CL (merge_arith_flags). For more details, See the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PARTIAL_RAT_STALLS.SLOW_LEA_WINDOW",
      EventDef::Encoding{
          .code = 0x59, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Cycles with at least one slow LEA uop being allocated.)",
      R"(This event counts the number of cycles with at least one slow LEA uop being allocated. A uop is generally considered as slow LEA if it has three sources (for example, two sources and immediate) regardless of whether it is a result of LEA instruction or not. Examples of the slow LEA uop are or uops with base, index, and offset source operands using base and index reqisters, where base is EBR/RBP/R13, using RIP relative or 16-bit addressing modes. See the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual for more details about slow LEA instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PARTIAL_RAT_STALLS.MUL_SINGLE_UOP",
      EventDef::Encoding{
          .code = 0x59, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Multiply packed/scalar single precision uops allocated.)",
      R"(Multiply packed/scalar single precision uops allocated.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS2.ALL_FL_EMPTY",
      EventDef::Encoding{
          .code = 0x5B, .umask = 0x0C, .cmask = 0, .msr_values = {0}},
      R"(Cycles with either free list is empty.)",
      R"(Cycles with either free list is empty.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS2.ALL_PRF_CONTROL",
      EventDef::Encoding{
          .code = 0x5B, .umask = 0x0F, .cmask = 0, .msr_values = {0}},
      R"(Resource stalls2 control structures full for physical registers.)",
      R"(Resource stalls2 control structures full for physical registers.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS2.BOB_FULL",
      EventDef::Encoding{
          .code = 0x5B, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Allocator is stalled if BOB is full and new branch needs it.)",
      R"(Cycles when Allocator is stalled if BOB is full and new branch needs it.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS2.OOO_RSRC",
      EventDef::Encoding{
          .code = 0x5B, .umask = 0x4F, .cmask = 0, .msr_values = {0}},
      R"(Resource stalls out of order resources full.)",
      R"(Resource stalls out of order resources full.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPL_CYCLES.RING0",
      EventDef::Encoding{
          .code = 0x5C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Unhalted core cycles when the thread is in ring 0.)",
      R"(Unhalted core cycles when the thread is in ring 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPL_CYCLES.RING123",
      EventDef::Encoding{
          .code = 0x5C, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Unhalted core cycles when thread is in rings 1, 2, or 3.)",
      R"(Unhalted core cycles when thread is in rings 1, 2, or 3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RS_EVENTS.EMPTY_CYCLES",
      EventDef::Encoding{
          .code = 0x5E, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Reservation Station (RS) is empty for the thread.)",
      R"(Cycles when Reservation Station (RS) is empty for the thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding Demand Data Read transactions in uncore queue.)",
      R"(Offcore outstanding Demand Data Read transactions in uncore queue.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD_C6",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 6, .msr_values = {0x00}},
      R"(Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.)",
      R"(Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding RFO store transactions in SuperQueue (SQ), queue to uncore.)",
      R"(Offcore outstanding RFO store transactions in SuperQueue (SQ), queue to uncore.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore.)",
      R"(Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOCK_CYCLES.SPLIT_LOCK_UC_LOCK_DURATION",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when L1 and L2 are locked due to UC or split lock.)",
      R"(Cycles when L1 and L2 are locked due to UC or split lock.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOCK_CYCLES.CACHE_LOCK_DURATION",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cycles when L1D is locked.)",
      R"(Cycles when L1D is locked.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.EMPTY",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Instruction Decode Queue (IDQ) empty cycles.)",
      R"(Instruction Decode Queue (IDQ) empty cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path.)",
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.DSB_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.)",
      R"(Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_DSB_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      R"(Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_DSB_CYCLES_4_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x18, .cmask = 4, .msr_values = {0}},
      R"(Cycles Decode Stream Buffer (DSB) is delivering 4 Uops.)",
      R"(Cycles Decode Stream Buffer (DSB) is delivering 4 Uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_DSB_CYCLES_ANY_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x18, .cmask = 1, .msr_values = {0}},
      R"(Cycles Decode Stream Buffer (DSB) is delivering any Uop.)",
      R"(Cycles Decode Stream Buffer (DSB) is delivering any Uop.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_MITE_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      R"(Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_MITE_CYCLES_4_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x24, .cmask = 4, .msr_values = {0}},
      R"(Cycles MITE is delivering 4 Uops.)",
      R"(Cycles MITE is delivering 4 Uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_MITE_CYCLES_ANY_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x24, .cmask = 1, .msr_values = {0}},
      R"(Cycles MITE is delivering any Uop.)",
      R"(Cycles MITE is delivering any Uop.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      R"(Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.)",
      R"(This event counts cycles during which the microcode sequencer assisted the front-end in delivering uops.  Microcode assists are used for complex instructions or scenarios that can't be handled by the standard decoder.  Using other instructions, if possible, will usually improve performance.  See the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual for more information.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_SWITCHES",
      EventDef::Encoding{
          .code = 0x79,
          .umask = 0x30,
          .edge = true,
          .cmask = 1,
          .msr_values = {0x00}},
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_ALL_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x3c, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path.)",
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Instruction cache, streaming buffer and victim cache misses.)",
      R"(This event counts the number of instruction cache, streaming buffer and victim cache misses. Counting includes unchacheable accesses.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Misses at all ITLB levels that cause page walks.)",
      R"(Misses at all ITLB levels that cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Misses in all ITLB levels that cause completed page walks.)",
      R"(Misses in all ITLB levels that cause completed page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks.)",
      R"(This event count cycles when Page Miss Handler (PMH) is servicing page walks caused by ITLB misses.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Operations that miss the first ITLB level but hit the second and do not cause any page walks.)",
      R"(Operations that miss the first ITLB level but hit the second and do not cause any page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.LCP",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Stalls caused by changing prefix length of the instruction.)",
      R"(Stalls caused by changing prefix length of the instruction.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.IQ_FULL",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Stall cycles because IQ is full.)",
      R"(Stall cycles because IQ is full.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0x88, .umask = 0xFF, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired  branches.)",
      R"(Speculative and retired  branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.TAKEN_DIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x90, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired mispredicted direct near calls.)",
      R"(Taken speculative and retired mispredicted direct near calls.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.ALL_DIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xD0, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired mispredicted direct near calls.)",
      R"(Speculative and retired mispredicted direct near calls.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xFF, .cmask = 0, .msr_values = {0}},
      R"(Speculative and retired mispredicted macro conditional branches.)",
      R"(Speculative and retired mispredicted macro conditional branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Uops not delivered to Resource Allocation Table (RAT) per thread when backend of the machine is not stalled .)",
      R"(This event counts the number of uops not delivered to the back-end per cycle, per thread, when the back-end was not stalled.  In the ideal case 4 uops can be delivered each cycle.  The event counts the undelivered uops - so if 3 were delivered in one cycle, the counter would be incremented by 1 for that cycle (4 - 3). If the back-end is stalled, the count for this event is not incremented even when uops were not delivered, because the back-end would not have been able to accept them.  This event is used in determining the front-end bound category of the top-down pipeline slots characterization.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 4, .msr_values = {0}},
      R"(Cycles per thread when 4 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.)",
      R"(Cycles per thread when 4 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CYCLES_GE_1_UOP_DELIV.CORE",
      EventDef::Encoding{
          .code = 0x9C,
          .umask = 0x01,
          .inv = true,
          .cmask = 4,
          .msr_values = {0}},
      R"(Cycles when 1 or more uops were delivered to the by the front end.)",
      R"(Cycles when 1 or more uops were delivered to the by the front end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_0",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are dispatched to port 0.)",
      R"(Cycles per thread when uops are dispatched to port 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_0_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x01,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are dispatched to port 0.)",
      R"(Cycles per core when uops are dispatched to port 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_1",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are dispatched to port 1.)",
      R"(Cycles per thread when uops are dispatched to port 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_1_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x02,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are dispatched to port 1.)",
      R"(Cycles per core when uops are dispatched to port 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_2",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x0C, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when load or STA uops are dispatched to port 2.)",
      R"(Cycles per thread when load or STA uops are dispatched to port 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_2_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x0C,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when load or STA uops are dispatched to port 2.)",
      R"(Cycles per core when load or STA uops are dispatched to port 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_3",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when load or STA uops are dispatched to port 3.)",
      R"(Cycles per thread when load or STA uops are dispatched to port 3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_3_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x30,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when load or STA uops are dispatched to port 3.)",
      R"(Cycles per core when load or STA uops are dispatched to port 3.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_4",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are dispatched to port 4.)",
      R"(Cycles per thread when uops are dispatched to port 4.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_4_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x40,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are dispatched to port 4.)",
      R"(Cycles per core when uops are dispatched to port 4.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_5",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when uops are dispatched to port 5.)",
      R"(Cycles per thread when uops are dispatched to port 5.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_5_CORE",
      EventDef::Encoding{
          .code = 0xA1,
          .umask = 0x80,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Cycles per core when uops are dispatched to port 5.)",
      R"(Cycles per core when uops are dispatched to port 5.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.ANY",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Resource-related stall cycles.)",
      R"(Resource-related stall cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.LB",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the cycles of stall due to lack of load buffers.)",
      R"(Counts the cycles of stall due to lack of load buffers.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.SB",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles stalled due to no store buffers available. (not including draining form sync).)",
      R"(Cycles stalled due to no store buffers available. (not including draining form sync).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.LB_SB",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x0A, .cmask = 0, .msr_values = {0}},
      R"(Resource stalls due to load or store buffers all being in use.)",
      R"(Resource stalls due to load or store buffers all being in use.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.MEM_RS",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x0E, .cmask = 0, .msr_values = {0}},
      R"(Resource stalls due to memory buffers or Reservation Station (RS) being fully utilized.)",
      R"(Resource stalls due to memory buffers or Reservation Station (RS) being fully utilized.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.OOO_RSRC",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0xF0, .cmask = 0, .msr_values = {0}},
      R"(Resource stalls due to Rob being full, FCSW, MXCSR and OTHER.)",
      R"(Resource stalls due to Rob being full, FCSW, MXCSR and OTHER.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L2_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Each cycle there was a MLC-miss pending demand load this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0.)",
      R"(Each cycle there was a MLC-miss pending demand load this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L1D_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x02, .cmask = 2, .msr_values = {0}},
      R"(Each cycle there was a miss-pending demand load this thread, increment by 1. Note this is in DCU and connected to Umask 1. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.)",
      R"(Each cycle there was a miss-pending demand load this thread, increment by 1. Note this is in DCU and connected to Umask 1. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_NO_DISPATCH",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x04, .cmask = 4, .msr_values = {0}},
      R"(Each cycle there was no dispatch for this thread, increment by 1. Note this is connect to Umask 2. No dispatch can be deduced from the UOPS_EXECUTED event.)",
      R"(Each cycle there was no dispatch for this thread, increment by 1. Note this is connect to Umask 2. No dispatch can be deduced from the UOPS_EXECUTED event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x05, .cmask = 5, .msr_values = {0}},
      R"(Each cycle there was a MLC-miss pending demand load and no uops dispatched on this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0 and 2.)",
      R"(Each cycle there was a MLC-miss pending demand load and no uops dispatched on this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0 and 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L1D_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x06, .cmask = 6, .msr_values = {0}},
      R"(Each cycle there was a miss-pending demand load this thread and no uops dispatched, increment by 1. Note this is in DCU and connected to Umask 1 and 2. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.)",
      R"(Each cycle there was a miss-pending demand load this thread and no uops dispatched, increment by 1. Note this is in DCU and connected to Umask 1 and 2. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB2MITE_SWITCHES.COUNT",
      EventDef::Encoding{
          .code = 0xAB, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Decode Stream Buffer (DSB)-to-MITE switches.)",
      R"(Decode Stream Buffer (DSB)-to-MITE switches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB2MITE_SWITCHES.PENALTY_CYCLES",
      EventDef::Encoding{
          .code = 0xAB, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles.)",
      R"(This event counts the cycles attributed to a switch from the Decoded Stream Buffer (DSB), which holds decoded instructions, to the legacy decode pipeline.  It excludes cycles when the back-end cannot  accept new micro-ops.  The penalty for these switches is potentially several cycles of instruction starvation, where no micro-ops are delivered to the back-end.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB_FILL.OTHER_CANCEL",
      EventDef::Encoding{
          .code = 0xAC, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cases of cancelling valid DSB fill not because of exceeding way limit.)",
      R"(Cases of cancelling valid DSB fill not because of exceeding way limit.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB_FILL.EXCEED_DSB_LINES",
      EventDef::Encoding{
          .code = 0xAC, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Decode Stream Buffer (DSB) fill encounter more than 3 Decode Stream Buffer (DSB) lines.)",
      R"(Cycles when Decode Stream Buffer (DSB) fill encounter more than 3 Decode Stream Buffer (DSB) lines.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB_FILL.ALL_CANCEL",
      EventDef::Encoding{
          .code = 0xAC, .umask = 0x0A, .cmask = 0, .msr_values = {0}},
      R"(Cases of cancelling valid Decode Stream Buffer (DSB) fill not because of exceeding way limit.)",
      R"(Cases of cancelling valid Decode Stream Buffer (DSB) fill not because of exceeding way limit.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB.ITLB_FLUSH",
      EventDef::Encoding{
          .code = 0xAE, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Flushing of the Instruction TLB (ITLB) pages, includes 4k/2M/4M pages.)",
      R"(Flushing of the Instruction TLB (ITLB) pages, includes 4k/2M/4M pages.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests sent to uncore.)",
      R"(Demand Data Read requests sent to uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cacheable and noncacheable code read requests.)",
      R"(Cacheable and noncacheable code read requests.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_RFO",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Demand RFO requests including regular RFOs, locks, ItoM.)",
      R"(Demand RFO requests including regular RFOs, locks, ItoM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.ALL_DATA_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Demand and prefetch data reads.)",
      R"(Demand and prefetch data reads.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.THREAD",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Uops dispatched per thread.)",
      R"(Uops dispatched per thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED.CORE",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Uops dispatched from any thread.)",
      R"(Uops dispatched from any thread.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_1",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 1 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_2",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 2, .msr_values = {0x00}},
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 2 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_3",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 3, .msr_values = {0x00}},
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 3 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_4",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 4, .msr_values = {0x00}},
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      R"(Cycles at least 4 micro-op is executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_NONE",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x02,
          .inv = true,
          .cmask = 0,
          .msr_values = {0x00}},
      R"(Cycles with no micro-ops executed from any thread on physical core.)",
      R"(Cycles with no micro-ops executed from any thread on physical core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_BUFFER.SQ_FULL",
      EventDef::Encoding{
          .code = 0xB2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cases when offcore requests buffer cannot take more entries for core.)",
      R"(Cases when offcore requests buffer cannot take more entries for core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "AGU_BYPASS_CANCEL.COUNT",
      EventDef::Encoding{
          .code = 0xB6, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(This event counts executed load operations with all the following traits: 1. addressing of the format [base + offset], 2. the offset is between 1 and 2047, 3. the address specified in the base register is in one page and the address [base+offset] is in an.)",
      R"(This event counts executed load operations with all the following traits: 1. addressing of the format [base + offset], 2. the offset is between 1 and 2047, 3. the address specified in the base register is in one page and the address [base+offset] is in an.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TLB_FLUSH.DTLB_THREAD",
      EventDef::Encoding{
          .code = 0xBD, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(DTLB flush attempts of the thread-specific entries.)",
      R"(DTLB flush attempts of the thread-specific entries.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TLB_FLUSH.STLB_ANY",
      EventDef::Encoding{
          .code = 0xBD, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(STLB flush attempts.)",
      R"(STLB flush attempts.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.LLC_MISS",
      EventDef::Encoding{
          .code = 0xBE, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of any page walk that had a miss in LLC. Does not necessary cause a SUSPEND.)",
      R"(Number of any page walk that had a miss in LLC. Does not necessary cause a SUSPEND.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_BLOCKS.BANK_CONFLICT_CYCLES",
      EventDef::Encoding{
          .code = 0xBF, .umask = 0x05, .cmask = 1, .msr_values = {0}},
      R"(Cycles when dispatched loads are cancelled due to L1D bank conflicts with other load ports.)",
      R"(Cycles when dispatched loads are cancelled due to L1D bank conflicts with other load ports.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(Number of instructions retired. General Counter   - architectural event.)",
      R"(Number of instructions retired. General Counter   - architectural event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.PREC_DIST",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired. (Precise Event - PEBS).)",
      R"(Instructions retired. (Precise Event - PEBS).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.ITLB_MISS_RETIRED",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired instructions experiencing ITLB misses.)",
      R"(Retired instructions experiencing ITLB misses.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.AVX_STORE",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of GSSE memory assist for stores. GSSE microcode assist is being invoked whenever the hardware is unable to properly handle GSSE-256b operations.)",
      R"(Number of GSSE memory assist for stores. GSSE microcode assist is being invoked whenever the hardware is unable to properly handle GSSE-256b operations.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.AVX_TO_SSE",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of transitions from AVX-256 to legacy SSE when penalty applicable.)",
      R"(Number of transitions from AVX-256 to legacy SSE when penalty applicable.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.SSE_TO_AVX",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of transitions from SSE to AVX-256 when penalty applicable.)",
      R"(Number of transitions from SSE to AVX-256 when penalty applicable.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Actually retired uops. (Precise Event - PEBS).)",
      R"(This event counts the number of micro-ops retired. (Precise Event))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.TOTAL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x01,
          .inv = true,
          .cmask = 10,
          .msr_values = {0}},
      R"(Cycles with less than 10 actually retired uops.)",
      R"(Cycles with less than 10 actually retired uops.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.CORE_STALL_CYCLES",
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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.RETIRE_SLOTS",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retirement slots used. (Precise Event - PEBS).)",
      R"(This event counts the number of retirement slots used each cycle.  There are potentially 4 slots that can be used each cycle - meaning, 4 micro-ops or 4 instructions could retire each cycle.  This event is used in determining the 'Retiring' category of the Top-Down pipeline slots characterization. (Precise Event - PEBS))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.COUNT",
      EventDef::Encoding{
          .code = 0xc3,
          .umask = 0x01,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Number of machine clears (nukes) of any type.)",
      R"(Number of machine clears (nukes) of any type.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of machine clears due to memory order conflicts.)",
      R"(This event counts the number of memory ordering Machine Clears detected. Memory Ordering Machine Clears can result from memory disambiguation, external snoops, or cross SMT-HW-thread snoop (stores) hitting load buffers.  Machine clears can have a significant performance impact if they are happening frequently.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(All (macro) branch instructions retired.)",
      R"(All (macro) branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Conditional branch instructions retired. (Precise Event - PEBS).)",
      R"(Conditional branch instructions retired. (Precise Event - PEBS).)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect near call instructions retired. (Precise Event - PEBS).)",
      R"(Direct and indirect near call instructions retired. (Precise Event - PEBS).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL_R3",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect macro near call instructions retired (captured in ring 3). (Precise Event - PEBS).)",
      R"(Direct and indirect macro near call instructions retired (captured in ring 3). (Precise Event - PEBS).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(All (macro) branch instructions retired. (Precise Event - PEBS).)",
      R"(All (macro) branch instructions retired. (Precise Event - PEBS).)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_RETURN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Return instructions retired. (Precise Event - PEBS).)",
      R"(Return instructions retired. (Precise Event - PEBS).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NOT_TAKEN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Not taken branch instructions retired.)",
      R"(Not taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Taken branch instructions retired. (Precise Event - PEBS).)",
      R"(Taken branch instructions retired. (Precise Event - PEBS).)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Far branch instructions retired.)",
      R"(Far branch instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x00, .cmask = 0, .msr_values = {0}},
      R"(All mispredicted macro branch instructions retired.)",
      R"(All mispredicted macro branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted conditional branch instructions retired. (Precise Event - PEBS).)",
      R"(Mispredicted conditional branch instructions retired. (Precise Event - PEBS).)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect mispredicted near call instructions retired. (Precise Event - PEBS).)",
      R"(Direct and indirect mispredicted near call instructions retired. (Precise Event - PEBS).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted macro branch instructions retired. (Precise Event - PEBS).)",
      R"(Mispredicted macro branch instructions retired. (Precise Event - PEBS))",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NOT_TAKEN",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted not taken branch instructions retired.(Precise Event - PEBS).)",
      R"(Mispredicted not taken branch instructions retired.(Precise Event - PEBS).)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.TAKEN",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted taken branch instructions retired. (Precise Event - PEBS).)",
      R"(Mispredicted taken branch instructions retired. (Precise Event - PEBS).)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.X87_OUTPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Number of X87 assists due to output value.)",
      R"(Number of X87 assists due to output value.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.X87_INPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Number of X87 assists due to input value.)",
      R"(Number of X87 assists due to input value.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.SIMD_OUTPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of SIMD FP assists due to Output values.)",
      R"(Number of SIMD FP assists due to Output values.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.SIMD_INPUT",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of SIMD FP assists due to input values.)",
      R"(Number of SIMD FP assists due to input values.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.ANY",
      EventDef::Encoding{
          .code = 0xCA, .umask = 0x1E, .cmask = 1, .msr_values = {0}},
      R"(Cycles with any input/output SSE or FP assist.)",
      R"(Cycles with any input/output SSE or FP assist.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ROB_MISC_EVENTS.LBR_INSERTS",
      EventDef::Encoding{
          .code = 0xCC, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Count cases of saving new LBR.)",
      R"(Count cases of saving new LBR.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_4",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x4}},
      R"(Loads with latency value being above 4 .)",
      R"(Loads with latency value being above 4 .)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_8",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x8}},
      R"(Loads with latency value being above 8.)",
      R"(Loads with latency value being above 8.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_16",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x10}},
      R"(Loads with latency value being above 16.)",
      R"(Loads with latency value being above 16.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_32",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x20}},
      R"(Loads with latency value being above 32.)",
      R"(Loads with latency value being above 32.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_64",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x40}},
      R"(Loads with latency value being above 64.)",
      R"(Loads with latency value being above 64.)",
      2003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_128",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x80}},
      R"(Loads with latency value being above 128.)",
      R"(Loads with latency value being above 128.)",
      1009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_256",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x100}},
      R"(Loads with latency value being above 256.)",
      R"(Loads with latency value being above 256.)",
      503,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_512",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x200}},
      R"(Loads with latency value being above 512.)",
      R"(Loads with latency value being above 512.)",
      101,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.PRECISE_STORE",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Sample stores and collect precise store operation via PEBS record. PMC3 only. (Precise Event - PEBS).)",
      R"(Sample stores and collect precise store operation via PEBS record. PMC3 only. (Precise Event - PEBS).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x11, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that miss the STLB. (Precise Event - PEBS).)",
      R"(Retired load uops that miss the STLB. (Precise Event - PEBS).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x12, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that miss the STLB. (Precise Event - PEBS).)",
      R"(Retired store uops that miss the STLB. (Precise Event - PEBS).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with locked access. (Precise Event - PEBS).)",
      R"(Retired load uops with locked access. (Precise Event - PEBS).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that split across a cacheline boundary. (Precise Event - PEBS).)",
      R"(This event counts line-split load uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K). (Precise Event - PEBS))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x42, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that split across a cacheline boundary. (Precise Event - PEBS).)",
      R"(This event counts line-split store uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K). (Precise Event - PEBS))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(All retired load uops. (Precise Event - PEBS).)",
      R"(This event counts the number of load uops retired (Precise Event))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(All retired store uops. (Precise Event - PEBS).)",
      R"(This event counts the number of store uops retired. (Precise Event - PEBS))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L1 cache hits as data sources. (Precise Event - PEBS).)",
      R"(Retired load uops with L1 cache hits as data sources. (Precise Event - PEBS).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L2 cache hits as data sources. (Precise Event - PEBS).)",
      R"(Retired load uops with L2 cache hits as data sources. (Precise Event - PEBS).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.LLC_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were data hits in LLC without snoops required. (Precise Event - PEBS).)",
      R"(This event counts retired load uops that hit in the last-level (L3) cache without snoops required. (Precise Event - PEBS))",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.HIT_LFB",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready. (Precise Event - PEBS).)",
      R"(Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready. (Precise Event - PEBS).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_MISS",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache. (Precise Event - PEBS).)",
      R"(Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache. (Precise Event - PEBS).)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_HIT",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were LLC and cross-core snoop hits in on-pkg core cache. (Precise Event - PEBS).)",
      R"(This event counts retired load uops that hit in the last-level cache (L3) and were found in a non-modified state in a neighboring core's private cache (same package).  Since the last level cache is inclusive, hits to the L3 may require snooping the private L2 caches of any cores on the same socket that have the line.  In this case, a snoop was required, and another L2 had the line in a non-modified state. (Precise Event - PEBS))",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_HITM",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were HitM responses from shared LLC. (Precise Event - PEBS).)",
      R"(This event counts retired load uops that hit in the last-level cache (L3) and were found in a non-modified state in a neighboring core's private cache (same package).  Since the last level cache is inclusive, hits to the L3 may require snooping the private L2 caches of any cores on the same socket that have the line.  In this case, a snoop was required, and another L2 had the line in a modified state, so the line had to be invalidated in that L2 cache and transferred to the requesting L2. (Precise Event - PEBS))",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_NONE",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were hits in LLC without snoops required. (Precise Event - PEBS).)",
      R"(Retired load uops which data sources were hits in LLC without snoops required. (Precise Event - PEBS).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_MISC_RETIRED.LLC_MISS",
      EventDef::Encoding{
          .code = 0xD4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with unknown information as data source in cache serviced the load. (Precise Event - PEBS).)",
      R"(This event counts retired demand loads that missed the  last-level (L3) cache. This means that the load is usually satisfied from memory in a client system or possibly from the remote socket in a server. Demand loads are non speculative load uops. (Precise Event - PEBS))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ANY",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x1F, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests that access L2 cache.)",
      R"(Demand Data Read requests that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.RFO",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that access L2 cache.)",
      R"(RFO requests that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.CODE_RD",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(L2 cache accesses when fetching instructions.)",
      R"(L2 cache accesses when fetching instructions.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.ALL_PF",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(L2 or LLC HW prefetches that access L2 cache.)",
      R"(L2 or LLC HW prefetches that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L1D_WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L1D writebacks that access L2 cache.)",
      R"(L1D writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L2_FILL",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 fill requests that access L2 cache.)",
      R"(L2 fill requests that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L2_WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(L2 writebacks that access L2 cache.)",
      R"(L2 writebacks that access L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.ALL_REQUESTS",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Transactions accessing L2 pipe.)",
      R"(Transactions accessing L2 pipe.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.I",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines in I state filling L2.)",
      R"(L2 cache lines in I state filling L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.S",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines in S state filling L2.)",
      R"(L2 cache lines in S state filling L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.E",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines in E state filling L2.)",
      R"(L2 cache lines in E state filling L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.ALL",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x07, .cmask = 0, .msr_values = {0}},
      R"(L2 cache lines filling L2.)",
      R"(This event counts the number of L2 cache lines brought into the L2 cache.  Lines are filled into the L2 cache when there was an L2 miss.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DEMAND_CLEAN",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Clean L2 cache lines evicted by demand.)",
      R"(Clean L2 cache lines evicted by demand.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DEMAND_DIRTY",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Dirty L2 cache lines evicted by demand.)",
      R"(Dirty L2 cache lines evicted by demand.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.PF_CLEAN",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Clean L2 cache lines evicted by L2 prefetch.)",
      R"(Clean L2 cache lines evicted by L2 prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.PF_DIRTY",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Dirty L2 cache lines evicted by L2 prefetch.)",
      R"(Dirty L2 cache lines evicted by L2 prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DIRTY_ALL",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x0A, .cmask = 0, .msr_values = {0}},
      R"(Dirty L2 cache lines filling the L2.)",
      R"(Dirty L2 cache lines filling the L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SQ_MISC.SPLIT_LOCK",
      EventDef::Encoding{
          .code = 0xF4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Split locks in SQ.)",
      R"(Split locks in SQ.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0244}},
      R"(Counts demand & prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts demand & prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0244}},
      R"(Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0244}},
      R"(Counts demand & prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts demand & prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400244}},
      R"(Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram.)",
      R"(Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0091}},
      R"(Counts all demand & prefetch data reads that hit in the LLC.)",
      R"(Counts all demand & prefetch data reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0091}},
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
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
          .msr_values = {0x10003c0091}},
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0091}},
      R"(Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0091}},
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400091}},
      R"(Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram.)",
      R"(Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0240}},
      R"(Counts all prefetch code reads that hit in the LLC.)",
      R"(Counts all prefetch code reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0240}},
      R"(Counts prefetch code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0240}},
      R"(Counts prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0240}},
      R"(Counts prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0240}},
      R"(Counts prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400240}},
      R"(Counts all prefetch code reads that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch code reads that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0090}},
      R"(Counts all prefetch data reads that hit in the LLC.)",
      R"(Counts all prefetch data reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0090}},
      R"(Counts prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0090}},
      R"(Counts prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0090}},
      R"(Counts prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0090}},
      R"(Counts prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400090}},
      R"(Counts all prefetch data reads that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch data reads that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0120}},
      R"(Counts all prefetch RFOs that hit in the LLC.)",
      R"(Counts all prefetch RFOs that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0120}},
      R"(Counts prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0120}},
      R"(Counts prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0120}},
      R"(Counts prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0120}},
      R"(Counts prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400120}},
      R"(Counts all prefetch RFOs that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch RFOs that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c03f7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) that hit in the LLC.)",
      R"(Counts all data/code/rfo reads (demand & prefetch) that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c03f7}},
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
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
          .msr_values = {0x10003c03f7}},
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c03f7}},
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c03f7}},
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x3004003f7}},
      R"(Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram.)",
      R"(Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0122}},
      R"(Counts all demand & prefetch RFOs that hit in the LLC.)",
      R"(Counts all demand & prefetch RFOs that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0122}},
      R"(Counts demand & prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts demand & prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
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
          .msr_values = {0x10003c0122}},
      R"(Counts demand & prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts demand & prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0122}},
      R"(Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0122}},
      R"(Counts demand & prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts demand & prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400122}},
      R"(Counts all demand & prefetch RFOs that miss the LLC  and the data returned from dram.)",
      R"(Counts all demand & prefetch RFOs that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.COREWB.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10008}},
      R"(OFFCORE_RESPONSE.COREWB.ANY_RESPONSE)",
      R"(OFFCORE_RESPONSE.COREWB.ANY_RESPONSE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0004}},
      R"(Counts all demand code reads that hit in the LLC.)",
      R"(Counts all demand code reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0004}},
      R"(Counts demand code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts demand code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
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
          .msr_values = {0x10003c0004}},
      R"(Counts demand code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts demand code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0004}},
      R"(Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0004}},
      R"(Counts demand code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts demand code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400004}},
      R"(Counts demand code reads that miss the LLC and the data returned from dram.)",
      R"(Counts demand code reads that miss the LLC and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0001}},
      R"(Counts all demand data reads that hit in the LLC.)",
      R"(Counts all demand data reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0001}},
      R"(Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
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
          .msr_values = {0x10003c0001}},
      R"(Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0001}},
      R"(Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0001}},
      R"(Counts demand data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts demand data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400001}},
      R"(Counts demand data reads that miss the LLC and the data returned from dram.)",
      R"(Counts demand data reads that miss the LLC and the data returned from dram.)",
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
          .msr_values = {0x3f803c0002}},
      R"(Counts all demand data writes (RFOs) that hit in the LLC.)",
      R"(Counts all demand data writes (RFOs) that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0002}},
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
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
          .msr_values = {0x10003c0002}},
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0002}},
      R"(Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0002}},
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400002}},
      R"(Counts demand data writes (RFOs) that miss the LLC and the data returned from dram.)",
      R"(Counts demand data writes (RFOs) that miss the LLC and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.OTHER.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x18000}},
      R"(Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches.)",
      R"(Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.OTHER.LRU_HINTS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x803c8000}},
      R"(Counts L2 hints sent to LLC to keep a line from being evicted out of the core caches.)",
      R"(Counts L2 hints sent to LLC to keep a line from being evicted out of the core caches.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.OTHER.PORTIO_MMIO_UC",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2380408000}},
      R"(Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses.)",
      R"(Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses.)",
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
          .msr_values = {0x3f803c0040}},
      R"(Counts all prefetch (that bring data to L2) code reads that hit in the LLC.)",
      R"(Counts all prefetch (that bring data to L2) code reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0040}},
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0040}},
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0040}},
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0040}},
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400040}},
      R"(Counts all prefetch (that bring data to L2) code reads that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch (that bring data to L2) code reads that miss the LLC  and the data returned from dram.)",
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
          .msr_values = {0x3f803c0010}},
      R"(Counts all prefetch (that bring data to L2) data reads that hit in the LLC.)",
      R"(Counts all prefetch (that bring data to L2) data reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0010}},
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0010}},
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0010}},
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0010}},
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400010}},
      R"(Counts prefetch (that bring data to L2) data reads that miss the LLC and the data returned from dram.)",
      R"(Counts prefetch (that bring data to L2) data reads that miss the LLC and the data returned from dram.)",
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
          .msr_values = {0x3f803c0020}},
      R"(Counts all prefetch (that bring data to L2) RFOs that hit in the LLC.)",
      R"(Counts all prefetch (that bring data to L2) RFOs that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0020}},
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0020}},
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0020}},
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0020}},
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L2_RFO.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400020}},
      R"(Counts all prefetch (that bring data to L2) RFOs that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch (that bring data to L2) RFOs that miss the LLC  and the data returned from dram.)",
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
          .msr_values = {0x3f803c0200}},
      R"(Counts all prefetch (that bring data to LLC only) code reads that hit in the LLC.)",
      R"(Counts all prefetch (that bring data to LLC only) code reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0200}},
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0200}},
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0200}},
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0200}},
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400200}},
      R"(Counts all prefetch (that bring data to LLC only) code reads that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch (that bring data to LLC only) code reads that miss the LLC  and the data returned from dram.)",
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
          .msr_values = {0x3f803c0080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads that hit in the LLC.)",
      R"(Counts all prefetch (that bring data to LLC only) data reads that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0080}},
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0080}},
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0080}},
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0080}},
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400080}},
      R"(Counts all prefetch (that bring data to LLC only) data reads that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch (that bring data to LLC only) data reads that miss the LLC  and the data returned from dram.)",
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
          .msr_values = {0x3f803c0100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs that hit in the LLC.)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs that hit in the LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003c0100}},
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.HITM_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003c0100}},
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.NO_SNOOP_NEEDED",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003c0100}},
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003c0100}},
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      R"(Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_MISS.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x300400100}},
      R"(Counts all prefetch (that bring data to LLC only) RFOs that miss the LLC  and the data returned from dram.)",
      R"(Counts all prefetch (that bring data to LLC only) RFOs that miss the LLC  and the data returned from dram.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.SPLIT_LOCK_UC_LOCK.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10400}},
      R"(Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address.)",
      R"(Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.STREAMING_STORES.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10800}},
      R"(Counts non-temporal stores.)",
      R"(Counts non-temporal stores.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x00010001}},
      R"(Counts all demand data reads .)",
      R"(Counts all demand data reads .)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x00010002}},
      R"(Counts all demand rfo's .)",
      R"(Counts all demand rfo's .)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x00010004}},
      R"(Counts all demand code reads.)",
      R"(Counts all demand code reads.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x000105B3}},
      R"(Counts all demand & prefetch data reads.)",
      R"(Counts all demand & prefetch data reads.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x00010122}},
      R"(Counts all demand & prefetch prefetch RFOs .)",
      R"(Counts all demand & prefetch prefetch RFOs .)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_READS.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x000107F7}},
      R"(Counts all data/code/rfo references (demand & prefetch) .)",
      R"(Counts all data/code/rfo references (demand & prefetch) .)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DATA_IN_SOCKET.LLC_MISS.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x6004001b3}},
      R"(Counts LLC replacements.)",
      R"(This event counts all data requests (demand/prefetch data reads and demand data writes (RFOs) that miss the LLC  where the data is returned from local DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ANY_REQUEST.LLC_MISS_LOCAL.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1f80408fff}},
      R"(REQUEST = ANY_REQUEST and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      R"(This event counts any requests that miss the LLC where the data was returned from local DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DATA_IN.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x10433}},
      R"(REQUEST = DATA_INTO_CORE and RESPONSE = ANY_RESPONSE)",
      R"(REQUEST = DATA_INTO_CORE and RESPONSE = ANY_RESPONSE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DATA_IN_SOCKET.LLC_MISS_LOCAL.ANY_LLC_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x17004001b3}},
      R"(REQUEST = DATA_IN_SOCKET and RESPONSE = LLC_MISS_LOCAL and SNOOP = ANY_LLC_HIT)",
      R"(REQUEST = DATA_IN_SOCKET and RESPONSE = LLC_MISS_LOCAL and SNOOP = ANY_LLC_HIT)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_IFETCH.LLC_MISS_LOCAL.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1f80400004}},
      R"(REQUEST = DEMAND_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      R"(REQUEST = DEMAND_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT_M.HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1000040002}},
      R"(REQUEST = DEMAND_RFO and RESPONSE = LLC_HIT_M and SNOOP = HITM)",
      R"(REQUEST = DEMAND_RFO and RESPONSE = LLC_HIT_M and SNOOP = HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_DATA_RD.LLC_MISS_LOCAL.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1f80400010}},
      R"(REQUEST = PF_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      R"(REQUEST = PF_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_IFETCH.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x10040}},
      R"(REQUEST = PF_RFO and RESPONSE = ANY_RESPONSE)",
      R"(REQUEST = PF_RFO and RESPONSE = ANY_RESPONSE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_IFETCH.LLC_MISS_LOCAL.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1f80400040}},
      R"(REQUEST = PF_RFO and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      R"(REQUEST = PF_RFO and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x10080}},
      R"(REQUEST = PF_LLC_DATA_RD and RESPONSE = ANY_RESPONSE)",
      R"(REQUEST = PF_LLC_DATA_RD and RESPONSE = ANY_RESPONSE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L_DATA_RD.LLC_MISS_LOCAL.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1f80400080}},
      R"(REQUEST = PF_LLC_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      R"(REQUEST = PF_LLC_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L_IFETCH.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x10200}},
      R"(REQUEST = PF_LLC_IFETCH and RESPONSE = ANY_RESPONSE)",
      R"(REQUEST = PF_LLC_IFETCH and RESPONSE = ANY_RESPONSE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.PF_L_IFETCH.LLC_MISS_LOCAL.DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1f80400200}},
      R"(REQUEST = PF_LLC_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      R"(REQUEST = PF_LLC_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace sandybridge_core
} // namespace facebook::hbt::perf_event::generated
