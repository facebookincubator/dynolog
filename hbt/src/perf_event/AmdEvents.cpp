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
}
} // namespace milan

void addAmdEvents(const CpuInfo& cpu_info, PmuDeviceManager& pmu_manager) {
  // When multiple families/models are in the fleet, add a switch stmt similar
  // to addEvents in json_events/generated/intel/JsonEvents.h
  switch (cpu_info.cpu_arch) {
    case CpuArch::MILAN:
    case CpuArch::BERGAMO:
    case CpuArch::GENOA:
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
