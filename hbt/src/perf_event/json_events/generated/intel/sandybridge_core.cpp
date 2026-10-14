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
namespace sandybridge_core {
namespace {

/*
  Events from sandybridge_core.json (407 events).

  Supported SKUs:
      - Arch: x86, Model: SNB id: 42
*/
constexpr std::
    array<StaticEventDef, 25>
        kAllowlistedEvents{
            {
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
                    .full_desc = "All (macro) branch instructions retired.",
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
                    .brief_desc =
                        "Taken branch instructions retired. (Precise Event - PEBS).",
                    .full_desc =
                        "Taken branch instructions retired. (Precise Event - PEBS).",
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
                    .brief_desc =
                        "All mispredicted macro branch instructions retired.",
                    .full_desc =
                        "All mispredicted macro branch instructions retired.",
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
                    .brief_desc =
                        "Reference cycles when the core is not in halt state.",
                    .full_desc =
                        "This event counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. This event has a constant ratio with the CPU_CLK_UNHALTED.REF_XCLK event. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. ",
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
                    .brief_desc =
                        "Core cycles when the thread is not in halt state.",
                    .full_desc =
                        "This event counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. ",
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
                        "Core cycles when at least one thread on the physical core is not in halt state.",
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
                    .brief_desc =
                        "Thread cycles when thread is not in halt state.",
                    .full_desc =
                        "Thread cycles when thread is not in halt state.",
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
                        "Core cycles when at least one thread on the physical core is not in halt state.",
                    .full_desc =
                        "Core cycles when at least one thread on the physical core is not in halt state.",
                    .default_sampling_period = 0x1E8483ULL,
                    .errata = "0",
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_LOAD_MISSES.WALK_COMPLETED",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Load misses at all DTLB levels that cause completed page walks.",
                    .full_desc =
                        "Load misses at all DTLB levels that cause completed page walks.",
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
                        "Store misses in all DTLB levels that cause completed page walks.",
                    .full_desc =
                        "Store misses in all DTLB levels that cause completed page walks.",
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
                        "Instruction cache, streaming buffer and victim cache misses.",
                    .full_desc =
                        "This event counts the number of instruction cache, streaming buffer and victim cache misses. Counting includes unchacheable accesses.",
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
                        "Uops not delivered to Resource Allocation Table (RAT) per thread when backend of the machine is not stalled .",
                    .full_desc =
                        "This event counts the number of uops not delivered to the back-end per cycle, per thread, when the back-end was not stalled.  In the ideal case 4 uops can be delivered each cycle.  The event counts the undelivered uops - so if 3 were delivered in one cycle, the counter would be incremented by 1 for that cycle (4 - 3). If the back-end is stalled, the count for this event is not incremented even when uops were not delivered, because the back-end would not have been able to accept them.  This event is used in determining the front-end bound category of the top-down pipeline slots characterization.",
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
                        "Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).",
                    .full_desc =
                        "Number of cycles waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).",
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
                        "Misses in all ITLB levels that cause completed page walks.",
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
                    .brief_desc = "L1D data line replacements.",
                    .full_desc =
                        "This event counts L1D data line replacements.  Replacements occur when a new line is brought into the cache, causing eviction of a line loaded earlier.  ",
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
                    .brief_desc = "L2 cache lines filling L2.",
                    .full_desc =
                        "This event counts the number of L2 cache lines brought into the L2 cache.  Lines are filled into the L2 cache when there was an L2 miss.",
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
                    .brief_desc = "L2 code requests.",
                    .full_desc = "L2 code requests.",
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
                        "Cases when loads get true Block-on-Store blocking code preventing store forwarding.",
                    .full_desc =
                        "This event counts loads that followed a store to the same address, where the data could not be forwarded inside the pipeline from the store to the load.  The most common reason why store forwarding would be blocked is when a load's address range overlaps with a preceding smaller uncompleted store.  See the table of not supported store forwards in the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual.  The penalty for blocked store forwarding is that the load must wait for the store to complete before it can be issued.",
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
                    .brief_desc =
                        "Core-originated cacheable demand requests missed LLC.",
                    .full_desc =
                        "Core-originated cacheable demand requests missed LLC.",
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
                        "Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore.",
                    .full_desc =
                        "Offcore outstanding cacheable Core Data Read transactions in SuperQueue (SQ), queue to uncore.",
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
                        "Cycles when offcore outstanding cacheable Core Data Read transactions are present in SuperQueue (SQ), queue to uncore.",
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
                        "Uops that Resource Allocation Table (RAT) issues to Reservation Station (RS).",
                    .full_desc =
                        "This event counts the number of Uops issued by the front-end of the pipeilne to the back-end.",
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
                    .brief_desc =
                        "Actually retired uops. (Precise Event - PEBS).",
                    .full_desc =
                        "This event counts the number of micro-ops retired. (Precise Event)",
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
                    .brief_desc =
                        "Retirement slots used. (Precise Event - PEBS).",
                    .full_desc =
                        "This event counts the number of retirement slots used each cycle.  There are potentially 4 slots that can be used each cycle - meaning, 4 micro-ops or 4 instructions could retire each cycle.  This event is used in determining the 'Retiring' category of the Top-Down pipeline slots characterization. (Precise Event - PEBS)",
                    .default_sampling_period = 0x1E8483ULL,
                    .errata = "0",
                },
            }};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 382> kFullOnlyEvents{
    {
        {
            .pmu_type = PmuType::cpu,
            .id = "AGU_BYPASS_CANCEL.COUNT",
            .encoding =
                {
                    .code = 0xB6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "This event counts executed load operations with all the following traits: 1. addressing of the format [base + offset], 2. the offset is between 1 and 2047, 3. the address specified in the base register is in one page and the address [base+offset] is in an.",
            .full_desc =
                "This event counts executed load operations with all the following traits: 1. addressing of the format [base + offset], 2. the offset is between 1 and 2047, 3. the address specified in the base register is in one page and the address [base+offset] is in an.",
            .default_sampling_period = 0x186A3ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ARITH.FPU_DIV",
            .encoding =
                {
                    .code = 0x14ULL,
                    .umask = 0x1ULL,
                    .edge = true,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Divide operations executed.",
            .full_desc =
                "This event counts the number of the divide operations executed.",
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
            .brief_desc =
                "Cycles when divider is busy executing divide operations.",
            .full_desc =
                "Cycles when divider is busy executing divide operations.",
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
            .full_desc =
                "Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.",
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
            .brief_desc = "Speculative and retired  branches.",
            .full_desc = "Speculative and retired  branches.",
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
            .brief_desc = "Speculative and retired macro-conditional branches.",
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
                "Speculative and retired macro-unconditional branches excluding calls and indirects.",
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
            .brief_desc = "Speculative and retired direct near calls.",
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
                "Speculative and retired indirect branches excluding calls and returns.",
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
            .brief_desc = "Not taken macro-conditional branches.",
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
                "Taken speculative and retired macro-conditional branches.",
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
                "Taken speculative and retired macro-conditional branch instructions excluding calls and indirects.",
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
            .brief_desc = "Taken speculative and retired direct near calls.",
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
                "Taken speculative and retired indirect branches excluding calls and returns.",
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
            .brief_desc = "Taken speculative and retired indirect calls.",
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
                "Taken speculative and retired indirect branches with return mnemonic.",
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
            .brief_desc =
                "All (macro) branch instructions retired. (Precise Event - PEBS).",
            .full_desc =
                "All (macro) branch instructions retired. (Precise Event - PEBS).",
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
            .brief_desc =
                "Conditional branch instructions retired. (Precise Event - PEBS).",
            .full_desc =
                "Conditional branch instructions retired. (Precise Event - PEBS).",
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
            .full_desc = "Far branch instructions retired.",
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
            .brief_desc =
                "Direct and indirect near call instructions retired. (Precise Event - PEBS).",
            .full_desc =
                "Direct and indirect near call instructions retired. (Precise Event - PEBS).",
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
                "Direct and indirect macro near call instructions retired (captured in ring 3). (Precise Event - PEBS).",
            .full_desc =
                "Direct and indirect macro near call instructions retired (captured in ring 3). (Precise Event - PEBS).",
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
            .brief_desc =
                "Return instructions retired. (Precise Event - PEBS).",
            .full_desc = "Return instructions retired. (Precise Event - PEBS).",
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
            .full_desc = "Not taken branch instructions retired.",
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
                "Speculative and retired mispredicted macro conditional branches.",
            .full_desc =
                "Speculative and retired mispredicted macro conditional branches.",
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
                "Speculative and retired mispredicted macro conditional branches.",
            .full_desc =
                "Speculative and retired mispredicted macro conditional branches.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_EXEC.ALL_DIRECT_NEAR_CALL",
            .encoding =
                {
                    .code = 0x89ULL,
                    .umask = 0xD0ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Speculative and retired mispredicted direct near calls.",
            .full_desc =
                "Speculative and retired mispredicted direct near calls.",
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
                "Mispredicted indirect branches excluding calls and returns.",
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
                "Not taken speculative and retired mispredicted macro conditional branches.",
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
                "Taken speculative and retired mispredicted macro conditional branches.",
            .full_desc =
                "Taken speculative and retired mispredicted macro conditional branches.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_EXEC.TAKEN_DIRECT_NEAR_CALL",
            .encoding =
                {
                    .code = 0x89ULL,
                    .umask = 0x90ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Taken speculative and retired mispredicted direct near calls.",
            .full_desc =
                "Taken speculative and retired mispredicted direct near calls.",
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
                "Taken speculative and retired mispredicted indirect branches excluding calls and returns.",
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
                "Taken speculative and retired mispredicted indirect calls.",
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
                "Taken speculative and retired mispredicted indirect branches with return mnemonic.",
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
            .brief_desc =
                "Mispredicted macro branch instructions retired. (Precise Event - PEBS).",
            .full_desc =
                "Mispredicted macro branch instructions retired. (Precise Event - PEBS)",
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
            .brief_desc =
                "Mispredicted conditional branch instructions retired. (Precise Event - PEBS).",
            .full_desc =
                "Mispredicted conditional branch instructions retired. (Precise Event - PEBS).",
            .default_sampling_period = 0x61A89ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.NEAR_CALL",
            .encoding =
                {
                    .code = 0xC5ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 1,
                },
            .brief_desc =
                "Direct and indirect mispredicted near call instructions retired. (Precise Event - PEBS).",
            .full_desc =
                "Direct and indirect mispredicted near call instructions retired. (Precise Event - PEBS).",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.NOT_TAKEN",
            .encoding =
                {
                    .code = 0xC5ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 1,
                },
            .brief_desc =
                "Mispredicted not taken branch instructions retired.(Precise Event - PEBS).",
            .full_desc =
                "Mispredicted not taken branch instructions retired.(Precise Event - PEBS).",
            .default_sampling_period = 0x61A89ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.TAKEN",
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
                "Mispredicted taken branch instructions retired. (Precise Event - PEBS).",
            .full_desc =
                "Mispredicted taken branch instructions retired. (Precise Event - PEBS).",
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
            .brief_desc = "Unhalted core cycles when the thread is in ring 0.",
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
                "Number of intervals between processor halts while thread is in ring 0.",
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
            .brief_desc =
                "Unhalted core cycles when thread is in rings 1, 2, or 3.",
            .full_desc =
                "Unhalted core cycles when thread is in rings 1, 2, or 3.",
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
                "Reference cycles when the thread is unhalted (counts at 100 MHz rate).",
            .full_desc =
                "Reference cycles when the thread is unhalted (counts at 100 MHz rate).",
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
                "Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).",
            .full_desc =
                "Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).",
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
                "Reference cycles when the thread is unhalted (counts at 100 MHz rate).",
            .full_desc =
                "Reference cycles when the thread is unhalted (counts at 100 MHz rate)",
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
                "Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).",
            .full_desc =
                "Reference cycles when the at least one thread on the physical core is unhalted (counts at 100 MHz rate).",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CYCLE_ACTIVITY.CYCLES_L1D_PENDING",
            .encoding =
                {
                    .code = 0xA3ULL,
                    .umask = 0x2ULL,
                    .cmask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Each cycle there was a miss-pending demand load this thread, increment by 1. Note this is in DCU and connected to Umask 1. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.",
            .full_desc =
                "Each cycle there was a miss-pending demand load this thread, increment by 1. Note this is in DCU and connected to Umask 1. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.",
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
            .brief_desc =
                "Each cycle there was a MLC-miss pending demand load this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0.",
            .full_desc =
                "Each cycle there was a MLC-miss pending demand load this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CYCLE_ACTIVITY.CYCLES_NO_DISPATCH",
            .encoding =
                {
                    .code = 0xA3ULL,
                    .umask = 0x4ULL,
                    .cmask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Each cycle there was no dispatch for this thread, increment by 1. Note this is connect to Umask 2. No dispatch can be deduced from the UOPS_EXECUTED event.",
            .full_desc =
                "Each cycle there was no dispatch for this thread, increment by 1. Note this is connect to Umask 2. No dispatch can be deduced from the UOPS_EXECUTED event.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CYCLE_ACTIVITY.STALLS_L1D_PENDING",
            .encoding =
                {
                    .code = 0xA3ULL,
                    .umask = 0x6ULL,
                    .cmask = 0x6ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Each cycle there was a miss-pending demand load this thread and no uops dispatched, increment by 1. Note this is in DCU and connected to Umask 1 and 2. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.",
            .full_desc =
                "Each cycle there was a miss-pending demand load this thread and no uops dispatched, increment by 1. Note this is in DCU and connected to Umask 1 and 2. Miss Pending demand load should be deduced by OR-ing increment bits of DCACHE_MISS_PEND.PENDING.",
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
            .brief_desc =
                "Each cycle there was a MLC-miss pending demand load and no uops dispatched on this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0 and 2.",
            .full_desc =
                "Each cycle there was a MLC-miss pending demand load and no uops dispatched on this thread (i.e. Non-completed valid SQ entry allocated for demand load and waiting for Uncore), increment by 1. Note this is in MLC and connected to Umask 0 and 2.",
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
            .brief_desc = "Decode Stream Buffer (DSB)-to-MITE switches.",
            .full_desc = "Decode Stream Buffer (DSB)-to-MITE switches.",
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
                "Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles.",
            .full_desc =
                "This event counts the cycles attributed to a switch from the Decoded Stream Buffer (DSB), which holds decoded instructions, to the legacy decode pipeline.  It excludes cycles when the back-end cannot  accept new micro-ops.  The penalty for these switches is potentially several cycles of instruction starvation, where no micro-ops are delivered to the back-end.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DSB_FILL.ALL_CANCEL",
            .encoding =
                {
                    .code = 0xACULL,
                    .umask = 0xAULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cases of cancelling valid Decode Stream Buffer (DSB) fill not because of exceeding way limit.",
            .full_desc =
                "Cases of cancelling valid Decode Stream Buffer (DSB) fill not because of exceeding way limit.",
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
                "Cycles when Decode Stream Buffer (DSB) fill encounter more than 3 Decode Stream Buffer (DSB) lines.",
            .full_desc =
                "Cycles when Decode Stream Buffer (DSB) fill encounter more than 3 Decode Stream Buffer (DSB) lines.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DSB_FILL.OTHER_CANCEL",
            .encoding =
                {
                    .code = 0xACULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cases of cancelling valid DSB fill not because of exceeding way limit.",
            .full_desc =
                "Cases of cancelling valid DSB fill not because of exceeding way limit.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.MISS_CAUSES_A_WALK",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Load misses in all DTLB levels that cause page walks.",
            .full_desc =
                "Load misses in all DTLB levels that cause page walks.",
            .default_sampling_period = 0x186A3ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.STLB_HIT",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Load operations that miss the first DTLB level but hit the second and do not cause page walks.",
            .full_desc =
                "This event counts load operations that miss the first DTLB level but hit the second and do not cause any page walks. The penalty in this case is approximately 7 cycles.",
            .default_sampling_period = 0x186A3ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.WALK_DURATION",
            .encoding =
                {
                    .code = 0x8ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles when PMH is busy with page walks.",
            .full_desc =
                "This event counts cycles when the  page miss handler (PMH) is servicing page walks caused by DTLB load misses.",
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
            .brief_desc =
                "Store misses in all DTLB levels that cause page walks.",
            .full_desc =
                "Store misses in all DTLB levels that cause page walks.",
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
                "Store operations that miss the first TLB level but hit the second and do not cause page walks.",
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
            .brief_desc = "Cycles when PMH is busy with page walks.",
            .full_desc = "Cycles when PMH is busy with page walks.",
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
            .brief_desc = "Cycles with any input/output SSE or FP assist.",
            .full_desc = "Cycles with any input/output SSE or FP assist.",
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
            .brief_desc = "Number of SIMD FP assists due to input values.",
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
            .brief_desc = "Number of SIMD FP assists due to Output values.",
            .full_desc = "Number of SIMD FP assists due to Output values.",
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
            .full_desc = "Number of X87 assists due to input value.",
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
            .full_desc = "Number of X87 assists due to output value.",
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
                "Number of SSE* or AVX-128 FP Computational packed double-precision uops issued this cycle.",
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
                "Number of SSE* or AVX-128 FP Computational packed single-precision uops issued this cycle.",
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
                "Number of SSE* or AVX-128 FP Computational scalar double-precision uops issued this cycle.",
            .full_desc =
                "Number of SSE* or AVX-128 FP Computational scalar double-precision uops issued this cycle.",
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
                "Number of SSE* or AVX-128 FP Computational scalar single-precision uops issued this cycle.",
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
                "Number of FP Computational Uops Executed this cycle. The number of FADD, FSUB, FCOM, FMULs, integer MULs and IMULs, FDIVs, FPREMs, FSQRTS, integer DIVs, and IDIVs. This event does not distinguish an FADD used in the middle of a transcendental flow from a s.",
            .full_desc =
                "Number of FP Computational Uops Executed this cycle. The number of FADD, FSUB, FCOM, FMULs, integer MULs and IMULs, FDIVs, FPREMs, FSQRTS, integer DIVs, and IDIVs. This event does not distinguish an FADD used in the middle of a transcendental flow from a s.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "HW_PRE_REQ.DL1_MISS",
            .encoding =
                {
                    .code = 0x4EULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Hardware Prefetch requests that miss the L1D cache. This accounts for both L1 streamer and IP-based (IPP) HW prefetchers. A request is being counted each time it access the cache & miss it, including if a block is applicable or if hit the Fill Buffer for .",
            .full_desc =
                "Hardware Prefetch requests that miss the L1D cache. This accounts for both L1 streamer and IP-based (IPP) HW prefetchers. A request is being counted each time it access the cache & miss it, including if a block is applicable or if hit the Fill Buffer for .",
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
                "Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches.",
            .full_desc =
                "Number of Instruction Cache, Streaming Buffer and Victim Cache Reads. both cacheable and noncacheable, including UC fetches.",
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
            .brief_desc =
                "Cycles Decode Stream Buffer (DSB) is delivering 4 Uops.",
            .full_desc =
                "Cycles Decode Stream Buffer (DSB) is delivering 4 Uops.",
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
            .brief_desc =
                "Cycles Decode Stream Buffer (DSB) is delivering any Uop.",
            .full_desc =
                "Cycles Decode Stream Buffer (DSB) is delivering any Uop.",
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
            .brief_desc = "Cycles MITE is delivering 4 Uops.",
            .full_desc = "Cycles MITE is delivering 4 Uops.",
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
            .brief_desc = "Cycles MITE is delivering any Uop.",
            .full_desc = "Cycles MITE is delivering any Uop.",
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
                "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from Decode Stream Buffer (DSB) path.",
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
                "Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.",
            .full_desc =
                "Uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.",
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
            .brief_desc = "Instruction Decode Queue (IDQ) empty cycles.",
            .full_desc = "Instruction Decode Queue (IDQ) empty cycles.",
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
                "Uops delivered to Instruction Decode Queue (IDQ) from MITE path.",
            .full_desc =
                "Uops delivered to Instruction Decode Queue (IDQ) from MITE path.",
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
                "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) from MITE path.",
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
                "Uops delivered to Instruction Decode Queue (IDQ) from MITE path.",
            .full_desc =
                "Uops delivered to Instruction Decode Queue (IDQ) from MITE path.",
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
                "Cycles when uops are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
            .full_desc =
                "This event counts cycles during which the microcode sequencer assisted the front-end in delivering uops.  Microcode assists are used for complex instructions or scenarios that can't be handled by the standard decoder.  Using other instructions, if possible, will usually improve performance.  See the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual for more information.",
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
                "Cycles when uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
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
                "Deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while Microcode Sequencer (MS) is busy.",
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
                "Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
            .full_desc =
                "Uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
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
                "Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
            .full_desc =
                "Uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
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
                "Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.",
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
                "Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
            .full_desc =
                "Uops delivered to Instruction Decode Queue (IDQ) while Microcode Sequencer (MS) is busy.",
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
            .id = "IDQ_UOPS_NOT_DELIVERED.CYCLES_GE_1_UOP_DELIV.CORE",
            .encoding =
                {
                    .code = 0x9CULL,
                    .umask = 0x1ULL,
                    .inv = true,
                    .cmask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when 1 or more uops were delivered to the by the front end.",
            .full_desc =
                "Cycles when 1 or more uops were delivered to the by the front end.",
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
            .full_desc =
                "Cycles with less than 2 uops delivered by the front end.",
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
            .full_desc =
                "Cycles with less than 3 uops delivered by the front end.",
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
            .brief_desc = "Stall cycles because IQ is full.",
            .full_desc = "Stall cycles because IQ is full.",
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
            .id = "INSTS_WRITTEN_TO_IQ.INSTS",
            .encoding =
                {
                    .code = 0x17ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Valid instructions written to IQ per cycle.",
            .full_desc = "Valid instructions written to IQ per cycle.",
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
            .full_desc =
                "This event counts the number of instructions retired from execution. For instructions that consist of multiple micro-ops, this event counts the retirement of the last micro-op of the instruction. Counting continues during hardware interrupts, traps, and inside interrupt handlers. ",
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
                "Number of instructions retired. General Counter   - architectural event.",
            .full_desc =
                "Number of instructions retired. General Counter   - architectural event.",
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
            .brief_desc = "Instructions retired. (Precise Event - PEBS).",
            .full_desc = "Instructions retired. (Precise Event - PEBS).",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_MISC.RAT_STALL_CYCLES",
            .encoding =
                {
                    .code = 0xDULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the thread.",
            .full_desc =
                "Cycles when Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the thread.",
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
                "Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).",
            .full_desc =
                "Number of occurrences waiting for the checkpoints in Resource Allocation Table (RAT) to be recovered after Nuke due to all other cases except JEClear (e.g. whenever a ucode assist is needed like SSE exception, memory disambiguation, etc...).",
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
                "Flushing of the Instruction TLB (ITLB) pages, includes 4k/2M/4M pages.",
            .default_sampling_period = 0x186A7ULL,
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
            .brief_desc = "Misses at all ITLB levels that cause page walks.",
            .full_desc = "Misses at all ITLB levels that cause page walks.",
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
                "Operations that miss the first ITLB level but hit the second and do not cause any page walks.",
            .full_desc =
                "Operations that miss the first ITLB level but hit the second and do not cause any page walks.",
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
            .brief_desc = "Cycles when PMH is busy with page walks.",
            .full_desc =
                "This event count cycles when Page Miss Handler (PMH) is servicing page walks caused by ITLB misses.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L1D.ALLOCATED_IN_M",
            .encoding =
                {
                    .code = 0x51ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Allocated L1D data cache lines in M state.",
            .full_desc = "Allocated L1D data cache lines in M state.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L1D.ALL_M_REPLACEMENT",
            .encoding =
                {
                    .code = 0x51ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cache lines in M state evicted out of L1D due to Snoop HitM or dirty line replacement.",
            .full_desc =
                "Cache lines in M state evicted out of L1D due to Snoop HitM or dirty line replacement.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L1D.EVICTION",
            .encoding =
                {
                    .code = 0x51ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "L1D data cache lines in M state evicted due to replacement.",
            .full_desc =
                "L1D data cache lines in M state evicted due to replacement.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L1D_BLOCKS.BANK_CONFLICT_CYCLES",
            .encoding =
                {
                    .code = 0xBFULL,
                    .umask = 0x5ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when dispatched loads are cancelled due to L1D bank conflicts with other load ports.",
            .full_desc =
                "Cycles when dispatched loads are cancelled due to L1D bank conflicts with other load ports.",
            .default_sampling_period = 0x186A3ULL,
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
                "Cycles a demand request was blocked due to Fill Buffers unavailability.",
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
            .brief_desc = "L1D miss outstanding duration in cycles.",
            .full_desc = "L1D miss outstanding duration in cycles.",
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
                "Cycles with L1D load Misses outstanding from any thread on physical core.",
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
                "Not rejected writebacks from L1D to L2 cache lines in E state.",
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
                "Not rejected writebacks from L1D to L2 cache lines in M state.",
            .full_desc =
                "Not rejected writebacks from L1D to L2 cache lines in M state.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_L1D_WB_RQSTS.HIT_S",
            .encoding =
                {
                    .code = 0x28ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Not rejected writebacks from L1D to L2 cache lines in S state.",
            .full_desc =
                "Not rejected writebacks from L1D to L2 cache lines in S state.",
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
                "Count the number of modified Lines evicted from L1 and missed L2. (Non-rejected WBs from the DCU.).",
            .full_desc =
                "Count the number of modified Lines evicted from L1 and missed L2. (Non-rejected WBs from the DCU.).",
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
            .brief_desc = "L2 cache lines in E state filling L2.",
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
            .brief_desc = "L2 cache lines in I state filling L2.",
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
            .brief_desc = "L2 cache lines in S state filling L2.",
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
            .brief_desc = "Clean L2 cache lines evicted by demand.",
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
            .brief_desc = "Dirty L2 cache lines evicted by demand.",
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
            .brief_desc = "Dirty L2 cache lines filling the L2.",
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
            .brief_desc = "Clean L2 cache lines evicted by L2 prefetch.",
            .full_desc = "Clean L2 cache lines evicted by L2 prefetch.",
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
            .brief_desc = "Dirty L2 cache lines evicted by L2 prefetch.",
            .full_desc = "Dirty L2 cache lines evicted by L2 prefetch.",
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
            .brief_desc = "Demand Data Read requests.",
            .full_desc = "Demand Data Read requests.",
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
            .brief_desc = "Requests from L2 hardware prefetchers.",
            .full_desc = "Requests from L2 hardware prefetchers.",
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
            .brief_desc = "RFO requests to L2 cache.",
            .full_desc = "RFO requests to L2 cache.",
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
            .brief_desc =
                "L2 cache hits when fetching instructions, code reads.",
            .full_desc =
                "L2 cache hits when fetching instructions, code reads.",
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
            .brief_desc = "L2 cache misses when fetching instructions.",
            .full_desc = "L2 cache misses when fetching instructions.",
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
            .brief_desc = "Demand Data Read requests that hit L2 cache.",
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
                "Requests from the L2 hardware prefetchers that hit L2 cache.",
            .full_desc =
                "Requests from the L2 hardware prefetchers that hit L2 cache.",
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
                "Requests from the L2 hardware prefetchers that miss L2 cache.",
            .full_desc =
                "Requests from the L2 hardware prefetchers that miss L2 cache.",
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
            .brief_desc = "RFO requests that hit L2 cache.",
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
            .brief_desc = "RFO requests that miss L2 cache.",
            .full_desc = "RFO requests that miss L2 cache.",
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
            .brief_desc = "RFOs that access cache lines in any state.",
            .full_desc = "RFOs that access cache lines in any state.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_STORE_LOCK_RQSTS.HIT_E",
            .encoding =
                {
                    .code = 0x27ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "RFOs that hit cache lines in E state.",
            .full_desc = "RFOs that hit cache lines in E state.",
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
            .brief_desc = "RFOs that hit cache lines in M state.",
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
            .brief_desc = "RFOs that miss cache lines.",
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
            .brief_desc = "L2 or LLC HW prefetches that access L2 cache.",
            .full_desc = "L2 or LLC HW prefetches that access L2 cache.",
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
            .brief_desc = "Transactions accessing L2 pipe.",
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
            .brief_desc = "L2 cache accesses when fetching instructions.",
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
            .brief_desc = "Demand Data Read requests that access L2 cache.",
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
            .brief_desc = "L1D writebacks that access L2 cache.",
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
            .brief_desc = "L2 fill requests that access L2 cache.",
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
            .brief_desc = "L2 writebacks that access L2 cache.",
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
            .brief_desc = "RFO requests that access L2 cache.",
            .full_desc = "RFO requests that access L2 cache.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "LD_BLOCKS.ALL_BLOCK",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of cases where any load ends up with a valid block-code written to the load buffer (including blocks due to Memory Order Buffer (MOB), Data Cache Unit (DCU), TLB, but load has no DCU miss).",
            .full_desc =
                "Number of cases where any load ends up with a valid block-code written to the load buffer (including blocks due to Memory Order Buffer (MOB), Data Cache Unit (DCU), TLB, but load has no DCU miss).",
            .default_sampling_period = 0x186A3ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "LD_BLOCKS.DATA_UNKNOWN",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Loads delayed due to SB blocks, preceding store operations with known addresses but unknown data.",
            .full_desc =
                "Loads delayed due to SB blocks, preceding store operations with known addresses but unknown data.",
            .default_sampling_period = 0x186A3ULL,
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
                "This event counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
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
            .brief_desc = "False dependencies in MOB due to partial compare.",
            .full_desc =
                "Aliasing occurs when a load is issued after a store and their memory addresses are offset by 4K.  This event counts the number of loads that aliased with a preceding store, resulting in an extended address check in the pipeline.  The enhanced address check typically has a performance penalty of 5 cycles.",
            .default_sampling_period = 0x186A3ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "LD_BLOCKS_PARTIAL.ALL_STA_BLOCK",
            .encoding =
                {
                    .code = 0x7ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "This event counts the number of times that load operations are temporarily blocked because of older stores, with addresses that are not yet known. A load operation may incur more than one block of this type.",
            .full_desc =
                "This event counts the number of times that load operations are temporarily blocked because of older stores, with addresses that are not yet known. A load operation may incur more than one block of this type.",
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
                "Not software-prefetch load dispatches that hit FB allocated for hardware prefetch.",
            .full_desc =
                "Not software-prefetch load dispatches that hit FB allocated for hardware prefetch.",
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
                "Not software-prefetch load dispatches that hit FB allocated for software prefetch.",
            .full_desc =
                "Not software-prefetch load dispatches that hit FB allocated for software prefetch.",
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
            .brief_desc = "Cycles when L1D is locked.",
            .full_desc = "Cycles when L1D is locked.",
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
                "Cycles when L1 and L2 are locked due to UC or split lock.",
            .full_desc =
                "Cycles when L1 and L2 are locked due to UC or split lock.",
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
                "Core-originated cacheable demand requests that refer to LLC.",
            .full_desc =
                "Core-originated cacheable demand requests that refer to LLC.",
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
                "Cycles 4 Uops delivered by the LSD, but didn't come from the decoder.",
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
                "Cycles Uops delivered by the LSD, but didn't come from the decoder.",
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
                "Maskmov false fault - counts number of time ucode passes through Maskmov flow due to instruction's mask being 0 while the flow was completed without raising a fault.",
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
                "This event counts the number of memory ordering Machine Clears detected. Memory Ordering Machine Clears can result from memory disambiguation, external snoops, or cross SMT-HW-thread snoop (stores) hitting load buffers.  Machine clears can have a significant performance impact if they are happening frequently.",
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
            .full_desc =
                "This event is incremented when self-modifying code (SMC) is detected, which causes a machine clear.  Machine clears can have a significant performance impact if they are happening frequently.",
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
                "Retired load uops which data sources were LLC and cross-core snoop hits in on-pkg core cache. (Precise Event - PEBS).",
            .full_desc =
                "This event counts retired load uops that hit in the last-level cache (L3) and were found in a non-modified state in a neighboring core's private cache (same package).  Since the last level cache is inclusive, hits to the L3 may require snooping the private L2 caches of any cores on the same socket that have the line.  In this case, a snoop was required, and another L2 had the line in a non-modified state. (Precise Event - PEBS)",
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
                "Retired load uops which data sources were HitM responses from shared LLC. (Precise Event - PEBS).",
            .full_desc =
                "This event counts retired load uops that hit in the last-level cache (L3) and were found in a non-modified state in a neighboring core's private cache (same package).  Since the last level cache is inclusive, hits to the L3 may require snooping the private L2 caches of any cores on the same socket that have the line.  In this case, a snoop was required, and another L2 had the line in a modified state, so the line had to be invalidated in that L2 cache and transferred to the requesting L2. (Precise Event - PEBS)",
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
                "Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache. (Precise Event - PEBS).",
            .full_desc =
                "Retired load uops which data sources were LLC hit and cross-core snoop missed in on-pkg core cache. (Precise Event - PEBS).",
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
                "Retired load uops which data sources were hits in LLC without snoops required. (Precise Event - PEBS).",
            .full_desc =
                "Retired load uops which data sources were hits in LLC without snoops required. (Precise Event - PEBS).",
            .default_sampling_period = 0x186A3ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_LOAD_UOPS_MISC_RETIRED.LLC_MISS",
            .encoding =
                {
                    .code = 0xD4ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 1,
                },
            .brief_desc =
                "Retired load uops with unknown information as data source in cache serviced the load. (Precise Event - PEBS).",
            .full_desc =
                "This event counts retired demand loads that missed the  last-level (L3) cache. This means that the load is usually satisfied from memory in a client system or possibly from the remote socket in a server. Demand loads are non speculative load uops. (Precise Event - PEBS)",
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
                "Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready. (Precise Event - PEBS).",
            .full_desc =
                "Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready. (Precise Event - PEBS).",
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
            .brief_desc =
                "Retired load uops with L1 cache hits as data sources. (Precise Event - PEBS).",
            .full_desc =
                "Retired load uops with L1 cache hits as data sources. (Precise Event - PEBS).",
            .default_sampling_period = 0x1E8483ULL,
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
            .brief_desc =
                "Retired load uops with L2 cache hits as data sources. (Precise Event - PEBS).",
            .full_desc =
                "Retired load uops with L2 cache hits as data sources. (Precise Event - PEBS).",
            .default_sampling_period = 0x186A3ULL,
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
            .brief_desc =
                "Retired load uops which data sources were data hits in LLC without snoops required. (Precise Event - PEBS).",
            .full_desc =
                "This event counts retired load uops that hit in the last-level (L3) cache without snoops required. (Precise Event - PEBS)",
            .default_sampling_period = 0xC365ULL,
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
            .brief_desc = "Loads with latency value being above 128.",
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
            .brief_desc = "Loads with latency value being above 16.",
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
            .brief_desc = "Loads with latency value being above 256.",
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
            .brief_desc = "Loads with latency value being above 32.",
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
            .brief_desc = "Loads with latency value being above 4 .",
            .full_desc = "Loads with latency value being above 4 .",
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
            .brief_desc = "Loads with latency value being above 512.",
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
            .brief_desc = "Loads with latency value being above 64.",
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
            .brief_desc = "Loads with latency value being above 8.",
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
                "Sample stores and collect precise store operation via PEBS record. PMC3 only. (Precise Event - PEBS).",
            .full_desc =
                "Sample stores and collect precise store operation via PEBS record. PMC3 only. (Precise Event - PEBS).",
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
            .brief_desc = "All retired load uops. (Precise Event - PEBS).",
            .full_desc =
                "This event counts the number of load uops retired (Precise Event)",
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
            .brief_desc = "All retired store uops. (Precise Event - PEBS).",
            .full_desc =
                "This event counts the number of store uops retired. (Precise Event - PEBS)",
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
            .brief_desc =
                "Retired load uops with locked access. (Precise Event - PEBS).",
            .full_desc =
                "Retired load uops with locked access. (Precise Event - PEBS).",
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
                "Retired load uops that split across a cacheline boundary. (Precise Event - PEBS).",
            .full_desc =
                "This event counts line-splitted load uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K). (Precise Event - PEBS)",
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
                "Retired store uops that split across a cacheline boundary. (Precise Event - PEBS).",
            .full_desc =
                "This event counts line-splitted store uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K). (Precise Event - PEBS)",
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
            .brief_desc =
                "Retired load uops that miss the STLB. (Precise Event - PEBS).",
            .full_desc =
                "Retired load uops that miss the STLB. (Precise Event - PEBS).",
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
            .brief_desc =
                "Retired store uops that miss the STLB. (Precise Event - PEBS).",
            .full_desc =
                "Retired store uops that miss the STLB. (Precise Event - PEBS).",
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
                "Speculative cache line split load uops dispatched to L1 cache.",
            .full_desc =
                "Speculative cache line split load uops dispatched to L1 cache.",
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
                "Speculative cache line split STA uops dispatched to L1 cache.",
            .full_desc =
                "Speculative cache line split STA uops dispatched to L1 cache.",
            .default_sampling_period = 0x1E8483ULL,
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
            .brief_desc = "Demand and prefetch data reads.",
            .full_desc = "Demand and prefetch data reads.",
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
            .brief_desc = "Cacheable and noncacheable code read requests.",
            .full_desc = "Cacheable and noncacheable code read requests.",
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
            .brief_desc = "Demand Data Read requests sent to uncore.",
            .full_desc = "Demand Data Read requests sent to uncore.",
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
            .brief_desc =
                "Demand RFO requests including regular RFOs, locks, ItoM.",
            .full_desc =
                "Demand RFO requests including regular RFOs, locks, ItoM.",
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
                "Cases when offcore requests buffer cannot take more entries for core.",
            .full_desc =
                "Cases when offcore requests buffer cannot take more entries for core.",
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
                "Cycles when offcore outstanding Demand Data Read transactions are present in SuperQueue (SQ), queue to uncore.",
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
                "Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle.",
            .full_desc =
                "Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle.",
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
                "Offcore outstanding Demand Data Read transactions in uncore queue.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD_C6",
            .encoding =
                {
                    .code = 0x60ULL,
                    .umask = 0x1ULL,
                    .cmask = 0x6ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.",
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
                "Offcore outstanding RFO store transactions in SuperQueue (SQ), queue to uncore.",
            .full_desc =
                "Offcore outstanding RFO store transactions in SuperQueue (SQ), queue to uncore.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0244ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand & prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts demand & prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
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
                "Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts demand & prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_CODE_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0244ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand & prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts demand & prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
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
                "Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all demand & prefetch code reads that miss the LLC  and the data returned from dram.",
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
            .brief_desc = "Counts all demand & prefetch data reads.",
            .full_desc = "Counts all demand & prefetch data reads.",
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
                "Counts all demand & prefetch data reads that hit in the LLC.",
            .full_desc =
                "Counts all demand & prefetch data reads that hit in the LLC.",
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
                "Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts demand & prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
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
                "Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts demand & prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
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
                "Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts demand & prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_DATA_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0091ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand & prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts demand & prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
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
                "Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all demand & prefetch data reads that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0240ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch code reads that hit in the LLC.",
            .full_desc = "Counts all prefetch code reads that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0240ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0240ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0240ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0240ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400240ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch code reads that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch code reads that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0090ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch data reads that hit in the LLC.",
            .full_desc = "Counts all prefetch data reads that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0090ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0090ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0090ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0090ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400090ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch data reads that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch data reads that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0120ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch RFOs that hit in the LLC.",
            .full_desc = "Counts all prefetch RFOs that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0120ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0120ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0120ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0120ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_PF_RFO.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400120ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch RFOs that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch RFOs that miss the LLC  and the data returned from dram.",
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
                "Counts all data/code/rfo references (demand & prefetch) .",
            .full_desc =
                "Counts all data/code/rfo references (demand & prefetch) .",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C03F7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all data/code/rfo reads (demand & prefetch) that hit in the LLC.",
            .full_desc =
                "Counts all data/code/rfo reads (demand & prefetch) that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C03F7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C03F7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C03F7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_READS.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C03F7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts data/code/rfo reads (demand & prefetch) that hit in the LLC and the snoops sent to sibling cores return clean response.",
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
                "Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all data/code/rfo reads (demand & prefetch) that miss the LLC  and the data returned from dram.",
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
            .brief_desc = "Counts all demand & prefetch prefetch RFOs .",
            .full_desc = "Counts all demand & prefetch prefetch RFOs .",
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
            .brief_desc =
                "Counts all demand & prefetch RFOs that hit in the LLC.",
            .full_desc =
                "Counts all demand & prefetch RFOs that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0122ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand & prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts demand & prefetch RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0122ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand & prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts demand & prefetch RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
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
                "Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts demand & prefetch RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_RFO.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0122ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand & prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts demand & prefetch RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ALL_RFO.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400122ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all demand & prefetch RFOs that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all demand & prefetch RFOs that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_REQUEST.LLC_MISS_LOCAL.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1F80408FFFULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = ANY_REQUEST and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .full_desc =
                "This event counts any requests that miss the LLC where the data was returned from local DRAM",
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
            .brief_desc = "OFFCORE_RESPONSE.COREWB.ANY_RESPONSE",
            .full_desc = "OFFCORE_RESPONSE.COREWB.ANY_RESPONSE",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DATA_IN.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10433ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = DATA_INTO_CORE and RESPONSE = ANY_RESPONSE",
            .full_desc = "REQUEST = DATA_INTO_CORE and RESPONSE = ANY_RESPONSE",
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
            .brief_desc = "Counts LLC replacements.",
            .full_desc =
                "This event counts all data requests (demand/prefetch data reads and demand data writes (RFOs) that miss the LLC  where the data is returned from local DRAM",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DATA_IN_SOCKET.LLC_MISS_LOCAL.ANY_LLC_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x17004001B3ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = DATA_IN_SOCKET and RESPONSE = LLC_MISS_LOCAL and SNOOP = ANY_LLC_HIT",
            .full_desc =
                "REQUEST = DATA_IN_SOCKET and RESPONSE = LLC_MISS_LOCAL and SNOOP = ANY_LLC_HIT",
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
            .brief_desc = "Counts all demand code reads.",
            .full_desc = "Counts all demand code reads.",
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
            .brief_desc = "Counts all demand code reads that hit in the LLC.",
            .full_desc = "Counts all demand code reads that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts demand code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts demand code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
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
                "Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts demand code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts demand code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
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
                "Counts demand code reads that miss the LLC and the data returned from dram.",
            .full_desc =
                "Counts demand code reads that miss the LLC and the data returned from dram.",
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
            .brief_desc = "Counts all demand data reads .",
            .full_desc = "Counts all demand data reads .",
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
            .brief_desc = "Counts all demand data reads that hit in the LLC.",
            .full_desc = "Counts all demand data reads that hit in the LLC.",
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
                "Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts demand data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts demand data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
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
                "Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts demand data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts demand data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
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
                "Counts demand data reads that miss the LLC and the data returned from dram.",
            .full_desc =
                "Counts demand data reads that miss the LLC and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_IFETCH.LLC_MISS_LOCAL.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1F80400004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = DEMAND_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .full_desc =
                "REQUEST = DEMAND_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
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
            .brief_desc = "Counts all demand rfo's .",
            .full_desc = "Counts all demand rfo's .",
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
                "Counts all demand data writes (RFOs) that hit in the LLC.",
            .full_desc =
                "Counts all demand data writes (RFOs) that hit in the LLC.",
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
                "Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts demand data writes (RFOs) that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data writes (RFOs) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts demand data writes (RFOs) that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
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
                "Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts demand data writes (RFOs) that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data writes (RFOs) that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts demand data writes (RFOs) that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.LLC_HIT_M.HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000040002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = DEMAND_RFO and RESPONSE = LLC_HIT_M and SNOOP = HITM",
            .full_desc =
                "REQUEST = DEMAND_RFO and RESPONSE = LLC_HIT_M and SNOOP = HITM",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data writes (RFOs) that miss the LLC and the data returned from dram.",
            .full_desc =
                "Counts demand data writes (RFOs) that miss the LLC and the data returned from dram.",
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
                "Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches.",
            .full_desc =
                "Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses. It also includes L2 hints sent to LLC to keep a line from being evicted out of the core caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.OTHER.LRU_HINTS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x803C8000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts L2 hints sent to LLC to keep a line from being evicted out of the core caches.",
            .full_desc =
                "Counts L2 hints sent to LLC to keep a line from being evicted out of the core caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.OTHER.PORTIO_MMIO_UC",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2380408000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses.",
            .full_desc =
                "Counts miscellaneous accesses that include port i/o, MMIO and uncacheable memory accesses.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_DATA_RD.LLC_MISS_LOCAL.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1F80400010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = PF_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .full_desc =
                "REQUEST = PF_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_IFETCH.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "REQUEST = PF_RFO and RESPONSE = ANY_RESPONSE",
            .full_desc = "REQUEST = PF_RFO and RESPONSE = ANY_RESPONSE",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_IFETCH.LLC_MISS_LOCAL.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1F80400040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "REQUEST = PF_RFO and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .full_desc =
                "REQUEST = PF_RFO and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to L2) code reads that hit in the LLC.",
            .full_desc =
                "Counts all prefetch (that bring data to L2) code reads that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch (that bring data to L2) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400040ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to L2) code reads that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch (that bring data to L2) code reads that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to L2) data reads that hit in the LLC.",
            .full_desc =
                "Counts all prefetch (that bring data to L2) data reads that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch (that bring data to L2) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) data reads that miss the LLC and the data returned from dram.",
            .full_desc =
                "Counts prefetch (that bring data to L2) data reads that miss the LLC and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to L2) RFOs that hit in the LLC.",
            .full_desc =
                "Counts all prefetch (that bring data to L2) RFOs that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch (that bring data to L2) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to L2) RFOs that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch (that bring data to L2) RFOs that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) code reads that hit in the LLC.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) code reads that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_CODE_RD.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) code reads that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) code reads that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads that hit in the LLC.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) data reads that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_DATA_RD.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs that hit in the LLC.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs that hit in the LLC.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops to sibling cores hit in either E/S state and the line is not forwarded.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) RFOs that hit in the LLC and the snoops sent to sibling cores return clean response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_LLC_RFO.LLC_MISS.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x300400100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs that miss the LLC  and the data returned from dram.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs that miss the LLC  and the data returned from dram.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L_DATA_RD.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = PF_LLC_DATA_RD and RESPONSE = ANY_RESPONSE",
            .full_desc = "REQUEST = PF_LLC_DATA_RD and RESPONSE = ANY_RESPONSE",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L_DATA_RD.LLC_MISS_LOCAL.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1F80400080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = PF_LLC_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .full_desc =
                "REQUEST = PF_LLC_DATA_RD and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L_IFETCH.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "REQUEST = PF_LLC_IFETCH and RESPONSE = ANY_RESPONSE",
            .full_desc = "REQUEST = PF_LLC_IFETCH and RESPONSE = ANY_RESPONSE",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L_IFETCH.LLC_MISS_LOCAL.DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1F80400200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "REQUEST = PF_LLC_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
            .full_desc =
                "REQUEST = PF_LLC_IFETCH and RESPONSE = LLC_MISS_LOCAL and SNOOP = DRAM",
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
                "Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address.",
            .full_desc =
                "Counts requests where the address of an atomic lock instruction spans a cache line boundary or the lock instruction is executed on uncacheable address.",
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
            .brief_desc = "Counts non-temporal stores.",
            .full_desc = "Counts non-temporal stores.",
            .default_sampling_period = 0x186A3ULL,
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
                "Number of GSSE memory assist for stores. GSSE microcode assist is being invoked whenever the hardware is unable to properly handle GSSE-256b operations.",
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
            .id = "OTHER_ASSISTS.ITLB_MISS_RETIRED",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Retired instructions experiencing ITLB misses.",
            .full_desc = "Retired instructions experiencing ITLB misses.",
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
            .brief_desc =
                "Number of any page walk that had a miss in LLC. Does not necessary cause a SUSPEND.",
            .full_desc =
                "Number of any page walk that had a miss in LLC. Does not necessary cause a SUSPEND.",
            .default_sampling_period = 0x186A3ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PARTIAL_RAT_STALLS.FLAGS_MERGE_UOP",
            .encoding =
                {
                    .code = 0x59ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Increments the number of flags-merge uops in flight each cycle.",
            .full_desc =
                "Increments the number of flags-merge uops in flight each cycle.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PARTIAL_RAT_STALLS.FLAGS_MERGE_UOP_CYCLES",
            .encoding =
                {
                    .code = 0x59ULL,
                    .umask = 0x20ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Performance sensitive flags-merging uops added by Sandy Bridge u-arch.",
            .full_desc =
                "This event counts the number of cycles spent executing performance-sensitive flags-merging uops. For example, shift CL (merge_arith_flags). For more details, See the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PARTIAL_RAT_STALLS.MUL_SINGLE_UOP",
            .encoding =
                {
                    .code = 0x59ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Multiply packed/scalar single precision uops allocated.",
            .full_desc =
                "Multiply packed/scalar single precision uops allocated.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PARTIAL_RAT_STALLS.SLOW_LEA_WINDOW",
            .encoding =
                {
                    .code = 0x59ULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles with at least one slow LEA uop being allocated.",
            .full_desc =
                "This event counts the number of cycles with at least one slow LEA uop being allocated. A uop is generally considered as slow LEA if it has three sources (for example, two sources and immediate) regardless of whether it is a result of LEA instruction or not. Examples of the slow LEA uop are or uops with base, index, and offset source operands using base and index reqisters, where base is EBR/RBP/R13, using RIP relative or 16-bit addressing modes. See the Intel(R) 64 and IA-32 Architectures Optimization Reference Manual for more details about slow LEA instructions.",
            .default_sampling_period = 0x1E8483ULL,
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
            .brief_desc = "Resource-related stall cycles.",
            .full_desc = "Resource-related stall cycles.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS.LB",
            .encoding =
                {
                    .code = 0xA2ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the cycles of stall due to lack of load buffers.",
            .full_desc =
                "Counts the cycles of stall due to lack of load buffers.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS.LB_SB",
            .encoding =
                {
                    .code = 0xA2ULL,
                    .umask = 0xAULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Resource stalls due to load or store buffers all being in use.",
            .full_desc =
                "Resource stalls due to load or store buffers all being in use.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS.MEM_RS",
            .encoding =
                {
                    .code = 0xA2ULL,
                    .umask = 0xEULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Resource stalls due to memory buffers or Reservation Station (RS) being fully utilized.",
            .full_desc =
                "Resource stalls due to memory buffers or Reservation Station (RS) being fully utilized.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS.OOO_RSRC",
            .encoding =
                {
                    .code = 0xA2ULL,
                    .umask = 0xF0ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Resource stalls due to Rob being full, FCSW, MXCSR and OTHER.",
            .full_desc =
                "Resource stalls due to Rob being full, FCSW, MXCSR and OTHER.",
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
            .brief_desc =
                "Cycles stalled due to no eligible RS entry available.",
            .full_desc =
                "Cycles stalled due to no eligible RS entry available.",
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
                "Cycles stalled due to no store buffers available. (not including draining form sync).",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS2.ALL_FL_EMPTY",
            .encoding =
                {
                    .code = 0x5BULL,
                    .umask = 0xCULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles with either free list is empty.",
            .full_desc = "Cycles with either free list is empty.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS2.ALL_PRF_CONTROL",
            .encoding =
                {
                    .code = 0x5BULL,
                    .umask = 0xFULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Resource stalls2 control structures full for physical registers.",
            .full_desc =
                "Resource stalls2 control structures full for physical registers.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS2.BOB_FULL",
            .encoding =
                {
                    .code = 0x5BULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when Allocator is stalled if BOB is full and new branch needs it.",
            .full_desc =
                "Cycles when Allocator is stalled if BOB is full and new branch needs it.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS2.OOO_RSRC",
            .encoding =
                {
                    .code = 0x5BULL,
                    .umask = 0x4FULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Resource stalls out of order resources full.",
            .full_desc = "Resource stalls out of order resources full.",
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
            .brief_desc = "Count cases of saving new LBR.",
            .full_desc = "Count cases of saving new LBR.",
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
                "Cycles when Reservation Station (RS) is empty for the thread.",
            .full_desc =
                "Cycles when Reservation Station (RS) is empty for the thread.",
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
            .default_sampling_period = 0x1E8483ULL,
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
                "Number of AVX-256 Computational FP double precision uops issued this cycle.",
            .full_desc =
                "Number of AVX-256 Computational FP double precision uops issued this cycle.",
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
                "Number of GSSE-256 Computational FP single precision uops issued this cycle.",
            .full_desc =
                "Number of GSSE-256 Computational FP single precision uops issued this cycle.",
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
            .brief_desc = "Split locks in SQ.",
            .full_desc = "Split locks in SQ.",
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
            .brief_desc = "DTLB flush attempts of the thread-specific entries.",
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
            .brief_desc = "STLB flush attempts.",
            .full_desc = "STLB flush attempts.",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.CORE",
            .encoding =
                {
                    .code = 0xB1ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops dispatched from any thread.",
            .full_desc = "Uops dispatched from any thread.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.THREAD",
            .encoding =
                {
                    .code = 0xB1ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops dispatched per thread.",
            .full_desc = "Uops dispatched per thread.",
            .default_sampling_period = 0x1E8483ULL,
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
            .brief_desc =
                "Cycles per thread when uops are dispatched to port 0.",
            .full_desc =
                "Cycles per thread when uops are dispatched to port 0.",
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
            .brief_desc = "Cycles per core when uops are dispatched to port 0.",
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
            .brief_desc =
                "Cycles per thread when uops are dispatched to port 1.",
            .full_desc =
                "Cycles per thread when uops are dispatched to port 1.",
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
            .brief_desc = "Cycles per core when uops are dispatched to port 1.",
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
                "Cycles per thread when load or STA uops are dispatched to port 2.",
            .full_desc =
                "Cycles per thread when load or STA uops are dispatched to port 2.",
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
                "Cycles per core when load or STA uops are dispatched to port 2.",
            .full_desc =
                "Cycles per core when load or STA uops are dispatched to port 2.",
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
                "Cycles per thread when load or STA uops are dispatched to port 3.",
            .full_desc =
                "Cycles per thread when load or STA uops are dispatched to port 3.",
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
                "Cycles per core when load or STA uops are dispatched to port 3.",
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
            .brief_desc =
                "Cycles per thread when uops are dispatched to port 4.",
            .full_desc =
                "Cycles per thread when uops are dispatched to port 4.",
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
            .brief_desc = "Cycles per core when uops are dispatched to port 4.",
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
            .brief_desc =
                "Cycles per thread when uops are dispatched to port 5.",
            .full_desc =
                "Cycles per thread when uops are dispatched to port 5.",
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
            .brief_desc = "Cycles per core when uops are dispatched to port 5.",
            .full_desc = "Cycles per core when uops are dispatched to port 5.",
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
                "Cycles at least 1 micro-op is executed from any thread on physical core.",
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
                "Cycles at least 2 micro-op is executed from any thread on physical core.",
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
                "Cycles at least 3 micro-op is executed from any thread on physical core.",
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
                "Cycles at least 4 micro-op is executed from any thread on physical core.",
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
                "Cycles with no micro-ops executed from any thread on physical core.",
            .full_desc =
                "Cycles with no micro-ops executed from any thread on physical core.",
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
                "Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads.",
            .full_desc =
                "Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for all threads.",
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
                "Cycles when Resource Allocation Table (RAT) does not issue Uops to Reservation Station (RS) for the thread.",
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

} // namespace sandybridge_core
} // namespace facebook::hbt::perf_event::generated
