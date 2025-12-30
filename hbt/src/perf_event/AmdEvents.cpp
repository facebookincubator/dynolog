// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/AmdEvents.h"
#ifdef FACEBOOK
#include "hbt/src/perf_event/fb/AmdEvents.h"
#endif

namespace facebook::hbt::perf_event {

void addCoreEvents(PmuDeviceManager& pmu_manager) {
  // L1 Instruction Cache
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l1_icache_fill_misses",
          EventDef::Encoding{.code = amd_msr::kL1ICacheFillMisses.val},
          "L1 instruction cache fill misses.",
          "L1 instruction cache fill misses from L2 cache."),
      std::vector<EventId>({"l1-icache-fill-misses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l1_icache_instr_fetches",
          EventDef::Encoding{.code = amd_msr::kL1ICacheInstrFetches.val},
          "L1 instruction cache instruction fetches.",
          "L1 instruction cache instruction fetches."),
      std::vector<EventId>({"l1-icache-instr-fetches"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l1_icache_instr_fetches_misses",
          EventDef::Encoding{.code = amd_msr::kL1ICacheInstrFetchesMisses.val},
          "L1 instruction cache instruction fetch misses.",
          "L1 instruction cache instruction fetch misses."),
      std::vector<EventId>({"l1-icache-instr-fetches-misses"}));

  // L1 Data Cache
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l1_dcache_misses",
          EventDef::Encoding{.code = amd_msr::kL1DCacheMisses.val},
          "L1 data cache misses.",
          "L1 data cache misses."),
      std::vector<EventId>({"l1-dcache-misses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l1_dcache_accesses",
          EventDef::Encoding{.code = amd_msr::kL1DCacheAcceses.val},
          "L1 data cache accesses.",
          "L1 data cache accesses."),
      std::vector<EventId>({"l1-dcache-accesses"}));

