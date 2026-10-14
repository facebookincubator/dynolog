// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto generated for hbt. Do not manually edit.
// @generated

#include <array>
#include <cstdint>
#include "hbt/src/perf_event/StaticEventDef.h"
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace ivybridge_core {
namespace {

/*
  Events from ivybridge_core.json (318 events).

  Supported SKUs:
      - Arch: x86, Model: IVB id: 58
*/
constexpr std::array<StaticEventDef, 29> kAllowlistedEvents{{
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.ALL_BRANCHES",
        .encoding =
            {
                .code = 0xC4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All (macro) branch instructions retired.",
        .full_desc = "Branch instructions at retirement.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.NEAR_TAKEN",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Taken branch instructions retired.",
        .full_desc = "Taken branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_RETIRED.ALL_BRANCHES",
        .encoding =
            {
                .code = 0xC5ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All mispredicted macro branch instructions retired.",
        .full_desc = "Mispredicted branch instructions at retirement.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.REF_TSC",
        .encoding =
            {
                .code = 0x0ULL,
                .umask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Reference cycles when the core is not in halt state.",
        .full_desc = "Reference cycles when the core is not in halt state.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.THREAD",
        .encoding =
            {
                .code = 0x0ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Core cycles when the thread is not in halt state.",
        .full_desc = "Core cycles when the thread is not in halt state.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.THREAD_ANY",
        .encoding =
            {
                .code = 0x0ULL,
                .umask = 0x2ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Core cycles when at least one thread on the physical core is not in halt state",
        .full_desc =
            "Core cycles when at least one thread on the physical core is not in halt state.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.THREAD_P",
        .encoding =
            {
                .code = 0x3CULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Thread cycles when thread is not in halt state",
        .full_desc =
            "Counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.THREAD_P_ANY",
        .encoding =
            {
                .code = 0x3CULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Core cycles when at least one thread on the physical core is not in halt state",
        .full_desc =
            "Core cycles when at least one thread on the physical core is not in halt state.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.STALLS_L1D_MISS",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0xCULL,
                .cmask = 0xCULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Execution stalls while L1 cache miss demand load is outstanding.",
        .full_desc =
            "Execution stalls while L1 cache miss demand load is outstanding.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.STALLS_L2_MISS",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x5ULL,
                .cmask = 0x5ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Execution stalls while L2 cache miss load* is outstanding.",
        .full_desc =
            "Execution stalls while L2 cache miss load* is outstanding.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.STALLS_MEM_ANY",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x6ULL,
                .cmask = 0x6ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Execution stalls while memory subsystem has an outstanding load.",
        .full_desc =
            "Execution stalls while memory subsystem has an outstanding load.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.STALLS_TOTAL",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x4ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Total execution stalls.",
        .full_desc = "Total execution stalls.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.WALK_COMPLETED",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x82ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes of any page size.",
        .full_desc =
            "Misses in all TLB levels that caused page walk completed of any size by demand loads.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.WALK_COMPLETED",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Store misses in all DTLB levels that cause completed page walks",
        .full_desc =
            "Miss in all TLB levels causes a page walk that completes of any page size (4K/2M/4M/1G).",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ICACHE.MISSES",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Instruction cache, streaming buffer and victim cache misses",
        .full_desc =
            "Number of Instruction Cache, Streaming Buffer and Victim Cache Misses. Includes UC accesses.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ_UOPS_NOT_DELIVERED.CORE",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops not delivered to Resource Allocation Table (RAT) per thread when backend of the machine is not stalled",
        .full_desc =
            "Count issue pipeline slots where no uop was delivered from the front end to the back end when there is no back-end stall.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INT_MISC.RECOVERY_CYCLES",
        .encoding =
            {
                .code = 0xDULL,
                .umask = 0x3ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.)",
        .full_desc =
            "Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.)",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INT_MISC.RECOVERY_CYCLES_ANY",
        .encoding =
            {
                .code = 0xDULL,
                .umask = 0x3ULL,
                .any = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke).",
        .full_desc =
            "Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke).",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.WALK_COMPLETED",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Misses in all ITLB levels that cause completed page walks",
        .full_desc =
            "Misses in all ITLB levels that cause completed page walks.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D.REPLACEMENT",
        .encoding =
            {
                .code = 0x51ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D data line replacements",
        .full_desc =
            "Counts the number of lines brought into the L1 data cache.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_IN.ALL",
        .encoding =
            {
                .code = 0xF1ULL,
                .umask = 0x7ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 cache lines filling L2",
        .full_desc = "L2 cache lines filling L2.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.ALL_CODE_RD",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x30ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 code requests",
        .full_desc = "Counts all L2 code requests.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LD_BLOCKS.STORE_FORWARD",
        .encoding =
            {
                .code = 0x3ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cases when loads get true Block-on-Store blocking code preventing store forwarding",
        .full_desc =
            "Loads blocked by overlapping with store buffer that cannot be forwarded.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LONGEST_LAT_CACHE.MISS",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x41ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Core-originated cacheable demand requests missed LLC",
        .full_desc =
            "This event counts each cache miss condition for references to the last level cache.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore",
        .full_desc =
            "Offcore outstanding cacheable data read transactions in SQ to uncore. Set Cmask=1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x8ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore",
        .full_desc =
            "Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.ANY",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops that Resource Allocation Table (RAT) issues to Reservation Station (RS)",
        .full_desc =
            "Increments each cycle the # of Uops issued by the RAT to RS. Set Cmask = 1, Inv = 1, Any= 1to count stalled cycles of this core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.ALL",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired uops.",
        .full_desc = "Retired uops.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.RETIRE_SLOTS",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retirement slots used.",
        .full_desc = "Retirement slots used.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 289> kFullOnlyEvents{{
    {
        .pmu_type = PmuType::cpu,
        .id = "ARITH.FPU_DIV",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x4ULL,
                .edge = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Divide operations executed",
        .full_desc = "Divide operations executed.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ARITH.FPU_DIV_ACTIVE",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when divider is busy executing divide operations",
        .full_desc =
            "Cycles that the divider is active, includes INT and FP. Set 'edge =1, cmask=1' to count the number of divides.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BACLEARS.ANY",
        .encoding =
            {
                .code = 0xE6ULL,
                .umask = 0x1FULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.",
        .full_desc = "Number of front end re-steers due to BPU misprediction.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.ALL_BRANCHES",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0xFFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Speculative and retired  branches",
        .full_desc =
            "Counts all near executed branches (not necessarily retired).",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.ALL_CONDITIONAL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0xC1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Speculative and retired macro-conditional branches",
        .full_desc = "Speculative and retired macro-conditional branches.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.ALL_DIRECT_JMP",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0xC2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Speculative and retired macro-unconditional branches excluding calls and indirects",
        .full_desc =
            "Speculative and retired macro-unconditional branches excluding calls and indirects.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.ALL_DIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0xD0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Speculative and retired direct near calls",
        .full_desc = "Speculative and retired direct near calls.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.ALL_INDIRECT_JUMP_NON_CALL_RET",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0xC4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Speculative and retired indirect branches excluding calls and returns",
        .full_desc =
            "Speculative and retired indirect branches excluding calls and returns.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.ALL_INDIRECT_NEAR_RETURN",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0xC8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Speculative and retired indirect return branches.",
        .full_desc = "Speculative and retired indirect return branches.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.NONTAKEN_CONDITIONAL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x41ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Not taken macro-conditional branches",
        .full_desc = "Not taken macro-conditional branches.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.TAKEN_CONDITIONAL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x81ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired macro-conditional branches",
        .full_desc =
            "Taken speculative and retired macro-conditional branches.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.TAKEN_DIRECT_JUMP",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x82ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired macro-conditional branch instructions excluding calls and indirects",
        .full_desc =
            "Taken speculative and retired macro-conditional branch instructions excluding calls and indirects.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.TAKEN_DIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x90ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Taken speculative and retired direct near calls",
        .full_desc = "Taken speculative and retired direct near calls.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.TAKEN_INDIRECT_JUMP_NON_CALL_RET",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x84ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired indirect branches excluding calls and returns",
        .full_desc =
            "Taken speculative and retired indirect branches excluding calls and returns.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.TAKEN_INDIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0xA0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Taken speculative and retired indirect calls",
        .full_desc = "Taken speculative and retired indirect calls.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.TAKEN_INDIRECT_NEAR_RETURN",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x88ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired indirect branches with return mnemonic",
        .full_desc =
            "Taken speculative and retired indirect branches with return mnemonic.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.ALL_BRANCHES_PEBS",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "All (macro) branch instructions retired.",
        .full_desc = "All (macro) branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.CONDITIONAL",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Conditional branch instructions retired.",
        .full_desc = "Conditional branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.FAR_BRANCH",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Far branch instructions retired.",
        .full_desc = "Number of far branches retired.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.NEAR_CALL",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Direct and indirect near call instructions retired.",
        .full_desc = "Direct and indirect near call instructions retired.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.NEAR_CALL_R3",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Direct and indirect macro near call instructions retired (captured in ring 3).",
        .full_desc =
            "Direct and indirect macro near call instructions retired (captured in ring 3).",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.NEAR_RETURN",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Return instructions retired.",
        .full_desc = "Return instructions retired.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.NOT_TAKEN",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Not taken branch instructions retired.",
        .full_desc =
            "Counts the number of not taken branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.ALL_BRANCHES",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0xFFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Speculative and retired mispredicted macro conditional branches",
        .full_desc =
            "Counts all near executed branches (not necessarily retired).",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.ALL_CONDITIONAL",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0xC1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Speculative and retired mispredicted macro conditional branches",
        .full_desc =
            "Speculative and retired mispredicted macro conditional branches.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.ALL_INDIRECT_JUMP_NON_CALL_RET",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0xC4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Mispredicted indirect branches excluding calls and returns",
        .full_desc =
            "Mispredicted indirect branches excluding calls and returns.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.INDIRECT",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0xE4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Speculative mispredicted indirect branches",
        .full_desc =
            "Counts speculatively miss-predicted indirect branches at execution time. Counts for indirect near CALL or JMP instructions (RET excluded).",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.NONTAKEN_CONDITIONAL",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x41ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Not taken speculative and retired mispredicted macro conditional branches",
        .full_desc =
            "Not taken speculative and retired mispredicted macro conditional branches.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.TAKEN_CONDITIONAL",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x81ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired mispredicted macro conditional branches",
        .full_desc =
            "Taken speculative and retired mispredicted macro conditional branches.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.TAKEN_INDIRECT_JUMP_NON_CALL_RET",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x84ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired mispredicted indirect branches excluding calls and returns",
        .full_desc =
            "Taken speculative and retired mispredicted indirect branches excluding calls and returns.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.TAKEN_INDIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0xA0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired mispredicted indirect calls",
        .full_desc =
            "Taken speculative and retired mispredicted indirect calls.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.TAKEN_RETURN_NEAR",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x88ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Taken speculative and retired mispredicted indirect branches with return mnemonic",
        .full_desc =
            "Taken speculative and retired mispredicted indirect branches with return mnemonic.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_RETIRED.ALL_BRANCHES_PEBS",
        .encoding =
            {
                .code = 0xC5ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Mispredicted macro branch instructions retired.",
        .full_desc = "Mispredicted macro branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_RETIRED.CONDITIONAL",
        .encoding =
            {
                .code = 0xC5ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Mispredicted conditional branch instructions retired.",
        .full_desc = "Mispredicted conditional branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_RETIRED.NEAR_TAKEN",
        .encoding =
            {
                .code = 0xC5ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "number of near branch instructions retired that were mispredicted and taken.",
        .full_desc =
            "number of near branch instructions retired that were mispredicted and taken.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPL_CYCLES.RING0",
        .encoding =
            {
                .code = 0x5CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Unhalted core cycles when the thread is in ring 0",
        .full_desc = "Unhalted core cycles when the thread is in ring 0.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPL_CYCLES.RING0_TRANS",
        .encoding =
            {
                .code = 0x5CULL,
                .umask = 0x1ULL,
                .edge = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of intervals between processor halts while thread is in ring 0",
        .full_desc =
            "Number of intervals between processor halts while thread is in ring 0.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPL_CYCLES.RING123",
        .encoding =
            {
                .code = 0x5CULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Unhalted core cycles when thread is in rings 1, 2, or 3",
        .full_desc = "Unhalted core cycles when the thread is not in ring 0.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_THREAD_UNHALTED.ONE_THREAD_ACTIVE",
        .encoding =
            {
                .code = 0x3CULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Count XClk pulses when this thread is unhalted and the other is halted.",
        .full_desc =
            "Count XClk pulses when this thread is unhalted and the other is halted.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_THREAD_UNHALTED.REF_XCLK",
        .encoding =
            {
                .code = 0x3CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Reference cycles when the thread is unhalted (counts at 100 MHz rate)",
        .full_desc =
            "Increments at the frequency of XCLK (100 MHz) when not halted.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_THREAD_UNHALTED.REF_XCLK_ANY",
        .encoding =
            {
                .code = 0x3CULL,
                .umask = 0x1ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate)",
        .full_desc =
            "Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate)",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.ONE_THREAD_ACTIVE",
        .encoding =
            {
                .code = 0x3CULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Count XClk pulses when this thread is unhalted and the other thread is halted.",
        .full_desc =
            "Count XClk pulses when this thread is unhalted and the other thread is halted.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.REF_XCLK",
        .encoding =
            {
                .code = 0x3CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Reference cycles when the thread is unhalted (counts at 100 MHz rate)",
        .full_desc =
            "Reference cycles when the thread is unhalted. (counts at 100 MHz rate)",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.REF_XCLK_ANY",
        .encoding =
            {
                .code = 0x3CULL,
                .umask = 0x1ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate)",
        .full_desc =
            "Reference cycles when the at least one thread on the physical core is unhalted. (counts at 100 MHz rate)",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.CYCLES_L1D_MISS",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x8ULL,
                .cmask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles while L1 cache miss demand load is outstanding.",
        .full_desc = "Cycles while L1 cache miss demand load is outstanding.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.CYCLES_L1D_PENDING",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x8ULL,
                .cmask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with pending L1 cache miss loads.",
        .full_desc =
            "Cycles with pending L1 cache miss loads. Set AnyThread to count per core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.CYCLES_L2_MISS",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles while L2 cache miss load* is outstanding.",
        .full_desc = "Cycles while L2 cache miss load* is outstanding.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.CYCLES_L2_PENDING",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with pending L2 cache miss loads.",
        .full_desc =
            "Cycles with pending L2 miss loads. Set AnyThread to count per core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.CYCLES_LDM_PENDING",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x2ULL,
                .cmask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with pending memory loads.",
        .full_desc =
            "Cycles with pending memory loads. Set AnyThread to count per core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.CYCLES_MEM_ANY",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x2ULL,
                .cmask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles while memory subsystem has an outstanding load.",
        .full_desc = "Cycles while memory subsystem has an outstanding load.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.CYCLES_NO_EXECUTE",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x4ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "This event increments by 1 for every cycle where there was no execute for this thread.",
        .full_desc = "Total execution stalls.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.STALLS_L1D_PENDING",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0xCULL,
                .cmask = 0xCULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Execution stalls due to L1 data cache misses",
        .full_desc =
            "Execution stalls due to L1 data cache miss loads. Set Cmask=0CH.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.STALLS_L2_PENDING",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x5ULL,
                .cmask = 0x5ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Execution stalls due to L2 cache misses.",
        .full_desc = "Number of loads missed L2.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CYCLE_ACTIVITY.STALLS_LDM_PENDING",
        .encoding =
            {
                .code = 0xA3ULL,
                .umask = 0x6ULL,
                .cmask = 0x6ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Execution stalls due to memory subsystem.",
        .full_desc = "Execution stalls due to memory subsystem.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DSB2MITE_SWITCHES.COUNT",
        .encoding =
            {
                .code = 0xABULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Decode Stream Buffer (DSB)-to-MITE switches",
        .full_desc = "Number of DSB to MITE switches.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DSB2MITE_SWITCHES.PENALTY_CYCLES",
        .encoding =
            {
                .code = 0xABULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles",
        .full_desc = "Cycles DSB to MITE switches caused delay.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DSB_FILL.EXCEED_DSB_LINES",
        .encoding =
            {
                .code = 0xACULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when Decode Stream Buffer (DSB) fill encounter more than 3 Decode Stream Buffer (DSB) lines",
        .full_desc = "DSB Fill encountered > 3 DSB lines.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.LARGE_PAGE_WALK_COMPLETED",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x88ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Page walk for a large page completed for Demand load.",
        .full_desc = "Page walk for a large page completed for Demand load.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.MISS_CAUSES_A_WALK",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x81ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Demand load Miss in all translation lookaside buffer (TLB) levels causes an page walk of any page size.",
        .full_desc =
            "Misses in all TLB levels that cause a page walk of any page size from demand loads.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.STLB_HIT",
        .encoding =
            {
                .code = 0x5FULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Load operations that miss the first DTLB level but hit the second and do not cause page walks",
        .full_desc =
            "Counts load operations that missed 1st level DTLB but hit the 2nd level.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.WALK_DURATION",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x84ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Demand load cycles page miss handler (PMH) is busy with this walk.",
        .full_desc = "Cycle PMH is busy with a walk due to demand loads.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.MISS_CAUSES_A_WALK",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Store misses in all DTLB levels that cause page walks",
        .full_desc =
            "Miss in all TLB levels causes a page walk of any page size (4K/2M/4M/1G).",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.STLB_HIT",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Store operations that miss the first TLB level but hit the second and do not cause page walks",
        .full_desc =
            "Store operations that miss the first TLB level but hit the second and do not cause page walks.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.WALK_DURATION",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when PMH is busy with page walks",
        .full_desc = "Cycles PMH is busy with this walk.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "EPT.WALK_CYCLES",
        .encoding =
            {
                .code = 0x4FULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycle count for an Extended Page table walk.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.",
        .full_desc =
            "Cycle count for an Extended Page table walk.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.ANY",
        .encoding =
            {
                .code = 0xCAULL,
                .umask = 0x1EULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with any input/output SSE or FP assist",
        .full_desc = "Cycles with any input/output SSE* or FP assists.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.SIMD_INPUT",
        .encoding =
            {
                .code = 0xCAULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of SIMD FP assists due to input values",
        .full_desc = "Number of SIMD FP assists due to input values.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.SIMD_OUTPUT",
        .encoding =
            {
                .code = 0xCAULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of SIMD FP assists due to Output values",
        .full_desc = "Number of SIMD FP assists due to output values.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.X87_INPUT",
        .encoding =
            {
                .code = 0xCAULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of X87 assists due to input value.",
        .full_desc = "Number of X87 FP assists due to input values.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.X87_OUTPUT",
        .encoding =
            {
                .code = 0xCAULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of X87 assists due to output value.",
        .full_desc = "Number of X87 FP assists due to output values.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_PACKED_DOUBLE",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SSE* or AVX-128 FP Computational packed double-precision uops issued this cycle",
        .full_desc =
            "Number of SSE* or AVX-128 FP Computational packed double-precision uops issued this cycle.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_PACKED_SINGLE",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SSE* or AVX-128 FP Computational packed single-precision uops issued this cycle",
        .full_desc =
            "Number of SSE* or AVX-128 FP Computational packed single-precision uops issued this cycle.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_SCALAR_DOUBLE",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SSE* or AVX-128 FP Computational scalar double-precision uops issued this cycle",
        .full_desc =
            "Counts number of SSE* or AVX-128 double precision FP scalar uops executed.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_SCALAR_SINGLE",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SSE* or AVX-128 FP Computational scalar single-precision uops issued this cycle",
        .full_desc =
            "Number of SSE* or AVX-128 FP Computational scalar single-precision uops issued this cycle.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.X87",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of FP Computational Uops Executed this cycle. The number of FADD, FSUB, FCOM, FMULs, integer MULs and IMULs, FDIVs, FPREMs, FSQRTS, integer DIVs, and IDIVs. This event does not distinguish an FADD used in the middle of a transcendental flow from a s",
        .full_desc = "Counts number of X87 uops executed.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ICACHE.HIT",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches",
        .full_desc =
            "Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ICACHE.IFETCH_STALL",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles where a code-fetch stalled due to L1 instruction-cache miss or an iTLB miss",
        .full_desc =
            "Cycles where a code-fetch stalled due to L1 instruction-cache miss or an iTLB miss.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.ALL_DSB_CYCLES_4_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x18ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles Decode Stream Buffer (DSB) is delivering 4 Uops",
        .full_desc = "Counts cycles DSB is delivered four uops. Set Cmask = 4.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.ALL_DSB_CYCLES_ANY_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x18ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles Decode Stream Buffer (DSB) is delivering any Uop",
        .full_desc =
            "Counts cycles DSB is delivered at least one uops. Set Cmask = 1.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.ALL_MITE_CYCLES_4_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x24ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles MITE is delivering 4 Uops",
        .full_desc =
            "Counts cycles MITE is delivered four uops. Set Cmask = 4.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.ALL_MITE_CYCLES_ANY_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x24ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles MITE is delivering any Uop",
        .full_desc =
            "Counts cycles MITE is delivered at least one uops. Set Cmask = 1.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.DSB_CYCLES",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x8ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from Decode Stream Buffer (DSB) path",
        .full_desc =
            "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from Decode Stream Buffer (DSB) path.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.DSB_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path",
        .full_desc =
            "Increment each cycle. # of uops delivered to IDQ from DSB path. Set Cmask = 1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.EMPTY",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Instruction Decode Queue (IDQ) empty cycles",
        .full_desc = "Counts cycles the IDQ is empty.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MITE_ALL_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x3CULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops delivered to Instruction Decode Queue (IDQ) from MITE path",
        .full_desc = "Number of uops delivered to IDQ from any path.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MITE_CYCLES",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x4ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from MITE path",
        .full_desc =
            "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from MITE path.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MITE_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops delivered to Instruction Decode Queue (IDQ) from MITE path",
        .full_desc =
            "Increment each cycle # of uops delivered to IDQ from MITE path. Set Cmask = 1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MS_CYCLES",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x30ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy",
        .full_desc =
            "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MS_DSB_CYCLES",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x10ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy",
        .full_desc =
            "Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MS_DSB_OCCUR",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x10ULL,
                .edge = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequencer (MS) is busy",
        .full_desc =
            "Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequencer (MS) is busy.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MS_DSB_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy",
        .full_desc =
            "Increment each cycle # of uops delivered to IDQ when MS_busy by DSB. Set Cmask = 1 to count cycles. Add Edge=1 to count # of delivery.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MS_MITE_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy",
        .full_desc =
            "Increment each cycle # of uops delivered to IDQ when MS_busy by MITE. Set Cmask = 1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MS_SWITCHES",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x30ULL,
                .edge = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer",
        .full_desc =
            "Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ.MS_UOPS",
        .encoding =
            {
                .code = 0x79ULL,
                .umask = 0x30ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy",
        .full_desc =
            "Increment each cycle # of uops delivered to IDQ from MS by either DSB or MITE. Set Cmask = 1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x1ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles per thread when 4 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.",
        .full_desc =
            "Cycles per thread when 4 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ_UOPS_NOT_DELIVERED.CYCLES_FE_WAS_OK",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts cycles FE delivered 4 uops or Resource Allocation Table (RAT) was stalling FE.",
        .full_desc =
            "Counts cycles FE delivered 4 uops or Resource Allocation Table (RAT) was stalling FE.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_1_UOP_DELIV.CORE",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x1ULL,
                .cmask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles per thread when 3 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.",
        .full_desc =
            "Cycles per thread when 3 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_2_UOP_DELIV.CORE",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x1ULL,
                .cmask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles with less than 2 uops delivered by the front end.",
        .full_desc = "Cycles with less than 2 uops delivered by the front end.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IDQ_UOPS_NOT_DELIVERED.CYCLES_LE_3_UOP_DELIV.CORE",
        .encoding =
            {
                .code = 0x9CULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles with less than 3 uops delivered by the front end.",
        .full_desc = "Cycles with less than 3 uops delivered by the front end.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ILD_STALL.IQ_FULL",
        .encoding =
            {
                .code = 0x87ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall cycles because IQ is full",
        .full_desc = "Stall cycles due to IQ is full.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ILD_STALL.LCP",
        .encoding =
            {
                .code = 0x87ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Stalls caused by changing prefix length of the instruction.",
        .full_desc =
            "Stalls caused by changing prefix length of the instruction.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.ANY",
        .encoding =
            {
                .code = 0x0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Instructions retired from execution.",
        .full_desc = "Instructions retired from execution.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.ANY_P",
        .encoding =
            {
                .code = 0xC0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of instructions retired. General Counter   - architectural event",
        .full_desc = "Number of instructions at retirement.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.PREC_DIST",
        .encoding =
            {
                .code = 0xC0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Precise instruction retired event with HW to reduce effect of PEBS shadow in IP distribution",
        .full_desc =
            "Precise instruction retired event with HW to reduce effect of PEBS shadow in IP distribution.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INT_MISC.RECOVERY_STALLS_COUNT",
        .encoding =
            {
                .code = 0xDULL,
                .umask = 0x3ULL,
                .edge = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.)",
        .full_desc =
            "Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc.)",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB.ITLB_FLUSH",
        .encoding =
            {
                .code = 0xAEULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Flushing of the Instruction TLB (ITLB) pages, includes 4k/2M/4M pages.",
        .full_desc =
            "Counts the number of ITLB flushes, includes 4k/2M/4M pages.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.LARGE_PAGE_WALK_COMPLETED",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Completed page walks in ITLB due to STLB load misses for large pages",
        .full_desc =
            "Completed page walks in ITLB due to STLB load misses for large pages.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.MISS_CAUSES_A_WALK",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Misses at all ITLB levels that cause page walks",
        .full_desc = "Misses in all ITLB levels that cause page walks.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.STLB_HIT",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Operations that miss the first ITLB level but hit the second and do not cause any page walks",
        .full_desc = "Number of cache load STLB hits. No page walk.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.WALK_DURATION",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when PMH is busy with page walks",
        .full_desc = "Cycle PMH is busy with a walk.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_PEND_MISS.FB_FULL",
        .encoding =
            {
                .code = 0x48ULL,
                .umask = 0x2ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles a demand request was blocked due to Fill Buffers unavailability",
        .full_desc =
            "Cycles a demand request was blocked due to Fill Buffers unavailability.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_PEND_MISS.PENDING",
        .encoding =
            {
                .code = 0x48ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D miss outstanding duration in cycles",
        .full_desc =
            "Increments the number of outstanding L1D misses every cycle. Set Cmask = 1 and Edge =1 to count occurrences.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_PEND_MISS.PENDING_CYCLES",
        .encoding =
            {
                .code = 0x48ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with L1D load Misses outstanding.",
        .full_desc = "Cycles with L1D load Misses outstanding.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_PEND_MISS.PENDING_CYCLES_ANY",
        .encoding =
            {
                .code = 0x48ULL,
                .umask = 0x1ULL,
                .any = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles with L1D load Misses outstanding from any thread on physical core",
        .full_desc =
            "Cycles with L1D load Misses outstanding from any thread on physical core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_L1D_WB_RQSTS.ALL",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Not rejected writebacks from L1D to L2 cache lines in any state.",
        .full_desc =
            "Not rejected writebacks from L1D to L2 cache lines in any state.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_L1D_WB_RQSTS.HIT_E",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Not rejected writebacks from L1D to L2 cache lines in E state",
        .full_desc =
            "Not rejected writebacks from L1D to L2 cache lines in E state.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_L1D_WB_RQSTS.HIT_M",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Not rejected writebacks from L1D to L2 cache lines in M state",
        .full_desc =
            "Not rejected writebacks from L1D to L2 cache lines in M state.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_L1D_WB_RQSTS.MISS",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Count the number of modified Lines evicted from L1 and missed L2. (Non-rejected WBs from the DCU.)",
        .full_desc = "Not rejected writebacks that missed LLC.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_IN.E",
        .encoding =
            {
                .code = 0xF1ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 cache lines in E state filling L2",
        .full_desc = "L2 cache lines in E state filling L2.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_IN.I",
        .encoding =
            {
                .code = 0xF1ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 cache lines in I state filling L2",
        .full_desc = "L2 cache lines in I state filling L2.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_IN.S",
        .encoding =
            {
                .code = 0xF1ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 cache lines in S state filling L2",
        .full_desc = "L2 cache lines in S state filling L2.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.DEMAND_CLEAN",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Clean L2 cache lines evicted by demand",
        .full_desc = "Clean L2 cache lines evicted by demand.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.DEMAND_DIRTY",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Dirty L2 cache lines evicted by demand",
        .full_desc = "Dirty L2 cache lines evicted by demand.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.DIRTY_ALL",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0xAULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Dirty L2 cache lines filling the L2",
        .full_desc = "Dirty L2 cache lines filling the L2.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.PF_CLEAN",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Clean L2 cache lines evicted by L2 prefetch",
        .full_desc = "Clean L2 cache lines evicted by the MLC prefetcher.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.PF_DIRTY",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Dirty L2 cache lines evicted by L2 prefetch",
        .full_desc = "Dirty L2 cache lines evicted by the MLC prefetcher.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.ALL_DEMAND_DATA_RD",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Demand Data Read requests",
        .full_desc =
            "Counts any demand and L1 HW prefetch data load requests to L2.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.ALL_PF",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0xC0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Requests from L2 hardware prefetchers",
        .full_desc = "Counts all L2 HW prefetcher requests.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.ALL_RFO",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0xCULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "RFO requests to L2 cache",
        .full_desc = "Counts all L2 store RFO requests.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.CODE_RD_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 cache hits when fetching instructions, code reads.",
        .full_desc = "Number of instruction fetches that hit the L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.CODE_RD_MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 cache misses when fetching instructions",
        .full_desc = "Number of instruction fetches that missed the L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.DEMAND_DATA_RD_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Demand Data Read requests that hit L2 cache",
        .full_desc = "Demand Data Read requests that hit L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.PF_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Requests from the L2 hardware prefetchers that hit L2 cache",
        .full_desc = "Counts all L2 HW prefetcher requests that hit L2.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.PF_MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Requests from the L2 hardware prefetchers that miss L2 cache",
        .full_desc = "Counts all L2 HW prefetcher requests that missed L2.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.RFO_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "RFO requests that hit L2 cache",
        .full_desc = "RFO requests that hit L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.RFO_MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "RFO requests that miss L2 cache",
        .full_desc =
            "Counts the number of store RFO requests that miss the L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_STORE_LOCK_RQSTS.ALL",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "RFOs that access cache lines in any state",
        .full_desc = "RFOs that access cache lines in any state.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_STORE_LOCK_RQSTS.HIT_M",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "RFOs that hit cache lines in M state",
        .full_desc = "RFOs that hit cache lines in M state.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_STORE_LOCK_RQSTS.MISS",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "RFOs that miss cache lines",
        .full_desc = "RFOs that miss cache lines.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.ALL_PF",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 or LLC HW prefetches that access L2 cache",
        .full_desc =
            "Any MLC or LLC HW prefetch accessing L2, including rejects.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.ALL_REQUESTS",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Transactions accessing L2 pipe",
        .full_desc = "Transactions accessing L2 pipe.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.CODE_RD",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 cache accesses when fetching instructions",
        .full_desc = "L2 cache accesses when fetching instructions.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.DEMAND_DATA_RD",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Demand Data Read requests that access L2 cache",
        .full_desc = "Demand Data Read requests that access L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.L1D_WB",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D writebacks that access L2 cache",
        .full_desc = "L1D writebacks that access L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.L2_FILL",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 fill requests that access L2 cache",
        .full_desc = "L2 fill requests that access L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.L2_WB",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 writebacks that access L2 cache",
        .full_desc = "L2 writebacks that access L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANS.RFO",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "RFO requests that access L2 cache",
        .full_desc = "RFO requests that access L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LD_BLOCKS.NO_SR",
        .encoding =
            {
                .code = 0x3ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "This event counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
        .full_desc =
            "The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LD_BLOCKS_PARTIAL.ADDRESS_ALIAS",
        .encoding =
            {
                .code = 0x7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "False dependencies in MOB due to partial compare on address",
        .full_desc =
            "False dependencies in MOB due to partial compare on address.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOAD_HIT_PRE.HW_PF",
        .encoding =
            {
                .code = 0x4CULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Not software-prefetch load dispatches that hit FB allocated for hardware prefetch",
        .full_desc =
            "Non-SW-prefetch load dispatches that hit fill buffer allocated for H/W prefetch.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOAD_HIT_PRE.SW_PF",
        .encoding =
            {
                .code = 0x4CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Not software-prefetch load dispatches that hit FB allocated for software prefetch",
        .full_desc =
            "Non-SW-prefetch load dispatches that hit fill buffer allocated for S/W prefetch.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOCK_CYCLES.CACHE_LOCK_DURATION",
        .encoding =
            {
                .code = 0x63ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when L1D is locked",
        .full_desc = "Cycles in which the L1D is locked.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOCK_CYCLES.SPLIT_LOCK_UC_LOCK_DURATION",
        .encoding =
            {
                .code = 0x63ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when L1 and L2 are locked due to UC or split lock",
        .full_desc =
            "Cycles in which the L1D and L2 are locked, due to a UC lock or split lock.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LONGEST_LAT_CACHE.REFERENCE",
        .encoding =
            {
                .code = 0x2EULL,
                .umask = 0x4FULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Core-originated cacheable demand requests that refer to LLC",
        .full_desc =
            "This event counts requests originating from the core that reference a cache line in the last level cache.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LSD.CYCLES_4_UOPS",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x1ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles 4 Uops delivered by the LSD, but didn't come from the decoder",
        .full_desc =
            "Cycles 4 Uops delivered by the LSD, but didn't come from the decoder.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LSD.CYCLES_ACTIVE",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles Uops delivered by the LSD, but didn't come from the decoder",
        .full_desc =
            "Cycles Uops delivered by the LSD, but didn't come from the decoder.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LSD.UOPS",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of Uops delivered by the LSD.",
        .full_desc = "Number of Uops delivered by the LSD.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACHINE_CLEARS.COUNT",
        .encoding =
            {
                .code = 0xC3ULL,
                .umask = 0x1ULL,
                .edge = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of machine clears (nukes) of any type.",
        .full_desc = "Number of machine clears (nukes) of any type.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACHINE_CLEARS.MASKMOV",
        .encoding =
            {
                .code = 0xC3ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "This event counts the number of executed Intel AVX masked load operations that refer to an illegal address range with the mask bits set to 0.",
        .full_desc =
            "Counts the number of executed AVX masked load operations that refer to an illegal address range with the mask bits set to 0.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACHINE_CLEARS.MEMORY_ORDERING",
        .encoding =
            {
                .code = 0xC3ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of machine clears due to memory order conflicts.",
        .full_desc =
            "Counts the number of machine clears due to memory order conflicts.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACHINE_CLEARS.SMC",
        .encoding =
            {
                .code = 0xC3ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Self-modifying code (SMC) detected.",
        .full_desc = "Number of self-modifying-code machine clears detected.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_HIT",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources were LLC and cross-core snoop hits in on-pkg core cache.",
        .full_desc =
            "Retired load uops which data sources were LLC and cross-core snoop hits in on-pkg core cache.",
        .default_sampling_period = 0x4E2BULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_HITM",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources were HitM responses from shared LLC.",
        .full_desc =
            "Retired load uops which data sources were HitM responses from shared LLC.",
        .default_sampling_period = 0x4E2BULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_MISS",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache.",
        .full_desc =
            "Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache.",
        .default_sampling_period = 0x4E2BULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_LLC_HIT_RETIRED.XSNP_NONE",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources were hits in LLC without snoops required.",
        .full_desc =
            "Retired load uops which data sources were hits in LLC without snoops required.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_LLC_MISS_RETIRED.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xD3ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Retired load uops which data sources missed LLC but serviced from local dram.",
        .full_desc =
            "Retired load uops whose data source was local memory (cross-socket snoop not needed or missed).",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.HIT_LFB",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.",
        .full_desc =
            "Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.L1_HIT",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired load uops with L1 cache hits as data sources.",
        .full_desc = "Retired load uops with L1 cache hits as data sources.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.L1_MISS",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources following L1 data-cache miss.",
        .full_desc =
            "Retired load uops which data sources following L1 data-cache miss.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.L2_HIT",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired load uops with L2 cache hits as data sources.",
        .full_desc = "Retired load uops with L2 cache hits as data sources.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.L2_MISS",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired load uops with L2 cache misses as data sources.",
        .full_desc = "Retired load uops with L2 cache misses as data sources.",
        .default_sampling_period = 0xC365ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.LLC_HIT",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired load uops which data sources were data hits in LLC without snoops required.",
        .full_desc =
            "Retired load uops which data sources were data hits in LLC without snoops required.",
        .default_sampling_period = 0xC365ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.LLC_MISS",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Miss in last-level (L3) cache. Excludes Unknown data-source.",
        .full_desc =
            "Miss in last-level (L3) cache. Excludes Unknown data-source.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_128",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 128",
        .full_desc = "Loads with latency value being above 128.",
        .default_sampling_period = 0x3F1ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_16",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 16",
        .full_desc = "Loads with latency value being above 16.",
        .default_sampling_period = 0x4E2BULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_256",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 256",
        .full_desc = "Loads with latency value being above 256.",
        .default_sampling_period = 0x1F7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_32",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 32",
        .full_desc = "Loads with latency value being above 32.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_4",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 4",
        .full_desc = "Loads with latency value being above 4.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_512",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 512",
        .full_desc = "Loads with latency value being above 512.",
        .default_sampling_period = 0x65ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_64",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x40ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 64",
        .full_desc = "Loads with latency value being above 64.",
        .default_sampling_period = 0x7D3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_8",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Loads with latency value being above 8",
        .full_desc = "Loads with latency value being above 8.",
        .default_sampling_period = 0xC365ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_TRANS_RETIRED.PRECISE_STORE",
        .encoding =
            {
                .code = 0xCDULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Sample stores and collect precise store operation via PEBS record. PMC3 only.",
        .full_desc =
            "Sample stores and collect precise store operation via PEBS record. PMC3 only.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_UOPS_RETIRED.ALL_LOADS",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x81ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "All retired load uops. (Precise Event)",
        .full_desc = "All retired load uops. (Precise Event)",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_UOPS_RETIRED.ALL_STORES",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x82ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "All retired store uops. (Precise Event)",
        .full_desc = "All retired store uops. (Precise Event)",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_UOPS_RETIRED.LOCK_LOADS",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x21ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired load uops with locked access. (Precise Event)",
        .full_desc = "Retired load uops with locked access. (Precise Event)",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_UOPS_RETIRED.SPLIT_LOADS",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x41ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops that split across a cacheline boundary. (Precise Event)",
        .full_desc =
            "Retired load uops that split across a cacheline boundary. (Precise Event)",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_UOPS_RETIRED.SPLIT_STORES",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x42ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired store uops that split across a cacheline boundary. (Precise Event)",
        .full_desc =
            "Retired store uops that split across a cacheline boundary. (Precise Event)",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_UOPS_RETIRED.STLB_MISS_LOADS",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x11ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired load uops that miss the STLB. (Precise Event)",
        .full_desc = "Retired load uops that miss the STLB. (Precise Event)",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_UOPS_RETIRED.STLB_MISS_STORES",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x12ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired store uops that miss the STLB. (Precise Event)",
        .full_desc = "Retired store uops that miss the STLB. (Precise Event)",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MISALIGN_MEM_REF.LOADS",
        .encoding =
            {
                .code = 0x5ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Speculative cache line split load uops dispatched to L1 cache",
        .full_desc =
            "Speculative cache-line split load uops dispatched to L1D.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MISALIGN_MEM_REF.STORES",
        .encoding =
            {
                .code = 0x5ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Speculative cache line split STA uops dispatched to L1 cache",
        .full_desc =
            "Speculative cache-line split Store-address uops dispatched to L1D.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MOVE_ELIMINATION.INT_ELIMINATED",
        .encoding =
            {
                .code = 0x58ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of integer Move Elimination candidate uops that were eliminated.",
        .full_desc =
            "Number of integer Move Elimination candidate uops that were eliminated.",
        .default_sampling_period = 0xF4243ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MOVE_ELIMINATION.INT_NOT_ELIMINATED",
        .encoding =
            {
                .code = 0x58ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of integer Move Elimination candidate uops that were not eliminated.",
        .full_desc =
            "Number of integer Move Elimination candidate uops that were not eliminated.",
        .default_sampling_period = 0xF4243ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MOVE_ELIMINATION.SIMD_ELIMINATED",
        .encoding =
            {
                .code = 0x58ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SIMD Move Elimination candidate uops that were eliminated.",
        .full_desc =
            "Number of SIMD Move Elimination candidate uops that were eliminated.",
        .default_sampling_period = 0xF4243ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MOVE_ELIMINATION.SIMD_NOT_ELIMINATED",
        .encoding =
            {
                .code = 0x58ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SIMD Move Elimination candidate uops that were not eliminated.",
        .full_desc =
            "Number of SIMD Move Elimination candidate uops that were not eliminated.",
        .default_sampling_period = 0xF4243ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS.ALL_DATA_RD",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Demand and prefetch data reads",
        .full_desc = "Data read requests sent to uncore (demand and prefetch).",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS.DEMAND_CODE_RD",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cacheable and noncacheable code read requests",
        .full_desc = "Demand code read requests sent to uncore.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS.DEMAND_DATA_RD",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Demand Data Read requests sent to uncore",
        .full_desc = "Demand data read requests sent to uncore.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS.DEMAND_RFO",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Demand RFO requests including regular RFOs, locks, ItoM",
        .full_desc =
            "Demand RFO read requests sent to uncore, including regular RFOs, locks, ItoM.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_BUFFER.SQ_FULL",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cases when offcore requests buffer cannot take more entries for core",
        .full_desc =
            "Cases when offcore requests buffer cannot take more entries for core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_CODE_RD",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x2ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle",
        .full_desc =
            "Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_DATA_RD",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore",
        .full_desc =
            "Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x4ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle",
        .full_desc =
            "Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_CODE_RD",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore outstanding code reads transactions in SuperQueue (SQ), queue to uncore, every cycle",
        .full_desc =
            "Offcore outstanding Demand Code Read transactions in SQ to uncore. Set Cmask=1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore outstanding Demand Data Read transactions in uncore queue.",
        .full_desc =
            "Offcore outstanding Demand Data Read transactions in SQ to uncore. Set Cmask=1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD_GE_6",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x1ULL,
                .cmask = 0x6ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue",
        .full_desc =
            "Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_RFO",
        .encoding =
            {
                .code = 0x60ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore outstanding RFO store transactions in SuperQueue (SQ), queue to uncore",
        .full_desc =
            "Offcore outstanding RFO store transactions in SQ to uncore. Set Cmask=1 to count cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0244ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all demand & prefetch code reads that hit in the LLC",
        .full_desc =
            "Counts all demand & prefetch code reads that hit in the LLC",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0244ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .full_desc =
            "Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_MISS.DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x300400244ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram",
        .full_desc =
            "Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x105B3ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all demand & prefetch data reads that hit in the LLC",
        .full_desc =
            "Counts all demand & prefetch data reads that hit in the LLC",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded",
        .full_desc =
            "Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded",
        .full_desc =
            "Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .full_desc =
            "Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_MISS.DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x300400091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram",
        .full_desc =
            "Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_READS.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x107F7ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all data/code/rfo references (demand & prefetch) ",
        .full_desc = "Counts all data/code/rfo references (demand & prefetch) ",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_READS.LLC_MISS.DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3004003F7ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram",
        .full_desc =
            "Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch prefetch RFOs ",
        .full_desc = "Counts all demand & prefetch prefetch RFOs ",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs that hit in the LLC",
        .full_desc = "Counts all demand & prefetch RFOs that hit in the LLC",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.NO_SNOOP_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .full_desc =
            "Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all writebacks from the core to the LLC",
        .full_desc = "Counts all writebacks from the core to the LLC",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DATA_IN_SOCKET.LLC_MISS.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6004001B3ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts LLC replacements",
        .full_desc = "Counts LLC replacements",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads that hit in the LLC",
        .full_desc = "Counts all demand code reads that hit in the LLC",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .full_desc =
            "Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_MISS.DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x300400004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand code reads that miss the LLC and the data returned from dram",
        .full_desc =
            "Counts demand code reads that miss the LLC and the data returned from dram",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data reads ",
        .full_desc = "Counts all demand data reads ",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data reads that hit in the LLC",
        .full_desc = "Counts all demand data reads that hit in the LLC",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded",
        .full_desc =
            "Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded",
        .full_desc =
            "Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .full_desc =
            "Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_MISS.DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x300400001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand data reads that miss the LLC and the data returned from dram",
        .full_desc =
            "Counts demand data reads that miss the LLC and the data returned from dram",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand rfo's ",
        .full_desc = "Counts all demand rfo's ",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all demand data writes (RFOs) that hit in the LLC",
        .full_desc = "Counts all demand data writes (RFOs) that hit in the LLC",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.HITM_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded",
        .full_desc =
            "Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.NO_SNOOP_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .full_desc =
            "Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x18000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches",
        .full_desc =
            "Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.SPLIT_LOCK_UC_LOCK.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10400ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address ",
        .full_desc =
            "Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address ",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.STREAMING_STORES.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10800ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts non-temporal stores",
        .full_desc = "Counts non-temporal stores",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OTHER_ASSISTS.ANY_WB_ASSIST",
        .encoding =
            {
                .code = 0xC1ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of times any microcode assist is invoked by HW upon uop writeback.",
        .full_desc =
            "Number of times any microcode assist is invoked by HW upon uop writeback.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OTHER_ASSISTS.AVX_STORE",
        .encoding =
            {
                .code = 0xC1ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of GSSE memory assist for stores. GSSE microcode assist is being invoked whenever the hardware is unable to properly handle GSSE-256b operations.",
        .full_desc =
            "Number of assists associated with 256-bit AVX store operations.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OTHER_ASSISTS.AVX_TO_SSE",
        .encoding =
            {
                .code = 0xC1ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of transitions from AVX-256 to legacy SSE when penalty applicable.",
        .full_desc =
            "Number of transitions from AVX-256 to legacy SSE when penalty applicable.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OTHER_ASSISTS.SSE_TO_AVX",
        .encoding =
            {
                .code = 0xC1ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of transitions from SSE to AVX-256 when penalty applicable.",
        .full_desc =
            "Number of transitions from SSE to AVX-256 when penalty applicable.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "PAGE_WALKS.LLC_MISS",
        .encoding =
            {
                .code = 0xBEULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of any page walk that had a miss in LLC.",
        .full_desc = "Number of any page walk that had a miss in LLC.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.ANY",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Resource-related stall cycles",
        .full_desc =
            "Cycles Allocation is stalled due to Resource Related reason.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.ROB",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles stalled due to re-order buffer full.",
        .full_desc = "Cycles stalled due to re-order buffer full.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.RS",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles stalled due to no eligible RS entry available.",
        .full_desc = "Cycles stalled due to no eligible RS entry available.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.SB",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles stalled due to no store buffers available. (not including draining form sync).",
        .full_desc =
            "Cycles stalled due to no store buffers available (not including draining form sync).",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ROB_MISC_EVENTS.LBR_INSERTS",
        .encoding =
            {
                .code = 0xCCULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Count cases of saving new LBR",
        .full_desc = "Count cases of saving new LBR records by hardware.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RS_EVENTS.EMPTY_CYCLES",
        .encoding =
            {
                .code = 0x5EULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when Reservation Station (RS) is empty for the thread",
        .full_desc = "Cycles the RS is empty for the thread.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RS_EVENTS.EMPTY_END",
        .encoding =
            {
                .code = 0x5EULL,
                .umask = 0x1ULL,
                .edge = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts end of periods where the Reservation Station (RS) was empty. Could be useful to precisely locate Frontend Latency Bound issues.",
        .full_desc =
            "Counts end of periods where the Reservation Station (RS) was empty. Could be useful to precisely locate Frontend Latency Bound issues.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_FP_256.PACKED_DOUBLE",
        .encoding =
            {
                .code = 0x11ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "number of AVX-256 Computational FP double precision uops issued this cycle",
        .full_desc =
            "Counts 256-bit packed double-precision floating-point instructions.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_FP_256.PACKED_SINGLE",
        .encoding =
            {
                .code = 0x11ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "number of GSSE-256 Computational FP single precision uops issued this cycle",
        .full_desc =
            "Counts 256-bit packed single-precision floating-point instructions.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SQ_MISC.SPLIT_LOCK",
        .encoding =
            {
                .code = 0xF4ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Split locks in SQ",
        .full_desc = "Split locks in SQ",
        .default_sampling_period = 0x186A3ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "TLB_FLUSH.DTLB_THREAD",
        .encoding =
            {
                .code = 0xBDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "DTLB flush attempts of the thread-specific entries",
        .full_desc = "DTLB flush attempts of the thread-specific entries.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "TLB_FLUSH.STLB_ANY",
        .encoding =
            {
                .code = 0xBDULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "STLB flush attempts",
        .full_desc = "Count number of STLB flush attempts.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_0",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per thread when uops are dispatched to port 0",
        .full_desc = "Cycles which a Uop is dispatched on port 0.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_0_CORE",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x1ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per core when uops are dispatched to port 0",
        .full_desc = "Cycles per core when uops are dispatched to port 0.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_1",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per thread when uops are dispatched to port 1",
        .full_desc = "Cycles which a Uop is dispatched on port 1.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_1_CORE",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x2ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per core when uops are dispatched to port 1",
        .full_desc = "Cycles per core when uops are dispatched to port 1.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_2",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0xCULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles per thread when load or STA uops are dispatched to port 2",
        .full_desc = "Cycles which a Uop is dispatched on port 2.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_2_CORE",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0xCULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Uops dispatched to port 2, loads and stores per core (speculative and retired).",
        .full_desc =
            "Uops dispatched to port 2, loads and stores per core (speculative and retired).",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_3",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x30ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles per thread when load or STA uops are dispatched to port 3",
        .full_desc = "Cycles which a Uop is dispatched on port 3.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_3_CORE",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x30ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles per core when load or STA uops are dispatched to port 3",
        .full_desc =
            "Cycles per core when load or STA uops are dispatched to port 3.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_4",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per thread when uops are dispatched to port 4",
        .full_desc = "Cycles which a Uop is dispatched on port 4.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_4_CORE",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x40ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per core when uops are dispatched to port 4",
        .full_desc = "Cycles per core when uops are dispatched to port 4.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_5",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per thread when uops are dispatched to port 5",
        .full_desc = "Cycles which a Uop is dispatched on port 5.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DISPATCHED_PORT.PORT_5_CORE",
        .encoding =
            {
                .code = 0xA1ULL,
                .umask = 0x80ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles per core when uops are dispatched to port 5",
        .full_desc = "Cycles per core when uops are dispatched to port 5.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of uops executed on the core.",
        .full_desc =
            "Counts total number of uops to be executed per-core each cycle.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_CYCLES_GE_1",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles at least 1 micro-op is executed from any thread on physical core",
        .full_desc =
            "Cycles at least 1 micro-op is executed from any thread on physical core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_CYCLES_GE_2",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
                .cmask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles at least 2 micro-op is executed from any thread on physical core",
        .full_desc =
            "Cycles at least 2 micro-op is executed from any thread on physical core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_CYCLES_GE_3",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
                .cmask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles at least 3 micro-op is executed from any thread on physical core",
        .full_desc =
            "Cycles at least 3 micro-op is executed from any thread on physical core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_CYCLES_GE_4",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles at least 4 micro-op is executed from any thread on physical core",
        .full_desc =
            "Cycles at least 4 micro-op is executed from any thread on physical core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_CYCLES_NONE",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
                .inv = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles with no micro-ops executed from any thread on physical core",
        .full_desc =
            "Cycles with no micro-ops executed from any thread on physical core.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CYCLES_GE_1_UOP_EXEC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles where at least 1 uop was executed per-thread",
        .full_desc = "Cycles where at least 1 uop was executed per-thread.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CYCLES_GE_2_UOPS_EXEC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
                .cmask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles where at least 2 uops were executed per-thread",
        .full_desc = "Cycles where at least 2 uops were executed per-thread.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CYCLES_GE_3_UOPS_EXEC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
                .cmask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles where at least 3 uops were executed per-thread",
        .full_desc = "Cycles where at least 3 uops were executed per-thread.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CYCLES_GE_4_UOPS_EXEC",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
                .cmask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles where at least 4 uops were executed per-thread",
        .full_desc = "Cycles where at least 4 uops were executed per-thread.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.STALL_CYCLES",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts number of cycles no uops were dispatched to be executed on this thread.",
        .full_desc =
            "Counts number of cycles no uops were dispatched to be executed on this thread.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.THREAD",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of uops to be executed per-thread each cycle.",
        .full_desc =
            "Counts total number of uops to be executed per-thread each cycle. Set Cmask = 1, INV =1 to count stall cycles.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.CORE_STALL_CYCLES",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x1ULL,
                .any = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads",
        .full_desc =
            "Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.FLAGS_MERGE",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Number of flags-merge uops being allocated.",
        .full_desc =
            "Number of flags-merge uops allocated. Such uops adds delay.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.SINGLE_MUL",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of Multiply packed/scalar single precision uops allocated",
        .full_desc =
            "Number of multiply packed/scalar single precision uops allocated.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.SLOW_LEA",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of slow LEA uops being allocated. A uop is generally considered SlowLea if it has 3 sources (e.g. 2 sources + immediate) regardless if as a result of LEA instruction or not.",
        .full_desc =
            "Number of slow LEA or similar uops allocated. Such uop has 3 sources (e.g. 2 sources + immediate) regardless if as a result of LEA instruction or not.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.STALL_CYCLES",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for the thread",
        .full_desc =
            "Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for the thread.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.CORE_STALL_CYCLES",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x1ULL,
                .any = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles without actually retired uops.",
        .full_desc = "Cycles without actually retired uops.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.STALL_CYCLES",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles without actually retired uops.",
        .full_desc = "Cycles without actually retired uops.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.TOTAL_CYCLES",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0xAULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles with less than 10 actually retired uops.",
        .full_desc = "Cycles with less than 10 actually retired uops.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "0",
    },
}};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

} // namespace

void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addStaticEventDefs(kAllowlistedEvents);
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addStaticEventDefs(kFullOnlyEvents);
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace ivybridge_core
} // namespace facebook::hbt::perf_event::generated
