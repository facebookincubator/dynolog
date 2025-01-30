// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/AmdEvents.h"
#ifdef FACEBOOK
#include "hbt/src/perf_event/fb/AmdEvents.h"
#endif

namespace facebook::hbt::perf_event {

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

namespace turin {
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
  // When multiple families/models are in the fleet, add a switch stmt similar
  // to addEvents in json_events/generated/intel/JsonEvents.h
  switch (cpu_info.cpu_arch) {
    case CpuArch::MILAN:
    case CpuArch::BERGAMO:
    case CpuArch::GENOA:
    case CpuArch::TURIN:
      milan::addEvents(pmu_manager);
#ifdef FACEBOOK
      milan::addEventsFb(pmu_manager);
#endif
      break;
    default:
      HBT_LOG_ERROR()
          << "Attempting to add AMD events, but model is not supported";
      break;
  }
}

} // namespace facebook::hbt::perf_event