  // L2 Cache
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_icache_fill_misses",
          EventDef::Encoding{.code = amd_msr::kL2ICacheFillMisses.val},
          "L2 instruction cache fill misses.",
          "L2 instruction cache fill misses."),
      std::vector<EventId>({"l2-icache-fill-misses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_dcache_accesses",
          EventDef::Encoding{.code = amd_msr::kL2DCacheAccesses.val},
          "L2 data cache accesses.",
          "L2 data cache accesses excluding L2 prefetcher."),
      std::vector<EventId>({"l2-dcache-accesses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_dcache_misses",
          EventDef::Encoding{.code = amd_msr::kL2DCacheMisses.val},
          "L2 data cache misses.",
          "L2 data cache misses excluding L2 prefetcher."),
      std::vector<EventId>({"l2-dcache-misses"}));

  // L2 with Prefetcher
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_accesses",
          EventDef::Encoding{.code = amd_msr::kL2Accesses.val},
          "L2 cache accesses.",
          "L2 cache accesses including L2 prefetcher."),
      std::vector<EventId>({"l2-accesses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_misses",
          EventDef::Encoding{.code = amd_msr::kL2Misses.val},
          "L2 cache misses.",
          "L2 cache misses including L2 prefetcher."),
      std::vector<EventId>({"l2-misses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_prefetcher_hits_in_l2",
          EventDef::Encoding{.code = amd_msr::kL2PrefetcherHitsInL2.val},
          "L2 prefetcher hits in L2.",
          "L2 prefetcher requests that hit in L2 cache."),
      std::vector<EventId>({"l2-prefetcher-hits-in-l2"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_prefetcher_hits_in_l3",
          EventDef::Encoding{.code = amd_msr::kL2PrefetcherHitsInL3.val},
          "L2 prefetcher hits in L3.",
          "L2 prefetcher requests that hit in L3 cache."),
      std::vector<EventId>({"l2-prefetcher-hits-in-l3"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_prefetcher_misses_in_l3",
          EventDef::Encoding{.code = amd_msr::kL2PrefetcherMissesInL3.val},
          "L2 prefetcher misses in L3.",
          "L2 prefetcher requests that miss in L3 cache."),
      std::vector<EventId>({"l2-prefetcher-misses-in-l3"}));

  // FLOPS
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "retired_x87_flops",
          EventDef::Encoding{.code = amd_msr::kRetiredX87Flops.val},
          "Retired x87 floating-point operations.",
          "Retired x87 floating-point operations."),
      std::vector<EventId>({"retired-x87-flops"}));

  // Branches
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "retired_branch_instructions",
          EventDef::Encoding{.code = amd_msr::kRetiredBranchInstructions.val},
          "Retired branch instructions.",
          "Retired branch instructions."),
      std::vector<EventId>({"retired-branch-instructions"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "retired_branch_mispred",
          EventDef::Encoding{.code = amd_msr::kRetiredBranchMispred.val},
          "Retired branch instructions mispredicted.",
          "Retired branch instructions mispredicted."),
      std::vector<EventId>({"retired-branch-mispred"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "retired_far_control_transfer",
          EventDef::Encoding{.code = amd_msr::kRetiredFarControlTransfer.val},
          "Retired far control transfers.",
          "Retired far control transfers."),
      std::vector<EventId>({"retired-far-control-transfer"}));

  // TLB
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "dtlb_misses",
          EventDef::Encoding{.code = amd_msr::kDTlbMisses.val},
          "Data TLB misses.",
          "Data TLB misses."),
      std::vector<EventId>({"dtlb-misses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "dtlb_accesses",
          EventDef::Encoding{.code = amd_msr::kDTlbAccesses.val},
          "Data TLB accesses.",
          "Data TLB accesses."),
      std::vector<EventId>({"dtlb-accesses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "itlb_misses",
          EventDef::Encoding{.code = amd_msr::kITlbMisses.val},
          "Instruction TLB misses.",
          "Instruction TLB misses."),
      std::vector<EventId>({"itlb-misses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "itlb_accesses",
          EventDef::Encoding{.code = amd_msr::kITlbAccesses.val},
          "Instruction TLB accesses.",
          "Instruction TLB accesses."),
      std::vector<EventId>({"itlb-accesses"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "load_plus_store_dtlb_misses",
          EventDef::Encoding{.code = amd_msr::kLoadPlusStoreDtlbMisses.val},
          "Load and store data TLB misses.",
          "Load and store data TLB misses."),
      std::vector<EventId>({"load-plus-store-dtlb-misses"}));

  // Stall Cycles
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "stalled_cycles_back_pressure",
          EventDef::Encoding{.code = amd_msr::kStalledCyclesBackPressure.val},
          "Stalled cycles due to back pressure.",
          "Stalled cycles due to back pressure."),
      std::vector<EventId>({"stalled-cycles-back-pressure"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "stalled_cycles_idq_empty",
          EventDef::Encoding{.code = amd_msr::kStalledCyclesIdqEmpty.val},
          "Stalled cycles due to IDQ empty.",
          "Stalled cycles due to instruction decode queue empty."),
      std::vector<EventId>({"stalled-cycles-idq-empty"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "stalled_cycles_any",
          EventDef::Encoding{.code = amd_msr::kStalledCyclesAny.val},
          "Stalled cycles due to any reason.",
          "Stalled cycles due to any reason."),
      std::vector<EventId>({"stalled-cycles-any"}));

  // IC Cache Fill
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ic_cache_fill_l2",
          EventDef::Encoding{.code = amd_msr::kIcCacheFillL2.val},
          "Instruction cache fills from L2.",
          "Instruction cache fills from L2 cache."),
      std::vector<EventId>({"ic-cache-fill-l2"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ic_cache_fill_sys",
          EventDef::Encoding{.code = amd_msr::kIcCacheFillSys.val},
          "Instruction cache fills from system.",
          "Instruction cache fills from system memory."),
      std::vector<EventId>({"ic-cache-fill-sys"}));

  // MAB
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_alloc_mab_count",
          EventDef::Encoding{.code = amd_msr::kLsAllocMabCount.val},
          "Load-store MAB allocations.",
          "Load-store miss address buffer allocations."),
      std::vector<EventId>({"ls-alloc-mab-count"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_mab_alloc_pipes",
          EventDef::Encoding{.code = amd_msr::kLsMabAllocPipes.val},
          "Load-store MAB allocated to pipes.",
          "Load-store miss address buffer allocated to pipes."),
      std::vector<EventId>({"ls-mab-alloc-pipes"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ic_mab_request",
          EventDef::Encoding{.code = amd_msr::kIcMabRequest.val},
          "Instruction cache MAB requests.",
          "Instruction cache miss address buffer requests."),
      std::vector<EventId>({"ic-mab-request"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ic_mab_requests_prefetch",
          EventDef::Encoding{.code = amd_msr::kIcMabRequestsPrefetch.val},
          "Instruction cache MAB prefetch requests.",
          "Instruction cache miss address buffer prefetch requests."),
      std::vector<EventId>({"ic-mab-requests-prefetch"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ic_mab_requests_demand",
          EventDef::Encoding{.code = amd_msr::kIcMabRequestsDemad.val},
          "Instruction cache MAB demand requests.",
          "Instruction cache miss address buffer demand requests."),
      std::vector<EventId>({"ic-mab-requests-demand"}));

  // Uops
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "retired_uops",
          EventDef::Encoding{.code = amd_msr::kRetiredUOps.val},
          "Retired micro-ops.",
          "Retired micro-operations."),
      std::vector<EventId>({"retired-uops"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "de_uops_dispatched_op_cache",
          EventDef::Encoding{.code = amd_msr::kDeUopsDispatchedOpCache.val},
          "Micro-ops dispatched from op cache.",
          "Micro-operations dispatched from op cache."),
      std::vector<EventId>({"de-uops-dispatched-op-cache"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "de_uops_dispatched_decoder",
          EventDef::Encoding{.code = amd_msr::kDeUopsDispatchedDecoder.val},
          "Micro-ops dispatched from decoder.",
          "Micro-operations dispatched from decoder."),
      std::vector<EventId>({"de-uops-dispatched-decoder"}));

  // Dispatch Slots (Zen4 stall events)
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "dispatch_slots",
          EventDef::Encoding{.code = amd_msr::kDispatchSlots.val},
          "Dispatch slots.",
          "Dispatch slots available (same as unhalted cycles)."),
      std::vector<EventId>({"dispatch-slots"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "frontend_bound_stalls",
          EventDef::Encoding{.code = amd_msr::kFrontendBoundStalls.val},
          "Frontend bound stalls.",
          "Stall cycles due to frontend bound conditions (Zen4)."),
      std::vector<EventId>({"frontend-bound-stalls"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "backend_bound_stalls",
          EventDef::Encoding{.code = amd_msr::kBackendBoundStalls.val},
          "Backend bound stalls.",
          "Stall cycles due to backend bound conditions (Zen4)."),
      std::vector<EventId>({"backend-bound-stalls"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "smt_contention_stalls",
          EventDef::Encoding{.code = amd_msr::kSMTContentionStalls.val},
          "SMT contention stalls.",
          "Stall cycles due to SMT contention (Zen4)."),
      std::vector<EventId>({"smt-contention-stalls"}));
}

namespace milan {

void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "cpu_cycles",
          EventDef::Encoding{.code = amd_msr::kUnhaltedCycles.val},
          "CPU cycles.",
          "Actual CPU cycles. Depends on frequency scaling, turbo mode and other effects."),
      std::vector<EventId>({"cpu-cycles", "cycles"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "instructions",
          EventDef::Encoding{.code = amd_msr::kRetiredInstructions.val},
          "Instructions retired.",
          "Instructions executed. Does not count speculative execution."),
      std::vector<EventId>({"retired_instructions", "retired-instructions"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_cache_misses_no_prefetcher",
          EventDef::Encoding{.code = amd_msr::kL2Misses.val},
          "L2 cache misses excluding L2 prefetcher",
          "L2 Data and Instruction cache misses excluding L2 prefetcher."),
      std::vector<EventId>({"l2-cache-misses-no-prefetcher"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l1_l2_pf_hit_in_l3",
          EventDef::Encoding{.code = amd_msr::kL1AndL2PrefetcherHitsInL3.val},
          "L1 and L2 prefetch hits in L3",
          "L1 and L2 prefetcher requests that hit in L3."),
      std::vector<EventId>({"l2-pf-hit-in-l3"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l1_l2_pf_miss_in_l3",
          EventDef::Encoding{.code = amd_msr::kL1AndL2PrefetcherMissesInL3.val},
          "L1 and L2 prefetch misses in L3",
          "L1 and L2 prefetcher requests that miss in L3"),
      std::vector<EventId>({"l2-pf-miss-in-l3"}));

  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l3_cache_misses",
          EventDef::Encoding{.code = amd_msr::kL3CacheMisses.val},
          "L3 Cache misses",
          "L3 Cache misses"),
      std::vector<EventId>({"l3-cache-misses"}));

  // FLOPs events for AMD Zen3/Zen4
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "zen3/4::fp_ret_x87_fp_ops.all",
          EventDef::Encoding{.code = amd_msr::kRetiredX87Flops.val},
          "Retired x87 floating-point ops of all types.",
          "The number of all x87 floating-point Ops that have retired."),
      std::vector<EventId>({"zen3/4-ret-x87-fp-ops-all"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "zen3::fp_ret_sse_avx_ops.all",
          EventDef::Encoding{.code = amd_msr::kZen3RetiredSseAvxFlops.val},
          "Retired SSE and AVX floating-point ops of all types.",
          "The number of all SSE/AVX floating-point Ops that have retired."),
      std::vector<EventId>({"zen3-ret-sse-avx-fp-ops-all"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "zen4::fp_ret_sse_avx_ops.all",
          EventDef::Encoding{.code = amd_msr::kZen4RetiredSseAvxFlops.val},
          "Retired SSE and AVX floating-point ops of all types.",
          "The number of all SSE/AVX floating-point Ops that have retired."),
      std::vector<EventId>({"zen4-ret-sse-avx-fp-ops-all"}));

  // Branches
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ex_ret_brn_tkn",
          EventDef::Encoding{.code = amd_msr::kRetiredBranchTaken.val},
          "Retired taken branch instructions.",
          "Retired taken branch instructions (all types of architectural control flow changes, including exceptions and interrupts)."),
      std::vector<EventId>({"ex-ret-brn-tkn"}));

  // Sampled memory latency for AMD Zen4. The latency is measured from the L3
  // cache to near/far data sources (DRAM, CXL, CCX cache) and back in
  // nano-seconds.
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_dram_latency.near",
          EventDef::Encoding{.code = amd_msr::kL3Zen4XiSampledLatDRamNear.val},
          "Sampled latency of requests that target the same NUMA node and return from DRAM.",
          "Dram_Near. Read-write. Sampled latency of requests that target the same NUMA node and return from DRAM."),
      std::vector<EventId>({"zen4-l3-xi-sampled-dram-latency-near"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_dram_latency_requests.near",
          EventDef::Encoding{
              .code = amd_msr::kL3Zen4XiSampledLatReqDRamNear.val},
          "L3 cache fill requests sourced from the same NUMA node and return from DRAM.",
          "Dram_Near. Read-write. The number of sampled L3 cache fill requests from the same NUMA node and return from DRAM."),
      std::vector<EventId>({"zen4-l3-xi-sampled-dram-latency-requests-near"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_dram_latency.far",
          EventDef::Encoding{.code = amd_msr::kL3Zen4XiSampledLatDRamFar.val},
          "Sampled latency of requests that target another NUMA node and return from DRAM.",
          "Dram_Near. Read-write. Sampled latency of requests that target another NUMA node and return from DRAM."),
      std::vector<EventId>({"zen4-l3-xi-sampled-dram-latency-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_dram_latency_requests.far",
          EventDef::Encoding{
              .code = amd_msr::kL3Zen4XiSampledLatReqDRamFar.val},
          "L3 cache fill requests sourced from another NUMA node and return from DRAM.",
          "Dram_Near. Read-write. The number of sampled L3 cache fill requests from another NUMA node and return from DRAM."),
      std::vector<EventId>({"zen4-l3-xi-sampled-dram-latency-requests-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_ccx_latency.near",
          EventDef::Encoding{.code = amd_msr::kL3Zen4XiSampledLatCCXNear.val},
          "Sampled latency of requests that target the same NUMA node and return from another CCX's cache.",
          "Dram_Near. Read-write. Sampled latency of requests that target the same NUMA node and return from another CCX's cache."),
      std::vector<EventId>({"zen4-l3-xi-sampled-ccx-latency-near"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_ccx_latency_requests.near",
          EventDef::Encoding{
              .code = amd_msr::kL3Zen4XiSampledLatReqCCXNear.val},
          "L3 cache fill requests sourced from the same NUMA node and return from another CCX's cache.",
          "Dram_Near. Read-write. The number of sampled L3 cache fill requests from the same NUMA node and return from another CCX's cache."),
      std::vector<EventId>({"zen4-l3-xi-sampled-ccx-latency-requests-near"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_ccx_latency.far",
          EventDef::Encoding{.code = amd_msr::kL3Zen4XiSampledLatCCXFar.val},
          "Sampled latency of requests that target another NUMA node and return from another CCX's cache.",
          "Dram_Near. Read-write. Sampled latency of requests that target another NUMA node and return from another CCX's cache."),
      std::vector<EventId>({"zen4-l3-xi-sampled-ccx-latency-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_l3,
          "zen4::l3_xi_sampled_ccx_latency_requests.far",
          EventDef::Encoding{.code = amd_msr::kL3Zen4XiSampledLatReqCCXFar.val},
          "L3 cache fill requests sourced from another NUMA node and return from another CCX's cache.",
          "Dram_Near. Read-write. The number of sampled L3 cache fill requests from another NUMA node and return from another CCX's cache."),
      std::vector<EventId>({"zen4-l3-xi-sampled-ccx-latency-requests-far"}));
}

} // namespace milan

namespace bergamo {

void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_dmnd_fills_from_sys.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsDmndFillsFromSysDramIoFar.val},
          "Demand data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Demand data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-dmnd-fills-from-sys.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_any_fills_from_sys.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsAnyFillsFromSysDramIoFar.val},
          "Any data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Any data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-any-fills-from-sys.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_sw_pf_dc_fills.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsSwPfDcFillsDramIoFar.val},
          "Software prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Software prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-sw-pf-dc-fills.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_hw_pf_dc_fills.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsHwPfDcFillsDramIoFar.val},
          "Hardware prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Hardware prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-hw-pf-dc-fills.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_fill_l3_resp",
          EventDef::Encoding{.code = amd_msr::kL2FillL3Responses.val},
          "L2 cache fill L3 responses.",
          "L2 cache fill L3 responses. Count all L3 responses to fill requests."),
      std::vector<EventId>({"l2-fill-l3-resp"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_fill_l3_miss_resp",
          EventDef::Encoding{.code = amd_msr::kL2FillL3MissResponses.val},
          "L2 Fill responses except from L3 or different L2 in the same CCX.",
          "L2 Fill responses except from L3 or different L2 in the same CCX."),
      std::vector<EventId>({"l2-fill-l3-miss-resp"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_fill_dram_resp",
          EventDef::Encoding{.code = amd_msr::kL2FillDramResponses.val},
          "L2 cache fill from all DRAM or MMIO responses.",
          "L2 cache fill responses returned from either DRAM or MMIO from the same or different NUMA node."),
      std::vector<EventId>({"l2-fill-dram-resp"}));
}

} // namespace bergamo

namespace turin {

void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_dmnd_fills_from_sys.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsDmndFillsFromSysDramIoFar.val},
          "Demand data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Demand data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-dmnd-fills-from-sys.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_any_fills_from_sys.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsAnyFillsFromSysDramIoFar.val},
          "Any data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Any data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-any-fills-from-sys.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_sw_pf_dc_fills.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsSwPfDcFillsDramIoFar.val},
          "Software prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Software prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-sw-pf-dc-fills.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "ls_hw_pf_dc_fills.dram_io_far",
          EventDef::Encoding{.code = amd_msr::kLsHwPfDcFillsDramIoFar.val},
          "Hardware prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket).",
          "Hardware prefetch data cache fills from either DRAM or MMIO in a different NUMA node (same or different socket)."),
      std::vector<EventId>({"ls-hw-pf-dc-fills.dram-io-far"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_fill_l3_resp",
          EventDef::Encoding{.code = amd_msr::kL2FillL3Responses.val},
          "L2 cache fill L3 responses.",
          "L2 cache fill L3 responses. Count all L3 responses to fill requests."),
      std::vector<EventId>({"l2-fill-l3-resp"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_fill_l3_miss_resp",
          EventDef::Encoding{.code = amd_msr::kL2FillL3MissResponses.val},
          "L2 Fill responses except from L3 or different L2 in the same CCX.",
          "L2 Fill responses except from L3 or different L2 in the same CCX."),
      std::vector<EventId>({"l2-fill-l3-miss-resp"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::cpu,
          "l2_fill_dram_resp",
          EventDef::Encoding{.code = amd_msr::kL2FillDramResponses.val},
          "L2 cache fill from all DRAM or MMIO responses.",
          "L2 cache fill requests that target the same or another NUMA node and return from either DRAM or MMIO from the same or different NUMA node."),
      std::vector<EventId>({"l2-fill-dram-resp"}));
}

void addZen5UmcEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_umc,
          "zen5::umc_read_write_cyc",
          EventDef::Encoding{.code = amd_msr::kUmcZen5ReadWriteCyc.val},
          "Zen5 UMC read/write cycles",
          "Number of cycles the DRAM (reads and writes) data bus channel is utilized."),
      std::vector<EventId>({"zen5-umc-read-write-cycles"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_umc,
          "zen5::umc_write_cyc",
          EventDef::Encoding{.code = amd_msr::kUmcZen5WriteCyc.val},
          "Zen5 UMC write cycles",
          "Number of cycles the DRAM write data bus channel is utilized."),
      std::vector<EventId>({"zen5-umc-write-cycles"}));
  pmu_manager.addEvent(
      std::make_shared<EventDef>(
          PmuType::amd_umc,
          "zen5::umc_cyc",
          EventDef::Encoding{.code = amd_msr::kUmcZen5Cyc.val},
          "Zen5 UMC cycles",
          "Total number of DRAM bus channel cycles."),
      std::vector<EventId>({"zen5-umc-write-cycles"}));
}

} // namespace turin

void addAmdEvents(const CpuInfo& cpu_info, PmuDeviceManager& pmu_manager) {
  // Add AMD core L1 - common across all architectures
  addCoreEvents(pmu_manager);
  // When multiple families/models are in the fleet, add a switch stmt similar
  // to addEvents in json_events/generated/intel/JsonEvents.h
  switch (cpu_info.cpu_arch) {
    case CpuArch::MILAN:
      milan::addEvents(pmu_manager);
#ifdef FACEBOOK
      milan::addEventsFb(pmu_manager);
#endif
      break;
    case CpuArch::BERGAMO:
    case CpuArch::GENOA:
      milan::addEvents(pmu_manager);
#ifdef FACEBOOK
      milan::addEventsFb(pmu_manager);
#endif
      bergamo::addEvents(pmu_manager);
      break;
    case CpuArch::TURIN:
      milan::addEvents(pmu_manager);
#ifdef FACEBOOK
      milan::addEventsFb(pmu_manager);
#endif
      turin::addEvents(pmu_manager);
      break;
    default:
      HBT_LOG_ERROR()
          << "Attempting to add AMD events, but model is not supported";
      break;
  }
}

} // namespace facebook::hbt::perf_event
