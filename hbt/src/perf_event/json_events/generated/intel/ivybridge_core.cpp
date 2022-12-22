// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace ivybridge_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from ivybridge_core.json (317 events).

    Supported SKUs:
        - Arch: x86, Model: IVB id: 58
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired from execution.)",
      R"(Instructions retired from execution.)",
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
      R"(Core cycles when the thread is not in halt state.)",
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
      R"(Core cycles when at least one thread on the physical core is not in halt state)",
      R"(Core cycles when at least one thread on the physical core is not in halt state.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when the core is not in halt state.)",
      R"(Reference cycles when the core is not in halt state.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.STORE_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cases when loads get true Block-on-Store blocking code preventing store forwarding)",
      R"(Loads blocked by overlapping with store buffer that cannot be forwarded.)",
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
      R"(The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.STORES",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Speculative cache line split STA uops dispatched to L1 cache)",
      R"(Speculative cache-line split Store-address uops dispatched to L1D.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS_PARTIAL.ADDRESS_ALIAS",
      EventDef::Encoding{
          .code = 0x07, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(False dependencies in MOB due to partial compare on address)",
      R"(False dependencies in MOB due to partial compare on address.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes an page walk of any page size.)",
      R"(Misses in all TLB levels that cause a page walk of any page size from demand loads.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes of any page size.)",
      R"(Misses in all TLB levels that caused page walk completed of any size by demand loads.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x84, .cmask = 0, .msr_values = {0}},
      R"(Demand load cycles page miss handler (PMH) is busy with this walk.)",
      R"(Cycle PMH is busy with a walk due to demand loads.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.LARGE_PAGE_WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x88, .cmask = 0, .msr_values = {0}},
      R"(Page walk for a large page completed for Demand load.)",
      R"(Page walk for a large page completed for Demand load.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INT_MISC.RECOVERY_CYCLES",
      EventDef::Encoding{
          .code = 0x0D, .umask = 0x03, .cmask = 1, .msr_values = {0}},
      R"(Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.))",
      R"(Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.))",
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
      R"(Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.))",
      R"(Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.))",
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
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Uops that Resource Allocation Table (RAT) issues to Reservation Station (RS))",
      R"(Increments each cycle the # of Uops issued by the RAT to RS. Set Cmask = 1, Inv = 1, Any= 1to count stalled cycles of this core.)",
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
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for the thread)",
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
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads)",
      R"(Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.FLAGS_MERGE",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of flags-merge uops being allocated.)",
      R"(Number of flags-merge uops allocated. Such uops adds delay.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.SLOW_LEA",
      EventDef::Encoding{
          .code = 0x0E, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Number of slow LEA uops being allocated. A uop is generally considered SlowLea if it has 3 sources (e.g. 2 sources + immediate) regardless if as a result of LEA instruction or not.)",
      R"(Number of slow LEA or similar uops allocated. Such uop has 3 sources (e.g. 2 sources + immediate) regardless if as a result of LEA instruction or not.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.X87",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of FP Computational Uops Executed this cycle. The number of FADD, FSUB, FCOM, FMULs, integer MULsand IMULs, FDIVs, FPREMs, FSQRTS, integer DIVs, and IDIVs. This event does not distinguish an FADD used in the middle of a transcendental flow from a s)",
      R"(Counts number of X87 uops executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Number of SSE* or AVX-128 FP Computational packed double-precision uops issued this cycle)",
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
      R"(Number of SSE* or AVX-128 FP Computational scalar single-precision uops issued this cycle)",
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
      R"(Number of SSE* or AVX-128 FP Computational packed single-precision uops issued this cycle)",
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
      R"(Number of SSE* or AVX-128 FP Computational scalar double-precision uops issued this cycle)",
      R"(Counts number of SSE* or AVX-128 double precision FP scalar uops executed.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_FP_256.PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0x11, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(number of GSSE-256 Computational FP single precision uops issued this cycle)",
      R"(Counts 256-bit packed single-precision floating-point instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_FP_256.PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0x11, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(number of AVX-256 Computational FP double precision uops issued this cycle)",
      R"(Counts 256-bit packed double-precision floating-point instructions.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.FPU_DIV_ACTIVE",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when divider is busy executing divide operations)",
      R"(Cycles that the divider is active, includes INT and FP. Set 'edge =1, cmask=1' to count the number of divides.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.FPU_DIV",
      EventDef::Encoding{
          .code = 0x14,
          .umask = 0x04,
          .edge = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Divide operations executed)",
      R"(Divide operations executed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.DEMAND_DATA_RD_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests that hit L2 cache)",
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
      R"(Demand Data Read requests)",
      R"(Counts any demand and L1 HW prefetch data load requests to L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(RFO requests that hit L2 cache)",
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
      R"(RFO requests that miss L2 cache)",
      R"(Counts the number of store RFO requests that miss the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_RFO",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x0C, .cmask = 0, .msr_values = {0}},
      R"(RFO requests to L2 cache)",
      R"(Counts all L2 store RFO requests.)",
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
      R"(Number of instruction fetches that hit the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.CODE_RD_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 cache misses when fetching instructions)",
      R"(Number of instruction fetches that missed the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_CODE_RD",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(L2 code requests)",
      R"(Counts all L2 code requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PF_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Requests from the L2 hardware prefetchers that hit L2 cache)",
      R"(Counts all L2 HW prefetcher requests that hit L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PF_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Requests from the L2 hardware prefetchers that miss L2 cache)",
      R"(Counts all L2 HW prefetcher requests that missed L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.ALL_PF",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xC0, .cmask = 0, .msr_values = {0}},
      R"(Requests from L2 hardware prefetchers)",
      R"(Counts all L2 HW prefetcher requests.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_STORE_LOCK_RQSTS.MISS",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(RFOs that miss cache lines)",
      R"(RFOs that miss cache lines.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_STORE_LOCK_RQSTS.HIT_M",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(RFOs that hit cache lines in M state)",
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
      R"(RFOs that access cache lines in any state)",
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
      R"(Count the number of modified Lines evicted from L1 and missed L2. (Non-rejected WBs from the DCU.))",
      R"(Not rejected writebacks that missed LLC.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_L1D_WB_RQSTS.HIT_E",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Not rejected writebacks from L1D to L2 cache lines in E state)",
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
      R"(Not rejected writebacks from L1D to L2 cache lines in M state)",
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
      R"(Core-originated cacheable demand requests missed LLC)",
      R"(This event counts each cache miss condition for references to the last level cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x4F, .cmask = 0, .msr_values = {0}},
      R"(Core-originated cacheable demand requests that refer to LLC)",
      R"(This event counts requests originating from the core that reference a cache line in the last level cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(Core cycles when at least one thread on the physical core is not in halt state)",
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
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate))",
      R"(Increments at the frequency of XCLK (100 MHz) when not halted.)",
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
          .msr_values = {0}},
      R"(Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate))",
      R"(Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_XCLK",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Reference cycles when the thread is unhalted (counts at 100 MHz rate))",
      R"(Reference cycles when the thread is unhalted. (counts at 100 MHz rate))",
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
      R"(Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate))",
      R"(Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate))",
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
      R"(L1D miss oustandings duration in cycles)",
      R"(Increments the number of outstanding L1D misses every cycle. Set Cmask = 1 and Edge =1 to count occurrences.)",
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
      R"(Cycles with L1D load Misses outstanding from any thread on physical core)",
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
      R"(Cycles a demand request was blocked due to Fill Buffers inavailability)",
      R"(Cycles a demand request was blocked due to Fill Buffers inavailability.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Store misses in all DTLB levels that cause completed page walks)",
      R"(Miss in all TLB levels causes a page walk that completes of any page size (4K/2M/4M/1G).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_DURATION",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles when PMH is busy with page walks)",
      R"(Cycles PMH is busy with this walk.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Store operations that miss the first TLB level but hit the second and do not cause page walks)",
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
      R"(Not software-prefetch load dispatches that hit FB allocated for software prefetch)",
      R"(Non-SW-prefetch load dispatches that hit fill buffer allocated for S/W prefetch.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE.HW_PF",
      EventDef::Encoding{
          .code = 0x4C, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Not software-prefetch load dispatches that hit FB allocated for hardware prefetch)",
      R"(Non-SW-prefetch load dispatches that hit fill buffer allocated for H/W prefetch.)",
      100003,
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
      R"(L1D data line replacements)",
      R"(Counts the number of lines brought into the L1 data cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(Number of intervals between processor halts while thread is in ring 0)",
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
      R"(Unhalted core cycles when thread is in rings 1, 2, or 3)",
      R"(Unhalted core cycles when the thread is not in ring 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RS_EVENTS.EMPTY_CYCLES",
      EventDef::Encoding{
          .code = 0x5E, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Reservation Station (RS) is empty for the thread)",
      R"(Cycles the RS is empty for the thread.)",
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
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x5F, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Load operations that miss the first DTLB level but hit the second and do not cause page walks)",
      R"(Counts load operations that missed 1st level DTLB but hit the 2nd level.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding Demand Data Read transactions in uncore queue.)",
      R"(Offcore outstanding Demand Data Read transactions in SQ to uncore. Set Cmask=1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore)",
      R"(Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD_GE_6",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x01, .cmask = 6, .msr_values = {0x00}},
      R"(Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue)",
      R"(Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle)",
      R"(Offcore outstanding Demand Code Read transactions in SQ to uncore. Set Cmask=1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x02, .cmask = 1, .msr_values = {0}},
      R"(Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle)",
      R"(Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x04, .cmask = 1, .msr_values = {0}},
      R"(Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle)",
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
      R"(Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore)",
      R"(Offcore outstanding cacheable data read transactions in SQ to uncore. Set Cmask=1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
      EventDef::Encoding{
          .code = 0x60, .umask = 0x08, .cmask = 1, .msr_values = {0}},
      R"(Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore)",
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
      R"(Cycles when L1 and L2 are locked due to UC or split lock)",
      R"(Cycles in which the L1D and L2 are locked, due to a UC lock or split lock.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x04, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from MITE path)",
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
      R"(Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path)",
      R"(Increment each cycle. # of uops delivered to IDQ from DSB path. Set Cmask = 1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.DSB_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x08, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from Decode Stream Buffer (DSB) path)",
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
      R"(Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Increment each cycle # of uops delivered to IDQ when MS_busy by DSB. Set Cmask = 1 to count cycles. Add Edge=1 to count # of delivery.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_DSB_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x10, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy.)",
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
      R"(Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequenser (MS) is busy)",
      R"(Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequenser (MS) is busy.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_MITE_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Increment each cycle # of uops delivered to IDQ when MS_busy by MITE. Set Cmask = 1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.ALL_MITE_CYCLES_ANY_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x24, .cmask = 1, .msr_values = {0}},
      R"(Cycles MITE is delivering any Uop)",
      R"(Counts cycles MITE is delivered at least one uops. Set Cmask = 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Increment each cycle # of uops delivered to IDQ from MS by either DSB or MITE. Set Cmask = 1 to count cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MS_CYCLES",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x30, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy)",
      R"(Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequenser (MS) is busy.)",
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
          .msr_values = {0}},
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer)",
      R"(Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ.MITE_ALL_UOPS",
      EventDef::Encoding{
          .code = 0x79, .umask = 0x3C, .cmask = 0, .msr_values = {0}},
      R"(Uops delivered to Instruction Decode Queue (IDQ) from MITE path)",
      R"(Number of uops delivered to IDQ from any path.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.HIT",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches)",
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
      R"(Instruction cache, streaming buffer and victim cache misses)",
      R"(Number of Instruction Cache, Streaming Buffer and Victim Cache Misses. Includes UC accesses.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.IFETCH_STALL",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Cycles where a code-fetch stalled due to L1 instruction-cache miss or an iTLB miss)",
      R"(Cycles where a code-fetch stalled due to L1 instruction-cache miss or an iTLB miss.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.MISS_CAUSES_A_WALK",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Misses at all ITLB levels that cause page walks)",
      R"(Misses in all ITLB levels that cause page walks.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Misses in all ITLB levels that cause completed page walks)",
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
      R"(Cycles when PMH is busy with page walks)",
      R"(Cycle PMH is busy with a walk.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Operations that miss the first ITLB level but hit the second and do not cause any page walks)",
      R"(Number of cache load STLB hits. No page walk.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.LARGE_PAGE_WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Completed page walks in ITLB due to STLB load misses for large pages)",
      R"(Completed page walks in ITLB due to STLB load misses for large pages.)",
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
      R"(Stall cycles because IQ is full)",
      R"(Stall cycles due to IQ is full.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.NONTAKEN_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Not taken macro-conditional branches)",
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
      R"(Taken speculative and retired macro-conditional branches)",
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
      R"(Taken speculative and retired macro-conditional branch instructions excluding calls and indirects)",
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
      R"(Taken speculative and retired indirect branches excluding calls and returns)",
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
      R"(Taken speculative and retired indirect branches with return mnemonic)",
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
      R"(Taken speculative and retired direct near calls)",
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
      R"(Taken speculative and retired indirect calls)",
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
      R"(Speculative and retired macro-conditional branches)",
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
      R"(Speculative and retired macro-unconditional branches excluding calls and indirects)",
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
      R"(Speculative and retired indirect branches excluding calls and returns)",
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
      R"(Speculative and retired direct near calls)",
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
      R"(Speculative and retired  branches)",
      R"(Counts all near executed branches (not necessarily retired).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.NONTAKEN_CONDITIONAL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Not taken speculative and retired mispredicted macro conditional branches)",
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
      R"(Taken speculative and retired mispredicted macro conditional branches)",
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
      R"(Taken speculative and retired mispredicted indirect branches excluding calls and returns)",
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
      R"(Taken speculative and retired mispredicted indirect branches with return mnemonic)",
      R"(Taken speculative and retired mispredicted indirect branches with return mnemonic.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.TAKEN_INDIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0xA0, .cmask = 0, .msr_values = {0}},
      R"(Taken speculative and retired mispredicted indirect calls)",
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
      R"(Speculative and retired mispredicted macro conditional branches)",
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
      R"(Mispredicted indirect branches excluding calls and returns)",
      R"(Mispredicted indirect branches excluding calls and returns.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IDQ_UOPS_NOT_DELIVERED.CORE",
      EventDef::Encoding{
          .code = 0x9C, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Uops not delivered to Resource Allocation Table (RAT) per thread when backend of the machine is not stalled)",
      R"(Count issue pipeline slots where no uop was delivered from the front end to the back end when there is no back-end stall.)",
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
      R"(Cycles per thread when uops are dispatched to port 0)",
      R"(Cycles which a Uop is dispatched on port 0.)",
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
      R"(Cycles per core when uops are dispatched to port 0)",
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
      R"(Cycles per thread when uops are dispatched to port 1)",
      R"(Cycles which a Uop is dispatched on port 1.)",
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
      R"(Cycles per core when uops are dispatched to port 1)",
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
      R"(Cycles per thread when load or STA uops are dispatched to port 2)",
      R"(Cycles which a Uop is dispatched on port 2.)",
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
      R"(Uops dispatched to port 2, loads and stores per core (speculative and retired).)",
      R"(Uops dispatched to port 2, loads and stores per core (speculative and retired).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DISPATCHED_PORT.PORT_3",
      EventDef::Encoding{
          .code = 0xA1, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(Cycles per thread when load or STA uops are dispatched to port 3)",
      R"(Cycles which a Uop is dispatched on port 3.)",
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
      R"(Cycles per core when load or STA uops are dispatched to port 3)",
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
      R"(Cycles per thread when uops are dispatched to port 4)",
      R"(Cycles which a Uop is dispatched on port 4.)",
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
      R"(Cycles per core when uops are dispatched to port 4)",
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
      R"(Cycles per thread when uops are dispatched to port 5)",
      R"(Cycles which a Uop is dispatched on port 5.)",
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
      R"(Cycles per core when uops are dispatched to port 5)",
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
      R"(Resource-related stall cycles)",
      R"(Cycles Allocation is stalled due to Resource Related reason.)",
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
      R"(Cycles stalled due to no store buffers available (not including draining form sync).)",
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
      "CYCLE_ACTIVITY.CYCLES_L2_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x01, .cmask = 1, .msr_values = {0}},
      R"(Cycles with pending L2 cache miss loads.)",
      R"(Cycles with pending L2 miss loads. Set AnyThread to count per core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L2_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x01, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles while L2 cache miss load* is outstanding.)",
      R"(Cycles while L2 cache miss load* is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_LDM_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x02, .cmask = 2, .msr_values = {0}},
      R"(Cycles with pending memory loads.)",
      R"(Cycles with pending memory loads. Set AnyThread to count per core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_NO_EXECUTE",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x04, .cmask = 4, .msr_values = {0}},
      R"(This event increments by 1 for every cycle where there was no execute for this thread.)",
      R"(Total execution stalls.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x05, .cmask = 5, .msr_values = {0}},
      R"(Execution stalls due to L2 cache misses.)",
      R"(Number of loads missed L2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_L2_MISS",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x05, .cmask = 5, .msr_values = {0x00}},
      R"(Execution stalls while L2 cache miss load* is outstanding.)",
      R"(Execution stalls while L2 cache miss load* is outstanding.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.STALLS_LDM_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x06, .cmask = 6, .msr_values = {0}},
      R"(Execution stalls due to memory subsystem.)",
      R"(Execution stalls due to memory subsystem.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLE_ACTIVITY.CYCLES_L1D_PENDING",
      EventDef::Encoding{
          .code = 0xA3, .umask = 0x08, .cmask = 8, .msr_values = {0}},
      R"(Cycles with pending L1 cache miss loads.)",
      R"(Cycles with pending L1 cache miss loads. Set AnyThread to count per core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(Cycles Uops delivered by the LSD, but didn't come from the decoder)",
      R"(Cycles Uops delivered by the LSD, but didn't come from the decoder.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.CYCLES_4_UOPS",
      EventDef::Encoding{
          .code = 0xA8, .umask = 0x01, .cmask = 4, .msr_values = {0x00}},
      R"(Cycles 4 Uops delivered by the LSD, but didn't come from the decoder)",
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
      R"(Decode Stream Buffer (DSB)-to-MITE switches)",
      R"(Number of DSB to MITE switches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB2MITE_SWITCHES.PENALTY_CYCLES",
      EventDef::Encoding{
          .code = 0xAB, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles)",
      R"(Cycles DSB to MITE switches caused delay.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DSB_FILL.EXCEED_DSB_LINES",
      EventDef::Encoding{
          .code = 0xAC, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Cycles when Decode Stream Buffer (DSB) fill encounter more than 3 Decode Stream Buffer (DSB) lines)",
      R"(DSB Fill encountered > 3 DSB lines.)",
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
      R"(Counts the number of ITLB flushes, includes 4k/2M/4M pages.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests sent to uncore)",
      R"(Demand data read requests sent to uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.DEMAND_CODE_RD",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Cacheable and noncachaeble code read requests)",
      R"(Demand code read requests sent to uncore.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.THREAD",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of uops to be executed per-thread each cycle.)",
      R"(Counts total number of uops to be executed per-thread each cycle. Set Cmask = 1, INV =1 to count stall cycles.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_CYCLES_GE_1",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x02, .cmask = 1, .msr_values = {0x00}},
      R"(Cycles at least 1 micro-op is executed from any thread on physical core)",
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
      R"(Cycles at least 2 micro-op is executed from any thread on physical core)",
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
      R"(Cycles at least 3 micro-op is executed from any thread on physical core)",
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
      R"(Cycles at least 4 micro-op is executed from any thread on physical core)",
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
      R"(Cycles with no micro-ops executed from any thread on physical core)",
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
      R"(Cases when offcore requests buffer cannot take more entries for core)",
      R"(Cases when offcore requests buffer cannot take more entries for core.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TLB_FLUSH.DTLB_THREAD",
      EventDef::Encoding{
          .code = 0xBD, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(DTLB flush attempts of the thread-specific entries)",
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
      R"(STLB flush attempts)",
      R"(Count number of STLB flush attempts.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PAGE_WALKS.LLC_MISS",
      EventDef::Encoding{
          .code = 0xBE, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Number of any page walk that had a miss in LLC.)",
      R"(Number of any page walk that had a miss in LLC.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OTHER_ASSISTS.AVX_STORE",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Number of GSSE memory assist for stores. GSSE microcode assist is being invoked whenever the hardware is unable to properly handle GSSE-256b operations.)",
      R"(Number of assists associated with 256-bit AVX store operations.)",
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
      "OTHER_ASSISTS.ANY_WB_ASSIST",
      EventDef::Encoding{
          .code = 0xC1, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Number of times any microcode assist is invoked by HW upon uop writeback.)",
      R"(Number of times any microcode assist is invoked by HW upon uop writeback.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired uops.)",
      R"(Retired uops.)",
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
          .any = true,
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
      R"(Retirement slots used.)",
      R"(Retirement slots used.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Counts the number of machine clears due to memory order conflicts.)",
      R"(Counts the number of machine clears due to memory order conflicts.)",
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
      R"(Number of self-modifying-code machine clears detected.)",
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
      R"(Counts the number of executed AVX masked load operations that refer to an illegal address range with the mask bits set to 0.)",
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
      R"(Branch instructions at retirement.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Conditional branch instructions retired.)",
      R"(Conditional branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect near call instructions retired.)",
      R"(Direct and indirect near call instructions retired.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL_R3",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Direct and indirect macro near call instructions retired (captured in ring 3).)",
      R"(Direct and indirect macro near call instructions retired (captured in ring 3).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_RETURN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Return instructions retired.)",
      R"(Return instructions retired.)",
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
      R"(Counts the number of not taken branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Taken branch instructions retired.)",
      R"(Taken branch instructions retired.)",
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
      R"(Number of far branches retired.)",
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
      R"(Mispredicted branch instructions at retirement.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES_PEBS",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted macro branch instructions retired.)",
      R"(Mispredicted macro branch instructions retired.)",
      400009,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(number of near branch instructions retired that were mispredicted and taken.)",
      R"(number of near branch instructions retired that were mispredicted and taken.)",
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
      R"(Number of X87 FP assists due to output values.)",
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
      R"(Number of X87 FP assists due to input values.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

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
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_4",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x4}},
      R"(Loads with latency value being above 4)",
      R"(Loads with latency value being above 4.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_8",
      EventDef::Encoding{
          .code = 0xCD, .umask = 0x01, .cmask = 0, .msr_values = {0x8}},
      R"(Loads with latency value being above 8)",
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
      R"(Loads with latency value being above 16)",
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
      R"(Loads with latency value being above 32)",
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
      R"(Loads with latency value being above 64)",
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
      R"(Loads with latency value being above 128)",
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
      R"(Loads with latency value being above 256)",
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
      R"(Loads with latency value being above 512)",
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
      R"(Sample stores and collect precise store operation via PEBS record. PMC3 only.)",
      R"(Sample stores and collect precise store operation via PEBS record. PMC3 only.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x11, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that miss the STLB. (Precise Event))",
      R"(Retired load uops that miss the STLB. (Precise Event))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STLB_MISS_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x12, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that miss the STLB. (Precise Event))",
      R"(Retired store uops that miss the STLB. (Precise Event))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x21, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with locked access. (Precise Event))",
      R"(Retired load uops with locked access. (Precise Event))",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops that split across a cacheline boundary. (Precise Event))",
      R"(Retired load uops that split across a cacheline boundary. (Precise Event))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x42, .cmask = 0, .msr_values = {0}},
      R"(Retired store uops that split across a cacheline boundary. (Precise Event))",
      R"(Retired store uops that split across a cacheline boundary. (Precise Event))",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x81, .cmask = 0, .msr_values = {0}},
      R"(All retired load uops. (Precise Event))",
      R"(All retired load uops. (Precise Event))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x82, .cmask = 0, .msr_values = {0}},
      R"(All retired store uops. (Precise Event))",
      R"(All retired store uops. (Precise Event))",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L1 cache hits as data sources.)",
      R"(Retired load uops with L1 cache hits as data sources.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L2 cache hits as data sources.)",
      R"(Retired load uops with L2 cache hits as data sources.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.LLC_HIT",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were data hits in LLC without snoops required.)",
      R"(Retired load uops which data sources were data hits in LLC without snoops required.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources following L1 data-cache miss.)",
      R"(Retired load uops which data sources following L1 data-cache miss.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops with L2 cache misses as data sources.)",
      R"(Retired load uops with L2 cache misses as data sources.)",
      50021,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.LLC_MISS",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Miss in last-level (L3) cache. Excludes Unknown data-source.)",
      R"(Miss in last-level (L3) cache. Excludes Unknown data-source.)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.HIT_LFB",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.)",
      R"(Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_MISS",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache.)",
      R"(Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_HIT",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x02, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were LLC and cross-core snoop hits in on-pkg core cache.)",
      R"(Retired load uops which data sources were LLC and cross-core snoop hits in on-pkg core cache.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_HITM",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x04, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were HitM responses from shared LLC.)",
      R"(Retired load uops which data sources were HitM responses from shared LLC.)",
      20011,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_NONE",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources were hits in LLC without snoops required.)",
      R"(Retired load uops which data sources were hits in LLC without snoops required.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_LLC_MISS_RETIRED.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xD3, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Retired load uops which data sources missed LLC but serviced from local dram.)",
      R"(Retired load uops whose data source was local memory (cross-socket snoop not needed or missed).)",
      100007,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ANY",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x1F, .cmask = 0, .msr_values = {0}},
      R"(Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.)",
      R"(Number of front end re-steers due to BPU misprediction.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.DEMAND_DATA_RD",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Demand Data Read requests that access L2 cache)",
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
      R"(RFO requests that access L2 cache)",
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
      R"(L2 cache accesses when fetching instructions)",
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
      R"(L2 or LLC HW prefetches that access L2 cache)",
      R"(Any MLC or LLC HW prefetch accessing L2, including rejects.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANS.L1D_WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L1D writebacks that access L2 cache)",
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
      R"(L2 fill requests that access L2 cache)",
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
      R"(L2 writebacks that access L2 cache)",
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
      R"(Transactions accessing L2 pipe)",
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
      R"(L2 cache lines in I state filling L2)",
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
      R"(L2 cache lines in S state filling L2)",
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
      R"(L2 cache lines in E state filling L2)",
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
      R"(L2 cache lines filling L2)",
      R"(L2 cache lines filling L2.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DEMAND_CLEAN",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x01, .cmask = 0, .msr_values = {0}},
      R"(Clean L2 cache lines evicted by demand)",
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
      R"(Dirty L2 cache lines evicted by demand)",
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
      R"(Clean L2 cache lines evicted by L2 prefetch)",
      R"(Clean L2 cache lines evicted by the MLC prefetcher.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.PF_DIRTY",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x08, .cmask = 0, .msr_values = {0}},
      R"(Dirty L2 cache lines evicted by L2 prefetch)",
      R"(Dirty L2 cache lines evicted by the MLC prefetcher.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DIRTY_ALL",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x0A, .cmask = 0, .msr_values = {0}},
      R"(Dirty L2 cache lines filling the L2)",
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
      R"(Split locks in SQ)",
      R"(Split locks in SQ)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3f803c0244}},
      R"(Counts all demand & prefetch code reads that hit in the LLC)",
      R"(Counts all demand & prefetch code reads that hit in the LLC)",
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
      R"(Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
      R"(Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
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
      R"(Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram)",
      R"(Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram)",
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
      R"(Counts all demand & prefetch data reads that hit in the LLC)",
      R"(Counts all demand & prefetch data reads that hit in the LLC)",
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
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
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
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
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
      R"(Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
      R"(Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
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
      R"(Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram)",
      R"(Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram)",
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
      R"(Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram)",
      R"(Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram)",
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
      R"(Counts all demand & prefetch RFOs that hit in the LLC)",
      R"(Counts all demand & prefetch RFOs that hit in the LLC)",
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
      R"(Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
      R"(Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
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
      R"(Counts all writebacks from the core to the LLC)",
      R"(Counts all writebacks from the core to the LLC)",
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
      R"(Counts all demand code reads that hit in the LLC)",
      R"(Counts all demand code reads that hit in the LLC)",
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
      R"(Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
      R"(Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
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
      R"(Counts demand code reads that miss the LLC and the data returned from dram)",
      R"(Counts demand code reads that miss the LLC and the data returned from dram)",
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
      R"(Counts all demand data reads that hit in the LLC)",
      R"(Counts all demand data reads that hit in the LLC)",
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
      R"(Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
      R"(Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded)",
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
      R"(Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
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
      R"(Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
      R"(Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
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
      R"(Counts demand data reads that miss the LLC and the data returned from dram)",
      R"(Counts demand data reads that miss the LLC and the data returned from dram)",
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
      R"(Counts all demand data writes (RFOs) that hit in the LLC)",
      R"(Counts all demand data writes (RFOs) that hit in the LLC)",
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
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
      R"(Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded)",
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
      R"(Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
      R"(Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores)",
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
      R"(Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches)",
      R"(Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches)",
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
      R"(Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address )",
      R"(Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address )",
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
      R"(Counts non-temporal stores)",
      R"(Counts non-temporal stores)",
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
      R"(Counts all demand data reads )",
      R"(Counts all demand data reads )",
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
      R"(Counts all demand rfo's )",
      R"(Counts all demand rfo's )",
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
      R"(Counts all demand code reads)",
      R"(Counts all demand code reads)",
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
      R"(Counts all demand & prefetch data reads)",
      R"(Counts all demand & prefetch data reads)",
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
      R"(Counts all demand & prefetch prefetch RFOs )",
      R"(Counts all demand & prefetch prefetch RFOs )",
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
      R"(Counts all data/code/rfo references (demand & prefetch) )",
      R"(Counts all data/code/rfo references (demand & prefetch) )",
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
      R"(Counts LLC replacements)",
      R"(Counts LLC replacements)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace ivybridge_core
} // namespace facebook::hbt::perf_event::generated
